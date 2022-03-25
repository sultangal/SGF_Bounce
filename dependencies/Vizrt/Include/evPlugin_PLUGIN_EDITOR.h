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

#if ! defined( EV_PLUGIN_PLUGIN_EDITOR_H )
#define EV_PLUGIN_PLUGIN_EDITOR_H

#include "evPlugin_BASE.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class PLUGIN_EDITOR
{
public:
    static bool open_embedded_window(const char* title);
    static HWND get_embedded_window_handle();
    static bool close_embedded_window();
    static int get_system_format();
};


#endif // EV_PLUGIN_PLUGIN_EDITOR_H

