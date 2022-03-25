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

#if ! defined( EV_PLUGIN_SCRIPT_PLUGIN_H )
#define EV_PLUGIN_SCRIPT_PLUGIN_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class PLUGIN_INSTANCE;
class PLUGIN_PARAMETER;
class ANIMATION;


//=========================================================================
// SCRIPT_PLUGIN OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class SCRIPT_PLUGIN : public BASE
{
public:

    /*! @brief script plugin
     *
     * @param[in] rhs right hand side
     * @return ?

     * @todo documentation to be done.
     */
    const SCRIPT_PLUGIN& operator=( const SCRIPT_PLUGIN & rhs );

    // cast-operator
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    operator PLUGIN_INSTANCE() const;

    /*! @brief with class PLUGIN_PARAMETER you can manipulate all values of script plugin
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int set( PLUGIN_PARAMETER & parameter );

    /*! @brief with class PLUGIN_PARAMETER get all values of script plugin
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int get( PLUGIN_PARAMETER & parameter );

};

#endif // EV_PLUGIN_SCRIPT_PLUGIN_H
