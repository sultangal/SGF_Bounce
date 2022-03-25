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

#if ! defined( EV_TYPES_H )
#define EV_TYPES_H

// plugin-instance handle; currently not used, supplied for the future ;-)
// too good to be true. typedefs have a clash with windows type ...
// typedef unsigned short  HPLUGININSTANCE;
// typedef unsigned short  HEDITOR;

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




#endif // EV_TYPES_H
