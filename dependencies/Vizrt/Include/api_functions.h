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

#ifndef __API_FUNCTIONS_H__
#define __API_FUNCTIONS_H__

#include "evPlugin_DynInterface.h"
#include "evMath.h"


#if _MSC_VER >= 1600

#include <stdint.h>

#else

#ifndef MV_ANSI_TYPES
#define MV_ANSI_TYPES

typedef __int8 int8_t;              // Signed 8 bits integer value.
typedef __int16 int16_t;            // Signed 16 bits integer value.
typedef __int32 int32_t;            // Signed 32 bits integer value.
typedef __int64 int64_t;            // Signed 64 bits integer value.

typedef unsigned __int8 uint8_t;    // Unsigned 8 bits integer value.
typedef unsigned __int16 uint16_t;  // Unsigned 16 bits integer value.
typedef unsigned __int32 uint32_t;  // Unsigned 32 bits integer value.
typedef unsigned __int64 uint64_t;  // Unsigned 64 bits integer value.

#ifndef _WCHAR_T_DEFINED
typedef uint16_t wchar_t;           // Unicode character.  Unsigned 16 bits value.
#define _WCHAR_T_DEFINED
#endif

#endif // MV_ANSI_TYPES

#endif // #if MSC_VER >= 1600




class OBJECTBASE;
class CONTAINER;
class GEOMETRY;
class SensorBufferData;

#define _VIZ_API_FUNCTIONS_MAX_RETARG_LENGTH 32768
//used by script functions

#ifndef _EVEREST
    // redirect opengl-calls to viz.
    #include "vizOpenGL.h"
#else
    #include "vizOGLContext.h"
#endif





class SCENE;

#ifdef __cplusplus
extern "C" {
#endif

VIZENGINE_API void _api__set_object(const OBJECTBASE *object);
VIZENGINE_API int _api__get_objectid(const char* container, const char* object, int type);
VIZENGINE_API int _api__get_objectid_local(const char* object, int type);
VIZENGINE_API int _api__get_objectid_from_id(int iObjectID, const char* object, int type);
VIZENGINE_API int _api__get_objectid_from_objectid(int id);
VIZENGINE_API int _api__get_objectid_global(const char* container, const char* object,int type);
VIZENGINE_API int _api__get_objectid_from_current_object();
VIZENGINE_API int _api__object_valid(int iObjectID);
VIZENGINE_API int _api__get_name(int objectId, const char** name);
VIZENGINE_API int _api__get_location_local(int objectId, const char** name);
VIZENGINE_API int _api__get_location_global(int objectId, const char** name);
VIZENGINE_API int _api__get_object_event_name(int objectId, const char** name);
VIZENGINE_API int _api__get_location_path(int objectId, const char** name);
VIZENGINE_API int _api__set_changed(int iObjectID);
VIZENGINE_API int _api__get_reference_count(int iObjectID, int * nReferenceCount);
VIZENGINE_API int _api__reference_create(int iObjectID);
VIZENGINE_API int _api__reference_delete(int iObjectID);

VIZENGINE_API int _api__get_local_container();
VIZENGINE_API int _api_get_position_of_container(int containerId);

//stack function meaningless in 3.0
//VIZENGINE_API void _api__push_object(OBJECTBASE *object);
//VIZENGINE_API void _api__pop_object(void);
//VIZENGINE_API void _api__push_scene(OBJECTBASE* object);
//VIZENGINE_API void _api__pop_scene(void);

//VIZENGINE_API SCENE * _api__get_scene(void);


VIZENGINE_API int _api__is_class(int objectID, int vizClassID, bool* pResult);

VIZENGINE_API int _api__get_cameraid(int camera_number, const char* object, int type);
VIZENGINE_API int _api__get_cameraid_local(const char* object, int type);

VIZENGINE_API int _api__get_lightid(int light_number, const char* object, int type);
VIZENGINE_API int _api__get_lightid_local(const char* object, int type);

VIZENGINE_API int _api__get_sceneid_local(void);

VIZENGINE_API char* _api__alloc_memory(size_t size);
VIZENGINE_API void _api__free_memory(void* ptr);

// BASE -- Animation
VIZENGINE_API int _api__get_valid_animobj_id(int objectID);
VIZENGINE_API int _api__is_animated(int objectID, bool* pRes);
VIZENGINE_API int _api__get_number_of_animation_channels_for_object(int objectID, int* pNumChannels);
VIZENGINE_API int _api__get_number_of_animation_channels_for_object_ex(int objectID, int* pNumChannels, bool includeChannelsOfSubObject);

VIZENGINE_API int _api__base_find_animation_channel(int objectID, const char* channelName, int* pChannelId, bool includeChannelsOfSubObject);
VIZENGINE_API int _api__base_find_or_create_animation_channel(int objectID, const char* channelName, int* pChannelId);
VIZENGINE_API int _api__base_find_keyframe(int objectID, const char* keyframeName, int* pKeyframeId, bool includeKeyframesOfSubObject);

VIZENGINE_API int _api__get_animation_channels_for_object(int objectID, int* pArraySize, int** pIdArray);
VIZENGINE_API int _api__get_animation_channels_for_object_ex(int objectID, int* pArraySize, int** pIdArray, bool includeChannelsOfSubObject);
VIZENGINE_API int _api__get_animation_channel_for_object_and_name(int objectID, const char* channelName, int* pChannelId);
VIZENGINE_API int _api__get_animatable_locations_for_anim_object(int objectID, int* pSizeOfLocArray, const char*** pLocArray);
VIZENGINE_API int _api__add_animation_channel(int animObjectID, const char* location, int directorID, int* pChannelID);
VIZENGINE_API int _api__has_animation_channel(int animObjectID, const char* location, int directorID, bool* pResult);

// CHANNEL & KEYFRAME
VIZENGINE_API int _api__channel_get_swing(int object_id, int* swing);
VIZENGINE_API int _api__channel_set_swing(int object_id, int swing);
VIZENGINE_API int _api__channel_get_loop(int object_id, int* loop);
VIZENGINE_API int _api__channel_set_loop(int object_id, int loop);
VIZENGINE_API int _api__channel_get_loop_counter(int object_id, int* loopCounter);
VIZENGINE_API int _api__channel_set_loop_counter(int object_id, int loopCounter);
VIZENGINE_API int _api__channel_get_start(int object_id, double* time);
VIZENGINE_API int _api__channel_get_end(int object_id, double* time);
VIZENGINE_API int _api__channel_move_keyframe(int object_id, double start, double end, double offset);
VIZENGINE_API int _api__channel_scale_keyframe(int object_id, double start, double end, double origin, double factor);
VIZENGINE_API int _api__channel_search_keyframe(int object_id, const char* keyFrameName, int* keyframe);
VIZENGINE_API int _api__channel_get_keyframe(int object_id, int keyIndex, int* keyframe);
VIZENGINE_API int _api__channel_get_keyframes_num(int object_id, int* numKeyframes);
VIZENGINE_API int _api__channel_get_name(int object_id, const char** channelName);
VIZENGINE_API int _api__channel_get_min(int object_id, double *minValue);
VIZENGINE_API int _api__channel_get_max(int object_id, double* maxValue);
VIZENGINE_API int _api__channel_clear(int object_id);
VIZENGINE_API int _api__channel_create_keyframe(int object_id, double time, int* keyframe);
VIZENGINE_API int _api__channel_delete_keyframe(int object_id, int keyframe);

VIZENGINE_API int _api__keyframe_base_get_name(int object_id, const char** keyframeName);
VIZENGINE_API int _api__keyframe_base_set_name(int object_id, const char* keyframeName);
VIZENGINE_API int _api__keyframe_base_get_time(int object_id, double* time);
VIZENGINE_API int _api__keyframe_base_set_time(int object_id, double time);
VIZENGINE_API int _api__keyframe_base_get_type(int object_id, int* keyType);
VIZENGINE_API int _api__keyframe_base_get_channel(int object_id, int* channel);
VIZENGINE_API int _api__keyframe_base_clear(int object_id);

VIZENGINE_API int _api__keyframe_handle_get_left_angle(int object_id, int handle_id, float* leftAngle);
VIZENGINE_API int _api__keyframe_handle_set_left_angle(int object_id, int handle_id, float leftAngle);
VIZENGINE_API int _api__keyframe_handle_get_right_angle(int object_id, int handle_id, float* rightAngle);
VIZENGINE_API int _api__keyframe_handle_set_right_angle(int object_id, int handle_id, float rightAngle);
VIZENGINE_API int _api__keyframe_handle_get_left_weight(int object_id, int handle_id, float* leftWeight);
VIZENGINE_API int _api__keyframe_handle_set_left_weight(int object_id, int handle_id, float leftWeight);
VIZENGINE_API int _api__keyframe_handle_get_right_weight(int object_id, int handle_id, float* rightWeight);
VIZENGINE_API int _api__keyframe_handle_set_right_weight(int object_id, int handle_id, float rightWeight);
VIZENGINE_API int _api__keyframe_handle_get_left_mode(int object_id, int handle_id, int* leftMode);
VIZENGINE_API int _api__keyframe_handle_set_left_mode(int object_id, int handle_id, int leftMode);
VIZENGINE_API int _api__keyframe_handle_get_right_mode(int object_id, int handle_id, int* rightMode);
VIZENGINE_API int _api__keyframe_handle_set_right_mode(int object_id, int handle_id, int rightMode);
VIZENGINE_API int _api__keyframe_handle_get_lock_mode(int object_id, int handle_id, int* lockMode);
VIZENGINE_API int _api__keyframe_handle_set_lock_mode(int object_id, int handle_id, int lockMode);

VIZENGINE_API int _api__keyframe_float_get(int object_id, float* value);
VIZENGINE_API int _api__keyframe_float_set(int object_id, float value);

VIZENGINE_API int _api__keyframe_bool_get(int object_id, int* value);
VIZENGINE_API int _api__keyframe_bool_set(int object_id, int value);

VIZENGINE_API int _api__keyframe_int_get(int object_id, int* value);
VIZENGINE_API int _api__keyframe_int_set(int object_id, int value);

VIZENGINE_API int _api__keyframe_event_get_value(int object_id, int* value);
VIZENGINE_API int _api__keyframe_event_set_value(int object_id, int value);
VIZENGINE_API int _api__keyframe_event_get_direction(int object_id, int* direction);
VIZENGINE_API int _api__keyframe_event_set_direction(int object_id, int direction);
__declspec(deprecated(" this is a deprecated function. please use _api__keyframe_event_get_duration_in_secs()."))
VIZENGINE_API int _api__keyframe_event_get_duration(int object_id, int* duration); // deprecated
__declspec(deprecated(" this is a deprecated function. please use _api__keyframe_event_set_duration_in_secs()."))
VIZENGINE_API int _api__keyframe_event_set_duration(int object_id, int duration); // deprecated
VIZENGINE_API int _api__keyframe_event_get_duration_in_secs(int object_id, double* duration);
VIZENGINE_API int _api__keyframe_event_set_duration_in_secs(int object_id, double duration);

VIZENGINE_API int _api__keyframe_push_button_get_direction(int object_id, int* direction);
VIZENGINE_API int _api__keyframe_push_button_set_direction(int object_id, int direction);

VIZENGINE_API int _api__keyframe_color_get(int object_id, float* r, float* g, float* b, float* a);
VIZENGINE_API int _api__keyframe_color_set(int object_id, float r, float g, float b, float a);

VIZENGINE_API int _api__keyframe_xyz_get(int object_id, float* x, float* y, float* z);
VIZENGINE_API int _api__keyframe_xyz_set(int object_id, float x, float y, float z);

// STAGE
VIZENGINE_API int _api__stage_get_local_id();
VIZENGINE_API int _api__stage_is_animation_running(int stageID, bool* pResult);
VIZENGINE_API int _api__stage_start_animation(int stageID);
VIZENGINE_API int _api__stage_start_animation_rev(int stageID);
VIZENGINE_API int _api__stage_stop_animation(int stageID);
VIZENGINE_API int _api__stage_continue_animation(int stageID);
VIZENGINE_API int _api__stage_continue_animation_rev(int stageID);

VIZENGINE_API int _api__stage_get_time_set_by_show_command(int object_id, double *time);

VIZENGINE_API int _api__stage_get_director(int object_id, const char *name, int *dir_id);
VIZENGINE_API int _api__stage_add_director(int object_id, const char *name, int *dir_id);
VIZENGINE_API int _api__stage_get_time(int object_id, double* time);
VIZENGINE_API int _api__stage_set_time(int object_id, double time);

VIZENGINE_API int _api__stage_has_directors(int stageID, bool* pResult);
VIZENGINE_API int _api__stage_get_root_director(int stageID, int* pDirectorID);
VIZENGINE_API int _api__stage_get_new_root_director(int stageID, int* pDirectorID);
VIZENGINE_API int _api__stage_create_root_director(int stageID, int* pDirectorID);

VIZENGINE_API int _api__stage_update_gui(int stageID);
VIZENGINE_API int _api__stage_update_animation_editor(int stageID);

VIZENGINE_API int _api__stage_find_director_by_name(int stageID, const char* name);

VIZENGINE_API int _api__stage_redraw();
VIZENGINE_API int _api__stage_get_stage_length(int stageID, bool bIIncludeLoop, double* start ,double* end  );

// DIRECTOR
VIZENGINE_API int _api__director_find_sub_director_by_name(int directorID, const char* name);

VIZENGINE_API int _api__director_get_stage(int directorID, int* pStageID);

VIZENGINE_API int _api__director_set_name(int directorID, const char* name);
VIZENGINE_API int _api__director_get_name(int directorID, const char** pName);

VIZENGINE_API int _api__director_set_time(int directorID, double time);
VIZENGINE_API int _api__director_get_time(int directorID, double* pTime);

VIZENGINE_API int _api__director_go_to(int directorID, const char* stopA, const char* stopB);
VIZENGINE_API int _api__director_go_to_rel(int directorID, const char* stopA, const char* stopB);
VIZENGINE_API int _api__director_go_to_trio(int directorID, const char* stopA, const char* stopB);

VIZENGINE_API int _api__director_get_field(int directorID, uint64_t* pField);

VIZENGINE_API int _api__director_set_local_offset(int directorID, double offset);
VIZENGINE_API int _api__director_get_local_offset(int directorID, double* pOffset);
VIZENGINE_API int _api__director_get_total_offset(int directorID, double* pOffset);

VIZENGINE_API int _api__director_get_start_time(int directorID, bool bGetAbsoluteTime, double* pTime);
VIZENGINE_API int _api__director_get_end_time(int directorID, bool bGetAbsoluteTime, double* pTime);

VIZENGINE_API int _api__director_next(int* pDirectorID);
VIZENGINE_API int _api__director_previous(int* pDirectorID);
VIZENGINE_API int _api__director_level_up(int* pDirectorID);
VIZENGINE_API int _api__director_level_down(int* pDirectorID);

VIZENGINE_API int _api__director_is_animation_running(int directorID, bool* pResult);
VIZENGINE_API int _api__director_start_animation(int directorID);
VIZENGINE_API int _api__director_start_animation_rev(int object_id);
VIZENGINE_API int _api__director_stop_animation(int directorID, bool bRecursive);
VIZENGINE_API int _api__director_continue_animation(int directorID);
VIZENGINE_API int _api__director_continue_animation_rev(int directorID);

VIZENGINE_API int _api__get_director_for_container(int cont_id);
VIZENGINE_API int _api__director_get_offset(int object_id, double* time);
VIZENGINE_API int _api__director_set_offset(int object_id, double time);

VIZENGINE_API int _api__director_get_number_of_animation_channels(int directorID, int* pResult);
VIZENGINE_API int _api__director_get_number_of_action_channels(int directorID, int* pResult);
VIZENGINE_API int _api__director_get_animation_channels(int directorID, int* pSizeOfIdArray, int** pIdArray);
VIZENGINE_API int _api__director_get_action_channels(int directorID, int* pSizeOfIdArray, int** pIdArray);
VIZENGINE_API int _api__director_get_event_channel(int directorID, int* pChannelID);
VIZENGINE_API int _api__director_get_animation_channel(int directorID, int index, int* pChannelID);
VIZENGINE_API int _api__director_get_action_channel(int directorID, int index, int* pChannelID);

VIZENGINE_API int _api__director_delete_channel(int directorID, int channelID);
VIZENGINE_API int _api__director_addDirector(int directorID, int where, int* pDirectorID);

VIZENGINE_API int _api__director_move(int directorID, int targetDirectorID, int where);
VIZENGINE_API int _api__director_copy(int directorID, int targetDirectorID, int where, int* pNewDirectorID);

VIZENGINE_API int _api__director_delete(int directorID);

// <old channel and keyframe functions>

// CHANNEL
VIZENGINE_API int _api__channel_is_float_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_int_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_bool_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_position_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_rotation_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_scaling_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_material_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_color_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_event_channel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_is_action_channel(int channelID, bool* pResult);

VIZENGINE_API int _api__channel_get_director(int channelID, int* pDirectorID);
VIZENGINE_API int _api__channel_set_director(int channelID, int directorID);
VIZENGINE_API int _api__channel_move_to_director(int channelID, int directorID);
VIZENGINE_API int _api__channel_copy_to_director(int channelID, int directorID);
VIZENGINE_API int _api__channel_get_animation_container(int channelID, int* animObjID);
VIZENGINE_API int _api__channel_get_animation_object(int channelID, int* animObjID);

VIZENGINE_API int _api__channel_get_command_name(int channelID, const char** pCommandName);
VIZENGINE_API int _api__channel_set_name(int channelID, const char* name);
VIZENGINE_API int _api__channel_get_name(int channelID, const char** pName);

VIZENGINE_API int _api__channel_set_container_offset(int channelID, double offset);
VIZENGINE_API int _api__channel_get_container_offset(int channelID, double* pOffset);
VIZENGINE_API int _api__channel_get_total_offset(int channelID, double* pOffset);

VIZENGINE_API int _api__channel_get_start_time(int channelID, bool bGetAbsoluteTime, double* pTime);
VIZENGINE_API int _api__channel_get_end_time(int channelID, bool bGetAbsoluteTime, double* pTime);

VIZENGINE_API int _api__channel_set_pre_swing(int channelID, bool val);
VIZENGINE_API int _api__channel_set_post_swing(int channelID, bool val);
VIZENGINE_API int _api__channel_set_pre_loop(int channelID, bool val);
VIZENGINE_API int _api__channel_set_post_loop(int channelID, bool val);
VIZENGINE_API int _api__channel_set_pre_loop_counter(int channelID, int val);
VIZENGINE_API int _api__channel_set_post_loop_counter(int channelID, int val);

VIZENGINE_API int _api__channel_get_pre_swing(int channelID, bool* val);
VIZENGINE_API int _api__channel_get_post_swing(int channelID, bool* val);
VIZENGINE_API int _api__channel_get_pre_loop(int channelID, bool* val);
VIZENGINE_API int _api__channel_get_post_loop(int channelID, bool* val);
VIZENGINE_API int _api__channel_get_pre_loop_counter(int channelID, int* val);
VIZENGINE_API int _api__channel_get_post_loop_counter(int channelID, int* val);

VIZENGINE_API int _api__channel_get_number_of_keyframes(int channelID, int* pResult);
VIZENGINE_API int _api__channel_get_first_keyframe(int channelID, int* pKeyframeId);
VIZENGINE_API int _api__channel_get_last_keyframe(int channelID, int* pKeyframeId);
VIZENGINE_API int _api__channel_get_keyframe(int channelID, int index, int* pKeyframeId);

VIZENGINE_API int _api__channel_get_keyframes(int channelID, int* pSizeOfIdArray, int** pIdArray);
VIZENGINE_API int _api__channel_delete_keyframe(int channelID, int keyframeID);
VIZENGINE_API int _api__channel_delete_keyframe_by_index(int channelID, int index);
VIZENGINE_API int _api__channel_add_keyframe(int channelID, double time, int* pKeyframeID);

VIZENGINE_API int _api__channel_has_subchannel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_get_subchannel(int channelID, int* pSubChannelID);
VIZENGINE_API int _api__channel_is_subchannel(int channelID, bool* pResult);
VIZENGINE_API int _api__channel_get_main_channel(int channelID, int* pSubChannelID);

VIZENGINE_API int _api__channel_delete(int channelID);

VIZENGINE_API int _api__channel_update(int channelID);
VIZENGINE_API int _api__channel_set_auto_updating(int channelID, bool update);
VIZENGINE_API int _api__channel_get_auto_updating(int channelID, bool &update);
VIZENGINE_API int _api__channel_get_build_count(int object_id, int* build_count);
VIZENGINE_API int _api__channel_pos_set_dummy_animation(int object_id, bool bDummyAnimation);

VIZENGINE_API int _api__convert_stage_time_to_channel_time(int channelId, double stageTime, double* pChannelTime);
VIZENGINE_API int _api__convert_channel_time_to_stage_time(int channelId, double channelTime, double* pStageTime);

// CHANNEL_POS
VIZENGINE_API int _api__channel_pos_get_frame_by_time(int object_id, double time, float* x, float* y, float* z);
VIZENGINE_API int _api__channel_pos_get_total_path_length(int object_id, double* totalLength);
VIZENGINE_API int _api__channel_pos_get_closed(int object_id, int* closed);
VIZENGINE_API int _api__channel_pos_set_closed(int object_id, int closed);
VIZENGINE_API int _api__channel_pos_set_calculate_direction(int object_id, bool value);
VIZENGINE_API int _api__channel_pos_get_calculate_direction(int object_id, bool* value);
VIZENGINE_API int _api__channel_pos_get_last_direction(int object_id, float* x, float* y, float* z);
VIZENGINE_API int _api__channel_pos_get_direction_by_time(int object_id, double time, float* x, float* y, float* z);
VIZENGINE_API int _api__channel_pos_set_all_key_frames_locked(int object_id, bool bLocked);

VIZENGINE_API int _api__channel_float_get_frame_by_time(int channelId, double time, float* pValue);
VIZENGINE_API int _api__channel_xyz_get_value_by_time(int channelId, double time, float pXyzValues[3]);
VIZENGINE_API int _api__channel_bool_get_value_by_time(int channelId, double time, bool* pValue);
VIZENGINE_API int _api__channel_int_get_value_by_time(int channelId, double time, int* pValue);
VIZENGINE_API int _api__channel_pos_get_value_and_direction_by_time(int channelId, double time, float pXyzValues[3], float pDirection[3]);

// KEYFRAME
VIZENGINE_API int _api__keyframe_get_channel(int keyframeID, int* pChannelID);

VIZENGINE_API int _api__keyframe_set_name(int keyframeID, const char* name);
VIZENGINE_API int _api__keyframe_get_name(int keyframeID, const char** pName);
VIZENGINE_API int _api__keyframe_set_time(int keyframeID, double time);
VIZENGINE_API int _api__keyframe_get_time(int keyframeID, double* pTime);

VIZENGINE_API int _api__keyframe_set_float_value(int keyframeID, float value);
VIZENGINE_API int _api__keyframe_set_float_value_by_axis(int keyframeID, int axisIndex, float value);
VIZENGINE_API int _api__keyframe_set_int_value(int keyframeID, int value);
VIZENGINE_API int _api__keyframe_set_bool_value(int keyframeID, bool value);
VIZENGINE_API int _api__keyframe_set_xyz_values(int keyframeID, float x, float y, float z);
VIZENGINE_API int _api__keyframe_set_material_value(int keyframeID, int materialID);
VIZENGINE_API int _api__keyframe_set_color_value(int keyframeID, long value);

VIZENGINE_API int _api__keyframe_get_float_value(int keyframeID, float* pValue);
VIZENGINE_API int _api__keyframe_get_float_value_by_axis(int keyframeID, int axisIndex, float* pValue);
VIZENGINE_API int _api__keyframe_get_int_value(int keyframeID, int* pValue);
VIZENGINE_API int _api__keyframe_get_bool_value(int keyframeID, bool* pValue);
VIZENGINE_API int _api__keyframe_get_xyz_values(int keyframeID, float* x, float* y, float* z);
VIZENGINE_API int _api__keyframe_get_material_value(int keyframeID, int* materialID);
VIZENGINE_API int _api__keyframe_get_color_value(int keyframeID, long* pColor);

VIZENGINE_API int _api__keyframe_set_locked(int keyframeID, bool bLocked);
VIZENGINE_API int _api__keyframe_get_locked(int keyframeID, bool* pbLocked);

VIZENGINE_API int _api__keyframe_get_number_of_axes(int keyframeID, int* pValue);
VIZENGINE_API int _api__keyframe_get_bezier_handle(int keyframeID, int index, int* pHandleID);

VIZENGINE_API int _api__keyframe_get_next_keyframe(int keyframeID, int* pNextKfId);
VIZENGINE_API int _api__keyframe_get_previous_keyframe(int keyframeID, int* pPrevKfId);

VIZENGINE_API int _api__keyframe_delete(int keyframeID);
VIZENGINE_API int _api__keyframe_update_animation(int keyframeID);

// </old channel and keyframe functions>

// BEZIER_HANDLE
VIZENGINE_API int _api_bezier_handle_set_left_angle(int handleID, float value);
VIZENGINE_API int _api_bezier_handle_set_left_weight(int handleID, float value);
VIZENGINE_API int _api_bezier_handle_set_left_mode(int handleID, int value);
VIZENGINE_API int _api_bezier_handle_set_right_angle(int handleID, float value);
VIZENGINE_API int _api_bezier_handle_set_right_weight(int handleID, float value);
VIZENGINE_API int _api_bezier_handle_set_right_mode(int handleID, int value);
VIZENGINE_API int _api_bezier_handle_set_lock_mode(int handleID, int value);
VIZENGINE_API int _api_bezier_handle_get_left_angle(int handleID, float* pValue);
VIZENGINE_API int _api_bezier_handle_get_left_weight(int handleID, float* pValue);
VIZENGINE_API int _api_bezier_handle_get_left_mode(int handleID, int* pValue);
VIZENGINE_API int _api_bezier_handle_get_right_angle(int handleID, float* pValue);
VIZENGINE_API int _api_bezier_handle_get_right_weight(int handleID, float* pValue);
VIZENGINE_API int _api_bezier_handle_get_right_mode(int handleID, int* pValue);
VIZENGINE_API int _api_bezier_handle_get_lock_mode(int handleID, int* pValue);

// CONTAINER
VIZENGINE_API int _api__container_set_active(int iObjectID, int value);
VIZENGINE_API int _api__container_get_active(int iObjectID, int *value);
VIZENGINE_API int _api__container_get_is_visible(int iObjectID, bool bCheckParents, bool bCheckAlphaValue, bool* pbVisbility);
VIZENGINE_API int _api__container_set_name(int iObjectID, const char *value);
VIZENGINE_API int _api__container_get_name(int iObjectID, const char **value);
VIZENGINE_API int _api__container_next(int* iObjectID);
VIZENGINE_API int _api__container_prev(int* iObjectID);
VIZENGINE_API int _api__container_level_up(int* iObjectID);
VIZENGINE_API int _api__container_level_down(int* iObjectID);
VIZENGINE_API int _api__container_level_up_2(int* iObjectID);
VIZENGINE_API int _api__container_level_down_2(int* iObjectID);
VIZENGINE_API int _api__container_add(int* iObjectID, int where);
VIZENGINE_API int _api__container_delete(int iObjectID);
VIZENGINE_API int _api__container_delete_under(int iObjectID);
VIZENGINE_API int _api__container_move(int iObjectID, int target_id, int where);
VIZENGINE_API int _api__container_move_magic(int iObjectID, int target_id, int where);
VIZENGINE_API int _api__container_copy(int iObjectID, int target_id, int where);
VIZENGINE_API int _api__container_copy_props(int object_id, int target_id);
VIZENGINE_API int _api__container_has_neighbour(int iObjectID, int where);

VIZENGINE_API int _api__container_set_transform(int containerId, int transformId);
VIZENGINE_API int _api__container_set_position(int iObjectID, int value);
VIZENGINE_API int _api__container_set_position_vector(int iObjectID, const float* v);
VIZENGINE_API int _api__container_set_rotation(int iObjectID, int value);
VIZENGINE_API int _api__container_set_rotation_vector(int iObjectID, const float* v);
VIZENGINE_API int _api__container_set_scaling(int iObjectID, int value);
VIZENGINE_API int _api__container_set_scaling_vector(int iObjectID, const float* v);
VIZENGINE_API int _api__container_set_center(int iObjectID, int value);
VIZENGINE_API int _api__container_set_center_vector(int iObjectID, const float* v);
VIZENGINE_API int _api__container_set_alpha(int iObjectID, int value);
VIZENGINE_API int _api__container_set_key(int iObjectID, int value);
VIZENGINE_API int _api__container_set_material(int iObjectID, int value);
VIZENGINE_API int _api__container_set_material_location(int iObjectID, const char* value);
VIZENGINE_API int _api__container_set_geometry(int iObjectID, int value);
VIZENGINE_API int _api__container_set_texture(int iObjectID, int value);
VIZENGINE_API int _api__container_set_shader(int iObjectID, int value);
VIZENGINE_API int _api__container_set_viewport_tile(int iObjectID, int value);

VIZENGINE_API int _api__container_set_alpha_active(int iObjectID, int value);
VIZENGINE_API int _api__container_set_key_active(int iObjectID, int value);
VIZENGINE_API int _api__container_set_geometry_active(int iObjectID, int value);
VIZENGINE_API int _api__container_set_shader_active(int iObjectID, int value);

VIZENGINE_API int _api__container_set_open(int iObjectID, bool value);

VIZENGINE_API int _api__container_set_expert(int iObjectID, int value);
VIZENGINE_API int _api__container_set_expert_active(int iObjectID, bool value);

VIZENGINE_API int _api__container_set_infotext(int iObjectID, int value);

VIZENGINE_API int _api__container_set_glow(int iObjectID, int value);
VIZENGINE_API int _api__container_set_glow_active(int iObjectID, bool value);

VIZENGINE_API int _api__container_set_hdr(int iObjectID, int value);
VIZENGINE_API int _api__container_set_hdr_active(int iObjectID, bool value);

VIZENGINE_API int _api__container_set_mask(int iObjectID, int value);
VIZENGINE_API int _api__container_set_mask_active(int iObjectID, bool value);
VIZENGINE_API int _api__container_set_mask_target(int iObjectID, int value);
VIZENGINE_API int _api__container_set_mask_target_active(int iObjectID, bool value);

VIZENGINE_API int _api__container_set_clipper_target(int iObjectID, int value);
VIZENGINE_API int _api__container_set_clipper_target_active(int iObjectID, bool value);

VIZENGINE_API int _api__container_get_transform(int containerId, int* pTransformId);
VIZENGINE_API int _api__container_get_position(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_position_vector(int iObjectID, float* v);
VIZENGINE_API int _api__container_get_rotation(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_rotation_vector(int iObjectID, float* v);
VIZENGINE_API int _api__container_get_scaling(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_scaling_vector(int iObjectID, float* v);
VIZENGINE_API int _api__container_get_center(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_center_vector(int iObjectID, float* v);
VIZENGINE_API int _api__container_get_alpha(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_key(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_material(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_geometry(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_texture(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_shader(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_viewport_tile(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_projector(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_projection_target(int iObjectID, int* value);

VIZENGINE_API int _api__container_get_alpha_active(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_key_active(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_geometry_active(int iObjectID, int* value);
VIZENGINE_API int _api__container_get_shader_active(int iObjectID, int* value);

VIZENGINE_API int _api__container_get_absolute_position(int iObjectID, float *x, float *y, float *z);
VIZENGINE_API int _api__container_get_absolute_rotation(int iObjectID, float *x, float *y, float *z);
VIZENGINE_API int _api__container_get_absolute_scaling(int iObjectID, float *x, float *y, float *z);

VIZENGINE_API int _api__container_get_open(int iObjectID, bool* value);

VIZENGINE_API int _api__container_get_expert(int iObjectID, int *value);
VIZENGINE_API int _api__container_get_expert_active(int iObjectID, bool *value);

VIZENGINE_API int _api__container_get_infotext(int iObjectID, int *value);

VIZENGINE_API int _api__container_get_glow(int iObjectID, int *value);
VIZENGINE_API int _api__container_get_glow_active(int iObjectID, bool *value);

VIZENGINE_API int _api__container_get_hdr(int iObjectID, int *value);
VIZENGINE_API int _api__container_get_hdr_active(int iObjectID, bool *value);

VIZENGINE_API int _api__container_get_mask(int iObjectID, int *value);
VIZENGINE_API int _api__container_get_mask_active(int iObjectID, bool *value);
VIZENGINE_API int _api__container_get_mask_target(int iObjectID, int *value);
VIZENGINE_API int _api__container_get_mask_target_active(int iObjectID, bool *value);

VIZENGINE_API int _api__container_get_clipper_target(int iObjectID, int *value);
VIZENGINE_API int _api__container_get_clipper_target_active(int iObjectID, bool *value);


VIZENGINE_API int _api__container_get_bounding_box(int iObjectID, float* lbb_x, float* lbb_y, float* lbb_z, float* rtf_x, float* rtf_y, float* rtf_z);
VIZENGINE_API int _api__container_get_bounding_box_no_inactive_nodes(int iObjectID, float* lbb_x, float* lbb_y, float* lbb_z, float* rtf_x, float* rtf_y, float* rtf_z);
VIZENGINE_API int _api__container_set_bounding_box(int iObjectID, float lbb_x, float lbb_y, float lbb_z, float rtf_x, float rtf_y, float rtf_z);
VIZENGINE_API int _api__container_reset_bounding_box(int iObjectID);

VIZENGINE_API int _api__container_create_material(int iObjectID, const char* value, bool always=true);
VIZENGINE_API int _api__container_create_geometry(int iObjectID, const char* value);
VIZENGINE_API int _api__container_create_geometry_bgl(int iObjectID, const char* value, unsigned int & requestId);
VIZENGINE_API int _api__container_create_key(int iObjectID);
VIZENGINE_API int _api__container_create_alpha(int iObjectID);
VIZENGINE_API int _api__container_create_texture(int iObjectID, const char* value);
VIZENGINE_API int _api__container_create_texture_bgl(int iObjectID, const char* value, unsigned int & requestId);
VIZENGINE_API int _api__container_create_texture_from_image_id(int iObjectID, int iImageID);
VIZENGINE_API int _api__container_create_viewport_tile(int iObjectID);
VIZENGINE_API int _api__container_create_function(int iObjectID, const char* value);
VIZENGINE_API int _api__container_create_shader(int iObjectID, const char * name);

VIZENGINE_API int _api__container_delete_material(int iObjectID);
VIZENGINE_API int _api__container_delete_geometry(int iObjectID);
VIZENGINE_API int _api__container_delete_key(int iObjectID);
VIZENGINE_API int _api__container_delete_alpha(int iObjectID);
VIZENGINE_API int _api__container_delete_texture(int iObjectID);
VIZENGINE_API int _api__container_delete_viewport_tile(int iObjectID);
VIZENGINE_API int _api__container_delete_function(int iObjectID, const char* name);
VIZENGINE_API int _api__container_delete_shader(int iObjectID);
VIZENGINE_API int _api__container_get_number_of_function_plugins(int iObjectID, unsigned int& num);
VIZENGINE_API int _api__container_get_function_plugins(int iObjectID, int function_id_array[], int array_size);
VIZENGINE_API int _api__container_get_transformation_matrix(int iObjectID, float* value);
VIZENGINE_API int _api__container_set_transformation_matrix(int iObjectID, float* value);
VIZENGINE_API int _api__container_set_external_matrix(int iObjectID, float* value);
VIZENGINE_API int _api__container_get_inverse_matrix(int iObjectID, float* value);
VIZENGINE_API int _api__container_recompute_matrix(int iObjectID);
VIZENGINE_API int _api__container_get_function(int iObjectID, int* value, const char* pszFunctionName);
VIZENGINE_API int _api__container_get_plugin_instance(int iObjectID, int* piPluginID, const char* pszPluginName);
VIZENGINE_API int _api__container_get_script_plugin_instance(int iObjectID, int* piPluginID);
VIZENGINE_API int _api__container_set_mode(int iObjectID, int value, bool add);

VIZENGINE_API int _api__rebuild_local_container();

VIZENGINE_API int _api__container_get_script_active(int iObjectID, bool* pbActive);
VIZENGINE_API int _api__container_set_script_active(int iObjectID, bool bActive);


VIZENGINE_API int _api__container_get_projector_mask(int iObjectID, int* value);
VIZENGINE_API int _api__container_set_projector_mask(int iObjectID, int value);
VIZENGINE_API int _api__container_get_projector_fovy(int iObjectID, float* value);
VIZENGINE_API int _api__container_set_projector_fovy(int iObjectID, float value);
VIZENGINE_API int _api__container_get_projector_tex_scale(int iObjectID, float *scale);
VIZENGINE_API int _api__container_set_projector_tex_scale(int iObjectID, float *scale);
VIZENGINE_API int _api__container_get_projector_tex_bias(int iObjectID, float *bias);
VIZENGINE_API int _api__container_set_projector_tex_bias(int iObjectID, float *bias);

VIZENGINE_API int _api__container_get_projection_target_mask(int iObjectID, int* value);
VIZENGINE_API int _api__container_set_projection_target_mask(int iObjectID, int value);

VIZENGINE_API int _api__container_has_projector(int iObjectID);
VIZENGINE_API int _api__container_has_projection_target(int iObjectID);

VIZENGINE_API int _api__container_create_projector(int iObjectID);
VIZENGINE_API int _api__container_create_projection_target(int iObjectID);
VIZENGINE_API int _api__container_create_expert(int iObjectID);
VIZENGINE_API int _api__container_create_infotext(int iObjectID);
VIZENGINE_API int _api__container_create_glow(int iObjectID);
VIZENGINE_API int _api__container_create_hdr(int iObjectID);
VIZENGINE_API int _api__container_create_mask(int iObjectID);
VIZENGINE_API int _api__container_create_mask_target(int iObjectID);
VIZENGINE_API int _api__container_create_clipper_target(int iObjectID);

VIZENGINE_API int _api__container_delete_projector(int iObjectID);
VIZENGINE_API int _api__container_delete_projection_target(int iObjectID);
VIZENGINE_API int _api__container_delete_expert(int iObjectID);
VIZENGINE_API int _api__container_delete_infotext(int iObjectID);
VIZENGINE_API int _api__container_delete_glow(int iObjectID);
VIZENGINE_API int _api__container_delete_hdr(int iObjectID);
VIZENGINE_API int _api__container_delete_mask(int iObjectID);
VIZENGINE_API int _api__container_delete_mask_target(int iObjectID);
VIZENGINE_API int _api__container_delete_clipper_target(int iObjectID);
VIZENGINE_API int _api__container_delete_animation(int iObjectID);
VIZENGINE_API int _api__container_container_animation(int iDestObjectID, int iSrcObjectID);
VIZENGINE_API bool _api__container_geo_llz2rs(int iObjectID,
                        double latitude, double longitude, double height, float& x, float& y, float& z);
VIZENGINE_API bool _api__container_geo_llz2rsLocal(int iObjectID,
                        double latitude, double longitude, double height, float& x, float& y, float& z);
VIZENGINE_API bool _api__container_geo_rs2llz(int iObjectID,
                        float x, float y, float z, double& longitude, double& latitude, double& height);
VIZENGINE_API bool _api__container_geo_rs2llzLocal(int iObjectID,
                        float x, float y, float z, double& longitude, double& latitude, double& height);
VIZENGINE_API bool _api__container_geo_llz2rsNormalized(int object_id,
                        double latitude, double longitude, double height, float& x, float& y, float& z);
VIZENGINE_API bool _api__container_geo_rs2llzNormalized(int object_id,
                        float x, float y, float z, double& longitude, double& latitude, double& height);
VIZENGINE_API bool _api__container_geo_llz2rsModel(int object_id,
                        double latitude, double longitude, double height, float& x, float& y, float& z);
VIZENGINE_API bool _api__container_geo_rs2llzModel(int object_id,
                        float x, float y, float z, double& longitude, double& latitude, double& height);
VIZENGINE_API bool _api__container_is_geo_image(int iObjectID);
VIZENGINE_API bool _api__container_geo_get_bbox(int iObjectID,
                        float& minx, float& maxx, float& miny, float& maxy);
VIZENGINE_API int _api__container_set_georef(int object_id, int value);
VIZENGINE_API int _api__container_get_georef(int object_id, int *value);
VIZENGINE_API int _api__container_delete_georef(int object_id);
VIZENGINE_API int _api__container_create_georef(int object_id);
VIZENGINE_API int _api__container_set_georef_active(int object_id, bool value);
VIZENGINE_API int _api__container_get_georefClosest(int object_id, int *value, bool searchTree);
VIZENGINE_API int _api__container_get_georef_active(int object_id, bool *value);

VIZENGINE_API int _api__container_set_draw_geometry_active(int object_id, int v);
VIZENGINE_API int _api__container_get_draw_geometry_active(int object_id, int *v);
VIZENGINE_API int _api__container_get_rotations_order(int object_id);
VIZENGINE_API void _api__container_set_rotations_order(int object_id, int rotOrder);

VIZENGINE_API int _api__container_get_director(int containerId, int* pDirectorId);
VIZENGINE_API int _api__container_set_animation_offset(int containerId, double offset);

VIZENGINE_API int _api__container_set_exact_picking(int containerId, bool value);
VIZENGINE_API int _api__container_get_exact_picking(int containerId, bool* pValue);

VIZENGINE_API int _api__container_show_one_child(int containerId, int childIndex);
VIZENGINE_API int _api__container_show_all_children(int containerId);
VIZENGINE_API int _api__container_hide_all_children(int containerId);
VIZENGINE_API int _api__container_get_index_of_first_active_child(int containerId);
VIZENGINE_API int _api__container_get_local_index(int containerId);
VIZENGINE_API int _api__container_get_sub_container_by_index(int containerId, int index);
VIZENGINE_API int _api__container_get_edited(int object_id, bool *value);

VIZENGINE_API int _api__container_get_is_merged(int containerId, bool* pValue);
VIZENGINE_API int _api__container_get_is_merged_and_animated(int containerId, bool* pValue);
VIZENGINE_API int _api__container_get_is_merged_and_controlled(int containerId, bool* pValue);

VIZENGINE_API int _api__container_get_director(int containerId, int* pDirectorId);

VIZENGINE_API int _api__container_set_force_transparency(int object_id, int force);
VIZENGINE_API int _api__container_get_force_transparency(int object_id, int *force);

VIZENGINE_API int _api__container_set_reference_geometry(int iObjectID, const char* value);

#ifdef HAS_VIZPHYSICS
// Physic
VIZENGINE_API void* _api__scene_get_physic(int iObjectID);
VIZENGINE_API int _api__container_set_rigidbody(int iObjectID, int value);
VIZENGINE_API int _api__container_get_rigidbody(int iObjectID, int* value);
VIZENGINE_API int _api__container_create_rigidbody(int iObjectID);
VIZENGINE_API int _api__container_delete_rigidbody(int iObjectID);

VIZENGINE_API int _api__container_rigidbody_attach(int iObjectID);
VIZENGINE_API int _api__container_rigidbody_deattach(int iObjectID);
VIZENGINE_API int _api__container_rigidbody_showGeometry(int iObjectID, int show);
VIZENGINE_API int _api__container_rigidbody_setTrigger(int iObjectID, int simulate);
VIZENGINE_API int _api__container_rigidbody_isTrigger(int iObjectID, int* res);
VIZENGINE_API int _api__container_rigidbody_setSimulated(int iObjectID, int simulate);
VIZENGINE_API int _api__container_rigidbody_isSimulated(int iObjectID, int* res);
VIZENGINE_API int _api__container_rigidbody_hasNoneDynamicShapes(int iObjectID, int* res);
VIZENGINE_API int _api__container_rigidbody_isDynamic(int iObjectID, int* res);
VIZENGINE_API int _api__container_rigidbody_isKinematic(int iObjectID, int* res);
VIZENGINE_API int _api__container_rigidbody_isStatic(int iObjectID, int* res);
VIZENGINE_API int _api__container_rigidbody_get_type(int iObjectID, int* res);
VIZENGINE_API int _api__container_rigidbody_set_type(int iObjectID, int type);
VIZENGINE_API int _api__container_rigidbody_set_scale(int iObjectID, float x, float y, float z);
VIZENGINE_API int _api__container_rigidbody_set_position(int iObjectID, float x, float y, float z);
VIZENGINE_API int _api__container_rigidbody_set_rotation(int iObjectID, float x, float y, float z);
VIZENGINE_API int _api__container_rigidbody_get_transform(int iObjectID, float* mat4x4);
VIZENGINE_API int _api__container_rigidbody_set_transform(int iObjectID, const float* mat4x4);
VIZENGINE_API int _api__container_rigidbody_set_staticFriction(int iObjectID, float staticFriction);
VIZENGINE_API int _api__container_rigidbody_set_dynamicFriction(int iObjectID, float dynamicFriction);
VIZENGINE_API int _api__container_rigidbody_set_restitution(int iObjectID, float restitution);
VIZENGINE_API int _api__container_rigidbody_removeAllShapes(int iObjectID);
VIZENGINE_API int _api__container_rigidbody_addSphere(int iObjectID, float radius, float center_x, float center_y, float center_z);
VIZENGINE_API int _api__container_rigidbody_addBox(int iObjectID, float width, float height, float depth, float center_x, float center_y, float center_z);
VIZENGINE_API int _api__container_rigidbody_addPlane(int iObjectID, float center_x, float center_y, float center_z);
VIZENGINE_API int _api__container_rigidbody_addConvex(int iObjectID, float center_x, float center_y, float center_z);
VIZENGINE_API int _api__container_rigidbody_addDecomposed(int iObjectID, float center_x, float center_y, float center_z);
VIZENGINE_API int _api__container_rigidbody_addTriangleMesh(int iObjectID, float center_x, float center_y, float center_z);
VIZENGINE_API int _api__container_rigidbody_set_gravity(int iObjectID, int disable);
VIZENGINE_API int _api__container_rigidbody_set_density(int iObjectID, float density);
VIZENGINE_API int _api__container_rigidbody_set_linearVelocity(int iObjectID, float x, float y, float z);
VIZENGINE_API int _api__container_rigidbody_set_angularVelocity(int iObjectID, float x, float y, float z);

#endif // HAS_VIZPHYSICS

VIZENGINE_API int _api__transformation_get_position(int transformId, int* pResId);
VIZENGINE_API int _api__transformation_get_rotation(int transformId, int* pResId);
VIZENGINE_API int _api__transformation_get_scaling(int transformId, int* pResId);
VIZENGINE_API int _api__transformation_get_center(int transformId, int* pResId);
VIZENGINE_API int _api__transformation_get_container(int transformId, int* pResId);

// POSITION
VIZENGINE_API int _api__set_position(int iObjectID, float x, float y, float z);
VIZENGINE_API int _api__get_position(int iObjectID, float *x, float *y, float *z);

// ROTATION
VIZENGINE_API int _api__set_rotation(int iObjectID, float x, float y, float z);
VIZENGINE_API int _api__get_rotation(int iObjectID, float *x, float *y, float *z);

// SCALING
VIZENGINE_API int _api__set_scaling(int iObjectID, float x, float y, float z);
VIZENGINE_API int _api__get_scaling(int iObjectID, float *x, float *y, float *z);

// CENTER
VIZENGINE_API int _api__set_center(int iObjectID, float x, float y, float z);
VIZENGINE_API int _api__get_center(int iObjectID, float *x, float *y, float *z);

// IMAGE
VIZENGINE_API int _api__get_image_objectid(const char* location);
VIZENGINE_API int _api__image_reload(int iObjectID);
VIZENGINE_API int _api__image_is_loaded(int iObjectID, bool &bLoaded);
VIZENGINE_API int _api__image_close(int iObjectID);
VIZENGINE_API int _api__set_image_pixel(int iObjectID, int x, int y, unsigned long color);
VIZENGINE_API int _api__get_image_pixel(int iObjectID, int x, int y, unsigned long *color);
VIZENGINE_API int _api__get_image_size(int iObjectID, int *x, int *y);
VIZENGINE_API int _api__get_image_data(int iObjectID, unsigned char **data);
VIZENGINE_API int _api__get_image_format(int iObjectID, int *format);
VIZENGINE_API int _api__rebuild_texture(int iObjectID);
VIZENGINE_API int _api__copy_image(int iObjectID);
VIZENGINE_API int _api__crop_image(int iObjectID, int left, int right, int up, int down);
VIZENGINE_API int _api__scale_image(int iObjectID, int x, int y);
VIZENGINE_API int _api__blur_image(int iObjectID, float value);
VIZENGINE_API int _api__flip_image(int iObjectID, char how);
VIZENGINE_API int _api__image_subtexload(int iObjectID, int level, int xoffset, int yoffset, int width, int height, int format, int type, void *pixels);
VIZENGINE_API int _api__image_subtexload_compressed(int iObjectID, int level, int width, int height, int texture_compression, int compressed_size, void *pixels);
VIZENGINE_API int _api__get_image_name(int iObjectID, char **value);
VIZENGINE_API int _api__image_set_subtexload(int iObjectID, int xStart, int xEnd, int yStart, int yEnd);
VIZENGINE_API int _api__create_image(int iObjectID,int width , int height,int format);
VIZENGINE_API int _api__create_image_from_file(const char* file_name);
VIZENGINE_API int _api__create_image_from_memory(const void* buffer, int buffer_size);
VIZENGINE_API int _api__create_compressed_image(int width, int height, int texture_compression, int compressed_size, void *pixels);
VIZENGINE_API int _api__convert_to_compressed_image(int iObjectID,int texture_compression );
VIZENGINE_API bool _api__set_free_image_data_after_define(int iObjectID, bool bAllow);

VIZENGINE_API int _api__set_image_format(int iObjectID,int  format);
VIZENGINE_API int _api__convert_to_image_format(int iObjectID,int  format);
VIZENGINE_API int _api__set_image_size(int iObjectID,int width , int height);
VIZENGINE_API int _api__save_image(int iObjectID,const char* location);

VIZENGINE_API bool _api__image_geo_llz2rs(int object_id,
                        double latitude, double longitude, double height, float& x, float& y,float& z);
VIZENGINE_API bool _api__image_geo_rs2llz(int object_id,
                        float x, float y, float z, double& longitude, double& latitude, double& height);
VIZENGINE_API bool _api__image_is_geo_data(int object_id);
VIZENGINE_API bool _api__image_geo_get_bbox(int object_id,
                        float& minx, float& maxx, float& miny, float& maxy);
VIZENGINE_API bool _api__image_geo_viz_custom_cmd(int object_id, long cmd,
                        int index, double& x, double& y, double& lon, double& lat, long& status);

VIZENGINE_API int _api__image_get_georef(int object_id, int *value);
VIZENGINE_API int _api__image_set_georef(int object_id, int value);
VIZENGINE_API int _api__image_create_georef(int object_id);
VIZENGINE_API int _api__image_delete_georef(int object_id);
VIZENGINE_API int _api__get_image_location(int m_iObjectID, char **value);

VIZENGINE_API int _api__image_set_must_update_external(int object_id, bool val );
VIZENGINE_API int _api__image_delete_image(int *object_id );

VIZENGINE_API int _api__image_get_texture_handle(int object_id, int* texture_handle);

// FONT
VIZENGINE_API int _api__get_font_objectid(const char* location);
VIZENGINE_API int _api__font_reload(int iObjectID);
VIZENGINE_API int _api__font_close(int iObjectID);
VIZENGINE_API int _api__get_font_char_name(int iObjectID, int character, const char** name);
VIZENGINE_API int _api__get_font_char_used(int iObjectID, int character, bool* value);
VIZENGINE_API int _api__get_font_char_advance(int iObjectID, int character, float* value);
VIZENGINE_API int _api__get_font_char_width(int iObjectID, int character, float* value);
VIZENGINE_API int _api__get_font_char_height(int iObjectID, int character, float* value);
VIZENGINE_API int _api__get_font_char_kerning(int iObjectID, int character1, int character2, float* value);
VIZENGINE_API int _api__set_font_char_kerning(int iObjectID, int character1, int character2, float value);
VIZENGINE_API int _api__get_font_bounding_box(int object_id,float *llx,float *lly,float *urx,float *ury);
VIZENGINE_API int _api__get_font_geomod(int object_id, int geom_type, int lod, int character, void*& object);

// DYNAMIC IMAGE
VIZENGINE_API int _api__image_set_subScene_scene(int object_id, int val );
VIZENGINE_API int _api__image_set_subScene_scene_by_name(int object_id, const char * chScene );
VIZENGINE_API int _api__image_get_subScene_scene(int object_id, int *val );
VIZENGINE_API int _api__image_get_is_subScene(int object_id );
VIZENGINE_API int _api__image_get_subScene_type(int object_id, int *val );
VIZENGINE_API int _api__image_set_subScene_type(int object_id, int val );
VIZENGINE_API int _api__image_get_subScene_camera_type(int object_id, int *val );
VIZENGINE_API int _api__image_set_subScene_camera_type(int object_id, int val );
VIZENGINE_API int _api__image_set_viewPort_active(int object_id,int iViewId , bool bActive);
VIZENGINE_API int _api__image_set_viewPort_position(int object_id, int iViewId ,int iX,int iY );
VIZENGINE_API int _api__image_set_viewPort_size(int object_id, int iViewId ,int iWidth,int iHeight );
VIZENGINE_API int _api__image_set_viewPort_camera(int object_id, int iViewId ,int iCamera);
VIZENGINE_API int _api__image_set_viewPort_camera_rot_offsets(int object_id, int iViewId,float fPanOffset,float fTiltOffset,float fRollOffset);
VIZENGINE_API int _api__image_set_viewPort_camera_pos_offsets(int object_id, int iViewId,float fXMove,float fYMove ,float fZMove);
VIZENGINE_API int _api__image_set_viewPort_camera_center_offsets(int object_id, int iViewId,float fXMove,float fYMove );
VIZENGINE_API int _api__image_set_viewPort_camera_full(int object_id, int iViewId ,int iCamera,
                    float fPanOffset,float fTiltOffset,float fRollOffset,float fXMove,float fYMove ,float fZMove);

VIZENGINE_API int  _api__image_set_subScene_render( int object_id);
VIZENGINE_API int  _api__image_set_subScene_size( int object_id,int  x, int  y );
VIZENGINE_API int  _api__image_get_subScene_size( int object_id,int *x, int *y );
VIZENGINE_API int  _api__image_set_Custom_subScene_size(int object_id, int  x, int  y, int  CustomSize_x,  int CustomSize_y );
VIZENGINE_API int  _api__image_get_Custom_subScene_size(int object_id, int *x, int *y, int *CustomSize_x, int *CustomSize_y );
VIZENGINE_API int  _api__image_set_subScene_renderMode(int  object_id,int eMode);
VIZENGINE_API int  _api__image_get_subScene_renderMode( int object_id,int *eMode);
VIZENGINE_API int  _api__image_set_dynamic( int object_id,int eType);
VIZENGINE_API int  _api__image_get_dynamic( int object_id,int *eType);
VIZENGINE_API int  _api__image_set_subScene_camera_offsets(int object_id,float fWidth ,float fheight , float fPosX , float fPosY );
VIZENGINE_API int  _api__image_get_subScene_camera_offsets(int object_id,float *fWidth, float *fheight , float *fPosX , float *fPosY );
VIZENGINE_API int  _api__image_set_subScene_use_camera_offsets(int object_id,int  iVal );
VIZENGINE_API int  _api__image_get_subScene_use_camera_offsets(int object_id,int  *iVal );
VIZENGINE_API int  _api__image_set_pre_callback(int object_id,void* p , void * preData);
VIZENGINE_API int  _api__image_set_post_callback(int object_id,void* p , void * preData);
//VIZENGINE_API int  _api__image_set_multi_camera_data(int objectID,float fPanOffset,float fTiltOffset,float fXMove,float fYMove);
VIZENGINE_API int  _api__image_set_subScene_camera_id(int object_id,int val );
VIZENGINE_API int  _api__image_get_subScene_camera_id(int object_id,int *val );

// VIEWPORT_TILE
VIZENGINE_API int _api__set_viewport_tile_scene(int object_id, int val);
VIZENGINE_API int _api__set_viewport_tile_scene_by_name(int object_id, const char * pszScene);
VIZENGINE_API int _api__get_viewport_tile_scene(int object_id, int *val);
VIZENGINE_API int _api__set_viewport_tile_camera_id(int object_id, int val);
VIZENGINE_API int _api__get_viewport_tile_camera_id(int object_id, int *val);
VIZENGINE_API int _api__set_viewport_tile_scene_type(int object_id, int val);
VIZENGINE_API int _api__get_viewport_tile_scene_type(int object_id, int *val);
VIZENGINE_API int _api__set_viewport_tile_camera_offsets(int object_id, float fWidth, float fHeight, float fPosX, float fPosY);
VIZENGINE_API int _api__get_viewport_tile_camera_offsets(int object_id, float *fWidth, float *fHeight, float *fPosX, float *fPosY);
VIZENGINE_API int _api__set_viewport_tile_use_camera_offsets(int object_id, int val);
VIZENGINE_API int _api__get_viewport_tile_use_camera_offsets(int object_id, int *val);

// TEXTURE_RENDERER
VIZENGINE_API int _api__texture_renderer_reset();
VIZENGINE_API int _api__texture_renderer_get_current_camera_offsets(float *fCropX , float *fCropY ,float *fOffsetX , float *fOffsetY);
VIZENGINE_API int _api__texture_renderer_get_current_keep_aspect(bool * value);
VIZENGINE_API int _api__texture_renderer_get_render_size(int *x , int *y);

// ALPHA
VIZENGINE_API int _api__set_alpha(int iObjectID, float value);
VIZENGINE_API int _api__get_alpha(int iObjectID, float *value);

// KEY
VIZENGINE_API int _api__set_key_use_rgb(int iObjectID, int value);
VIZENGINE_API int _api__get_key_use_rgb(int iObjectID, int *value);
VIZENGINE_API int _api__set_key_use_key(int iObjectID, int value);
VIZENGINE_API int _api__get_key_use_key(int iObjectID, int *value);
VIZENGINE_API int _api__set_key_automatic_alpha(int iObjectID, int value);
VIZENGINE_API int _api__get_key_automatic_alpha(int iObjectID, int *value);
VIZENGINE_API int _api__set_key_alpha(int iObjectID, float value);
VIZENGINE_API int _api__get_key_alpha(int iObjectID, float *value);

// MATERIAL
VIZENGINE_API int _api__set_material_enlighted(int iObjectID, int value);
VIZENGINE_API int _api__get_material_enlighted(int iObjectID, int *value);
VIZENGINE_API int _api__set_material_color(int iObjectID, unsigned long value);
VIZENGINE_API int _api__get_material_color(int iObjectID, unsigned long *value);
VIZENGINE_API int _api__set_material_ambient(int iObjectID, unsigned long value);
VIZENGINE_API int _api__get_material_ambient(int iObjectID, unsigned long *value);
VIZENGINE_API int _api__set_material_diffuse(int iObjectID, unsigned long value);
VIZENGINE_API int _api__get_material_diffuse(int iObjectID, unsigned long *value);
VIZENGINE_API int _api__set_material_specular(int iObjectID, unsigned long value);
VIZENGINE_API int _api__get_material_specular(int iObjectID, unsigned long *value);
VIZENGINE_API int _api__set_material_emission(int iObjectID, unsigned long value);
VIZENGINE_API int _api__get_material_emission(int iObjectID, unsigned long *value);
VIZENGINE_API int _api__set_material_alpha(int iObjectID, float value);
VIZENGINE_API int _api__get_material_alpha(int iObjectID, float *value);
VIZENGINE_API int _api__set_material_shininess(int iObjectID, float value);
VIZENGINE_API int _api__get_material_shininess(int iObjectID, float *value);

// TEXTURE
VIZENGINE_API int _api__get_texture_active(int iObjectID, int *value);
VIZENGINE_API int _api__set_texture_active(int iObjectID, int value);
VIZENGINE_API int _api__get_texture_map_type(int iObjectID, int *value);
VIZENGINE_API int _api__set_texture_map_type(int iObjectID, int value);
VIZENGINE_API int _api__get_texture_env_type(int iObjectID, int *value);
VIZENGINE_API int _api__set_texture_env_type(int iObjectID, int value);
VIZENGINE_API int _api__get_texture_qual_type(int iObjectID, int *value);
VIZENGINE_API int _api__set_texture_qual_type(int iObjectID, int value);
VIZENGINE_API int _api__get_texture_effect_type(int iObjectID, int *value);
VIZENGINE_API int _api__set_texture_effect_type(int iObjectID, int value);
VIZENGINE_API int _api__get_texture_wrap_type(int iObjectID, int *value);
VIZENGINE_API int _api__set_texture_wrap_type(int iObjectID, int value);


VIZENGINE_API int _api__get_texture_map_pos_x(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_pos_x(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_pos_y(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_pos_y(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_pos(int iObjectID, float* pVertex);
VIZENGINE_API int _api__set_texture_map_pos(int iObjectID, float* pVertex);

VIZENGINE_API int _api__get_texture_map_center_x(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_center_x(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_center_y(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_center_y(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_center(int iObjectID, float* pVertex);
VIZENGINE_API int _api__set_texture_map_center(int iObjectID, float* pVertex);

VIZENGINE_API int _api__get_texture_map_rot_x(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_rot_x(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_rot_y(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_rot_y(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_rot_z(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_rot_z(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_rot(int iObjectID, float* pVertex);
VIZENGINE_API int _api__set_texture_map_rot(int iObjectID, float* pVertex);

VIZENGINE_API int _api__get_texture_map_scale_x(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_scale_x(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_scale_y(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_map_scale_y(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_map_scale(int iObjectID, float* pVertex);
VIZENGINE_API int _api__set_texture_map_scale(int iObjectID, float* pVertex);
VIZENGINE_API int _api__get_texture_map_matrix(int iObjectID, float* value);

VIZENGINE_API int _api__get_texture_blend_value(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_blend_value(int iObjectID, float value);

VIZENGINE_API int _api__get_texture_effect_value(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_effect_value(int iObjectID, float value);
VIZENGINE_API int _api__get_texture_sharpen_value(int iObjectID, float *value);
VIZENGINE_API int _api__set_texture_sharpen_value(int iObjectID, float value);

VIZENGINE_API int _api__get_texture_image_width(int iObjectID, int *value);
VIZENGINE_API int _api__get_texture_image_height(int iObjectID, int *value);
VIZENGINE_API int _api__set_texture_image_size(int iObjectID, int width, int height);
VIZENGINE_API int _api__set_texture_image_from_location(int iObjectID, const char* location);
VIZENGINE_API int _api__set_texture_image_from_image(int iObjectID, int image_object_id);
VIZENGINE_API int _api__get_texture_image(int iObjectID, int *value);
VIZENGINE_API int _api__set_texture_image2_from_location(int iObjectID, const char* location);
VIZENGINE_API int _api__set_texture_image2_from_image(int iObjectID, int image_object_id);
VIZENGINE_API int _api__get_texture_image2(int iObjectID, int *value);
VIZENGINE_API int _api__draw_texture(int iObjectID,float cur_texcoord_scale, float load_bias_s, float load_bias_t);
VIZENGINE_API int _api__texture_create_texture(int* pTextureId, int imageID);
VIZENGINE_API int _api__texture_delete_texture(int* pTextureId);

VIZENGINE_API int _api__texture_set_compression(int object_id, int val);
VIZENGINE_API int _api__texture_get_compression(int object_id, int* val);

VIZENGINE_API int _api__texture_get_optimize(int iObjectID, int *optimize);
VIZENGINE_API int _api__texture_set_optimize(int iObjectID, int optimize);

VIZENGINE_API int _api__get_texture_texture_handle(int iObjectID, int *texture_handle);
VIZENGINE_API int _api__get_free_texture_unit(int iObjectID, int *value);
VIZENGINE_API int _api__texture_apply_image_ex_transformation(int iObjectID, float *fScl, float *fRot, float *fPos);

VIZENGINE_API int _api__texture_set_force_no_mipmaps(int object_id, int val);
VIZENGINE_API int _api__texture_get_force_no_mipmaps(int object_id, int* val);

VIZENGINE_API int _api__texture_get_anisotropy(int object_id, float* anisotropy);
VIZENGINE_API int _api__texture_set_anisotropy(int object_id, float anisotropy);

VIZENGINE_API int _api__texture_get_display_component( int object_id, int* type );
VIZENGINE_API int _api__texture_set_display_component( int object_id, int type );

VIZENGINE_API int _api__texture_get_constant_color( int object_id, float* red, float* green, float* blue, float* alpha );
VIZENGINE_API int _api__texture_set_constant_color( int object_id, float red, float green, float blue, float alpha );

// CAMERA
VIZENGINE_API int _api__get_camera_view(int iObjectID, int* value);
VIZENGINE_API int _api__set_camera_view(int iObjectID, int value);
VIZENGINE_API int _api__get_camera_position(int iObjectID, int* value);
VIZENGINE_API int _api__get_camera_position_vector(int iObjectID, float* v);
VIZENGINE_API int _api__get_camera_position_ext(int iObjectID, int* value);
VIZENGINE_API int _api__get_camera_position_ext_vector(int iObjectID, float* v);
VIZENGINE_API int _api__set_camera_position(int iObjectID, int value);
VIZENGINE_API int _api__set_camera_position_vector(int iObjectID, float* v);
VIZENGINE_API int _api__get_camera_direction(int iObjectID, int* value);
VIZENGINE_API int _api__get_camera_direction_vector(int iObjectID, float* v);
VIZENGINE_API int _api__set_camera_direction(int iObjectID, int value);
VIZENGINE_API int _api__set_camera_direction_vector(int iObjectID, float* v);
VIZENGINE_API int _api__get_camera_pan(int iObjectID, float *value);
VIZENGINE_API int _api__get_camera_pan_ext(int iObjectID, float *value);
VIZENGINE_API int _api__set_camera_pan(int iObjectID, float value);
VIZENGINE_API int _api__get_camera_tilt(int iObjectID, float *value);
VIZENGINE_API int _api__get_camera_tilt_ext(int iObjectID, float *value);
VIZENGINE_API int _api__set_camera_tilt(int iObjectID, float value);
VIZENGINE_API int _api__get_camera_twist(int iObjectID, float *value);
VIZENGINE_API int _api__get_camera_twist_ext(int iObjectID, float *value);
VIZENGINE_API int _api__set_camera_twist(int iObjectID, float value);
VIZENGINE_API int _api__get_camera_fovx(int iObjectID, float *value);
VIZENGINE_API int _api__get_camera_fovx_ext(int iObjectID, float *value);
VIZENGINE_API int _api__set_camera_fovx(int iObjectID, float value);
VIZENGINE_API int _api__get_camera_fovy(int iObjectID, float *value);
VIZENGINE_API int _api__get_camera_fovy_ext(int iObjectID, float *value);
VIZENGINE_API int _api__set_camera_fovy(int iObjectID, float value);
VIZENGINE_API int _api__get_camera_cx(int iObjectID, float *value);
VIZENGINE_API int _api__get_camera_cx_ext(int iObjectID, float *value);
VIZENGINE_API int _api__set_camera_cx(int iObjectID, float value);
VIZENGINE_API int _api__get_camera_cy(int iObjectID, float *value);
VIZENGINE_API int _api__get_camera_cy_ext(int iObjectID, float *value);
VIZENGINE_API int _api__set_camera_cy(int iObjectID, float value);
VIZENGINE_API int _api__get_camera_decouple_external(int iObjectID, bool *value);
VIZENGINE_API int _api__set_camera_decouple_external(int iObjectID, bool value);
VIZENGINE_API int _api__get_camera_external_active(int iObjectID, bool *value);
VIZENGINE_API int _api__set_camera_external_active(int iObjectID, bool value);
VIZENGINE_API int _api__get_camera_pos_tracking(int iObjectID, int* value);
VIZENGINE_API int _api__set_camera_pos_tracking(int iObjectID, int value);
VIZENGINE_API int _api__get_camera_rot_tracking(int iObjectID, int* value);
VIZENGINE_API int _api__set_camera_rot_tracking(int iObjectID, int value);
VIZENGINE_API int _api__get_camera_pos_tracking_active(int iObjectID, int* value);
VIZENGINE_API int _api__set_camera_pos_tracking_active(int iObjectID, int value);
VIZENGINE_API int _api__set_camera_pos_tracking_reset(int iObjectID);
VIZENGINE_API int _api__get_camera_rot_tracking_active(int iObjectID, int* value);
VIZENGINE_API int _api__set_camera_rot_tracking_active(int iObjectID, int value);
VIZENGINE_API int _api__set_camera_rot_tracking_reset(int iObjectID);
VIZENGINE_API int _api__set_camera_focal_plane(int iObjectID, float value);
VIZENGINE_API int _api__get_camera_focal_plane(int iObjectID, float *value);
VIZENGINE_API int _api__get_camera_matrix(int iObjectID, float* value);
VIZENGINE_API int _api__get_camera_view_matrix(int iObjectID, float* value);
VIZENGINE_API int _api__set_camera_view_matrix(int object_id, float* value);
VIZENGINE_API int _api__get_camera_projection_matrix(int iObjectID, float* value);
VIZENGINE_API int _api__set_camera_frustum(int object_id, float l, float r, float b, float t);
VIZENGINE_API int _api__get_camera_frustum(int object_id, float* l, float* r, float* b, float* t);
VIZENGINE_API int _api__get_camera_frustum_type(int object_id, int* frustumType);
VIZENGINE_API int _api__get_camera_frustum_normalized(int object_id, float* leftNormalized, float* rightNormalized, float* topNormalized, float* bottomNormalized, int* frustumType);
VIZENGINE_API int _api__camera_enable_recompute_matrices(int object_id, bool b);
VIZENGINE_API int _api__camera_recompute_matrices_now(int object_id);
VIZENGINE_API int _api__camera_set_local_clipping(int iObjectID, bool bLocal);
VIZENGINE_API int _api__camera_get_local_clipping(int iObjectID, bool * bLocal);
VIZENGINE_API int _api__camera_set_near(int iObjectID, float near);
VIZENGINE_API int _api__camera_get_near(int iObjectID, float * near);
VIZENGINE_API int _api__camera_set_far(int iObjectID, float far);
VIZENGINE_API int _api__camera_get_far(int iObjectID, float * far);
VIZENGINE_API int _api__camera_set_frustum_offsets(int iObjectID,bool bUseFrustumOffsets, float fXSize , float fYSize, float fXOffset,float fYOffset);
VIZENGINE_API int _api__camera_get_frustum_offsets(int iObjectID, bool *bUseFrustumOffsets, float *fXSize , float *fYSize, float *fXOffset,float *fYOffset);
VIZENGINE_API int _api__camera_set_distortion_factor(int iObjectID, float factor);
VIZENGINE_API int _api__camera_get_distortion_factor(int iObjectID, float *factor);



// LIGHT
VIZENGINE_API int _api__get_light_active(int iObjectID, int* value);
VIZENGINE_API int _api__set_light_active(int iObjectID, int value);
VIZENGINE_API int _api__get_light_type(int iObjectID, int* value);
VIZENGINE_API int _api__set_light_type(int iObjectID, int value);
VIZENGINE_API int _api__get_light_position(int iObjectID, int* value);
VIZENGINE_API int _api__get_light_position_vector(int iObjectID, float* v);
VIZENGINE_API int _api__set_light_position(int iObjectID, int value);
VIZENGINE_API int _api__set_light_position_vector(int iObjectID, float* v);
VIZENGINE_API int _api__get_light_rotation(int iObjectID, int* value);
VIZENGINE_API int _api__get_light_rotation_vector(int iObjectID, float* v);
VIZENGINE_API int _api__set_light_rotation(int iObjectID, int value);
VIZENGINE_API int _api__set_light_rotation_vector(int iObjectID, float* v);
VIZENGINE_API int _api__get_light_attenuation(int iObjectID, float *value);
VIZENGINE_API int _api__set_light_attenuation(int iObjectID, float value);
VIZENGINE_API int _api__get_light_color(int iObjectID, int* value);
VIZENGINE_API int _api__get_light_color_value(int iObjectID, unsigned int* value);
VIZENGINE_API int _api__set_light_color(int iObjectID, int value);
VIZENGINE_API int _api__set_light_color_value(int iObjectID, unsigned int value);
VIZENGINE_API int _api__get_light_pos_tracking(int iObjectID, int* value);
VIZENGINE_API int _api__set_light_pos_tracking(int iObjectID, int value);
VIZENGINE_API int _api__get_light_rot_tracking(int iObjectID, int* value);
VIZENGINE_API int _api__set_light_rot_tracking(int iObjectID, int value);
VIZENGINE_API int _api__get_light_pos_tracking_active(int iObjectID, int* value);
VIZENGINE_API int _api__set_light_pos_tracking_active(int iObjectID, int value);
VIZENGINE_API int _api__set_light_pos_tracking_reset(int iObjectID);
VIZENGINE_API int _api__get_light_rot_tracking_active(int iObjectID, int* value);
VIZENGINE_API int _api__set_light_rot_tracking_active(int iObjectID, int value);
VIZENGINE_API int _api__set_light_rot_tracking_reset(int iObjectID);

// SCENE
VIZENGINE_API int _api__get_scene_background_color(int iObjectID, int* value);
VIZENGINE_API int _api__set_scene_background_color_value(int iObjectID, unsigned int color);
VIZENGINE_API int _api__set_scene_background_color(int iObjectID, int value);
VIZENGINE_API int _api__get_scene_background_color_value(int iObjectID, unsigned int* color);

VIZENGINE_API int _api__get_scene_background_image(int iObjectID, int* pTextureID);
VIZENGINE_API int _api__set_scene_background_image(int iObjectID, int textureID);
VIZENGINE_API int _api__get_scene_background_image_active(int iObjectID, bool* value);
VIZENGINE_API int _api__set_scene_background_image_active(int iObjectID, bool value);

VIZENGINE_API int _api__get_scene_alpha_clear_value(int iObjectID, int* value);
VIZENGINE_API int _api__set_scene_alpha_clear_value(int iObjectID, int value);
VIZENGINE_API int _api__get_scene_video_format(int iObjectID, int video, int* value);
VIZENGINE_API int _api__set_scene_video_format(int iObjectID, int video, int value);
__declspec(deprecated(" this is a deprecated function"))
VIZENGINE_API int _api__get_scene_video_download(int iObjectID, int video, int* value);
__declspec(deprecated(" this is a deprecated function"))
VIZENGINE_API int _api__set_scene_video_download(int iObjectID, int video, int value);
VIZENGINE_API int _api__get_scene_current_camera(int iObjectID, int* value);
VIZENGINE_API int _api__set_scene_current_camera(int iObjectID, int value);
VIZENGINE_API int _api__get_scene_current_selflayer_camera(int iObjectID, int* value, int layer);
VIZENGINE_API int _api__set_scene_current_selflayer_camera(int iObjectID, int value, int layer);
VIZENGINE_API int _api__get_scene_current_viewing_camera(int iObjectID, int* pCameraId);
VIZENGINE_API int _api__scene_redraw();
VIZENGINE_API int _api__get_scene_function(int iObjectID, int* value, char* function_name);
VIZENGINE_API int _api__get_scene_plugin_instance(int iObjectID, int* piPluginID, const char* pszPluginName);
VIZENGINE_API int _api__set_scene_auto_key_active(bool value);
VIZENGINE_API int _api__get_scene_auto_key_active(bool* value);
VIZENGINE_API int _api__set_scene_auto_key_position(float x, float y, float z);
VIZENGINE_API int _api__get_scene_auto_key_position(float* x, float* y, float* z);
VIZENGINE_API int _api__scene_has_root (int iObjectID);
VIZENGINE_API int _api__scene_create_root (int iObjectID);
VIZENGINE_API int _api__scene_get_root (int iObjectID, int &container_id);
VIZENGINE_API int _api__scene_get_container (int object_id, const char * name ,int &container_id);
VIZENGINE_API int _api__scene_get_name (int object_id, const char** name);

VIZENGINE_API int _api__scene_get_stage(int iObjectID, int* pStageID);
VIZENGINE_API int _api__scene_find_container_by_name(int sceneId, const char* name);
VIZENGINE_API int _api__scene_create_function(int iObjectID, const char* value);
VIZENGINE_API int _api__scene_delete_function(int iObjectID, const char* value);

VIZENGINE_API int _api__scene_s2v_get_index(int iObjectID, int *index);
VIZENGINE_API int _api__scene_s2v_set_index(int iObjectID, const int index);
VIZENGINE_API int _api__scene_s2v_get_rot(int iObjectID, const int index, float *rot);
VIZENGINE_API int _api__scene_s2v_set_rot(int iObjectID, const int index, float rot);
VIZENGINE_API int _api__scene_s2v_get_pos(int iObjectID, const int index, float *x, float *y, float *z);
VIZENGINE_API int _api__scene_s2v_set_pos(int iObjectID, const int index, float x, float y, float z);
VIZENGINE_API int _api__scene_s2v_get_name(int iObjectID, const int index, const char **name);
VIZENGINE_API int _api__scene_s2v_set_name(int iObjectID, const int index, const char *name);

VIZENGINE_API int _api__scene_set_culling(int iObjectID, bool value);
VIZENGINE_API int _api__scene_get_culling(int iObjectID, bool *value);
VIZENGINE_API int _api__scene_set_zsort(int iObjectID, int transp_mode, int opaque_mode);
VIZENGINE_API int _api__scene_get_zsort(int iObjectID, int *transp_mode, int *opaque_mode);

VIZENGINE_API int _api__scene_set_sort_priority_list(int iObjectID, int *plist);
VIZENGINE_API int _api__scene_get_sort_priority_list(int iObjectID, int *plist);

VIZENGINE_API int _api__scene_set_depth_buffer_state(int iObjectID, bool value);
VIZENGINE_API int _api__scene_get_depth_buffer_state(int iObjectID, bool *value);

VIZENGINE_API int _api__scene_set_edited_container(int object_id, int value);
VIZENGINE_API int _api__scene_get_edited_container(int object_id, int *value);

VIZENGINE_API int _api__scene_get_video_channel(int iObjectID, int* channel, int iChannelID);
VIZENGINE_API int _api__scene_get_gfx_channel(int iObjectID, int* channel, int index);
VIZENGINE_API int _api__scene_get_image_channel(int iObjectID, int* channel, int index);
VIZENGINE_API int _api__scene_get_super_channel(int iObjectID, int* channel, int index);

VIZENGINE_API int _api__scene_get_active_gfx_channels(int iObjectID, int** indices);

VIZENGINE_API int _api__scene_get_script_plugin_instance(int iObjectID, int* piPluginID);

VIZENGINE_API int _api__scene_deform_screen_pos(int iObjectID, float &fX, float &fY);
VIZENGINE_API int _api__scene_undeform_screen_pos(int iObjectID, float &fX, float &fY);

VIZENGINE_API int _api__scene_screen_pos_to_world_pos(int iObjectID, float fX, float fY, evVertex3D &v3dPos);
VIZENGINE_API int _api__scene_screen_pos_to_world_grid(int iObjectID, float fX, float fY, evVertex3D &v3dPos);
VIZENGINE_API int _api__scene_world_pos_to_screen_pos(int iObjectID, evVertex3D v3dPos, float &fX, float &fY);


// PLUGIN_PARAMETER
VIZENGINE_API int _api__set_plugin_parameter(const char* pszPluginName, const char* pszFieldName, int* piDataType, int* piOffset, int* piMax, int* piMin);
VIZENGINE_API int _api__set_plugin_parameter_2(const char* pszPluginName, const char* pszFieldName, int* piDataType, int* piOffset,
                                 int* piMax, int* piMin,int* iId, bool *bNotify );
VIZENGINE_API int _api__set_plugin_parameter_script(int iObjectID, const char* pszFieldName, int* piDataType, int* piOffset,
                                 int* piMax, int* piMin,int* iId, bool *bNotify );
VIZENGINE_API int _api__print_plugin_parameter_all();
VIZENGINE_API int _api__print_plugin_parameter(const char* pszPluginName);


// PLUGIN_INSTANCE
VIZENGINE_API int _api__plugin_instance_local();
VIZENGINE_API int _api__plugin_instance_MTRegister(int iObjectID, int stroke, int controlType);
VIZENGINE_API int _api__plugin_instance_MTRegisterEx(int iObjectID, int stroke, int controlType, void * /*THeapArray<float>*/ params);
VIZENGINE_API int _api__plugin_instance_MTUnregister(int iObjectID);
VIZENGINE_API int _api__plugin_instance_MTIsRegistered(int iObjectID, bool *registered);
VIZENGINE_API int _api__plugin_instance_MTSetPosition(int iObjectID, int x, int y);
VIZENGINE_API int _api__plugin_instance_MTUseCenter(int iObjectID, bool flag);
VIZENGINE_API int _api__plugin_instance_MTUseCenterGet(int iObjectID, bool *pFlag);
VIZENGINE_API int _api__plugin_instance_MTObjectPlane(int iObjectID, int iPlane);
VIZENGINE_API int _api__plugin_instance_MTObjectPlaneGet(int iObjectID, int &iPlane);
VIZENGINE_API int _api__plugin_instance_MTGridGet(int iObjectID, int *pGridId);
VIZENGINE_API int _api__plugin_instance_MTGridSet(int iObjectID, int gridId);
VIZENGINE_API int _api__plugin_instance_MTAlignGrid(int iObjectID, bool flag);
VIZENGINE_API int _api__plugin_instance_MTAlignGridGet(int iObjectID, bool *pFlag);
VIZENGINE_API int _api__plugin_instance_MTDOFEventDistribution(int iObjectID, bool flag);
VIZENGINE_API int _api__plugin_instance_MTDOFEventDistributionGet(int iObjectID, bool *pFlag);
VIZENGINE_API int _api__plugin_instance_MTHasMomentum(int iObjectID, bool *pFlag);
VIZENGINE_API int _api__plugin_instance_MTTouched(int iObjectID, bool *pFlag);
VIZENGINE_API int _api__plugin_instance_get_trace_count(int iObjectID, unsigned int &iCount);
VIZENGINE_API int _api__plugin_instance_HitContainer(int iObjectID, int& iContainerObjectID);
VIZENGINE_API int _api__plugin_instance_DOFEventDistribution(int iObjectID, bool flag);
VIZENGINE_API int _api__plugin_instance_DOFEventDistributionGet(int iObjectID, bool *pFlag);
VIZENGINE_API int _api__get_plugin_instance_name(int iObjectID, const char** pluginName);
VIZENGINE_API int _api__plugin_instance_is_geometry(int iObjectID, bool *pVal);
VIZENGINE_API int _api__plugin_instance_is_function(int iObjectID, bool *pVal);
VIZENGINE_API int _api__plugin_instance_is_script(int iObjectID, bool *pVal);
VIZENGINE_API int _api__plugin_instance_set_is_pickable(int iObjectID, bool bVal);
VIZENGINE_API int _api__plugin_instance_is_set_pickable(int iObjectID, bool *pVal);


// GEOMETRY_MODIFIER
VIZENGINE_API void _api__geomod_init(void* object);
VIZENGINE_API void _api__geomod_get_info(void* object, int& numVertices, int& numMeshes, bool& hasNormals, bool& hasTexCoords, bool& hasColors);
VIZENGINE_API void _api__geomod_goto_mesh(void* object, int nmesh, float*& meshPtr);
VIZENGINE_API void _api__geomod_next_mesh(void* object, float*& meshPtr);
VIZENGINE_API void _api__geomod_get_mesh_type(void* object, float* meshPtr, int& meshType);
VIZENGINE_API void _api__geomod_get_num_mesh_verices(void* object, float* meshPtr, int& numVertices);
VIZENGINE_API void _api__geomod_goto_vertex(void* object, float* meshPtr, int nvertex, float*& vertexPtr);
VIZENGINE_API void _api__geomod_next_vertex(void* object, float* meshPtr, float*& vertexPtr);
VIZENGINE_API void _api__geomod_get_vertex(void* object, float* vertexPtr, float& x, float& y, float& z);
VIZENGINE_API void _api__geomod_get_vertices(void* object, float* vertexPtr, int numVertices, float* vertices);
VIZENGINE_API void _api__geomod_set_vertex(void* object, float* vertexPtr, float x, float y, float z);
VIZENGINE_API void _api__geomod_set_vertices(void* object, float* vertexPtr, int numVertices, float* vertices);
VIZENGINE_API void _api__geomod_get_normal(void* object, float* vertexPtr, float& x, float& y, float& z);
VIZENGINE_API void _api__geomod_get_normals(void* object, float* vertexPtr, int numNormals, float* normals);
VIZENGINE_API void _api__geomod_set_normal(void* object, float* vertexPtr, float x, float y, float z);
VIZENGINE_API void _api__geomod_set_normals(void* object, float* vertexPtr, int numNormals, float* normals);
VIZENGINE_API void _api__geomod_get_tex_coord(void* object, float* vertexPtr, float& s, float& t);
VIZENGINE_API void _api__geomod_get_tex_coords(void* object, float* vertexPtr, int numTexCoords, float* texCoords);
VIZENGINE_API void _api__geomod_set_tex_coord(void* object, float* vertexPtr, float s, float t);
VIZENGINE_API void _api__geomod_set_tex_coords(void* object, float* vertexPtr, int numTexCoords, float* texCoords);;
VIZENGINE_API void _api__geomod_get_color(void* object, float* vertexPtr, unsigned long int& color);
VIZENGINE_API void _api__geomod_get_colors(void* object, float* vertexPtr, int numColors, unsigned long int* colors);
VIZENGINE_API void _api__geomod_set_color(void* object, float* vertexPtr, unsigned long int color);
VIZENGINE_API void _api__geomod_set_colors(void* object, float* vertexPtr, int numColors, unsigned long int* colors);

// GEOMETRY
VIZENGINE_API int _api__geometry_get_name(int iObjectID, const char **value);
VIZENGINE_API int _api__set_geom_params(int iObjectID, int data_type, char* name, int offset, void* data, int max, int min);
VIZENGINE_API int _api__set_geom_params_2(int iObjectID, int iDataType, char* name, int offset, void* data, int iMax, int iMin,int iId, bool bNotify);
VIZENGINE_API int _api__get_geom_params(int iObjectID, int data_type, char* name, int offset, void* data);
VIZENGINE_API int _api__set_geom_params_plugin(GEOMETRY* geom, int data_type, char* name, int offset, void* data, int max, int min,int iId, bool bNotify);
VIZENGINE_API int _api__get_geom_params_plugin(GEOMETRY* geom, int data_type, char* name, int offset, void* data);
VIZENGINE_API int _api__get_geom_params_text (int iObjectID, int index, int offset, void* data , int mode =0 );
VIZENGINE_API int _api__set_geom_params_text (int iObjectID, int index, int offset, void* data , int mode =0 );
VIZENGINE_API int _api__convert_geom_params_text(int iObjectID, char * source, unsigned char  *dest);
VIZENGINE_API int _api__get_geom_type_id(int iObjectID, int *type_id);
VIZENGINE_API int _api__get_geom_type(int iObjectID, char **type);
VIZENGINE_API int _api__set_geom_changed(int iObjectID);
VIZENGINE_API int _api__rebuild_geom(int iObjectID);
VIZENGINE_API int _api__set_geom_texcoord_scale(int iObjectID, float scale);
VIZENGINE_API int _api__get_geom_texcoord_scale(int iObjectID, float *scale);
VIZENGINE_API int _api__geom_build_new(int iObjectID);
VIZENGINE_API int _api__geom_done(int iObjectID);

VIZENGINE_API int _api__geom_data_read_init (int iObjectID, int type, int lod, int &no_vertices, bool &has_normals, bool &has_texc, bool &has_color);
VIZENGINE_API int _api__geom_data_read_next_mesh (int iObjectID, int &meshtype, int &no_vertices_in_mesh);
VIZENGINE_API int _api__geom_data_read_next_vertex (int iObjectID);
VIZENGINE_API int _api__geom_data_read_get_vertex (int iObjectID, float &x, float &y, float &z);
VIZENGINE_API int _api__geom_data_read_get_normals (int iObjectID, float &x, float &y, float &z);
VIZENGINE_API int _api__geom_data_read_get_texc (int iObjectID, float &s, float &t);
VIZENGINE_API int _api__geom_data_read_get_color (int iObjectID, unsigned long int &color);
VIZENGINE_API int _api__geom_data_read_end (int iObjectID);
VIZENGINE_API int _api__set_geom_detail_or_fontstyle(int object_id, int value);
VIZENGINE_API int _api__get_geom_detail(int object_id, int *value);
VIZENGINE_API int _api__geometry_get_build_count(int object_id, int * build_count);
VIZENGINE_API int _api__geom_dispatcher(int object_id, ULONG_PTR msg, ULONG_PTR param, ULONG_PTR & ret);
VIZENGINE_API int _api__get_geom_geomod(int object_id, int geom_type, int lod, void*& object);
VIZENGINE_API int _api_get_geom_bounding_box(int iObjectID, float* lbb_x, float* lbb_y, float* lbb_z, float* rtf_x, float* rtf_y, float* rtf_z);

VIZENGINE_API bool _api__geometry_register_text_changed_callback(int objectId);
VIZENGINE_API bool _api__geometry_register_changed_callback(int objectId);
VIZENGINE_API bool _api__geometry_unregister_changed_callback(int objectId);

// FUNCTION
VIZENGINE_API int _api__set_function_params(int iObjectID, int data_type, char* name, int offset, void* data, int max, int min);
VIZENGINE_API int _api__set_function_params_2(int iObjectID, int iDataType, char* name, int offset, void* data, int iMax, int iMin,int iId, bool bNotify);
VIZENGINE_API int _api__get_function_params(int iObjectID, int data_type, char* name, int offset, void* data);
VIZENGINE_API int _api__get_function_dataptr(int iObjectID, void** ptr);
VIZENGINE_API int _api__get_function_type(int iObjectID, char **type);
VIZENGINE_API int _api__function_dispatcher(int object_id, ULONG_PTR msg, ULONG_PTR param, ULONG_PTR & ret);
VIZENGINE_API int _api__function_set_active(int iObjectID, bool active);
VIZENGINE_API int _api__function_get_active(int iObjectID, bool& active);

// SCRIPT AND SCRIPTFUNCTION API for PluginLib
VIZENGINE_API int _api__get_local_script();
VIZENGINE_API int _api__scene_get_script_object(int iSceneID, int* id);
VIZENGINE_API int _api__container_get_script_object(int containerId, int* id);
VIZENGINE_API int _api__script_run_script(int iScriptID);
VIZENGINE_API bool _api__script_compile_script(int iScriptID, bool bCallOnInit=false);
VIZENGINE_API int _api__script_get_scriptfunction(int iScriptID, const char* functionName, const char* typeString);
VIZENGINE_API int _api__script_invoke_scriptfunction(int iScriptID, const char* functionName, const char* typeString, void* /*THeapArray<const char*>*/ argVectorChar, const char ** retValue);
//_api__script_invoke_scriptfunction(...): The maximum size of each argument returned by a script is limited to 32768 bytes

// SCRIPT_PLUGIN
VIZENGINE_API int _api__set_script_plugin_params(int iObjectID, const char* pszFieldName, void* data, bool bNotify);
VIZENGINE_API int _api__get_script_plugin_params(int iObjectID, const char* pszFieldName, void* data);

// GUI_COMMANDS
VIZENGINE_API int _api__gui_tree_editor_update();
VIZENGINE_API int _api__gui_container_editor_update(int iObjectID);
VIZENGINE_API int _api__gui_container_editor_recompute(int iObjectID);
VIZENGINE_API int _api__gui_container_set_open(int iObjectID, bool value);
VIZENGINE_API int _api__gui_container_get_open(int iObjectID, bool* value);
VIZENGINE_API int _api__gui_send_error_msg(const char* pszMsg);
VIZENGINE_API int _api__gui_send_info_msg(const char* pszMsg);
VIZENGINE_API int _api__gui_send_command(const char* command);
VIZENGINE_API int _api__gui_send_command_rebuild_controllist();
VIZENGINE_API int _api__gui_show_working_dialog(const char* pszMsg);
VIZENGINE_API int _api__gui_close_working_dialog();
VIZENGINE_API int _api__gui_send_window_size(int iWidth, int iHeight);


// VIZ
VIZENGINE_API int _api__everest_get_computer_type();

VIZENGINE_API int _api__viz_get_gpu_device(int & id);
VIZENGINE_API int _api__viz_get_number_of_gpus(int & count);
VIZENGINE_API int _api__viz_get_engine_instance(int & instance);

VIZENGINE_API int _api__viz_get_is_on_air(bool* value);
VIZENGINE_API int _api__everest_get_is_nle(bool* value);
VIZENGINE_API int _api__viz_get_is_post_recording(bool* value);
VIZENGINE_API int _api__viz_get_audio_mix_post(int samples, int channels, int buffer_size, char * buffer);
VIZENGINE_API int _api__viz_get_post_supports_audio(bool* value);
VIZENGINE_API int _api__viz_get_post_current_time(float* value);
VIZENGINE_API int _api__viz_send_command(const char* command, const char** answer);
VIZENGINE_API int _api__viz_send_answer(const char* msg);
VIZENGINE_API int _api__viz_send_error(const char* msg);
VIZENGINE_API int _api__viz_get_sysid(const char** value);
VIZENGINE_API int _api__viz_get_renderer_id(int &value);
VIZENGINE_API int _api__viz_get_refreshrate(double *value);
VIZENGINE_API int _api__viz_get_config_refreshrate(double *value);
VIZENGINE_API int _api__viz_get_retrace_counter_64(uint64_t *value);
VIZENGINE_API int _api__viz_get_videoout_retrace_counter_64 (uint64_t *value);
VIZENGINE_API int _api__viz_get_videoout_output_retrace_counter_64 (uint64_t *value);
VIZENGINE_API int _api__viz_get_videoout_input_retrace_counter_64 (uint64_t *value);

//Deprecated, replaced by ..._64 but remain for compatibility reasons
VIZENGINE_API int _api__viz_get_retrace_counter(unsigned long *value);
VIZENGINE_API int _api__viz_get_videoout_retrace_counter (unsigned long *value);
VIZENGINE_API int _api__viz_get_videoout_output_retrace_counter (unsigned long *value);
VIZENGINE_API int _api__viz_get_videoout_input_retrace_counter (unsigned long *value);

VIZENGINE_API int _api__viz_get_videoout_propagation_delay();

VIZENGINE_API int _api__viz_get_output_field_dominance(bool *bEven);
VIZENGINE_API int _api__viz_get_output_interlaced(bool *bEven);
VIZENGINE_API int _api__viz_get_output_format();
VIZENGINE_API int _api__viz_get_camera_stereo_mode();
VIZENGINE_API const char* _api__viz_config_convert_path(const char* orig_path);
VIZENGINE_API int _api__viz_is_feature_enabled(int feature, bool *enabled);
VIZENGINE_API int _api__viz_is_vga_mode(bool *isVgaMode);
VIZENGINE_API int _api__viz_query_mouse_pos(int win_id, int *xpos, int *ypos);
VIZENGINE_API int _api__viz_query_mouse_pos_undeformed(int win_id, int *xpos, int *ypos);
VIZENGINE_API int _api__viz_get_window_size(int *width, int *height);
VIZENGINE_API int _api__viz_get_output_to_render_ratio( float * ratioX, float * ratioY );
VIZENGINE_API int _api__viz_get_elapsed_time(double *value);

VIZENGINE_API unsigned int _api__viz_get_current_timecode();
VIZENGINE_API unsigned int _api__viz_get_post_timecode();

VIZENGINE_API int _api__viz_is_importable_picture(const char *imageName);
VIZENGINE_API int _api__viz_import_image(const char *imageName,int *format , int *width , int *height , unsigned char **data);
VIZENGINE_API int _api__viz_done_import_image();

VIZENGINE_API int _api__viz_get_aspect(float *value);
VIZENGINE_API int _api__viz_get_out_renderer_size(int *w,int *h);
VIZENGINE_API int _api__viz_get_out_renderer_buffer_size(int *w, int *h);
VIZENGINE_API int _api__viz_get_panasonic_video_data(int x, int y, int width, int height, unsigned char ** data );

VIZENGINE_API int _api__viz_get_post_window_size(int *width, int *height);
VIZENGINE_API int _api__viz_set_window_cursor(int cursor);

// UNDOREDO
VIZENGINE_API int _api__viz_start_undo_step(const char* undoLabel, unsigned int uNumberOfIDs, unsigned int* pObjectIDs);
VIZENGINE_API void _api__viz_end_undo_step(bool bRefreshGUI = true);
VIZENGINE_API void _api__viz_cancel_undo_step(void);

VIZENGINE_API int _api__everest_load_scene( const char *scene,int *sceneId);
VIZENGINE_API int _api__everest_set_show_object_bounding_box(bool v);
VIZENGINE_API int _api__everest_get_show_object_bounding_box(bool *v);
VIZENGINE_API int _api__viz_get_mapserver_parameters(bool *bActive, const char ** ServerIp, const char ** UserName,
                                                       const char ** Password, const char ** DefaultProject, int *iDefaultImageWidth, int *iDefaultImageHeight);
VIZENGINE_API int _api__viz_set_mapserver_parameters(bool bActive, const char * ServerIp, const char * UserName,
                                                       const char * Password, const char * DefaultProject, int iDefaultImageWidth, int iDefaultImageHeight);
VIZENGINE_API int _api__viz_get_temporary_files_path(const char ** chTemporaryFilesPath);
__declspec(deprecated(" this is a deprecated function. Please use _api__viz_get_clip_data_directory()"))
VIZENGINE_API int _api__viz_get_clip_data_directoryA(char * chClipDataDir, int nBufSizeInChars);
VIZENGINE_API int _api__viz_get_clip_data_directory(wchar_t * chClipDataDir, int nBufSizeInChars);
__declspec(deprecated(" this is a deprecated function. Please use _api__viz_get_viz_programdata_folder()"))
VIZENGINE_API int _api__viz_get_viz_programdata_folderA(char * chVizDataFolder, int nBufSizeInChars);
VIZENGINE_API int _api__viz_get_viz_programdata_folder(wchar_t * chVizDataFolder, int nBufSizeInChars);
VIZENGINE_API int _api__viz_send_feedback_command(const char* str);
VIZENGINE_API int _api__viz_get_command_number(int* commandNumber);
VIZENGINE_API int _api__everest_get_scene(int iEditor, int iLayer, int * iSceneID);
VIZENGINE_API int _api__everest_set_scene(int iEditor, int iLayer, const char * scene);
VIZENGINE_API int _api__everest_set_scene_by_id(int iEditor, int iLayer, int iSceneID);
VIZENGINE_API int _api__everest_unload_scene(const char * scene);
VIZENGINE_API int _api__everest_unload_scene_by_id(int iSceneID);
VIZENGINE_API int _api__viz_hit_test(int iStrokeID, int x, int y);
VIZENGINE_API int _api__viz_send_attribution_list(int iAttributionSize,
                                    const char ** chAttributionNamesList,
                                    const char * chAttributionMain ,
                                    int iAttributionMainValue);
VIZENGINE_API int _api__viz_get_trace_by_index(unsigned int iIndex, unsigned int& iTraceID);
VIZENGINE_API int _api__viz_get_trace_count(unsigned int& iTraceCount);
VIZENGINE_API int _api__viz_get_background_loading_level(int &level);
VIZENGINE_API int _api__viz_get_number_of_texture_image_units(int& unit_count);
VIZENGINE_API int _api__viz_get_render_scale(float& render_scale);


// POOL
VIZENGINE_API int _api__pool_pool_exist (const char *name);
VIZENGINE_API int _api__pool_get_pool (const char *name, int *returnid);
VIZENGINE_API int _api__pool_item_exist (int pool_id, const char *name);
VIZENGINE_API int _api__pool_create_item (int pool_id, int *obj_id);
VIZENGINE_API int _api__pool_save (int pool_id, const char *name, int obj_id);
VIZENGINE_API int _api__pool_delete (int pool_id, const char *name);
VIZENGINE_API int _api__pool_get_object (int pool_id, const char *name, int *obj_id);
// just for debugging
//VIZENGINE_API int _api__pools_print_pool_info ();

// CLOCK
VIZENGINE_API int _api__clock_get_clock(const int iClockID, int *iObjectID);
VIZENGINE_API int _api__clock_set_time(const int iObjectID, const double dTime);
VIZENGINE_API int _api__clock_get_time(const int iObjectID, double *dTime);
VIZENGINE_API int _api__clock_set_new_start_time(const int iObjectID, const double dTime);
VIZENGINE_API int _api__clock_start(const int iObjectID);
VIZENGINE_API int _api__clock_pause(const int iObjectID);
VIZENGINE_API int _api__clock_stop(const int iObjectID);
VIZENGINE_API int _api__clock_continue(const int iObjectID);
VIZENGINE_API int _api__clock_get_is_running(const int iObjectID, bool *bFlag);
VIZENGINE_API int _api__clock_get_check_limit(const int iObjectID, bool *bCheck);
VIZENGINE_API int _api__clock_set_check_limit(const int iObjectID, const bool bCheck);
VIZENGINE_API int _api__clock_get_limit(const int iObjectID, double *dValue);
VIZENGINE_API int _api__clock_set_limit(const int iObjectID, const double dValue);
VIZENGINE_API int _api__clock_add_time_diff(const int iObjectID, const double dValue);
VIZENGINE_API int _api__clock_get_direction(const int iObjectID, int *iDir);
VIZENGINE_API int _api__clock_set_direction(const int iObjectID, const int iDir);

// the essential part of the solver algorithm for viz sports
VIZENGINE_API double _api__solve_calc_l2_froml1a(double l1,double f,double a,double sign);
VIZENGINE_API double _api__solve_calc_a_froml1l2(double l1, float *m1, double l2, float *m2);

// deprecated SENSOR_CHANNEL
VIZENGINE_API int _api__get_sensor_id(int* sensor_id, const char* sensor_name, const char*channel_name);
VIZENGINE_API int _api__get_free_sensor_id(int* sensor_id);
VIZENGINE_API int _api__set_sensor_active(int sensor_id, bool active);
VIZENGINE_API int _api__get_sensor_active(int sensor_id, bool* active);
VIZENGINE_API int _api__set_sensor_type(int sensor_id, int type);
VIZENGINE_API int _api__get_sensor_type(int sensor_id, int* type);
VIZENGINE_API int _api__set_sensor_sensor_name(int sensor_id, const char* sensor_name);
VIZENGINE_API int _api__get_sensor_sensor_name(int sensor_id, const char** sensor_name);
VIZENGINE_API int _api__set_sensor_channel_name(int sensor_id, const char* channel_name);
VIZENGINE_API int _api__get_sensor_channel_name(int sensor_id, const char** channel_name);

#if 0
#define API_SENSOR_DATA_SET_PROT(what) \
    VIZENGINE_API int _api__set_sensor_data_##what(int sensor_id, ##what value);
#define API_SENSOR_DATA_GET_PROT(what) \
    VIZENGINE_API int _api__get_sensor_data_##what(int sensor_id, ##what * value);
API_SENSOR_DATA_SET_PROT(bool);
API_SENSOR_DATA_SET_PROT(int);
API_SENSOR_DATA_SET_PROT(float);
API_SENSOR_DATA_SET_PROT(double);
API_SENSOR_DATA_GET_PROT(bool);
API_SENSOR_DATA_GET_PROT(int);
API_SENSOR_DATA_GET_PROT(float);
API_SENSOR_DATA_GET_PROT(double);
#endif

VIZENGINE_API int _api__set_sensor_data_bool  (int sensor_id, bool   value);
VIZENGINE_API int _api__set_sensor_data_int   (int sensor_id, int    value);
VIZENGINE_API int _api__set_sensor_data_float (int sensor_id, float  value);
VIZENGINE_API int _api__set_sensor_data_double(int sensor_id, double value);
VIZENGINE_API int _api__get_sensor_data_bool  (int sensor_id, bool   * value);
VIZENGINE_API int _api__get_sensor_data_int   (int sensor_id, int    * value);
VIZENGINE_API int _api__get_sensor_data_float (int sensor_id, float  * value);
VIZENGINE_API int _api__get_sensor_data_double(int sensor_id, double * value);

// EXPERT
VIZENGINE_API int _api__get_expert_backside(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_backside(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_wireframe(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_wireframe(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_outline(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_outline(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_twosided_lighting(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_twosided_lighting(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_zbuffer_draw(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_zbuffer_draw(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_line_antialiasing(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_line_antialiasing(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_separate_specular(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_separate_specular(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_wireframe_width(int iObjectID, float *value);
VIZENGINE_API int _api__set_expert_wireframe_width(int iObjectID, float value);
VIZENGINE_API int _api__get_expert_exact_picking(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_exact_picking(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_mirror(int iObjectID, int *value);
VIZENGINE_API int _api__set_expert_mirror(int iObjectID, int value);
VIZENGINE_API int _api__get_expert_render_mode(int iObjectID, int *value);
VIZENGINE_API int _api__set_expert_render_mode(int iObjectID, int value);
VIZENGINE_API int _api__get_expert_transparency_mode(int iObjectID, int *value);
VIZENGINE_API int _api__set_expert_transparency_mode(int iObjectID, int value);
VIZENGINE_API int _api__get_expert_shade_model(int iObjectID, int *value);
VIZENGINE_API int _api__set_expert_shade_model(int iObjectID, int value);
VIZENGINE_API int _api__get_expert_zbuffer_read(int iObjectID, bool *value);
VIZENGINE_API int _api__set_expert_zbuffer_read(int iObjectID, bool value);
VIZENGINE_API int _api__get_expert_draw_layer(int iObjectID, int *value);
VIZENGINE_API int _api__set_expert_draw_layer(int iObjectID, int value);

// INFOTEXT
VIZENGINE_API int _api__get_infotext_text(int iObjectID, const char **value);
VIZENGINE_API int _api__set_infotext_text(int iObjectID, const char *value);

// GLOW
VIZENGINE_API int _api__get_glow_blur_width(int iObjectID, float *value);
VIZENGINE_API int _api__set_glow_blur_width(int iObjectID, float value);
VIZENGINE_API int _api__get_glow_strength(int iObjectID, float *value);
VIZENGINE_API int _api__set_glow_strength(int iObjectID, float value);
VIZENGINE_API int _api__get_glow_object_strength(int iObjectID, float *value);
VIZENGINE_API int _api__set_glow_object_strength(int iObjectID, float value);
VIZENGINE_API int _api__get_glow_draw_texture(int iObjectID, bool *value);
VIZENGINE_API int _api__set_glow_draw_texture(int iObjectID, bool value);
VIZENGINE_API int _api__get_glow_texture_unit(int iObjectID, int *value);
VIZENGINE_API int _api__set_glow_texture_unit(int iObjectID, int value);
VIZENGINE_API int _api__get_glow_use_color(int iObjectID, bool *value);
VIZENGINE_API int _api__set_glow_use_color(int iObjectID, bool value);
VIZENGINE_API int _api__get_glow_color(int iObjectID, unsigned long *value);
VIZENGINE_API int _api__set_glow_color(int iObjectID, unsigned long value);
VIZENGINE_API int _api__get_glow_textured(int iObjectID, bool *value);
VIZENGINE_API int _api__set_glow_textured(int iObjectID, bool value);

// MASK
VIZENGINE_API int _api__get_mask_layer(int iObjectID, int *value);
VIZENGINE_API int _api__set_mask_layer(int iObjectID, int value);

// MASK_TARGET
VIZENGINE_API int _api__get_mask_target_layer(int iObjectID, int *value);
VIZENGINE_API int _api__set_mask_target_layer(int iObjectID, int value);

// CLIPPER
VIZENGINE_API int _api__get_clipperid(int clipper_number, char* object, int type);

VIZENGINE_API int _api__get_clipper_active(int iObjectID, int *value);
VIZENGINE_API int _api__set_clipper_active(int iObjectID, int value);

VIZENGINE_API int _api__get_clipper_show(int iObjectID, bool *value);
VIZENGINE_API int _api__set_clipper_show(int iObjectID, bool value);
VIZENGINE_API int _api__get_clipper_reverse(int iObjectID, bool *value);
VIZENGINE_API int _api__set_clipper_reverse(int iObjectID, bool value);

VIZENGINE_API int _api__get_clipper_container(int iObjectID, int *cont);
VIZENGINE_API int _api__set_clipper_container(int iObjectID, int cont);

VIZENGINE_API int _api__get_clipper_track_container_active(int iObjectID, bool *value);
VIZENGINE_API int _api__set_clipper_track_container_active(int iObjectID, bool value);
VIZENGINE_API int _api__clipper_get_position(int iObjectID, int *value);
VIZENGINE_API int _api__clipper_set_position(int iObjectID, int value);
VIZENGINE_API int _api__clipper_get_rotation(int iObjectID, int *value);
VIZENGINE_API int _api__clipper_set_rotation(int iObjectID, int value);



// CLIPPER_TARGET
VIZENGINE_API int _api__get_clipper_target_planes(int iObjectID, int *value);
VIZENGINE_API int _api__set_clipper_target_planes(int iObjectID, int value);


// functions used by the script engine

VIZENGINE_API void* _api__container_get_script(int containerId);
VIZENGINE_API void* _api__scene_get_script(int sceneId);

VIZENGINE_API float _api__get_position_x(int iObjectID);
VIZENGINE_API float _api__get_position_y(int iObjectID);
VIZENGINE_API float _api__get_position_z(int iObjectID);
VIZENGINE_API void _api__set_position_x(int iObjectID, float x);
VIZENGINE_API void _api__set_position_y(int iObjectID, float y);
VIZENGINE_API void _api__set_position_z(int iObjectID, float z);

VIZENGINE_API float _api__get_rotation_x(int iObjectID);
VIZENGINE_API float _api__get_rotation_y(int iObjectID);
VIZENGINE_API float _api__get_rotation_z(int iObjectID);
VIZENGINE_API void _api__set_rotation_x(int iObjectID, float x);
VIZENGINE_API void _api__set_rotation_y(int iObjectID, float y);
VIZENGINE_API void _api__set_rotation_z(int iObjectID, float z);

VIZENGINE_API float _api__get_scaling_x(int iObjectID);
VIZENGINE_API float _api__get_scaling_y(int iObjectID);
VIZENGINE_API float _api__get_scaling_z(int iObjectID);
VIZENGINE_API void _api__set_scaling_x(int iObjectID, float x);
VIZENGINE_API void _api__set_scaling_y(int iObjectID, float y);
VIZENGINE_API void _api__set_scaling_z(int iObjectID, float z);

VIZENGINE_API float _api__get_center_x(int iObjectID);
VIZENGINE_API float _api__get_center_y(int iObjectID);
VIZENGINE_API float _api__get_center_z(int iObjectID);
VIZENGINE_API void _api__set_center_x(int iObjectID, float x);
VIZENGINE_API void _api__set_center_y(int iObjectID, float y);
VIZENGINE_API void _api__set_center_z(int iObjectID, float z);

VIZENGINE_API int _api__container_find_super_container_by_name(int containerId, const char* name);
VIZENGINE_API int _api__container_find_sub_container_by_name(int containerId, const char* name);
VIZENGINE_API int _api__get_mouse_position(float* pos);
VIZENGINE_API bool _api__is_mouse_inside_container(int containerId);
VIZENGINE_API bool _api__is_container_on_top(int containerId);
VIZENGINE_API bool _api__get_screen_bounds(int containerId, evVertex3D &v3dBound1, evVertex3D &v3dBound2);
VIZENGINE_API int _api__is_vertex_in_bounding_box(int containerId, const float* pVertex, bool* pResult);
VIZENGINE_API int _api__is_screen_point_in_bounding_box(int containerId, int x, int y, bool* pResult);
VIZENGINE_API int _api__container_get_uv_coordinates_of_screen_point(int containerId, int x, int y, float &u, float &v);
VIZENGINE_API int _api__container_set_screen_position_ortho(int iObjectID, int x, int y);
VIZENGINE_API int _api__container_get_screen_position_ortho(int iObjectID, int *pX, int *pY);
VIZENGINE_API int _api__container_set_screen_size_ortho(int iObjectID, int x, int y);
VIZENGINE_API int _api__container_get_screen_size_ortho(int iObjectID, int *pX, int *pY);
VIZENGINE_API int _api__container_get_screen_position(int iObjectID, int *pX, int *pY);
//VIZENGINE_API int _api__container_set_screen_position(int iObjectID, int x, int y);
//VIZENGINE_API int _api__container_set_screen_center(int iObjectID, int x, int y);
VIZENGINE_API int _api__container_set_center_position_locked(int iObjectID, const evVertex3D& v3dCenter);
VIZENGINE_API int _api__container_set_center_screen_position_locked(int iObjectID, float fX, float fY);
VIZENGINE_API int _api__container_set_center_screen_grid_position_locked(int iObjectID, float fX, float fY);
VIZENGINE_API int _api__container_screen_pos_to_local_pos(int iObjectID, float fX, float fY, evVertex3D &v3dPos);
VIZENGINE_API int _api__container_screen_pos_to_local_plane_xy(int iObjectID, float fX, float fY, evVertex3D &v3dPos);
VIZENGINE_API int _api__container_screen_pos_to_local_plane_xz(int iObjectID, float fX, float fY, evVertex3D &v3dPos);
VIZENGINE_API int _api__container_screen_pos_to_local_plane_yz(int iObjectID, float fX, float fY, evVertex3D &v3dPos);
VIZENGINE_API int _api__container_screen_offset_to_local_plane_xy_offset(int iObjectID, float fDX, float fDY, evVertex3D &v3dDPos);
VIZENGINE_API int _api__container_screen_offset_to_local_plane_xz_offset(int iObjectID, float fDX, float fDY, evVertex3D &v3dDPos);
VIZENGINE_API int _api__container_screen_offset_to_local_plane_yz_offset(int iObjectID, float fDX, float fDY, evVertex3D &v3dDPos);
VIZENGINE_API int _api__container_screen_absolute_offset_to_local_plane_xy_offset(int iObjectID, float fXOld, float fYOld, float fXNew, float fYNew, evVertex3D &v3dDPos);
VIZENGINE_API int _api__container_screen_absolute_offset_to_local_plane_xz_offset(int iObjectID, float fXOld, float fYOld, float fXNew, float fYNew, evVertex3D &v3dDPos);
VIZENGINE_API int _api__container_screen_absolute_offset_to_local_plane_yz_offset(int iObjectID, float fXOld, float fYOld, float fXNew, float fYNew, evVertex3D &v3dDPos);
VIZENGINE_API int _api__container_screen_pos_to_local_grid(int iObjectID, float fX, float fY, evVertex3D &v3dPos);
VIZENGINE_API int _api__container_local_pos_to_screen_pos(int iObjectID, evVertex3D v3dPos, float &fX, float &fY);
VIZENGINE_API int _api__container_local_pos_to_world_pos(int iObjectID, evVertex3D v3dPos, evVertex3D &v3dPosWorld);
VIZENGINE_API int _api__container_world_pos_to_local_pos(int iObjectID, evVertex3D v3dPos, evVertex3D &v3dPosLocal);
//VIZENGINE_API int _api__container_lock_grid_to_container(int iObjectID);
//VIZENGINE_API int _api__container_release_grid(int iObjectID);
VIZENGINE_API int _api__container_get_first_child_containing_mouse_cursor(int containerId);
VIZENGINE_API int _api__container_get_screen_point_to_geom_surface(int iObjectID, int x, int y, evVertex3D &v3dPos);
VIZENGINE_API int _api__container_set_show(int iObjectID, int value);
VIZENGINE_API int _api__container_get_show(int iObjectID, int * value);
VIZENGINE_API void _api__set_render_function_parameters(int layer, void* pEditor, bool bUseDisplayList, bool bWireframe, bool bBackFace, int *viewport, bool* valid_planes, bool bKeyOnly, bool bBlendAllowed);
VIZENGINE_API int _api__container_render(int iObjectID, bool render_transformation);
VIZENGINE_API int _api__container_render_geometry(int iObjectID, bool render_transformation);
VIZENGINE_API int _api__container_set_force_calculate_matrix(int object_id);
VIZENGINE_API int _api__container_create_container_fx(int iObjectID);
VIZENGINE_API int _api__container_delete_container_fx(int iObjectID);
VIZENGINE_API int _api__container_get_container_fx(int iObjectID, int *iContFxID);
VIZENGINE_API int _api__container_set_container_fx(int object_id, int value);
VIZENGINE_API int _api__container_get_container_fx_active(int iObjectID, bool *value);
VIZENGINE_API int _api__container_set_container_fx_active(int object_id, bool value);
VIZENGINE_API int _api__container_get_uuid(int iObjectID, char* psUuidString, int iMaxStringLength);
VIZENGINE_API int _api__container_is_background_loading_geometry(int iObjectID, bool& loading);


VIZENGINE_API bool _api__is_key_down(int keyCode);
VIZENGINE_API int _api_get_plugin_paramter_float(const char* name, float* ret);
VIZENGINE_API int _api_get_plugin_paramter_int(const char* name, int* ret);
VIZENGINE_API int _api_get_plugin_paramter_bool(const char* name, bool* ret);
VIZENGINE_API int _api_get_plugin_paramter_string(const char* name, const char** ret);

VIZENGINE_API int _api__update_current_stage();
VIZENGINE_API int _api__update_animation_editor();

VIZENGINE_API bool _api__is_class_Base(int id);
VIZENGINE_API bool _api__is_class_Transform(int id);
VIZENGINE_API bool _api__is_class_Position(int id);
VIZENGINE_API bool _api__is_class_Rotation(int id);
VIZENGINE_API bool _api__is_class_Scaling(int id);
VIZENGINE_API bool _api__is_class_Center(int id);
VIZENGINE_API bool _api__is_class_Image(int id);
VIZENGINE_API bool _api__is_class_Alpha(int id);
VIZENGINE_API bool _api__is_class_Key(int id);
VIZENGINE_API bool _api__is_class_Material(int id);
VIZENGINE_API bool _api__is_class_Geometry(int id);
VIZENGINE_API bool _api__is_class_Texture(int id);
VIZENGINE_API bool _api__is_class_Container(int id);
VIZENGINE_API bool _api__is_class_Camera(int id);
VIZENGINE_API bool _api__is_class_Light(int id);
VIZENGINE_API bool _api__is_class_Scene(int id);
VIZENGINE_API bool _api__is_class_BezierHandle(int id);
VIZENGINE_API bool _api__is_class_Keyframe(int id);
VIZENGINE_API bool _api__is_class_Channel(int id);
VIZENGINE_API bool _api__is_class_Director(int id);
VIZENGINE_API bool _api__is_class_Stage(int id);
VIZENGINE_API bool _api__is_class_SharedMemory(int id);
VIZENGINE_API bool _api__is_class_Global(int id);

VIZENGINE_API char* _api__variant_variable_init_bool(bool value);
VIZENGINE_API char* _api__variant_variable_init_int(int value);
VIZENGINE_API char* _api__variant_variable_init_double(double value);
VIZENGINE_API char* _api__variant_variable_init_vertex(const float* p);
VIZENGINE_API char* _api__variant_variable_init_matrix(const float* p);
VIZENGINE_API char* _api__variant_variable_init_color(unsigned int color_value);
VIZENGINE_API char* _api__variant_variable_init_string(const char* s);

VIZENGINE_API bool _api__variant_variable_get_bool(const char* s, bool& value);
VIZENGINE_API bool _api__variant_variable_get_int(const char* s, int& value);
VIZENGINE_API bool _api__variant_variable_get_double(const char* s, double& value);
VIZENGINE_API bool _api__variant_variable_get_vertex(const char* s, float* p);
VIZENGINE_API bool _api__variant_variable_get_matrix(const char* s, float* p);
VIZENGINE_API bool _api__variant_variable_get_color(const char* s, unsigned int* p);
VIZENGINE_API bool _api__variant_variable_get_string(const char* s, char** p);

VIZENGINE_API bool _api__shared_script_memory_has_key(int objectId, const char* keyString);
VIZENGINE_API bool _api__shared_script_memory_create_key(int objectId, const char* keyString);
VIZENGINE_API bool _api__shared_script_memory_delete_key(int objectId, const char* keyString);
VIZENGINE_API bool _api__shared_script_memory_set_value(int objectId, const char* keyString, const char* dataString);
VIZENGINE_API bool _api__shared_script_memory_set_value_delayed(int objectId, const char* keyString, const char* dataString);
VIZENGINE_API bool _api__shared_script_memory_find(int objectId, const char* keyString, const char** pDataString);
VIZENGINE_API bool _api__shared_memory_register_changed_callback(int objectId, const char* keyString);
VIZENGINE_API bool _api__shared_memory_unregister_changed_callback(int objectId, const char* keyString);
VIZENGINE_API bool _api__shared_script_memory_get_all_keys(int objectId, void* /* THeapArray<THeapArray<char> > */ out_array);

VIZENGINE_API bool _api__shared_script_memory_get_keys(int objectId, int& keyArraySize, const char**& keyArray); // unused
VIZENGINE_API bool _api__shared_script_memory_set_raw_string(int objectId, const char* key, const char* raw_string); // unused

VIZENGINE_API int _api__scene_set_camera_near(int object_id, float fValue);
VIZENGINE_API int _api__scene_set_camera_far(int object_id, float fValue);
VIZENGINE_API int _api__scene_get_camera_near(int object_id, float *fValue);
VIZENGINE_API int _api__scene_get_camera_far(int object_id, float *fValue);
VIZENGINE_API int _api__scene_get_is_warm_up_stage(int object_id, bool *bWarmup);
VIZENGINE_API int _api__scene_get_is_last_warm_up_frame(int object_id, bool *bWarmup);

VIZENGINE_API int _api__scene_get_shared_script_memory(int sceneId);
VIZENGINE_API int _api__global_get_shared_script_memory();
VIZENGINE_API int _api__global_get_distributed_shared_script_memory();
VIZENGINE_API int _api__global_get_font_encoding(int* pFontCode);
VIZENGINE_API void _api__global_set_show_mouse_cursor(bool v);
VIZENGINE_API bool _api__global_get_show_mouse_cursor();

VIZENGINE_API int    _api__global_get_timecode_index(const char* device, const char* timecode_type);
VIZENGINE_API bool   _api__global_get_timecode(int index, int* rHours, int* rMinutes, int* rSeconds, int* sFrames);
VIZENGINE_API bool   _api__global_get_timecode2(int index, int* rHours, int* rMinutes, int* rSeconds, int* sFrames, bool* bField2);
VIZENGINE_API bool   _api__global_get_timecode_string(int index, const char** rTimecode);
VIZENGINE_API bool   _api__global_get_timecode_field2(int index, bool* bField2);
VIZENGINE_API bool   _api__global_get_timecode_get_progressive(int index, bool* bProgressive);
VIZENGINE_API bool   _api__global_get_timecode_get_fields(int index, uint32_t* fields);
VIZENGINE_API bool   _api__global_get_timecode_get_frames(int index, uint32_t* frames);
VIZENGINE_API bool   _api__global_get_timecode_get_fields_in_24h(int index, uint32_t* fields_in24h);
VIZENGINE_API bool   _api__global_get_timecode_get_external_clock_ref(int index, bool* external_clock_ref);
VIZENGINE_API bool   _api__global_get_timecode_get_check_color_frame(int index, bool* check_color_frame);
VIZENGINE_API bool   _api__global_get_timecode_get_check_drop_frame_compensation(int index, bool* check_drop_frame_compensation);
VIZENGINE_API bool   _api__global_get_timecode_get_check_polarity_correctness(int index, bool* check_polarity_correctness);
VIZENGINE_API bool   _api__global_get_timecode_get_assigned(int index, bool* assigned);
VIZENGINE_API bool   _api__global_get_user_bits(int index, uint32_t* user_bits);
VIZENGINE_API size_t _api__global_get_number_of_timecode_sources();
VIZENGINE_API bool   _api__global_get_tc_device(int index, const char** rDevice);
VIZENGINE_API bool   _api__global_get_tc_type(int index, const char** rType);
VIZENGINE_API int    _api__global_get_tracked_camera_timecode(const int cameraIndex);


VIZENGINE_API int _api__get_filename_of_pool_object(const char* location, char* returnBuffer, int bufferLength);
VIZENGINE_API int _api__get_path_of_pool_object(const char* location, bool addPoolPrefix, char* returnBuffer, int bufferLength);
VIZENGINE_API int _api__get_filename_of_uuid(const char* uuidString, char* returnBuffer, int bufferLength);
VIZENGINE_API int _api__get_path_of_uuid(const char* uuidString, char* returnBuffer, int bufferLength);
VIZENGINE_API int _api__get_paths_of_uuid(const char* uuidString, char* returnBuffer, int bufferLength);
VIZENGINE_API int _api__get_uuid_of_path(const char* pathString, char* returnBuffer, int bufferLength);

VIZENGINE_API int _api__scene_get_unlocked_grid(int objectId, int *pGridId);
VIZENGINE_API int _api__scene_get_grid(int objectId, int *pGridId, int gridNumber);
VIZENGINE_API int _api__scene_set_grid(int objectId, int gridNumber);

// GRID
VIZENGINE_API int _api__grid_get_type(int objectId, int *pValue);
VIZENGINE_API int _api__grid_set_type(int objectId, int type);
VIZENGINE_API int _api__grid_get_locked(int objectId, bool *pValue);
VIZENGINE_API int _api__grid_set_locked(int objectId, bool bLock);
VIZENGINE_API int _api__grid_move_to_container(int objectId, int containerId);

// VIDEO_CHANNEL
VIZENGINE_API int _api__video_channel_sample_now(int objectId);
VIZENGINE_API int _api__video_channel_set_keyer_sample_params(int objectId, int x, int y, int width, int height);
VIZENGINE_API int _api__video_channel_get_sample_uv_range_check_active(int objectId, bool *active);
VIZENGINE_API int _api__video_channel_set_sample_uv_range_check_active(int objectId, bool active);
VIZENGINE_API int _api__video_channel_set_sample_uv_range(int objectId, float fURangeMin, float fURangeMax, float fVRangeMin, float fVRangeMax);
VIZENGINE_API int _api__video_channel_get_sample_trustiness(int objectId, float *pValue);
VIZENGINE_API int _api__video_channel_get_sample_lum(int objectId, float *pValue);
VIZENGINE_API int _api__video_channel_set_sample_lum(int objectId, float lum);
VIZENGINE_API int _api__video_channel_get_sample_u(int objectId, float *pValue);
VIZENGINE_API int _api__video_channel_set_sample_u(int objectId, float u);
VIZENGINE_API int _api__video_channel_get_sample_v(int objectId, float *pValue);
VIZENGINE_API int _api__video_channel_set_sample_v(int objectId, float v);
VIZENGINE_API int _api__video_channel_get_yuv_texture_target(int objectId, int *pValue);

// VIDEO GLOBAL
VIZENGINE_API int _api__video_global_set_vbi_channel(const char* pszVbiChannel);
VIZENGINE_API int _api__video_global_get_vbi_channel(const char** ppszVbiChannel);
VIZENGINE_API int _api__video_global_get_vbi_channel_list(const char** ppszVbiChannelList);


// GEOREF
VIZENGINE_API bool _api__georef_lonLat2xy(int object_id,
    double longitude, double latitude, double height, float& tx, float& ty, float& tz);
VIZENGINE_API bool _api__georef_xy2LonLat(int object_id,
    float tx, float ty, float tz, double& longitude, double& latitude, double& height);

VIZENGINE_API bool _api__georef_lonLat2xyNormalized(int object_id,
    double longitude, double latitude, double height, float& tx, float& ty, float& tz);
VIZENGINE_API bool _api__georef_xy2LonLatNormalized(int object_id,
    float tx, float ty, float tz, double& longitude, double& latitude, double& height);

VIZENGINE_API bool _api__georef_lonLat2xyModel(int object_id,
    double longitude, double latitude, double height, float& tx, float& ty, float& tz);
VIZENGINE_API bool _api__georef_xy2LonLatModel(int object_id,
    float tx, float ty, float tz, double& longitude, double& latitude, double& height);

VIZENGINE_API bool _api__georef_getLonLatBBox(int object_id, double& minLon, double& maxLon, double& minLat, double& maxLat);

VIZENGINE_API void _api__georef_get_dllName(int object_id, char** dllName);
VIZENGINE_API void _api__georef_set_dllName(int object_id, const char* dllName);
VIZENGINE_API void _api__georef_getParameterLong(int object_id, const char* paramName, long& value);
VIZENGINE_API void _api__georef_setParameterLong(int object_id, const char* paramName, long value);
VIZENGINE_API void _api__georef_getParameterFloat(int object_id, const char* paramName, float& value);
VIZENGINE_API void _api__georef_setParameterFloat(int object_id, const char* paramName, float value);
VIZENGINE_API void _api__georef_getParameterDouble(int object_id, const char* paramName, double& value);
VIZENGINE_API void _api__georef_setParameterDouble(int object_id, const char* paramName, double value);
VIZENGINE_API void _api__georef_getParameterString(int object_id, const char* paramName, const char* str, int maxSize);
VIZENGINE_API void _api__georef_setParameterString(int object_id, const char* paramName, const char* str, int maxSize);
VIZENGINE_API void _api__georef_readVGR(int object_id, const char* fileName);

VIZENGINE_API long _api__georef_getChangeID(int object_id);
VIZENGINE_API int _api__georef_copy_properties(int object_id, int value);

// ContainerFx
VIZENGINE_API int _api__container_fx_set_position(int object_id, float x, float y, float z);
VIZENGINE_API int _api__container_fx_get_position(int object_id, float& x, float& y, float& z);
VIZENGINE_API int _api__container_fx_set_position_mode(int object_id, int positionMode);
VIZENGINE_API int _api__container_fx_get_position_mode(int object_id, int& positionMode);
VIZENGINE_API int _api__container_fx_set_rotation(int object_id, float x, float y, float z);
VIZENGINE_API int _api__container_fx_get_rotation(int object_id, float& x, float& y, float& z);
VIZENGINE_API int _api__container_fx_set_rotation_mode(int object_id, int rotationMode);
VIZENGINE_API int _api__container_fx_get_rotation_mode(int object_id, int& rotationMode);
VIZENGINE_API int _api__container_fx_set_scaling(int object_id, float x, float y, float z);
VIZENGINE_API int _api__container_fx_get_scaling(int object_id, float& x, float& y, float& z);
VIZENGINE_API int _api__container_fx_set_scaling_mode(int object_id, int scalingMode);
VIZENGINE_API int _api__container_fx_get_scaling_mode(int object_id, int& scalingMode);
VIZENGINE_API int _api__container_fx_set_center_x_mode(int object_id, int centerMode);
VIZENGINE_API int _api__container_fx_get_center_x_mode(int object_id, int& centerMode);
VIZENGINE_API int _api__container_fx_set_center_y_mode(int object_id, int centerMode);
VIZENGINE_API int _api__container_fx_get_center_y_mode(int object_id, int& centerMode);
VIZENGINE_API int _api__container_fx_set_center_z_mode(int object_id, int centerMode);
VIZENGINE_API int _api__container_fx_get_center_z_mode(int object_id, int& centerMode);
VIZENGINE_API int _api__container_fx_set_color(int object_id, float r, float g, float b, float a);
VIZENGINE_API int _api__container_fx_get_color(int object_id, float& r, float& g, float& b, float& a);
VIZENGINE_API int _api__container_fx_set_color_mode(int object_id, int colorMode);
VIZENGINE_API int _api__container_fx_get_color_mode(int object_id, int& colorMode);
VIZENGINE_API int _api__container_fx_set_alpha(int object_id, float alpha);
VIZENGINE_API int _api__container_fx_get_alpha(int object_id, float& alpha);
VIZENGINE_API int _api__container_fx_set_alpha_mode(int object_id, int alphaMode);
VIZENGINE_API int _api__container_fx_get_alpha_mode(int object_id, int& alphaMode);
VIZENGINE_API int _api__container_fx_set_active(int object_id, bool active);
VIZENGINE_API int _api__container_fx_get_active(int object_id, bool& active);
VIZENGINE_API int _api__container_fx_reset(int object_id);


VIZENGINE_API int _api__tools_tcl_string_split(const char* s, void* /* THeapArray<THeapArray<char> > */ out_array);

VIZENGINE_API bool _api__plugin_editor_open_embedded_window(const char* title);
VIZENGINE_API void* _api__plugin_editor_get_embedded_window_handle();
VIZENGINE_API bool _api__plugin_editor_close_embedded_window();
VIZENGINE_API int _api__get_system_format();
VIZENGINE_API int _api__get_output_ringbuffer_size();
VIZENGINE_API int _api__get_output_ringbuffer_used();


// The shader API calls
VIZENGINE_API int _api__shader_get_type(int iObjectID, char **type);
VIZENGINE_API int _api__shader_set_active(int iObjectID, int value);
VIZENGINE_API int _api__shader_get_active(int iObjectID, int *value);

VIZENGINE_API int _api__set_shader_params(int iObjectID, int data_type, char* name, int offset, void* data, int max, int min);
VIZENGINE_API int _api__get_shader_params(int iObjectID, int data_type, char* name, int offset, void* data);
VIZENGINE_API int _api__shader_dispatcher(int iObjectID, ULONG_PTR msg, ULONG_PTR param, ULONG_PTR & ret);


// the OGL Context API calls
VIZENGINE_API GLboolean _api__context_valid();
VIZENGINE_API GLboolean _api__context_multisampled();
VIZENGINE_API GLboolean _api__context_get_GL_BLEND();
VIZENGINE_API GLboolean _api__context_get_GL_DEPTH_TEST();
VIZENGINE_API GLboolean _api__context_get_GL_CULL_FACE();
VIZENGINE_API GLboolean _api__context_get_GL_NORMALIZE();
VIZENGINE_API GLboolean _api__context_get_GL_ALPHA_TEST();
VIZENGINE_API GLboolean _api__context_get_GL_LINE_STIPPLE();
VIZENGINE_API GLboolean _api__context_get_GL_LINE_SMOOTH();
VIZENGINE_API GLboolean _api__context_get_GL_LOGIC_OP();
VIZENGINE_API GLboolean _api__context_get_GL_STENCIL_TEST();
VIZENGINE_API void      _api__context_get_GL_CLIP_PLANES(GLboolean state[6]);
VIZENGINE_API GLboolean _api__context_get_GL_CLIP_PLANE0();
VIZENGINE_API GLboolean _api__context_get_GL_CLIP_PLANE1();
VIZENGINE_API GLboolean _api__context_get_GL_CLIP_PLANE2();
VIZENGINE_API GLboolean _api__context_get_GL_CLIP_PLANE3();
VIZENGINE_API GLboolean _api__context_get_GL_CLIP_PLANE4();
VIZENGINE_API GLboolean _api__context_get_GL_CLIP_PLANE5();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHTING();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT_MODEL_TWO_SIDE();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT_MODEL_LOCAL_VIEWER();
VIZENGINE_API void        _api__context_get_GL_LIGHTS(GLboolean state[8]);
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT0();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT1();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT2();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT3();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT4();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT5();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT6();
VIZENGINE_API GLboolean _api__context_get_GL_LIGHT7();
VIZENGINE_API GLboolean _api__context_get_GL_POLYGON_MODE();
VIZENGINE_API GLboolean _api__context_get_GL_FRONT_FACE();
VIZENGINE_API GLboolean _api__context_get_GL_DEPTH_MASK();
VIZENGINE_API GLenum    _api__context_get_GL_DEPTH_FUNC();
VIZENGINE_API GLenum    _api__context_get_GL_BLEND_SFACTOR();
VIZENGINE_API GLenum    _api__context_get_GL_BLEND_DFACTOR();
VIZENGINE_API GLenum    _api__context_get_GL_BLEND_EQUATION();
VIZENGINE_API GLenum    _api__context_get_GL_SHADE_MODEL();
VIZENGINE_API float        _api__context_get_GL_LINE_WIDTH();
VIZENGINE_API GLboolean _api__context_get_GL_TEXTURE_ENABLED(int);
VIZENGINE_API GLenum    _api__context_get_GL_TEXTURE_ENVIRONMENT(int);
VIZENGINE_API GLenum    _api__context_get_GL_TEXTURE_TARGET(int);
VIZENGINE_API GLenum    _api__context_get_GL_TEXTURE_COMPONENTS(int);
VIZENGINE_API GLenum    _api__context_get_GL_TEXTURE_FORMAT(int);
VIZENGINE_API OGL_CONTEXT::eTextureCoordGen _api__context_get_GL_TEXTURE_COORD_GEN(int);
VIZENGINE_API GLenum    _api__context_get_GL_TEXTURE_TYPE(int);
VIZENGINE_API GLenum    _api__context_get_GL_TEXTURE_COMPRESSION(int);
VIZENGINE_API OGL_CONTEXT::eTextureQuality _api__context_get_GL_TEXTURE_QUALITY(int);
VIZENGINE_API int        _api__context_get_GL_TEXTURE_IMAGE(int);
VIZENGINE_API void        _api__context_get_GL_TEXTURE_SIZE(int, int*, int*);
VIZENGINE_API void        _api__context_get_material_ambient(float*, float*, float*);
VIZENGINE_API void        _api__context_get_material_diffuse(float*, float*, float*);
VIZENGINE_API void        _api__context_get_material_specular(float*, float*, float*);
VIZENGINE_API void        _api__context_get_material_emission(float*, float*, float*);
VIZENGINE_API float        _api__context_get_material_shininess();
VIZENGINE_API float        _api__context_get_material_alpha();
VIZENGINE_API void        _api__context_get_viewport(int*, int*, int*, int*);
VIZENGINE_API void        _api__context_get_window_size( int*, int*);


// Channel Base
VIZENGINE_API bool        _api__avchannel_is_valid(int object_id);

VIZENGINE_API void        _api__avchannel_get_position(int object_id, float *x, float *y);
VIZENGINE_API void        _api__avchannel_set_position(int object_id, float x, float y);

VIZENGINE_API void        _api__avchannel_get_screen_position(int object_id, float *x, float *y);
VIZENGINE_API void        _api__avchannel_set_screen_position(int object_id, float x, float y);

VIZENGINE_API void        _api__avchannel_get_center(int object_id, float *x, float *y);
VIZENGINE_API void        _api__avchannel_set_center(int object_id, float x, float y);

VIZENGINE_API void        _api__avchannel_get_screen_center(int object_id, float *x, float *y);
VIZENGINE_API void        _api__avchannel_set_screen_center(int object_id, float x, float y);

VIZENGINE_API void        _api__avchannel_get_size(int object_id, float *width, float *height);
VIZENGINE_API void        _api__avchannel_set_size(int object_id, float width, float height);

VIZENGINE_API void        _api__avchannel_get_screen_size(int object_id, float *width, float *height);
VIZENGINE_API void        _api__avchannel_set_screen_size(int object_id, float width, float height);

VIZENGINE_API void        _api__avchannel_get_crop(int object_id, float *left, float *right, float *top, float *bottom);
VIZENGINE_API void        _api__avchannel_set_crop(int object_id, float left, float right, float top, float bottom);

VIZENGINE_API void        _api__avchannel_get_screen_crop(int object_id, float *left, float *right, float *top, float *bottom);
VIZENGINE_API void        _api__avchannel_set_screen_crop(int object_id, float left, float right, float top, float bottom);

VIZENGINE_API void        _api__avchannel_get_alpha(int object_id, float *alpha);
VIZENGINE_API void        _api__avchannel_set_alpha(int object_id, float alpha);

VIZENGINE_API void        _api__avchannel_get_master_volume(int object_id, float *volume);
VIZENGINE_API void        _api__avchannel_set_master_volume(int object_id, float volume);

VIZENGINE_API void        _api__avchannel_get_channel_volume(int object_id, int audio_channel, float *volume);
VIZENGINE_API void        _api__avchannel_set_channel_volume(int object_id, int audio_channel, float volume);

VIZENGINE_API void        _api__avchannel_get_force_key(int object_id, bool *force_key);
VIZENGINE_API void        _api__avchannel_set_force_key(int object_id, bool force_key);

VIZENGINE_API void        _api__avchannel_get_keep_aspect(int object_id, bool *keep_aspect);
VIZENGINE_API void        _api__avchannel_set_keep_aspect(int object_id, bool keep_aspect);

VIZENGINE_API void        _api__avchannel_get_controlled_animation(int object_id, bool *controlled_animation);
VIZENGINE_API void        _api__avchannel_set_controlled_animation(int object_id, bool controlled_animation);

//Set channel content relative position in percent
VIZENGINE_API int _api__avchannel_content_set_position(int object_id, float x, float y);

// Get channel content relative position in percent
VIZENGINE_API int _api__avchannel_content_get_position(int object_id, float* x, float* y);

// Set channel content center in percent
VIZENGINE_API int _api__avchannel_content_set_center(int object_id, float x, float y);

// Get channel content center in percent
VIZENGINE_API int _api__avchannel_content_get_center(int object_id, float* x, float* y);

// Set channel content size in percent
VIZENGINE_API int _api__avchannel_content_set_size(int object_id, float x, float y);

// Get channel content size in percent
VIZENGINE_API int _api__avchannel_content_get_size(int object_id, float* x, float* y);

// Set channel content relative crop in percent
VIZENGINE_API int _api__avchannel_content_set_crop(int object_id, float left, float right, float top, float bottom);

// Get channel content relative crop in percent
VIZENGINE_API int _api__avchannel_content_get_crop(int object_id, float* left, float* right, float* top, float* bottom);

// Set channel content zoom mode
VIZENGINE_API int _api__avchannel_content_set_zoom_mode(int object_id, int mode);

// Get channel content zoom mode
VIZENGINE_API int _api__avchannel_content_get_zoom_mode(int object_id, int* mode);

// Set channel content border color
VIZENGINE_API int _api__avchannel_content_set_border_color(int object_id, float r, float g, float b, float a);

// Get channel content border color
VIZENGINE_API int _api__avchannel_content_get_border_color(int object_id, float* r, float* g, float* b, float* a);


// GFX Channel
VIZENGINE_API bool        _api__gfxchannel_is_valid(int object_id);

VIZENGINE_API void        _api__gfxchannel_set_object(int object_id, const char *location);

VIZENGINE_API void        _api__gfxchannel_set_local_scene(int object_id, int scene_id);
VIZENGINE_API void        _api__gfxchannel_get_local_scene(int object_id, int *scene_id);

VIZENGINE_API void        _api__gfxchannel_set_current_camera(int object_id, int camera);
VIZENGINE_API void        _api__gfxchannel_get_current_camera(int object_id, int *camera);


// Image Channel
VIZENGINE_API bool        _api__image_channel_is_valid(int object_id);


// Super Channel
VIZENGINE_API bool        _api__super_channel_is_valid(int object_id);
VIZENGINE_API bool        _api__super_channel_toggle(int object_id);
VIZENGINE_API bool        _api__super_channel_get_playing(int object_id, int& proxy_id);
VIZENGINE_API bool        _api__super_channel_get_pending(int object_id, int& proxy_id);
VIZENGINE_API bool        _api__super_channel_get_a(int object_id, int& proxy_id);
VIZENGINE_API bool        _api__super_channel_get_b(int object_id, int& proxy_id);

VIZENGINE_API bool        _api__super_channel_get_transition_auto_mode(int object_id);
VIZENGINE_API bool        _api__super_channel_set_transition_auto_mode(int object_id, bool automatic);

VIZENGINE_API bool        _api__super_channel_get_ab_transition_manual(int object_id, int& director_id);
VIZENGINE_API bool        _api__super_channel_set_ab_transition_manual(int object_id, int director_id);
VIZENGINE_API bool        _api__super_channel_get_ab_transition(int object_id, int& director_id);
VIZENGINE_API bool        _api__super_channel_get_ab_transition_reverse(int object_id);
VIZENGINE_API bool        _api__super_channel_set_ab_transition_reverse(int object_id, bool reverse);

VIZENGINE_API bool        _api__super_channel_get_ba_transition_manual(int object_id, int& director_id);
VIZENGINE_API bool        _api__super_channel_set_ba_transition_manual(int object_id, int director_id);
VIZENGINE_API bool        _api__super_channel_get_ba_transition(int object_id, int& director_id);
VIZENGINE_API bool        _api__super_channel_get_ba_transition_reverse(int object_id);
VIZENGINE_API bool        _api__super_channel_set_ba_transition_reverse(int object_id, bool reverse);


// Proxy Channel
VIZENGINE_API bool        _api__proxy_channel_is_valid(int object_id);
VIZENGINE_API bool        _api__proxy_channel_set_object(int object_id, const char *location);
VIZENGINE_API int         _api__proxy_channel_get_wrapped_channel_vizid(int object_id, int *vizid);
VIZENGINE_API int         _api__proxy_channel_get_wrapped_channel_type(int object_id, const char ** type);

// Set channel relative position in percent
VIZENGINE_API int _api__proxy_channel_set_position(int object_id, float x, float y);

// Get channel relative position in percent
VIZENGINE_API int _api__proxy_channel_get_position(int object_id, float* x, float* y);

// Set channel relative size in percent
VIZENGINE_API int _api__proxy_channel_set_size(int object_id, float x, float y);

// Get channel relative size in percent
VIZENGINE_API int _api__proxy_channel_get_size(int object_id, float* x, float* y);

// Set channel relative center in percent
VIZENGINE_API int _api__proxy_channel_set_center(int object_id, float x, float y);

// Get channel relative center in percent
VIZENGINE_API int _api__proxy_channel_get_center(int object_id, float* x, float* y);

// Set channel relative crop in percent
VIZENGINE_API int _api__proxy_channel_set_crop(int object_id, float left, float right, float top, float bottom);

// Get channel relative crop in percent
VIZENGINE_API int _api__proxy_channel_get_crop(int object_id, float* left, float* right, float* top, float* bottom);

// Set channel audio volume
VIZENGINE_API int _api__proxy_channel_set_audio_volume(int object_id, float v);

// Get channel audio volume
VIZENGINE_API int _api__proxy_channel_get_audio_volume(int object_id, float *v);

// Set channel alpha
VIZENGINE_API int _api__proxy_channel_set_alpha(int object_id, float v);

// Get channel alpha
VIZENGINE_API int _api__proxy_channel_get_alpha(int object_id, float *v);

//Set channel content relative position in percent
VIZENGINE_API int _api__proxy_channel_content_set_position(int object_id, float x, float y);

// Get channel content relative position in percent
VIZENGINE_API int _api__proxy_channel_content_get_position(int object_id, float* x, float* y);

// Set channel content center in percent
VIZENGINE_API int _api__proxy_channel_content_set_center(int object_id, float x, float y);

// Get channel content center in percent
VIZENGINE_API int _api__proxy_channel_content_get_center(int object_id, float* x, float* y);

// Set channel content size in percent
VIZENGINE_API int _api__proxy_channel_content_set_size(int object_id, float x, float y);

// Get channel content size in percent
VIZENGINE_API int _api__proxy_channel_content_get_size(int object_id, float* x, float* y);

// Set channel content relative crop in percent
VIZENGINE_API int _api__proxy_channel_content_set_crop(int object_id, float left, float right, float top, float bottom);

// Get channel content relative crop in percent
VIZENGINE_API int _api__proxy_channel_content_get_crop(int object_id, float* left, float* right, float* top, float* bottom);

// Set channel content zoom mode
VIZENGINE_API int _api__proxy_channel_content_set_zoom_mode(int object_id, int mode);

// Get channel content zoom mode
VIZENGINE_API int _api__proxy_channel_content_get_zoom_mode(int object_id, int* mode);

// Set channel content border color
VIZENGINE_API int _api__proxy_channel_content_set_border_color(int object_id, float r, float g, float b, float a);

// Get channel content border color
VIZENGINE_API int _api__proxy_channel_content_get_border_color(int object_id, float* r, float* g, float* b, float* a);

// Set channel content border color
VIZENGINE_API int _api__proxy_channel_content_set_border_color(int object_id, float r, float g, float b, float a);

// Clip Channel
VIZENGINE_API int         _api__clip_channel_get_number_of_clip_channels();
VIZENGINE_API int         _api__clip_channel_get_number_of_clip_channels_active();
VIZENGINE_API bool        _api__clip_channel_is_valid_channel(int iChannelID);
VIZENGINE_API bool        _api__clip_channel_get_pending_clip_supported(int iChannelID);
VIZENGINE_API bool        _api__clip_channel_is_clip_loaded( int iChannelID, const char* rClipName );
VIZENGINE_API bool        _api__clip_channel_is_clip_loaded_active( int iChannelID, const char* rClipName );
VIZENGINE_API bool        _api__clip_channel_is_clip_loaded_pending( int iChannelID, const char* rClipName );
VIZENGINE_API void        _api__clip_channel_set_clip_name_ex(int, const char* rClipName, uint64_t uiFrameIn, uint64_t uiFrameOut, bool bAutoPlay );
VIZENGINE_API void        _api__clip_channel_set_clip_name(int, const char* rClipName);
VIZENGINE_API void        _api__clip_channel_set_clip_name_pending_ex(int, const char* rClipName, uint64_t uiFrameIn, uint64_t uiFrameOut, bool bAutoPlay );
VIZENGINE_API void        _api__clip_channel_set_clip_name_pending(int, const char* rClipName);
VIZENGINE_API void        _api__clip_channel_swap_Pending(int);
VIZENGINE_API void        _api__clip_channel_swap_eof_pending(int);
VIZENGINE_API void        _api__clip_channel_set_clip_name_back2back_ex(int, const char* rClipName, uint64_t uiFrameIn, uint64_t uiFrameOut, bool bAutoPlay );
VIZENGINE_API void        _api__clip_channel_set_clip_name_back2back(int, const char* rClipName);
VIZENGINE_API void        _api__clip_channel_get_clip_name(int, const char** rClipName);
VIZENGINE_API void        _api__clip_channel_get_clip_name_active(int, const char** rClipName);
VIZENGINE_API void        _api__clip_channel_get_clip_name_pending(int, const char** rClipName);
VIZENGINE_API void        _api__clip_channel_cmd_play(int, uint64_t uiFrameIn);
VIZENGINE_API void        _api__clip_channel_cmd_play_active(int, uint64_t uiFrameIn);
VIZENGINE_API void        _api__clip_channel_cmd_play_pending(int, uint64_t uiFrameIn);
VIZENGINE_API void        _api__clip_channel_cmd_scrub(int, uint64_t uiFrameIn);
VIZENGINE_API void        _api__clip_channel_cmd_scrub_active(int, uint64_t uiFrameIn);
VIZENGINE_API void        _api__clip_channel_cmd_scrub_pending(int, uint64_t uiFrameIn);
VIZENGINE_API void        _api__clip_channel_cmd_pause(int);
VIZENGINE_API void        _api__clip_channel_cmd_pause_active(int);
VIZENGINE_API void        _api__clip_channel_cmd_pause_pending(int);
VIZENGINE_API void        _api__clip_channel_cmd_continue(int);
VIZENGINE_API void        _api__clip_channel_cmd_continue_active(int);
VIZENGINE_API void        _api__clip_channel_cmd_continue_pending(int);
VIZENGINE_API void        _api__clip_channel_cmd_stop(int);
VIZENGINE_API void        _api__clip_channel_cmd_stop_active(int);
VIZENGINE_API void        _api__clip_channel_cmd_stop_pending(int);
VIZENGINE_API void        _api__clip_channel_cmd_flush(int);
VIZENGINE_API void        _api__clip_channel_cmd_flush_active(int);
VIZENGINE_API void        _api__clip_channel_cmd_flush_pending(int);
VIZENGINE_API double      _api__clip_channel_get_playback_speed(int);
VIZENGINE_API double      _api__clip_channel_get_playback_speed_active(int);
VIZENGINE_API double      _api__clip_channel_get_playback_speed_pending(int);
VIZENGINE_API void        _api__clip_channel_set_playback_speed(int, double);
VIZENGINE_API void        _api__clip_channel_set_playback_speed_active(int, double);
VIZENGINE_API void        _api__clip_channel_set_playback_speed_pending(int, double);
VIZENGINE_API bool        _api__clip_channel_get_loop_mode(int);
VIZENGINE_API bool        _api__clip_channel_get_loop_mode_active(int);
VIZENGINE_API bool        _api__clip_channel_get_loop_mode_pending(int);
VIZENGINE_API void        _api__clip_channel_set_loop_mode(int, bool);
VIZENGINE_API void        _api__clip_channel_set_loop_mode_active(int, bool);
VIZENGINE_API void        _api__clip_channel_set_loop_mode_pending(int, bool);
VIZENGINE_API int         _api__clip_channel_get_repeat_mode(int);
VIZENGINE_API int         _api__clip_channel_get_repeat_mode_active(int);
VIZENGINE_API int         _api__clip_channel_get_repeat_mode_pending(int);
VIZENGINE_API void        _api__clip_channel_set_repeat_mode(int, int);
VIZENGINE_API void        _api__clip_channel_set_repeat_mode_active(int, int);
VIZENGINE_API void        _api__clip_channel_set_repeat_mode_pending(int, int);
VIZENGINE_API bool        _api__clip_channel_get_reversefields(int);
VIZENGINE_API bool        _api__clip_channel_get_reversefields_active(int);
VIZENGINE_API bool        _api__clip_channel_get_reversefields_pending(int);
VIZENGINE_API void        _api__clip_channel_set_reversefields(int, bool);
VIZENGINE_API void        _api__clip_channel_set_reversefields_active(int, bool);
VIZENGINE_API void        _api__clip_channel_set_reversefields_pending(int, bool);
VIZENGINE_API bool        _api__clip_channel_get_upscaleluma(int);
VIZENGINE_API bool        _api__clip_channel_get_upscaleluma_active(int);
VIZENGINE_API bool        _api__clip_channel_get_upscaleluma_pending(int);
VIZENGINE_API void        _api__clip_channel_set_upscaleluma(int, bool);
VIZENGINE_API void        _api__clip_channel_set_upscaleluma_active(int, bool);
VIZENGINE_API void        _api__clip_channel_set_upscaleluma_pending(int, bool);
VIZENGINE_API uint64_t    _api__clip_channel_get_framein(int);
VIZENGINE_API uint64_t    _api__clip_channel_get_framein_active(int);
VIZENGINE_API uint64_t    _api__clip_channel_get_framein_pending(int);
VIZENGINE_API void        _api__clip_channel_set_framein(int, uint64_t);
VIZENGINE_API void        _api__clip_channel_set_framein_active(int, uint64_t);
VIZENGINE_API void        _api__clip_channel_set_framein_pending(int, uint64_t);
VIZENGINE_API uint64_t    _api__clip_channel_get_frameout(int);
VIZENGINE_API uint64_t    _api__clip_channel_get_frameout_active(int);
VIZENGINE_API uint64_t    _api__clip_channel_get_frameout_pending(int);
VIZENGINE_API void        _api__clip_channel_set_frameout(int, uint64_t);
VIZENGINE_API void        _api__clip_channel_set_frameout_active(int, uint64_t);
VIZENGINE_API void        _api__clip_channel_set_frameout_pending(int, uint64_t);
VIZENGINE_API void        _api__clip_channel_set_frameinout(int, uint64_t, uint64_t);
VIZENGINE_API void        _api__clip_channel_set_frameinout_active(int, uint64_t, uint64_t);
VIZENGINE_API void        _api__clip_channel_set_frameinout_pending(int, uint64_t, uint64_t);
VIZENGINE_API bool        _api__clip_channel_get_autorun(int);
VIZENGINE_API void        _api__clip_channel_set_autorun(int, bool);
VIZENGINE_API int         _api__clip_channel_get_modeonloaderror(int);
VIZENGINE_API void        _api__clip_channel_set_modeonloaderror(int, int);
VIZENGINE_API uint64_t    _api__clip_channel_get_duration(int);
VIZENGINE_API uint64_t    _api__clip_channel_get_duration_pending(int);
VIZENGINE_API uint64_t    _api__clip_channel_get_current_frame(int);
VIZENGINE_API uint64_t    _api__clip_channel_get_current_frame_pending(int);
VIZENGINE_API int         _api__clip_channel_get_current_mode(int);
VIZENGINE_API int         _api__clip_channel_get_current_mode_pending(int);
VIZENGINE_API void        _api__clip_channel_get_report_values( int iChannelID, uint64_t &uiDuration, uint64_t &uiCurrentFrame, int &iCurrentMode );
VIZENGINE_API void        _api__clip_channel_get_report_values_pending( int iChannelID, uint64_t &uiDuration, uint64_t &uiCurrentFrame, int &iCurrentMode );
VIZENGINE_API double      _api__clip_channel_convert_frames_to_seconds( int iChannelID, uint64_t );
VIZENGINE_API uint64_t    _api__clip_channel_convert_seconds_to_frames( int iChannelID, double );
VIZENGINE_API double      _api__clip_get_frames_per_second( int iChannelID );
VIZENGINE_API bool        _api__clip_is_interlaced(int iChannelID);
VIZENGINE_API int         _api__clip_get_clip_name_absolute(const char* rClipName, char * outBuffer, size_t outBufferBytes);
VIZENGINE_API void        _api__clip_set_loop_in_frame(int iChannelID, uint64_t uiLoopInFrame);
VIZENGINE_API uint64_t    _api__clip_get_loop_in_frame(int iChannelID);
VIZENGINE_API void        _api__clip_set_loop_out_frame(int iChannelID, uint64_t uiLoopOutFrame);
VIZENGINE_API uint64_t    _api__clip_get_loop_out_frame(int iChannelID);
VIZENGINE_API void        _api__clip_set_loop_count(int iChannelID, int iLoopCount);
VIZENGINE_API int         _api__clip_get_loop_count(int iChannelID);
VIZENGINE_API void        _api__clip_set_next_cue_is_instant(bool bInstant);

VIZENGINE_API void        _api__clip_animation_loop_stop(int iChannelID);
VIZENGINE_API void        _api__clip_animation_loop_flush(int iChannelID);
VIZENGINE_API void        _api__clip_animation_stage_scrub(int iChannelID, uint64_t uiFrame);
VIZENGINE_API bool        _api__clip_animation_loop_configured(int iChannelID);

VIZENGINE_API int         _api__clip_queue_list(int iChannelID, char * outBuffer, size_t outBufferBytes);
VIZENGINE_API void        _api__clip_queue_insert(int iChannelID, const char* rClipName, uint64_t uiFrameIn, uint64_t uiFrameOut, bool bAutoStart, int iPosition);
VIZENGINE_API void        _api__clip_queue_replace(int iChannelID, const char* rClipName, uint64_t uiFrameIn, uint64_t uiFrameOut, bool bAutoStart, int iPosition);
VIZENGINE_API void        _api__clip_queue_delete(int iChannelID, int iPosition);
VIZENGINE_API void        _api__clip_queue_move(int iChannelID, int iSource, int iTarget);
VIZENGINE_API void        _api__clip_queue_flush(int iChannelID);

VIZENGINE_API int         _api__clip_queue_list_pending(int iChannelID, char * outBuffer, size_t outBufferBytes);
VIZENGINE_API void        _api__clip_queue_insert_pending(int iChannelID, const char* rClipName, uint64_t uiFrameIn, uint64_t uiFrameOut, bool bAutoStart, int iPosition);
VIZENGINE_API void        _api__clip_queue_replace_pending(int iChannelID, const char* rClipName, uint64_t uiFrameIn, uint64_t uiFrameOut, bool bAutoStart, int iPosition);
VIZENGINE_API void        _api__clip_queue_delete_pending(int iChannelID, int iPosition);
VIZENGINE_API void        _api__clip_queue_move_pending(int iChannelID, int iSource, int iTarget);
VIZENGINE_API void        _api__clip_queue_flush_pending(int iChannelID);

VIZENGINE_API int         _api__clip_request_clip_status(int iChannelID, char * outBuffer, size_t outBufferBytes);

VIZENGINE_API void        _api__clip_channel_get_register_mode_changed_key(int iChannelID, const char** rShmKey );
VIZENGINE_API void        _api__clip_channel_get_register_mode_changed_key_pending(int iChannelID, const char** rShmKey );
VIZENGINE_API void        _api__clip_channel_set_register_mode_changed_key(int iChannelID, const char* rShmKey );
VIZENGINE_API void        _api__clip_channel_set_register_mode_changed_key_pending(int iChannelID, const char* rShmKey );
VIZENGINE_API void        _api__clip_channel_get_register_frame_changed_key(int iChannelID, const char** rShmKey );
VIZENGINE_API void        _api__clip_channel_set_register_frame_changed_key(int iChannelID, const char* rShmKey );
VIZENGINE_API void        _api__clip_channel_get_register_player_status_key(int iChannelID, const char** rShmKey );
VIZENGINE_API void        _api__clip_channel_set_register_player_status_key(int iChannelID, const char* rShmKey );

VIZENGINE_API void        _api__clip_channel_set_pos_x(int iChannelID, double dPosX);
VIZENGINE_API double      _api__clip_channel_get_pos_x(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_pos_y(int iChannelID, double dPosY);
VIZENGINE_API double      _api__clip_channel_get_pos_y(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_width(int iChannelID, double dWidth);
VIZENGINE_API double      _api__clip_channel_get_width(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_height(int iChannelID, double dHeight);
VIZENGINE_API double      _api__clip_channel_get_height(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_crop_left(int iChannelID, double dCropLeft);
VIZENGINE_API double      _api__clip_channel_get_crop_left(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_crop_right(int iChannelID, double dCropRight);
VIZENGINE_API double      _api__clip_channel_get_crop_right(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_crop_top(int iChannelID, double dCropTop);
VIZENGINE_API double      _api__clip_channel_get_crop_top(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_crop_bottom(int iChannelID, double dCropBottom);
VIZENGINE_API double      _api__clip_channel_get_crop_bottom(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_alpha(int iChannelID, double dAlpha);
VIZENGINE_API double      _api__clip_channel_get_alpha(int iChannelID);
VIZENGINE_API void        _api__clip_channel_set_master_volume(int iChannelID, double volume);
VIZENGINE_API double      _api__clip_channel_get_master_volume(int iChannelID);


// live channel
VIZENGINE_API int         _api__clip_channel_get_number_of_live_channels();
VIZENGINE_API int         _api__clip_channel_get_number_of_live_channels_active();
VIZENGINE_API bool        _api__live_channel_is_valid_channel(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_pos_x(int iChannelID, double dPosX);
VIZENGINE_API double      _api__live_channel_get_pos_x(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_pos_y(int iChannelID, double dPosY);
VIZENGINE_API double      _api__live_channel_get_pos_y(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_width(int iChannelID, double dWidth);
VIZENGINE_API double      _api__live_channel_get_width(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_height(int iChannelID, double dHeight);
VIZENGINE_API double      _api__live_channel_get_height(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_crop_left(int iChannelID, double dCropLeft);
VIZENGINE_API double      _api__live_channel_get_crop_left(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_crop_right(int iChannelID, double dCropRight);
VIZENGINE_API double      _api__live_channel_get_crop_right(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_crop_top(int iChannelID, double dCropTop);
VIZENGINE_API double      _api__live_channel_get_crop_top(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_crop_bottom(int iChannelID, double dCropBottom);
VIZENGINE_API double      _api__live_channel_get_crop_bottom(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_alpha(int iChannelID, double dAlpha);
VIZENGINE_API double      _api__live_channel_get_alpha(int iChannelID);
VIZENGINE_API void        _api__live_channel_set_master_volume(int iChannelID, double volume);
VIZENGINE_API double      _api__live_channel_get_master_volume(int iChannelID);


// TOUCH
VIZENGINE_API int         _api__touch_get_valid(unsigned int iTraceID, unsigned int iTouchIndex, bool& bValid);
VIZENGINE_API int         _api__touch_get_event(unsigned int iTraceID, unsigned int iTouchIndex, int& iEvent);
VIZENGINE_API int         _api__touch_get_xy(unsigned int iTraceID, unsigned int iTouchIndex, double& dX, double& dY);
VIZENGINE_API int         _api__touch_get_xy_undeformed(unsigned int iTraceID, unsigned int iTouchIndex, double& dX, double& dY);
VIZENGINE_API int         _api__touch_get_pressure(unsigned int iTraceID, unsigned int iTouchIndex, double& dPressure);
VIZENGINE_API int         _api__touch_get_direction(unsigned int iTraceID, unsigned int iTouchIndex, evVertex3D& v3dDir);
VIZENGINE_API int         _api__touch_get_timestamp(unsigned int iTraceID, unsigned int iTouchIndex, double& dTimestamp);

// TRACE
VIZENGINE_API int         _api__trace_get_valid(unsigned int iTraceID, bool& bValid);
VIZENGINE_API int         _api__trace_get_last_touch(unsigned int iTraceID, unsigned int& iTouchIndex);
VIZENGINE_API int         _api__trace_get_touch_count(unsigned int iTraceID, unsigned int& iTouchCount);
VIZENGINE_API int         _api__trace_get_touch(unsigned int iTraceID, unsigned int iTouchIndex);
VIZENGINE_API int         _api__trace_get_source(unsigned int iTraceID, unsigned int& iSource);
VIZENGINE_API int         _api__trace_get_type(unsigned int iTraceID, unsigned int& iType, unsigned int& iSubType);

// GESTURE_RECOGNIZER
VIZENGINE_API int         _api__gesture_recognizer_construct(unsigned int& iRecognizerID);
VIZENGINE_API int         _api__gesture_recognizer_destruct(unsigned int iRecognizerID);
VIZENGINE_API int         _api__gesture_recognizer_copy(unsigned int iRecognizerID);
VIZENGINE_API int         _api__gesture_recognizer_get_valid(unsigned int iRecognizerID, bool& bValid);
VIZENGINE_API int         _api__gesture_recognizer_get_active(unsigned int iRecognizerID, bool& bActive);
VIZENGINE_API int         _api__gesture_recognizer_set_active(unsigned int iRecognizerID, bool bActive);
VIZENGINE_API int         _api__gesture_recognizer_get_handle_patterns(unsigned int iRecognizerID, bool& bHandle);
VIZENGINE_API int         _api__gesture_recognizer_set_handle_patterns(unsigned int iRecognizerID, bool bHandle);
VIZENGINE_API int         _api__gesture_recognizer_get_handle_taps(unsigned int iRecognizerID, bool& bHandle);
VIZENGINE_API int         _api__gesture_recognizer_set_handle_taps(unsigned int iRecognizerID, bool bHandle);
VIZENGINE_API int         _api__gesture_recognizer_add_trace(unsigned int iRecognizerID, unsigned int iTraceID);
VIZENGINE_API int         _api__gesture_recognizer_remove_trace(unsigned int iRecognizerID, unsigned int iTraceID);
VIZENGINE_API int         _api__gesture_recognizer_add_handler(unsigned int iRecognizerID, int iObjectID);
VIZENGINE_API int         _api__gesture_recognizer_remove_handler(unsigned int iRecognizerID, int iObjectID);
VIZENGINE_API int         _api__gesture_recognizer_get_check_pattern_orientation(unsigned int iRecognizerID, bool& bCheck);
VIZENGINE_API int         _api__gesture_recognizer_set_check_pattern_orientation(unsigned int iRecognizerID, bool bCheck);

// GESTURE
VIZENGINE_API int         _api__gesture_get_valid(unsigned int iGestureID, bool& bValid);
VIZENGINE_API int         _api__gesture_get_pattern_id(unsigned int iGestureID, unsigned int& iPatternID);
VIZENGINE_API int         _api__gesture_get_recognizer(unsigned int iGestureID, unsigned int& iRecognizerID);

// AUDIO
VIZENGINE_API int _api__audio_alloc_plugin_track(int* trackId);
VIZENGINE_API int _api__audio_free_plugin_track(int trackId);
VIZENGINE_API int _api__audio_send_plugin_buffer(int trackId, int retrace, void *buffer);
VIZENGINE_API int _api__audio_get_live_channel_volume(int liveInput, int channel, float *volume);
VIZENGINE_API int _api__audio_set_live_channel_volume(int liveInput, int channel, float volume);

// save a snapshot
VIZENGINE_API int _api__save_snapshot( char const * uri, int width, int height, GLenum format, void const * buffer, size_t size );

// SUBSTANCE
VIZENGINE_API int _api__get_substance_data(int iObjectID, const unsigned char ** data, int * dataSize);
VIZENGINE_API int _api__get_substance_location(int iObjectID, char **value);
VIZENGINE_API int _api__get_substance_objectid(const char* location);


// Container Mesh
VIZENGINE_API void* _api__container_geometry_construct(int containerID);
VIZENGINE_API void  _api__container_geometry_destruct(void* mesh);
VIZENGINE_API int   _api__container_geometry_nbVertices(void* mesh);
VIZENGINE_API int   _api__container_geometry_nbIndices(void* mesh);
VIZENGINE_API float* _api__container_geometry_vertices(void* mesh);
VIZENGINE_API unsigned int* _api__container_geometry_indices(void* mesh);

#ifdef __cplusplus
}    // extern "C"
#endif

#endif    // !__API_FUNCTIONS_H__
