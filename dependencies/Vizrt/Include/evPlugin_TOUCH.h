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

#include "evPlugin_PLUGINFUNC.h"

#if ! defined( EV_PLUGIN_TOUCH_H )
#define EV_PLUGIN_TOUCH_H

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


//=========================================================================
// TOUCH OBJECT
//=========================================================================

/*! @brief ?
 *
 * This class is used as an interface for the internal viz touch objects.
 */
class TOUCH
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    TOUCH();

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    TOUCH(unsigned int iTraceID, unsigned int iTouchIndex);

    /*! @brief is Touch valid
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool valid( void ) const;

    /*! @brief get Trace ID
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned int GetTraceID() const;

    /*! @brief set Trace ID
     *
     * @return ?

     * @todo documentation to be done.
     */
    void SetTraceID(unsigned int iTraceID);

    /*! @brief get Touch index
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned int GetTouchIndex() const;

    /*! @brief set Touch index
     *
     * @return ?

     * @todo documentation to be done.
     */
    void SetTouchIndex(unsigned int iTouchIndex);

    /*! @brief set Touch data
     *
     * @return ?

     * @todo documentation to be done.
     */
    void Init(unsigned int iTraceID, unsigned int iTouchIndex);

    /*! @brief get touch event (TOUCH_DOWN, TOUCH_MOVE, TOUCH_UP)
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetEvent(TouchEvent& eEvent) const;

    /*! @brief get position in screen-coordinates
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetXY(double& dX, double& dY) const;

    /*! @brief get undeformed position in screen-coordinates
    *
    * @return ?

    * @todo documentation to be done.
    */
    bool GetXYUndeformed(double& dX, double& dY) const;

    /*! @brief get pressure
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetPressure(double& dPressure) const;

    /*! @brief get pointing direction (e.g. of a finger, pointing device, etc.)
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetDirection(evVertex3D& v3dDir) const;

    /*! @brief get timestamp
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetTimestamp(double& dTimestamp) const;

private:
    unsigned int m_iTraceID;
    unsigned int m_iTouchIndex;
};

#endif // EV_PLUGIN_TOUCH_H
