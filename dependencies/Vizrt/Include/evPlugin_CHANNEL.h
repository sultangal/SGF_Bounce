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

#if ! defined( EV_PLUGIN_CHANNEL_H )
#define EV_PLUGIN_CHANNEL_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class KEYFRAME_BASE;
class DIRECTOR;

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class CHANNEL : public BASE
{
public:
    /*! @brief get swing active
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_swing(int* swing);

    /*! @brief set swing active
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_swing(int swing);

    /*! @brief get loop active
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_loop(int* loop);

    /*! @brief set loop active
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_loop(int loop);

    /*! @brief get number of loop cycles
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_loop_counter(int* loopCounter);

    /*! @brief set number of loop cycles
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_loop_counter(int loopCounter);

    /*! @brief When does the animation of this container start?
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_start(double* time);

    /*! @brief get channel end
    *
    * @return 0 if failed

    * When does the animation end (time of the last keyframe) but also takes swing and
    * loop settings of the channel into account
    */
    int get_end(double* time);

    /*! @brief move keyframes in the defined range
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int move_keyframe(double startInSeconds, double endInSeconds, double offsetInSeconds);

    /*! @brief scalce keyframes in the defined range
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int scale_keyframe(double startInSeconds, double endInSeconds, double originInSeconds, double factor);

    /*! @brief find a keyframe
    *
    * @return 0 if failed

    * Find a keyframe in this channel by name (name is either $name or #index)
    */
    int search_keyframe(const char* keyFrameName, KEYFRAME_BASE& keyframe);

    /*! @brief get keyframe by index
    *
    * @return 0 if failed

    * Get a keyframe by index. You can loop over all the keyframes until it returns
    * false or the keyframe is NULL
    */
    int get_keyframe(int keyIndex, KEYFRAME_BASE& keyframe);

    /*! @brief get number of keyframes
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_keyframes_num(int* numKeyframes);

    /*! @brief get channel name
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_name(const char** channelName);

    /*! @brief get valid channel min value
    *
    * @return 0 if failed

    *  These values are the valid min and max values for the channel. e.g alpha
    *  goes from 0.0 to 100.0. This is mainly used for plugin parameters
    */
    int get_min(double* minValue);

    /*! @brief get valid channel max value
    *
    * @return 0 if failed

    *  These values are the valid min and max values for the channel. e.g alpha
    *  goes from 0.0 to 100.0. This is mainly used for plugin parameters
    */
    int get_max(double* maxValue);

    /*! @brief Delete all the keyframes of this channel
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int clear();

    /*! @brief Create a keyframe at a certain time
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int create_keyframe(double timeInSeconds, KEYFRAME_BASE& keyframe);

    /*! @brief delete the specified keyframe
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int delete_keyframe(KEYFRAME_BASE& keyframe);

    /*! @brief delete the specified keyframe
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_build_count(int* build_count);

    /*! @brief get value at a certain time
    *
    * @return 0 if failed

    * The following methods compute the value of an animation at the specified time
    * without modifying the animated object. Note that for psoition channels,
    * you can also call CHANNEL_POS::get_value_and_direction_by_time, which also
    * returns the tangetial direction.
    * This function gets the value for float channels.
    */
    int get_value_by_time(double time, float* pValue); // for float channels

    /*! @brief get value at a certain time
    *
    * @return 0 if failed

    * Get value for bool channels.
    */
    int get_value_by_time(double time, bool* pValue);

    /*! @brief get value at a certain time
    *
    * @return 0 if failed

    * Get value for integer channels.
    */
    int get_value_by_time(double time, int* pValue);

    /*! @brief get value at a certain time
    *
    * @return 0 if failed

    * Get value position/rotation/scaling channels.
    */
    int get_value_by_time(double time, evVertex3D* pValue);

    /*! @brief convert stage time to channel time
    *
    * @return 0 if failed

    * This method converts stage time (= global time) into channel time.
    * All CHANNEL methods accept channel time, which may differ from stage time
    * if director and container offsets are involved.
    */
    int convert_stage_time_to_channel_time(double stageTime, double* pChannelTime);

    /*! @brief convert channel time to stage time
    *
    * @return 0 if failed

    * This method converts channel time (= global time) into channel time.
    * All CHANNEL methods accept channel time, which may differ from stage time
    * if director and container offsets are involved.
    */
    int convert_channel_time_to_stage_time(double channelTime, double* pStageTime);

    /*! @brief create a dummy animation
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_dummy_animation(bool bDummyAnimation);

    /*! @brief get the channels director
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_director(DIRECTOR& director);

    /*! @brief get the channels director
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_director(const DIRECTOR& director);

    /*! @brief move to a director
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int move_to_director(const DIRECTOR& director);

    /*! @brief copy to a director
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int copy_to_director(const DIRECTOR& director);

    /*! @brief get animation container
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_animation_container(CONTAINER& container);

    /*! @brief get animation object
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_animation_object(BASE& object);

    /*! @brief get command name
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_command_name(const char ** pCommandName);

    /*! @brief set channel name
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_name(const char * name);

    /*! @brief activate (default) or de-activate animation calculation
    *
    * @return 0 if failed

    * Activates/deactivates automatic animation (spline) calculation 
    * (can be turned of while creating a lot of keyframes to improve performance)
    */
    int set_auto_updating(bool update);

    /*! @brief get status of animation calculation update flag
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_auto_updating(bool &update);

    /*! @brief get channel container offset
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_container_offset(double* offset);

    /*! @brief get total channel offset
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_total_offset(double * pOffset);

    /*! @brief set container channel offset
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_container_offset(double offset);

    /*! @brief get channel start time
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_start_time(bool bGetAbsoluteTime, double* pTime);

    /*! @brief get channel end time
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_end_time(bool bGetAbsoluteTime, double * pTime);

    /*! @brief set pre-swing
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_pre_swing(bool val);

    /*! @brief set post-swing
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_post_swing(bool val);

    /*! @brief set pre-loop
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_pre_loop(bool val);

    /*! @brief set post-loop
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_post_loop(bool val);

    /*! @brief set pre-loop count
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_pre_loop_counter(int val);

    /*! @brief set post-loop count
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int set_post_loop_counter(int val);

    /*! @brief get pre-swing
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_pre_swing(bool * val);

    /*! @brief get post-swing
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_post_swing(bool * val);

    /*! @brief get pre-loop
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_pre_loop(bool * val);

    /*! @brief get post-loop
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_post_loop(bool * val);

    /*! @brief get pre loop-counter
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_pre_loop_counter(int * val);

    /*! @brief get post loop-counter
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_post_loop_counter(int * val);

    /*! @brief get number of keyframes of this channel
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_number_of_keyframes(int * pResult);

    /*! @brief get first keyframe
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_first_keyframe(KEYFRAME_BASE &keyframe);

    /*! @brief get first keyframe
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int get_last_keyframe(KEYFRAME_BASE &keyframe);

    /*! @brief delete keyframe by index
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int delete_keyframe_by_index(int index);

    /*! @brief adds a keyframe at a certain time
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int add_keyframe(double time, KEYFRAME_BASE &keyframe);

    /*! @brief updates and recalculates the current channel
    *
    * @return 0 if failed

    * @todo documentation to be done.
    */
    int update();
};

class CHANNEL_POS : public CHANNEL
{
public:
    CHANNEL_POS();
    CHANNEL_POS(const CHANNEL& channel);
    CHANNEL_POS& operator=(const CHANNEL& channel);

    //Set/Get Closed Path
    int get_closed(int* closed);
    int set_closed(int closed);

    //Path Length
    int get_total_path_length(double* totalLength);

    // Computes the value of the position animation at 'time' without modifying the animated object.
    // The result is stored in 'pValue'.
    // Optionally, if pDirection != NULL, the tangential direction at 'time' is returned in pDirection.
    int get_value_and_direction_by_time(double time, evVertex3D* pValue, evVertex3D* pDirection);

    // Locks or unlocks all position keyframes.
    int lock_all_key_frames(bool bLocked);

    // Miscellaneous methods used by dummy channels (=channels not attached to an object).
    int set_calculate_direction(bool value);
    int get_calculate_direction(bool* value);
    int get_last_direction(float* x, float* y, float* z);
    int get_direction_by_time(double time, float* x, float* y, float* z);
    int get_frame_by_time(double time, float* x, float* y, float* z);
};

#endif // EV_PLUGIN_CHANNEL_H
