/*! @file
    @brief this file is part of the viz pluginlib.
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

#if ! defined( EV_PLUGIN_VIEWPORT_TILE_H )
#define EV_PLUGIN_VIEWPORT_TILE_H

#include "evPlugin_BASE.h"
#include "evPlugin_IMAGE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


class VIEWPORT_TILE : public BASE
{
public:
    enum cropType
    {
        cropNone = 0,
        cropManual
    };

    enum sceneType
    {
        typeLocalScene = 0,
        typeOtherScene,
        typeMainLayer
    };

    /*
    Set/Get the scene for the viewport tile
    */
    int set_scene(SCENE scene);
    int set_scene(const char * pszScene);
    int get_scene(SCENE &scene);

    /*
    Set/Get camera id
    */
    int set_camera_id(int val);
    int get_camera_id(int *val);

    int get_scene_type(sceneType *val);
    int set_scene_type(sceneType val);

    /*
    Set/Get sub scene camera type and offsets option.
    */
    int set_use_camera_offsets(cropType val);
    int set_camera_offsets(float fWidth, float fHeight, float fPosX, float fPosY);

    int get_use_camera_offsets(cropType *val);
    int get_camera_offsets(float *fWidth, float *fHeight, float *fPosX, float *fPosY);
};

#endif