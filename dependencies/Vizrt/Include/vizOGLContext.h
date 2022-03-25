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

#ifndef __vizOglContext_h__
#define __vizOglContext_h__

#include <GL/gl.h>

/*! @brief Access renderer states.
 * This class defines the access to "render" states within the viz render engine
 * It includes OpenGl states, current window size ....
 * @note ...
 * \warning
 * \internal
 * \author hubert oehm
 * \version
 */
class OGL_CONTEXT {
public:
    // the context must be valid at all time, but just to make sure :-)
    static GLboolean valid();

    static GLboolean get_multisampled();
    static GLboolean get_GL_BLEND();
    static GLboolean get_GL_DEPTH_TEST();
    static GLboolean get_GL_CULL_FACE();
    static GLboolean get_GL_NORMALIZE();
    static GLboolean get_GL_ALPHA_TEST();
    static GLboolean get_GL_LINE_STIPPLE();
    static GLboolean get_GL_LINE_SMOOTH();
    static GLboolean get_GL_LOGIC_OP();
    static GLboolean get_GL_STENCIL_TEST();

    static void      get_GL_CLIP_PLANES(GLboolean[6]);
    static GLboolean get_GL_CLIP_PLANE0();
    static GLboolean get_GL_CLIP_PLANE1();
    static GLboolean get_GL_CLIP_PLANE2();
    static GLboolean get_GL_CLIP_PLANE3();
    static GLboolean get_GL_CLIP_PLANE4();
    static GLboolean get_GL_CLIP_PLANE5();

    static GLboolean get_GL_LIGHTING();
    static GLboolean get_GL_LIGHT_MODEL_TWO_SIDE();
    static GLboolean get_GL_LIGHT_MODEL_LOCAL_VIEWER();

    static void      get_GL_LIGHTS(GLboolean[8]);
    static GLboolean get_GL_LIGHT0();
    static GLboolean get_GL_LIGHT1();
    static GLboolean get_GL_LIGHT2();
    static GLboolean get_GL_LIGHT3();
    static GLboolean get_GL_LIGHT4();
    static GLboolean get_GL_LIGHT5();
    static GLboolean get_GL_LIGHT6();
    static GLboolean get_GL_LIGHT7();

    static GLboolean get_GL_POLYGON_MODE();
    static GLboolean get_GL_FRONT_FACE();
    static GLboolean get_GL_DEPTH_MASK();

    static GLenum get_GL_DEPTH_FUNC();
    static GLenum get_GL_BLEND_SFACTOR();
    static GLenum get_GL_BLEND_DFACTOR();
    static GLenum get_GL_BLEND_EQUATION();

    static GLenum get_GL_SHADE_MODEL();

    static float get_GL_LINE_WIDTH();

    // brief is a certain texture active.
    static GLboolean get_GL_TEXTURE_ENABLED(int unit);

    // 1D, 2D ...
    static GLenum get_GL_TEXTURE_TARGET(int unit);

    // GL_ALPHA, GL_RGBA ...
    static GLenum get_GL_TEXTURE_COMPONENTS(int unit);

    // GL_ALPHA, GLRGBA ...
    static GLenum get_GL_TEXTURE_FORMAT(int unit);

    enum eTextureCoordGen
    {
        VIZ_TEXTURE_COORD_VERTEX=0,
        VIZ_TEXTURE_COORD_LINEAR=1,
        VIZ_TEXTURE_COORD_SPHERE=2,
        VIZ_TEXTURE_COORD_CUBE_MAP=3
    };
    static eTextureCoordGen get_GL_TEXTURE_COORD_GEN(int unit);

    //  GL_MODULATE, GL_DECAL, GL_BLEND ...
    static GLenum get_GL_TEXTURE_ENVIRONMENT(int unit);

    // GL_BYTE, GL_SHORT ...
    static GLenum get_GL_TEXTURE_TYPE(int unit);

    // -1, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, GL_COMPRESSED_RGBA_S3TC_DXT5_EXT
    static GLenum get_GL_TEXTURE_COMPRESSION(int unit);

    enum eTextureQuality
    {
        VIZ_TEXTURE_PIXEL=1,
        VIZ_TEXTURE_LINEAR=2,
        VIZ_TEXTURE_MIPMAP=3,
        VIZ_TEXTURE_SHARPEN=4,
        VIZ_TEXTURE_LINEAR_MIPMAP=5,
        VIZ_TEXTURE_CUBEMAP=6
    };
    static eTextureQuality get_GL_TEXTURE_QUALITY(int unit);

    // width and heightof the texture
    static void get_GL_TEXTURE_SIZE(int unit, int*, int*);

    // this returns the ID of the image of the texture. Access the image itself by using
    // IMAGE image;
    // image = get_GL_TEXTURE_IMAGE();
    static int get_GL_TEXTURE_IMAGE(int unit);

    // r, g, b
    static void get_material_ambient(float*, float*, float*);
    static void get_material_diffuse(float*, float*, float*);
    static void get_material_specular(float*, float*, float*);
    static void get_material_emission(float*, float*, float*);
    static float get_material_shininess();
    static float get_material_alpha();

    // x, y, width, height
    static void get_viewport(int*, int*, int*, int*);

    // get the size of the drawable
    static void get_window_size(int*, int*);
};



#endif
