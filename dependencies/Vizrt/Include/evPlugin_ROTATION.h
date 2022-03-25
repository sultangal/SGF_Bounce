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

#if ! defined( EV_PLUGIN_ROTATION_H )
#define EV_PLUGIN_ROTATION_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;
class ANIMATION;

//=========================================================================
// ROTATION OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class ROTATION : public BASE
{
public:
    friend class TRANSFORMATION;

    /*! @brief get rotation of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief rotation of container with containername
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    const ROTATION& operator=( const char * name );

    /*! @brief rotation of CONTAINER
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    const ROTATION& operator=( const CONTAINER& container );

    /*! @brief copy rotation from another rotation
     *
     * @param[in] rotation
     * @return ?

     * @todo documentation to be done.
     */
    const ROTATION& operator=( const ROTATION& rotation );

    /*! @brief set rotation values
     *
     * @param[in] x
     * @param[in] y
     * @param[in] z
     * @return ?

     * @todo documentation to be done.
     */
    int set( float x, float y, float z );

    /*! @brief get rotation values
     *
     * @param[out] x
     * @param[out] y
     * @param[out] z
     * @return ?

     * @todo documentation to be done.
     */
    int get( float *x, float *y, float *z );
};


#endif // EV_PLUGIN_ROTATION_H
