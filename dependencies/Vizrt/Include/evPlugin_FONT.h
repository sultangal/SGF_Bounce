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

#if ! defined( EV_PLUGIN_FONT_H )
#define EV_PLUGIN_FONT_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class GEOMETRY_MODIFIER;

//=========================================================================
// FONT OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class FONT : public BASE
{
public:

    /*! @brief ?
     *
     * @param name ?
     * @return ?

     * @todo documentation to be done.
     */
    const FONT& operator=( const char* name );

    /*! @brief ?
     *
     * @param rhs ?
     * @return ?

     * @todo documentation to be done.
     */
    const FONT& operator=( const FONT& rhs );

    /*! @brief reload the font, if closed ! -> font is already loaded, with = operator !
     *
     * @return ?

     * @todo documentation to be done.
     */
    int reload( void );

    /*! @brief close the font
     *
     * @return ?

     * @todo documentation to be done.
     */
    int close( void );

    /*! @brief get the name
     *
     * @param[in] character ?
     * @param[out] name ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_char_name( int character, const char** name );

    /*! @brief is char used in this font
     *
     * @param[in] character ?
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_char_used( int character, bool* value );

    /*! @brief char advance
     *
     * @param[in] character ?
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_char_advance( int character, float* value );

    /*! @brief char width
     *
     * @param[in] character ?
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_char_width( int character, float* value );

    /*! @brief char height
     *
     * @param[in] character ?
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_char_height( int character, float* value );

    /*! @brief get the kerning between two characters
     *
     * @param[in] character1 ?
     * @param[in] character2 ?
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_char_kerning( int character1, int character2, float* value );

    /*! @brief set the kerning between two characters
     *
     * @param[in] character1 ?
     * @param[in] character2 ?
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int set_char_kerning( int character1, int character2, float value );

    /*! @brief ?
     *
     * @param[out] llx ?
     * @param[out] lly ?
     * @param[out] urx ?
     * @param[out] ury ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_bounding_box( float *llx, float *lly, float *urx, float *ury );

    /*! @brief ?
     *
     * @param[in] geom_type ?
     * @param[in] lod ?
     * @param[in] character ?
     * @param[out] geom_modifier ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_geom_modifier( int geom_type, int lod, int character, GEOMETRY_MODIFIER& geom_modifier );
};




#endif // EV_PLUGIN_FONT_H
