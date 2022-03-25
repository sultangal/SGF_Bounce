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

#if ! defined( EV_PLUGIN_DIRECTOR_H )
#define EV_PLUGIN_DIRECTOR_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


//=========================================================================
// DIRECTOR
//=========================================================================

/*! @brief ?
 *
 * @todo documentation to be done.
 */
class DIRECTOR : public BASE
{
public:
    /*! @brief get the director with the specified name
     *
     * @param[in] name ?
     * @return ?

     * @You can access sub-directors with the '$' sign. E.g.: Dir$SubDir$SubSubDir...
     */
    const DIRECTOR& operator=(const char* name);

    void operator=(CONTAINER& cont);
    void operator=(DIRECTOR& dir);

    /*! @brief ?
     *
     * @param[out] stage ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_stage(STAGE& stage);

    /*! @brief ?
     *
     * @param[in] name ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_name(const char* name);

    /*! @brief ?
     *
     * @param[out] pName ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_name(const char** pName);


    /*! @brief set the director offset with respect to the parent director (if any)
     *
     * @param[in] offset ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_local_offset(double offset);

    /*! @brief get the director offset with respect to the parent director (if any)
     *
     * @param[out] pOffset ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_local_offset(double* pOffset);

    /*! @brief get the accumulated director offset of this director and all its parents
     *
     * @param[out] pOffset ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_total_offset(double* pOffset);

    /*! @brief ?
     *
     * @param[in] bGetAbsoluteTime ?
     * @param[out] startTime ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_start_time(bool bGetAbsoluteTime, double* startTime);

    /*! @brief ?
     *
     * @param[in] bGetAbsoluteTime ?
     * @param[out] endTime ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_end_time(bool bGetAbsoluteTime, double* endTime);

    /*! @brief get the next director in the tree
     *
     * @return ?

     * @todo documentation to be done.
     */
    int next( void );

    /*! @brief get the previous director in the tree
     *
     * @return ?

     * @todo documentation to be done.
     */
    int prev( void );

    /*! @brief get the director one level up in tree
     *
     * @return ?

     * @todo documentation to be done.
     */
    int level_up( void );

    /*! @brief get the director one level down in tree
     *
     * @return ?

     * @todo documentation to be done.
     */
    int level_down( void );

    /*! @brief move and copy constants
     *
     * enum values for directional navigation
     * @todo documentation to be checked
     */
    enum where
    {
        NEXT=1,         /*!<  */
        PREVIOUS=2,     /*!<  */
        LEVEL_DOWN=3,   /*!<  */
        LEVEL_UP=4      /*!<  */
    };

    /*! @brief ?
     *
     * @param target ?
     * @param[in] where ?
     * @return ?

     * @todo documentation to be done.
     */
    int move(DIRECTOR& target, int where) const;

    /*! @brief ?
     *
     * @param target ?
     * @param[in] where ?
     * @param pDest ?
     * @return ?

     * @todo documentation to be done.
     */
    int copy(DIRECTOR& target, int where, DIRECTOR* pDest) const;

    /*! @brief ?
     *
     * @param[in] where ?
     * @param[out] pDirectorID ?
     * @return ?

     * @todo documentation to be done.
     */
    int add_director(int where, DIRECTOR* pDirectorID) const;

    /*! @brief is the animation in this director running?
     *
     * @param[out] pResult ?
     * @return ?

     * @todo documentation to be done.
     */
    int is_animation_running(bool* pResult);

    /*! @brief start the animation in this director and its sub-directors
     *
     * @return ?

     * @todo documentation to be done.
     */
    int start_animation( void );

    //! @brief Starts the animation in reverse direction.
    int start_animation_rev();

    /*! @brief stop the animation in this director
     *
     * @return ?

     * @todo documentation to be done.
     */
    int stop_animation( void );

    /*! @brief continue the animation in this director and its sub-directors
     *
     * @return ?

     * @todo documentation to be done.
     */
    int continue_animation( void );

    //! @brief Continues the animation in reverse direction.
    int continue_animation_rev();

    /*! @brief Sets the time marker and animates.
     *
     * Sets the time marker and animates all channels of the director and is sub-directors.
     *
     * @param[in] time is specified in stage time.
     * @return ?

     * @todo documentation to be done.
     */
    int set_time(double time);

    /*! @brief Returns the position of the time marker (in stage time).
     *
     * @param[out] pTime
     * @return ?

     * @todo documentation to be done.
     */
    int get_time(double* pTime);

    /*! @brief for compatibility with 2.x.
     *
     * @param[in] time ?
     * @return set_time(time)
     * @todo documentation to be done.
     * \sa set_time()
     */
    int set_animation_frame(double time) { return set_time(time); }

    /*! @brief for compatibility with 2.x.
     *
     * @param[out] time ?
     * @return get_time(time)
     * @todo documentation to be done.
     */
    int get_animation_frame(double* time) { return get_time(time); }

    //! @brief Sets the time (obsolete, use set_time).
    int set_timeline(double time) { return set_time(time); }

    //! @brief Gets the time (obsolete, use get_time).
    int get_timeline(double* time) { return get_time(time); }

    //! @brief Gets the local director offset (in secs).
    //! \deprecated Use get_local_offset instead.
    int get_offset(double* time);

    //! @brief Sets the local director offset (in secs).
    //! @deprecated Use set_local_offset instead.
    int set_offset(double time);

    /*! @brief Animate from stop a to b.
    *
    * @param[in] stopA Name of stoppoint A
    * @param[in] stopA Name of stoppoint B

    * @todo documentation to be done.
    */
    int go_to(const char* stopA, const char* stopB);

    /*! @brief Animate from stop a to b relative to the director offset.
    *
    * @param[in] stopA Name of stoppoint A
    * @param[in] stopA Name of stoppoint B

    * @todo documentation to be done.
    */
    int go_to_rel(const char* stopA, const char* stopB);

    /*! @brief Animate from stop a to b according to the Trio rules.
    *
    * @param[in] stopA Name of stoppoint A
    * @param[in] stopA Name of stoppoint B

    * @todo documentation to be done.
    */
    int go_to_trio(const char* stopA, const char* stopB);

    // the following member functions are used to access the channels of this director

    /*! @brief number of animation channels
     *
     * @param[out] pResult ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_number_of_animation_channels(int* pResult);

    /*! @brief number of action channels
     *
     * @param[out] pResult ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_number_of_action_channels(int* pResult);

    /*! @brief Gets the animation channels.
     *
     * @param[out] channels ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_animation_channels(THeapArray<CHANNEL>& channels);

    /*! @brief access action channels
     *
     * @param[out] channels ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_action_channels(THeapArray<CHANNEL>& channels);

    /*! @brief access event channel
     *
     * @param[out] channel ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_event_channel(CHANNEL& channel);

    /*! @brief ?
     *
     * @param[in] channel ?
     * @return ?

     * @todo documentation to be done.
     */
    int delete_channel(const CHANNEL& channel);

    /*! @brief delete this director (and all sub-directors)
     *
     * @return ?

     * @todo documentation to be done.
     */
    int erase( void );
};


#endif // EV_PLUGIN_DIRECTOR_H
