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

    evRegisterPushButton("update", "Update", 3);

    evRegisterPluginVersion(0, 0, 1);
    evRegisterTotalSize(sizeof(BouncePlugin));
}

void BouncePlugin::MakeChannelBounce()
{   
    CONTAINER cont;
    cont.local();
    cont.get_animation_channels(channels);
    int channelCount = channels.GetSize();

    if (channelCount > 0)
    {
        const char* pName = {};
        const char** some = new const char* [channelCount+1]{};
        for (unsigned int i = 0; i < channelCount; i++)
        {
            if (channels[i].valid())
            {
                channels[i].get_name(&pName);
                some[i] = pName;
            }
        }
        evUpdateParameterEntries("animChannel", some);      

        if (m_vDropDwnSelection <= channelCount)
        {
            int chanId = channels[m_vDropDwnSelection].GetID();

            double currTime = 0.0;
            _api__stage_get_time(_api__stage_get_local_id(), &currTime);

            double deltaTime = 0.0;
            int keyframeNumber = 0;
            int* keyframeIdArr = {};
            double dTime = DBL_MAX;
            double keyframeTime = 0.0;
            int keyIndex = 0;
            _api__channel_get_keyframes(chanId, &keyframeNumber, &keyframeIdArr);
            for (int i = 0; i < keyframeNumber; i++)
            {
                _api__keyframe_get_time(keyframeIdArr[i], &keyframeTime);
                double tt = abs(currTime - keyframeTime);
                if (tt < dTime)
                {
                    dTime = tt;
                    keyIndex = i;
                }
            }

            double keyframeTime2 = 0.0;
            _api__keyframe_get_time(keyframeIdArr[keyIndex], &keyframeTime2);
            if (keyframeTime2 > currTime) {
                keyIndex--;
            }

            double keyTime = 0.0;
            if (keyIndex == 0) {
                deltaTime = 0.0;
            }
            else {
                _api__keyframe_get_time(keyframeIdArr[keyIndex], &keyTime);
                deltaTime = currTime - keyTime;
            }

            float keyValue = 0.0f;
            _api__keyframe_get_float_value(keyframeIdArr[keyIndex], &keyValue);

            float pValue = 0.0f;
            _api__channel_float_get_frame_by_time(chanId, keyTime - 0.02, &pValue);

            float velocity = (keyValue - pValue) * m_fVelocity;

            _api__channel_float_get_frame_by_time(chanId, currTime, &pValue);

            if (!velocity == 0 && keyIndex > 0) {
                pValue = pValue + velocity * m_fAmp * sin(m_fFreq * deltaTime * 2.0f * PI) / exp(m_fDec * deltaTime);
            }
            else {
                _api__channel_float_get_frame_by_time(chanId, currTime, &pValue);
            }

            GEOMETRY geom = GEOMETRY();
            geom.local();
            char** geomName = new char* ();
            geom.get_type(geomName);

            const char** channelName = new const char* ();
            _api__channel_get_name(chanId, channelName);
            PLUGIN_PARAMETER pparam = PLUGIN_PARAMETER();
            pparam.Init(*geomName, *channelName);
            pparam = pValue;
            geom.set(pparam);
            delete[] channelName;
            delete[] geomName;
        }        
        delete[] some;
    }
}






