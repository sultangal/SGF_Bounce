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

#ifndef _EV_LICENSE_H_
#define _EV_LICENSE_H_

enum EV_FEATURES
{
    //EV_FEATURE_GUI,                     // 0
    //EV_FEATURE_VIRTUAL_SET,
    //EV_FEATURE_DEVICE_CONTROL,
    //EV_FEATURE_DEVICE_RENDER,
    //EV_FEATURE_MULTIPIPE_1,

    //EV_FEATURE_MULTIPIPE_2,             // 5
    //EV_FEATURE_MULTIPIPE_3,
    //EV_FEATURE_MULTIPIPE_4,
    //EV_FEATURE_CLIPSTATION,
    //EV_FEATURE_PREVIEW_VERSION,
    //EV_FEATURE_TERRAIN,

    //EV_FEATURE_TARGA3200,               // 15
    //EV_FEATURE_TARGA3200_CODEC1,
    //EV_FEATURE_TARGA3200_CODEC2,
    //EV_FEATURE_DEMO,

    //EV_FEATURE_AUDIO,                   // 20
    //EV_FEATURE_SAVE_INTERNET,
    //EV_FEATURE_SHADER,

    //EV_FEATURE_GIZMOZ,
    //EV_FEATURE_VIZUAL_DATA_TOOLS,

    
    //EV_FEATURE_ACTION_MODEL = ??,
    //EV_FEATURE_DUAL_CHANNEL,
    //EV_FEATURE_NO_VIDEO_PREVIEW,

    //EV_FEATURE_VIDEOIN_1,               // 35
    //EV_FEATURE_VIDEOIN_2,
    //EV_FEATURE_VIDEOIN_3,
    //EV_FEATURE_VIDEOIN_4,
    //EV_FEATURE_CLIPIN_1,

    //EV_FEATURE_CLIPIN_2,                // 40
    //EV_FEATURE_CLIPIN_3,
    //EV_FEATURE_CLIPIN_4,
    //EV_FEATURE_3D_STEREO,
    //EV_FEATURE_CHROMAKEY,

    //EV_FEATURE_WEATHER_DEMO_DATA,       // 45
    //EV_FEATURE_3G_SDI_OUTPUT,
    
    //EV_FEATURE_VIZRT_AE_IMPORT,

    //EV_FEATURE_IPSTREAM_OUTPUT,          // 50
    //EV_FEATURE_VizIONumberOfCameras_1,
    //EV_FEATURE_VizIONumberOfCameras_2,
    //EV_FEATURE_VizIONumberOfCameras_3,
    //EV_FEATURE_VizIONumberOfCameras_4,

    //EV_FEATURE_VizIOTrackingRecorder,    // 55
    //EV_FEATURE_TRICASTER,
    //EV_FEATURE_C4D_IMPORT,
    //EV_FEATURE_Reserved_1,
    //EV_FEATURE_Reserved_2,

    //EV_FEATURE_VizIOSportLensCalibration,  // 60
    //EV_FEATURE_VizIOArenaUserInterface,
    //EV_FEATURE_IPSTREAM_INPUT_1,
    //EV_FEATURE_IPSTREAM_INPUT_2,
    //EV_FEATURE_IPSTREAM_INPUT_3,
    //EV_FEATURE_IPSTREAM_INPUT_4,        // 65

    EV_MAX_FEATURES = 67


    , EV_FEATURE_PPI_PLUGINS = 47
    , EV_ENG_PLUG_MULTITOUCH = 1200502

    , EV_FEATURE_IMAGEFX = 12
    // , EV_FEATURE_AUDIOFX = ??
    , EV_FEATURE_REALFX = 10
    , EV_FEATURE_SPLINEFX = 13
    , EV_FEATURE_TEXTFX = 9
    , EV_FEATURE_PIXELFX = 34
    // , EV_FEATURE_VIDEOFX = ??
    , EV_FEATURE_GRAFFITI = 25
    , EV_FEATURE_WEATHER = 18
    , EV_FEATURE_WEATHER_PLUGINS = 23
    , EV_FEATURE_WEATHER_PLAYOUT = 27
    // , EV_FEATURE_SOCIALTVFX = ??
    , EV_FEATURE_EVS_CONTROL_PLUGINS = 48

    , EV_FEATURE_DNXHD = 21
    , EV_FEATURE_GEOFX = 28

    , EV_FEATURE_RTT_ADVANCED_MATERIALS = 30
    , EV_ENG_PLROY_RTTFX = 1200604

    , EV_FEATURE_SUBSTANCE = 66
    , EV_ENG_PLROY_SUBSAUTH = 1200605

    , EV_ENG_PLROY_EZGALLERY = 1200606 ///< ezGallery
    , EV_ENG_PLROY_EZPOSTFX = 1200607 ///< ezPostFx
    , EV_ENG_PLROY_EZSHADERS = 1200608 ///< ezShaders
    , EV_ENG_PLROY_EZMESH = 1200609 ///< ezMesh
    , EV_ENG_PLROY_EZDEFORM = 1200610 ///< ezDeform
    , EV_ENG_PLROY_EZCOMPOSER = 1200611 ///< ezComposer
    , EV_ENG_PLROY_EZLOGIC = 1200612 ///< ezLogic
    , EV_ENG_PLROY_EZLINK = 1200613 ///< ezLink
    , EV_ENG_PLROY_EZTUBULAR = 1200614 ///< ezTubular
    , EV_ENG_PLROY_DORNA_MTAP = 1200615 ///< DornaMT APP
    , EV_ENG_PLROY_DORNA_MTPL = 1200616 ///< DornaMT Plugin
    , EV_ENG_PLROY_EZJSPRO = 1200617 ///< ezJavascript (Pro)
};

#endif /* _EV_LICENSE_H_ */
