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

#ifndef __evDevice_h__
#define __evDevice_h__

enum EDeviceCMD {
    EVD_TYPE_REQUEST = 1,
    EVD_STOP,
    EVD_PLAY,
    EVD_PLAY_REV,
    EVD_RECORD,
    EVD_EJECT,
    EVD_FAST_FORWARD,
    EVD_JOG_FORWARD,
    EVD_FAST_REWIND,
    EVD_JOG_REWIND,
    EVD_PREROLL,
    EVD_CUE,
    EVD_IN_ENTRY,
    EVD_OUT_ENTRY,
    EVD_INC_FRAME,
    EVD_DEC_FRAME,
    EVD_TIMECODE_SENSE,
    EVD_STOP_NODELAY,
    EVD_PLAY_NODELAY,
    EVD_CUE_NODELAY,
    EVD_SET_CURRENT_CLIP,
    EVD_GET_CURRENT_CLIP,
    EVD_GET_FIRST_GROUP,
    EVD_GET_NEXT_GROUP,
    EVD_GET_FIRST_CLIP,
    EVD_GET_NEXT_CLIP,
    EVD_CAPABILITIES_REQUEST,
    EVD_CLIP_CREATE,
    EVD_CLIP_DELETE,
    EVD_CLIP_CLEAR,
    EVD_CLIP_EXISTS,
    EVD_RECORD_FIELD,
    EVD_RECORD_DONE,
    EVD_GET_NUMBER_OF_COMPONENS,
    EVD_CHECK_IMAGE_SIZE,
    EVD_GET_NUMBER_OF_CHANNELS,
    EVD_GET_IMAGE_DATA,
    EVD_GET_CLIPINFO,
    EVD_GET_PRE_ROLL,
    EVD_RECORD_NODELAY,
    EVD_EDIT_ON,
    EVD_EDIT_ON_NODELAY,
    EVD_EDIT_OFF,
    EVD_EDIT_OFF_NODELAY,
    EVD_EDIT_PRESET,
    EVD_GET_EDIT_ON_DELAY,
    EVD_GET_ANIMATION_PREROLL,
    EVD_GET_POST_PLAY_DELAY,
    EVD_GET_PRE_ANIMATION_DELAY,
    EVD_GET_EDIT_OFF_DELAY,

    EVD_PLAY_PRESET = 60,
    EVD_PLAY_PRESET_BACK,
    EVD_PLAY_PRESET_LOOP,
    EVD_PLAY_PRESET_SWING,
    EVD_STOP_PRESET_ONCE,
    EVD_STOP_PRESET_LOOP
};

enum EDeviceCapability {
    EVD_CAP_CLIP = 0x01,                    // can handle clips
    EVD_CAP_CLIPLIST = 0x02,                // can browse cliplists
    EVD_CAP_DELETE = 0x04,                  // can delete clips
    EVD_CAP_PLAY = 0x08,                    // has a play mode
    EVD_CAP_FIELD_RECORD = 0x10,            // able to record fields
    EVD_CAP_REALTIME_PLAYBACK = 0x20,       // able to get realtime texture data
    EVD_CAP_TEXTURE_PLAYBACK = 0x40,        // able to get texture data for clips
    EVD_CAP_REALTIME_RECORD = 0x80,         // able to record
    EVD_CAP_FRAME_FORMAT_PROGRESSIVE = 0x100,// frame formats
    EVD_CAP_FRAME_FORMAT_INT_F1 = 0x200,
    EVD_CAP_FRAME_FORMAT_INT_F2 = 0x400,
    EVD_CAP_DATA_FORMAT_RGB = 0x800,        // data formats
    EVD_CAP_DATA_FORMAT_RGBA = 0x1000
};

#define FIELD_1_DOMINANT                    1
#define FIELD_2_DOMINANT                    2
#define PROGRESSIVE_FRAME                   3

struct EVD_clipinfo
{
    const char* clipname;
    int         no_frames;
    int         width;
    int         height;
    int         texture_width;
    int         texture_height;
    int         components;
    int         field_dom;
    int         frame_rate;
    bool        restart;
    int*        subchannels;
#ifdef _WIN32
    bool operator== (const EVD_clipinfo &ci) const
        { return no_frames == ci.no_frames && width == ci.width && height == ci.height && texture_width == ci.texture_width &&
          texture_height == ci.texture_height && components == ci.components && field_dom == ci.field_dom &&
          ((clipname!=NULL && ci.clipname!=NULL && !strcmp (clipname, ci.clipname)) || clipname == ci.clipname) ||
            restart == ci.restart && subchannels == ci.subchannels; }
    bool operator!= (const EVD_clipinfo &ci) const
        { return !operator==(ci); }
#endif
};

struct EVD_fieldinfo
{
    int     fieldno;
    char*   data;
    int*    subchannels;
};

#endif
