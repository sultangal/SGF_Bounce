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


#ifndef __EV_OBJECTS_H__
#define __EV_OBJECTS_H__




// If we compile with MFC, we cannot declare POSITION, because that name is
// also used by the MFC. Use VIZ_POSITION instead.
#ifdef _AFXDLL
#define DONT_DECLARE_POSITION_TYPEDEF
#endif

#include "Misc.h"
#include "evMath.h"
#include "evIODef.h"
#include "THeapArray.h"


#define CURRENT_CAMERA  -1
#define ROOT            "ROOT"

/*
class RGBAColor;
class CONTAINER;
class TRANSFORMATION;
class VIZ_POSITION;
class ROTATION;
class SCALING;
class CENTER;
class ALPHA;
class KEY;
class MATERIAL;
class GEOMETRY;
class GEOMETRY_MODIFIER;
class TEXTURE;
class CAMERA;
class LIGHT;
class SCENE;
class PLUGIN_PARAMETER;
class FUNCTION;
class IMAGE;
class FONT;
class STAGE;
class TEXT_CHARACTER_PROPERTY;
class PROJECTOR;
class PROJECTION_TARGET;
class EXPERT;
class MASK;
class MASK_TARGET;
class CLIPPER;
class CLIPPER_TARGET;
class OGL;
class DIRECTOR;
class CHANNEL;
class BEZIER_HANDLE;
class GEOREF;
class SHARED_MEMORY;
class KEYFRAME_BASE;
class SHADER;
class SCRIPTFUNCTION;
class SCRIPT_PLUGIN;
class INFOTEXT;
class TOUCH;
class TOUCH_TRACE;
class GESTURE;
class GESTURE_RECOGNIZER;
*/

/*!@brief {brief description}
 *
 * {a more elaborate description of enum}
 * @todo documentation to be done.
 * \sa (see also)
 */
enum
{
    GE_STANDARD,    /*!<  */
    GE_IMPORTED,    /*!<  */
    GE_OUTLINE      /*!<  */
};












//
//#define evPLUGIN_POLLUTE
//
#include "evPlugin_BASE.h"

#include "evPlugin_AVCHANNEL.h"
#include "evPlugin_GFXCHANNEL.h"
#include "evPlugin_ALPHA.h"
#include "evPlugin_BEZIER_HANDLE.h"
#include "evPlugin_CAMERA.h"
#include "evPlugin_CENTER.h"
#include "evPlugin_CHANNEL.h"
#include "evPlugin_CLIPPER.h"
#include "evPlugin_CLIPPER_TARGET.h"
#include "evPlugin_CLOCK.h"
#include "evPlugin_CONTAINER.h"
#include "evPlugin_DIRECTOR.h"
#include "evPlugin_EXPERT.h"
#include "evPlugin_FONT.h"
#include "evPlugin_FUNCTION.h"
#include "evPlugin_GEOMETRY.h"
#include "evPlugin_GEOMETRY_MODIFIER.h"
#include "evPlugin_GUI_COMMANDS.h"
#include "evPlugin_IMAGE.h"
#include "evPlugin_DYNAMIC_IMAGE.h"
#include "evPlugin_KEY.h"
#include "evPlugin_KEYFRAME.h"
#include "evPlugin_LIGHT.h"
#include "evPlugin_MASK.h"
#include "evPlugin_MASK_TARGET.h"
#include "evPlugin_MATERIAL.h"
#include "evPlugin_PLUGIN_EDITOR.h"
#include "evPlugin_PLUGIN_PARAMETER.h"
#include "evPlugin_PLUGIN_INSTANCE.h"
#include "evPlugin_SCRIPT_PLUGIN.h"
#include "evPlugin_POOL.h"
#include "evPlugin_POSITION.h"
#include "evPlugin_PROJECTION_TARGET.h"
#include "evPlugin_PROJECTOR.h"
#include "evPlugin_ROTATION.h"
#include "evPlugin_SCALING.h"
#include "evPlugin_SCENE.h"
#include "evPlugin_SENSOR_CHANNEL.h"
#include "evPlugin_SHADER.h"
#include "evPlugin_SHARED_MEMORY.h"
#include "evPlugin_SCRIPTFUNCTION.h"
#include "evPlugin_SCRIPT.h"
#include "evPlugin_STAGE.h"
#include "evPlugin_TEXTURE.h"
#include "evPlugin_TEXT_CHARACTER_PROPERTY.h"
#include "evPlugin_TEXT_CONTROL.h"
#include "evPlugin_TOUCH.h"
#include "evPlugin_TRACE.h"
#include "evPlugin_GESTURE.h"
#include "evPlugin_GESTURE_RECOGNIZER.h"
#include "evPlugin_TRANSFORMATION.h"
#include "evPlugin_GRID.h"
#include "evPlugin_VIDEO_CHANNEL.h"
#include "evPlugin_INFOTEXT.h"
#include "evPlugin_VIEWPORT_TILE.h"
#include "evPlugin_VIZ.h"
#include "evPlugin_vizError.h"
#include "evPlugin_SUBSTANCE.h"


// those classes don't exist in viz3
// #include "evPlugin_3DTF2.h"
// #include "evPlugin_VIEWPORT.h"
// #include "evPlugin_WINDOW_MASK.h"
// #include "evPlugin_CONTAINER_FX.h"
// #include "evPlugin_DYNAMIC_IMAGE.h"




// #include "evPlugin_.h"
//
//#undef evPLUGIN_POLLUTE
//


















/// \internal until the class id done we include it
#include "CVgeomData.h"










// TODO:
#if 0
/*! @brief A representation of an actor (= container, light, camera, or scene) in the stage
 *
 */
class ACTOR : public BASE
{
public:
    void init(const BASE& object);
    void init(const BASE& object, const DIRECTOR& dir);
};

/*! @brief A representation of an animation object in the stage
 *
 */
class ANIMATION_OBJECT : public BASE
{
    void init(const BASE& object);
    void init(const BASE& object, const DIRECTOR& dir);
};
#endif



#endif // __EV_OBJECTS_H__
