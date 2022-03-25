#ifndef EV_PLUGIN_GFXCHANNEL_H
#define EV_PLUGIN_GFXCHANNEL_H

/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2006,2015 Vizrt Austria GmbH                                       *
 *  All Rights Reserved.                                                         *
 *                                                                               *
 *  This is PROPRIETARY SOURCE CODE of Vizrt Austria GmbH;                       *
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

#include "evPlugin_BASE.h"
#include "evPlugin_AVCHANNEL.h"

/**
 * @brief      { This class represents a GFXChannel }
 */
class GFXCHANNEL : public AVCHANNEL
{
public:
    /**
     * @brief      Determines if valid.
     *
     * @return     True if valid, False otherwise.
     */
    bool  is_valid();

    /**
     * @brief      Sets the location of this GFX Channel.
     *
     * @param[in]  location  The location
     */
    void  set_object(const char *location);

    /**
     * @brief      Sets the local scene.
     *
     * @param[in]  scene_id  The scene identifier
     */
    void  set_local_scene(int scene_id);

    /**
     * @brief      Gets the local scene.
     *
     * @param[out] scene_id  The scene identifier
     */
    void  get_local_scene(int *scene_id);

    /**
     * @brief      Sets the current camera.
     *
     * @param[in]  camera  The camera
     */
    void  set_current_camera(int camera);

    /**
     * @brief      Gets the current camera.
     *
     * @param[out] camera  The camera
     */
    void  get_current_camera(int *camera);
};

#endif //EV_PLUGIN_GFXCHANNEL_H