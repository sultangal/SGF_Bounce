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

    evRegisterPushButton("pushButton", "Bake Animation", 3);

    evRegisterPluginVersion(0, 0, 1);
    evRegisterTotalSize(sizeof(BouncePlugin));
}

void BouncePlugin::MakeChannelBounce(double currTime, bool bake)
{    
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
                VIZ_POSITION pos = VIZ_POSITION();
                pos.local();
                pos.set(pValue[0], pValue[1], pValue[2]);
                if (bake) {
                    KEYFRAME_XYZ key = KEYFRAME_XYZ();
                    key.set(pValue[0], pValue[1], pValue[2]);
                    channels[m_vDropDwnSelection].add_keyframe(currTime, key);
                }
            }

            if (sChanName == "Rotation")
            {
                ROTATION rot = ROTATION();
                rot.local();
                rot.set(pValue[0], pValue[1], pValue[2]);
            }

            if (sChanName == "Scaling")
            {
                SCALING scale = SCALING();
                scale.local();
                scale.set(pValue[0], pValue[1], pValue[2]);
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
    {
        DIRECTOR dir = DIRECTOR();
        channels[m_vDropDwnSelection].get_director(dir);
        double dirEndTime = 0.0;
        dir.get_end_time(false, &dirEndTime);
        double currTime = 0.0;
        printf("VALUE : %f \n", dirEndTime);
        while (currTime <= dirEndTime)
        {
            MakeChannelBounce(currTime, true);
            currTime = currTime + 0.02;
        }
    }
}

//printf("VALUE : %d \n", value);



