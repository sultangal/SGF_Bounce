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

#if ! defined( EV_PLUGIN_ALPHA_H )
#define EV_PLUGIN_ALPHA_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;

//=========================================================================
// ALPHA OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class ALPHA : public BASE
{
public:

    /*! @brief get alpha of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief alpha of container with containername
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    const ALPHA& operator=( const char* name );

    /*! @brief alpha of CONTAINER
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    const ALPHA& operator=( const CONTAINER& container );

    /*! @brief copy alpha from another alpha
     *
     * @param[in] rhs
     * @return ?

     * @todo documentation to be done.
     */
    const ALPHA& operator=( const ALPHA& rhs);

    /*! @brief set alpha value
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set( float value );

    /*! @brief get alpha value
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get( float * value );
};


#endif // EV_PLUGIN_ALPHA_H
