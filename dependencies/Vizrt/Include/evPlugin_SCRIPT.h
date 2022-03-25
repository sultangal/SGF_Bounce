/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2006 PEAK software technologies GmbH                               *
 *  All Rights Reserved.                                                         *
 *                                                                               *
 *  This is PROPRIETARY SOURCE CODE of PEAK software technologies GmbH;          *
 *  the contents of this file may not be disclosed to third parties, copied or   *
 *  duplicated in any form, in whole or in part, without the prior written       *
 *  permission of PEAK software technologies GmbH                                *
 *                                                                               *
 * ============================================================================= */

/*  CAUTION:
 *  --------
 *  This file contains no user-modifiable data
 *  Under no circumstances change anything in this file without an
 *  explicit order from an employee of PEAK software technologies GmbH
 *
 */


#if ! defined( EV_PLUGIN_SCRIPT_H )
#define EV_PLUGIN_SCRIPT_H

#include "evPlugin_BASE.h"
#include "evPlugin_SHARED_MEMORY.h"

//=========================================================================
// SCRIPT OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class SCRIPT : public BASE
{
public:
    /*! @brief get script
     *
     * with this function you get the container on which the script is located
     * \return{no return value, creates handle on current script}
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief run the entire script
     *
     * with this function you can run the current script
     * \return{returns 1 (success), NULL (unknown error/no script), -1 (not compiled) or -2 (not active)}
     * @todo documentation to be done.
     */
    int run_script( void );

    /*! @brief get a scriptfunction
     *
     * with this function you can run the current script
     * \return{returns 1 (success), NULL (unknown error/no script), -1 (not compiled), -2 (not active)or -3 (function does not exist, incorrect arguments)}
     * @todo documentation to be done.
     */
    int get_scriptfunction( const char * functionName, const char* typeString, SCRIPTFUNCTION& scriptFunction );


    /*! @brief compile script
     *
     * with this function you can compile the current script
     * \return{returns (bool) true when successfully, false for any error}
     * @todo documentation to be done.
     */
    bool compile( bool bCallOnInit=false );
};

#endif // EV_PLUGIN_SCRIPT_H
