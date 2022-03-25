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

#ifndef __EVPLUGIN_ERROR_CONSTANTS__
#define __EVPLUGIN_ERROR_CONSTANTS__



/*! @brief plugin error codes.
 *
 * named container for plugin error codes.
 *
 */
struct VIZERROR
{
    /*! @brief enum values for the error codes.
     *
     * lists the various values available for reporting errors.
     * \sa PLUGIN_INIT_EX()
     */
    enum Error_Codes_t
    {
        Success = 0,        /*!< operation o.k.                                 */
        ELicense,           /*!< no valid license present to run.               */
        EHardware,          /*!< missing hardware/driver                        */
        EVersion,           /*!< not compatible with the running viz-version    */
        EInvalidObject,     /*!< not a valid viz object                         */
        EPrerequisite,      /*!< software required by the plugin is not present */
        EInactive,          /*!< plugin was set to inactive                     */
        EDuplicate,         /*!< plugin with the same name already exists       */
        EUnknown = -1,      /*!< unspecified error.                             */
    };
};

#endif
