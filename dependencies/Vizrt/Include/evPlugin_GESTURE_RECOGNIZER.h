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

#if ! defined( EV_PLUGIN_GESTURE_RECOGNIZER_H )
#define EV_PLUGIN_GESTURE_RECOGNIZER_H

#include "evPlugin_PLUGIN_INSTANCE.h"
#include "evPlugin_TRACE.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


//=========================================================================
// GESTURE_RECOGNIZER OBJECT
//=========================================================================

/*! @brief ?
 *
 * This class is used as an interface for the internal viz gesture
 * recognizer objects.
 * @todo documentation to be done.
 */
class GESTURE_RECOGNIZER
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    GESTURE_RECOGNIZER();

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    GESTURE_RECOGNIZER(unsigned int iRecognizerID);

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    GESTURE_RECOGNIZER(const GESTURE_RECOGNIZER& gestureRecognizer);

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    virtual ~GESTURE_RECOGNIZER();

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    const GESTURE_RECOGNIZER& operator=(const GESTURE_RECOGNIZER& rhs);

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    bool operator==(const GESTURE_RECOGNIZER& rhs) const;

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    bool operator!=(const GESTURE_RECOGNIZER& rhs) const;

    /*! @brief is GestureRecognizer valid
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool valid( void ) const;

    /*! @brief get GestureRecognizer ID
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned int GetRecognizerID() const;

    /*! @brief set GestureRecognizer ID
     *
     * @return ?

     * @todo documentation to be done.
     */
    void SetRecognizerID(unsigned int iRecognizerID);

    /*! @brief set GestureRecognizer data
     *
     * @return ?

     * @todo documentation to be done.
     */
    void Init(unsigned int iRecognizerID);

    /*! @brief get is active
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetActive() const;

    /*! @brief set is active
     *
     * @return ?

     * @todo documentation to be done.
     */
    void SetActive(bool bActive) const;

    /*! @brief get pattern handling
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetHandlePatterns() const;

    /*! @brief set pattern handling
     *
     * @return ?

     * @todo documentation to be done.
     */
    void SetHandlePatterns(bool bHandle) const;

    /*! @brief get tap handling
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetHandleTaps() const;

    /*! @brief set tap handling
     *
     * @return ?

     * @todo documentation to be done.
     */
    void SetHandleTaps(bool bHandle) const;

    /*! @brief adds a trace for recognition
     *
     * @return ?

     * @todo documentation to be done.
     */
    void AddTrace(const TOUCH_TRACE& trace) const;

    /*! @brief adds a trace for recognition
     *
     * @return ?

     * @todo documentation to be done.
     */
    void AddTrace(unsigned int iTraceID) const;

    /*! @brief removes a trace from recognition
     *
     * @return ?

     * @todo documentation to be done.
     */
    void RemoveTrace(const TOUCH_TRACE& trace) const;

    /*! @brief removes a trace from recognition
     *
     * @return ?

     * @todo documentation to be done.
     */
    void RemoveTrace(unsigned int iTraceID) const;

    /*! @brief adds a trace for recognition
     *
     * @return ?

     * @todo documentation to be done.
     */
    void AddHandler(const PLUGIN_INSTANCE& plugin) const;

    /*! @brief adds a trace for recognition
     *
     * @return ?

     * @todo documentation to be done.
     */
    void AddHandler(int iObjectID) const;

    /*! @brief removes a trace from recognition
     *
     * @return ?

     * @todo documentation to be done.
     */
    void RemoveHandler(const PLUGIN_INSTANCE& plugin) const;

    /*! @brief removes a trace from recognition
     *
     * @return ?

     * @todo documentation to be done.
     */
    void RemoveHandler(int iObjectID) const;

    /*! @brief get pattern orientation checking
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetCheckPatternOrientation() const;

    /*! @brief set pattern orientation checking
     *
     * @return ?

     * @todo documentation to be done.
     */
    void SetCheckPatternOrientation(bool bCheck) const;

private:
    unsigned int m_iRecognizerID;
};

#endif // EV_PLUGIN_GESTURE_RECOGNIZER_H
