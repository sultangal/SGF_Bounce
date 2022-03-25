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

#if ! defined( EV_PLUGIN_KEY_H )
#define EV_PLUGIN_KEY_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;

//=========================================================================
// KEY OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class KEY : public BASE
{
public:
    /*! @brief get key of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief key of container with containername
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    const KEY& operator=( const char * name );

    /*! @brief key of CONTAINER
     *
     * @param[in] container right hand side
     * @return ?

     * @todo documentation to be done.
     */
    const KEY& operator=( const CONTAINER& container );

    /*! @brief copy key from another key
     *
     * @param rhs right hand side
     * @return ?

     * @todo documentation to be done.
     */
    const KEY& operator=( const KEY& rhs );

    /*! @brief draw rgb 1 don't 0
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_draw_rgb( int value );

    /*! @brief get draw rgb flag
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_draw_rgb( int * value );

    /*! @brief draw key 1 don't 0
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_draw_key( int value );

    /*! @brief get draw key flag
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_draw_key( int * value );

    /*! @brief automatic alpha on 1 off 0
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_automatic_alpha( int value );

    /*! @brief get automatic alpha flag
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_automatic_alpha( int * value );

    /*! @brief set alpha value -> only if automatic alpha is off
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_alpha( float value );

    /*! @brief get alpha value
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_alpha( float * value );
};


#endif // EV_PLUGIN_KEY_H
