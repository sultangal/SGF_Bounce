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

#if ! defined( EV_PLUGIN_CENTER_H )
#define EV_PLUGIN_CENTER_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;


//=========================================================================
// CENTER OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class CENTER : public BASE
{
public:
    friend class TRANSFORMATION;

    /*! @brief get center of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local();

    /*! @brief center of container with containername
     *
     * @param[in] name
     * @return ?

     * @todo documentation to be done.
     */
    const CENTER& operator=( const char * name );

    /*! @brief center of CONTAINER
     *
     * @param[in] container
     * @return ?

     * @todo documentation to be done.
     */
    const CENTER& operator=( const CONTAINER & container );

    /*! @brief copy center from another center
     *
     * @param[in] rhs
     * @return ?

     * @todo documentation to be done.
     */
    const CENTER& operator=( const CENTER& rhs );

    /*! @brief set center values
     *
     * @param[in] x
     * @param[in] y
     * @param[in] z
     * @return ?

     * @todo documentation to be done.
     */
    int set( float x, float y, float z );

    /*! @brief get center values
     *
     * @param[out] pfX
     * @param[out] pfY
     * @param[out] pfZ
     * @return ?

     * @todo documentation to be done.
     */
    int get( float *pfX, float *pfY, float *pfZ ) const;
};


#endif // EV_PLUGIN_CENTER_H
