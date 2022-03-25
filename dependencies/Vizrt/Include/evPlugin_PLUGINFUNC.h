/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2006,2013 Vizrt Austria GmbH                                       *
 *  All Rights Reserved.                                                         *
 *                                                                               *
 *  This is PROPRIETARY SOURCE CODE ofVizrt Austria GmbH;                        *
 *  the contents of this file may not be disclosed to third parties, copied or   *
 *  duplicated in any form, in whole or in part, without the prior written       *
 *  permission of Vizrt Austria GmbH                                             *
 *                                                                               *
 * ============================================================================= */

/*  CAUTION:
 *  --------
 *  This file contains no user-modifiable data
 *  Under no circumstances change anything in this file without an
 *  explicit order from Vizrt Austria GmbH
 *
 */

#if ! defined( EV_PLUGIN_PLUGINFUNC_H )
#define EV_PLUGIN_PLUGINFUNC_H

// #include "evPlugin_BASE.h"
#include "evMath.h"
#include "evTypes.h"
#include "THeapArray.h"

#include "evPlugin_DynInterface.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------

#define _DOUBLE_DEFS
#ifndef _DOUBLE_DEFS
#include "ftimage.h"
#endif


#define PLUGINFUNC VIZPLUGIN_API        // "PLUGINFUNC is deprecated. please use VIZPLUGIN_API instead."


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief is called during startup of viz before registering the plugin.
 *
 * viz 3.0 supports a new plugin-initialization callback function
 * (PLUGIN_INIT_EX), which can return a error-status. This can be useful
 * if you want viz to not initialize your plugin.
 * (e.g.: no lizense for your plugin, no hardware found, etc.)
 * besides the return value this callback should provide the
 * same functionality as PLUGIN_INIT(). please refer to that function
 * for more documentation on the init callback.
 *
 * make this a simple forwarder to a static function in your class. example:
 * @code
    VIZPLUGIN_API void PLUGIN_INIT_EX()
    {
        CV_Example::Plugin_Init_Ex();
    }
    @endcode
 *
 * @warning PLUGIN_INIT_EX() and PLUGIN_INIT() are mutually exclusive functions.
 * conflicts are handled by ignoring the PLUGIN_INIT() if there is a
 * PLUGIN_INIT_EX() found.
 *
 * @return VIZERROR::Success, if everything is fine and viz should
 *         proceed initializing this plugin. for other error codes see evPluginError.h
 * @note you have to implement one of PLUGIN_INIT_EX() or PLUGIN_INIT().
 * @see PLUGIN_INIT(), evPluginError.h
 */
VIZPLUGIN_API int PLUGIN_INIT_EX( void ); // new in viz 3.0



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief is called during startup of viz to register the plugin.
 *
 * this callback function is called by viz only once per session.
 * the plugin needs to determine its argument structure here.
 *
 * make this a simple forwarder to a static function in your class. example:
 * @code
    VIZPLUGIN_API void PLUGIN_INIT()
    {
        CV_Example::Plugin_Init();
    }
    @endcode
 *
 *
 *
 * the init callback is the place where yout need to register the
 * name, folder, type, and optionally the version of the plugin:
 * @code
    // register the plugin name (& type) to viz.
    const char* CV_Example::PLUGIN_NAME   = "Example";              // the name of this plugin
    const char* CV_Example::PLUGIN_FOLDER = "Folder_Example";       // the folder for this plugin
    const int   CV_Example::PLUGIN_VERSION    = 1;                  // version number
    const int   CV_Example::PLUGIN_RELEASE    = 0;                  // release number
    const int   CV_Example::PLUGIN_PATCHLEVEL = 16;                 // patchlevel info

    evRegisterPlugin( CV_Example::PLUGIN_NAME );
    evRegisterPluginFolder( CV_Example::PLUGIN_FOLDER );
    evRegisterPluginType( EV_FUNCTION_CONTAINER );

    // optionally, but a good idea in general
    evRegisterPluginVersion( CV_Example::PLUGIN_VERSION,
                             CV_Example::PLUGIN_RELEASE,
                             CV_Example::PLUGIN_PATCHLEVEL );
    @endcode
 *
 *
 * next you are registering the Parameters for the GUI, if any:
 * @code
    // TODO: add parameter registration here:
    // Don't forget, that you need to add the registered variable
    // to your class as well!
    evRegisterParameterFileSelector("clip_file",           "Clip file",           "http://10.211.2.117/videos/KL2.mpg", "", "*.*");
    evRegisterParameterBool(        "loop",                "Loop video",          false );
    evRegisterParameterInt(         "preload_frame_count", "Preload frame count", 60, 1, 1<<16 );
    // evHideParameter();   // hide the last parameter
    evRegisterPushButton(           "clip_play",           "Play",                BUTTON_CLIP_PLAY );
   @endcode
 *
 *
 *
 *
 * next you are registering the info string:
 * @code
    // info button: about the plugin
    ostringstream info_string;

    info_string
        << "Folder/Name: " << CV_Example::PLUGIN_FOLDER << "/" << CV_Example::PLUGIN_NAME << "\n"
        << "Version: " << CV_Example::PLUGIN_VERSION << "."
                       << CV_Example::PLUGIN_RELEASE << ".PL"
                       << CV_Example::PLUGIN_PATCHLEVEL << "\n"

#ifdef __DATE__
        << "Builddate: " << __DATE__ << "\n"
#endif

        << ""                                                                                       << "\n"
        << "Plugin for playing video clips projected on a texture."                                 << "\n"
        << "If you want alpha, the video clip needs to have alpha transparency. Drag the"           << "\n"
        << "SoftClip texture-function over the image object."                                       << "\n"
        << ""                                                                                       << "\n"
        << "* Clip File:"                                                                           << "\n"
        << "  ----------"                                                                           << "\n"
        << "  You can load clips from the file system by using the"                                 << "\n"
        << "  \\\"Browse\\\"-Button or you can enter locations in the form"                         << "\n"
        << "  of valid a uri. e.g. http://... mms://..."                                            << "\n"
        << ""                                                                                       << "\n"
        << "* Loop video:"                                                                          << "\n"
        << "  -----------"                                                                          << "\n"
        << "  Determines if the clip restarts at the beginning immediately after"                   << "\n"
        << "  it has finished or reached the OUT TC. the queue is filled with preload"              << "\n"
        << "  frames prior to the restart of the clip."                                             << "\n"
        << ""                                                                                       << "\n"
        << "* Preload frame count:"                                                                 << "\n"
        << "  --------------------"                                                                 << "\n"
        << "  Determines the number of frames to be pre-loaded before playback"                     << "\n"
        << "  starts. Please keep in mind that the larger this number the larger"                   << "\n"
        << "  the memory used. Too small numbers may result in poor performance"                    << "\n"
        << "  if the clip source fails to deliver a steady stream."                                 << "\n"
        << ""                                                                                       << "\n"
        << "* Play:"                                                                                << "\n"
        << "  -----------"                                                                          << "\n"
        << "  Toggles between Play and Pause."                                                      << "\n"
        ;

    evRegisterInfoText( "info", info_string.str().c_str() );
   @endcode
 *
 *
 *
 * and at last viz needs to know about the total size of your instance data:
 * @code
    // --------------------------------------------------------------------
    // after registering the plugin data to viz, call
    // 'evRegisterTotalSize' to make sure viz allocated enough memory.
    // NOTE: you can remove this call, if your class does not
    // use any 'private' m_data_.
    // You can not register additional variables after
    // 'evRegisterTotalSize' was called!!!
    evRegisterTotalSize( sizeof( CV_Example ));
   @endcode
 *
 *
 * @warning PLUGIN_INIT_EX() and PLUGIN_INIT() are mutually exclusive functions.
 * conflicts are handled by ignoring the PLUGIN_INIT() if there is a
 * PLUGIN_INIT_EX() found.
 *
 * @note you have to implement one of PLUGIN_INIT() or PLUGIN_INIT_EX().
 * @see PLUGIN_INIT_EX()
 * @see evRegisterParameterFloat(), evRegisterParameterInt(), evRegisterParameterBool(),
 *     evRegisterParameterColor(), evRegisterParameterRadio(), evRegisterParameterString(),
 *     evRegisterParameterFileSelector(), evRegisterParameterDirSelector(),
 *     evRegisterParameterText(), evRegisterParameterList(), ...
 */
VIZPLUGIN_API void PLUGIN_INIT( void );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief initialize instance specific data.
 *
 * is called to construct a new instance of your plugin.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 *
 *
 * this is the place to create a new object of your plugin. example:
 * @code
    VIZPLUGIN_API void PLUGIN_INIT_FUNCTION( void * pvDataPtr )
    {
       // we don need the return value
       // CV_Example * plugin =
       new( pvDataPtr ) CV_Example;
    }
   @endcode
 *
 *
 * @see PLUGIN_COPY_FUNCTION(), PLUGIN_CLEANUP_FUNCTION()
 */
VIZPLUGIN_API void PLUGIN_INIT_FUNCTION( void * pvDataPtr );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief initialize instance specific data.
 *
 * is called to construct a new instance of your plugin as a
 * copy of another instance of the same plugin.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] pvSource pointer to a POD. this is the instance to be copied from.
 *
 *
 * this is the place to create a new object of your plugin with the
 * aid of a copy constructor. example:
 * @code
    VIZPLUGIN_API void PLUGIN_COPY_FUNCTION( void *pvDataPtr, const void *pvSource )
    {
       // we don need the return value
        // CV_Example * plugin =
        new( pvDataPtr ) CV_Example( static_cast< const CV_Example * >( pvSource ));
    }
   @endcode
 *
 *
 * @see PLUGIN_INIT_FUNCTION(), PLUGIN_CLEANUP_FUNCTION()
 */
VIZPLUGIN_API void PLUGIN_COPY_FUNCTION( void * pvDataPtr, const void * pvSource );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief destroy instance specific data.
 *
 * is called right before the destruction of a plugin instance.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 *
 *
 * destroy your object here. example:
 * @code
    VIZPLUGIN_API void PLUGIN_CLEANUP_FUNCTION( void *pvDataPtr )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->~CV_Example();
    }
   @endcode
 *
 *
 * @see PLUGIN_INIT_FUNCTION(), PLUGIN_COPY_FUNCTION()
 */
VIZPLUGIN_API void PLUGIN_CLEANUP_FUNCTION( void * pvDataPtr );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief cleanup plugin specific data.
 *
 * is called right before the plugin is unloaded.
 *
 * @see PLUGIN_INIT(), PLUGIN_INIT_FUNCTION()
 */
VIZPLUGIN_API void PLUGIN_DISPOSE();




// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief is called if a parameter in the GUI was changed.
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] n_VarID is the index of the parameter that was changed
 *            this index starts from 0 and increases by each registered parameter
 *            calling evRegisterParameter{XXX}().
 *
 *
 * a simple forwarder to your class. example:
 * @code
    VIZPLUGIN_API void PLUGIN_CHANGED_CALLBACK( void * pvDataPtr, int n_VarID )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Plugin_Changed_Callback( iVarID );
    }
   @endcode
 *
 *
 *
 * if the GUI changes a parameter you will get notified.
   the parameter n_VarID tells you what has changed.
 * @code
    vizTrace("---> CV_Example::Plugin_Changed_Callback() param=%d\n", n_VarID );

    // char * p; MS VC 6
    switch( n_VarID )
    {
    case ARG_CLIP_FILE:
        // get rid of painful '\\' separator chars
        for( char * p = m_data_.lpsz_clip_file; *p != '\0'; ++p )
        {
            if( *p == '\\' )
            {
                *p = '/';
            }
        }
        Plugin_Exec_Action( BUTTON_CLIP_PLAY );
        break;

    case ARG_LOOP:
    case ARG_PRELOAD_FRAME_COUNT:
        break;

    default:
        vizTrace( "    unknown parameter %d changed.\n", n_VarID );
        break;
    }

    SCENE::redraw();

   @endcode
 *
 *
 * @see evRegisterParameterFloat(), evRegisterParameterInt(), evRegisterParameterBool(),
 *     evRegisterParameterColor(), evRegisterParameterRadio(), evRegisterParameterString(),
 *     evRegisterParameterFileSelector(), evRegisterParameterDirSelector(),
 *     evRegisterParameterText(), evRegisterParameterList(), ...
 */
VIZPLUGIN_API void PLUGIN_CHANGED_CALLBACK( void * pvDataPtr, int n_VarID );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief is called only for geometry plugins.
 *
 *  if it's necessary to rebuild the geometry.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] iLevelOfDetail is the requested level of detail to be rebuilt.
 *
 * is a simple forwarder to your class. example:
 * @code
    VIZPLUGIN_API void PLUGIN_NEW_GEOM( void *pvDataPtr, int iLevelOfDetail )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Plugin_New_Geom( iLevelOfDetail );
    }
  @endcode
 *
 *
 * @code
   @endcode
 *
 *
 */
VIZPLUGIN_API void PLUGIN_NEW_GEOM( void * pvDataPtr, int iLevelOfDetail );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief called once for every field rendered.
 *
 * the exact time this callback function is called depends on its type:
 * @verbatim
     plugin type         call time
     -----------------------------
     geometry            before geometry is drawn
     container           before drawing matrix for the container is calculated
     scene               after animation calculation
     camera              n/a
     light               n/a
   @endverbatim
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 *
 * is a simple forwarder to your class. example:
 * @code
    VIZPLUGIN_API void PLUGIN_EXEC_PER_FIELD( void *pvDataPtr )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Exec_Per_Field_1();
    }
   @endcode
 *
 *
 * @code
   @endcode
 *
 *
 * \sa PLUGIN_EXEC_PER_FIELD2()
 */
VIZPLUGIN_API void PLUGIN_EXEC_PER_FIELD( void * pvDataPtr );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief called once for every field rendered.
 *
 * the exact time this callback function is called depends on its type:
 * @verbatim
     plugin type         call time
     -----------------------------
     geometry            never
     container           never
     scene               between fetching external camera data and recomputing the camera matrix
     camera              n/a
     light               n/a
   @endverbatim
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 *
 * is a simple forwarder to your class. example:
 * @code
    VIZPLUGIN_API void PLUGIN_EXEC_PER_FIELD2( void *pvDataPtr )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Exec_Per_Field_2();
    }
   @endcode
 *
 *
 * @code
   @endcode
 *
 *
 * @see PLUGIN_EXEC_PER_FIELD()
 */
VIZPLUGIN_API void PLUGIN_EXEC_PER_FIELD2( void * pvDataPtr );

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief called once for every field rendered.

    returns the object-IDs of the container(s) whose bounding-box will
    be used by the PLUGIN_EXEC_PER_FIELD_LAYOUT-function and therefore
    need to be up-to-date when that function is called.

    @param[in] pvDataPtr pointer to a POD. this is the memory of the
             plugin instance data.
    @param references array of container-IDs, DON'T clear it, just APPEND.

    @see PLUGIN_EXEC_PER_FIELD_LAYOUT()
 */
VIZPLUGIN_API void PLUGIN_EXEC_PER_FIELD3( void * pData );

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief called once for every field rendered at the end of the render

    returns the object-IDs of the container(s) whose bounding-box will
    be used by the PLUGIN_EXEC_PER_FIELD_LAYOUT-function and therefore
    need to be up-to-date when that function is called.

    @param[in] pvDataPtr pointer to a POD. this is the memory of the
             plugin instance data.
    @param references array of container-IDs, DON'T clear it, just APPEND.

    @see PLUGIN_EXEC_PER_FIELD3()
 */
VIZPLUGIN_API void PLUGIN_GET_LAYOUT_REFERENCES(void *pvDataPtr, THeapArray<int> &references);

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief called once for every field rendered *after* all other exec-per-field functions.
 *
 * when this is called the local container data has been calculated for
 * the whole scene-tree, also the calls are sorted according to the
 * dependencies read through PLUGIN_GET_LAYOUT_REFERENCES. So you
 * can assume that the bounding-boxes you read from other containers
 * are up to date.
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 *
 * \sa PLUGIN_GET_LAYOUT_REFERENCES
 * \sa PLUGIN_EXEC_PER_FIELD()
 */
VIZPLUGIN_API void PLUGIN_EXEC_PER_FIELD_LAYOUT(void *pvDataPtr);

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief an action occured.
 *
 * e.g. is called if a push button is pressed in the GUI
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] n_VarID is the index of the action which has occured.
 *            this index is the same as with calling evRegisterPushButton.
 *
 * is a simple forwarder to your class. example:
 * \code
    VIZPLUGIN_API void PLUGIN_EXEC_ACTION( void *pvDataPtr, int n_VarID )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Plugin_Exec_Action( n_VarID );
    }
   \endcode
 *
 * n_VarID tells you what acction has occured.
 * \code
    vizTrace("---> CV_Example::Plugin_Exec_Action() param=%d\n", n_VarID );

    switch( n_VarID )
    {
    case BUTTON_CLIP_PLAY:
        action_play_();
        break;

    default:
        vizTrace( "    unknown action %d executed.\n", n_VarID );
        break;
    }

    SCENE::redraw();
   \endcode
 *
 * \sa evRegisterPushButton()
 */
VIZPLUGIN_API void PLUGIN_EXEC_ACTION( void * pvDataPtr, int n_VarID );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief after scene load is complete.
 *
 * this functionm is called after viz loaded a scene that includes this plugin.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @note changed from PLUGIN_LOAD in viz 2.x
 *
 * is a simple forwarder to your class. example:
 * \code
    VIZPLUGIN_API void PLUGIN_AFTER_LOAD( void *pvDataPtr )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Plugin_After_Load();
    }
   \endcode
 *
 *
 * this is the proper place to do things after loading.
 * in this example we are simply realying - simulating the change
 * of a parameter (which then triggers further actions):
 * \code
    vizTrace("---> CV_Example::Plugin_After_Load()\n" );

    Plugin_Changed_Callback( ARG_CLIP_FILE );
   \endcode
 *
 * \sa PLUGIN_AFTER_SAVE()
 */
VIZPLUGIN_API void PLUGIN_AFTER_LOAD( void * pvDataPtr );

//! Deprecated. Use PLUGIN_AFTER_LOAD.
VIZPLUGIN_API void PLUGIN_LOAD( void * pvDataPtr );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief called after background-loading an object is finihed
 *
 * this functionm is called after viz has loaded an object in the background.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] iObjectID object ID of the loaded object
 *
 * is a simple forwarder to your class. example:
 * \code
    VIZPLUGIN_API void PLUGIN_OBJECT_LOADED( void *pvDataPtr, int iObjectID )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Plugin_Object_Loaded(iObjectID);
    }
   \endcode
 */
VIZPLUGIN_API void PLUGIN_OBJECT_LOADED( void * pvDataPtr, int iObjectID );

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief called when a request has a new status
*
* this functionm is called whenever a request has a new status.
* @param[in] pvDataPtr pointer to a POD. this is the memory of the
*            plugin instance data.
* @param[in] requestID the ID of the request
* @param[in] the new status (0 = FAILED, 1 = SUCCESS)
* @param[in] iObjectID object ID of the object affected by the request
*
*/
VIZPLUGIN_API void PLUGIN_REQUEST_STATUS_UPDATE(void * pvDataPtr, unsigned int requestId, unsigned int status, int iObjectID);

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief after scene saved.
 *
 * this function is called for each instance after viz saved.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @note changed from PLUGIN_SAVE in viz 2.x
 *
 * is a simple forwarder to your class. example:
 * \code
    VIZPLUGIN_API void PLUGIN_AFTER_SAVE( void *pvDataPtr )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Plugin_After_Save();
    }
   \endcode
 *
 *
 * \code
   \endcode
 *
 *
 * \sa PLUGIN_AFTER_LOAD()
 */
VIZPLUGIN_API void PLUGIN_AFTER_SAVE( void * pvDataPtr );

//! Deprecated. Use PLUGIN_AFTER_SAVE.
VIZPLUGIN_API void PLUGIN_SAVE( void * pvDataPtr );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief status request for the GUI
 *
 * this function is called if the GUI wants to refresh the state of the UI.
 * this would be the proper place where the plugin can set the UI state
 * to enabled/disabled or shown/hidden.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 *
 *
 * is a simple forwarder to your class. example:
 * \code
    VIZPLUGIN_API void PLUGIN_GUI_STATUS( void *pvDataPtr )
    {
        CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
        plugin->Plugin_Gui_Status();
    }
   \endcode
 *
 * enable or disable certain GUI parameters, update the
 * values for other parameters, show or hide parameters, etc.
 * make sure the GUI reflects the state of your plugin correctly.
 * \code
    evSendGuiStatus( "loop", DISABLED );
    evSendGuiParameterShow( "preload_frame_count", ENABLED );
    m_data_. preload_frame_count = some_computation();

    SCENE::redraw();
   \endcode
 *
 *
 * \sa evSendGuiStatus(), evSendGuiParameterShow(), EGUIState
 */
VIZPLUGIN_API void PLUGIN_GUI_STATUS( void * pvDataPtr );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief prior to rendering.
 *
 * this function is called before the render step.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] ulBitMask the bitmask states.
 * @param[in] fAlpha is the transparency of the container.if you are going to use
 *            color in the OpenGL part, you have to multiply your alpha with this parameter.
 *
 *
 * is a simple forwarder to your class. example:
 * \code
     VIZPLUGIN_API void PLUGIN_PRE_RENDER_OPENGL( void *pvDataPtr, unsigned long ulBitMask, float fAlpha )
     {
         CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
         plugin->Plugin_Pre_Render_OpenGL( ulBitMask, fAlpha );
     }
   \endcode
 *
 *
 * \code
   \endcode
 *
 *
 * \sa PLUGIN_RENDER_OPENGL(), PLUGIN_POST_RENDER_OPENGL()
 */
VIZPLUGIN_API void PLUGIN_PRE_RENDER_OPENGL( void * pvDataPtr, unsigned long ulBitMask, float fAlpha );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief during rendering.
 *
 * this function is called when viz renders the container.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] ulBitMask the bitmask states.
 * @param[in] fAlpha is the transparency of the container.if you are going to use
 *            color in the OpenGL part, you have to multiply your alpha with this parameter.
 *
 *
 * is a simple forwarder to your class. example:
 * \code
     VIZPLUGIN_API void PLUGIN_RENDER_OPENGL( void *pvDataPtr, unsigned long ulBitMask, float fAlpha )
     {
         CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
         plugin->Plugin_Render_OpenGL( ulBitMask, fAlpha );
     }
   \endcode
 *
 *
 * \code
   \endcode
 *
 *
 * \sa PLUGIN_RENDER_OPENGL(), PLUGIN_POST_RENDER_OPENGL()
 */
VIZPLUGIN_API void PLUGIN_RENDER_OPENGL( void * pvDataPtr, unsigned long ulBitMask, float fAlpha );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief after rendering.
 *
 * this function is called after viz rendered the container.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] ulBitMask the bitmask states.
 * @param[in] fAlpha is the transparency of the container.if you are going to use
 *            color in the OpenGL part, you have to multiply your alpha with this parameter.
 *
 *
 * is a simple forwarder to your class. example:
 * \code
     VIZPLUGIN_API void PLUGIN_POST_RENDER_OPENGL( void *pvDataPtr, unsigned long ulBitMask, float fAlpha )
     {
         CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
         plugin->Plugin_Post_Render_OpenGL( ulBitMask, fAlpha );
     }
   \endcode
 *
 *
 * \code
   \endcode
 *
 *
 * \sa PLUGIN_RENDER_OPENGL(), PLUGIN_POST_RENDER_OPENGL()
 */
VIZPLUGIN_API void PLUGIN_POST_RENDER_OPENGL( void * pvDataPtr, unsigned long ulBitMask, float fAlpha );


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
VIZPLUGIN_API void PLUGIN_RENDER_CONTAINER( void * pvDataPtr );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief during rendering.
 *
 * this function is called when viz renders the scene.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] iEditor the current editor.
 * @param[in] iFrameNumber the current frame number.
 * @param[in] iWidth the width of the editor.
 * @param[in] iHeight the height of the editor.
 * @param[in] iMask the bitmask states.
 *
 *
 * is a simple forwarder to your class. example:
 * \code
     VIZPLUGIN_API void PLUGIN_SCENE_PRE_RENDER_OPENGL( void* pvDataPtr, int iEditor, int iFrameNumber,
                                                        int iWidth , int iHeight, long iMask )
     {
         CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
         plugin->Plugin_Scene_Pre_Render_OpenGL( iEditor, iFrameNumber, iWidth ,iHeight, iMask );
     }
   \endcode
 *
 *
 * \code
   \endcode
 *
 *
 * \sa PLUGIN_SCENE_POST_RENDER_OPENGL()
 */
VIZPLUGIN_API void PLUGIN_SCENE_PRE_RENDER_OPENGL( void* pvDataPtr, int iEditor, int iFrameNumber,
                                                    int iWidth, int iHeight, long iMask );





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief after rendering.
 *
 * this function is called when viz rendered the scene.
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] iEditor the current editor.
 * @param[in] iFrameNumber the current frame number.
 * @param[in] iWidth the width of the editor.
 * @param[in] iHeight the height of the editor.
 * @param[in] iMask the bitmask states.
 *
 *
 * is a simple forwarder to your class. example:
 * \code
     VIZPLUGIN_API void PLUGIN_SCENE_POST_RENDER_OPENGL( void* pvDataPtr, int iEditor, int iFrameNumber,
                                                        int iWidth , int iHeight, long iMask )
     {
         CV_Example * plugin = static_cast< CV_Example * >( pvDataPtr );
         plugin->Plugin_Scene_Post_Render_OpenGL( iEditor, iFrameNumber, iWidth ,iHeight, iMask );
     }
   \endcode
 *
 *
 * \code
   \endcode
 *
 *
 * \sa PLUGIN_SCENE_PRE_RENDER_OPENGL()
 */
VIZPLUGIN_API void PLUGIN_SCENE_POST_RENDER_OPENGL( void* pvDataPtr, int iEditor, int iFrameNumber,
                                                    int iWidth, int iHeight, long iMask );




// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief container for EFrameFormat codes.
 *
 * lists the possible values for EFrameFormat.
 *
 * @todo documentation to be done.
 */
struct EFrameFormat
{
    /// possible values for EFrameFormat.
    enum Enum
    {
        FramesFullrate = 1,         /*!<   */
        InterlacedTop = 2,          /*!<   */
        InterlacedBottom = 4,       /*!<   */
        FieldsTop = 8,              /*!<   */
        FieldsBottom = 16,          /*!<   */
        FullInterlacedTop = 32,     /*!<   */
        FullInterlacedBottom = 64,  /*!<   */
        FramesDoublerate = 128      /*!<   */
    };
};

/*! @brief container for EPixelFormat codes.
 *
 * lists the possible values for EPixelFormat.
 *
 * @todo documentation to be done.
 */
struct EPixelFormat
{
    /// possible values for EPixelFormat.
    enum Enum
    {
        RGB = 1,        /*!<   */
        RGBA = 2,       /*!<   */
        RGB_AAA = 4,    /*!<   */
        ALPHA = 5       /*!<   */
    };
};

/*! @brief ?
 *
 *
 * \sa EFrameFormat, EPixelFormat
 *
 * @todo documentation to be done.
 */
struct RenderToDiskCapabilities
{
    /// a combination of EFrameFormat constants
    int frameFormats;
    /// a combination of EPixelFormat constants
    int pixelFormats;

    /// default value for EFrameFormat
    EFrameFormat::Enum defaultFrameFormat;
    /// default value for EPixelFormat
    EPixelFormat::Enum defaultPixelFormat;
};

/*! @brief ?
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param pCaps ??
 * \sa RenderToDiskCapabilities
 * @todo documentation to be done.
 */
VIZPLUGIN_API void RENDER_TO_DISK_GET_CAPABILITIES( void * pvDataPtr, RenderToDiskCapabilities * pCaps );

/*! @brief ?
 *
 *
 *
 * \sa RENDER_TO_DISK_CREATE_CLIP(), RENDER_TO_DISK_WRITE_CLIP_DATA()
 *
 * @todo documentation to be done.
 */
struct RenderToDiskClipInfo
{
    // general clip info //

    /// The path name (including file name, but without extension) of the output file.
    const char* clipPath;

    // width and heigt of one frame of the clip to create
    unsigned int uiClipFrameWidth;
    unsigned int uiClipFrameHeight;

    /// width and height of the buffer that viz provides for one field
    unsigned int uiVizBufferFieldWidth;
    ///
    unsigned int uiVizBufferFieldHeight;
    // determines if the buffer that viz provides is interlaced or progressive
    bool bVizBufferInterlaced;

    bool overwriteFile;     // Set TRUE to overwrite existing file(s)
    bool overwriteError;    // Initially FALSE, set to TRUE when plugin cancels because of existing file

    ///
    EFrameFormat::Enum frameFormat;
    ///
    EPixelFormat::Enum pixelFormat;

    //audio properties
    int iChannels;
    int iSamplesPerSec;
    int iBitsPerSample;

    // info for writing individual frames //

    ///
    int     fieldNumber;
    ///
    char *  pData;
};

/*! @brief holds the filenames that are created during the execution of the plugin function call.
 *
 *
 *
 * @see RENDER_TO_DISK_CREATE_CLIP(), RENDER_TO_DISK_WRITE_CLIP_DATA()
 *
 */
struct RenderToDiskClipNames
{
    char const * pszClipNameVideo;
    char const * pszClipNameKey;
    char const * pszClipNameProxy;
    char const * pszClipNameAudio;
    char const * pszClipNameVbi;
};


/*! @brief ?
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] pClipInfo ??
 * \sa RENDER_TO_DISK_CREATE_CLIP()
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API void RENDER_TO_DISK_VIZ_PROPERTIES_CHANGED( void * pvDataPtr, const RenderToDiskClipInfo * pClipInfo );

/*! @brief ?
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] pClipInfo ??
 * \sa RENDER_TO_DISK_WRITE_CLIP_DATA()
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API void RENDER_TO_DISK_CREATE_CLIP( void * pvDataPtr, RenderToDiskClipInfo * pClipInfo, RenderToDiskClipNames * pClipNames );

/*! @brief ?
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] pClipData ??
 * \sa RENDER_TO_DISK_CREATE_CLIP()
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API void RENDER_TO_DISK_WRITE_CLIP_DATA( void * pvDataPtr, const RenderToDiskClipInfo * pClipData, RenderToDiskClipNames * pClipNames );

/*! @brief ?
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * \sa RenderToDiskCapabilities
 */
VIZPLUGIN_API void RENDER_TO_DISK_CLOSE_CLIP( void * pvDataPtr );

/*! @brief called before a post render template is loaded
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * \sa RENDER_TO_DISK_TEMPLATE_LOAD_BEGIN
 *
 * @todo documentation to be done.
*/
VIZPLUGIN_API void RENDER_TO_DISK_TEMPLATE_LOAD_BEGIN( void * pvDataPtr );

/*! @brief called after a post render template is loaded
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * \sa RENDER_TO_DISK_TEMPLATE_LOAD_DONE
 *
 * @todo documentation to be done.
*/
VIZPLUGIN_API void RENDER_TO_DISK_TEMPLATE_LOAD_DONE( void * pvDataPtr );

/*! @brief Optional function to define an order in which the parameters should be restored when loaded from a template
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[out] piNumParameter pointer where the number of parameters is stored.
 * @param[out] ppiParameterList pointer to an array where the parameter order should be stored.
 *             If this is NULL only the number of parameters should be returned
 *             (to allocate the array and call this function again).
 * \code
     VIZPLUGIN_API void RENDER_TO_DISK_PARAMETER_ORDER( void *pvDataPtr, int * piNumParameter, int ** ppiParameterList )
     {
         *piNumParameter = m_iNumParameter;
         if (ppiParameterList) {
            for(int i = 0; i < m_iNumParameter; ++i) {
                (*ppiParameterList)[i] = i;
            }
         }
     }
   \endcode
 * \sa RENDER_TO_DISK_PARAMETER_ORDER
 *
 * @todo documentation to be done.
*/
VIZPLUGIN_API void RENDER_TO_DISK_PARAMETER_ORDER( void * pvDataPtr, int * piNumParameter, int ** ppiParameterList );


/*! @brief called to restore a ordered parameter
 *
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] iIndex index of the parameter
 * @param[in] pData value of the parameter
 * \sa RENDER_TO_DISK_TEMPLATE_LOADED
 *
 * @todo documentation to be done.
*/
VIZPLUGIN_API void RENDER_TO_DISK_PARAMETER_RESTORE( void * pvDataPtr, int iIndex, void* pData );


/// the bitmask states for the OpenGL plugins (works for PLUGIN_RENDER_OPENGL only right now !!!)
#define EV_OGL_DRAW_PLAIN       1


/*! @brief Deprecated. Use PLUGIN_MOUSE_MOVE, etc. instead.
 *
 * @param[in] pvDataPtr pointer to a POD. This is the memory of the
 *            plugin instance data.
 * @param[in] hEditor identifies the editor, receiving this event
 * @param[in] uEvent event type. possible values are listed under Viz_Event_Types_t
 * @param[in] uFlags event dependant states
 * @param[in] dwExt additional event dependant data.
       \verbatim
              mouse events: LOWORD(dwExt) = x-pos; HIWORD(dwExt) = y-pos of the mouse
              key-events:   LOWORD(dwExt) = repeat-count; HIWORD(dwExt) = modifier-key state
        \endverbatim
 * @return 0 ... tell viz to proceed with event processing, 1 ... tell viz not to handle this event and not to dispatch this event
 * \sa Viz_Event_Types_t
 */
VIZPLUGIN_API int PLUGIN_ON_INPUT_EVENT(void* pvDataPtr, HEDITOR hEditor, unsigned short uEvent, unsigned short uFlags, unsigned long dwExt);


/*! @brief Deprecated. Ported from 2.8 for compatibility only. Use PLUGIN_MOUSE_MOVE, etc. instead.
//=========================================================================
//  PLUGIN_MOUSE_CALLBACK
//
//  is called when a mouse event happens. parameters:
//
//  int win_id .......... see above
//  int event ........... if it was a button event or a window enter/leave
//                        event. there are two defines, EV_MOUSE_BUTPRESS
//                        and EV_MOUSE_ENTER
//  int onoff ........... true means button pressed or mouse entered window
//                        false means button released or mouse left window
//  int button .......... which mouse button was pressed/released
//  int x, int y ........ mouse position
//  ulong time .......... see above
//  bool &clear_event ... see above
//=========================================================================
*/
VIZPLUGIN_API void PLUGIN_MOUSE_CALLBACK(void *dataptr, int win_id, int event, int onoff, int button, int x, int y, unsigned long time, bool &clear_event);


/*! @brief Deprecated. Ported from 2.8 for compatibility only. Use PLUGIN_KEY_DOWN, etc. instead.
//=========================================================================
//  PLUGIN_KEYBOARD_CALLBACK
//
//  is called when a keyboard event happens. parameters:
//
//  int win_id .......... window id
//  int onoff ........... true means key was pressed, false means released
//  int key_code ........ the key that was pressed/released (see evIODef.h)
//  ulong time .......... the time when the event happened
//  bool &clear_event ... set this to true if you don't want that other
//                        plugins or viz will process this event
//=========================================================================
*/
VIZPLUGIN_API void PLUGIN_KEYBOARD_CALLBACK(void *dataptr, int win_id, int onoff, int key_code, unsigned long time, bool &clear_event);


/*! @brief EnterContainer Callback
 *
 * @param[in] pvDataPtr Pointer to instance specific data.
 *
 * This callback is invoked when the mouse cursor enters the
 * area occupied by the container in the output window.
 *
 * \sa evSetCallEnterLeaveForTopObjectsOnly, CONTAINER::set_exact_picking, CONTAINER::contains_mouse_cursor, CONTAINER::is_on_top
 */
VIZPLUGIN_API void PLUGIN_ENTER_CONTAINER(void* pvDataPtr);


/*! @brief LeaveContainer Callback
 *
 * @param[in] pvDataPtr Pointer to instance specific data.
 *
 * This callback is invoked when the mouse cursor leaves the
 * area occupied by the container in the output window.
 *
 * \sa evSetCallEnterLeaveForTopObjectsOnly, CONTAINER::set_exact_picking, CONTAINER::contains_mouse_cursor, CONTAINER::is_on_top
 */
VIZPLUGIN_API void PLUGIN_LEAVE_CONTAINER(void* pvDataPtr);


/*! @brief EnterSubContainer Callback
 *
 * @param[in] pvDataPtr Pointer to instance specific data.
 * @param[in] containerId The viz id of the sub-container being entered.
 *
 * This callback is invoked when the mouse cursor enters the
 * area occupied by a sub-container of the local container.
 *
 * \sa evSetCallEnterLeaveForTopObjectsOnly, CONTAINER::set_exact_picking, CONTAINER::contains_mouse_cursor, CONTAINER::is_on_top
 */
VIZPLUGIN_API void PLUGIN_ENTER_SUB_CONTAINER(void* pvDataPtr, int containerId);


/*! @brief LeaveSubContainer Callback
 *
 * @param[in] pvDataPtr Pointer to instance specific data.
 * @param[in] containerId The viz id of the sub-container being left.
 *
 * This callback is invoked when the mouse cursor leaves the
 * area occupied by a sub-container of the local container.
 *
 * \sa evSetCallEnterLeaveForTopObjectsOnly, CONTAINER::set_exact_picking, CONTAINER::contains_mouse_cursor, CONTAINER::is_on_top
 */
VIZPLUGIN_API void PLUGIN_LEAVE_SUB_CONTAINER(void* pvDataPtr, int containerId);

/*! brief MouseMove Callback
 *
 * \sa evSetCallMouseMoveForTopObjectsOnly
 */
VIZPLUGIN_API void PLUGIN_MOUSE_MOVE(void* pvDataPtr, int x, int y);

/*! brief LButtonDown Callback
 *
 * \sa evSetCallButtonDownForTopObjectsOnly
 */
VIZPLUGIN_API void PLUGIN_LBUTTON_DOWN(void* pvDataPtr);

/*! brief MButtonDown Callback
 *
 * \sa evSetCallButtonDownForTopObjectsOnly
 */
VIZPLUGIN_API void PLUGIN_MBUTTON_DOWN(void* pvDataPtr);

/*! brief RButtonDown Callback
 *
 * \sa evSetCallButtonDownForTopObjectsOnly
 */
VIZPLUGIN_API void PLUGIN_RBUTTON_DOWN(void* pvDataPtr);

/*! brief LButtonUp Callback
 */
VIZPLUGIN_API void PLUGIN_LBUTTON_UP(void* pvDataPtr);

/*! brief MButtonUp Callback
 */
VIZPLUGIN_API void PLUGIN_MBUTTON_UP(void* pvDataPtr);

/*! brief RButtonUp Callback
 */
VIZPLUGIN_API void PLUGIN_RBUTTON_UP(void* pvDataPtr);

/*! brief MouseWheel Callback
* \sa evSetCallMouseWheelForTopObjectsOnly
 */
VIZPLUGIN_API void PLUGIN_MOUSE_WHEEL(void* pvDataPtr, int iDistance);

/*! brief KeyDown Callback
    @param pvDataPtr ?
    @param[in] keyCode The virtual-key code of the key pressed.
 */
VIZPLUGIN_API void PLUGIN_KEY_DOWN(void* pvDataPtr, int keyCode);

/*! brief KeyUp Callback
    @param pvDataPtr ?
   @param[in] keyCode The virtual-key code of the key released.
 */
VIZPLUGIN_API void PLUGIN_KEY_UP(void* pvDataPtr, int keyCode);

VIZPLUGIN_API void PLUGIN_BUTTON_DOWN_6DOF(void* pvDataPtr, int button, const evVertex3D& pos, const evVertex3D& rot);

VIZPLUGIN_API void PLUGIN_BUTTON_UP_6DOF(void* pvDataPtr, int button, const evVertex3D& pos, const evVertex3D& rot);

VIZPLUGIN_API void PLUGIN_MOVE_6DOF(void* pvDataPtr, int button, const evVertex3D& pos, const evVertex3D& rot);

VIZPLUGIN_API void PLUGIN_MOVE_RELATIVE_6DOF(void* pvDataPtr, int button, const evVertex3D& pos, const evVertex3D& rot);

VIZPLUGIN_API void PLUGIN_SCALE_6DOF(void* pvDataPtr, int button, const evVertex3D& scale);

VIZPLUGIN_API void PLUGIN_VIDEO_SAMPLING_FINISHED(void* pvDataPtr, int videoChannelId);

/*! @brief Multitouch callbacks
 */
VIZPLUGIN_API void PLUGIN_MT_HIT(void* pvDataPtr, int stroke, int x, int y);

VIZPLUGIN_API void PLUGIN_MT_MENU(void* pvDataPtr, int x, int y);

VIZPLUGIN_API void PLUGIN_MT_CONTROL_PZR2D(void* pvDataPtr, int x, int y, const evVertex3D& rot, const evVertex3D& scale, float pressure);

VIZPLUGIN_API void PLUGIN_MT_CONTROL_BUTTON(void* pvDataPtr, int strokes, float pressure);

VIZPLUGIN_API void PLUGIN_MT_CONTROL_INACTIVE(void* pvDataPtr);

/*! @brief is called on any Trace event (TOUCH_DOWN, TOUCH_MOVE, TOUCH_UP)
 *
 * Note that Trace IDs and Stroke IDs of other callbacks are identical (e.g.: PLUGIN_MT_HIT can be easily used for hit testing of traces).
 */
VIZPLUGIN_API void PLUGIN_TOUCH_TRACE(void* pvDataPtr, unsigned int iTraceId, unsigned int iTouchIndex);

VIZPLUGIN_API void PLUGIN_GESTURE(void* pvDataPtr, unsigned int iGestureId);

/*! @brief is called if the rigidbody collides with another rigibody
*/
VIZPLUGIN_API void PLUGIN_ON_CONTACT(void* pvDataPtr, int container);

/*! @brief is called if a rigidbody enters the trigger
*/
VIZPLUGIN_API void PLUGIN_TRIGGER_ENTER(void* pvDataPtr, int container);

/*! @brief is called if a rigidbody is inside the trigger
*/
VIZPLUGIN_API void PLUGIN_TRIGGER_STAY(void* pvDataPtr, int container);

/*! @brief is called if a rigidbody leaves the trigger
*/
VIZPLUGIN_API void PLUGIN_TRIGGER_EXIT(void* pvDataPtr, int container);


/*! @brief is called if VIZ::hit_test picked one or more objects
 *
 * The hits are z-sorted, starting with top-most object.
 */
typedef struct _HitData
{
    int iObjectID;
    int iLayerID;
} HitData;
VIZPLUGIN_API void PLUGIN_HIT_TEST_RESULT(void* pvDataPtr, int iStrokeID, const HitData* pHits, int iNumHits);

/*! @brief is called when other plugin sends message to this plugin.
 *
 * ??
 * @param[in] dataptr ??
 * @param[in] msg message id
 * @param[in] param message parameter
 * @param[out] ret return value
 *
 * @todo how do i send a message to another plugin?
 * @todo documentation to be done. ran
 */
//VIZPLUGIN_API __declspec(deprecated("function is deprecated. please use PLUGIN_DISPATCHER_CALLBACK_PTR instead.")) void PLUGIN_DISPATCHER_CALLBACK( void * dataptr, unsigned long msg, unsigned long param, unsigned long & ret );
//VIZPLUGIN_API void PLUGIN_DISPATCHER_CALLBACK( void * dataptr, unsigned long msg, unsigned long param, unsigned long & ret );
VIZPLUGIN_API void PLUGIN_DISPATCHER_CALLBACK( void * dataptr, ULONG_PTR msg, ULONG_PTR param, ULONG_PTR & ret );

/*! @brief Callback signalling a change of a SHARED_MEMORY variable.
*
* @param[in] pInstanceData Pointer to instance data (to be cast to PLUGIN_DATA).
* @param[in] sharedMemoryId Id of the SHARED_MEMORY object in which the change occured.
*            Pass sharedMemoryId to the constructor of SHARED_MEMORY to create a valid object.
* @param[in] key The key identifying the variable that has been changed.
*
* This callback is invoked in response to a SHARED_MEMORY variable being changed (by a call
* to SHARED_MEMORY::set_value or an equivalent script command). It is invoked only for those
* variables for which SHARED_MEMORY::register_changed_callback was previously called.
*/
VIZPLUGIN_API void PLUGIN_SHARED_MEMORY_VARIABLE_CHANGED(void* pInstanceData, int sharedMemoryId, const char* key);


/*! @brief Callback signalling that a SHARED_MEMORY variable has been deleted.
*
* @param[in] pInstanceData Pointer to instance data (to be cast to PLUGIN_DATA).
* @param[in] sharedMemoryId Id of the SHARED_MEMORY object in which the deletion occured.
*            Pass sharedMemoryId to the constructor of SHARED_MEMORY to create a valid object.
* @param[in] key The key identifying the variable that has been deleted.
*
* This callback is invoked in response to a SHARED_MEMORY variable being deleted (by a call
* to SHARED_MEMORY::delete_key or an equivalent script command). It is invoked only for those
* variables for which SHARED_MEMORY::register_changed_callback was previously called.
*/
VIZPLUGIN_API void PLUGIN_SHARED_MEMORY_VARIABLE_DELETED(void* pInstanceData, int sharedMemoryId, const char* key);



//=========================================================================
//  PLUGIN_GET_GEOMETRY_STATUS
//
//  a shader can force viz to render geometry with normals, texcoords ...
//  This call also tells viz if the shader renders transparency
//  valid return values are:
//  is_transparent: true or false
//
//  need_normals, need_tex_coords:
//  SHADER_GEOMETRY_REQUIREMENT_DONT_CARE       The shader does not want to override the current viz setting
//  SHADER_GEOMETRY_REQUIREMENT_YES             The shader must have this property
//  SHADER_GEOMETRY_REQUIREMENT_NO              The shader does not need this property
//  e.g. if the shader ALWAYS generates texture coordinates there is no need to render them from viz,
//  so the shader should use PLUGIN_GET_GEOMETRY_STATUS and set need_tex_coords to SHADER_GEOMETRY_REQUIREMENT_NO
//=========================================================================
#define SHADER_GEOMETRY_REQUIREMENT_DONT_CARE   0
#define SHADER_GEOMETRY_REQUIREMENT_YES         1
#define SHADER_GEOMETRY_REQUIREMENT_NO          2
VIZPLUGIN_API void PLUGIN_GET_SHADER_GEOMETRY_REQUIREMENT(void *pvDataPtr, bool& is_transparent, int& need_normals, int& need_tex_coords,
                                                       int& needTangentSpace, int& needBinormal, int& unused1, int& unused2, int& unused3);
 

/*! @brief Callback signalling that a registered geometry has changed.
*
* @param[in] pInstanceData Pointer to instance data (to be cast to PLUGIN_DATA).
* @param[in] geomId Id of the GEOMERY object in which the change occured.
*/
VIZPLUGIN_API void PLUGIN_GEOMETRY_CHANGED(void* pInstanceData, int geomId);

#ifdef MAX_NUMBER_OT_TT_PIX
#if MAX_NUMBER_OT_TT_PIX != (2)
#error value of MAX_NUMBER_OT_TT_PIX macro is inconsistend please check other definitions
#endif //MAX_NUMBER_OT_TT_PIX != (2)
#else
#define MAX_NUMBER_OT_TT_PIX        (2)
#endif //MAX_NUMBER_OT_TT_PIX

#ifndef VIZEXTERN_HAVE_FREETYPE
//=========================================================================
// Fontstyle stuff ...

#define FT_CURVE_TAG( flag )  ( flag & 3 )
typedef unsigned char BYTE ;
typedef unsigned short    WORD;
const int STATIC_BITMAP_WIDTH = 1024 ;
typedef signed long  FT_Pos;


#ifdef _DOUBLE_DEFS
#define FT_Curve_Tag_On           1
#define FT_Curve_Tag_Conic        0
#define FT_Curve_Tag_Cubic        2

/*! @brief ?
 *
 *
 * @todo documentation to be done.
 */
struct FT_BBox_
{
    ///
    FT_Pos  xMin;
    ///
    FT_Pos  yMin;
    ///
    FT_Pos  xMax;
    ///
    FT_Pos  yMax;
};
typedef struct  FT_BBox_ FT_BBox;
/*! @brief ?
 *
 *
 * @todo documentation to be done.
 */
struct FT_Vector_
{
    ///
    FT_Pos  x;
    ///
    FT_Pos  y;

};
typedef struct  FT_Vector_ FT_Vector;
#endif // #ifdef _DOUBLE_DEFS

/*! @brief ?
 *
 *
 * @todo documentation to be done.
 */
struct TT_PIX
{
    ///
    WORD trueRows ;
    ///
    WORD trueWidth ;
    ///
    WORD rows ;
    ///
    WORD width ;
    ///
    WORD startY ;
    ///
    WORD startX ;
    ///
    BYTE buffer[ STATIC_BITMAP_WIDTH * STATIC_BITMAP_WIDTH ];
    ///
    FT_BBox Bbox ;
};


#ifdef _DOUBLE_DEFS
/*! @brief ?
 *
 *
 * @todo documentation to be done.
 */
struct  FT_Outline_
{
    /// number of contours in glyph
    short       n_contours;
    /// number of points in the glyph
    short       n_points;
    /// the outline's points
    FT_Vector*  points;
    /// the points flags
    char*       tags;
    /// the contour end points
    short*      contours;
    /// outline masks
    int         flags;

};
typedef struct  FT_Outline_ FT_Outline;
#endif // #ifdef _DOUBLE_DEFS




/*! @brief ?
 *
 *
 * @todo documentation to be done.
 */
struct glyphMetrics
{
    ///
    float   xMin;                   // bounding box character
    ///
    float   yMin;
    ///
    float   xMax;
    ///
    float   yMax;
    ///
    float   zMin ;
    ///
    float   zMax ;

    ///
    glyphMetrics()
    {
        xMin = 0.0f;
        xMax = 0.0f;
        yMin = 0.0f;
        yMax = 0.0f;
        zMin = 0.0f;
        zMax = 0.0f;
    }
};


#endif // VIZEXTERN_HAVE_FREETYPE

/*! @brief ?
 *
 *
 * @todo documentation to be done.
 */
enum
{
    MODIFY_CHANGE_NONE      = (0<<0) ,      /*!<    */
    MODIFY_CHANGE_TEX       = (1<<0) ,      /*!<    */
    MODIFY_CHANGE_CONTOUR   = (1<<1) ,  /*!<    */
    MODIFY_CHANGE_GEOM      = (1<<2) ,      /*!<    */
    MODIFY_CHANGE_ALL       = (MODIFY_CHANGE_TEX|MODIFY_CHANGE_CONTOUR|MODIFY_CHANGE_GEOM)  /*!<    */
};

/*! @brief ?
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param pchLastTtPix
 * @param ppTTPix
 * @param[in] iTexLevel
 * @param[in] iIndex
 * @return ??
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API int PLUGIN_MODIFIER_TEXTURE( void * pvDataPtr, unsigned char * pchLastTtPix,  TT_PIX ** ppTTPix, int iTexLevel, int iIndex );

/*! @brief ?
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] outline
 * @param[in] iIndex
 * @return ??
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API int PLUGIN_MODIFIER_CONTOUR( void * pvDataPtr, FT_Outline * outline, int iIndex );

/*! @brief If implemented, this function is called before PLUGIN_MODIFIER_CONTOUR.
 *         The plugin can specify the desired output of n_points and n_contours
 *         for the FT_Outline struct. When the PLUGIN_MODIFIER_CONTOUR is called,
 *         the struct will have enough memory reserved.
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] outline
 * @param[in,out] maxContours pointer to set maximum number of contours.
 * @param[in,out] maxPoints pointer to set maximum number of points.
 * @param[in] iIndex
 * @return ??
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API int PLUGIN_PRE_MODIFIER_CONTOUR( void * pvDataPtr, const FT_Outline * outline, short *maxContours, short *maxPoints, int iIndex );

/*! @brief ?
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] pGeom
 * @param[in] pMetrics
 * @param[in] iTexGeom
 * @param[in] iIndex
 * @return ??
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API int PLUGIN_MODIFIER_GEOMETRY( void * pvDataPtr,void * pGeom, const glyphMetrics * pMetrics, int iTexGeom, int iIndex );

/*! @brief ?
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] pGeom
 * @param[in] pMetrics
 * @param[in] iTexGeom
 * @param[in] iIndex
 * @return ??
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API int PLUGIN_MODIFIER_DRAW_GEOM( void * pvDataPtr,void * pGeom , const glyphMetrics * pMetrics, int iTexGeom, int iIndex );

/*! @brief ?
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] outline
 * @param[in] iIndex
 * @return ??
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API int PLUGIN_MODIFIER_DRAW_CONTOUR( void * pvDataPtr, FT_Outline * outline , int iIndex );

/*! @brief ?
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @return ??
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API int PLUGIN_MODIFIER_GET_CHANGED( void * pvDataPtr );


/*! @brief Mulitouch Control Types
 *
 *
 * @todo documentation to be done.
 */


enum MTControlTypes {
    MT_CONTROL_BUTTON = 1,
    MT_CONTROL_PZR2D,
    MT_CONTROL_PZR2D_TILT
};

/*! @brief Touch Event Types
 *
 *
 * @todo documentation to be done.
 */
enum TouchEvent {
    TOUCH_DOWN = 1,
    TOUCH_MOVE,
    TOUCH_UP
};

/*! @brief Gesture Event Types
 *
 *
 * @todo documentation to be done.
 */
enum GestureEvent {
    GESTURE_MANIPULATION_START = 1,
    GESTURE_MANIPULATION_STOP,
    GESTURE_MOMENTUM_START,
    GESTURE_MOMENTUM_STOP,
    GESTURE_TAP,
    GESTURE_DOUBLE_TAP,
    GESTURE_TAP_HOLD,
    GESTURE_TRANSFORMATION,
    GESTURE_PATTERN
};

/*! @brief Gesture Pattern Types
 *
 *
 * @todo documentation to be done.
 */
enum GesturePatternType {
    PATTERN_INVALID = 0,
    PATTERN_RIGHT,
    PATTERN_LEFT,
    PATTERN_UP,
    PATTERN_DOWN,
    PATTERN_CIRCLE,
    PATTERN_SQUARE,
    PATTERN_TRIANGLE
};

/*! @brief Grid Types
 *
 *
 * @todo documentation to be done.
 */
enum GridTypes {
    GRID_TYPE_NONE = 0,
    GRID_TYPE_XY,
    GRID_TYPE_XZ,
    GRID_TYPE_ZY,
    GRID_TYPE_FREE
};


/*! @brief Write data to "ExtraData" file-unit.
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 * @param[in] pszDataNode name of node to be written.
 *
 * If PLUGIN_WRITE_EXTRA_DATA is present in the plugin, viz is calling
 * this function after scene-data has been saved.
 * In PLUGIN_WRITE_EXTRA_DATA, the plugin should write XML-formated-Strings.
 * Optionally, the plugin may register one or more data-nodes under which
 * it want to save data. The current data-node is passed over to the plugin through
 * pszDataNode. PLUGIN_WRITE_EXTRA_DATA may be called multiple times, if more
 * than one data-node has been registered.
 *
 * @see evRegisterDataNode PLUGIN_INIT evWriteData_binary
 */
VIZPLUGIN_API void PLUGIN_WRITE_EXTRA_DATA(const void* pvDataPtr, const char* pszDataNode);


/*! @brief ?
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API void PLUGIN_READ_DATA( void * pvDataPtr );

/*! @brief ?
 *
 * @param[in] pvDataPtr pointer to a POD. this is the memory of the
 *            plugin instance data.
 *
 * @todo documentation to be done.
 */
VIZPLUGIN_API void PLUGIN_WRITE_DATA( void * pvDataPtr );

/*! @brief ?
*
* @param[active] is called when entering preview mode (active == 1) 
*                or leaving preview mode (active == 0)
*
* @todo documentation to be done.
*/
VIZPLUGIN_API void PLUGIN_ON_PREVIEW(void * pvDataPtr, int active);

/*! @brief Get progress of ready for drawing.
*
* @param[in]  pvDataPtr pointer to a POD. this is the memory of the
*             plugin instance data.
* @param[out] status refer to ready to render status, plugin have to
*             change value to 1 if it is ready to render.
* @param[out] progress optional pointer to progress of preparing of
*             renderer. If it is not null pointer and plugin doesn't
*             ready to reder yet, plugin can change pointed value to
*             preparing progressive (0 to 99).
*/
VIZPLUGIN_API void PLUGIN_READY_TO_RENDER(void* pvDataPtr, int& status, int* progress);

/*! @brief Get status of ready for drawing asynchronously.
*             Do not use any other plugin APIs within the scope of this
*             callback since it is not executed from the main thread
*             for threadsafe!
*
* @param[in]  pvDataPtr pointer to a POD. this is the memory of the
*             plugin instance data.
* @param[out] ready refer to the status after full initialization of
*             plugin including all required resources. Changes this
*             value to 1 if plugin is ready to render, set to 0 if
*             something went wrong and it can't reach the ready state.
*/
VIZPLUGIN_API void PLUGIN_READY_TO_RENDER_ASYNC(void* pvDataPtr, int& ready);

/*! @brief Get a embedded gui window handle.
*
* @param[in]  pvDataPtr pointer to a POD. this is the memory of the
*             plugin instance data.
* @param[in] embedded viz artist window handle for docked and undocked window.
*/
VIZPLUGIN_API void PLUGIN_GUI_SET_WINDOW_HANDLE(void* pvDataPtr, void* hwnd);

/*! @brief Get the size of the embedded window handle.
*
* @param[in]  pvDataPtr pointer to a POD. this is the memory of the
*             plugin instance data.
* @param[in]  width of the window (use _api__gui_send_window_size if window is bigger and
*             scrollbar should be shown)
* @param[in]  height of the window (use _api__gui_send_window_size if window is bigger and
*             scrollbar should be shown)
*/
VIZPLUGIN_API void PLUGIN_GUI_SET_WINDOW_SIZE(void* pvDataPtr, unsigned int uiWidth, unsigned int uiHeight);

/*! @brief Get a embedded gui window handle.
*
* @param[in]  pvDataPtr pointer to a POD. this is the memory of the
*             plugin instance data.
* @param[in]  tab index (0 is reserved for the generated UI parameters)
* @param[in]  embedded viz artist window handle for this tab
*/
VIZPLUGIN_API void PLUGIN_GUI_SET_WINDOW_TAB_HANDLE(void* pvDataPtr, unsigned int tabIndex, void* hwnd);

/*! @brief Get the size of the embedded window handle.
*
* @param[in]  pvDataPtr pointer to a POD. this is the memory of the
*             plugin instance data.
* @param[in]  tab index (0 is reserved for the generated UI parameters)
* @param[in]  width of the tab window (use _api__gui_send_window_size if window is bigger and
*             scrollbar should be shown)
* @param[in]  height of the tab window (use _api__gui_send_window_size if window is bigger and
*             scrollbar should be shown)
*/
VIZPLUGIN_API void PLUGIN_GUI_SET_WINDOW_TAB_SIZE(void* pvDataPtr, unsigned int tabIndex, unsigned int uiWidth, unsigned int uiHeight);

#ifdef __cplusplus
}
#endif

#endif // EV_PLUGIN_PLUGINFUNC_H
