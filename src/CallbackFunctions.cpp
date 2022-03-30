#include <SGF_Bounce.h>

VIZPLUGIN_API void PLUGIN_INIT()
{
    BouncePlugin::Init();
}

VIZPLUGIN_API void PLUGIN_EXEC_PER_FIELD(void* pvDataPtr)
{

    BouncePlugin* plugin = static_cast<BouncePlugin*>(pvDataPtr);
    double currTime = 0.0;
    _api__stage_get_time(_api__stage_get_local_id(), &currTime);
    plugin->MakeChannelBounce(currTime, false);
}

VIZPLUGIN_API void PLUGIN_INIT_FUNCTION(void* pvDataPtr)
{
    BouncePlugin* plugin = static_cast<BouncePlugin*>(pvDataPtr);
}

VIZPLUGIN_API void PLUGIN_EXEC_ACTION(void* pvDataPtr, int n_VarID)
{
    BouncePlugin* plugin = static_cast<BouncePlugin*>(pvDataPtr);
    plugin->BakeAnimation(n_VarID);
}