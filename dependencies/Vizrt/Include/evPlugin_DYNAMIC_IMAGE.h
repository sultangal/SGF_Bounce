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

#if ! defined( EV_PLUGIN_DYNAMIC_IMAGE_H )
#define EV_PLUGIN_DYNAMIC_IMAGE_H

#include "evPlugin_BASE.h"
#include "evPlugin_IMAGE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


typedef void  (*DYNAMIC_IMAGE_CALLBACK)(int iImageId, void * pUserData ,  bool *bGoAgain , int iRenderCounter ,int iSpare);

class DYNAMIC_IMAGE : public IMAGE
{
public:
    enum dynamicImage
    {
        dynamicImageNone = 0 ,
        dynamicImageSubScene
    };
    enum dynamicImageSize
    {
        dynamicImageSizeNone  ,
        dynamicImageSize8     ,
        dynamicImageSize16    ,
        dynamicImageSize32    ,
        dynamicImageSize64    ,
        dynamicImageSize128   ,
        dynamicImageSize256   ,
        dynamicImageSize512   ,
        dynamicImageSize1024  ,
        dynamicImageSizeVideo ,
        dynamicImageSizeCustom,
        dynamicImageSize2048
    };
    enum subSceneType
    {
        typeLocalScene,
        typeOtherScene,
        typeOtherTransition,
        typeLocalSubScene,
        typeMainLayer,

    };
    enum cameraType
    {
        typeVizCamera,
        typeVizLight,
        typeVizCubeMap,
        typeRemote,
        typeVizMultiCamera

    };
    enum renderMode
    {
        renderModeAuto,
        renderModeOnChange,
        renderModeAlways,
        renderModeCommand,
        renderModeGrab,
    };
    enum cropSceneType
    {
        cropSceneNone,
        cropSceneManual,
        cropSceneAuto
    };

    /*
    Change the image to  dynamic image, Must be called first, Resets the image.
    */
    int set_dynamic(dynamicImage eType);
    int get_dynamic(dynamicImage *eType);

    /*
    Set/Get the sub scene type
    */
    int set_type(subSceneType val);
    int get_type(subSceneType *val);
    int get_is_subScene();

    /*
    Set/Get the scene for the dynamic image, Relevant only when sub scene type is not called
    */
    int set_scene(SCENE scene);
    int set_scene(const char * chScene);
    int clear_scene();
    int get_scene(SCENE &scene);

    /*
    Set/Get the size of the dynamic image (dynamicImageSize )
    */
    int set_size(dynamicImageSize x, dynamicImageSize y, int CustomSize_x = 0, int CustomSize_y = 0 );
    int get_size(dynamicImageSize *x, dynamicImageSize *y, int *CustomSize_x = NULL, int *CustomSize_y = NULL );

    /*
    Set/Get sub scene render mode
    */
    int get_renderMode(renderMode *eMode);
    int set_renderMode(renderMode eMode);

    /*
    Switch on a flag to render the dynamic image, The actual render will take place before the next frame.
    Relevant for render mode  renderModeCommand or  renderModeGrab
    */
    int set_render();

    /*
    Set/Get camera number for dynamic images
    */
    int Set_Dynamic_CameraID( int val  );
    int Get_Dynamic_CameraID( int *val );

    /*
    Set/Get sub scene camera type and offsets option.
    */
    int set_camera_type(cameraType val);
    int set_use_camera_offsets(cropSceneType  iVal );
    int set_camera_offsets(float fWidth ,float fHeight , float fPosX , float fPosY );

    int get_camera_type(cameraType *val);
    int get_use_camera_offsets(cropSceneType  *iVal );
    int get_camera_offsets(float *fWidth ,float *fHeight , float *fPosX , float *fPosY );

    /*
    Advance option for dynamic image using viewport
    */
    int set_viewPort_active(int iViewId , bool bActive);
    int set_viewPort_position( int iViewId ,int iX,int iY );
    int set_viewPort_size( int iViewId ,int iWidth,int iHeight );
    int set_viewPort_camera( int iViewId ,int iCamera );
    int set_viewPort_camera_rot_offsets( int  iViewId , float fPanOffset,  float fTiltOffset,float fRollOffset );
    int set_viewPort_camera_pos_offsets( int  iViewId , float  fXMove, float fYMove,float  fZMove );
    int set_viewPort_camera_center_offsets( int  iViewId , float  fXMove, float fYMove );
    //int set_multi_camera_data(float fPanOffset,float fTiltOffset,float fXMove,float fYMove);
    int set_viewPort_camera( int iViewId ,int  iCamera ,float fPanOffset,
                             float fTiltOffset,float fRollOffset,float  fXMove, float fYMove,float  fZMove );


    /*
    set callbacks
    */
    int set_pre_callback(DYNAMIC_IMAGE_CALLBACK p , void * preData ) ;
    int set_post_callback(DYNAMIC_IMAGE_CALLBACK p , void * postData ) ;

};

class TEXTURE_RENDERER : public BASE
{
public:
    static int resetRenderer();
    static int get_current_camera_offsets(float *fCropX , float *fCropY ,float *fOffsetX , float *fOffsetY);
    static int get_current_keep_aspect(bool *enabled);
    static int get_render_size(int *x , int *y);
};

#endif //EV_PLUGIN_DYNAMIC_IMAGE_H
