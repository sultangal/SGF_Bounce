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

#if ! defined( EV_PLUGIN_MASK_TARGET_H )
#define EV_PLUGIN_MASK_TARGET_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class MASK_TARGET : public BASE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get mask_target from container
     *
     * @param container ?
     * @todo documentation to be done.
     */
    void operator=(const CONTAINER & container );

    /*! @brief get mask_target from another mask_target
     *
     * @param target ?
     * @todo documentation to be done.
     */
    void operator=(const MASK_TARGET & target );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_layer( int * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_layer( int value );
};


#endif // EV_PLUGIN_MASK_TARGET_H
