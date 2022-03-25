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

#if ! defined( EV_PLUGIN_vizError_H )
#define EV_PLUGIN_vizError_H

// #include "evPlugin_BASE.h"

/*! @brief forward definitions for CVgeomData.h
 *
 * @note the following definitions are dummy definitions;
 * without them, we would not be able to include CVgeomData.h
 */
struct vizError
{
    /*!@brief {brief description}
     *
     * {a more elaborate description of enum}
     * @todo documentation to be done.
     * @note IMPORTANT: add error text to gapszError - in viz.cpp!!!!!!
     * \sa gapszError in viz.cpp
     */
    enum code
    {
        firstError,             /*!<  */
        noMemory = firstError,  /*!<  */

        // <--- place error-codes here <---
        // (IMPORTANT: add error text to gapszError - in viz.cpp!!!!!!)

        lastError               /*!<  */
    };
     ///
    static const char * gapszError[lastError];
};


/*! @brief {brief description}
 *
 * a more elaborate description of function.
 *
 * @param[in] eErrorCode {description}
 * @post {description of the postcondition}
 * @todo documentation to be done.
 */
void ErrorExit( vizError::code eErrorCode );

 /*! @brief {brief description}
 *
 * a more elaborate description of function.
 *
 * @param[in] pszCause {description}
 * @param[in] nExitCode {description}
 * \post {description of the postcondition}
 * @todo documentation to be done.
 */
void ErrorExit( const char* pszCause = 0, int nExitCode = -1, bool bKillGui = true );

 /*! @brief {brief description}
 *
 * a more elaborate description of function.
 *
 * @param[in] nExitCode {description}
 * @param[in] pszFmt {description}
 * \post {description of the postcondition}
 * @todo documentation to be done.
 */
void ErrorExit( int nExitCode, const char *pszFmt, ... );



#endif // EV_PLUGIN_vizError_H
