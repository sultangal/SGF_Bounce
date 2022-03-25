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

#if ! defined( EV_PLUGIN_SUBSTANCE_H )
#define EV_PLUGIN_SUBSTANCE_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;

//=========================================================================
// SUBSTANCE OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class SUBSTANCE : public BASE
{
public:
    /*! @brief get substance of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get substance with location
     *
     * @param[in] location
     * @return ?

     * @todo documentation to be done.
     */
    const SUBSTANCE& operator=( const char* location );

    /*! @brief substance of CONTAINER
     *
     * @param[in] container ?
     * @return ?

     * @todo documentation to be done.
     */
    const SUBSTANCE& operator=( const CONTAINER& container );

    /*! @brief copy substance from another substance
     *
     * @param[in] substance right hand side
     * @return ?

     * @todo documentation to be done.
     */
    const SUBSTANCE& operator=( const SUBSTANCE& substance );  

    /*! @brief get the substance sbsar binary data
     *
     * @param[out] data binary data of the substance
     * @param[out] dataSize size of the data
     * @return ?

     * @todo documentation to be done.
     */
    int get_data( const unsigned char ** data, int * dataSize );

    /*! @brief get the substance GH location
    *
    * @param[out] value the substance location
    * @return ?

    * @todo documentation to be done.
    */
    int get_location(char **value);
};

#endif // EV_PLUGIN_SUBSTANCE_H
