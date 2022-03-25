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

#if ! defined( EVPLUGIN_DYNINTERFACE_H )
#define EVPLUGIN_DYNINTERFACE_H

#undef PLUGINFUNC
#undef PLUGIN_EXTERN
#undef PLUGIN_EXTERN_DEPRECATE_TEXT


#if defined( _WIN32 )

#if defined( VIZENGINE_EXPORTS )
    #define VIZENGINE_API      __declspec(dllexport)
    #define VIZENGINE_API_DEPRECATE_TEXT(_Text) __declspec(dllexport,deprecated(_Text))
#else // #if defined( VIZENGINE_EXPORTS )
#if ! defined( DONT_DECLARE_PLUGIN_EXTERN_AS_DLLIMPORT )
    #define VIZENGINE_API      __declspec(dllimport)
    #define VIZENGINE_API_DEPRECATE_TEXT(_Text) __declspec(dllimport,deprecated(_Text))
#else // #if ! defined( DONT_DECLARE_PLUGIN_EXTERN_AS_DLLIMPORT )
    #define VIZENGINE_API
    #define VIZENGINE_API_DEPRECATE_TEXT(_Text) __declspec(deprecated(_Text))
#endif // #if ! defined( DONT_DECLARE_PLUGIN_EXTERN_AS_DLLIMPORT )
#endif // #if defined( VIZENGINE_EXPORTS )

#else // #if defined( _WIN32 )

#if defined( VIZENGINE_EXPORTS )
    #define VIZENGINE_API      extern
    #define VIZENGINE_API_DEPRECATE_TEXT    extern
#else // #if defined( VIZENGINE_EXPORTS )
    #define VIZENGINE_API
    #define VIZENGINE_API_DEPRECATE_TEXT
#endif // #if defined( VIZENGINE_EXPORTS )

#endif // #if defined( _WIN32 )



#if defined( _WIN32 )

#if defined( VIZPLUGIN_EXPORTS )
    #define VIZPLUGIN_API      __declspec(dllexport)
    #define VIZPLUGIN_API_DEPRECATE_TEXT(_Text) __declspec(dllexport,deprecated(_Text))
#else // #if defined( VIZPLUGIN_EXPORTS )
    #define VIZPLUGIN_API      __declspec(dllimport)
    #define VIZPLUGIN_API_DEPRECATE_TEXT(_Text) __declspec(dllimport,deprecated(_Text))
#endif // #if defined( VIZPLUGIN_EXPORTS )

#else // #if defined( _WIN32 )

#if defined( VIZPLUGIN_EXPORTS )
    #define VIZPLUGIN_API      extern
    #define VIZPLUGIN_API_DEPRECATE_TEXT    extern
#else // #if defined( VIZPLUGIN_EXPORTS )
    #define VIZPLUGIN_API
    #define VIZPLUGIN_API_DEPRECATE_TEXT
#endif // #if defined( VIZPLUGIN_EXPORTS )

#endif // #if defined( _WIN32 )














#endif // EVPLUGIN_DYNINTERFACE_H
