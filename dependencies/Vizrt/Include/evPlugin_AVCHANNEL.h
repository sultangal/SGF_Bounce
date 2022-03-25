#ifndef EV_PLUGIN_AVCHANNEL_H
#define EV_PLUGIN_AVCHANNEL_H

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

class evVertex2D;

enum class eContentZoomMode : int { Original, ScaleToFill, ScaleToFit_Max, ScaleToFit_Min, Undefined };

/**
 * @brief      { Base class for all audio video related channels }
 */
class AVCHANNEL : public BASE
{
public:
    /**
     * @brief      Determines if this channel is valid.
     *
     * @return     True if valid, False otherwise.
     */
    virtual bool is_valid();

    /**
     * @brief      Gets the position.
     *
     * @param[out] x     { x position }
     * @param[out] y     { y position }
     */
    void get_position(float *x, float *y);

    /**
     * @brief      Sets the position.
     *
     * @param[in]  x     { x position }
     * @param[in]  y     { y position }
     */
    void set_position(float x, float y);

    /**
     * @brief      Gets the screen position.
     *
     * @param[out] x     { x position }
     * @param[out] y     { y position }
     */
    void get_screen_position(float *x, float *y);
    /**
     * @brief      Sets the screen position.
     *
     * @param[in]  x     { x position }
     * @param[in]  y     { y position }
     */
    void set_screen_position(float x, float y);

    /**
     * @brief      Gets the center.
     *
     * @param[out] x     { x center }
     * @param[out] y     { y center }
     */
    void get_center(float *x, float *y);

    /**
     * @brief      Sets the center.
     *
     * @param[in]  x     { x center }
     * @param[in]  y     { y center }
     */
    void set_center(float x, float y);

    /**
     * @brief      Gets the screen center.
     *
     * @param[out] x     { x center }
     * @param[out] y     { y center }
     */
    void get_screen_center(float *x, float *y);

    /**
     * @brief      Sets the screen center.
     *
     * @param[in]  x     { x center }
     * @param[in]  y     { y center }
     */
    void set_screen_center(float x, float y);

    /**
     * @brief      Gets the size.
     *
     * @param[out] width   The width
     * @param[out] height  The height
     */
    void get_size(float *width, float *height);

    /**
     * @brief      Sets the size.
     *
     * @param[in]  width   The width
     * @param[in]  height  The height
     */
    void set_size(float width, float height);

    /**
     * @brief      Gets the screen size.
     *
     * @param[out] width   The width
     * @param[out] height  The height
     */
    void get_screen_size(float *width, float *height);

    /**
     * @brief      Sets the screen size.
     *
     * @param[in]  width   The width
     * @param[in]  height  The height
     */
    void set_screen_size(float width, float height);

    /**
     * @brief      Gets the crop.
     *
     * @param[out] left    The left
     * @param[out] right   The right
     * @param[out] top     The top
     * @param[out] bottom  The bottom
     */
    void get_crop(float *left, float *right, float *top, float *bottom);

    /**
     * @brief      Sets the crop.
     *
     * @param[in]  left    The left
     * @param[in]  right   The right
     * @param[in]  top     The top
     * @param[in]  bottom  The bottom
     */
    void set_crop(float left, float right, float top, float bottom);

    /**
     * @brief      Gets the screen crop.
     *
     * @param[out] left    The left
     * @param[out] right   The right
     * @param[out] top     The top
     * @param[out] bottom  The bottom
     */
    void get_screen_crop(float *left, float *right, float *top, float *bottom);

    /**
     * @brief      Sets the screen crop.
     *
     * @param[in]  left    The left
     * @param[in]  right   The right
     * @param[in]  top     The top
     * @param[in]  bottom  The bottom
     */
    void set_screen_crop(float left, float right, float top, float bottom);

    /**
     * @brief      Gets the alpha.
     *
     * @param[out] alpha  The alpha
     */
    void get_alpha(float *alpha);

    /**
     * @brief      Sets the alpha.
     *
     * @param[in]  alpha  The alpha from 0 to 1.0
     */
    void set_alpha(float alpha);

    /**
     * @brief      Gets the master audio volume.
     *
     * @param[out] volume  The volume in percent (1.0 == 100%, range >= 0.0)
     */
    void get_master_volume(float *volume);

    /**
     * @brief      Sets the master audio volume.
     *
     * @param[in]  volume  The volume in percent (1.0 == 100%, range >= 0.0)
     */
    void set_master_volume(float volume);

    /**
     * @brief      Gets the channel volume.
     *
     * @param[in]  audio_channel  The audio channel
     * @param[out] volume         The volume in percent (1.0 == 100%, range >= 0.0)
     */
    void get_channel_volume(int audio_channel, float *volume);

    /**
     * @brief      Sets the channel volume.
     *
     * @param[in]  audio_channel  The audio channel
     * @param[in]  volume         The volume in percent (1.0 == 100%, range >= 0.0)
     */
    void set_channel_volume(int audio_channel, float volume);

    /**
     * @brief      Gets if force key is enabled.
     *
     * @param[out] force_key  The force key
     */
    void get_force_key(bool *force_key);

    /**
     * @brief      Sets if force key is enabled.
     *
     * @param[in]  force_key  The force key
     */
    void set_force_key(bool force_key);

    /**
     * @brief      Gets if keep aspect is enabled.
     *
     * @param[out] keep_aspect  The keep aspect
     */
    void get_keep_aspect(bool *keep_aspect);

    /**
     * @brief      Sets if keep aspect is enabled.
     *
     * @param[in]  keep_aspect  The keep aspect
     */
    void set_keep_aspect(bool keep_aspect);

    /**
     * @brief      Gets if controlled animation is enabled.
     *
     * @param[out] controlled_animation  The controlled animation
     */
    void get_controlled_animation(bool *controlled_animation);

    /**
     * @brief      Sets if controlled animation is enabled.
     *
     * @param[in]  controlled_animation  The controlled animation
     */
    void set_controlled_animation(bool controlled_animation);

    /*! @brief Set content relative position in percent
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_set_position(const evVertex2D& position);

    /*! @brief Get content relative position in percent
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_get_position(evVertex2D& position);

    /*! @brief Set content center in percent
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_set_center(const evVertex2D& position);

    /*! @brief Get content center in percent
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_get_center(evVertex2D& position);

    /*! @brief Set content size in percent
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_set_size(const evVertex2D& position);

    /*! @brief Get content size in percent
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_get_size(evVertex2D& position);

    /*! @brief Set content relative crop in percent
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_set_crop(float left, float right, float top, float bottom);

    /*! @brief Get content relative crop in percent
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_get_crop(float& left, float& right, float& top, float& bottom);

    /*! @brief Set content zoom mode
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_set_zoom_mode(eContentZoomMode zoomMode);

    /*! @brief Get content zoom mode
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_get_zoom_mode(eContentZoomMode& zoomMode);

    /*! @brief Set content border color
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_set_border_color(float r, float g, float b, float a);

    /*! @brief Get content border color
    *
    * @return false if failed

    * @todo documentation to be done.
    */
    bool content_get_border_color(float& r, float& g, float& b, float& a);
};

#endif