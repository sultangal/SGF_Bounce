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


#ifndef __EV_COMMON_H__
#define __EV_COMMON_H__


// #error "evCommon.h included"

/*  @todo: cleanup of double definitions coming from freetype and viz
 *
 *
 */



//#include "evMath.h"
//#include "evPluginError.h"
//#include <string>


#define _DOUBLE_DEFS
#ifndef _DOUBLE_DEFS
#include "ftimage.h"
#endif

#if 0

// moved to evTypes.h

#ifndef DECLARE_VIZHANDLE
    #define DECLARE_VIZHANDLE(_type_)   typedef unsigned short _type_;
#endif

// plugin-instance handle; currently not used, supplied for the future ;-)

#ifndef HPLUGININSTANCE_DEFINED
DECLARE_VIZHANDLE (HPLUGININSTANCE);    // plugin-instance handle
#define HPLUGININSTANCE_DEFINED
#endif

#ifndef HEDITOR_DEFINED
DECLARE_VIZHANDLE (HEDITOR);    // viz-editor handle
#define HEDITOR_DEFINED
#endif

#endif

//
//#define evPLUGIN_POLLUTE
//
#include "evPlugin_PLUGINFUNC.h"
#include "evPlugin_PLUGINEXTERN.h"
// #include "evPlugin_MATH.h"
//
//#undef evPLUGIN_POLLUTE
//


#endif // __EV_COMMON_H__
