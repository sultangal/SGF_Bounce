#ifndef EV_PLUGIN_IMAGE_CHANNEL_H
#define EV_PLUGIN_IMAGE_CHANNEL_H

/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2006,2015 Vizrt Austria GmbH                                       *
 *  All Rights Reserved.                                                         *
 *                                                                               *
 *  This is PROPRIETARY SOURCE CODE of Vizrt Austria GmbH;                       *
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

#include "evPlugin_BASE.h"
#include "evPlugin_AVCHANNEL.h"

/**
 * @brief      { This class represents a ImageChannel }
 */
class IMAGE_CHANNEL : public AVCHANNEL
{
public:
    /**
     * @brief      Determines if valid.
     *
     * @return     True if valid, False otherwise.
     */
    bool  is_valid();
};

#endif //EV_PLUGIN_IMAGE_CHANNEL_H