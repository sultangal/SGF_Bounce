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

#if ! defined( EV_PLUGIN_LIGHT_H )
#define EV_PLUGIN_LIGHT_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class ROTATION;
class MATERIAL;
class CONTAINER;
class ANIMATION;
class VIZ_POSITION;

//=========================================================================
// LIGHT OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class LIGHT : public BASE
{
public:
    /*! @brief not in use yet!! -> for light plugins
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get the light by number
     *
     * @param number ?
     * @return ?

     * @todo documentation to be done.
     */
    const LIGHT& operator=( int number );

    /*! @brief copy light from another light
     *
     * @param light ?
     * @return ?

     * @todo documentation to be done.
     */
    const LIGHT& operator=( const LIGHT & light );

    enum type
    {
        LOCAL_LIGHT=1,      /*!<  */
        SPOT_LIGHT=2,       /*!<  */
        INFINITE_LIGHT=3    /*!<  */
    };

    /*! @brief get the type -> enum type
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_type( int * value );

    /*! @brief set the type with type enum
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_type( int value );

    /*! @brief get the position of the light
     *
     * @param[out] position
     * @return ?

     * @todo documentation to be done.
     */
    int get_position( VIZ_POSITION & position );

    /*! @brief set the position of the light
     *
     * @param[in] position
     * @return ?

     * @todo documentation to be done.
     */
    int set_position( VIZ_POSITION & position );

    /*! @brief set the light active
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_active(int value);

    /*! @brief get the active status of the light
     *
     * @param[out] value
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_active(int* value);

    /*! @brief get the direction of the light
     *
     * @param[out] rotation
     * @return ?

     * @todo documentation to be done.
     */
    int get_direction( ROTATION & rotation );

    /*! @brief set the direction of the light
     *
     * @param[in] rotation
     * @return ?

     * @todo documentation to be done.
     */
    int set_direction( ROTATION & rotation );

    /*! @brief get attenuation by spotlight
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_attenuation( float * value );

    /*! @brief set attenuation by spotlight
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_attenuation( float value );

    /*! @brief get the light color
     *
     * @param[out] material
     * @return ?

     * @todo documentation to be done.
     */
    int get_color( MATERIAL & material );

    /*! @brief set the light color
     *
     * @param[in] material
     * @return ?

     * @todo documentation to be done.
     */
    int set_color( MATERIAL & material );

    /*! @brief get the position tracking of the light
     *
     * @param[out] container
     * @return ?

     * @todo documentation to be done.
     */
    int get_pos_tracking( CONTAINER & container );
    /*! @brief set the position tracking of the light
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    int set_pos_tracking( CONTAINER & container );

    /*! @brief get the rotation tracking of the light
     *
     * @param[out] container
     * @return ?

     * @todo documentation to be done.
     */
    int get_rot_tracking( CONTAINER & container );

    /*! @brief set the rotation tracking of the light
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    int set_rot_tracking( CONTAINER & container );

    /*! @brief is the position tracking active or inactive
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_pos_tracking_active( int * value );

    /*! @brief set the position tracking active or inactive
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_pos_tracking_active( int value );

    /*! @brief reset the position tracking
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_pos_tracking_reset( void );

    /*! @brief is the rotation tracking active or inactive
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_rot_tracking_active( int * value );

    /*! @brief set the rotation tracking active or inactive
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_rot_tracking_active( int value );

    /*! @brief reset the rotation tracking
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_rot_tracking_reset( void );
};


#endif // EV_PLUGIN_LIGHT_H
