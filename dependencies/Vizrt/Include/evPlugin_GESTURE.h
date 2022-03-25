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

#if ! defined( EV_PLUGIN_GESTURE_H )
#define EV_PLUGIN_GESTURE_H

#include "evPlugin_GESTURE_RECOGNIZER.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


//=========================================================================
// GESTURE OBJECT
//=========================================================================

/*! @brief ?
 *
 * This class is used as an interface for the internal viz gesture objects.
 * @todo documentation to be done.
 */
class GESTURE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    GESTURE();

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    GESTURE(unsigned int iGestureID);

    /*! @brief is Gesture valid
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool valid( void ) const;

    /*! @brief get Gesture ID
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned int GetGestureID() const;

    /*! @brief set Gesture ID
     *
     * @return ?

     * @todo documentation to be done.
     */
    void SetGestureID(unsigned int iGestureID);

    /*! @brief set Gesture data
     *
     * @return ?

     * @todo documentation to be done.
     */
    void Init(unsigned int iGestureID);

    /*! @brief get id of the recognized pattern
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned int GetPatternID() const;

    /*! @brief get gesture recognizer which generated this gesture
     *
     * @return ?

     * @todo documentation to be done.
     */
    void GetRecognizer(GESTURE_RECOGNIZER& recognizer) const;

    /*! @brief get ID of th gesture recognizer which generated this gesture
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned int GetRecognizerID() const;

private:
    unsigned int m_iGestureID;
};

#endif // EV_PLUGIN_GESTURE_H
