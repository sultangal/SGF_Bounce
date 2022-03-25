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

#if ! defined( EV_PLUGIN_STAGE_H )
#define EV_PLUGIN_STAGE_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class DIRECTOR;

//=========================================================================
// STAGE
//=========================================================================

/*! @brief ?
 *
 * @todo documentation to be done.
 */
class STAGE : public BASE
{
public:
    /*! @brief get the local scene which is loaded
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief is at least one director running
     *
     * @param[out] pResult
     * @return ?

     * @todo documentation to be done.
     */
    int is_animation_running( bool * pResult );

    /*! @brief start the animation in all directors
     *
     * @return ?

     * @todo documentation to be done.
     */
    int start_animation();

    int start_animation_rev();

    /*! @brief stop the animation in all directors
     *
     * @return ?

     * @todo documentation to be done.
     */
    int stop_animation( void );

    /*! @brief continue the animation in all directors
     *
     * @return ?

     * @todo documentation to be done.
     */
    int continue_animation();

    int continue_animation_rev();

    int get_time(double* time);
    int set_time(double time);

    int get_timeline(double* time) { return get_time(time); }
    int set_timeline(double time) { return set_time(time); }

    // The names below are wrong - should be set_frame() and get_frame
    //  as the parameter is time in seconds!
    int get_animation_frame(double *timeInSeconds) { return get_time(timeInSeconds); }
    int set_animation_frame(double timeInSeconds) { return set_time(timeInSeconds); }

    // this will return the time which was used in the last SHOW or SHOW_POST
    // command for the stage
    int get_time_set_by_show_command(double *timeInSeconds);

    int get_director(const char *name, DIRECTOR& dir);

    int add_director(const char* name, DIRECTOR& dir);

    /*! @brief are there any directors in the stage?
     *
     * @param[out] pResult
     * @return ?

     * @todo documentation to be done.
     */
    int has_directors(bool* pResult);

    /*! @brief get the root director
     *
     * get the root director and return it in 'director'.
     * a new one is created if necessary.
     * @param[out] director the root director
     * @return ?

     * @todo documentation to be checked
     * \sa create_root_director
     */
    int get_root_director(DIRECTOR& director);

    /*! @brief create a new root director
     *
     * create a new root director and return it in 'director'.
     * if there already is a root director, it is returned in 'director'
     * @param[out] director the root director
     * @return ?

     * @todo documentation to be checked
     * \sa get_root_director
     */
    int create_root_director(DIRECTOR& director);


    /*! @brief rebuild the stage tree
     *
     * @return ?

     * @todo documentation to be done.
     */
    int update_gui();
    int get_stage_length(bool bIIncludeLoop, double* start ,double* end  );
};



#endif // EV_PLUGIN_STAGE_H
