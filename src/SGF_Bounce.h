#include <iostream>
#include <algorithm>
#include <iterator>
#include <evCommon.h>
#include <evGeom.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <Misc.h>
#include <api_functions.h>
#include <evGeom.h>
#include <evObjects.h>


static char* PLUGIN_NAME = "SGF_Bounce";
static float PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989f;
typedef struct PLUGIN_DATA
{
    float fAmp;
    float fFreq;
    float fDec;
    float fVel;
    int vDropDwnSelection;
} PLUGIN_DATA;

class BouncePlugin
{

private:
    float m_fAmp;
    float m_fFreq;
    float m_fDec;
    float m_fVelocity;
    int m_vDropDwnSelection;
    THeapArray<CHANNEL> channels;
    bool isAnimChanValid;
    float SetValuePos(float& velocity, float& amplitude, float& frequency, float& decay, double& deltaTime);
    int UpdateChannelList();
    void GetNearestKeyframe(const double& time, int& keyframeID, int& keyframeIndex, double& keyframeTime, double& deltaTime);
    void GetKeyframeArray();
    void CalculateValueXYZ(const int& keyframeID, const double& keyframeTime, const int& keyframeIndex,
        const double& currTime, const double& deltaTime, float* out);
    void CalculateValueFloat(const int& keyframeID, const double& keyframeTime, const int& keyframeIndex,
        const double& currTime, const double& deltaTime, float& out);

public:
    BouncePlugin(PLUGIN_DATA* pData);
    ~BouncePlugin();

    static void Init();
    void MakeChannelBounce(double currTime, bool bake);
    void BakeAnimation(int n_VarID);
};

inline float BouncePlugin::SetValuePos(float& velocity, float& amplitude, float& frequency, float& decay, double& deltaTime)
{
    velocity, amplitude, frequency, decay, deltaTime;
    return 0.0f;
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

inline void BouncePlugin::GetKeyframeArray()
{

}
