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

#ifndef __MISC_H__
#define __MISC_H__






//#include <stdio.h>
#include <math.h>
#include <ctype.h>


#include "evPlugin_RGBAColor.h"
#include "evPlugin_MATH.h"

#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------------------------------------------------
//  2d points ...
// ---------------------------------------------------------------------
/*! @brief 2d point structure
 *
 *
 *
 * @todo documentation to be done.
 */
struct EVPOINT
{
    float x;
    float y;

    EVPOINT( float _x=0.0F, float _y=0.0F )
            { x = _x; y = _y; }
};
typedef struct EVPOINT EVPOINT;


// ---------------------------------------------------------------------
//  3d points ...
// ---------------------------------------------------------------------
/*! @brief 3d point structure
 *
 *
 *
 * @todo documentation to be done.
 */
struct EVPOINT3D
{
    float x;
    float y;
    float z;
};
typedef struct EVPOINT3D EVPOINT3D;


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 *
 *
 * @todo documentation to be done.
 */
class CPoint3d : public EVPOINT3D
{
public:
    /* @brief default constructor
     *
     * @param[in] fx
     * @param[in] fy
     * @param[in] fz
     * @return
     * @todo documentation to be done.
     */
    CPoint3d( float fx=0., float fy=0., float fz=0. ) { x=fx; y=fy; z=fz; }

    /* @brief constructor
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    CPoint3d( const EVPOINT3D& pt ) { x=pt.x; y=pt.y; z=pt.z; }

    /* @brief constructor
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    CPoint3d( const EVPOINT& pt ) { x=pt.x; y=pt.y; z=0.; }

    /* @brief assignment
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& operator = ( const EVPOINT3D & pt ) { x=pt.x; y=pt.y; z=pt.z; return *this; }

    /* @brief assignment
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& operator = ( const EVPOINT & pt ) { x=pt.x; y=pt.y; z=0.;   return *this; }

    /* @brief some simple mathematics
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    CPoint3d operator - ( const EVPOINT3D& pt ) const { return CPoint3d(x-pt.x, y-pt.y, z-pt.z); }

    /* @brief some simple mathematics
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& operator -= (const EVPOINT3D& pt) { x-=pt.x; y-=pt.y; z-=pt.z; return *this; }

    /* \briefsome simple mathematics
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    CPoint3d operator + (const EVPOINT3D& pt) const { return CPoint3d(x+pt.x, y+pt.y, z+pt.z); }

    /* @brief some simple mathematics
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& operator += (const EVPOINT3D& pt) { x+=pt.x; y+=pt.y; z+=pt.z; return *this; }

    /* @brief some simple mathematics
     *
     * @param[in] div
     * @return
     * @todo documentation to be done.
     */
    CPoint3d operator / (const float div) const { return CPoint3d(x/div, y/div, z/div); }

    /* @brief some simple mathematics
     *
     * @param[in] div
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& operator /= (const float div) { x/=div; y/=div; z/=div; return *this; }

    /* @brief some simple mathematics
     *
     * @param[in] f
     * @return
     * @todo documentation to be done.
     */
    CPoint3d operator * (const float f) const { return CPoint3d(x*f, y*f, z*f); }

    /* @brief some simple mathematics
     *
     * @param[in] div
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& operator *= (const float div) { x*=div; y*=div; z*=div; return *this; }

    /* @brief data convertion ...
     *
     * @return
     * @todo documentation to be done.
     */
    operator const EVPOINT& ( void ) const { return *(EVPOINT*)this; }

    /* @brief data convertion ...
     *
     * @return
     * @todo documentation to be done.
     */
    operator const EVPOINT* ( void ) const { return (EVPOINT*)this; }

    /* @brief data convertion ...
     *
     * @return
     * @todo documentation to be done.
     */
    operator const EVPOINT3D* ( void ) const { return this; }

    /* @brief usefull functions ...
     *
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& Normalize( void ) { const float n = fsqrt(x*x + y*y + z*z); x/=n; y/=n; z/=n; return *this; }

    /* @brief usefull functions ...
     *
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& Reverse( void ) { x=-x; y=-y; z=-z; return *this; }

    /* @brief ?
     *
     * @param[in] axis
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& rotR90( unsigned char axis )
    {
        float f;
        switch(toupper(axis)) {
        case 'X': f=y;y=-z;z=f;break;
        case 'Y': f=x;x=-z;z=f;break;
        case 'Z': f=x;x=-y;y=f;break;
        }
        return *this;
    }

    /* @brief ?
     *
     * @param[in] axis
     * @return
     * @todo documentation to be done.
     */
    const EVPOINT3D& rotL90( unsigned char axis )
    {
        float f;
        switch(toupper(axis)) {
        case 'X': f=z;z=-y;y=f;break;
        case 'Y': f=z;z=-x;x=f;break;
        case 'Z': f=y;y=-x;x=f;break;
        }
        return *this;
    }

    /* @brief ?
     *
     * @param[in] pt
     * @return
     * @todo documentation to be done.
     */
    float LengthTo( const EVPOINT3D* pt = nullptr ) const
    {
        CPoint3d t(pt ? x-pt->x : x, pt ? y-pt->y : y, pt ? z-pt->z : z);
        return fsqrt(t.x*t.x + t.y*t.y + t.z*t.z);
    }
};


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class EVRECT
{
public:
    float left;
    float top;
    float right;
    float bottom;

public:
    /*! @brief ?
     *
     * @param[in] l
     * @param[in] t
     * @param[in] r
     * @param[in] b
     * @todo documentation to be done.
     */
    EVRECT( const float l, const float t, const float r, const float b )
        {left = l; top = t; right = r;  bottom = b;}

    /*! @brief ?
     *
     * @param[in] rptLeftTop
     * @param[in] rptRightBottom
     * @todo documentation to be done.
     */
    EVRECT( const EVPOINT& rptLeftTop, const EVPOINT& rptRightBottom )
            {left = rptLeftTop.x; top = rptLeftTop.y; right = rptRightBottom.x; bottom = rptRightBottom.y; }

    /*! @brief ?
     *
     * @param[in] rsource
     * @todo documentation to be done.
     */
    EVRECT( const EVRECT& rsource )
            { left = rsource.left; top = rsource.top; right = rsource.right; bottom = rsource.bottom; }

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~EVRECT() {}

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float Width( void ) const {return right-left;}

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float Height( void )const {return top-bottom;}
};





#ifdef __cplusplus
}
#endif

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, bool val)
{
    *(bool*)ptr = val;
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, char val)
{
    *(char*)ptr = val;
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, unsigned char val)
{
    *ptr = val;
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, short val)
{
    *(short*)ptr = ((val << 8) & 0xff00) | ((val >> 8) & 0xff);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, unsigned short val)
{
    *(unsigned short*)ptr = ((val << 8) & 0xff00) | ((val >> 8) & 0xff);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, int val)
{
    *(int*)ptr = (val >> 24) | ((val&0x00ff0000) >> 8) | ((val&0x0000ff00) << 8) | (val << 24);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, unsigned int val)
{
    *(unsigned int*)ptr = (val >> 24) | ((val&0x00ff0000) >> 8) | ((val&0x0000ff00) << 8) | (val << 24);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, long val)
{
    *(long*)ptr = (val >> 24) | ((val&0x00ff0000) >> 8) | ((val&0x0000ff00) << 8) | (val << 24);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, unsigned long val)
{
    *(unsigned long*)ptr = (val >> 24) | ((val&0x00ff0000) >> 8) | ((val&0x0000ff00) << 8) | (val << 24);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamSave(unsigned char* ptr, float val)
{
    DataParamSave(ptr, *((unsigned long*)&val));
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, char& val)
{
    val = *(char*)ptr;
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, unsigned char& val)
{
    val = *(unsigned char*)ptr;
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, short& val)
{
    val = *(short*)ptr;
    val = ((val << 8) & 0xff00) | ((val >> 8) & 0xff);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, unsigned short& val)
{
    val = *(unsigned short*)ptr;
    val = ((val << 8) & 0xff00) | ((val >> 8) & 0xff);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, int& val)
{
    val = *(int*)ptr;
    val = (val >> 24) | ((val&0x00ff0000) >> 8) | ((val&0x0000ff00) << 8) | (val << 24);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, unsigned int& val)
{
    val = *(unsigned int*)ptr;
    val = (val >> 24) | ((val&0x00ff0000) >> 8) | ((val&0x0000ff00) << 8) | (val << 24);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, long& val)
{
    val = *(long*)ptr;
    val = (val >> 24) | ((val&0x00ff0000) >> 8) | ((val&0x0000ff00) << 8) | (val << 24);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, unsigned long& val)
{
    val = *(unsigned long*)ptr;
    val = (val >> 24) | ((val&0x00ff0000) >> 8) | ((val&0x0000ff00) << 8) | (val << 24);
}

/*! @brief ?
 *
 * @param[in] ptr
 * @param[out] val
 * @todo documentation to be done.
 */
inline void DataParamLoad(unsigned char* ptr, float& val)
{
    DataParamLoad(ptr, *((unsigned long*)&val));
}

#endif
