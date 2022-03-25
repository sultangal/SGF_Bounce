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

#if ! defined( EV_PLUGIN_PLUGIN_INSTANCE_H )
#define EV_PLUGIN_PLUGIN_INSTANCE_H

#include "evPlugin_BASE.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------

class PLUGIN_PARAMETER;

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class PLUGIN_INSTANCE : public BASE
{
public:
    /*! @brief get gemoetry of container, on which plugin is dragged on
     *
     * @return ?

     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief with class PLUGIN_PARAMETER you can manipulate all values of PLUGIN_INSTANCE
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int set( PLUGIN_PARAMETER & parameter );

    /*! @brief with class PLUGIN_PARAMETER get all values of PLUGIN_INSTANCE
     *
     * @param parameter ?
     * @return ?

     * @todo documentation to be done.
     */
    int get( PLUGIN_PARAMETER & parameter );

    /*! @brief ?
     *
     * @param[in] bFlag ?
     * @return ?

     * @Distribute DOF events to other plugin instances (default)
     * or fire them only on the local instance..
     */
    int DOFEventDistribution(bool bFlag);

    /*! @brief ?
     *
     * @param[in] pbFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    int GetDOFEventDistribution(bool *pbFlag);

    /*! @brief ?
     *
     * @param[in] stroke ?
     * @param[in] controlType ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTRegister(int stroke, int controlType);

    /*! @brief ?
     *
     * @param[in] stroke ?
     * @param[in] controlType ?
     * @param[in] params ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTRegisterEx(int stroke, int controlType, const THeapArray<float>& params);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int MTUnregister();

    /*! @brief ?
     *
     * @param[out] registered ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTIsRegistered(bool* registered);

    /*! @brief ?
     *
     * @param[in] x position ?
     * @param[in] y position ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTSetPosition(int x, int y);

    /*! @brief ?
     *
     * @param[in] bFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTUseCenter(bool bFlag);

    /*! @brief ?
     *
     * @param[in] pbFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTGetUseCenter(bool *pbFlag);

    /*! @brief ?
     *
     * @param[in] iPlane ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTObjectPlane(int iPlane);

    /*! @brief ?
     *
     * @param[in] iPlane ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTGetObjectPlane(int &iPlane);

    /*! @brief ?
     *
     * @param[in] bFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTAlignGrid(bool bFlag);

    /*! @brief ?
     *
     * @param[in] pbFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTGetAlignGrid(bool *pbFlag);

    /*! @brief ?
     *
     * @param[in] bFlag ?
     * @return ?

     * @Distribute multi-touch DOF events to other plugin instances (default)
     * or fire them only on the local instance..
     */
    int MTDOFEventDistribution(bool bFlag);

    /*! @brief ?
     *
     * @param[in] pbFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTGetDOFEventDistribution(bool *pbFlag);

    /*! @brief ?
     *
     * @param[in] pbFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTHasMomentum(bool *pbFlag);

    /*! @brief ?
     *
     * @param[in] pbFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    int MTTouched(bool *pbFlag);

    /*! @brief ?
     *
     * @param[in] iCount ?
     * @return ?

     * @todo documentation to be done.
     */
    int GetTraceCount(unsigned int& iCount);

    /*! @brief ?
     *
     * @param[in] container ?
     * @return ?

     * @todo documentation to be done.
     */
    int GetHitContainer(CONTAINER& container);

    /*! @brief ?
     *
     * @param[out] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int is_geometry(bool *pVal);

    /*! @brief ?
     *
     * @param[out] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int is_function(bool *pVal);

    /*! @brief ?
     *
     * @param[out] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int is_script(bool *pVal);

    /*! @brief ?
     *
     * @param[out] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_is_pickable(bool bVal);

    /*! @brief ?
     *
     * @param[out] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int is_set_pickable(bool *pbVal);
};


#endif // EV_PLUGIN_PLUGIN_INSTANCE_H

