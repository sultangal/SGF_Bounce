#include <SGF_Bounce.h>

VIZPLUGIN_API void PLUGIN_INIT()
{
    BouncePlugin::Init();
}

VIZPLUGIN_API void PLUGIN_EXEC_PER_FIELD(void* pvDataPtr)
{

    BouncePlugin* plugin = static_cast<BouncePlugin*>(pvDataPtr);
    plugin->MakeChannelBounce();
}

VIZPLUGIN_API void PLUGIN_INIT_FUNCTION(void* pvDataPtr)
{
    BouncePlugin* plugin = static_cast<BouncePlugin*>(pvDataPtr);
}
