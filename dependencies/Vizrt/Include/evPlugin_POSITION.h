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

#if ! defined( EV_PLUGIN_POSITION_H )
#define EV_PLUGIN_POSITION_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;
class ANIMATION;

//=========================================================================
// VIZ_POSITION OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class VIZ_POSITION : public BASE
{
public:
    friend class TRANSFORMATION;

    /*! @brief get position of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief position of container with containername
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    const VIZ_POSITION& operator=( const char * name );

    /*! @brief position of CONTAINER
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    const VIZ_POSITION& operator=( const CONTAINER& container );

    /*! @brief copy position from another position
     *
     * @param[in] position
     * @return ?

     * @todo documentation to be done.
     */
    const VIZ_POSITION& operator=( const VIZ_POSITION& position );

    /*! @brief set position values
     *
     * @param[in] x
     * @param[in] y
     * @param[in] z
     * @return ?

     * @todo documentation to be done.
     */
    int set( float x, float y, float z );

    /*! @brief get position values
     *
     * @param[out] x
     * @param[out] y
     * @param[out] z
     * @return ?

     * @todo documentation to be done.
     */
    int get( float *x, float *y, float *z );
};

// don't do that otherwise people stick to POSITION instead of VIZ_POSITION
// and POSITION clashes with a type declared by some other OS header
// #ifndef DONT_DECLARE_POSITION_TYPEDEF
// typedef VIZ_POSITION POSITION;
// #endif



#endif // EV_PLUGIN_POSITION_H
