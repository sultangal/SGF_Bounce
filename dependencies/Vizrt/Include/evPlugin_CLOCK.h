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

#if ! defined( EV_PLUGIN_CLOCK_H )
#define EV_PLUGIN_CLOCK_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class CLOCK : public BASE
{
public:

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum clock_direction
    {
        UP,
        DOWN
    };

    /*! @brief constructor/destructor
     *
     * @todo documentation to be done.
     */
    CLOCK()                 { SetID(-1); }

    /*! @brief ?
     *
     * @param[in] which
     * @todo documentation to be done.
     */
    CLOCK( const int which )  { get_clock(which); }

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~CLOCK()                { /* do nothing */ }

    /*! @brief ?
     *
     * @param which ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_clock( const int which );

    /*! @brief ?
     *
     * @param time ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_time( const double time );

    /*! @brief ?
     *
     * @param[in] hr
     * @param[in] min
     * @param[in] sec
     * @param[in] sec100
     * @return ?

     * @todo documentation to be done.
     */
    int set_time( const double hr, const double min, const double sec, const double sec100 );

    /*! @brief ?
     *
     * @param[out] time
     * @return ?

     * @todo documentation to be done.
     */
    int get_time( double * time );

    /*! @brief ?
     *
     * @param[out] hr
     * @param[out] min
     * @param[out] sec
     * @param[out] sec100
     * @return ?

     * @todo documentation to be done.
     */
    int get_time( double * hr, double * min, double * sec, double * sec100 );

    /*! @brief ?
     *
     * @param time ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_new_start_time( const double time );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int start( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int pause( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int stop( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int cont( void );

    /*! @brief ?
     *
     * @param[out] flag
     * @return ?

     * @todo documentation to be done.
     */
    int get_is_running( bool * flag );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_check_limit( bool * check );
    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_check_limit( const bool check);

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_limit( double * value );
    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_limit( const double value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int add_time_diff( const double value );

    /*! @brief ?
     *
     * @param[out] dir
     * @return ?

     * @todo documentation to be done.
     */
    int get_direction( clock_direction * dir );

    /*! @brief ?
     *
     * @param[in] dir
     * @return ?

     * @todo documentation to be done.
     */
    int set_direction( const clock_direction dir );
};


#endif // EV_PLUGIN_CLOCK_H
