/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2011 Vizrt Austria GmbH                                            *
 *  All Rights Reserved.                                                         *
 *                                                                               *
 *  This is PROPRIETARY SOURCE CODE of PEAK software technologies GmbH;          *
 *  the contents of this file may not be disclosed to third parties, copied or   *
 *  duplicated in any form, in whole or in part, without the prior written       *
 *  permission of PEAK software technologies GmbH                                *
 *                                                                               *
 * ============================================================================= */

/*  CAUTION:
 *  --------
 *  This file contains no user-modifiable data
 *  Under no circumstances change anything in this file without an
 *  explicit order from an employee of Vizrt GmbH
 *
 */

#if ! defined( EV_PLUGIN_INFOSTRING_H )
#define EV_PLUGIN_INFOSTRING_H


#include <sstream>

inline void
InfoStringBasics( std::ostringstream & ostrInfoString )
{
    ostrInfoString
        << "Folder/Name: "
        << THIS_PLUGIN_FOLDER
        << "/"
        << THIS_PLUGIN_NAME
        << "\n"
        << "Product Version: "
        << THIS_PROD_VERS_STR
        << ". File Version: "
        << THIS_FILE_VERS_STR
        << "\n"
        << "Last Changed Date: "
        << THIS_WCDATE
        << "\n"
        << "Build: "
        << THIS_BUILDCOMMENT
        << "\n"
    ;
    // return ostrInfoString;
}
#endif // EV_PLUGIN_INFOSTRING_H
