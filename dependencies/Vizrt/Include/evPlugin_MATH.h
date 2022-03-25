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

#if ! defined( EV_PLUGIN_MATH_H )
#define EV_PLUGIN_MATH_H

// #include "evPlugin_BASE.h"
// #include "evMath.h"

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif


#if defined( evPLUGIN_POLLUTE )
#if defined( _WIN32 )

//#ifndef M_PI
//#define M_PI    3.14159265358979323846
//#endif

#define fsqrt   sqrtf
#define ftan    tanf
#define fatan2  atan2f
#define fsin    sinf
#define fcos    cosf
#define facos   acosf
#define fasin   asinf
#define ffloor  floorf
#define fceil   ceilf
#define fatan   atanf
#define fexp(f) ((float)exp(f))

#endif // #if defined( _WIN32 )
#ifdef _LINUX
#define fsqrt(x) sqrt(x)
#define facos(x) acos(x)
#define ftan(x) tan(x)
#define fcos(x) cos(x)
#define fsin(x) sin(x)
#define fatan2(x,y) atan2(x,y)
#define fasin(x) asin(x)
#define ffloor(x) floor(x)
#define fatan(x) atan(x)
#define fexp(x) exp(x)
#define fceil   (float)ceil


#ifdef max
#undef max
#endif //max

#ifdef min
#undef min
#endif //min
#endif

#else // evPLUGIN_POLLUTE

#include <math.h>

inline float fsqrt( float x )               { return sqrtf( x ); }
inline float ftan( float x )                { return tanf( x ); }
inline float fatan2( float y, float x )     { return atan2f( y, x ); }
inline float fsin( float x )                { return sinf( x ); }
inline float fcos( float x )                { return cosf( x ); }
inline float facos( float x )               { return acosf( x ); }
inline float fasin( float x )               { return asinf( x ); }
inline float ffloor( float x )              { return floorf( x ); }
inline float fceil( float x )               { return ceilf( x ); }
inline float fatan( float x )               { return atanf( x ); }
inline float fexp( float x )                { return expf( x ); }

#endif // evPLUGIN_POLLUTE

#ifdef __cplusplus
}
#endif


#endif // EV_PLUGIN_MATH_H
