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

#if ! defined( EV_PLUGIN_TRACE_H )
#define EV_PLUGIN_TRACE_H

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class TOUCH;

//=========================================================================
// TOUCH_TRACE OBJECT
//=========================================================================

/*! @brief ?
 *
 * This class is used as an interface for the internal viz trace objects.
 * @todo documentation to be done.
 */
class TOUCH_TRACE
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    TOUCH_TRACE();

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    TOUCH_TRACE(unsigned int iTraceID);

    /*! @brief is Trace valid
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

    /*! @brief set Trace data
     *
     * @return ?

     * @todo documentation to be done.
     */
    void Init(unsigned int iTraceID);

    /*! @brief get last touch
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetLastTouch(TOUCH& touch) const;

    /*! @brief get number of touches
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetTouchCount(unsigned int& iTouchCount) const;

    /*! @brief get last touch
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetTouch(unsigned int iTouchIndex, TOUCH& touch) const;

    enum eTraceSource {
        eTSrcUndefined = 0,
        eTSrcMouse,
        eTSrcWin7,
        eTSrcTuio,
        eTSrcPPi, // deprecated
        eTSrcLeap,
        eTSrcWinStylus,
        eNumTraceSources
    };

    /*! @brief get trace source
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetSource(eTraceSource& eSource) const;

    enum eTraceType {
        eTTypeUndefined = 0,
        eTTypeTool,
        eTTypeFinger,
        eTTypeHand,
        eTTypePalm,
        eTTypeStylus
    };

    enum eTraceSubTypeStylus {
        eTSTypeStylusUndefined = 0,
        eTSTypeStylusEraser
    };

    /*! @brief get trace type
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool GetType(eTraceType& eType, unsigned int& iSubType) const;

private:
    unsigned int m_iTraceID;
};

#endif // EV_PLUGIN_TRACE_H
