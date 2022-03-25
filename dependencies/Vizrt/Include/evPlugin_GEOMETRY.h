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

#if ! defined( EV_PLUGIN_GEOMETRY_H )
#define EV_PLUGIN_GEOMETRY_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;
class PLUGIN_PARAMETER;
class GEOMETRY_MODIFIER;
class ANIMATION;

// the geometry types
enum GEOMETRY_TYPE
{
    GEOMETRY_DEFAULT = 0,
    GEOMETRY_IMPORT,
    GEOMETRY_TEXT,
    GEOMETRY_IMAGE,
    GEOMETRY_PLUGIN,
    GEOMETRY_CLOCK,
    GEOMETRY_POLYGON
};

//=========================================================================
// GEOMETRY OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class GEOMETRY : public BASE
{
public:

    /*! @brief get gemoetry of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief geometry of container with containername
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    const GEOMETRY& operator=( const char * container );

    /*! @brief gemoetry of CONTAINER
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    const GEOMETRY& operator=( const CONTAINER& container );

    /*! @brief copy gemoetry from another gemoetry
     *
     * @param geometry ?
     * @return ?

     * @todo documentation to be done.
     */
    const GEOMETRY& operator=( const GEOMETRY& geometry );

    /*! @brief gets geometry name
     *
     * @param[out] pName ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_name(const char** pName);

    /*! @brief with class PLUGIN_PARAMETER you can manipulate all values of geometry
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int set( PLUGIN_PARAMETER & parameter );

    /*! @brief with class PLUGIN_PARAMETER get all values of geometry
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int get( PLUGIN_PARAMETER & parameter );

    /*! @brief Modifies scaling of texture vertices. Texture vertices are scaled
     *
     * @param scale ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_texcoord_scale( float scale );

    /*! @brief ?
     *
     * between 0.0 and 1.0. If you need a different range, send you texture
     * vertices between 0.0 and 1.0 but use a different scale factor
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_texcoord_scale( float * value );

    /*! @brief returns type id geometry
     *
     * @param[out] value pointer to get type id
     * @return 1 if the correct type id is returned
     */
    int get_type( int * value );

    /*! @brief returns a pointer to the name string in Everest. Do NOT modify!!!
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_type( char ** value );

    /*! @brief if the geometry is a plugin, it will mark the geometry for a rebuild
     *
     * @return ?

     * @todo documentation to be done.
     */
    int rebuild( void );

    /*! @brief do not mark the geometry, rebuild it right now!!!
     *
     * @return ?

     * @todo documentation to be done.
     */
    int rebuild_now( void );

    /*! @brief builds a new geometry
     *
     * @return ?

     * @todo documentation to be done.
     */
    int build_new_geom( void );

    /*! @brief ends geometry building
     *
     * @return ?

     * @todo documentation to be done.
     */
    int geom_done( void );

    /*! @brief save the geometry to the database; set name to NULL to save to current db location
     *
     * @param[in] name ?
     * @return ?

     * @todo documentation to be done.
     */
    int geom_save( char * name );

    /*! @brief ?
     *
     * @param[in] type ?
     * @param[in] lod ?
     * @param no_vertices ?
     * @param has_normals ?
     * @param has_texc ?
     * @param has_color ?
     * @return ?

     * @todo documentation to be done.
     */
    bool data_read_init( int type, int lod, int & no_vertices, bool & has_normals, bool & has_texc, bool & has_color );

    /*! @brief ?
     *
     * @param meshtype ?
     * @param no_vertices_in_mesh ?
     * @return ?

     * @todo documentation to be done.
     */
    void data_read_next_mesh( int & meshtype, int & no_vertices_in_mesh );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void data_read_next_vertex( void );

    /*! @brief ?
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void data_read_get_vertex ( float & x, float & y, float & z );

    /*! @brief ?
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void data_read_get_normals( float & x, float & y, float & z );


    /*! @brief ?
     *
     * @param[out] s ?
     * @param[out] t ?
     * @return ?

     * @todo documentation to be done.
     */
    void data_read_get_texc( float &s, float &t );

    /*! @brief ?
     *
     * @param[out] color ?
     * @return ?

     * @todo documentation to be done.
     */
    void data_read_get_color( unsigned long int & color );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void data_read_end( void );

    /*! @brief use the DETAIL_XY and STYLE_XY defines together with this function.
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_detail_setting( int value );

    /*! @brief get the currently used level of detail of the GEOMETRY object
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_detail( int * value );

    /*! @brief get the build count
     *
     * @param[out] build_count ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_build_count(int* build_count);

    /*! @brief ?
     *
     * @param[in] msg ?
     * @param[in] param ?
     * @param[out] ret ?
     * @return ?

     * @todo documentation to be done.
     */
    int dispatcher( ULONG_PTR msg, ULONG_PTR param, ULONG_PTR & ret );

    /*! @brief ?
     *
     * @param[in] geom_type ?
     * @param[in] lod ?
     * @param[out] geom_modifier ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_geom_modifier( int geom_type, int lod, GEOMETRY_MODIFIER & geom_modifier );

    /*! @brief Gets the bounding box of the geometry.

     * @param[out] lbb_x ?
     * @param[out] lbb_y ?
     * @param[out] lbb_z ?
     * @param[out] rtf_x ?
     * @param[out] rtf_y ?
     * @param[out] rtf_z ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_bounding_box(float* lbb_x, float* lbb_y, float* lbb_z, float* rtf_x, float* rtf_y, float* rtf_z);

    /*! @brief Causes PLUGIN_GEOMETRY_CHANGED to be invoked whenever
     * the geometry's text changed.
     *
     * @return true if successful
     */
    bool register_text_changed_callback();

    /*! @brief Causes PLUGIN_GEOMETRY_CHANGED to be invoked whenever
     * the geometry changed.
     *
     * @return true if successful
     */
    bool register_changed_callback();

    /*! @brief Removes the binding set up by register_changed_callback.
     *
     * @return true if successful
     */
    bool unregister_changed_callback();
};

#endif // EV_PLUGIN_GEOMETRY_H
