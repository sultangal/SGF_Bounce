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

#if ! defined( EV_PLUGIN_CLIPPER_H )
#define EV_PLUGIN_CLIPPER_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;
class VIZ_POSITION;
class ROTATION;

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class CLIPPER : public BASE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get clipper from another clipper.
     *
     * @param clipper
     * @todo documentation to be done.
     */
    void operator=( CLIPPER & clipper );

    /*! @brief get the light by number
     *
     * @param[in] number
     * @todo documentation to be done.
     */
    void operator=( int number );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_active( int * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_active( int value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_show( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_show( bool value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_reverse( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_reverse( bool value );

    /*! @brief ?
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_container( CONTAINER & container );

    /*! @brief ?
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_container( CONTAINER & container );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_track_container_active( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_track_container_active( bool value );

    /*! @brief ?
     *
     * @param pos ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_position( VIZ_POSITION & pos );

    /*! @brief ?
     *
     * @param pos ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_position( VIZ_POSITION & pos );

    /*! @brief ?
     *
     * @param rot ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_rotation( ROTATION & rot );

    /*! @brief ?
     *
     * @param rot ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_rotation( ROTATION & rot );
};




#endif // EV_PLUGIN_CLIPPER_H
