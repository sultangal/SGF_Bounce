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

#if ! defined( EV_PLUGIN_KEYFRAME_H )
#define EV_PLUGIN_KEYFRAME_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------

enum
{
    KEY_LOCK_MODE_LOCKED,
    KEY_LOCK_MODE_SINGLE,
    KEY_LOCK_MODE_MIRROR
};

enum
{
    KEY_HANDLE_MODE_SMOOTH,
    KEY_HANDLE_MODE_LINEAR,
    KEY_HANDLE_MODE_JUMP
};


enum
{
    KEYFRAME_TYPE_NONE,          /*!<  */
    KEYFRAME_TYPE_BOOL,          /*!<  */
    KEYFRAME_TYPE_INT,           /*!<  */
    KEYFRAME_TYPE_FLOAT,         /*!<  */
    KEYFRAME_TYPE_EVENT,         /*!<  */
    KEYFRAME_TYPE_ACTION,        /*!<  */
    KEYFRAME_TYPE_XYZ,           /*!<  */
    KEYFRAME_TYPE_COLOR,         /*!<  */
    KEYFRAME_TYPE_DEVICE,        /*!<  */
    KEYFRAME_TYPE_TARGA3200,     /*!<  */
    KEYFRAME_TYPE_SOUND,         /*!<  */
    KEYFRAME_TYPE_CGP_CLIP,      /*!<  */
    KEYFRAME_TYPE_PUSH_BUTTON,    /*!<  */
    KEYFRAME_TYPE_CLIP
};

enum
{
    AN_EVENT_STOP       = 0,
    AN_EVENT_NONE       = 2,
    AN_EVENT_PAUSE      = 3,
    AN_EVENT_LOCAL_STOP = 100
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_BASE : public BASE
{
public:
    int get_name(const char** keyframeName);
    int set_name(const char* keyframeName);

    int get_time(double* timeInSeconds);
    int set_time(double timeInSeconds);

    // The type of the keyframe (KEYFRAME_TYPE_NONE, KEYFRAME_TYPE_BOOL etc. see above)
    int get_type(int* keyType);

    int get_channel(CHANNEL& channel);

    // This will delete the keyframe.
    int clear();
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_HANDLE
{
public:
    KEYFRAME_HANDLE();
    int object_id; // object_id of the keyframe with this handle!
    int handle_id; // handle_id: 0 = regular handle, 1 = speed_handle

    int get_left_angle(float* leftAngleInDeg);
    int set_left_angle(float leftAngleInDeg);
    int get_right_angle(float* rightAngleInDeg);
    int set_right_angle(float rightAngleInDeg);
    int get_left_weight(float* leftWeightInDeg);
    int set_left_weight(float leftWeightInDeg);
    int get_right_weight(float* rightWeightInDeg);
    int set_right_weight(float rightWeightInDeg);

    // see enum KEY_HANDLE_MODE_SMOOTH, KEY_HANDLE_MODE_LINEAR, KEY_HANDLE_MODE_JUMP
    int get_left_mode(int* leftMode);
    int set_left_mode(int leftMode);
    int get_right_mode(int* rightMode);
    int set_right_mode(int rightMode);

    // see enum KEY_LOCK_MODE_LOCKED, KEY_LOCK_MODE_SINGLE, KEY_LOCK_MODE_MIRROR
    int get_lock_mode(int* lockMode);
    int set_lock_mode(int lockMode);
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_FLOAT : public KEYFRAME_BASE
{
public:
    int get(float* value);
    int set(float value);

    int get_handle(KEYFRAME_HANDLE& handle);
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_BOOL : public KEYFRAME_BASE
{
public:
    int get(int* value);
    int set(int value);
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_INT : public KEYFRAME_BASE
{
public:
    int get(int* value);
    int set(int value);
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_EVENT : public KEYFRAME_BASE
{
public:
    int get_value(int* value);
    int set_value(int value);
    int get_direction(int* direction);
    int set_direction(int direction);
    int get_duration(double* duration);
    int set_duration(double duration);
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_PUSH_BUTTON : public KEYFRAME_BASE
{
public:
    int get_direction(int* direction);
    int set_direction(int direction);
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_COLOR : public KEYFRAME_BASE
{
public:
    // Values are between [0-1]
    int get(float* r, float* g, float* b, float* a);
    int set(float r, float g, float b, float a);
};

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class KEYFRAME_XYZ : public KEYFRAME_BASE
{
public:
    int get(float* x, float* y, float* z);
    int set(float x, float y, float z);

    // handle_id: 0 = regular handle, 1 = speed_handle
    int get_handle(KEYFRAME_HANDLE& handle, int handle_id);

    // locks or unlocks the keyframe
    int set_locked(bool v);

    // determines whether the keyframe is locked or unlocked
    int is_locked(bool* v);
};



#endif // EV_PLUGIN_KEYFRAME_H
