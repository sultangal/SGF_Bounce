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

#if ! defined( EV_PLUGIN_PLUGINEXTERN_H )
#define EV_PLUGIN_PLUGINEXTERN_H

#include "evPlugin_DynInterface.h"

// this include needs to be before the defines for the printf family otherwise
// the compiler chokes during include of cstdio
#ifdef __cplusplus
#include <string>
#endif




// do not redirect printf if we are compiling VizArtist
#if ! defined( VIZENGINE_EXPORTS )
#pragma deprecated( "printf", "vprintf", "wprintf", "vwprintf" )
#define printf          _vizprintf      // force printf to viz console.
#define vprintf         _vizvprintf     // force vprintf to viz console.
#define wprintf         _vizwprintf     // force wprintf to viz console.
#define vwprintf        _vizvwprintf    // force vwprintf to viz console.


// To generate debug output on the viz console just use vizTrace() as you would use printf()
// Any vizTrace() statements are removed by the compiler if you compile for release.
#if defined( _DEBUG )
    #define vizTrace _vizprintf
#else
    inline void voidTrace(const char*, ...) { }
    #define vizTrace              1 ? (void)0 : ::voidTrace
#endif

#endif // #if ! defined( VIZENGINE_EXPORTS )

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------

#include <stdarg.h>


#ifdef __cplusplus
extern "C" {
#endif

/*! @brief write output to viz console
*/
VIZENGINE_API int
_vizprintf(const char* fmt, ...);
VIZENGINE_API int
_vizwprintf(const wchar_t* fmt, ...);
VIZENGINE_API int
_vizvprintf(const char* fmt, va_list args);
VIZENGINE_API int
_vizvwprintf(const wchar_t* fmt, va_list args);

/*! @brief enumeration types of plugin types.
 *
 * lists the differnt plugin types available and to be used with
 * evRegisterPluginType function.
 *
 * depending on the type there is minimum set of
 * function callbacks which have to be implemented.
   - function plugins (EV_FUNCTION_CONTAINER, EV_FUNCTION_SCENE, EV_FUNCTION_CAMERA, EV_FUNCTION_LIGHT, EV_COMMAND)
     must implement PLUGIN_INIT_FUNCTION() and in addition one of the following:
     - PLUGIN_EXEC_PER_FIELD()
     - PLUGIN_EXEC_PER_FIELD2()
     - PLUGIN_EXEC_PER_FIELD3()
     - PLUGIN_EXEC_ACTION()

   - geometry plugins (EV_GEOMETRY) must implement one of the following:
     - PLUGIN_NEW_GEOM()
     - PLUGIN_RENDER_OPENGL()

   - modifier plugins (EV_MODIFIER) must implement PLUGIN_MODIFIER_GET_CHANGED()
     and in addition one of the following:
     - PLUGIN_MODIFIER_TEXTURE()
     - PLUGIN_MODIFIER_CONTOUR()
     - PLUGIN_MODIFIER_GEOMETRY()

   - render-to-disk plugins (EV_RENDER_TO_DISK) must implement one of the following:
     - RENDER_TO_DISK_CREATE_CLIP()
     - RENDER_TO_DISK_WRITE_CLIP_DATA()
 *
 *
 * \sa evRegisterPluginType().
 */
enum VIZ_Plugin_Type_t
{
    EV_UNKOWN = 0,                          /*!<  do not use this value                   */
    EV_GEOMETRY = 1,                        /*!<  this is a geometry plugin (default)     */
    EV_FUNCTION = 2,                        /*!<  this is a function plugin for container */
    EV_FUNCTION_CONTAINER = EV_FUNCTION,    /*!<  this is a function plugin for container */
    /* 3 not used */
    EV_FUNCTION_SCENE = 4,                  /*!<  this is a function plugin for scene     */
    EV_FUNCTION_CAMERA = 5,                 /*!<  not supported                           */
    EV_FUNCTION_LIGHT = 6,                  /*!<  not supported                           */
    EV_COMMAND = 7,                         /*!<  not supported                           */
    EV_MODIFIER = 8,                        /*!<  this is a modifier plugin for fonts     */
    EV_SHADER = 9,                          /*!<  this is a shader plugin for containers  */

    /* device specific plugin types */
    EV_PLUGINTYPE_DEVICE_CONTROL = 10,      /*!<  not supported                           */
    EV_PLUGINTYPE_DEVICE_RENDER = 11,       /*!<  not supported                           */
    EV_RENDER_TO_DISK = 12,                 /*!<  this is a render-to-disk plugin         */
};




/*! @brief register plugin with viz
 *
 * registers the plugin with viz. no instance of this plugin is created.
 * @param pszPluginName The name of the plugin. This name is presented to the
 *                      viz user through the graphical user interface.
 * \sa evRegisterPluginFolder(), evRegisterPluginType()
 */
VIZENGINE_API void evRegisterPlugin( const char * pszPluginName );

/*! @brief Register the folder of the plugin to the viz system.
 *
 * this name is presented to the viz user through the graphical user interface
 * the plugin can then be accessed from this folder.
 * @param pszPluginFolder the name of the folder. it may consist of a
 *        single directory only. no path seperators are allowed.
 *
 * \sa evRegisterPlugin(), evRegisterPluginType()
 */
VIZENGINE_API void evRegisterPluginFolder( const char * pszPluginFolder );

/*! @brief register UAC compatible folders for the Plugin
*
* Register the folders where the Plugin is supposed to stores its local and temporary data.
* Call this function after evRegisterPlugin because it needs the Plugin's name !
*/
VIZENGINE_API void evRegisterPluginUACfolders( void );

/*! @brief state this Shader Plugin can be used with enlighten
*
* If a shader plugin calls this function viz knows that it can be used when Global Illumination FX
* is enabled.
*/
VIZENGINE_API void evRegisterGlobalIlluminationFX(void);

/*! @brief get full file path of the Plugin.
*
* @return a pointer pointing to the full file path of the Plugin.
*/
VIZENGINE_API const char* evGetPluginFilePath(void);

/*! @brief get Program Data subfolder
*
* @return a pointer pointing to the subfolder in "Program Data" where the Plugin stores its local data
*/
__declspec(deprecated(" this is a deprecated function. Please use evGetPluginDataFolder()"))
VIZENGINE_API const char* evGetPluginDataFolderA(void);
VIZENGINE_API const wchar_t* evGetPluginDataFolder( void );

/*! @brief get Program Data subfolder
*
* @param bPluginSpecific if true include the Plugin's name in the folder to make it plugin specific
* @return a pointer pointing to the subfolder in "Program Data" where the Plugin stores its temporary data
*/
__declspec(deprecated(" this is a deprecated function. Please use evGetPluginTempFolder()"))
VIZENGINE_API const char* evGetPluginTempFolderA(bool bPluginSpecific = false);
VIZENGINE_API const wchar_t* evGetPluginTempFolder( bool bPluginSpecific = false );

/*! @brief Register a node-name for extra-data-plugins.
 *
 * this nodename is used, if extra-data plugins are called
 * to save its data to file.
 * Extra-Data-Plugins may register multiple or no data-nodes. This
 * string will be passed over to the plugins-write-function, to tell the
 * plugin which data it should write.
 * @param pszXMLNode the name of the node under which the data
 *        of this plugin get stored. No special characters are allowed!
 */
VIZENGINE_API void evRegisterDataNode(const char* pszXMLNode);
#ifdef __cplusplus
}

namespace VizPlugin
{
    extern const std::string DataNode_ControlPlugin_V1_0;
}

extern "C" {
#endif

/*! @brief Sets the plugin type.
 *
 * set plugin type.
 * @param type denotes type of the plugin.
 *
 * \sa VIZ_Plugin_Type_t
 * \sa evRegisterPlugin(), evRegisterPluginFolder()
 */
VIZENGINE_API void evRegisterPluginType( int type );

/*! @brief Sets the plugin GUI type.
 *
 * Set which type of GUI is used by plugin, TCL/TK or WPF.
 * @param iGuiType denotes GUI type: GUI_DEFAULT or GUI_WPF
 * \sa GuiType
 */
VIZENGINE_API void evRegisterGuiType(int iGuiType);

/*! @brief Sets persistency state of plugin.
 *
 * @param bPersistent set persistency mode of plugin.
 * Sets the plugin's persistency state. By default, plugins are marked as
 * non-persistent, meaning that they are unloaded when not in use. Call
 * evSetPersistent(true) if the plugin defines global variables initialized
 * in PLUGIN_INIT and accessed later on by the instances of the plugin.
 * \sa PLUGIN_INIT()
 */
VIZENGINE_API void evSetPersistent( bool bPersistent );

VIZENGINE_API void evSetOffairEvent(bool bSubscribe);

/*! brief Controls enter/leave behavior.
 *
 * @param b Flag that controls the enter/leave behavior.
 *
 * Call this function with b = false if you want the enter/leave
 * callbacks to be called even if the mouse cursor is not over the container.
 * By default, this flag is set to true.
 *
 * \sa PLUGIN_ENTER_CONTAINER, PLUGIN_LEAVE_CONTAINER, PLUGIN_ENTER_SUB_CONTAINER, PLUGIN_ENTER_SUB_CONTAINER
 */
VIZENGINE_API void evSetCallEnterLeaveForTopObjectsOnly(bool b);

/*! brief Controls mouse-move behavior.
 *
 * @param b Flag that controls the mouse-move behavior.
 *
 * Call this function with b = false if you want the PLUGIN_MOUSE_MOVE
 * callback to be called even if the mouse cursor is not over the container.
 * By default, this flag is set to false.
 *
 * \sa PLUGIN_MOUSE_MOVE
 */
VIZENGINE_API void evSetCallMouseMoveForTopObjectsOnly(bool b);

/*! brief Controls button-down behavior.
 *
 * @param b Flag that controls the button-down behavior.
 *
 * Call this function with b = false if you want the PLUGIN_xBUTTON_DOWN
 * callbacks to be called even if the mouse cursor is not over the container.
 * By default, this flag is set to true.
 *
 * \sa PLUGIN_LBUTTON_DOWN, PLUGIN_MBUTTON_DOWN, PLUGIN_RBUTTON_DOWN
 */
VIZENGINE_API void evSetCallButtonDownForTopObjectsOnly(bool b);

/*! brief Controls mouse wheel behavior.
 *
 * @param b Flag that controls the mouse wheel behavior.
 *
 * Call this function with b = false if you want the PLUGIN_xBUTTON_DOWN
 * callbacks to be called even if the mouse cursor is not over the container.
 * By default, this flag is set to true.
 *
 * \sa PLUGIN_MOUSE_WHEEL
 */
VIZENGINE_API void evSetCallButtonDownForTopObjectsOnly(bool b);

/*! brief Gets a flag controlling enter/leave behavior.
 *
 * @return Gets the value of the flag previously passed to evSetCallEnterLeaveForTopObjectsOnly.
 */
VIZENGINE_API bool evIsCallEnterLeaveForTopObjectsOnly();

/*! brief Gets a flag controlling mouse-move behavior.
 *
 * @return Gets the value of the flag previously passed to evSetCallMouseMoveForTopObjectsOnly.
 */
VIZENGINE_API bool evIsCallMouseMoveForTopObjectsOnly();

/*! brief Gets a flag controlling button-down behavior.
 *
 * @return Gets the value of the flag previously passed to evSetCallButtonDownForTopObjectsOnly.
 */
VIZENGINE_API bool evIsCallButtonDownForTopObjectsOnly();

/// version part of complex version number
#define _VER(v)     (int)((unsigned char)((((long)v)>>24) & 0xff))
/// release part of complex version number
#define _REL(v)     (int)((unsigned char)((((long)v)>>16) & 0xff))
/// patch level part of complex version number
#define _PL(v)      (((int)(((long)v) & 0xffff)<0) ? -(int)(((long)v) & 0xffff) : (int)(((long)v) & 0xffff))
/// beta state part of complex version number
#define _ISBETA(v)  (0 > (int)(((long)v) & 0xffff))
/// create version number out of cersion, release and patch level part.
#define MAKE_VERSION_LONG(v,r,pl)   (unsigned long)((unsigned long)(((unsigned char)(v))<<24) | (unsigned long)((unsigned char)(r)<<16) | (unsigned long)((unsigned short)(pl)))

/*! @brief determine viz version
 *
 * Get the version of the currently running viz as unsigned long.
 * Use the macros _VER(), _REL(), _PL(), _ISBETA() to get the
 * version/release/ patchlevel/beta-state part out of this unsigned long.
 * @return the complex version number.
 */
VIZENGINE_API unsigned long VIZGetVersion();

/*! @brief set plugin version.
 *
 * You can use this to set information about your plugin's version.
 * @param[in] iVersion version part
 * @param[in] iRelease release part
 * @param[in] iPatchLevel patch level part
 */
VIZENGINE_API void evRegisterPluginVersion( int iVersion, int iRelease, int iPatchLevel );

/*! @brief set required viz version.
 *
 * You can use this to set information about the required viz version.
 * @param[in] iVersion version part
 * @param[in] iRelease release part
 * @param[in] iPatchLevel patch level part
 */
VIZENGINE_API void evRegisterRequiredVersion( int iVersion, int iRelease, int iPatchLevel );

/*! @brief event callback types
 *
 * Your plugin may catch some events, occured within the scene-editor.
 * Currently there various keyboard & mouse-events catchable.
 * To get these events, your plugin must call the evRegisterInputEvent during
 * the plugin-initialization.
 *
 * The following events are currently available to your plugin.
 *
 * You can use any combination of the previous constants, to direct
 * those events to your plugin.
 *
 * @note In addition to be able to receive events, your plugin need to
 * have a event-handling callback-function named PLUGIN_ON_INPUT_EVENT.
 */
enum Viz_Event_Types_t
{
    EVT_KEYBOARD = 0x1,     /*!<  keyboard events      */
    EVT_MOUSEBUTTON = 0x2,  /*!<  mouse button events  */
    EVT_MOUSEMOVE = 0x4,    /*!<  mouse move events    */
    EVT_FOCUS_CHANGE = 0x8  /*!<  change in focus      */
};

/*! @brief event callback registration
 *
 * Your plugin may catch some events, occured within the scene-editor.
 * Currently there various keyboard & mouse-events catchable.
 * To get these events, your plugin must call the evRegisterInputEvent during
 * the plugin-initialization.
 * @param[in] uRegisteredEvents combinatino of event types to register
 * \sa Viz_Event_Types_t
 */
VIZENGINE_API void evRegisterInputEvent( unsigned int uRegisteredEvents );

/*! @brief decide for/against LOD with geometry plugin.
 *
 * @param bDoUseLevelOfDetail Level of Detail on or off.
 * If you want to create a geometry plugin (type is EV_GEOMETRY) and not use
 * Level of Detail for your plugin. Call this function in
 * the PLUGIN_INIT_FUNCTION of your plugin.
 * \sa PLUGIN_NEW_GEOM(), PLUGIN_INIT_FUNCTION()
 */
VIZENGINE_API void evRegisterUseLOD( bool bDoUseLevelOfDetail );

/*! @brief event handling for debugging. not to be confused with input events, such as mouse and keyboard events.
 *
 * @param[in] value
 * \sa evRegisterEvent(), evEventStart(), evEventEnd()
 * @todo Documentation missing on how to be used. ran
 */
VIZENGINE_API void evRegisterUseEvents( bool value );

/*! @brief event handling for debugging. not to be confused with input events, such as mouse and keyboard events.
 *
 * @param[in] name
 * @param[in] type
 * \sa evRegisterUseEvents(), evEventStart(), evEventEnd()
 * @todo Documentation missing on how to be used.
 * @todo Documentation to be done. ran
 */
VIZENGINE_API int evRegisterEvent( char * name, unsigned int type );

/*! @brief event handling for debugging. not to be confused with input events, such as mouse and keyboard events.
 *
 *
 * @param[in] idx
 * \sa evRegisterUseEvents(),evRegisterEvent(), evEventEnd()
 * @todo Documentation missing on how to be used.
 * @todo Documentation to be done. ran
 */
VIZENGINE_API void evEventStart( int idx );

/*! @brief event handling for debugging. not to be confused with input events, such as mouse and keyboard events.
 *
 *
 * @param[in] idx
 * \sa evRegisterUseEvents(),evRegisterEvent(), evEventStart()
 * @todo Documentation missing on how to be used.
 * @todo Documentation to be done. ran
 */
VIZENGINE_API void evEventEnd( int idx );

// this pluginlib is providing the version2 of the evRegisterParameterXXX functions.
// later versions may define another symbol, e.g. EV_REGISTER_PARAMETER_V_3. etc.
#define EV_REGISTER_PARAMETER_V_2

/*=========================================================================
  evRegisterParameterFloat
  evRegisterParameterSliderFloat
  evRegisterParameterInt
  evRegisterParameterSliderInt
  evRegisterParameterBool
  evRegisterParameterColor
  evRegisterParameterRadio
  evRegisterParameterString
  evRegisterParameterFileSelector
  evRegisterParameterText
  evRegisterInfoText
  evRegisterParameterList
  evRegisterParameterDropDown
  evRegisterParameterImage
  evRegisterParameterImageEx
  evRegisterParameterSubstance
  evRegisterParameterHList
  evRegisterParameterFont

  Register a plugin parameter to the viz system

  name          the name of the plugin parameter (must not contain whitespaces
                          or other special chars).
  label         label to show in the editor (whitespaces allowed)
  def           default value
  min           minimum value allowed
  max           maximum value allowed
  valuelabels   labels for each value of a radio button editor
  widgetlen     lenght of text field in GUI
  maxlen        maximum length of string
  check         allowed characters for input (e.g. "A-Za-z0-9")
  pathdef       default path
  filedef       default file
  filterdef     default filter (e.g. "*.cc")
  width         width of widget
  height        height of widget
  ppszEntries   array of listvalues for list and hlist
  separator     separator for hlist values
=========================================================================*/

/*! @brief Register a plugin parameter of type \a float with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] fDefault default value
 * @param[in] fMin minimum value allowed
 * @param[in] fMax maximum value allowed
 */
VIZENGINE_API void evRegisterParameterFloat( const char * pszName, const char * pszLabel, float fDefault, float fMin, float fMax );
VIZENGINE_API bool evRegisterParameterFloatEx( const char * pszName, const char * pszLabel, float fDefault, float fMin, float fMax, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter slider of type \a float with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] fDefault default value
 * @param[in] fMin minimum value allowed
 * @param[in] fMax maximum value allowed
 */
VIZENGINE_API void evRegisterParameterSliderFloat( const char * pszName, const char * pszLabel, float fDefault, float fMin, float fMax, int iWidth );
VIZENGINE_API bool evRegisterParameterSliderFloatEx( const char * pszName, const char * pszLabel, float fDefault, float fMin, float fMax, int iWidth, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter of type \a int with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] iDefault default value
 * @param[in] iMin minimum value allowed
 * @param[in] iMax maximum value allowed
 * @param[in] iWidth gui parameter width
 */
VIZENGINE_API void evRegisterParameterInt( const char * pszName, const char * pszLabel, int iDefault, int iMin, int iMax );
VIZENGINE_API bool evRegisterParameterIntEx( const char * pszName, const char * pszLabel, int iDefault, int iMin, int iMax, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter slider of type \a int with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] iDefault default value
 * @param[in] iMin minimum value allowed
 * @param[in] iMax maximum value allowed
 * @param[in] iWidth gui parameter width
 */
VIZENGINE_API void evRegisterParameterSliderInt( const char * pszName, const char * pszLabel, int iDefault, int iMin, int iMax, int iWidth );
VIZENGINE_API bool evRegisterParameterSliderIntEx( const char * pszName, const char * pszLabel, int iDefault, int iMin, int iMax, int iWidth, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter of type \a bool with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] bDefault default value
 */
VIZENGINE_API void evRegisterParameterBool( const char * pszName, const char * pszLabel, bool bDefault );
VIZENGINE_API bool evRegisterParameterBoolEx( const char * pszName, const char * pszLabel, bool bDefault, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter for a color (type \a unsigned long) with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] lDefault default value
 */
VIZENGINE_API void evRegisterParameterColor( const char * pszName, const char * pszLabel, unsigned long lDefault );
VIZENGINE_API bool evRegisterParameterColorEx( const char * pszName, const char * pszLabel, unsigned long lDefault, size_t & offset, size_t & total_size );

/*! @brief Register a group of radio buttons with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] iDefault index of default item
 * @param[in] ppszLabels labels of the items
 */
VIZENGINE_API void evRegisterParameterRadio( const char * pszName, const char * pszLabel, int iDefault, const char ** ppszLabels );
VIZENGINE_API bool evRegisterParameterRadioEx( const char * pszName, const char * pszLabel, int iDefault, const char ** ppszLabels, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter for a string (type \a const char*) with viz.
 *
 * the string length is limited to 64kB.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] pszDefault default value
 * @param[in] iWidgetLen length of text field in GUI (number of characters)
 * @param[in] iMaxLen maximum length of string
 * @param[in] pszCheck allowed characters for input (e.g. "A-Za-z0-9")
*/
VIZENGINE_API void evRegisterParameterString( const char * pszName, const char * pszLabel, const char * pszDefault, int iWidgetLen, int iMaxLen, const char * pszCheck );
VIZENGINE_API bool evRegisterParameterStringEx( const char * pszName, const char * pszLabel, const char * pszDefault, int iWidgetLen, int iMaxLen, const char * pszCheck, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter for a string (type \a const char*) with viz.
 *
 * the string length is limited to 64kB.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] pszDefault default value
 * @param[in] iWidgetLen length of text field in GUI
 * @param[in] iWidgetHeight height of the text field in GUI
*/
VIZENGINE_API void evRegisterParameterLabel( const char * pszName, const char * pszLabel, const char * pszDefault, int iWidgetLen, int iWidgetHeight );
VIZENGINE_API bool evRegisterParameterLabelEx( const char * pszName, const char * pszLabel, const char * pszDefault, int iWidgetLen, int iWidgetHeight, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter for a file path with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] pszPathDefault default path
 * @param[in] pszFile default file
 * @param[in] pszFilter default filter (e.g. "*.cc")
 */
VIZENGINE_API void evRegisterParameterFileSelector( const char * pszName, const char * pszLabel, const char * pszPathDefault, const char * pszFile, const char * pszFilter );
VIZENGINE_API bool evRegisterParameterFileSelectorEx( const char * pszName, const char * pszLabel, const char * pszPathDefault, const char * pszFile, const char * pszFilter, size_t & offset, size_t & total_size );

/*! @brief Register a plugin parameter for a directory path with viz.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] pszPathDefault default path
 */
VIZENGINE_API void evRegisterParameterDirSelector( const char * pszName, const char * pszLabel, const char * pszPathDefault);
VIZENGINE_API bool evRegisterParameterDirSelectorEx( const char * pszName, const char * pszLabel, const char * pszPathDefault, size_t & offset, size_t & total_size );

/*! @brief Register a text box for a plugin parameter.
 *
 * @param[in] pszName the name of the plugin parameter for which the info text should be set
 * @param[in] pszDefault default text
 * @param[in] iWidth width of the text box
 * @param[in] iHeight height of the text box
 */
VIZENGINE_API void evRegisterParameterText( const char * pszName, const char * pszDefault, int iWidth, int iHeight );
VIZENGINE_API bool evRegisterParameterTextEx( const char * pszName, const char * pszDefault, int iWidth, int iHeight, size_t & offset, size_t & total_size );

/*! @brief Register an info text for a plugin parameter
 *
 * @param[in] pszName the name of the plugin parameter for which the info text should be set
 * @param[in] pszText info text
 */
VIZENGINE_API void evRegisterInfoText( const char * pszName, const char * pszText );
// VIZENGINE_API bool evRegisterInfoTextEx( const char * pszName, const char * pszText, size_t & offset, size_t & total_size );

/*! @brief Register a parameter list.
 *
 * @param[in] pszName the name of the list (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] iDefault index of default list item
 * @param[in] ppszEntries values to appear in the list
 * @param[in] iWidgetLen length of text field in GUI (number of characters)
 * @param[in] iHeight height of the dropdown list (number of list entries)
 */
VIZENGINE_API void evRegisterParameterList( const char * pszName, const char * pszLabel, int iDefault, const char ** ppszEntries, int iWidgetLen, int iHeight );
VIZENGINE_API bool evRegisterParameterListEx( const char * pszName, const char * pszLabel, int iDefault, const char ** ppszEntries, int iWidgetLen, int iHeight, size_t & offset, size_t & total_size );

/*! @brief Register a parameter dropdown box.
 *
 * @param[in] pszName the name of the dropdown box (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] iDefault index of default dropdown item
 * @param[in] ppszEntries values to appear in the dropdown box
 * @param[in] iWidth width of the dropdown box
 * @param[in] iHeight height of the dropdown box
 */
VIZENGINE_API void evRegisterParameterDropDown( const char * pszName, const char * pszLabel, int iDefault, const char ** ppszEntries, int iWidth, int iHeight );
VIZENGINE_API bool evRegisterParameterDropDownEx( const char * pszName, const char * pszLabel, int iDefault, const char ** ppszEntries, int iWidth, int iHeight, size_t & offset, size_t & total_size );

/*! @brief register an image parameter.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] pszDefault of default image item
 */
VIZENGINE_API void evRegisterParameterImage( const char * pszName, const char * pszLabel, const char * pszDefault );
VIZENGINE_API bool evRegisterParameterImageEx2( const char * pszName, const char * pszLabel, const char * pszDefault, size_t & offset, size_t & total_size );


/*! @brief register a substance parameter.
*
* @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
* @param[in] pszLabel label to show in the editor (whitespaces allowed)
* @param[in] pszDefault of default substance item
*/
VIZENGINE_API void evRegisterParameterSubstance(const char * pszName, const char * pszLabel, const char * pszDefault);

/*! @brief register an extended image parameter.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] pszDefaultImage name of default image item
 * @param[in] bPosActive activates position controllers
 * @param[in] bRotActive activates rotation controllers
 * @param[in] bSclActive activates scaling controllers
    @param[in] fPosXDefault default value
    @param[in] fPosYDefault default value
    @param[in] fRotXDefault default value
    @param[in] fRotYDefault default value
    @param[in] fRotZDefault default value
    @param[in] fSclXDefault default value
    @param[in] fSclYDefault default value
    @param[in] fPosXMin minimum value
    @param[in] fPosYMin minimum value
    @param[in] fRotXMin minimum value
    @param[in] fRotYMin minimum value
    @param[in] fRotZMin minimum value
    @param[in] fSclXMin minimum value
    @param[in] fSclYMin minimum value
    @param[in] fPosXMax maximum value
    @param[in] fPosYMax maximum value
    @param[in] fRotXMax maximum value
    @param[in] fRotYMax maximum value
    @param[in] fRotZMax maximum value
    @param[in] fSclXMax maximum value
    @param[in] fSclYMax maximum value
 *
 * use PLUGIN_PARAMETER::IMAGE_EX as data type in your plugin and
 * mind that there are used 9 plugin id's for this element (1 for the ImageEx object,
 * 1 for the image, 2 for position, 3 for rotation and 2 for scaling)!
 */
VIZENGINE_API void evRegisterParameterImageEx( const char * pszName, const char * pszLabel, const char * pszDefaultImage,
    bool bPosActive, bool bRotActive, bool bSclActive,
    float fPosXDefault = 0.f, float fPosXMin = 0.f, float fPosXMax = 0.f,
    float fPosYDefault = 0.f, float fPosYMin = 0.f, float fPosYMax = 0.f,
    float fRotXDefault = 0.f, float fRotXMin = 0.f, float fRotXMax = 0.f,
    float fRotYDefault = 0.f, float fRotYMin = 0.f, float fRotYMax = 0.f,
    float fRotZDefault = 0.f, float fRotZMin = 0.f, float fRotZMax = 0.f,
    float fSclXDefault = 1.f, float fSclXMin = 1.f, float fSclXMax = 1.f,
    float fSclYDefault = 1.f, float fSclYMin = 1.f, float fSclYMax = 1.f);

VIZENGINE_API bool evRegisterParameterImageEx3( const char * pszName, const char * pszLabel, const char * pszDefaultImage,
    bool bPosActive, bool bRotActive, bool bSclActive
    , size_t & offset, size_t & total_size
    , float fPosXDefault = 0.f, float fPosXMin = 0.f, float fPosXMax = 0.f
    , float fPosYDefault = 0.f, float fPosYMin = 0.f, float fPosYMax = 0.f
    , float fRotXDefault = 0.f, float fRotXMin = 0.f, float fRotXMax = 0.f
    , float fRotYDefault = 0.f, float fRotYMin = 0.f, float fRotYMax = 0.f
    , float fRotZDefault = 0.f, float fRotZMin = 0.f, float fRotZMax = 0.f
    , float fSclXDefault = 1.f, float fSclXMin = 1.f, float fSclXMax = 1.f
    , float fSclYDefault = 1.f, float fSclYMin = 1.f, float fSclYMax = 1.f
     );

/*! @brief register a font parameter.
 *
 * @param[in] pszName the name of the plugin parameter (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] pszDefault value
 */
VIZENGINE_API void evRegisterParameterFont( const char * pszName, const char * pszLabel, const char * pszDefault );
VIZENGINE_API bool evRegisterParameterFontEx( const char * pszName, const char * pszLabel, const char * pszDefault, size_t & offset, size_t & total_size );

/*! @brief Register a horizontal list.
 *
 * @param[in] pszName the name of the list (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] iDefault index of default list item
 * @param[in] ppszEntries values to appear in the list
 * @param[in] chSeparator for the values
 * @param[in] iWidth width of the parameter list
 * @param[in] iHeight height of the parameter list
 */
VIZENGINE_API void evRegisterParameterHList( const char * pszName, const char * pszLabel, int iDefault, const char ** ppszEntries, char chSeparator, int iWidth, int iHeight );
VIZENGINE_API bool evRegisterParameterHListEx( const char * pszName, const char * pszLabel, int iDefault, const char ** ppszEntries, char chSeparator, int iWidth, int iHeight, size_t & offset, size_t & total_size );

/*! @brief register a dropbox for other containers.
 *
 * allows other containers to be dropped into. the plugin can then perform various operations
 * on the dropped containers during the callbacks.
 * @param[in] pszName the name of the list (must not contain whitespaces or other special chars).
 * @param[in] pszLabel label to show in the editor (whitespaces allowed)
 * @param[in] pszDefault default container
 */
VIZENGINE_API void evRegisterParameterContainer( const char * pszName, const char * pszLabel, const char * pszDefault );
VIZENGINE_API bool evRegisterParameterContainerEx( const char * pszName, const char * pszLabel, const char * pszDefault, size_t & offset, size_t & total_size );

/*! @brief Registers UI tabs.
*
* adds tabs to the plugin editor. Label mapping: label 0 -> first tab (bult-in parameters), label 1 -> second tab (embedded), ...
* on the dropped containers during the callbacks. This function could be called once per plugin - additional calls will 
* overwrite the previously specified tabs.
* @param[in] ppszTabLabels labels of the items (0 terminated string array)
*/
VIZENGINE_API bool evRegisterTabs(const char ** ppszTabLabels);

/*! @brief Register paramter data
 *
 * @param[in] name name of the parameter
 *
 * The corresponding type in the plugin data has to be an "unsigned char *".
 * Allocation for this paramter has to be done with "new unsigned char[size]".
 * At the beginning there is the size of the following bytes encoded in an unsigned long value.
 */
VIZENGINE_API void evRegisterParameterData( const char * name );
VIZENGINE_API bool evRegisterParameterDataEx( const char * name, size_t & offset, size_t & total_size );

/*! @brief Register License stuff.
 *
 * @param pszKey a key under which this license texts are stored in VizArtist.
 * @param pszLegal legal text that needs to printed upon startup.
 * @param pszAcknowledgement acknowledgement that may be printed upon startup.
 * @param pszLicense license text idf it needs to be printed in an "about" request.
 * @return 0 if the license texts were successfully added. any number otherwise.
 *
 */
VIZENGINE_API
int
evRegisterLicenseText( char const * pszKey
                     , char const * pszLegal
                     , char const * pszAcknowledgement
                     , char const * pszLicense
                     );

/*! @brief Register plugin function
 *
 * @param[in] name ??
 * @todo documentation to be done.
 */
VIZENGINE_API void evRegisterScriptingFunction(const char* szName);

/*! Hides the last registered parameter in the GUI.
 *
 * called after a evRegisterParameterXXX() function to hide the registered parameter from the UI.
 */
VIZENGINE_API void evHideParameter( void );

/*! Hides already registered parameters in the GUI.
*
* called after evRegisterParameterXXX() functions to hide them from the UI.
*/
VIZENGINE_API void evHideParameters(void);

/*! Disable or enable animation on the last registered parameter
 *
 * called after a evRegisterParameterXXX() function to specify if a parameter can be animated.
 */
VIZENGINE_API void evSetAnimateParameter(bool bValue);


/*! Default Behaviour to Enable / Disable Animation on parameters
 */
VIZENGINE_API void evSetDefaultAnimateParameter(bool bValue);

// Note: In newly compiled plugins, evRegisterUserData and evRegisterTotalSize are
// forwarded to evRegisterUserData32 and evRegisterTotalSize32, respectively. This
// change was necessary because the old functions (evRegisterUserData and evRegisterTotalSize)
// took only 'short' paramters, which was insufficient in some cases. evRegisterUserData32
// and evRegisterTotalSize32 take 'int' parameters.
// viz.lib still exports the old functions with short paramters, so that plugins don't have to
// be recompiled.

/*! @brief register additional space for POD (plain old data)
 *
 * allocate instance data in addition to the parameters already registered.
 * @param[in] size number of requested "additional" bytes.
 *
 */
VIZENGINE_API void evRegisterUserData32( unsigned int size );
VIZENGINE_API bool evRegisterUserData32Ex( size_t align_requirement, size_t size, size_t & offset, size_t & total_size );

#ifndef DONT_INCLUDE_INLINE_FUNCTIONS_IN_EV_COMMON
//#if ! defined( _WIN64 )
// we do not offer this unsecure version in 64 bit anymore
__declspec(deprecated("please consider using evRegisterUserDataEx() in place of evRegisterUserData()."))
inline void evRegisterUserData(unsigned int size)
{
    evRegisterUserData32(size);
}
//#endif // _WIN64
inline bool evRegisterUserDataEx(size_t align_requirement, size_t size, size_t & offset, size_t & total_size)
{
    return evRegisterUserData32Ex(align_requirement, size, offset, total_size);
}
#endif

/*! @brief tell viz the total number of bytes needed for this plugin.
 *
 * For convenience, you can use "evRegisterTotalSize" with "sizeof(PLUGIN_DATA)" after registering
 * all your plugin's data instead of "evRegisterUserData" with the required
 * additional data.
 * @param[in] usTotalSize total size of your plugin's data-structure; if your plugin requests
 *                        more size than viz reserved for it, the internal storage place will
 *                        be increased, to be able to give you the requested amount of memory.
 */
VIZENGINE_API void evRegisterTotalSize32(unsigned int usTotalSize);

#ifndef DONT_INCLUDE_INLINE_FUNCTIONS_IN_EV_COMMON
inline void evRegisterTotalSize(unsigned int size)
{
    evRegisterTotalSize32(size);
}
#endif

/*! @brief Register a push button with viz.
 *
 * register a push button that can later be used together with the PLUGIN_EXEC_ACTION() function.
 * @param pszName the name of the push button (must not contain whitespaces or other special chars).
 * @param pszLabel label to show in the editor (whitespaces allowed)
 * @param iButtonID handle which will be returned to the plugin when the button is pressed in the editor
 * @see PLUGIN_EXEC_ACTION()
*/
VIZENGINE_API void evRegisterPushButton( const char * pszName, const char * pszLabel, int iButtonID );

/*! @brief visibility states for parameters in the UI
 *
 * nominates the visibility states for registered parameters in the UI.
 */
enum EGUIState
{
    DISABLED = 0,   /*!< shown but read only and greyed out          */
    ENABLED = 1,    /*!< shown and can be changed from within the UI */
    HIDE = 0,       /*!< hide the parameter */
    SHOW = 1        /*!< show the parameter */
};

/*! @brief enable/disable a parameter in the GUI
 *
 * @param pszName the name of the plugin parameter
 * @param iState state, which the widget should get (either ENABLED or DISABLED)
 * @see EGUIState
 */
VIZENGINE_API void evSendGuiStatus( const char * pszName, int iState );

/*! @brief show/hide a parameter in the GUI.
 *
 * @param pszName the name of the plugin parameter
 * @param iState should the parameter be visible or not (either SHOW or HIDE)
 * @see EGUIState
 */
VIZENGINE_API void evSendGuiParameterShow( const char * pszName, int iState );

/*! @brief defines if a parameter should be updated or not
 *
 * @param pszName the name of the plugin parameter
 * @param iState should the parameter be updated or not (either ENABLED or DISABLED)
 * @see EGUIState
 */
VIZENGINE_API void evSendGuiParameterUpdate( const char * pszName, int iState );

/*! @brief send GUI a refresh command.
 *
 * @see EGUIState
 */
VIZENGINE_API void evSendGuiRefresh();

/*! @brief update parameters.
 *
 * @set new default, min and max value for parameters like Int, SliderInt etc.
 * @param[in] pszName the name of the plugin parameter
 * @param[in] iDefault default value
 * @param[in] iMin minimum value allowed
 * @param[in] iMax maximum value allowed
 */
VIZENGINE_API void evUpdateParameterIntDefMinMax(const char* pszName, int iDefault, int iMin, int iMax);

/*! @brief update parameters.
 *
 * @set new default, min and max value for parameters like Float, SliderFloat etc.
 * @param[in] pszName the name of the plugin parameter
 * @param[in] fDefault default value
 * @param[in] fMin minimum value allowed
 * @param[in] fMax maximum value allowed
 */
VIZENGINE_API void evUpdateParameterFloatDefMinMax(const char* pszName, float fDefault, float fMin, float fMax);

/*! @brief update parameter entries.
 *
 * @set new entries for parameters like List or DropDown
 * @param[in] pszName the name of the plugin parameter
 * @param[in] new ppszEntries values to appear in the dropdown box
 */
VIZENGINE_API void evUpdateParameterEntries(const char* pszName, const char ** ppszEntries);


/*! @brief ?
 *
 * Subgeometries in viz are created with each evNewGeom call. These
 * are handled with containers inside viz. Use this call to get the
 * container which corresponds to the current evGeom (created with evNewGeom).
 * @return the current container
   @verbatim
       CONTAINER container;
       container = evGeomGetCurrentContainer;
   @endverbatim
 *
 * You can do a lot of things with that container now.
 * e.g. create textures for multiple textures within one geometry.
 *
 */
//VIZENGINE_API int evGeomGetCurrentContainer( void );


/*! @brief abort rendereing to disk.
 *
 * Call this function from within RENDER_TO_DISK_CREATE_CLIP() to abort
 * the render-to-disk process.
 * @param[in] errorMessage message describing the reason what lead to the abortion of the process.
 *
 * @todo documentation to be done.
 */
//Add the error number, which is the reason for aborting
VIZENGINE_API void evAbortRenderToDiskProcess( const char * errorMessage, int abortErr=0 );
VIZENGINE_API void evMessageRenderToDiskProcess(const char* pszMessage);



/*! @brief Register uniforms for shader plugins
 *
 * These calls define uniform variables for shader plugins. The
 * can be are mapped one to one into the OpenGL Shading Language functions.
 * @return nothing
 */
VIZENGINE_API void evShaderParameter1Float              (char *name);
VIZENGINE_API void evShaderParameter2Float              (char *name);
VIZENGINE_API void evShaderParameter3Float              (char *name);
VIZENGINE_API void evShaderParameter4Float              (char *name);
VIZENGINE_API void evShaderParameter1Int                (char *name);
VIZENGINE_API void evShaderParameter2Int                (char *name);
VIZENGINE_API void evShaderParameter3Int                (char *name);
VIZENGINE_API void evShaderParameter4Int                (char *name);
VIZENGINE_API void evShaderParameterSampler             (char *name);


/*! @brief Functions needed to define the shader itself
 *
 * The File versions will open the passed file name, read the file
 * and compile it. Use const char *chData version if you have
 * the shader code in memory.
 * @return nothing
 */
VIZENGINE_API void evCreateFragmentProgramFromFile(const char *chFile);
VIZENGINE_API void evCreateFragmentProgram(const char *chData);
VIZENGINE_API void evCreateVertexProgramFromFile(const char *chFile);
VIZENGINE_API void evCreateVertexProgram(const char *chData);
VIZENGINE_API void evSetShaderVersion(int version, bool compatibility);

/*! @brief Compile and link the registered shader source
 *
 * @return nothing
 */
VIZENGINE_API void evCompileAndLinkShader();

/*! @brief Switch debug for shader compilation on or off
 *
 * Passing true will activate shader compilation debugging and
 * Viz will print any error message encountered during shader
 * compilation into the viz console.
 * @return nothing
 */
VIZENGINE_API void evSetShaderDebug(int iVal);

/*! @brief This marks the uniform variables as "dirty"
 *
 * This function marks the uniform variable of the shader plugin
 * as dirty and will initiate a transfer of the shader uniforms
 * when needed.
 * @return nothing
 */
VIZENGINE_API void evSetUpdateUniforms();

/*! @brief Adds a variant of a shader plugin
 *
 * @return nothing
 */
VIZENGINE_API int evAddShaderVariant(const char *chDefine);

/*! @brief Selects a variant which was added with evAddShaderVariant before
 *
 * @return nothing
 */
VIZENGINE_API void evSelectShaderVariant(int iVal);

/*! @brief Sets a specific vertex tangent attribute location
 *
 * @return nothing
 */
VIZENGINE_API void evSetShaderTangentAttribLocation(int iVal);

/*! @brief Sets a specific vertex binormal attribute location
 *
 * @return nothing
 */
VIZENGINE_API void evSetShaderBinormalAttribLocation(int iVal);


VIZENGINE_API void evSendUniformsNow();

/*! @brief Activates or deactivates rendering of shader
 *
 * @return nothing
 */
VIZENGINE_API void evSetRenderShader(int iVal);

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------

VIZENGINE_API bool evReadData_bool(bool* data);
VIZENGINE_API bool evReadData_short(int16_t * data);
VIZENGINE_API bool evReadData_unsigned_short(uint16_t * data);
//VIZENGINE_API bool evReadData_int(int * data);
//VIZENGINE_API bool evReadData_unsigned_int(unsigned int * data);
VIZENGINE_API bool evReadData_long(int32_t * data);
VIZENGINE_API bool evReadData_unsigned_long(uint32_t * data);
VIZENGINE_API bool evReadData_float(float * data);
VIZENGINE_API bool evReadData_double(double * data);
VIZENGINE_API bool evReadData_binary(void* pvData, int nBytes);

VIZENGINE_API void evWriteData_bool(const bool data);
VIZENGINE_API void evWriteData_short(const int16_t data);
VIZENGINE_API void evWriteData_unsigned_short(const uint16_t data);
//VIZENGINE_API void evWriteData_int(const int data);
//VIZENGINE_API void evWriteData_unsigned_int(const unsigned int data);
VIZENGINE_API void evWriteData_long(const int32_t data);
VIZENGINE_API void evWriteData_unsigned_long(const uint32_t data);
VIZENGINE_API void evWriteData_float(const float data);
VIZENGINE_API void evWriteData_double(const double data);
VIZENGINE_API void evWriteData_binary (const void* pvData, unsigned int uiNumBytes);

#ifdef __cplusplus
}
#endif


#endif // EV_PLUGIN_PLUGINEXTERN_H
