#include <SGF_Bounce.h>

BouncePlugin::BouncePlugin(PLUGIN_DATA* pData)
{
    m_fAmp = pData->fAmp;
    m_fFreq = pData->fFreq;
    m_fDec = pData->fDec;
    m_fVelocity = pData->fVel;
    m_vDropDwnSelection = pData->vDropDwnSelection;
    channels = THeapArray<CHANNEL>();
    isAnimChanValid = false;
    _vizprintf("---> SGF_Plugins::SGF_Bounce()\n");
}

BouncePlugin::~BouncePlugin() {}

void BouncePlugin::Init()
{ 
    evRegisterPlugin(PLUGIN_NAME);
    evRegisterPluginType(EV_FUNCTION);
    evRegisterPluginFolder("SGF_Plugins");
    
    evRegisterParameterFloat("amp", "Amplitude", 0.25f, -1000.0f, 1000.0f);
    evRegisterParameterFloat("freq", "Frequency", 2.0f, -1000.0f, 1000.0f);
    evRegisterParameterFloat("dec", "Decay", 3.0f, -1000.0f, 1000.0f);
    evRegisterParameterFloat("velocity", "Velocity", 1.0f, -1000.0f, 1000.0f);
    evRegisterParameterDropDown("animChannel", "Select animation channel", 0, nullptr, 10, 10);

    //evRegisterPushButton("pushButton", "Bake Animation", 3);

    evRegisterPluginVersion(0, 0, 1);
    evRegisterTotalSize(sizeof(BouncePlugin));
}

void BouncePlugin::MakeChannelBounce(bool bake)
{    
    double currTime = 0.0;
    _api__stage_get_time(_api__stage_get_local_id(), &currTime);
    if (UpdateChannelList())
    {
        int chanId = channels[m_vDropDwnSelection].GetID();                 
        int keyframeIndex = 0;
        int keyframeID = 0;
        double keyTime = 0.0;
        double deltaTime = 0.0;
        GetNearestKeyframe(currTime, keyframeID, keyframeIndex, keyTime, deltaTime);

        const char* channelName = nullptr;
        channels[m_vDropDwnSelection].get_name(&channelName);
        std::string sChanName = channelName;
        if (sChanName == "Position" || sChanName == "Rotation" || sChanName == "Scaling")
        {
            float pValue[3] = { 0.0f, 0.0f, 0.0f };
            CalculateValueXYZ(keyframeID, keyTime, keyframeIndex, currTime, deltaTime, pValue);
            if (sChanName == "Position")
            {
                SetValueXYZ<VIZ_POSITION>(pValue);
                if (bake) {
                    BakeXYZvalueToKey(pValue, currTime);
                }
            }
            if (sChanName == "Rotation")
            {
                SetValueXYZ<ROTATION>(pValue);
                if (bake) {
                    BakeXYZvalueToKey(pValue, currTime);
                }
            }
            if (sChanName == "Scaling")
            {
                SetValueXYZ<SCALING>(pValue);
                if (bake) {
                    BakeXYZvalueToKey(pValue, currTime);
                }
            }              
        }
        else {
            float pValue = 0.0f;
            CalculateValueFloat(keyframeID, keyTime, keyframeIndex, currTime, deltaTime, pValue);
            GEOMETRY geom = GEOMETRY();
            geom.local();
            char* geomName = nullptr;
            geom.get_type(&geomName);
            PLUGIN_PARAMETER pparam = PLUGIN_PARAMETER();
            pparam.Init(geomName, channelName);
            pparam = pValue;
            geom.set(pparam);
        }               
    }   
}

void BouncePlugin::BakeAnimation(int n_VarID)
{
    //TODO: make proper bake method
    if (n_VarID == 3)
    {/*
        int keyframeNumber = 0;
        int* keyframeIdArr = nullptr;
        _api__channel_get_keyframes(channels[m_vDropDwnSelection].GetID(), &keyframeNumber, &keyframeIdArr);

        DIRECTOR dir = DIRECTOR();
        channels[m_vDropDwnSelection].get_director(dir);
        double dirEndTime = 0.0;
        dir.get_end_time(false, &dirEndTime);
        double currTime = 0.0;
        printf("VALUE : %f \n", dirEndTime);
        while (currTime <= dirEndTime)
        {
            MakeChannelBounce(true);
            currTime = currTime + 0.02;
        }
        */
    }       
}

inline int BouncePlugin::UpdateChannelList()
{
    CONTAINER cont;
    cont.local();
    cont.get_animation_channels(channels);
    int channelsCount = channels.GetSize();
    if (channelsCount > 0 && m_vDropDwnSelection <= channelsCount)
    {
        const char** chanNameList = new const char* [channelsCount + 1]{};
        for (unsigned int i = 0; i < channelsCount; i++)
        {
            if (channels[i].valid())
            {
                const char* tempName = nullptr;
                channels[i].get_name(&tempName);
                chanNameList[i] = tempName;
            }
        }
        evUpdateParameterEntries("animChannel", chanNameList);
        delete[] chanNameList;
        return 1;
    }
    else return 0;
}

//returning nearest "keyframeID" and "keyframeIndex" but not greater than current time, and "deltaTime" - time difference between current time and keyframe time
inline void BouncePlugin::GetNearestKeyframe(const double& time, int& keyframeID, int& keyframeIndex, double& keyframeTime, double& deltaTime)
{
    int keyframeNumber = 0;
    int* keyframeIdArr = nullptr;
    _api__channel_get_keyframes(channels[m_vDropDwnSelection].GetID(), &keyframeNumber, &keyframeIdArr);
    int keyIndex = 0;
    double dTime = DBL_MAX;
    double tt = 0.0;
    for (int i = 0; i < keyframeNumber; i++)
    {
        double keyframeTime1 = 0.0;
        _api__keyframe_get_time(keyframeIdArr[i], &keyframeTime1);
        tt = abs(time - keyframeTime1);
        if (tt < dTime)
        {
            dTime = tt;
            keyIndex = i;
        }
    }

    double keyframeTime2 = 0.0;
    _api__keyframe_get_time(keyframeIdArr[keyIndex], &keyframeTime2);
    if (keyframeTime2 > time) {
        keyIndex--;
    }

    if (keyIndex <= 0) {
        deltaTime = 0.0;
        keyIndex = 0;
    }
    else {
        _api__keyframe_get_time(keyframeIdArr[keyIndex], &keyframeTime);
        deltaTime = time - keyframeTime;
    }

    keyframeIndex = keyIndex;
    keyframeID = keyframeIdArr[keyIndex];
}

inline void BouncePlugin::CalculateValueXYZ(const int& keyframeID, const double& keyframeTime, const int& keyframeIndex,
    const double& currTime, const double& deltaTime, float* out)
{
    int chanId = channels[m_vDropDwnSelection].GetID();
    float keyValue[3] = { 0.0f, 0.0f, 0.0f };
    _api__keyframe_get_xyz_values(keyframeID, &keyValue[0], &keyValue[1], &keyValue[2]);

    _api__channel_xyz_get_value_by_time(chanId, keyframeTime - 0.002, out);

    float velocity[3] =
    {
        (keyValue[0] - out[0]) * m_fVelocity,
        (keyValue[1] - out[1]) * m_fVelocity,
        (keyValue[2] - out[2]) * m_fVelocity
    };

    _api__channel_xyz_get_value_by_time(chanId, currTime, out);

    for (unsigned int i = 0; i < 3; i++)
    {
        if (!(velocity[i]) == 0.0f && keyframeIndex > 0)
        {
            out[i] = out[i] + velocity[i] * m_fAmp * sin(m_fFreq * deltaTime * 2.0f * PI) / exp(m_fDec * deltaTime);
        }
    }
}

inline void BouncePlugin::CalculateValueFloat(const int& keyframeID, const double& keyframeTime, const int& keyframeIndex,
    const double& currTime, const double& deltaTime, float& out)
{
    int chanId = channels[m_vDropDwnSelection].GetID();

    float keyValue = 0.0f;
    _api__keyframe_get_float_value(keyframeID, &keyValue);

    _api__channel_float_get_frame_by_time(chanId, keyframeTime - 0.002, &out);

    float velocity = (keyValue - out) * m_fVelocity;

    _api__channel_float_get_frame_by_time(chanId, currTime, &out);

    if (!velocity == 0.0f && keyframeIndex > 0)
    {
        out = out + velocity * m_fAmp * sin(m_fFreq * deltaTime * 2.0f * PI) / exp(m_fDec * deltaTime);
    }
}

template <typename T>
inline void BouncePlugin::SetValueXYZ(const float* value)
{
    T xyz = T();
    xyz.local();
    xyz.set(value[0], value[1], value[2]);
}

inline void BouncePlugin::BakeXYZvalueToKey(const float* value, const double time)
{
    KEYFRAME_XYZ key = KEYFRAME_XYZ();
    key.set(value[0], value[1], value[2]);
    channels[m_vDropDwnSelection].add_keyframe(time, key);
}
//printf("VALUE : %d \n", value);



