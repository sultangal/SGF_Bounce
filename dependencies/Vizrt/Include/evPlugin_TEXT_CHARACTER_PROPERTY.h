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

#if ! defined( EV_PLUGIN_TEXT_CHARACTER_PROPERTY_H )
#define EV_PLUGIN_TEXT_CHARACTER_PROPERTY_H

// #include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------

/*! @brief TEXT_CHARACTER_PROPERTY OBJECT
 *
 *  This class exists only to maintain backward compatibility with 2.7 plugin source code.
 *  New plugins should use CV_TEXT_CONTROL instead!
 *
 * @todo documentation to be done.
 */
class TEXT_CHARACTER_PROPERTY
{
public:

    // which modes do exist. Also defined in viz/main/geom_text.h
    enum
    {
        TRANSFORM_MODE_NONE=0
        , TRANSFORM_MODE_ABSOLUTE
        , TRANSFORM_MODE_RELATIVE
    };
    enum
    {
        CENTER_MODE_NONE=0
        , CENTER_MODE_ABSOLUTE
        , CENTER_MODE_RELATIVE
        , CENTER_MODE_NW
        , CENTER_MODE_N
        , CENTER_MODE_NE
        , CENTER_MODE_BW
        , CENTER_MODE_B
        , CENTER_MODE_BE
        , CENTER_MODE_W
        , CENTER_MODE_C
        , CENTER_MODE_E
        , CENTER_MODE_SW
        , CENTER_MODE_S
        , CENTER_MODE_SE
    };

    // which properties should be written to viz
    enum {
        ACCESS_NONE=0
        , ACCESS_POSITION=1
        , ACCESS_ROTATION=2
        , ACCESS_SCALING=4
        , ACCESS_CENTER=8
        , ACCESS_KERNING=16
        , ACCESS_ALPHA=32
        , ACCESS_COLOR=64
        , ACCESS_ORIGINAL_POSITION=128    // where should the character be by default
        , ACCESS_CHAR_SIZE=256
        , ACCESS_CHAR_INDEX=512

        , ACCESS_DEFAULT = ACCESS_POSITION|ACCESS_ROTATION|ACCESS_SCALING|ACCESS_CENTER|ACCESS_KERNING

        , ACCESS_ALL = ACCESS_ALPHA|ACCESS_COLOR|ACCESS_POSITION|ACCESS_ROTATION|ACCESS_SCALING|ACCESS_CENTER|ACCESS_KERNING|ACCESS_ORIGINAL_POSITION|ACCESS_CHAR_SIZE|ACCESS_CHAR_INDEX
    };

    // constructor
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    TEXT_CHARACTER_PROPERTY()
    {
        Reset();
    }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void Reset(void)
    {
        character_index = 0;
        kerning = 0.0;
        position_mode = TRANSFORM_MODE_NONE;
        rotation_mode = TRANSFORM_MODE_NONE;
        scaling_mode = TRANSFORM_MODE_NONE;
        center_mode = CENTER_MODE_NONE;
        alpha_mode = TRANSFORM_MODE_NONE;
        color_mode = TRANSFORM_MODE_NONE;
        position[0] = position[1] = position[2] = 0.0;
        rotation[0] = rotation[1] = rotation[2] = 0.0;
        scaling[0] = scaling[1] = scaling[2] = 1.0;
        center[0] = center[1] = center[2] = 0.0;
        original_position[0] = original_position[1] = original_position[2] = 0.0;
                    bottomLeftCorner[0] = bottomLeftCorner[1] = bottomLeftCorner[2] = 0.0;;
                    topRightCorner[0] = topRightCorner[1] = topRightCorner[2] = 0.0;
        alpha = 1.0;
        color_r = 1.0;
        color_g = 1.0;
        color_b = 1.0;
        center_updates_position = false;
                    char_unicode = 0 ;

        access_mask = ACCESS_ALL;
    }

    /*! @brief ?
     *
     * @param[in] old right hand side
     * @return ?

     * @todo documentation to be done.
     */
    const TEXT_CHARACTER_PROPERTY& operator=(const TEXT_CHARACTER_PROPERTY& old)
    {
        character_index = old.character_index;
        kerning = old.kerning;
        alpha_mode = old.alpha_mode;
        color_mode = old.color_mode;
        position_mode = old.position_mode;
        rotation_mode = old.rotation_mode;
        scaling_mode = old.scaling_mode;
        center_mode = old.center_mode;
        for(int x=0; x<3; x++)
        {
            position[x] = old.position[x];
            rotation[x] = old.rotation[x];
            scaling[x] = old.scaling[x];
            center[x] = old.center[x];
            original_position[x] = old.original_position[x];
            bottomLeftCorner[x] =  old.bottomLeftCorner[x];
            topRightCorner[x] =  old.topRightCorner[x];

        }
        alpha = old.alpha;
        color_r = old.color_r;
        color_g = old.color_g;
        color_b = old.color_b;
        center_updates_position = old.center_updates_position;
        access_mask = old.access_mask;
    char_unicode = old.char_unicode;
        return *this;
    }

    /*! @brief ?
     *
     * @param[in] old right hand side
     * @return ?

     * @todo documentation to be done.
     */
    void operator=(PLUGIN_PARAMETER& old);

    // access functions to my private data
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_index(void)   { return character_index; }

    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_index(int v) { character_index = v; }


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_kerning(void)   { return kerning; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_kerning(float v) { kerning = v; }


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_alpha_mode(void)   { return alpha_mode; }

    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_alpha_mode(int v) { alpha_mode = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_alpha(void)   { return alpha; }

    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_alpha(float v) { alpha = v; }        // always between 0.0 and 1.0

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_color_mode(void)   { return color_mode; }

    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_color_mode(int v) { color_mode = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_color_r(void)   { return color_r; }

    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_color_r(float v) { color_r = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_color_g(void)   { return color_g; }

    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_color_g(float v) { color_g = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_color_b(void)   { return color_b; }

    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_color_b(float v) { color_b = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_position_mode(void)   { return position_mode; }

    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_position_mode(int v) { position_mode = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_position_x(void) { return position[0]; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_position_y(void) { return position[1]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_position_z(void) { return position[2]; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_position_x(float v) { position[0] = v; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_position_y(float v) { position[1] = v; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_position_z(float v) { position[2] = v; }
    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_position(float x, float y, float z) { position[0] = x; position[1] = y; position[2] = z; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_rotation_mode(void)   { return rotation_mode; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_rotation_mode(int v) { rotation_mode = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_rotation_x(void) { return rotation[0]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_rotation_y(void) { return rotation[1]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_rotation_z(void) { return rotation[2]; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_rotation_x(float v) { rotation[0] = v; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_rotation_y(float v) { rotation[1] = v; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_rotation_z(float v) { rotation[2] = v; }
    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_rotation(float x, float y, float z) { rotation[0] = x; rotation[1] = y; rotation[2] = z; }


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_scaling_mode(void)   { return scaling_mode; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_scaling_mode(int v) { scaling_mode = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_scaling_x(void) { return scaling[0]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_scaling_y(void) { return scaling[1]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_scaling_z(void) { return scaling[2]; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_scaling_x(float v) { scaling[0] = v; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_scaling_y(float v) { scaling[1] = v; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_scaling_z(float v) { scaling[2] = v; }
    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_scaling(float x, float y, float z) { scaling[0] = x; scaling[1] = y; scaling[2] = z; }


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_center_mode(void)   { return center_mode; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_center_mode(int v) { center_mode = v; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_center_x(void) { return center[0]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_center_y(void) { return center[1]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_center_z(void) { return center[2]; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_center_x(float v) { center[0] = v; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_center_y(float v) { center[1] = v; }
    /*! @brief ?
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_center_z(float v) { center[2] = v; }
    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_center(float x, float y, float z) { center[0] = x; center[1] = y; center[2] = z; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool get_center_updates_position() { return center_updates_position; }
    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_center_updates_position(bool value) { center_updates_position = value; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_original_position_x(void) { return original_position[0]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_original_position_y(void) { return original_position[1]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_original_position_z(void) { return original_position[2]; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_char_width(void) { return topRightCorner[0] - bottomLeftCorner[0]; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_char_height(void) { return topRightCorner[1] - bottomLeftCorner[1]; }

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    void set_access_mask(int value)    { access_mask = value; }
    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    void add_access_mask(int value)    { access_mask |= value; }
    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    void remove_access_mask(int value) { access_mask &= ~value; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_access_mask(void)          { return access_mask; }
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int get_char_unicode(void)      {return char_unicode;};

public:

    int character_index;    // which character do i want to change
    float kerning;          // set kerning between two characters
    int alpha_mode;         // change the alpha, how do we want to do it. see enum
    float alpha;            // the transparency fo the character (between 0.0 and 1.0)
    int color_mode;
    float color_r;
    float color_g;
    float color_b;
    int position_mode;      // if we want to do transformation, how do we want to do it. see enum
    float position[3];      // a position for each character
    int rotation_mode;      // if we want to do transformation, how do we want to do it. see enum
    float rotation[3];      // rotate the characters
    int scaling_mode;       // if we want to do transformation, how do we want to do it. see enum
    float scaling[3];       // and also scale them
    int center_mode;        // if we want to do transformation, how do we want to do it. see enum
    float center[3];        // where is the center of the character

    float original_position[3]; // here should my character be (without the text props)
    float bottomLeftCorner[3];
    float topRightCorner[3];
    int char_unicode ;



    int access_mask;        // select which properties should be read and written to viz

    bool center_updates_position; // changing the center should update the position of the character
};


#endif // EV_PLUGIN_TEXT_CHARACTER_PROPERTY_H
