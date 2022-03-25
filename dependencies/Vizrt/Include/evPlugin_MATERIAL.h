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

#if ! defined( EV_PLUGIN_MATERIAL_H )
#define EV_PLUGIN_MATERIAL_H

#include "evPlugin_BASE.h"
#include "evPlugin_RGBAColor.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;
class ANIMATION;

//=========================================================================
// MATERIAL OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class MATERIAL : public BASE
{
public:
    /*! @brief get material of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get material of container, on which plugin is inherited
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local_inheritor( void );

    /*! @brief material of container with containername
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    const MATERIAL& operator=( const char* container );

    /*! @brief material of CONTAINER
     *
     * @param[in] container ?
     * @return ?

     * @todo documentation to be done.
     */
    const MATERIAL& operator=( const CONTAINER& container );

    /*! @brief copy material from another material
     *
     * @param[in] material right hand side
     * @return ?

     * @todo documentation to be done.
     */
    const MATERIAL& operator=( const MATERIAL& material );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_enlighted( int value );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_enlighted( int * value );

    /*! @brief set color
     *
     * @param[in] value ?
     * @return ?

     * @todo uebergabe einer klasse per value und nicht per const reference
     * @todo documentation to be done.
     */
    int set_color( RGBAColor value );

    /*! @brief get color
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_color( RGBAColor * value );

    /*! @brief set ambient color
     *
     * @param[in] value ?
     * @return ?

     * @todo uebergabe einer klasse per value und nicht per const reference
     * @todo documentation to be done.
     */
    int set_ambient( RGBAColor value );

    /*! @brief get ambient color
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_ambient( RGBAColor * value );

    /*! @brief set diffuse color
     *
     * @param value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_diffuse( RGBAColor value );

    /*! @brief get diffuse color
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_diffuse( RGBAColor * value );

    /*! @brief set emission color
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_emission( RGBAColor value );

    /*! @brief get emission color
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_emission( RGBAColor * value );

    /*! @brief set specular color
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_specular( RGBAColor value );

    /*! @brief get specular color
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_specular( RGBAColor * value );

    /*! @brief set alpha value
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_alpha( float value );

    /*! @brief get alpha value
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_alpha( float * value );

    /*! @brief set shininess value
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_shininess( float value );

    /*! @brief get shininess value
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_shininess( float * value );
};



#endif // EV_PLUGIN_MATERIAL_H
