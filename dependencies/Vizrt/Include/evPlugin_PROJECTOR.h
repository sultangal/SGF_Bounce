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

#if ! defined( EV_PLUGIN_PROJECTOR_H )
#define EV_PLUGIN_PROJECTOR_H

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
class PROJECTOR : public BASE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief get projector from container
     *
     * @param container ?
     * @todo documentation to be done.
     */
    void operator=( CONTAINER & container );

    /*! @brief get projector from another projector
     *
     * @param projector ?
     * @todo documentation to be done.
     */
    void operator=( PROJECTOR & projector );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int GetFovy( float * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int SetFovy( float value );

    /*! @brief ?
     *
     * @param[out] scale
     * @return ?

     * @todo documentation to be done.
     */
    int GetTexScale( float * scale );

    /*! @brief ?
     *
     * @param scale ?
     * @return ?

     * @todo documentation to be done.
     */
    int SetTexScale( float * scale );

    /*! @brief ?
     *
     * @param[out] bias ?
     * @return ?

     * @todo documentation to be done.
     */
    int GetTexBias( float * bias );
    /*! @brief ?
     *
     * @param bias ?
     * @return ?

     * @todo documentation to be done.
     */
    int SetTexBias( float * bias );

    /*! @brief ?
     *
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    int GetLayer( int * value );

    /*! @brief ?
     *
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    int SetLayer( int value );
};


#endif // EV_PLUGIN_PROJECTOR_H
