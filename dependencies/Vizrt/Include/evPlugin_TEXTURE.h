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

#if ! defined( EV_PLUGIN_TEXTURE_H )
#define EV_PLUGIN_TEXTURE_H

#include "evPlugin_BASE.h"
#include "evPlugin_PLUGIN_PARAMETER.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;
class IMAGE;
class ANIMATION;
class evMatrix;

//=========================================================================
// TEXTURE OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class TEXTURE : public BASE
{
public:
    /*! @brief get texture of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get texture of container, on which plugin is inherited (shaders)
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local_inheritor( void );

    /*! @brief texture of container with containername
     *
     * @param[in] container ?
     * @return ?

     * @todo documentation to be done.
     */
    const TEXTURE& operator=( const char * container );

    /*! @brief texture of CONTAINER
     *
     * @param[in] container ?
     * @return ?

     * @todo documentation to be done.
     */
    const TEXTURE& operator=( const CONTAINER & container );

    /*! @brief copy texture from another texture
     *
     * @param[in] rhs
     * @return ?

     * @todo documentation to be done.
     */
    const TEXTURE& operator=( const TEXTURE & rhs );


    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum optimize
    {
        TEXTURE_OPTIMIZE_QUALITY =1 ,   /*!<  */
        TEXTURE_OPTIMIZE_MEMORY = 0     /*!<  */
    };

    enum compression
    {
        TEXTURE_COMPRESSION_NONE,
        TEXTURE_COMPRESSION_DXT1,
        TEXTURE_COMPRESSION_DXT3,
        TEXTURE_COMPRESSION_DXT5
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum mapping
    {
        MAP_LINEAR  = 1,    /*!<  */
        MAP_VERTEX  = 2,    /*!<  */
        MAP_REFLECT = 3,    /*!<  */
        MAP_SPHERIC = 4,    /*!<  */
        MAP_CYLINDRIC = 5,  /*!<  */
        MAP_CUBE    = 6     /*!<  */
    };

    enum displaycomponent
    {
        DISPLAY_COLOR_ALPHA = 0,
        DISPLAY_COLOR,
        DISPLAY_ALPHA
    };

    /*! @brief get the active state
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_active( int * value );

    /*! @brief set the active state
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_active( int value );

    /*! @brief get the type of mapping -> enum mapping values
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_type( int * value );

    /*! @brief set the type of mapping with the mapping enum values
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_type( int value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum environment
    {
        ENV_BLEND=0x0BE2,       /*!<  */
        ENV_DECAL=0x2101,       /*!<  */
        ENV_MODULATE=0x2100     /*!<  */
    };

    /*! @brief get the environment type -> enum environment values
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_env_type( int * value );

    /*! @brief set the type of environment with the environment enum values
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_env_type( int value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum quality
    {
        QUAL_PIXEL=1,       /*!<  */
        QUAL_LINEAR=2,      /*!<  */
        QUAL_MIPMAP=3,      /*!<  */
        QUAL_SHARPEN=4      /*!<  */
    };

    /*! @brief get the type of quality -> enum quality values
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_qual_type( int * value );

    /*! @brief set the type of quality with the quality enum values
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_qual_type( int value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum effect
    {
        EFFECT_BLUR=0,      /*!<  */
        EFFECT_MOSAIC=1     /*!<  */
    };

    /*! @brief get the type of effect -> effect enum values
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_effect_type( int * value );

    /*! @brief set the type of effect with the effect enum values
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_effect_type( int value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum wrap
    {
        WRAP_REPEAT=0x2901,     /*!<  */
        WRAP_CLAMP=0x2900       /*!<  */
    };

    /*! @brief get the type of wrap -> wrap enum values
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_wrap_type( int * value );

    /*! @brief set the type of wrap with the wrap enum values
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_wrap_type( int value );

    /*! @brief get the mapping x position
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_pos_x( float * value );

    /*! @brief set the mapping x position
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_pos_x( float value );

    /*! @brief get the mapping y position
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_pos_y( float * value );

    /*! @brief set the mapping y position
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_pos_y( float value );

    /*! @brief get the mapping x center
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_center_x( float * value );

    /*! @brief set the mapping x center
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_center_x( float value );

    /*! @brief get the mapping y center
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_center_y( float * value );

    /*! @brief set the mapping y center
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_center_y( float value );

    /*! @brief get the mapping x rotation
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_rot_x( float * value );

    /*! @brief set the mapping x rotation
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_rot_x( float value );

    /*! @brief get the mapping y rotation
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_rot_y( float * value );

    /*! @brief set the mapping y rotation
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_rot_y( float value );

    /*! @brief get the mapping z rotation
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_rot_z( float * value );

    /*! @brief set the mapping z rotation
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_rot_z( float value );

    /*! @brief get the mapping x scaling
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_scale_x( float * value );

    /*! @brief set the mapping x scaling
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_scale_x( float value );

    /*! @brief get the mapping y scaling
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_map_scale_y( float * value );

    /*! @brief set the mapping y scaling
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_map_scale_y( float value );

    /*! @brief get texture matrix
     *
     * @param[out] matrix ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_matrix(evMatrix& matrix);

    /*! @brief get the value of blending
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_blend_value( float * value );

    /*! @brief set blending value
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_blend_value( float value );

    /*! @brief get the value of effect
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_effect_value( float * value );

    /*! @brief set effect value
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_effect_value( float value );

    /*! @brief get the value of sharpen
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_sharpen_value( float * value );

    /*! @brief set sharpen value
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_sharpen_value( float value );

    /*! @brief get the width of the image
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_image_width( int * value );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_image_height( int * value );

    /*! @brief set the size of image
     *
     * @param[in] width ?
     * @param[in] height ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_image_size( int width, int height );

    /*! @brief set the image with location
     *
     * @param[in] location ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_image( char * location );

    /*! @brief set the image with image
     *
     * @param[in] image ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_image( IMAGE & image );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_image( IMAGE & value );

    /*! @brief set the image 2 with location
     *
     * @param[in] location ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_image2( char * location );

    /*! @brief set the image 2 with image
     *
     * @param[in] image ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_image2( IMAGE & image );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_image2( IMAGE & value );

    /*! @brief ?
     *
     * @param[in] cur_texcoord_scale ?
     * @param[in] load_bias_s ?
     * @param[in] load_bias_t ?
     * @return ?

     * @todo documentation to be done.
     */
    int draw_texture( float cur_texcoord_scale, float load_bias_s, float load_bias_t );

    /*! @brief ?
     *
     * @param val ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_optimize( optimize val );
    int get_optimize( optimize *val );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return Texture Handle
     * @return This function returns the texture ID used by opengl for this image.
               If this image is not used as a texture value will be -1.
     */
    int get_texture_handle( int * value );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return This function sets the next unused texture unit in the passed value.
               If there aren't any units available, then the function returns
               false and a default texture unit id is written into value.
     */
    int get_free_texture_unit( int * value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return This function applies the image ex transformation to the current texture
     * @see evRegisterParameterImageEx().
     */
    int apply_image_ex_transformation( PLUGIN_PARAMETER::IMAGE_EX * value );

    /*! @brief ?
    *
    * @param[out] val ?
    * @return This function gets the anisotropic filtering for the texture
    */
    int get_anisotropy(float * anisotropy);

    /*! @brief ?
    *
    * @param[in] val ?
    * @return This function sets the anisotropic filtering for the texture
    */
    int set_anisotropy(float anisotropy);

    /*! @brief ?
    *
    * @param[in] val ?
    * @return This function returns the display_component type of the texture -> displaycomponent enum
    */
    int get_display_component( int* type );

    /*! @brief ?
    *
    * @param[in] val ?
    * @return This function sets the display_component type of the texture -> displaycomponent enum
    */
    int set_display_component( int type );

    /*! @brief ?
    *
    * @param[in] val ?
    * @return This function gets the constant color of the texture
    */
    int get_constant_color( float* red, float* green, float* blue, float* alpha );

    /*! @brief ?
    *
    * @param[in] val ?
    * @return This function sets the constant color of the texture
    */
    int set_constant_color( float red, float green, float blue, float alpha );

    // Ported from 2.x:
    /* DO NOT USE THIS IF YOU DON'T KNOW WHAT YOU ARE DOING */
    int create_texture(IMAGE& image);
    int create_3d_texture( const char* pData );
    int delete_texture();

    int set_compression(compression val);
    int get_compression(compression *val);

    int set_force_no_mipmaps(int val);
    int get_force_no_mipmaps(int *val);
};


#endif // EV_PLUGIN_TEXTURE_H
