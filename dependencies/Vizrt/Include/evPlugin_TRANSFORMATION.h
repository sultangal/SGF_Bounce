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

#if ! defined( EV_PLUGIN_TRANSFORMATION_H )
#define EV_PLUGIN_TRANSFORMATION_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


//=========================================================================
// TRANSFORMATION OBJECT
//=========================================================================
/*! @brief A container's transformation object.
 *
 * To get a TRANSFORMATION object, call CONTAINER::get_transformation.
 * This type's is provided to enable access to position/rotation/scaling animations.
 */
class TRANSFORMATION : public BASE
{
public:
    /*! @brief Gets the position of the transformation.
     *
     * @param[out] position
     * @return 1 if successful, otherwise 0
     */
    int get_position(VIZ_POSITION& position);

    /*! @brief Gets the rotation of the transformation.
     *
     * @param[out] rotation
     * @return 1 if successful, otherwise 0
     */
    int get_rotation(ROTATION& rotation);

    /*! @brief Gets the scaling of the transformation.
     *
     * @param[out] scaling
     * @return 1 if successful, otherwise 0
     */
    int get_scaling(SCALING& scaling);

    /*! @brief Gets the center of the transformation.
     *
     * @param[out] center
     * @return 1 if successful, otherwise 0
     */
    int get_center(CENTER& center);

    /*! @brief Returns the container holding this transformation object.
     *
     * @return 1 if successful, otherwise 0
     */
    int get_container(CONTAINER& container);
};




#endif // EV_PLUGIN_TRANSFORMATION_H
