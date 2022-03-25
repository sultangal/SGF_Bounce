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

#if ! defined( EV_PLUGIN_CONTAINER_H )
#define EV_PLUGIN_CONTAINER_H

#include "evPlugin_PLUGINEXTERN.h"
#include "evPlugin_BASE.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class VIZ_POSITION;
class ROTATION;
class SCALING;
class CENTER;
class ALPHA;
class KEY;
class MATERIAL;
class GEOMETRY;
class TEXTURE;
class PROJECTOR;
class PROJECTION_TARGET;
class EXPERT;
class MASK;
class MASK_TARGET;
class CLIPPER_TARGET;
class WINDOW_MASK;
class GEOREF;
class FUNCTION;
class evMatrix;
class DIRECTOR;
class ANIMATION;
class CONTAINER_FX;
class IMAGE;
class SHADER;
class evVertex3D;
class TRANSFORMATION;
class PLUGIN_INSTANCE;
class SCRIPT_PLUGIN;
class SCRIPT;
class CONTAINER_FX;
class INFOTEXT;
class VIEWPORT_TILE;
#ifdef HAS_VIZPHYSICS
class Rigidbody;
#endif

//=========================================================================
// CONTAINER OBJECT
//=========================================================================

/*! @brief ?
 *
 * @todo documentation to be done.
 */
class CONTAINER : public BASE
{
public:
    /*! @brief get container for plugin.
     *
     * with this function you get the container on which the plugin is located
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get container for plugin inheritor.
     *
     * with this function you get the container on which the plugin is inherited (shader)
     * @todo documentation to be done.
     */
    void local_inheritor( void );

    /*! @brief get container with name of container.
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    const CONTAINER& operator=(const char* name);

    /*! @brief copy container from another.
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    const CONTAINER& operator=(const CONTAINER& container);

    /*! @brief ?
     *
     * @param[in] number
     * @return ?

     * @todo documentation to be done.
     */
    const CONTAINER& operator=(int number);

    /*! @brief this method searches through the whole tree.
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     *
     * This method should no longer be used, as it has been superseded by SCENE::get_container.
     */
    void global_search(const char* name);

    /*! @brief Finds a sub-container named 'name'.
     *
     * This method performs a breadth-first search for a sub-container named 'name'.
     * 'name' may be a path, such as "foo$bar", in which case the method first searches for a container named "foo"
     * and then, starting from there, for a sub-container named "bar". Leading $ signs
     * ("$foo$bar") are acceptable.
     * The result is saved in 'container', which may point to the same container
     * as the 'this' pointer. If no container is found, container.valid() will be false.
     * See also SCENE::get_container.
     */
    int get_sub_container(const char *name, CONTAINER& container);

    /*! @brief set container visible (1) oder invisible (0).
     *
     * @param[in] visibility
     * @return ?

     * @todo documentation to be done.
     */
    int set_active(int visibility);

    /*! @brief is the container active.
     *
     * @param[out] pVsibility
     * @return ?

     * @todo documentation to be done.
     */
    int get_active( int *pVsibility );

    /*! @brief is the container visible.
     *
     * @param[in] bCheckParents
     * @param[in] bCheckAlphaValue
     * @param[out] pVisibility
     * @return ?

     * Returns true if this container is visible (ie, if it is active, has a scaling > 0 and
     * and alpha value (if any) > 0). If bCheckParents is true, the method returns true only
     * if the the container as well as all its parent containers are visible.
     * If bCheckAlphaValue == true, containers with alpha == 0.0 are considered invisible.
     */
    int get_is_visible( bool bCheckParents, bool bCheckAlphaValue, bool *pbVisbility );

    /*! @brief change the name of a container.
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    int set_name(const char* name);

    /*! @brief returns a pointer to the name string in Everest.
     *
     * @param[out] value
     * @return ?

     * @note DO NOT MODIFY!!! use set_name() instead
     * @todo documentation to be done.
     */
    int get_name(const char** value);


    //! Deprecated. Use get_name(const char** value).
    int get_name(char** value) { return get_name((const char**)value); }

    /*! @brief with get_script one can get hold of the script, which is on the container
     * bfu
     * @param[out] value ?
     * @return ?

     * \verbatim
        e.g. If you want to have a handle to a script that is assigned to a container
        use the following code
        CONTAINER container.local();
        SCRIPT script;
        container.get_script(script);

       \endverbatim
     * @todo documentation to be done.
     */
    int get_script( SCRIPT& value ); //bfu


    //! Deprecated. Use GetID().
    int get_id() const { return GetID(); }

    /*! @brief get the next container in the tree.
     *
     * @return ?

     * @todo documentation to be done.
     */

    /*! @brief Enables or disables exact picking.
     *
     * @param[in] value A flag indicating whether exact picking should be enabled or disabled.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * Exact picking affects the accuracy with which the test for inclusion of
     * the mouse cursor within a container is performed. If it is enabled, the
     * test is performed on a per-pixel basis. If it is disabled, the test takes
     * into account only the bounding box of the container.
     *
     * By default, exact picking is enabled.
     *
     * The state of the exact-picking flag affects the behavior of the
     * PLUGIN_ENTER_CONTAINER, PLUGIN_LEAVE_CONTAINER, PLUGIN_ENTER_SUB_CONTAINER,
     * and PLUGIN_LEAVE_SUB_CONTAINER callbacks.
     */
    int set_exact_picking(bool value);

    /*! @brief Gets the state of the exact-picking flag.
     *
     * @param[out] pValue A pointer to a bool that receives the state of the exact-picking flag.
     * @return 1 if the call succeeds, otherwise 0.
     * \sa set_exact_picking
     */
    int get_exact_picking(bool* pValue);

    /*! @brief Gets the local container index
     *
     * @param[out] pIndex A pointer to an int that receives the index
     * @return 1 if the call succeeds, otherwise 0.
     * \sa set_exact_picking
     */
    int get_local_index(int* pIndex);

    /*! @brief Gets the corresponding sub container to the passed index
     *
     * @param[in] index Requested container index
     * @param[out] container The returned container
     * @return 1 if the call succeeds, otherwise 0.
     * \sa set_exact_picking
     */
    int get_sub_container_by_index(int index, CONTAINER& container);

    /*! @brief Mouse cursor inclusion check.
     *
     * @param[out] pValue A pointer to a bool that receives the result.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * Returns true if and only if the mouse cursor is over the container.
     * For this method to work correctly, it is required
     * that at least one enter or leave callback be defined on the container or
     * on a super-container.
     */
    int contains_mouse_cursor(bool* pValue);

    /*! @brief Is container on top?.
     *
     * @param[out] pValue A pointer to a bool that receives the result.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * Returns true if and only if the mouse cursor is over the container
     * AND if the container is on top at the moouse cursor position.
     * For this method to work correctly, it is required
     * that at least one enter or leave callback be defined on the container or
     * on a super-container. Typically, this method is called within
     * PLUGIN_ENTER_CONTAINER or PLUGIN_ENTER_SUB_CONTAINER.
     */
    int is_on_top(bool* pValue);

    /*! @brief get screen bounds.
     *
     * @param[out] v3dBound1 contains left-bottom screen coordinates
     * @param[out] v3dBound2 contains right-top screen coordinates
     *
     * Returns screen coordinates defining the rectangle occupied by
     * the container.
     */
    int get_screen_bounds(evVertex3D &v3dBound1, evVertex3D &v3dBound2);

    /*! @brief Checks for bounding box inclusion.
     *
     * @param[in] v
     * @param[out] pResult
     *
     * Tests whether the point 'v' is inside the container's bounding box.
     * 'v' must be specified in world coordinates.
     */
    int is_vertex_in_bounding_box(const evVertex3D& v, bool* pResult);

    /*! @brief Checks for bounding box inclusion.
     *
     * @param[in] x The x coordinate of the screen point.
     * @param[in] y The y coordinate of the screen point.
     * @param[out] pResult\
     *
     * Tests whether the screen point (x, y) is inside the area
     * covered by the container's bounding box.
     */
    int is_screen_point_in_bounding_box(int x, int y, bool* pResult);

    /*! @brief Gets the uv coordinates of a specific screenpoint.
     *
     * @param[in] x The x coordinate of the screen point.
     * @param[in] y The y coordinate of the screen point.
     * @param[out] u The u coordinate.
     * @param[out] v The v coordinate.
     *
     * This function can be used to determine the uv texture coordinates
     * of a specific point on the screen.
     */
    int get_uv_coordinates_of_screen_point(int x, int y, float &u, float &v);

    /*! @brief Sets the containers screen position.
     *
     * @param[in] x The new x position on screen.
     * @param[in] y The new y position on screen.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * Sets the containers screen position the same way as you can do it via Artist GUI.
     * There must not be any rotation on the object! If you want to move rotated objects
     * to a certain screen position then use set_screen_position
     */
    int set_screen_position_ortho(int x, int y);

    /*! @brief Gets the containers screen position.
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * Gets the containers screen position the same way as you can do it via Artist GUI.
     * There must not be any rotation on the object! If you want to get the screen position
     * of rotated objects then you'll have to use get_screen_position instead.
     */
    int get_screen_position_ortho(int *x, int *y);

    int get_screen_position(int *x, int *y);

    /*! @brief Sets the containers screen size.
     *
     * @param[in] x The new width on screen.
     * @param[in] y The new height on screen.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * Sets the containers screen size the same way as you can do it via Artist GUI.
     * There must not be any rotation on the object! If you want to move rotated objects
     * to a certain screen position then use set_screen_position
     */
    int set_screen_size_ortho(int x, int y);

    /*! @brief Gets the containers screen size.
     *
     * @param[in] x The width on screen.
     * @param[in] y The height on screen.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * Gets the containers screen size the same way as you can do it via Artist GUI.
     * There must not be any rotation on the object! If you want to get the screen position
     * of rotated objects then you'll have to use get_screen_position instead.
     */
    int get_screen_size_ortho(int *x, int *y);

    /*! @brief Sets the containers center point without changing its position.
     *
     * @param[in] v3dCenter The new center position.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * @todo documentation to be done.
     */
    int set_center_position_locked(const evVertex3D& v3dCenter);

    /*! @brief Sets the container's center point to the passed screen position without affecting the container position.
     *
     * @param[in] fX The new center x screen position.
     * @param[in] fY The new center y screen position.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * @todo documentation to be done.
     */
    int set_center_screen_position_locked(float fX, float fY);

    /*! @brief Sets the container's center point to the passed screen position, using the current grid, without affecting the container position.
     *
     * @param[in] fX The new center x screen position.
     * @param[in] fY The new center y screen position.
     * @return 1 if the call succeeds, otherwise 0.
     *
     * @todo documentation to be done.
     */
    int set_center_screen_grid_position_locked(float fX, float fY);

    /*! @brief Converts the screen position to the local container position
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dPos
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you assign the returned vertex to the local container's
     * position then it moves exactly to the passed screenposition (orthogonal to camera).
     */
    int screen_pos_to_local_pos(float fX, float fY, evVertex3D &v3dPos);

    /*! @brief Converts the screen position to a position on the local object plane
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dPos
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you assign the returned vertex to the local container's
     * position then it moves exactly to the passed screenposition (on the object plane).
     */
    int screen_pos_to_local_plane_xy(float fX, float fY, evVertex3D &v3dPos);

    /*! @brief Converts the screen position to a position on the local object plane
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dPos
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you assign the returned vertex to the local container's
     * position then it moves exactly to the passed screenposition (on the object plane).
     */
    int screen_pos_to_local_plane_xz(float fX, float fY, evVertex3D &v3dPos);

    /*! @brief Converts the screen position to a position on the local object plane
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dPos
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you assign the returned vertex to the local container's
     * position then it moves exactly to the passed screenposition (on the object plane).
     */
    int screen_pos_to_local_plane_yz(float fX, float fY, evVertex3D &v3dPos);

    /*! @brief Converts the screen offset to a offset on the local object plane
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dOffset
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you add the returned vertex to the local container's
     * position then it moves exactly to the passed screenoffset (on the object plane).
     */
    int screen_offset_to_local_plane_xy_offset(float fX, float fY, evVertex3D &v3dOffset);

    /*! @brief Converts the screen offset to a offset on the local object plane
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dOffset
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you add the returned vertex to the local container's
     * position then it moves exactly to the passed screenoffset (on the object plane).
     */
    int screen_offset_to_local_plane_xz_offset(float fX, float fY, evVertex3D &v3dOffset);

    /*! @brief Converts the screen offset to a offset on the local object plane
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dOffset
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you add the returned vertex to the local container's
     * position then it moves exactly to the passed screenoffset (on the object plane).
     */
    int screen_offset_to_local_plane_yz_offset(float fX, float fY, evVertex3D &v3dOffset);

    /*! @brief Converts the screen offset to a offset on the local object plane
     *
     * @param[in] xOld The old x position on screen.
     * @param[in] yOld The old y position on screen.
     * @param[in] xNew The new x position on screen.
     * @param[in] yNew The new y position on screen.
     * @param[out] v3dOffset
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you add the returned vertex to the local container's
     * position then it moves exactly to the passed screenoffset (on the object plane).
     * With the ability to define start- and stoppoint you can do accurate movements of non-orthogonal objects as well.
     */
    int screen_offset_to_local_plane_xy_offset(float fXOld, float fYOld, float fXNew, float fYNew, evVertex3D &v3dOffset);

    /*! @brief Converts the screen offset to a offset on the local object plane
     *
     * @param[in] xOld The old x position on screen.
     * @param[in] yOld The old y position on screen.
     * @param[in] xNew The new x position on screen.
     * @param[in] yNew The new y position on screen.
     * @param[out] v3dOffset
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you add the returned vertex to the local container's
     * position then it moves exactly to the passed screenoffset (on the object plane).
     * With the ability to define start- and stoppoint you can do accurate movements of non-orthogonal objects as well.
     */
    int screen_offset_to_local_plane_xz_offset(float fXOld, float fYOld, float fXNew, float fYNew, evVertex3D &v3dOffset);

    /*! @brief Converts the screen offset to a offset on the local object plane
     *
     * @param[in] xOld The old x position on screen.
     * @param[in] yOld The old y position on screen.
     * @param[in] xNew The new x position on screen.
     * @param[in] yNew The new y position on screen.
     * @param[out] v3dOffset
     * @return 1 if the call succeeds, otherwise 0.
     *
     * This would mean if you add the returned vertex to the local container's
     * position then it moves exactly to the passed screenoffset (on the object plane).
     * With the ability to define start- and stoppoint you can do accurate movements of non-orthogonal objects as well.
     */
    int screen_offset_to_local_plane_yz_offset(float fXOld, float fYOld, float fXNew, float fYNew, evVertex3D &v3dOffset);

    /*! @brief Converts the screen position to current grid intersection point
     *
     * @param[in] x The x position on screen.
     * @param[in] y The y position on screen.
     * @param[out] v3dPos
     * @return 1 if the call succeeds, otherwise 0.
     *
     * The returned coordinates are in local container coordinate space.
     */
    int screen_pos_to_local_grid(float fX, float fY, evVertex3D &v3dPos);

    /*! @brief Converts local position to the position on the screen
     *
     * @param[in] v3dPos The local position
     * @param[out] x The x position on screen.
     * @param[out] y The y position on screen.
     * @return 1 if the call succeeds, otherwise 0.
     *
     */
    int local_pos_to_screen_pos(evVertex3D v3dPos, float &fX, float &fY);

    /*! @brief Converts the local position to a world coordinate space position
     *
     * @param[in] v3dPos The local position
     * @param[out] v3dPosWorld The returned world position
     * @return 1 if the call succeeds, otherwise 0.
     *
     */
    int local_pos_to_world_pos(evVertex3D v3dPos, evVertex3D &v3dPosWorld);

    /*! @brief Converts the world position to a local coordinate space position
     *
     * @param[in] v3dPos The world position
     * @param[out] v3dPosLocal The returned local position
     * @return 1 if the call succeeds, otherwise 0.
     *
     */
    int world_pos_to_local_pos(evVertex3D v3dPos, evVertex3D &v3dPosLocal);

    /*! @brief get the next container in the tree.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int next( void );

    /*! @brief get the previous container in the tree.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int prev( void );

    /*! @brief get the container one level up in tree.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int level_up( void );

    /*! @brief get the container one level down in tree.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int level_down( void );

    /*! @brief get the container one level up in tree.
     *
     * used for traveling inside merged objects.
     * @return ?

     * @todo documentation to be done.
     */
    int level_up_2( void );

    /*! @brief get the container one level down in tree.
     *
     * used for traveling inside merged objects.
     * @return ?

     * @todo documentation to be done.
     */
    int level_down_2( void );

    // Add a container relative to this container. After add the container if the
    // newly created containers. (works like next(), prev()...)


    /*! @brief add container previous to this one.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int add_prev( void );

    /*! @brief add container next to this one.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int add_next( void );

    /*! @brief add container one level down to this one
     *
     * @return ?

     * @todo documentation to be done.
     */
    int add_level_down( void );

    /*! @brief check if there are other containers previous to this container.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int has_prev( void );

    /*! @brief check if there are other containers next to this container.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int has_next( void );

    /*! @brieftran check if there are other containers down to this container (child).
     *
     * @return ?

     * @todo documentation to be done.
     */
    int has_level_down( void );

    /*! @brieftran check if there are other containers up to this container (parent).
     *
     * @return ?

     * @todo documentation to be done.
     */
    int has_level_up( void );

    /*! @brief delete the container and all container under it.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_all( void );

    /*! @brief delete only the containers under this container.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_under( void );

    /*! @brief directional enumerations.
     *
     * enum values for move and copy.
     */
    enum where
    {
        NEXT=1,         /*!<  */
        PREVIOUS=2,     /*!<  */
        LEVEL_DOWN=3,   /*!<  */
        LEVEL_UP=4      /*!<  */
    };

    /*! @brief move the container to target and where
     *
     * @param target ?
     * @param[in] where gives the direction
     * @return ?

     * @todo documentation to be done.
     */
    int move(CONTAINER& target, int where) const;

    /*! @brief copy the container next, previous.... to target
     *
     * @param target ?
     * @param[in] where gives the direction
     * @return ?

     * @todo documentation to be done.
     */
    int copy(CONTAINER& target, int where) const;

    /*! @brief copies the container to target container.
     *
     * @param  target ?
     * @return ?

     * \warning existing data will be overwritten!
     * @todo documentation to be done.
     */
    int copy(CONTAINER& target) const;

    /*! @brief set position of container with position object.
     *
     * @param[in] position ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_position( const VIZ_POSITION& position );

    /*! @brief set rotation of container with rotation object.
     *
     * @param[in] rotation ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_rotation( const ROTATION& rotation );

    /*! @brief set scaling of container with scaling object.
     *
     * @param[in] scaling ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_scaling( const SCALING& scaling );

    /*! @brief set center.
     *
     * @param[in] center ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_center( const CENTER& center );

    /*! @brief set alpha of container.
     *
     * @param[in] alpha ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_alpha( const ALPHA& alpha );

    /*! @brief set key.
     *
     * @param[in] key ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_key( const KEY& key );

    /*! @brief set material of container.
     *
     * @param[in] material ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_material( const MATERIAL& material );

    /*! @brief set material of container.
     *
     * @param[in] pszLocation ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_material( const char* pszLocation );

    /*! @brief give container a geometry.
     *
     * @param[in] geometry ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_geometry( const GEOMETRY& geometry );

    /*! @brief map on container a texture.
     *
     * @param[in] texture ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_texture( const TEXTURE& texture );

    /*! @brief map on container a shader.
    *
    * @param[in] shader ?
    * @return ?

    * @todo documentation to be done.
    */
    int set_shader(const SHADER& shader);

    /*! @brief set viewport tile object.
     *
     * @param[in] texture ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_viewport_tile( const VIEWPORT_TILE& viewportTile );

    /*! @brief set projector object.
     *
     * @param projector ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_projector( PROJECTOR& projector );

    /*! @brief set projection_target object.
     *
     * @param target ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_projection_target( PROJECTION_TARGET& target );

    /*! @brief set expert object
     *
     * @param expert ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_expert( EXPERT& expert );

    /*! @brief set infotext object
     *
     * @param expert ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_infotext( INFOTEXT& infotext );

    /*! @brief set mask object
     *
     * @param mask ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_mask( MASK& mask );

    /*! @brief set mask target object.
     *
     * @param target ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_mask_target( MASK_TARGET& target );

    /*! @brief set clipper target object
     *
     * @param target ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_clipper_target( CLIPPER_TARGET& target );

    /*! @brief set active flag of alpha! 0 and 1
     *
     * @param[in] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_alpha_active( int active );

    /*! @brief set active flag of key
     *
     * @param[in] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_key_active( int active );

    /*! @brief activate or inactivate geometry
     *
     * @param[in] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_geometry_active( int active );

    /*! @brief activate or inactivate shader
    *
    * @param[in] active ?
    * @return ?

    * @todo documentation to be done.
    */
    int set_shader_active(int active);

    /*! @brief ?
     *
     * @param[in] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_expert_active( bool active );

    /*! @brief ?
     *
     * @param[in] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_mask_active( bool active );

    /*! @brief ?
     *
     * @param[in] active
     * @return ?

     * @todo documentation to be done.
     */
    int set_mask_target_active( bool active );

    /*! @brief ?
     *
     * @param[in] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_clipper_target_active( bool active );

    /*! @brief Gets the container's transformation object.
     *
     * @param[out] transformation object
     * @return 1 if successful, otherwise 0
     */
    int get_transformation(TRANSFORMATION& transformation);

    /*! @brief get the position of container.
     *
     * @param[out] position ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_position( VIZ_POSITION& position );

    /*! @brief get the rotation of container
     *
     * @param[out] rotation ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_rotation( ROTATION& rotation );

    /*! @brief get scaling
     *
     * @param[out] scaling ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_scaling( SCALING& scaling );

    /*! @brief get center
     *
     * @param[out] center ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_center( CENTER& center );

    /*! @brief get alpha object
     *
     * @param[out] alpha ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_alpha( ALPHA& alpha );

    /*! @brief get key
     *
     * @param[out] key ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_key( KEY& key);

    /*! @brief get material object
     *
     * @param[out] material ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_material( MATERIAL& material );

    /*! @brief get the geometry
     *
     * @param[out] geometry ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_geometry( GEOMETRY& geometry );

    /*! @brief get the texture
     *
     * @param[out] texture ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_texture( TEXTURE& texture );

    __declspec(deprecated("get_multi_texture() function is deprecated. Use get_texture instead."))
    int
    get_multi_texture(int iId, TEXTURE &texture)
    {
#if defined _DEBUG
        _vizprintf( "get_multi_texture() function is deprecated\n" );
        __debugbreak();
#endif // #if defined _DEBUG

        if(iId == 0 ) return get_texture(texture);
        return 0;
    }

    /*! @brief get the shader
    *
    * @param[out] shader ?
    * @return ?

    * @todo documentation to be done.
    */
    int get_shader(SHADER& shader);

    /*! @brief get the viewport tile
     *
     * @param[out] viewport tile ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_viewport_tile( VIEWPORT_TILE& viewportTile );

    /*! @brief get projector object
     *
     * @param projector ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_projector( PROJECTOR& projector );

    /*! @brief get projection_target object
     *
     * @param[out] target ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_projection_target( PROJECTION_TARGET& target );

    /*! @brief get expert object
     *
     * @param[out] expert ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_expert( EXPERT& expert );

    /*! @brief get infotext object
     *
     * @param[out] infotext ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_infotext( INFOTEXT& infotext );

#ifdef HAS_VIZPHYSICS
    /*! @brief get rigidbody object
    *
    * @param[out] rigidbody ?
    * @return ?

    * @todo documentation to be done.
    */
    int get_rigidbody(Rigidbody& rigidbody);
#endif //HAS_VIZPHYSICS

    /*! @brief get mask object
     *
     * @param[out] mask ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_mask( MASK& mask );

    /*! @brief get mask target object
     *
     * @param target ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_mask_target( MASK_TARGET& target );

    /*! @brief get clipper target object
     *
     * @param target ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_clipper_target( CLIPPER_TARGET& target );

    /*! @brief with get_function one can get hold of the plugin function, which is on the container
     *
     * @param[out] value ?
     * @param[in] pszName ?
     * @return ?

     * \verbatim
        e.g. If you want to have a handle to a function plugin <pszName> that is assigned to a container
        use the following code
        CONTAINER container.local();
        FUNCTION function;
        container.get_function(function, "MyFunction");

        we have to use the get_function call with a function name, because it is possible to assign
        more than one function to a container
       \endverbatim
     * @todo documentation to be done.
     */
    int get_function( FUNCTION& value, const char* pszName );

    /*! @brief with get_plugin_instance one can get hold of the plugin instance, which is on the container
     *
     * @param[out] value ?
     * @param[in] pszName ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_plugin_instance(PLUGIN_INSTANCE& value, const char* pszName);

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

    /*! @brief get number of all function plugins of a container
    *
    * @param[out] num ?
    * @return ?

    * @todo documentation to be done.
    */
    int get_number_of_functions(unsigned int& num);

    /*! @brief get all function plugins of a container
     *
     * create a local array of function objects and also pass the size of this array
     * the first unused function in this array will be "invalid": function_array[x].valid() == false
     * to mark the end of the array.
     * @param[out] function_array ?
     * @param[in] size_array ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_functions( FUNCTION function_array[], int size_array );


    /*! @brief is alpha active.
     *
     * @param[out] pActive ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_alpha_active( int* pActive );

    /*! @brief is key active.
     *
     * @param[out] pActive ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_key_active( int* pActive );

    /*! @brief is geometry active
     *
     * @param[out] pActive ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_geometry_active( int* pActive );

    /*! @brief is shader active
    *
    * @param[out] pActive ?
    * @return ?

    * @todo documentation to be done.
    */
    int get_shader_active(int* pActive);

    /*! @brief ?
     *
     * @param[out] pActive ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_expert_active( bool* pActive );

    /*! @brief ?
     *
     * @param pActive ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_mask_active( bool* pActive );

    /*! @brief ?
     *
     * @param[out] pActive ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_mask_target_active( bool* pActive );

    /*! @brief ?
     *
     * @param[out] Active ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_clipper_target_active( bool* Active );

    /*! @brief get the absolute position of container.
     *
     * the the position of the object to the root coordinate system.
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_absolute_position(float *x, float *y, float *z);

    /*! @brief get the absolute rotation of container.
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_absolute_rotation(float *x, float *y, float *z);

    /*! @brief get the absolute scaling of container.
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_absolute_scaling(float *x, float *y, float *z);

    /*! @brief transformations of a container as matrix
     *
     * @param matrix ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_transformation_matrix( evMatrix& matrix );

    /*! @brief ?
     *
     * @param matrix ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_transformation_matrix( evMatrix& matrix );

    /*! @brief ?
     *
     * @param matrix ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_external_matrix(evMatrix& matrix);

    /*! @brief ?
     *
     * @param matrix ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_inverse_matrix( evMatrix& matrix );

    /*! @brief recalculate transformation matrix of container
     *
     * @return ?

     * This function is useful if you can't wait one field for the updated matrix.
     * Use it carefully and only where it is really needed (current transformation matrix,
     * transformed bounding box, screen-position or screen-size)
     */
    int recompute_matrix();

    /*! @brief open-status of tree under container
     *
     * open or close tree underneath container.
     * changes the display of the scenetree in the GUI, does not influence rendering.
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_open( bool value );

    /*! @brief is tree open or close unterneath
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_open( bool* value );

    /*! @brief get the position of boundingbox of the container
     *
     * @param[out] lbb_x left-bottom-back x position
     * @param[out] lbb_y left-bottom-back y position
     * @param[out] lbb_z left-bottom-back z position
     * @param[out] rtf_x right-top-front x position
     * @param[out] rtf_y right-top-front y position
     * @param[out] rtf_z right-top-front z position
     * @return ?

     * \warning this function is slow, so use this carefully!
     * @todo documentation to be done.
     */
    int get_bounding_box(float* lbb_x, float* lbb_y, float* lbb_z, float* rtf_x, float* rtf_y, float* rtf_z);

    /*! @brief ?
     *
     * @param[out] lbb_x left-bottom-back x position
     * @param[out] lbb_y left-bottom-back y position
     * @param[out] lbb_z left-bottom-back z position
     * @param[out] rtf_x right-top-front x position
     * @param[out] rtf_y right-top-front y position
     * @param[out] rtf_z right-top-front z position
     * @return ?

     * @todo documentation to be done.
     */
    int get_bounding_box_no_inactive_nodes(float* lbb_x, float* lbb_y, float* lbb_z, float* rtf_x, float* rtf_y, float* rtf_z);

    /*! @brief this function can be used by opengl plugins to set a bounding box
     *
     * @param[in] lbb_x left-bottom-back x position
     * @param[in] lbb_y left-bottom-back y position
     * @param[in] lbb_z left-bottom-back z position
     * @param[in] rtf_x right-top-front x position
     * @param[in] rtf_y right-top-front y position
     * @param[in] rtf_z right-top-front z position
     * @return ?

     * @todo documentation to be done.
     */
    int set_bounding_box(float lbb_x, float lbb_y, float lbb_z, float rtf_x, float rtf_y, float rtf_z);

    /*! @brief this function restores the bounding box parameters as they were before set_bound_box
     *
     * @return ?

     * @todo documentation to be done.
     */
    int reset_bounding_box( void );

    /*! @brief create a material for the container.
     *
     * If the material is not found in the database, a default material is created.
     *
     * @param[in] pszMat name of material in the database.
     * @param[in] always if true, always set or reset the material, even if pszMat is an invalid location; otherwise set the material only, if pszMat is a valid location
     * @return ?

     * @todo documentation to be done.
     */
    int create_material( const char* pszMat, bool always = true );

    /*! @brief create a geometry for the container.
     *
     * pszGeom can be on of
        - BUILT_IN*GEOM*\<GeomName\> where GeomName is the Name of
          a geometry plugin.
        - GEOM*ObjectName where ObjectName is the Name of an imported
          Geometry in the Everest Geometry Database
     *
     * @param[in] pszGeom ?
     * @return ?

     * @todo documentation to be done.
     */
    int create_geometry( const char* pszGeom );

    /*! @brief create a geometry for the container using background loading.
    *
    * pszGeom can be on of
    - BUILT_IN*GEOM*\<GeomName\> where GeomName is the Name of
    a geometry plugin.
    - GEOM*ObjectName where ObjectName is the Name of an imported
    Geometry in the Everest Geometry Database
    *
    * @param[in] pszGeom ?
    * @param[out] requestId The request ID of the background loading request
    * @return ?

    * @todo documentation to be done.
    */
    int create_geometry_bgl(const char* pszGeom, unsigned int& requestId);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_key( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_alpha( void );

    /*! @brief Creates a texture for the material using an image defined by value.
     *
     * @param pszTexture value e.g. IMAGE*ImageName
     * @return ?

     * @todo documentation to be done.
     */
    int create_texture( const char* pszTexture );

    /*! @brief Creates a texture for the material using an image id.
     *
     * @param image ?
     * @return ?

     * @todo documentation to be done.
     */
    int create_texture( IMAGE& image );

    /*! @brief Creates a texture for the material using an image defined by value using background loading.
    *
    * @param[in] pszTexture value e.g. IMAGE*ImageName
    * @param[out] requestId The request ID of the background loading request
    * @return ?

    * @todo documentation to be done.
    */
    int create_texture_bgl(const char* pszTexture, unsigned int& requestId);

    __declspec(deprecated("create_multi_texture() function is deprecated. Use create_texture instead."))
    int create_multi_texture(int iId , IMAGE& image)
    {
#if defined _DEBUG
        _vizprintf( "create_multi_texture() function is deprecated\n" );
        __debugbreak();
#endif // #if defined _DEBUG
        if(iId == 0 )
            return create_texture(image);
        return 0;
    }

    /*! @brief creates a viewport tile object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_viewport_tile( void );

    /*! @brief creates a projector object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_projector( void );

    /*! @brief creates a projection target object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_projection_target( void );

    /*! @brief creates an expert object
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_expert( void );

    /*! @brief creates an infotext object
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_infotext( void );

#ifdef HAS_VIZPHYSICS
    /*! @brief creates an rigidbody object
    *
    * @return ?

    * @todo documentation to be done.
    */
    int create_rigidbody(void);
#endif // HAS_VIZPHYSICS

    /*! @brief creates a mask object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_mask( void );

    /*! @brief creates a mask target object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_mask_target( void );

    /*! @brief creates a clipper target object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int create_clipper_target( void );

    /*! @brief Add a function plugin to a container.
     *
     * A valid location would be BUILT_IN*FUNCTION*MyFunctionPlugin.
     * @param pszFunction ?
     * @return ?

     * @todo documentation to be done.
     */
    int create_function( const char* pszFunction );

    /*! @brief delete the material from container.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_material( void );

    /*! @brief delete the geometry from container.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_geometry( void );

    /*! @brief delete the key from this container
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_key( void );

    /*! @brief delete the alpha from this container
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_alpha( void );

    /*! @brief delete the texture from this container
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_texture( void );

    __declspec(deprecated("delete_multi_texture() function is deprecated. Use delete_texture instead."))
    int delete_multi_texture(int iId )
    {
#if defined _DEBUG
        _vizprintf( "delete_multi_texture() function is deprecated\n" );
        __debugbreak();
#endif // #if defined _DEBUG
        if(iId == 0 )
            return delete_texture();
        return 0;
    }

    /*! @brief delete the viewport tile from this container
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_viewport_tile( void );

    /*! @brief delete a function plugin fro.m this container.
     *
     * @param pszFunction ?
     * @return ?

     * @warning do not call this function within the function plugin
     *          that you want to remove!
     * @todo documentation to be done.
     */
    int delete_function( const char* pszFunction );

    /*! @brief delete the shader from this container
    *
    * @return ?

    * @todo documentation to be done.
    */
    int delete_shader( void );

    /*! @brief deletes the projetor object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_projector( void );

    /*! @brief deletes the projection target object
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_projection_target( void );

    /*! @brief deletes the expert object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_expert( void );

    /*! @brief deletes the infotext object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_infotext( void );

#ifdef HAS_VIZPHYSICS
    /*! @brief deletes the rigidbody object
    *
    * @return ?

    * @todo documentation to be done.
    */
    int delete_rigidbody(void);
#endif // HAS_VIZPHYSICS

    /*! @brief deletes the mask object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_mask( void );

    /*! @brief deletes the mask target object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_mask_target( void );

    /*! @brief deletes the clipper target object.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_clipper_target( void );

    /*! @brief deletes all animation channels
     *
     * @return ?

     * @todo documentation to be done.
     */
    int delete_animation( void );

    /*! @brief copies animation channels from source container
     *
     * @param[in] source ?
     * @return ?

     * @todo documentation to be done.
     */
    int copy_animation_from(CONTAINER &source);

    /*! @brief ?
     *
     *
     */
    enum Mode {
            eModeNone = 0,          /*!<  */
            eModeNoTexture = 1,     /*!<  */
            eModeNoMaterial = 2,    /*!<  */
            eModeNoDelete = 4,      /*!<  */
            eModeNoCopy = 8,        /*!<  */
            eModeNoMove = 16,       /*!<  */
            eModeNoProps = 32,      /*!<  */
    };

    /*! @brief ?
     *
     * @param[in] value ?
     * @param[in] add ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_mode( int value, bool add = false );


        /*
        Geographical (longitude, latitude,z) to position (x,y) conversion

        The given container will be searched upwards until there is a container
         with an image with geographical data.
        */


    /*! @brief ?
     *
     * @param[in] longitude ?
     * @param[in] latitude ?
     * @param[in] height ?
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_llz2rs(double longitude, double latitude, double height ,float& x, float& y, float& z);

    /*! @brief ?
     *
     * @param[in] longitude ?
     * @param[in] latitude ?
     * @param[in] height ?
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_llz2rsLocal(double longitude, double latitude, double height ,float& x, float& y, float& z);

    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @param[out] longitude ?
     * @param[out] latitude  ?
     * @param[out] height    ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_rs2llz(float x, float y, float z, double& longitude, double& latitude, double& height);

    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @param[out] longitude ?
     * @param[out] latitude  ?
     * @param[out] height    ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_rs2llzLocal(float x, float y, float z, double& longitude, double& latitude, double& height);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_llz2rsNormalized(double longitude, double latitude, double height ,float& x, float& y, float& z);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_rs2llzNormalized(float x, float y, float z, double& longitude, double& latitude, double& height);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_llz2rsModel(double longitude, double latitude, double height ,float& x, float& y, float& z);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_rs2llzModel(float x, float y, float z, double& longitude, double& latitude, double& height);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool is_geo_image(void);

    /*! @brief ?
     *
     * @param minx ?
     * @param maxx ?
     * @param miny ?
     * @param maxy ?
     * @return ?

     * @todo documentation to be done.
     */
    bool geo_get_bbox(float& minx, float& maxx, float& miny, float& maxy);

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
     * @param[in] b ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_georef_active(bool b);

    /*! @brief ?
     *
     * @param b ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_georef_active(bool* b);

    /*! @brief look for georef.

        look for georef on the container and image
        and up in the tree, until one is found.

        @param g ?
        @param[in] bsearchTree ?
        @return ?

        @todo documentation to be done.
     */
    int get_georefClosest(GEOREF&g, bool bsearchTree);

    /*! @brief ?
     *
     *
     * @todo documentation to be done.
     */
    enum rot_order
    {
        ROT_ORDER_XYZ = 0,
        ROT_ORDER_ZYX = 1,
        ROT_ORDER_ZXY = 2,
        ROT_ORDER_YXZ = 3,
        ROT_ORDER_YZX = 4,
        ROT_ORDER_XZY = 5
    };

    /*! @brief Returns enum rot_order above
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_rotations_order( void );

    /*! @brief Set enum rot_order above
     *
     * @param rotOrder ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_rotations_order( int rotOrder );

    /*! @brief Returns true if the container has been changed.
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_edited( bool * value );

    /*! @brief Returns true if the container was merged.
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_is_merged( bool * value );

    /*! @brief Returns true if the container was merged
        and contains animation.
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_is_merged_and_animated( bool * value );

    /*! @brief Returns true if the container was merged
        and contains a control group.
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_is_merged_and_controlled( bool * value );

    /*! @brief get a director for this container
     *
     * @param[out] director ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_director( DIRECTOR & director );

    //! @brief Sets the container offset in all directors referencing this container.
    int set_animation_offset(double offset);
    // set container to draw the geometry
    int set_draw_geometry_active(int value);
    // is the container drawing the geometry?
    int get_draw_geometry_active(int *value);

    int  set_force_transparency(int force);
    int  get_force_transparency(int *force);

    int  create_shader(const char * shader_name);

     /*! @brief set a geometry for the container using references.
     * If the geometry is in the pool references are used for the
     * geometries and materials of its subcontainers.
     * If no pool object is found a new geometry is created.
     *
     * @param[in] pszGeom the path of a geometry object, e.g. "GEOM*ObjectName"
     * @return ?
     */
    int set_reference_geometry( const char* pszGeom );

     /*! @brief calculate intersection for projected ray from a screen-space position with a object surface.
     * The intersection point is returned in world coordinates.
     *
     * @param[in] x screen position
     * @param[in] y screen position
     * @param[out] v3dPos intersection point
     * @return ?
     */
    int get_screen_point_to_geom_surface(int x, int y, evVertex3D &v3dPos);

     /*! @brief set if to render or not the container
     *
     * @param[in] value
     * @return ?
     */
    int set_show(int value);

    /*! @brief get if to render or not the container
     *
     * @param[out] value
     * @return ?
     */
    int get_show(int *value);

     /*! @brief render container
     *
     * @param[in] render transformation
     * @return ?
     */
    int render(bool render_transformation);

     /*! @brief render geometry
     *
     * @param[in] render transformation
     * @return ?
     */
    int render_geometry(bool render_transformation);

    /*! @brief set container fx
     *
     * @param[in] container fx
     * @return ?
     */
    int set_container_fx(CONTAINER_FX&);

    /*! @brief get container_fx object
     *
     * @param[in] container_fx object
     * @return ?
     */
    int get_container_fx(CONTAINER_FX&);

    /*! @brief set container fx active on/off
     *
     * @param[in] bool on/off
     * @return ?
     */
    int set_container_fx_active(bool);

    /*! @brief get container fx active
     *
     * @param[in] bool on/off
     * @return ?
     */
    int get_container_fx_active(bool*);

    /*! @brief creates a container_fx object
     *
     * @param[in] bool on/off
     * @return ?
     */
    int create_container_fx();

    /*! @brief deletes the container_fx object
     *
     * @param[in] bool on/off
     * @return ?
     */
    int delete_container_fx();

    /*! @brief force recalculating the container's matrix
     *
     * @param[in]
     * @return ?
     */
    int set_force_calculate_matrix();

    /*! @brief get container uuid
     *
     * @param[out] uuid
     * @param[in] uuid string length
     * @return ?
     */
    int get_uuid(char* psUuidString, int iMaxStringLength);

    /*! @brief get geometry background loading state
    * 
    * @param[out] true if the geometry in this container is currently being loaded in the background
    * @return ?
    */
    int get_is_background_loading_geometry(bool& loading);
};


#endif // EV_PLUGIN_CONTAINER_H
