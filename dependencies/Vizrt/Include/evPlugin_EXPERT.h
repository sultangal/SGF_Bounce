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

#if ! defined( EV_PLUGIN_EXPERT_H )
#define EV_PLUGIN_EXPERT_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class EXPERT : public BASE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void local();

    /*! @brief ?
     *
     * @param container ?
     * @todo documentation to be done.
     */
    void operator=( CONTAINER & container );

    /*! @brief ?
     *
     * @param expert ?
     * @todo documentation to be done.
     */
    void operator=( EXPERT & expert );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_backside( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_backside( bool value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_wireframe( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_wireframe( bool value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_zbuffer_read( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_zbuffer_read( bool value );

        /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_draw_layer( int * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_draw_layer( int value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */

    int get_outline( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_outline( bool value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_twosided_lighting( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_twosided_lighting( bool value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_zbuffer_draw( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_zbuffer_draw( bool value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_line_antialiasing( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_line_antialiasing( bool value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_separate_specular( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_separate_specular( bool value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_wireframe_width( float * value );
    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_wireframe_width( float value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_mirror( int * value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_exact_picking( bool * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_exact_picking( bool value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_mirror( int value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum render_mode
    {
        ADD=0,              /*!<  */
        BLEND,              /*!<  */
        REV_SUBTRACT,       /*!<  */
        SUBTRACT,           /*!<  */
        MULTIPLY,           /*!<  */
        REV_MULTIPLY,       /*!<  */
        MIN,                /*!<  */
        MAX                 /*!<  */
    };

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_render_mode( int * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_render_mode( int value );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum transparency_mode
    {
        TR_BLEND=0, /*!<  */
        TR_MASK     /*!<  */
    };

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_transparency_mode( int * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_transparency_mode( int value );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_shade_model( int * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_shade_model( int value );
};



#endif // EV_PLUGIN_EXPERT_H
