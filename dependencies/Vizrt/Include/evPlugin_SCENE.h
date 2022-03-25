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

#if ! defined( EV_PLUGIN_SCENE_H )
#define EV_PLUGIN_SCENE_H

#include "evPlugin_BASE.h"
#include "evPlugin_SCRIPT.h"
#include "evPlugin_VIZ.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class MATERIAL;
class TEXTURE;
class FUNCTION;
class CONTAINER;
class evVertex3D;
class CAMERA;
class STAGE;
class SHARED_MEMORY;
class GRID;
class VIDEO_CHANNEL;
class PLUGIN_INSTANCE;
class SCRIPT_PLUGIN;
class AVCHANNEL;
class GFXCHANNEL;
class IMAGE_CHANNEL;
class SUPER_CHANNEL;
#ifdef HAS_VIZPHYSICS
class Physic;
#endif


//=========================================================================
// SCENE OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class SCENE : public BASE
{
public:
    /*! @brief get the local scene which is loaded
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get background color
     *
     * @param material ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_script( SCRIPT& value );

    /*! @brief get background color
     *
     * @param material ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_background_color( MATERIAL & material );

    /*! @brief set background color
     *
     * @param[in] material ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_background_color( MATERIAL & material );

    /*! @brief get background image
     *
     * @param[out] texture ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_background_image( TEXTURE & texture );

    /*! @brief set background image
     *
     * @param[in] texture ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_background_image( TEXTURE & texture );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_background_image_active( bool * value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_background_image_active( bool value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum alpha_clear_value
    {
        ALPHA_VIRTUAL,      /*!<  */
        ALPHA_FULLSCREEN,   /*!<  */
        ALPHA_OVERLAY       /*!<  */
    };

    /*! @brief get alpha clear value -> enum alpha_clear_value
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_alpha_clear_value( int * value );

    /*! @brief set alpha clear value with alpha_clear_value enum
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_alpha_clear_value( int value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum video_format
    {
        FORMAT_RGB=0x1907,  /*!<  */
        FORMAT_RGBA=0x1908  /*!<  */
    };

    /*! @brief get video format -> enum video format
     *
     * @param[in] video ?
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_video_format( int video, int * value );

    /*! @brief set video format with video_format enum
     *
     * @param[in] video ?
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_video_format( int video, int value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum video_download
    {
        DOWNLOAD_PROGRESSIVE,   /*!<  */
        DOWNLOAD_INTERLACED     /*!<  */
    };

    /*! @brief ?
     *
     * @param[in] video ?
       @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    __declspec(deprecated(" this is a deprecated function"))
    int get_video_download( int video, int * value );

    /*! @brief ?
     *
     * @param[in] video ?
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    __declspec(deprecated(" this is a deprecated function"))
    int set_video_download( int video, int value );   // set video format download method with video_download enum

    /*! @brief ?
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_current_camera( int * value );                             // get the current camera of this scene
    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_current_camera( int value );                              // set the current camera

    /*! @brief ?
     *
     * @param value ?
     * @param[in] layer ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_current_camera( int * value, VIZ::vizLayer layer);                             // get the current camera of this scene
    /*! @brief ?
     *
     * @param[in] value ?
     * @param[in] layer ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_current_camera( int value, VIZ::vizLayer layer);                              // set the current camera


    /*! @brief Returns the current viewing camera.
     *
     * @param cam ?
     * @return ?

     *
     * Returns the current viewing camera. In on-air mode, this call is identical to get_current_camera.
     * In authoring mode, this returns the current viewing camera, which may be an orthogonal camera.
     */
    int get_current_viewing_camera(CAMERA& cam);

    /*! @brief ?
     *
     * @param value ?
     * @param[in] function_name ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_function( FUNCTION & value, const char * function_name );   // get scene plugin with function plugin name

    /*! @brief with get_plugin_instance one can get hold of the plugin instance, which is on the scene
     *
     * @param[out] value ?
     * @param[in] pszName ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_plugin_instance(PLUGIN_INSTANCE& value, const char* pszName);

    /*! @brief Add a scene plugin to the scene.
     *
     * A valid location would be BUILT_IN*FUNCTION*MyScenePlugin.
     * @param[in] function_name ?
     * @return ?

     * @todo documentation to be done.
     */
    int create_function( const char * function_name );       // creates a new scene plugin

    /*! @brief ?
     *
     * @param[in] function_name
     * @return ?

     * @todo documentation to be done.
     */
    int delete_function( const char * function_name );       // deletes a scene plugin

    /*! @brief activate/deactivate the auto key feature
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_auto_key_active( bool * value );

    /*! @brief get video format download method -> enum video download
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_auto_key_active( bool value );

    /*! @brief set the position which is used to calculate the auto key
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_auto_key_position( float * x, float * y, float * z );

    /*! @brief set the position which is used to calculate the auto key
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_auto_key_position( float x, float y, float z );

    /*! @brief redraw the scene
     *
     * @return ?

     * @todo documentation to be done.
     */
    static int redraw( void );

    /*! @brief handle the root container of the scene
     *
     * @return ?

     * @todo documentation to be done.
     */
    int has_root( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_root( void );

    /*! @brief Returns the root container.
     */
    int get_root( CONTAINER & container );

    /*! @brief Finds a container named 'name'.
     *
     * @param[in] name ?
     * @param[out] container ?
     * @return ?

     *
     * This method performs a breadth-first search for a container named 'name'.
     * 'name' may be a path, such as "foo$bar", in which case the method first searches for a container named "foo"
     * and then, starting from there, for a sub-container named "bar". Leading $ signs
     * ("$foo$bar") are acceptable.
     * The result is saved in 'container'. If no container is found, container.valid() will be false.
     * See also CONTAINER::get_sub_container.
     */
    int get_container(const char *name, CONTAINER& container);

    int get_name( const char** name );

    /*! @brief ?
     *
     * @param[out] stage ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_stage( STAGE & stage );

    /*! @brief ?
     *
     * @param[out] container ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_edited_container(CONTAINER container );

    /*! @brief ?
     *
     * @param[out] container ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_edited_container(CONTAINER &container );

    /*! @brief s2v stuff
     *
     * @param[out] idx ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_s2v_index( int * idx );

    /*! @brief ?
     *
     * @param[in] idx ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_s2v_index( int idx );

    /*! @brief ?
     *
     * @param[in] idx ?
     * @param[out] name ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_s2v_name( int idx, char ** name );

    /*! @brief ?
     *
     * @param[in] idx ?
     * @param[out] name ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_s2v_name( int idx, const char * name );

    /*! @brief ?
     *
     * @param[in] idx ?
     * @param[out] position ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_s2v_pos( int idx, evVertex3D * position );

    /*! @brief ?
     *
     * @param[in] idx ?
     * @param[in] position ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_s2v_pos( int idx, const evVertex3D position );

    /*! @brief ?
     *
     * @param[in] idx ?
     * @param[out] angle ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_s2v_rot( int idx, float * angle );

    /*! @brief ?
     *
     * @param[in] idx ?
     * @param[in] angle ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_s2v_rot( int idx, const float angle );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_culling( bool value );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_culling( bool * value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum transp_sort_mode
    {
        SORT_TRANSP_OFF = 0,    /*!<  */
        SORT_TRANSP_ON = 1      /*!<  */
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum opaque_sort_mode
    {
        SORT_OPAQUE_OFF = 0,                /*!<  */
        SORT_OPAQUE_BY_Z = 2,               /*!<  */
        SORT_OPAQUE_BY_GSTATE = 3,          /*!<  */
        SORT_OPAQUE_BY_GSTATE_AND_Z = 4     /*!<  */
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum sort_priority
    {
        SORT_PRI_ENTEXTURE,             /*!<  */
        SORT_PRI_TEXTURE,               /*!<  */
        SORT_PRI_ENLIGHTING,            /*!<  */
        SORT_PRI_BACKFACE,              /*!<  */
        SORT_PRI_TWOSIDED_LIGHTING,     /*!<  */

        SORT_PRI_END,                   /*!<  */
        SORT_NUM_PRI                    /*!<  */
    };


    /*! @brief ?
     *
     * @param[in] transp_mode ?
     * @param[in] opaque_mode ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_zsort( int transp_mode, int opaque_mode );

    /*! @brief ?
     *
     * @param[in] transp_mode ?
     * @param[out] opaque_mode ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_zsort( int * transp_mode, int * opaque_mode );

    /*! @brief ?
     *
     * @param plist ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_sort_priority_list( int * plist );

    /*! @brief ?
     *
     * @param plist ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_sort_priority_list( int * plist );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_depth_buffer_state( bool value );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_depth_buffer_state( bool * value );

    int get_shared_memory(SHARED_MEMORY& sm);

    // TODO: add documentation
    int set_camera_near(float value);
    int set_camera_far(float value);
    int get_camera_near(float* pValue);
    int get_camera_far(float* pValue);

    int get_is_warm_up_stage(bool *bWarmup);
    int get_is_last_warm_up_frame(bool *bWarmup);

     /*! @brief ?
     *
     * @param grid
     * @return ?

     * @todo documentation to be done.
     */
    int get_unlocked_grid(GRID &grid);

     /*! @brief get specified grid
     *
     * @param ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_grid(GRID &grid, int gridNumber);

    /*! @brief sets the current scene grid
    *
    * @param ?
    * @return ?

    * @todo documentation to be done.
    */
    int set_grid(int gridNumber);

     /*! @brief ?
     *
     * @param [out] channel?
     * @param [in] channelID?
     * @return ?

     * @todo documentation to be done.
     */
    int get_video_channel(VIDEO_CHANNEL& channel, int channelID);

    /*! @brief ?
    *
    * @param [out] channel?
    * @param [in] channelID?
    * @return ?

    * @todo documentation to be done.
    */
    int get_avchannel(AVCHANNEL& channel, int channelID);

    /*! @brief returns a GFX_CHANNEL
    *
    * @param [out] gfx channel
    * @param [in] index (zero based)
    * @return ?

    * @todo documentation to be done.
    */
    int get_gfx_channel(GFXCHANNEL& channel, int index);
    
    /*! @brief get indices list of currently active gfx channels
    *
    * @param [out] indices gfx channels
    * @return number of indices in the list

    * @todo documentation to be done.
    */
    int get_active_gfx_channel(int **indices);

    /*! @brief returns an IMAGE_CHANNEL
    *
    * @param [out] image channel
    * @param [in] index (zero based)
    * @return ?

    * @todo documentation to be done.
    */
    int get_image_channel(IMAGE_CHANNEL& channel, int index);

    /*! @brief returns a SUPER_CHANNEL
    *
    * @param [out] super channel
    * @param [in] index (zero based)
    * @return ?

    * @todo documentation to be done.
    */
    int get_super_channel(SUPER_CHANNEL& channel, int index);

#ifdef HAS_VIZPHYSICS
    /*! @brief Get the physic object for this scene?
    *
    * @return Physic object?
    */
    Physic get_physic();
#endif // HAS_VIZPHYSICS

    /*! @brief with get_script_plugin_instance one can get hold of the script plugin instance, which is on the container
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_script_plugin_instance(PLUGIN_INSTANCE& value);

    /*! @brief with get_script_plugin_instance one can get hold of the script plugin instance, which is on the container
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_script_plugin_instance(SCRIPT_PLUGIN& value);

    /*! @brief applies the lens deformation to the passed screen coordinates
    *
    * @param[in] x The x position on screen.
    * @param[in] y The y position on screen.
    * @param[out] v3dPos
    * @return 1 if the call succeeds, otherwise 0.
    *
    */
    int deform_screen_pos(float &fX, float &fY);

    /*! @brief applies the inverse lens deformation to the passed screen coordinates
    *
    * @param[in] x The x position on screen.
    * @param[in] y The y position on screen.
    * @param[out] v3dPos
    * @return 1 if the call succeeds, otherwise 0.
    *
    */
    int undeform_screen_pos(float &fX, float &fY);

    /*! @brief Converts the screen position to the world position
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @return 1 if the call succeeds, otherwise 0.
     *
     */
    int screen_pos_to_world_pos(float fX, float fY, evVertex3D &v3dPos);

    /*! @brief Converts the screen position to current grid intersection point
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dPos
     * @return 1 if the call succeeds, otherwise 0.
     *
     * The returned coordinates are in world coordinate space.
     */
    int screen_pos_to_world_grid(float fX, float fY, evVertex3D &v3dPos);

    /*! @brief Converts the world position to the positino on the screen
     *
     * @param[in] v3dPos The local position
     * @param[out] x The x position on screen.
     * @param[out] y The y position on screen.
     * @return 1 if the call succeeds, otherwise 0.
     *
     */
    int world_pos_to_screen_pos(evVertex3D v3dPos, float &fX, float &fY);
};


#endif // EV_PLUGIN_SCENE_H
