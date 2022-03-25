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

#if ! defined( EV_PLUGIN_POOL_H )
#define EV_PLUGIN_POOL_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class SCENE;
class IMAGE;
class GEOMETRY;


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class POOL : public BASE
{
public:
    /*! @brief standard constructor
     *
     * @todo documentation to be done.
     */
    POOL();

    /*! @brief constructor that gets a pool
     *
     * @param[in] name
     * @todo documentation to be done.
     */
    POOL( const char *name );

    /*! @brief copy constructor
     *
     * @param oldpool ?
     * @todo documentation to be done.
     */
    POOL( const POOL & oldpool );

    /*! @brief destructor
     *
     * @todo documentation to be done.
     */
    ~POOL();

    /*! @brief pool handling
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    int get_pool( const char * name );

    /*! @brief ?
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    int pool_exist( const char * name );


    /*! @brief creates a new item with \<name\>
     *
     * @return ?

     * @todo documentation to be done.
     */
    int mem_create_item( void );

    /*! @brief get current item for scenes
     *
     * @param item ?
     * @return ?

     * @todo documentation to be done.
     */
    int mem_get_item( SCENE * item );

    /*! @brief get current item for images
     *
     * @param item ?
     * @return ?

     * @todo documentation to be done.
     */
    int mem_get_item( IMAGE * item );

    /*! @brief get current item for geometries
     *
     * @param item ?
     * @return ?

     * @todo documentation to be done.
     */
    int mem_get_item( GEOMETRY * item );

    /*! @brief saves item under \<name\> in database
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    int mem_save_to_db( const char * name );

    /*! @brief saves item under \<name\> in database
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    int db_item_exist( const char * name );

    /*! @brief saves \<source\> under \<target\>
     *
     * @param[in] source
     * @param[in] target
     * @return ?

     * @todo documentation to be done.
     */
    int db_copy( const char *source, const char *target );

    /*! @brief delete the item \<name\>
     *
     * @param[in] name ?
     * @return ?

     * @todo documentation to be done.
     */
    int db_delete( const char * name );

    /*! @brief get item out of db for scenes
     *
     * @param[in] name ?
     * @param item ?
     * @return ?

     * @todo documentation to be done.
     */
    int db_get_item( const char * name, SCENE * item );

    /*! @brief get item out of db for images
     *
     * @param name ?
     * @param item ?
     * @return ?

     * @todo documentation to be done.
     */
    int db_get_item( const char * name, IMAGE * item );

    /*! @brief get item out of db for geometries
     *
     * @param[in] name ?
     * @param item ?
     * @return ?

     * @todo documentation to be done.
     */
    int db_get_item( const char * name, GEOMETRY * item );

private:
    ///
    int m_iPoolID;
};



#endif // EV_PLUGIN_POOL_H
