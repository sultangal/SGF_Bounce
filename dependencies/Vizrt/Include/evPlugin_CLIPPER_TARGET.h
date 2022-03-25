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

#if ! defined( EV_PLUGIN_CLIPPER_TARGET_H )
#define EV_PLUGIN_CLIPPER_TARGET_H

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
class CLIPPER_TARGET : public BASE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void local();

    /*! @brief ?
     *
     * @param container ?
     * @todo documentation to be done.
     */
    void operator=( CONTAINER & container );                         // get clipper_target from container

    /*! @brief ?
     *
     * @param target ?
     * @todo documentation to be done.
     */
    void operator=( CLIPPER_TARGET & target );            // get clipper_target from another clipper_target

    /*! @brief ?
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_planes( int * value );

    /*! @brief ?
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_planes( int value );
};


#endif // EV_PLUGIN_CLIPPER_TARGET_H
