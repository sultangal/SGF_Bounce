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

#if ! defined( EV_PLUGIN_FUNCTION_H )
#define EV_PLUGIN_FUNCTION_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class PLUGIN_PARAMETER;
class ANIMATION;


//=========================================================================
// FUNCTION OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class FUNCTION : public BASE
{
public:

    /*! @brief function plugin
     *
     * @param[in] rhs right hand side
     * @return ?

     * @todo documentation to be done.
     */
    const FUNCTION& operator=( const FUNCTION & rhs );

    /*! @brief with class PLUGIN_PARAMETER you can manipulate all values of functionplugin
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int set( PLUGIN_PARAMETER & parameter );

    /*! @brief with class PLUGIN_PARAMETER get all values of functionplugin
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int get( PLUGIN_PARAMETER & parameter );

    /*! @brief returns a pointer to the name string in Everest. Do NOT modify!!!
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_type( char ** value );

    /*! @brief get the pointer to the data in the functionplugin
     *
     * @warning if you are not really really sure about what you are doing with this, don't use this !
     * @param ptr ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_dataptr( void ** ptr );

    /*! @brief ?
     *
     * @param[in] msg ?
     * @param[in] param ?
     * @param ret ?
     * @return ?

     * @todo documentation to be done.
     */
    int dispatcher( ULONG_PTR msg, ULONG_PTR param, ULONG_PTR & ret );

    /*! @brief ?
     *
     * @param[in] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_active(bool active);

    /*! @brief is the container visible.
     *
     * @param[out] active ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_active(bool& active);
};

#endif // EV_PLUGIN_FUNCTION_H
