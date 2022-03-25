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

#if ! defined( EV_PLUGIN_SCRIPTFUNCTION_H )
#define EV_PLUGIN_SCRIPTFUNCTION_H

#include "evPlugin_BASE.h"
#include "evPlugin_SHARED_MEMORY.h"


//=========================================================================
// SCRIPTFUNCTION OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class SCRIPTFUNCTION : public BASE
{
public:
    SCRIPTFUNCTION();

    /*! @brief check with valid
     *
     * if the function valid (overrides base)
     *
     * @return validity of object
     *
     * @todo documentation to be checked
     */
    bool valid( void ) const;

    /*! @brief invoke this scriptfunction
     *
     * with this function you can run the current scriptfunction
     * \return{returns 1 (success), NULL (unknown error/no script/no success), -1 (not compiled), -2 (not active) or -3 (argumentVector too short/long)}
     * @todo documentation to be done.
     */
    int invoke(VARIANT_VAR& retVal, THeapArray<VARIANT_VAR> &argumentVector);

    /*! @brief get typestring
     *
     * returns the typestring, NULL if no scriptfunction/no success
     * \return{returns typestring or "" when no success}
     * @todo documentation to be done.
     */
    const char* get_typestring();

    /*! @brief clear/undo the handle
     *
     * clears the current instance
     * @todo documentation to be done.
     */
    void clear();

    /*! @brief define scriptfunction
     *
     * with this function the current scriptfunction is defined. Don't use this one! Use SCRIPT::get_scriptfunction!
     * @todo documentation to be done.
     */
    void define( int in_iScriptID, const char* in_functionName, const char* in_typeString );

private:
    int iScriptID;
    const char* functionName;
    const char* typeString;
};

#endif // EV_PLUGIN_SCRIPT_H
