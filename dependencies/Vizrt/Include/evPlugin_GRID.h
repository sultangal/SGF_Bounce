/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2006 PEAK software technologies GmbH                               *
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
 *  explicit order from an employee of PEAK software technologies GmbH
 *
 */

#if ! defined( EV_PLUGIN_GRID_H )
#define EV_PLUGIN_GRID_H

#include "evPlugin_BASE.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class GRID : public BASE
{
public:

    /*! @brief ?
     *
     * @param pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_type(int *pValue);

    /*! @brief ?
     *
     * @param type ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_type(int type);

    /*! @brief ?
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    int move_to_container(const CONTAINER& container);

    /*! @brief ?
     *
     * @param pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int is_locked(bool *pValue);

    /*! @brief ?
     *
     * @param bLock ?
     * @return ?

     * @todo documentation to be done.
     */
    int lock(bool bLock);
};


#endif // EV_PLUGIN_GRID_H

