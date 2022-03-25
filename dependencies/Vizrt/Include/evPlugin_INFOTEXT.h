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

#if ! defined( EV_PLUGIN_INFOTEXT_H )
#define EV_PLUGIN_INFOTEXT_H

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
class INFOTEXT : public BASE
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
     * @param infotext ?
     * @todo documentation to be done.
     */
    void operator=( INFOTEXT & infotext );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int get_text( const char** value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int set_text( const char* value );
};



#endif // EV_PLUGIN_INFOTEXT_H
