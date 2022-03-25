#ifndef EV_PLUGIN_SUPER_CHANNEL_H
#define EV_PLUGIN_SUPER_CHANNEL_H

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
#include "evPlugin_PROXY_CHANNEL.h"

/**
 * @brief      { This class represents a SuperChannel }
 */
class SUPER_CHANNEL : public AVCHANNEL
{
public:
    /**
     * @brief      Determines if valid.
     *
     * @return     True if valid, False otherwise.
     */
    bool is_valid();

    /**
    * @brief      Toggles playing and pending sub-channel
    *
    * @return     true if successful
    */
    bool toggle();

    /*! @brief Get playing sub-channel
    *
    * @param[out] playing proxy channel
    * @return true if the call succeeds, otherwise false.
    *
    * Get playing sub-channel. This channel is not valid during transitions. Check the return value!
    */
    bool get_playing(PROXY_CHANNEL & proxy);
    
    /*! @brief Get pending sub-channel
    *
    * @param[out] pending proxy channel
    * @return true if the call succeeds, otherwise 0.
    *
    * Get pending sub-channel. This channel is not valid during transitions. Check the return value!
    */
    bool get_pending(PROXY_CHANNEL & proxy);

    /*! @brief Get sub-channel A
    *
    * @param[out] proxy channel
    * @return true if the call succeeds.
    *
    * Get playing sub-channel. This channel is not valid during transitions. Check the return value!
    */
    bool get_a(PROXY_CHANNEL & proxy);

    /*! @brief Get sub-channel B
    *
    * @param[out] pending proxy channel
    * @return true if the call succeeds.
    *
    * Get pending sub-channel. This channel is not valid during transitions. Check the return value!
    */
    bool get_b(PROXY_CHANNEL & proxy);

    /*! @brief Get status of transition mode
    *
    * @return aut mode
    *
    * Get transition mode. Automatic or manually set transitions.
    */
    bool get_transition_auto_mode();

    /*! @brief Set status of transition mode
    *
    * @return true on successful set
    *
    * Set transition mode. Automatic or manually set transitions.
    */
    bool set_transition_auto_mode(bool automatic);

    /*! @brief Get manually set A-B transition director
    *
    * @param[out] transition director
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool get_ab_transition_manual(DIRECTOR & director);

    /*! @brief Set A-B transition director manually
    *
    * @param[in] transition director
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool set_ab_transition_manual(const DIRECTOR & director);

    /*! @brief Get A-B transition director
    *
    * @param[out] transition director
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool get_ab_transition(DIRECTOR & director);

    /*! @brief Set A-B transition direction
    *
    * @param[in] reverse direction
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool set_ab_transition_reverse(bool reverse);

    /*! @brief Get A-B transition direction
    *
    * @param[out] transition direction
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool get_ab_transition_reverse();

    /*! @brief Get manually set B-A transition director
    *
    * @param[out] transition director
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool get_ba_transition_manual(DIRECTOR & director);

    /*! @brief Set B-A transition director manually
    *
    * @param[in] transition director
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool set_ba_transition_manual(const DIRECTOR & director);

    /*! @brief Get B-A transition director
    *
    * @param[out] transition director
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool get_ba_transition(DIRECTOR & director);

    /*! @brief Set B-A transition direction
    *
    * @param[in] reverse direction
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool set_ba_transition_reverse(bool reverse);

    /*! @brief Get B-A transition direction
    *
    * @param[out] transition direction
    * @return true if the call succeeds.
    *
    * @todo documentation to be done.
    */
    bool get_ba_transition_reverse();
};

#endif //EV_PLUGIN_SUPER_CHANNEL_H