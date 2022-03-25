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

#if ! defined( EV_PLUGIN_IMAGE_H )
#define EV_PLUGIN_IMAGE_H

#include "evPlugin_BASE.h"
#include "evPlugin_SCENE.h" // due to set_subScene_scene


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class GEOREF;

//=========================================================================
// IMAGE OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class IMAGE : public BASE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum subSceneType
    {
        typeLocalScene,         /*!<  */
        typeOtherScene,         /*!<  */
        typeOtherTransition,    /*!<  */
        typeLocalSubScene       /*!<  */

    };
    enum cameraType
    {
        typeVizCamera,          /*!<  */
        typeVizLight,           /*!<  */
        typeVizContainer,       /*!<  */
        typeRemote              /*!<  */
    };

    enum renderMode
    {
        renderModeAuto,         /*!<  */
        renderModeAllways,      /*!<  */
        renderModeFirst,        /*!<  */
        renderModeSecond,       /*!<  */
        renderModeCommand       /*!<  */
    };

    /*! @brief get image with location
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    const IMAGE& operator=( const char * name );

    /*! @brief image from image
     *
     * @param[in] rhs
     * @return ?

     * @todo documentation to be done.
     */
    const IMAGE& operator=( const IMAGE& rhs );

    /*! @brief reload the image, if the file on disk has changed.
     *
     * the image is loaded automatically if it is accessed.
     * @return ?

     * @todo documentation to be done.
     */
    int reload( void );

    /*! @brief returns true if the assigned image is completely loaded
     *
     * in case of background-loading an image this function will return
     * false until the image is completely loaded.
     * @return ?

     * @todo documentation to be done.
     */
    int is_loaded(bool &bLoaded);

    /*! @brief close the image
     *
     * @return ?

     * @todo documentation to be done.
     */
    int close( void );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_name( char** value );

    /*! @brief get the size of the image
     *
     * @param[out] x ?
     * @param[out] y ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_size( int * x, int * y ) const;

    /*! @brief get the pointer to image-data
     *
     * @param[out] data ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_data( unsigned char ** data ) const;

    /*! @brief set pixel
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] color ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_pixel( int x, int y, unsigned long color );

    /*! @brief get pixel
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[out] color ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_pixel( int x, int y, unsigned long *color );

    /*! @brief get format (GLenum -> e.g. GL_RGBA, GL_RGB, GL_ALPHA)
     *
     * @param[out] format
     * @return ?

     * @todo documentation to be done.
     */
    int get_format( int * format );

    /*! @brief scale the image
     *
     * @param[in] x ?
     * @param[in] y ?
     * @return ?

     * @todo documentation to be done.
     */
    int scale( int x, int y );

    /*! @brief crop the image - left -> cut off int pixel from left side
     *
     * @param[in] left ?
     * @param[in] right ?
     * @param[in] up ?
     * @param[in] down ?
     * @return ?

     * @todo documentation to be done.
     */
    int crop( int left, int right, int up, int down );

    /*! @brief flip the image -> how = 'x' or 'y'
     *
     * @param[in] how ?
     * @return ?

     * @todo documentation to be done.
     */
    int flip( char how );

    /*! @brief blur the image
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int blur( float value );


    /*! @brief rebuild the texture
     *
     * A texture will be generated out if the image (resize of the image,
     * if neccessary and load it into texture memory
     * call this function if the image content has changed
     * @return ?

     * @todo documentation to be done.
     */
    int rebuild_texture();


    /*! @brief ?
     *
     * @param[out] value ?
     * @return Texture Handle  This function returns the texture ID used by opengl.
               If the texture is not defined yet value will be -1.
     */
    int get_texture_handle( int * value );


    /*! @brief copy - so original won't be changed
     *
     * @param[out] image ?
     * @return ?

     * @todo documentation to be done.
     */
    void copy( IMAGE& image );

    /*! @brief ?
     *
     * @param[in] level specifies the level of detail number
     * @param[in] xoffset texel offset in the x direction
     * @param[in] yoffset texel offset in the y direction
        @param[in] width ?
        @param[in] height ?
        @param[in] format format of the pixel data
        @param[in] type data type of pixel data
     * @param[in] pixels data
     * @return ?

     * @todo documentation to be done.
     */
    int subtexload( int level
        , int xoffset
        , int yoffset
        , int width
        , int height
        , int format
        , int type
        , void *pixels
        );

    /*! @brief ?
     *
     * @param[in] level specifies the level of detail number
        @param[in] width ?
        @param[in] height ?
        @param[in] texture compression (from TEXTURE::compression) enum
        @param[in] compressed_size specifies the size of the compressed image
     * @param[in] pixels data
     * @return ?

     * @todo documentation to be done.
     */
    int subtexload_compressed(int level, int width, int height, int texture_compression, int compressed_size, void *pixels);


    /*! @brief ?
     *
     * @param[in] xoffset ?
     * @param[in] yoffset ?
     * @param[in] width ?
     * @param[in] height ?
     * @return ?

     * @todo documentation to be done.
     */
    int setSubtexload( int xoffset, int yoffset, int width, int height );

    /*! @brief ?
     *
     * @param[in] width ?
     * @param[in] height ?
     * @param[in] format ?
     * @return ?

     * @todo documentation to be done.
     */
    int createImage( int width , int height, int format );

    /*! @brief ?
     *
     * @param[in] file_name ?
     * @return ?

     * @todo documentation to be done.
     */
    int createImage(const char* file_name);
    
    /*! @brief Allows/disallows freeing the image data after the texture is defined/loaded
     *
     * @param[in] bAllow Set to true to allow for freeing the image data from the RAM after it was uploaded to the GPU. Default is false.
     * @return ?
    
     * @todo documentation to be done.
     */
    int setFreeDataAfterDefine(bool bAllow);

    /*! @brief ?
     *
     * @param buffer ?
     * @param[in] buffer_size ?
     * @return ?

     * @todo documentation to be done.
     */
     int ConvertToCompressedImage(int iCompressionLevel);

    /*! @brief ?
     *
     * @param[in] format ?
     * @return ?

     * @todo documentation to be done.
     */
    int CreateCompressedImage(int width, int height, int texture_compression, int compressed_size, void *pixels);

    /*! @brief ?
     *
     * @param[in] format ?
     * @return ?

     * @todo documentation to be done.
     */
      int createImage(const void * buffer, int buffer_size);

    /*! @brief ?
     *
     * @param[in] format ?
     * @return ?

     * @todo documentation to be done.
     */
    int setImageFormat( int format );

    /*! @brief ?
     *
     * @param[in] format ?
     * @return ?

     * @todo documentation to be done.
     */
    int convertToImageFormat( int format );

    /*! @brief ?
     *
     * @param[in] width ?
     * @param[in] height ?
     * @return ?

     * @todo documentation to be done.
     */
    int setImageSize( int width , int height );

    /*! @brief ?
     *
     * @param[in] location ?
     * @return ?

     * @todo documentation to be done.
     */
    int saveImage( const char * location );

    /*! @brief ?
     *
     * @param[in] longitude ?
     * @param[in] latitude ?
     * @param[in] height ?
     * @param x ?
     * @param y ?
     * @param z ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_llz2rs( double longitude, double latitude, double height ,float& x, float& y, float& z );

    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @param longitude ?
     * @param latitude ?
     * @param height ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_rs2llz(float x, float y, float z, double& longitude, double& latitude, double& height);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool is_geo_image( void );

    /*! @brief ?
     *
     * @param minx ?
     * @param maxx ?
     * @param miny ?
     * @param maxy ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_get_bbox( float& minx, float& maxx, float& miny, float& maxy );

    /*! @brief For custom viz geo reference plugins
     *
     * @param[in] cmd ?
     * @param[in] idx ?
     * @param x ?
     * @param y ?
     * @param lon ?
     * @param lat ?
     * @param status ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_get_viz_custom_cmd( long cmd, int idx, double& x, double& y, double& lon, double& lat, long& status );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_must_update_external( bool val );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_image( void );

    /*! @brief ?
     *
     * @param[out] georef ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_georef(GEOREF& georef);
    /*! @brief ?
     *
     * @param[in] georef ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_georef(GEOREF& georef);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_georef(void);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_georef(void);

    /*! @brief ?
     *
     * @param value  ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_location(char** value);

/*
    int set_subScene_scene(SCENE scene);
    int clear_subScene_scene();
    int set_subScene_scene(const char * chScene);
    int get_subScene_scene(SCENE &scene);
    int get_is_subScene();
    int get_subScene_type(subSceneType *val);
*/
};


#endif // EV_PLUGIN_IMAGE_H
