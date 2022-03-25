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

#if ! defined( EV_PLUGIN_CAMERA_H )
#define EV_PLUGIN_CAMERA_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class VIZ_POSITION;
class CONTAINER;
class evMatrix;
class ANIMATION;


//=========================================================================
// CAMERA OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class CAMERA : public BASE
{
public:
    /*! @brief not in use yet!! for camera plugins
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get camera with number
     *
     * @param[in] n ?
     * @return ?

     * @todo documentation to be done.
     */
    const CAMERA& operator=( int n );

    /*! @brief copy camera from another camera
     *
     * @param[in] camera right hand side
     * @return ?

     * @todo documentation to be done.
     */
    const CAMERA& operator=( const CAMERA& camera );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum
    {
        PERSPECTIVE=0,  /*!<  */
        ORTHOGONAL=2    /*!<  */
    };

    /*! @brief get view of camera -> enum
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_view( int * value );

    /*! @brief set view of camera with enum
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_view( int value );

    /*! @brief get the position of the camera
     *
     * @param position ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_position( VIZ_POSITION & position );

    /*! @brief get the position of the external camera
     *
     * @param position ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_position_ext( VIZ_POSITION & position );

    /*! @brief set position
     *
     * @param position ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_position( VIZ_POSITION & position );

    /*! @brief get the direction of the camera
     *
     * @param position ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_direction( VIZ_POSITION & position );

    /*! @brief set the direction of the camera
     *
     * @param position ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_direction( VIZ_POSITION & position );

    /*! @brief get pan
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_pan( float * value );

    /*! @brief get pan of external camera
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_pan_ext( float * value );

    /*! @brief set pan
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_pan( float value );

    /*! @brief get tilt
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_tilt( float * value );

    /*! @brief get tilt of external camera
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_tilt_ext( float * value );

    /*! @brief set tilt
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_tilt( float value );

    /*! @brief get twist
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_twist( float * value );

    /*! @brief get twist of external camera
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_twist_ext( float * value );

    /*! @brief set twist
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_twist( float value );

    /*! @brief get field of view in X direction
     *
     * @param[out] value ?
     * @return ?

     * @note ignored and invalid if camera is not in external mode
     * @todo documentation to be done.
     */
    int get_fovx( float * value );

    /*! @brief get field of view of external camera in x
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_fovx_ext( float * value );

    /*! @brief set field of view in x
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_fovx( float value );

    /*! @brief get field of view in Y direction
     *
     * @param[out] value ?
     * @return ?

     * @note equal to zoom value in GUI
     * @todo documentation to be done.
     */
    int get_fovy( float * value );

    /*! @brief get field of view of external camera in y
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_fovy_ext( float * value );

    /*! @brief set field of view in y
     *
     * @param[in]  value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_fovy( float value );

    /*! @brief get center shift in X direction (in pixels)
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_cx( float * value );

    /*! @brief get center shift of external camera in x
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_cx_ext( float * value );

    /*! @brief set center shift in x
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_cx( float value );

    /*! @brief get center shift in Y direction (in pixels)
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_cy( float * value );

    /*! @brief get center shift of external camera in y
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_cy_ext( float * value );

    /*! @brief set center shift in y
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_cy( float value );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return if value is true, everest is receiving external camera data
     *         without copying them to its internal camera structures for rendering.
     *         These data can be fetched with the '_ext' functions.
     * @todo documentation to be done.
     */
    int get_decouple_external( bool * value );

    /*! @brief ?
     *
     * @param[in] value if value set to true, everest is receiving external camera data
     *                  without copying them to its internal camera structures for rendering.
     *                  These data can be fetched with the '_ext' functions.
     * @return ?

     * @todo documentation to be done.
     */
    int set_decouple_external( bool value );

    /*! @brief is this camera getting its data from an external camera ?
     *
     * corresponds to the 'EDITOR/REMOTE' button in the everest camera GUI
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_external_active( bool * value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_external_active( bool value );

    /*! @brief set position of container, which is the tracking object
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_pos_tracking( CONTAINER & container );

    /*! @brief get position of container, which is the tracking object
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_pos_tracking( CONTAINER & container );

    /*! @brief set rotation of container, which is the tracking object
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_rot_tracking( CONTAINER & container );

    /*! @brief get rotation of container, which is the tracking object
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_rot_tracking( CONTAINER & container );


    /*! @brief is the position tracking active
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_pos_tracking_active( int * value );

    /*! @brief set the position tracking active or inactive
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_pos_tracking_active( int value );

    /*! @brief reset the position tracking
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_pos_tracking_reset( void );

    /*! @brief is the rotation tracking active
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_rot_tracking_active( int * value );

    /*! @brief set the rotation tracking active or inactive
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_rot_tracking_active( int value );

    /*! @brief how far is the focal plane away from camera
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_focal_plane( float * value );

    /*! @brief set the focal plane
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_focal_plane( float value );


    /*! @brief reset the rotation tracking
     *
     * @return ?

     * @todo documentation to be done.
     */
    int set_rot_tracking_reset( void );

    /*! @brief the result of view and projection
     *
     * @param matrix ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_matrix( evMatrix & matrix );

    /*! @brief the viewing transformation of the camera
     *
     * @param matrix ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_view_matrix( evMatrix & matrix );

    int set_view_matrix(evMatrix&);             // set the viewing transformation of the camera

    /*! @brief the projection transformation of the camera
     *
     * @param matrix ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_projection_matrix( evMatrix & matrix );

    int enable_recompute_matrices(bool);        // enable/disable recompute matrices
    int recompute_matrices();                    //  recompute camera matrices now

    int set_frustum( float left, float right, float bottom, float top ); // sets the frustum in the case of orthographic camera
    int get_frustum( float* left, float* right, float* bottom, float* top );

    enum frustumType { FRUSTUM_REGULAR, FRUSTUM_VIDEOWALL, FRUSTUM_SNAPSHOT }; // Return normalized frustum coords between [0, 1]
    int get_frustum_type(int* frustumType);
    int get_frustum_normalized(float* leftNormalized, float* rightNormalized, float* topNormalized, float* bottomNormalized, int* frustumType);


    /*! @brief get if camera is using it's own near & far for clipping (and not the scene's)
     *
     * @param[out] local ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_local_clipping(bool * local);

    /*! @brief set camera to use it's own near & far for clipping (and not the scene's)
     *
     * @param[in] local ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_local_clipping(bool local);

    /*! @brief get clipping near value
     *
     * @param[out] camera_near ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_near(float * camera_near);

    /*! @brief set clipping near value
     *
     * @param[in] camera_near ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_near(float camera_near);

    /*! @brief get clipping far value
     *
     * @param[out] camera_far ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_far(float * camera_far);

    /*! @brief set clipping far value
     *
     * @param[in] camera_far ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_far(float camera_far);

    /*! @brief set clipping near and far value
     *
     * @param[out] camera_near ?
     * @param[out] camera_far ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_near_far(float * camera_near, float * camera_far);

    /*! @brief set clipping near and far value
     *
     * @param[in] camera_near ?
     * @param[in] camera_far ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_near_far(float camera_near, float camera_far);
     /*! @brief set clipping near and far value
     *
     * @param[in] camera_near ?
     * @param[in] camera_far ?
     * @return ?

     * @todo documentation to be done.
     */

    int SetFrustumOffsets(bool bUseFrustumOffsets, float fXSize , float fYSize, float fXOffset,float fYOffset);
     /*! @brief set clipping near and far value
     *
     * @param[in] camera_near ?
     * @param[in] camera_far ?
     * @return ?

     * @todo documentation to be done.
     */
    int GetFrustumOffsets(bool *bUseFrustumOffsets, float *fXSize , float *fYSize, float *fXOffset,float *fYOffset);


    /*! @brief sets the distortion factor [0.0f - 1.0f], which describes how strong the 
    *          distortion should be applied (1.0 -> 100%, 0.5 -> 50%, 0.0 -> no distortion)
    *
    * @param[in] factor ?
    * @return ?

    * @todo documentation to be done.
    */
    int set_distortion_factor(float factor);

    /*! @brief sets the distortion factor [0.0f - 1.0f], which describes how strong the
    *          distortion should be applied (1.0 -> 100%, 0.5 -> 50%, 0.0 -> no distortion)
    *
    * @param[out] factor ?
    * @return ?

    * @todo documentation to be done.
    */
    int get_distortion_factor(float *factor);
};



#endif // EV_PLUGIN_CAMERA_H
