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

#if ! defined( EV_PLUGIN_BASE_H )
#define EV_PLUGIN_BASE_H

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;
class CAMERA;
class LIGHT;

#include "THeapArray.h"

/*!@brief {brief description}
 *
 * {a more elaborate description of enum}
 * @todo documentation to be done.
 */
enum EClassId
{
    CID_NONE,           /*!<  */
    CID_STAGE,          /*!<  */
    CID_DIRECTOR,       /*!<  */
    CID_CHANNEL,        /*!<  */
    CID_KEYFRAME,       /*!<  */
    CID_CONTAINER,      /*!<  */
    CID_POSITION,       /*!<  */
    CID_ROTATION,       /*!<  */
    CID_SCALING,        /*!<  */
    CID_CENTER,         /*!<  */
    CID_IMAGE,          /*!<  */
    CID_FONT,           /*!<  */
    CID_ALPHA,          /*!<  */
    CID_KEY,            /*!<  */
    CID_MATERIAL,       /*!<  */
    CID_GEOMETRY,       /*!<  */
    CID_FUNCTION,       /*!<  */
    CID_TEXTURE,        /*!<  */
    CID_CAMERA,         /*!<  */
    CID_LIGHT,          /*!<  */
    CID_SCENE,          /*!<  */
    CID_POOL,           /*!<  */
    CID_CLOCK,          /*!<  */
    CID_SHADER,         /*!<  */
    CID_SCRIPT,         /*!<  */
    CID_SCRIPT_PLUGIN   /*!<  */
};





//=========================================================================
// BASE CLASS: all objects inherit this base class
//=========================================================================

/*! @brief base class
 *
 *  BASE CLASS: all objects inherit this base class
 * @todo documentation to be done.
 */
class BASE
{
    friend class CONTAINER;
    friend class CAMERA;
    friend class LIGHT;
    friend class STAGE;
    friend class DIRECTOR;
    friend class CHANNEL;
    friend class SCENE;
    friend class BEZIER_HANDLE;
    friend class KEYFRAME_BASE;

protected:
    ///
    int m_iObjectID;

public:
    ///
    BASE();

    /*! @brief ?
     *
     * @param[in] iID
     *
     * @todo documentation to be done.
     */
    BASE( int iID ) { m_iObjectID = iID; }

    /*! @brief ?
     *
     * @return
     *
     * @todo documentation to be done.
     */
    int GetID( void ) const { return m_iObjectID; }

    /*! @brief ?
     *
     * @param[in] iID set to that value
     *
     * @todo documentation to be done.
     */
    void SetID( int iID ) { m_iObjectID = iID; }

    //! Deprecated. Supported for compatibility with 2.x plugins only.
    //! Use GetID and SetID instead.
    int& id() { return m_iObjectID; }

    /*! @brief check with valid
     *
     * if the object in plugin is valid (connection to viz)
     *
     * @return validity of object
     *
     * @todo documentation to be checked
     */
    bool valid( void ) const;

    /*! @brief ?
     *
     * @return
     *
     * @todo documentation to be done.
     */
    int set_changed( void );

    /*! @brief ?
     *
     * @param[in] classID ?
     * @param[out] pResult ?
     * @return
     *
     * @todo documentation to be done.
     */
    int is_class( int classID, bool * pResult );

    /*! @brief Checks if this object is animated.
     * Returns true in *pResult if this object or (in case of a cotnainer) any of its sub-objects
     * is animated. Otherwise, false is returned.
     * @param[out] pResult
     * @return 1 if call is successful, otherwise 0
     *
     * @todo documentation to be done.
     */
    int is_animated( bool * pResult );

    /*! @brief Gets the number of animation channels acting on this object.
     * get the number of channels for this object
     * @param[out] pResult
     * @param includeChannelsOfSubObject If true, also traverses sub-objects (only relevant if this is a CONTAINER object).
     * @return
     *
     * @todo documentation to be done.
     */
    int get_number_of_animation_channels(int* pResult, bool includeChannelsOfSubObject = true);

    /* @brief Finds an animation channel by name.
     * This method searches for an animation channel acting on this object. If a matching channel is found, a reference to it is returned in
     * 'channel', otherwise 'channel' will be invalid (which is always the case when this method is called on objects of non-animatable types
     * such as DIRECTOR).
     * You can limit the search to a particular director by using the syntax "directorName$channelName" for the channelName argument.
     * Nested directors may be specified like this: "directorName1$directorName2$channelName".
     * If 'includeChannelsOfSubObject' is true, sub-objects are also traversed (relevant only for CONTAINER objects).
     */
    int find_animation_channel(const char* channelName, CHANNEL& channel, bool includeChannelsOfSubObject = true);

    /* @brief Finds or creates an animation channel by name.
     * This method searches for an animation channel acting on this object. If a matching channel is found, a reference to it is returned in
     * 'channel', otherwise a new channel is created and a reference to it is returned in 'channel'.
     * As with find_animation_channel, you can specify a director path as part of 'channelName', eg "directorName1$directorName2$channelName".
     * If called on a CONTAINER, this method also looks for channels in the container's TRANSFORMATION object, but does not traverse any
     * other sub-objects. Consequently, you can create a new position channel as follows:
     * CONTAINER container;
     * CHANNEL channel;
     * // initialize container
     * container.find_or_create_animation_channel("Position", channel);
     */
    int find_or_create_animation_channel(const char* channelName, CHANNEL& channel);

    /* @brief Finds a keyframe by name.
     * This method searches for a keyframe acting beloging to this object. If a matching keyframe is found, a reference to it is returned in
     * 'channel', otherwise 'channel' will be invalid (which is always the case when this method is called on objects of non-animatable types
     * such as DIRECTOR).
     * You can limit the search to a particular director by using the syntax "directorName$keyframeName" for the keyframeName argument.
     * Nested directors may be specified like this: "directorName1$directorName2$keyframeName".
     * If 'includeChannelsOfSubObject' is true, sub-objects are also traversed (relevant only for CONTAINER objects).
     */
    int find_keyframe(const char* keyframeName, KEYFRAME_BASE& keyframe, bool includeKeyframesOfSubObject = true);

    /*! @brief Gets the animation channels acting on this object.
     * Fills 'channels' with the animation channels acting on this object.
     * @param[out] channels
     * @param includeChannelsOfSubObject If true, also traverses sub-objects (only relevant if this is a CONTAINER object).
     * @return
     *
     * @todo documentation to be done.
     */
    int get_animation_channels(THeapArray<CHANNEL>& channels, bool includeChannelsOfSubObject = true);

    /*! @brief  Gets an array of locations of object properties for which there can be animation channels.
     * @note This method does not traverse sub-objects.
     */
    int get_animatable_locations(THeapArray<const char*>& locations);

    /*! @brief Creates a channel for the value at 'location'.
     * @note This method does not traverse sub-objects. in particular, if you want to create a new position channel
     * on a container, you must first get the container's transformation object, and then call
     * transformation.add_animation_channel("POSITION", dir, channel).
     */
    int add_animation_channel(const char* location, const DIRECTOR& director, CHANNEL& newChannel);

    /*! @brief Determines whether there a channel for the specified location in the specified director.
     * @note This method does not traverse sub-objects.
     */
    int has_animation_channel(const char* location, const DIRECTOR& director, bool* pResult);

    /*! @brief ?
     *
     * @param[out] nReferenceCount ?
     * @return
     *
     * @todo documentation to be done.
     */
    int get_reference_count( int * nReferenceCount );

    /*! @brief increases the reference count by 1
     */
    int reference_create();

        /*! @brief decreases the reference count by 1.
     */
    int reference_delete();

    /*! @brief get the event name of a viz object
    *
    * @param[out] name the name of the event (could change)
    * @return
    *
    * @todo documentation to be done.
    */
    int get_object_event_name(const char** name);
};

#endif // EV_PLUGIN_BASE_H
