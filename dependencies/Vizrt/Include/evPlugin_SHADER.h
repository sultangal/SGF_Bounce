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

#if ! defined( EV_PLUGIN_SHADER_H )
#define EV_PLUGIN_SHADER_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class PLUGIN_PARAMETER;

class SHADER : public BASE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief returns a pointer to the name string in VIZ. Do NOT modify!!!
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_type( char ** value );

    /*! @brief shader of container with containername
     *
     * @param[in] container ?
     * @return ?

     * @todo documentation to be done.
     */
    const SHADER& operator=( const char * container );

    /*! @brief get shader from container
     *
     * @param[in] container right hand side.
     * @todo documentation to be done.
     */
    const SHADER& operator=( const CONTAINER & container );

    /*! @brief get mask from another mask
     *
     * @param[in] shader right hand side
     * @todo documentation to be done.
     */
    const SHADER& operator=( const SHADER & shader );

    /*! @brief ?
     *
     * @param[in] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_active( int active);

    /*! @brief is the container visible.
     *
     * @param[out] pActive ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_active( int *pActive );

    /*! @brief with class PLUGIN_PARAMETER you can manipulate all values of shader
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int set( PLUGIN_PARAMETER & parameter );

    /*! @brief with class PLUGIN_PARAMETER get all values of shader
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int get( PLUGIN_PARAMETER & parameter );

    /*! @brief ?

        @param[in] msg ?
        @param[in] param ?
        @param[out] ret ?
        @return ?

        @todo documentation to be done.
     */
    int dispatcher( ULONG_PTR msg, ULONG_PTR param, ULONG_PTR & ret );
};

#endif // EV_PLUGIN_SHADER_H
