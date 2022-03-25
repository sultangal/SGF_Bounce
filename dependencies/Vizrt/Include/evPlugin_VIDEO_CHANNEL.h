/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2006 PEAK software technologies GmbH                               *
 *  All Rights Reserved.                                                         *
 *                                                                               *
 *  This is PROPRIETARY SOURCE CODE of PEAK software technologies GmbH;          *
 *  the contents of this file may not be disclosed to third parties, copied or   *
 *  duplicated in any form, in whole or in part, without the prior written       *
 *  permission of PEAK software technologies GmbH                                *
 *                                                                               *
 * ============================================================================= */

/*  CAUTION:
 *  --------
 *  This file contains no user-modifiable data
 *  Under no circumstances change anything in this file without an
 *  explicit order from an employee of PEAK software technologies GmbH
 *
 */

#if ! defined( EV_PLUGIN_VIDEO_CHANNEL_H )
#define EV_PLUGIN_VIDEO_CHANNEL_H

#include "evPlugin_BASE.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class VIDEO_CHANNEL : public BASE
{
public:
    /*! @brief samples now
     *
     * @return ?

     * @As soon as the sampling is done PLUGIN_VIDEO_SAMPLING_FINISHED
     * will be called
     */
    int sample_now();

   /*! @brief set keyer sample parameters
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_keyer_sample_params(int x, int y, int width, int height);

   /*! @brief set keyer sample parameters
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_sample_uv_range_check_active(bool *active);

   /*! @brief set keyer sample parameters
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_sample_uv_range_check_active(bool active);

   /*! @brief set keyer sample parameters
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_sample_uv_range(float fURangeMin, float fURangeMax, float fVRangeMin, float fVRangeMax);

   /*! @brief set keyer sample parameters
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_sample_trustiness(float *pValue);

   /*! @brief get sample lum
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_sample_lum(float *pValue);

   /*! @brief set sample lum
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_sample_lum(float lum);

   /*! @brief get sample u
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_sample_u(float *pValue);

   /*! @brief set sample u
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_sample_u(float u);

   /*! @brief get sample v
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_sample_v(float *pValue);

   /*! @brief set sample v
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_sample_v(float v);

   /*! @brief get yuv texture target(ogl handle)
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_yuv_texture_target(int *pValue);
};


#endif // EV_PLUGIN_VIDEO_CHANNEL_H

