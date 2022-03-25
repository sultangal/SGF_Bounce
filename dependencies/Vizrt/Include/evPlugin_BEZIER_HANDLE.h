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

#if ! defined( EV_PLUGIN_BEZIER_HANDLE_H )
#define EV_PLUGIN_BEZIER_HANDLE_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------

//=========================================================================
// BEZIER_HANDLE
//=========================================================================

/*! @brief ?
 *
 * @todo documentation to be done.
 */
class BEZIER_HANDLE : public BASE
{
public:
    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_left_angle(float value);

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_left_weight(float value);

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_left_mode(int value);

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_right_angle(float value);

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_right_weight(float value);

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_right_mode(int value);

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_lock_mode(int value);

    /*! @brief ?
     *
     * @param[out] pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_left_angle(float* pValue);

    /*! @brief ?
     *
     * @param[out] pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_left_weight(float* pValue);

    /*! @brief ?
     *
     * @param[out] pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_left_mode(int* pValue);

    /*! @brief ?
     *
     * @param[out] pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_right_angle(float* pValue);

    /*! @brief ?
     *
     * @param[out] pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_right_weight(float* pValue);

    /*! @brief ?
     *
     * @param[out] pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_right_mode(int* pValue);

    /*! @brief ?
     *
     * @param[out] pValue ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_lock_mode(int* pValue);
};



#endif // EV_PLUGIN_BEZIER_HANDLE_H
