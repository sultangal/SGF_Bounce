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

#if ! defined( EV_PLUGIN_RGBACOLOR_H )
#define EV_PLUGIN_RGBACOLOR_H




// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


// ---------------------------------------------------------------------
//  RGBA colors ...
// ---------------------------------------------------------------------
// typedef unsigned char   uchar;


#pragma warning( push )
#pragma warning (disable : 4201)    // nonstandard extension used : nameless struct/union

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class RGBAColor
{
protected:
    /*! @brief union for storage of color value.
     *
     * store either a per component or a combined long value.
     */
    union
    {
        unsigned long m_rgbaValue;
        struct
        {
            unsigned char m_r;        ///!< red
            unsigned char m_g;        ///!< green
            unsigned char m_b;        ///!< blue
            unsigned char m_a;        ///!< alpha
        };
    };

public:
    /*! @brief default constructor
     *
     * @param[in] clrRGBA combined RGBA color value.
     */
    RGBAColor( unsigned long clrRGBA = 0L )
        : m_rgbaValue( clrRGBA )
    {}

    /*! @brief component constructor
     *
     * @param[in] r red component.
     * @param[in] g green component.
     * @param[in] b blue component.
     * @param[in] a alpha component. defaults to 0xff.
     */
    RGBAColor( unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xff )
        : m_r(r)
        , m_g(g)
        , m_b(b)
        , m_a(a)
    {}

    /*! @brief set red component.
     *
     * @param[in] red component value.
     */
    void SetRed( unsigned char red )
    {
        m_r = red;
    }

    /*! @brief set green component.
     *
     * @param[in] green component value.
     */
    void SetGreen( unsigned char green )
    {
        m_g = green;
    }

    /*! @brief set blue component.
     *
     * @param[in] blue component value.
     */
    void SetBlue( unsigned char blue )
    {
        m_b = blue;
    }

    /*! @brief set alpha component.
     *
     * @param[in] alpha component value.
     */
    void SetAlpha( unsigned char alpha )
    {
        m_a = alpha;
    }

    /*! @brief data access to red component
     *
     * @return red value.
     */
    unsigned char Red() const
    {
        return m_r;
    }

    /*! @brief data access to green value.
     *
     * @return green value.
     */
    unsigned char Green() const
    {
        return m_g;
    }

    /*! @brief data access to blue value.
     *
     * @return blue value.
     */
    unsigned char Blue() const
    {
        return m_b;
    }

    /*! @brief data access to alpha value.
     *
     * @return alpha value.
     */
    unsigned char Alpha() const
    {
        return m_a;
    }

    /*! @brief data access to combined color values.
     *
     * @return red, green, blue, and alpha values.
     */
    operator unsigned long () const
    {
        return m_rgbaValue;
    }

    /*! @brief assignment operator
     *
     * @param[in] rgba right hand side of assignment.
     */
    const RGBAColor & operator = ( unsigned long rgba )
    {
        m_rgbaValue = rgba;
        return *this;
    }
};


#pragma warning( pop )

#endif // EV_PLUGIN_RGBACOLOR_H
