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

#if ! defined( EV_PLUGIN_CONTAINER_FX_H )
#define EV_PLUGIN_CONTAINER_FX_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
class CONTAINER_FX : public BASE
{
public:
    enum { X_MODE_NONE=0, X_MODE_LEFT, X_MODE_CENTER, X_MODE_RIGHT };
    enum { Y_MODE_NONE=0, Y_MODE_TOP, Y_MODE_CENTER, Y_MODE_BOTTOM };
    enum { Z_MODE_NONE=0, Z_MODE_FRONT, Z_MODE_CENTER, Z_MODE_BACK };
    enum { TRANSFORM_MODE_NONE=0, TRANSFORM_MODE_ABSOLUTE, TRANSFORM_MODE_RELATIVE };

    int set_position(float x, float y, float z);
    int get_position(float& x, float& y, float& z);

    // See TRANSFORM_MODE above
    int set_position_mode(int positionMode);
    int get_position_mode(int& positionMode);

    int set_rotation(float x, float y, float z);
    int get_rotation(float& x, float& y, float& z);

    // See TRANSFORM_MODE above
    int set_rotation_mode(int rotationMode);
    int get_rotation_mode(int& rotationMode);

    int set_scaling(float x, float y, float z);
    int get_scaling(float& x, float& y, float& z);

    // See TRANSFORM_MODE above
    int set_scaling_mode(int scalingMode);
    int get_scaling_mode(int& scalingMode);

    // See CONTAINER_FX_CENTER_X_MODE above
    int set_center_x_mode(int centerMode);
    int get_center_x_mode(int& centerMode);

    // See CONTAINER_FX_CENTER_Y_MODE above
    int set_center_y_mode(int centerMode);
    int get_center_y_mode(int& centerMode);

    // See CONTAINER_FX_CENTER_Z_MODE above
    int set_center_z_mode(int centerMode);
    int get_center_z_mode(int& centerMode);

    int set_color(float r, float g, float b, float a);
    int get_color(float& r, float& g, float& b, float& a);

    // See CONTAINER_FX_CENTER_Z_MODE above
    int set_color_mode(int colorMode);
    int get_color_mode(int& colorMode);

    int set_alpha(float alpha);
    int get_alpha(float& alpha);

    // See CONTAINER_FX_CENTER_Z_MODE above
    int set_alpha_mode(int alphaMode);
    int get_alpha_mode(int& alphaMode);

    int set_active(bool active);
    int get_active(bool& active);

    int reset();
};


#endif // EV_PLUGIN_CONTAINER_FX_H

