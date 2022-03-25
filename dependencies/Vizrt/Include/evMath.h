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

#ifndef _EV_MATH_H_
#define _EV_MATH_H_

#include <math.h>

#include <vector>
#include <float.h>

#include "evPlugin_MATH.h"


#ifndef WIN32
    #include <ctype.h>
#else
    #include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>


#define MAXSPLCOMP 3


#ifndef M_PI1_2
#pragma deprecated( "M_PI1_2" ) // use M_PI_2 instead
    /// constant pi divided by 2
    #define M_PI1_2                         (M_PI/2.0)
#endif

#ifndef RAD
    /// constant rad factor pi divided by 180
    #define RAD_FACTOR                      (M_PI/180.0)
    /// constant degree factor 180 divided by pi
    #define DEG_FACTOR                      (180.0/M_PI)
    /// get radiant.
    #define RAD(x)                          (RAD_FACTOR * (x))
    /// get grad.
    #define GRAD(x)                         (DEG_FACTOR * (x))
    /// get grad.
    #define DEG(x)                          (DEG_FACTOR * (x))
#endif


class evMatrix;
class evVertex2D;
class evVertex3D;
class CVSpline3D;

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
struct CVTriangleFace
{
    /// @todo documentation to be done.
    int iA;
    /// @todo documentation to be done.
    int iB;
    /// @todo documentation to be done.
    int iC;
    /// @todo documentation to be done.
    float fA;
    /// @todo documentation to be done.
    float fB;
    /// @todo documentation to be done.
    float fC;
    /// @todo documentation to be done.
    evVertex3D *pA;
    /// @todo documentation to be done.
    evVertex3D *pB;
    /// @todo documentation to be done.
    evVertex3D *pC;
    /// @todo documentation to be done.
    evVertex3D *pNA;
    /// @todo documentation to be done.
    evVertex3D *pNB;
    /// @todo documentation to be done.
    evVertex3D *pNC;
};
/// @todo documentation to be done.
typedef std::vector<CVTriangleFace> TRIANGLEVEC;
/// @todo documentation to be done.
typedef std::vector<CVSpline3D*> SPLINEVEC;
/// @todo documentation to be done.
typedef std::vector<evVertex3D*> VERTEX3DVEC;

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @param[in] vecVertices ?
 * @param vecNormals ?
 * @param vecTriangles ?
 * @param[in] bNormals ?
 * @param[in] bQuality ?
 * @return ?

 * @todo documentation to be done.
 */
bool BuildTriangleSurface( const VERTEX3DVEC & vecVertices
                         , VERTEX3DVEC & vecNormals
                         , TRIANGLEVEC & vecTriangles
                         , bool bNormals
                         , bool bQuality
                         );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @param[in] sinp ?
 * @param[in] cosp ?
 * @return ?

 * @todo documentation to be done.
 */
inline float angle_from_sincos( float sinp, float cosp )
{
    float phi;
    // sin ranges from -1. to 1.
    if (sinp > 1.) sinp = 1.;
    if (sinp < -1.) sinp = -1.;
    if (sinp > -FLT_EPSILON && sinp < FLT_EPSILON) {
        // sin close to zero
        if (cosp < 0.)  phi = (float)M_PI; // quad. 2 or 3
        else phi = 0.; // quad 1 or 4
    }
    else if (cosp < 0.)
        phi = (float)(M_PI - asin(sinp)); // quad 2 or 3
    else
        phi = (float)asin(sinp); // quad 1 or 4
    return phi;
}



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @param[in] sinp ?
 * @param[in] cosp ?
 * @return ?

 * @todo documentation to be done.
 */
inline double angle_from_sincos( double sinp, double cosp )
{
    double phi;
    // sin ranges from -1. to 1.

    if (cosp < -1. || cosp > 1.) {
        phi = asin(sinp);
        if (cosp < 0.) phi = M_PI-phi;
    }
    else {
        phi = acos(cosp);
        if (sinp < 0.) phi = -phi;
    }
    return phi;
}



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @param angle1 ?
 * @param[in] angle2 ?
 * @return ?

 * @todo documentation to be done.
 */
inline void match_angle1_to_angle2( float &angle1, float angle2 )
{
    float base = ((int) (angle2/(360.0f)))*360.0f;
    if (angle2-base < angle1-270.)
        base-=360.;
    if (angle2-base > angle1+270.)
        base+=360.;
    angle1 += base;
}



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @param[in] a ?
 * @return ?

 * @todo documentation to be done.
 */
inline double mysqrt( double a )
{
    if (a < DBL_EPSILON) return 0.;
    double x = a/2.;
    double x1 = 1./2.*(x+a/x);
    while (fabs(x1-x) > DBL_EPSILON) {
        x = x1;
        x1 = 1./2.*(x+a/x);
    }
    return x1;
}



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @param fMatIn ?
 * @param fVector ?
 * @param iNoEle ?
 * @return ?

 * @todo documentation to be done.
 */
inline bool SolveGauss( double * fMatIn, double * fVector, int iNoEle )
{
    int i,j,k;
    double dg, fk, tmp;
    double* fMatrix;

    fMatrix = new double[iNoEle*iNoEle];
    for (i = 0; i < iNoEle*iNoEle; ++i)
            fMatrix[i] = fMatIn[i];

    for (i = 0; i < iNoEle-1; ++i) {
        bool neNull = true;
        if (fabs(fMatrix[i*iNoEle+i]) < FLT_EPSILON) {
            neNull = false;
            for (j = i+1; j < iNoEle; ++j) {
                if (fabs(fMatrix[i*iNoEle+j]) > FLT_EPSILON) {
                    neNull = true;
                    for (k = 0; k < iNoEle; ++k) {
                        tmp = fMatrix[i*iNoEle+k];
                        fMatrix[i*iNoEle+k] = fMatrix[j*iNoEle+k];
                        fMatrix[j*iNoEle+k] = tmp;
                    }
                    tmp = fVector[i];
                    fVector[i] = fVector[j];
                    fVector[j] = tmp;
                }
            }
        }
        if (neNull) {
            dg = fMatrix[i*iNoEle+i];
            if (fabs(dg) < FLT_EPSILON) {
                delete []fMatrix;
                return false;
            }
            for (j = i+1; j < iNoEle; ++j) {
                fk = fMatrix[j*iNoEle+i]/dg;
                fVector[j] = fVector[j]-fk*fVector[i];
                for (k = i; k < iNoEle; ++k) {
                    fMatrix[j*iNoEle+k] = fMatrix[j*iNoEle+k] - fk*fMatrix[i*iNoEle+k];
                }
            }
        }
    }
    for (i = iNoEle-1; i > -1; --i) {
        for (j = iNoEle-1; j > i; --j)
            fVector[i] -= fMatrix[i*iNoEle+j]*fVector[j];
        if (fabs(fMatrix[i*iNoEle+i]) == 0.) {
            delete []fMatrix;
            return false;
        }
        else
            fVector[i] = fVector[i]/fMatrix[i*iNoEle+i];
    }
    delete []fMatrix;
    return true;
}



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief a class for matrix operations
 *
 * @todo documentation to be done.
 */
class evMatrix
{
    float mat[16];

    friend class evVertex3D;

public:
    /// standard destructor
    evMatrix();

    /*! @brief ?
     *
     * @param[in] m ?
     * @todo documentation to be done.
     */
    evMatrix( const float * m );

    /*! @brief ?
     *
     * @param[in] m ?
     * @todo documentation to be done.
     */
    evMatrix( const double * m );

    /*! @brief ?
     *
     * @param[in] rm ?
     * @todo documentation to be done.
     */
    evMatrix( const evMatrix& rm );

    /// destructor
    ~evMatrix() {};

    /*! @brief init functions
     *
     * @return ?

     * @todo documentation to be done.
     */
    const evMatrix& load_identity();

    /*! @brief assignment operator
     *
     * @param[in] mat ?
     * @return ?

     * @todo documentation to be done.
     */
    const evMatrix &operator=( const evMatrix &rhs );

    /*! @brief assignment operator
     *
     * @param[in] m ?
     * @return ?

     * @todo documentation to be done.
     */
    const evMatrix &operator=( const float * m );

    /*! @brief assignment operator
     *
     * @param[in] m ?
     * @return ?

     * @todo documentation to be done.
     */
    const evMatrix &operator=( const double * m );

    /*! @brief comparison operator
     *
     * @param[in] mat ?
     * @return true if the matrices are equal.
     * @todo documentation to be done.
     */
    bool operator==( const evMatrix &rhs ) const;

    /*! @brief comparison operator
     *
     * @param[in] mat ?
     * @return false if the matrices are equal.
     * @todo documentation to be done.
     */
    bool operator!=( const evMatrix &rhs ) const;

    /*! @brief multiplication operator
     *
     * @param[in] mat ?
     * @return ?

     * @todo documentation to be done.
     */
    const evMatrix &operator*=( const evMatrix &rhs );

    /*! @brief multiplication operator
     *
     * @param[in] mat ?
     * @return ?

     * @todo documentation to be done.
     */
    const evMatrix &operator/=( const evMatrix &rhs );

    /*! @brief conversion function
     *
     * @param[out] m ?
     * @todo documentation to be done.
     */
    void create_double( double * m ) const;

    /*! @brief index operator
     *
     * @param[out] idx ?
     * @return ?

     * @todo documentation to be done.
     */
    const float& operator[]( int idx ) const { return mat[idx]; }

    /*! @brief index operator
     *
     * @param[out] idx ?
     * @return ?

     * @todo documentation to be done.
     */
    float& operator[]( int idx )             { return mat[idx]; }

    /*! @brief const float * operator
     *
     * @return ?

     * @todo documentation to be done.
     */
    operator const float*() const                   { return mat; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    const float* read() const                       { return mat; }

    /*! @brief projection calls
     *
     * @param[in] fov ?
     * @param[in] aspect ?
     * @param[in] fNear ?
     * @param[in] fFar ?
     * @return ?

     * @todo documentation to be done.
     */
    void perspective( float fov, float aspect, float fNear, float fFar );

    /*! @brief projection calls
     *
     * @param[in] left ?
     * @param[in] right ?
     * @param[in] bottom ?
     * @param[in] top ?
     * @param[in] fNear ?
     * @param[in] fFar ?
     * @return ?

     * @todo documentation to be done.
     */
    void ortho( float left, float right, float bottom, float top, float fNear, float fFar );

    /*! @brief projection calls
     *
     * @param[in] left ?
     * @param[in] right ?
     * @param[in] bottom ?
     * @param[in] top ?
     * @param[in] fNear ?
     * @param[in] fFar ?
     * @return ?

     * @todo documentation to be done.
     */
    void frustum( float left, float right, float bottom, float top, float fNear, float fFar );

    /*! @brief OpenGL-style transformations using evVertex3D
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void translate( const evVertex3D& v );

    /*! @brief OpenGL-style transformations using evVertex3D
     *
     * @param[in] angle ?
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void rotate( const float angle, const evVertex3D& v );

    /*! @brief OpenGL-style transformations using evVertex3D
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void scale( const evVertex3D& v );

    /*! @brief OpenGL-style transformations
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void translate( float x, float y, float z );

    /*! @brief OpenGL-style transformations
     *
     * @param[in] angle
     * @param[in] x
     * @param[in] y
     * @param[in] z
     * @return ?

     * @todo documentation to be done.
     */
    void rotate( float angle, float x, float y, float z );

    /*! @brief OpenGL-style transformations
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void scale( float x, float y, float z );

    /*! @brief rotation around main axis
     *
     * @param[in] angle ?
     * @return ?

     * @todo documentation to be done.
     */
    void rotate_x( float angle );

    /*! @brief rotation around main axis
     *
     * @param[in] angle ?
     * @return ?

     * @todo documentation to be done.
     */
    void rotate_y( float angle );

    /*! @brief rotation around main axis
     *
     * @param[in] angle ?
     * @return ?

     * @todo documentation to be done.
     */
    void rotate_z( float angle );

    /*! @brief rotation around all three axes
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void rotate( const evVertex3D& v );

    /*! @brief extraction functions
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void get_rotation( float& x, float& y, float& z ) const;

    /*! @brief extraction functions
     *
     * @param[out] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void get_rotation( evVertex3D& v ) const;

    /*! @brief extraction functions
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void get_scaling( float& x, float& y, float& z ) const;

    /*! @brief extraction functions
     *
     * @param[out] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void get_scaling( evVertex3D& v ) const;

    /*! @brief get_scaling2 returns the square amount of the scaling
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return the square amount of the scaling
     * @todo documentation to be done.
     */
    void get_scaling2( float& x, float& y, float& z ) const;

    /*! @brief get_scaling2 returns the square amount of the scaling
     *
     * @param[out] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void get_scaling2( evVertex3D& v ) const;

    /*! @brief ?
     *
     * @param[out] x ?
     * @param[out] y ?
     * @param[out] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void get_translation( float& x, float& y, float& z ) const;

    /*! @brief ?
     *
     * @param[out] v ?
     * @return ?

     * @todo documentation to be done.
     */
    void get_translation( evVertex3D& v ) const;

    /*! @brief ?
     *
     * @param fMatrix ?
     * @param fVector ?
     * @param[in] iNoEle ?
     * @return ?

     * @todo documentation to be done.
     */
    static bool SolveGauss( double* fMatrix, double* fVector, int iNoEle );

    /*! @brief ?
     *
     * @param dMatIn ?
     * @param dVecIn ?
     * @param[in] nElem ?
     * @param dVecOut ?
     * @return ?

     * @todo documentation to be done.
     */
    static bool Gauss( double * dMatIn, double * dVecIn, int nElem, double * dVecOut );

    /*! @brief ?
     *
     * @param[out] x1 ?
     * @param[out] y1 ?
     * @param[out] z1 ?
     * @param[out] x2 ?
     * @param[out] y2 ?
     * @param[out] z2 ?
     * @return ?

     * @todo documentation to be done.
     */
    bool get_rotation_inxyz( float& x1, float& y1, float& z1, float& x2, float& y2, float& z2 ) const;

    /*! @brief ?
     *
     * @param[out] x1 ?
     * @param[out] y1 ?
     * @param[out] z1 ?
     * @param[out] x2 ?
     * @param[out] y2 ?
     * @param[out] z2 ?
     * @return ?

     * @todo documentation to be done.
     */
    bool get_rotation_inzxy( float& x1, float& y1, float& z1, float& x2, float& y2, float& z2 ) const;

    /*! @brief ?
     *
     * @param v3dRotations ?
     * @return ?

     * @todo documentation to be done.
     */
    int get_rotation_inxyz( evVertex3D v3dRotations[4] ) const;

    /*! @brief ?
     *
     * @param[out] x1 ?
     * @param[out] y1 ?
     * @param[out] z1 ?
     * @param[out] x2 ?
     * @param[out] y2 ?
     * @param[out] z2 ?
     * @return ?

     * @todo documentation to be done.
     */
    bool get_rotation_inzyx( float& x1, float& y1, float& z1, float& x2, float& y2, float& z2 ) const;

    /*! @brief ?
     *
     * @param v3dOriginal ?
     * @param v3dTransformed ?
     * @return ?

     * @todo documentation to be done.
     */
    bool GetTransform(const evVertex3D v3dOriginal[4], const evVertex3D v3dTransformed[4]);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void glLoadMatrix() const {glLoadMatrixf(mat);};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void glMultMatrix() const {glMultMatrixf(mat);};

    /*! @brief get a 3x3 submatrix from this (required by inverse)
     *
     * @param i ?
     * @param j ?
     * @return ?

     * @todo documentation to be done.
     */
    evMatrix get_submatrix3x3( int i, int j ) const;

    /*! @brief calculate the determinate
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_determinante() const;

    /*! @brief calculate the determinate of 3x3 matrix
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_determinante3x3() const;

    /*! @brief inverse the matrix
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool inverse();

    /*! @brief transpose the matrix
     *
     * @return ?

     * @todo documentation to be done.
     */
    void transpose();
};



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief a class for 2D vertex operations
 *
 * base class of class evVertex3D.
 * @todo documentation to be done.
 */
class evVertex2D
{
public:
    float x;
    float y;

    /*! @brief constructor
     *
     * @todo documentation to be done.
     */
    evVertex2D() : x( 0.0 ), y( 0.0 ) {}

    /*! @brief constructor
     *
     * @param[in] _x ?
     * @param[in] _y ?
     * @todo documentation to be done.
     */
    evVertex2D( float _x, float _y ) : x( _x ), y( _y ) {}

    /*! @brief constructor
     *
     * @param[in] _x ?
     * @param[in] _y ?
     * @todo documentation to be done.
     */
    evVertex2D( double _x, double _y ) : x( (float)_x ), y( (float)_y ) {}

    /*! @brief constructor
     *
     * @param[in] _x ?
     * @param[in] _y ?
     * @todo documentation to be done.
     */
    evVertex2D( long _x, long _y ) : x( (float)_x ), y( (float)_y ) {}

    /*! @brief constructor
     *
     * @param[in] _x ?
     * @param[in] _y ?
     * @todo documentation to be done.
     */
    evVertex2D( int _x, int _y ) : x( (float)_x ), y( (float)_y ) {}

    /*! @brief constructor
     *
     * @param[in] _x ?
     * @param[in] _y ?
     * @todo documentation to be done.
     */
    evVertex2D( short _x, short _y ) : x( (float)_x ), y( (float)_y ) {}

    /*! @brief copy constructor
     *
     * @param[in] source ?
     * @todo documentation to be done.
     */
    evVertex2D( const evVertex2D & source ) : x( source.x ), y( source.y ) {}

    /*! @brief destructors
     *
     */
    ~evVertex2D() {};






    /*! @brief substract operator
     *
     * @param[in] source ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex2D operator-( const evVertex2D & source ) const    { return evVertex2D( x - source.x, y - source.y ); }

    /*! @brief substract operator
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex2D& operator-=( const evVertex2D & c );

    /*! @brief add operator
     *
     * @param[in] source ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex2D operator+( const evVertex2D & source ) const    {return evVertex2D( x + source.x, y + source.y ); }

    /*! @brief add operator
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex2D& operator+=( const evVertex2D & c );


    /*! @brief mathematical operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex2D operator/( float v ) const;

    /*! @brief mathematical operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex2D& operator/=( float v );


    /*! @brief mathematical operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex2D operator*( float v ) const;

    /*! @brief mathematical operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex2D& operator*=( float v );


    /*! @brief assignment operator
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex2D& operator=( const evVertex2D & c );

    /*! @brief assignment operator
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex2D& operator=( const evVertex3D & c );






    /*! @brief comparison operator
     *
     * @param[in] v ?
     * @return true if v is equal
     * @todo documentation to be done.
     */
    inline bool operator==( const evVertex2D & v ) const       { return get_x() == v.get_x() && get_y() == v.get_y(); }

    /*! @brief comparison operator
     *
     * @param[in] v ?
     * @return false if v is equal
     * @todo documentation to be done.
     */
    bool operator!=( const evVertex2D & v ) const              { return !operator==(v); }





    // calc distance from a vertex to a line
    // usage:
    // result = vertex.distance_to_line(line_point_a, linepoint_b)
    /*! @brief ?
     *
     * @param[in] v1 ?
     * @param[in] v2 ?
     * @return ?

     * @todo documentation to be done.
     */
    inline float distance_to_line(const evVertex2D& v1, const evVertex2D& v2) const;

    /*! @brief ?
     *
     * @param[in] a1 ?
     * @param[in] a2 ?
     * @param[in] b1 ?
     * @param[in] b2 ?
     * @param[out] result ?
     * @return ?

     * @todo documentation to be done.
     */
    friend bool Intersection_2D(const evVertex2D& a1, const evVertex2D& a2, const evVertex2D& b1, const evVertex2D& b2, evVertex2D& result);




    /*! @brief set routine
     *
     * @param[in] vx ?
     * @param[in] vy ?
     * @todo documentation to be done.
     */
    void  set( float vx, float vy )   { x = vx; y = vy; };

    /*! @brief set and get routines
     *
     * @param[in] value ?
     * @todo documentation to be done.
     */
    void  set_x( float value )                { x = value; };

    /*! @brief set routine
     *
     * @param[in] value ?
     * @todo documentation to be done.
     */
    void  set_y( float value )                { y = value; };

    /*! @brief get routine
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_x() const                             { return x; };

    /*! @brief get routine
     *
     * @return ?

     * @todo documentation to be done.
     */
    float get_y() const                             { return y; };

    /*! @brief get routine
     *
     * @return ?

     * @todo documentation to be done.
     */
    const float *get_p() const              { return &x; };

    /*! @brief get routine
     *
     * @return ?

     * @todo documentation to be done.
     */
    float *get_p()                                  { return &x; };




    /*! @brief ?
     *
     * @param[in] d ?
     * @todo documentation to be done.
     */
    void add_x( float d ) { x += d; }

    /*! @brief ?
     *
     * @param[in] d ?
     * @todo documentation to be done.
     */
    void add_y( float d ) { y += d; }




    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool valid() const              { return x == FLT_MIN ? false : true; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float len() const               { return fsqrt(x*x + y*y); };

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float normalize();

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void glVertex() const {glVertex2f(x,y);};
};


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief a class for 3D vertex operations
 *
 * @todo documentation to be done.
 */
class evVertex3D : public evVertex2D
{
public:
    float z;

    /*! @brief constructor
     *
     * @todo documentation to be done.
     */
    evVertex3D() : evVertex2D(), z( 0.0F ) {}

    /*! @brief constructor
     *
     * @param[in] _x ?
     * @param[in] _y ?
     * @param[in] _z ?
     * @todo documentation to be done.
     */
    evVertex3D( float _x, float _y, float _z = 0.0F ) : evVertex2D( _x, _y ), z( _z ) {}

    /*! @brief copy constructor
     *
     * @param[in] src ?
     * @todo documentation to be done.
     */
    evVertex3D( const evVertex3D &src ) : evVertex2D( src.x, src.y ), z( src.z ) {}

    /*! @brief constructor
     *
     * @param[in] src ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D( const evVertex2D & src ) : evVertex2D( src ), z( 0.0F ) {}

    /*! @brief destructor
     *
     */
    ~evVertex3D() {};




    /*! @brief mathematical operators
     *
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D operator-() const;

    /*! @brief mathematical operators
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D operator+( const evVertex3D &c ) const;

    /*! @brief mathematical operators
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator+=( const evVertex3D &c );




    /*! @brief mathematical operators
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D operator-( const evVertex3D &c ) const;

    /*! @brief mathematical operators
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator-=( const evVertex3D &c );




    /*! @brief mathematical operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D operator/( float v ) const;

    /*! @brief mathematical operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator/=( float v );




    /*! @brief mathematical operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D operator*( float v ) const;

    /*! @brief mathematical operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator*=( float v );




    /*! @brief dot product
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    float operator*( const evVertex3D & c ) const;




    /*! @brief comparison operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    bool operator==( const evVertex3D& v ) const                                  { return z == v.get_z() && evVertex2D::operator==(v); }

    /*! @brief comparison operators
     *
     * @param[in] v ?
     * @return ?

     * @todo documentation to be done.
     */
    bool operator!=( const evVertex3D& v ) const                                  { return !operator==(v); }




    /*! @brief assignment operators
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator=( const evVertex3D & c )                             { set(c.get_x(), c.get_y(), c.get_z()); return *this; }

    /*! @brief assignment operators
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator=( evVertex3D * c )                                   { set(c->get_x(), c->get_y(), c->get_z()); return *this; }

    /*! @brief assignment operators
     *
     * @param[in] c ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator=( const evVertex2D & c )                             { set(c.get_x(), c.get_y(), 0.0f); return *this; }

    /*! @brief assignment operators
     *
     * @param[in] m ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator*=( const evMatrix & m );

    /*! @brief assignment operators
     *
     * @param[in] m ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& operator*=( const evMatrix * m );





    /*! @brief set routines
     *
     * @param[in] vx ?
     * @param[in] vy ?
     * @param[in] vz ?
     * @todo documentation to be done.
     */
    void  set( float vx, float vy, float vz )       { evVertex2D::set(vx, vy); z = vz; }

    /*! @brief set routines
     *
     * @param[in] value ?
     * @todo documentation to be done.
     */
    void  set_z(float value)                        { z = value; }

    /*! @brief set routines
     *
     * @todo documentation to be done.
     */
    float get_z() const                             { return z; }




    /*! @brief ?
     *
     * @param[in] d ?
     * @todo documentation to be done.
     */
    void add_z( float d ) { z += d; }





    /*! @brief projection
     *
     * @param view_mat ?
     * @param proj_mat ?
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] width ?
     * @param[in] height ?
     * @return ?

     * @todo documentation to be done.
     */
    bool project( const evMatrix & view_mat, const evMatrix & proj_mat, int x1, int y1, int width, int height );

    /*! @brief projection
     *
     * @param view_mat ?
     * @param proj_mat ?
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] width ?
     * @param[in] height ?
     * @return ?

     * @todo documentation to be done.
     */
    bool project( const evMatrix * view_mat, const evMatrix * proj_mat, int x1, int y1, int width, int height );

    /*! @brief projection
     *
     * @param mat ?
     * @param[in] w_halfwidth ?
     * @param[in] w_halfheight ?
     * @return ?

     * @todo documentation to be done.
     */
    bool project( const evMatrix & mat, int w_halfwidth, int w_halfheight );

    /*! @brief projection
     *
     * @param mat ?
     * @param[in] w_halfwidth ?
     * @param[in] w_halfheight ?
     * @return ?

     * @todo documentation to be done.
     */
    bool project( const evMatrix * mat, int w_halfwidth, int w_halfheight );

    /*! @brief projection
     *
     * @param view ?
     * @param proj ?
     * @param[in] w_x ?
     * @param[in] w_y ?
     * @param[in] w_width ?
     * @param[in] w_height ?
     * @todo documentation to be done.
     */
    void unproject( const evMatrix & view, const evMatrix & proj, int w_x, int w_y, int w_width, int w_height );

    /*! @brief projection
     *
     * @param view ?
     * @param proj ?
     * @param[in] w_x ?
     * @param[in] w_y ?
     * @param[in] w_width ?
     * @param[in] w_height ?
     * @todo documentation to be done.
     */
    void unproject( const evMatrix * view, const evMatrix * proj, int w_x, int w_y, int w_width, int w_height );

    /*! @brief projection
     *
     * @param view ?
     * @param proj ?
     * @param[in] w_x ?
     * @param[in] w_y ?
     * @param[in] w_width ?
     * @param[in] w_height ?
     * @param[in] vPlane1 ?
     * @param[in] vPlane2 ?
     * @param[in] vPlane3 ?
     * @return ?

     * @todo documentation to be done.
     */
    bool unproject( const evMatrix & view, const evMatrix & proj, int w_x, int w_y, int w_width, int w_height,
            evVertex3D vPlane1, evVertex3D vPlane2, evVertex3D vPlane3 );

    /*! @brief projection
     *
     * @param view ?
     * @param proj ?
     * @param[in] w_x ?
     * @param[in] w_y ?
     * @param[in] w_width ?
     * @param[in] w_height ?
     * @param[in] vPlane1 ?
     * @param[in] vPlane2 ?
     * @param[in] vPlane3 ?
     * @return ?

     * @todo documentation to be done.
     */
    bool unproject(const evMatrix * view, const evMatrix * proj, int w_x, int w_y, int w_width, int w_height,
            evVertex3D vPlane1, evVertex3D vPlane2, evVertex3D vPlane3 );




    /*! @brief calc distances to lines/planes
     *
     * \verbatim
        usage: result = vertex.distance_to_plane(param1, param2)
       \endverbatim
     * @param[in] plane_normal ?
     * @param[in] plane_vertex ?
     * @return ?

     * @todo documentation to be done.
     */
    float distance_to_plane( const evVertex3D & plane_normal, const evVertex3D & plane_vertex );

    /*! @brief calc distances to lines/planes
     *
     * \verbatim
        usage: result = vertex.distance_to_plane_signed(param1, param2)
       \endverbatim
     * @param[in] plane_normal ?
     * @param[in] plane_vertex ?
     * @return ?

     * @todo documentation to be done.
     */
    float distance_to_plane_signed( const evVertex3D & plane_normal, const evVertex3D & plane_vertex );

    /*! @brief calc distances to lines/planes
     *
     * \verbatim
        usage: result = vertex.distance_to_line(param1, param2)
       \endverbatim
     * @param[in] v1 ?
     * @param[in] v2 ?
     * @return ?

     * @todo documentation to be done.
     */
    float distance_to_line( const evVertex3D& v1, const evVertex3D& v2 );




    /*! @brief returns x and y rotation of the vertex
     *
     * @param xrot ?
     * @param yrot ?
     * @return x and y rotation of the vertex
     * @todo documentation to be done.
     */
    void  get_rotations( float & xrot, float & yrot ) const;

    /*! @brief returns x and y rotation of the vertex
     *
     * @param xrot ?
     * @param yrot ?
     * @return x and y rotation of the vertex
     * @todo documentation to be done.
     */
    void get_rotations_for_pathtracking(float & xrot, float & yrot);

    /*! @brief length
     *
     * @return ?

     * @todo documentation to be done.
     */
    float len() const               { return fsqrt(len2()); };

    /*! @brief length
     *
      * @return ?

     * @todo documentation to be done.
     */
    float len2() const              { return get_x()*get_x() + get_y()*get_y() + z*z; };

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float normalize();




    /*! @brief ?
     *
     * @param axis ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& rotR90( unsigned char axis )          { float f;
                                                                switch(toupper(axis)) {
                                                                case 'X': f=y;y=-z;z=f;break;
                                                                case 'Y': f=x;x=-z;z=f;break;
                                                                case 'Z': f=x;x=-y;y=f;break;
                                                                }
                                                                return *this;
                                                            }

    /*! @brief ?
     *
     * @param axis ?
     * @return ?

     * @todo documentation to be done.
     */
    const evVertex3D& rotL90( unsigned char axis )          {   float f;
                                                                switch(toupper(axis)) {
                                                                case 'X': f=z;z=-y;y=f;break;
                                                                case 'Y': f=z;z=-x;x=f;break;
                                                                case 'Z': f=y;y=-x;x=f;break;
                                                                }
                                                                return *this;
                                                            }




    /*! @brief cross product
     *
     * @param v1 ?
     * @param v2 ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D cross( const evVertex3D & v1, const evVertex3D & v2 );




    /*! @brief center of triangle
     *
     * \verbatim
        usage: result = triangle_center(A, B, C)
       \endverbatim
     * @param[in] v1 ?
     * @param[in] v2 ?
     * @param[in] v3 ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D triangle_center( const evVertex3D & v1, const evVertex3D & v2, const evVertex3D & v3 );

    /*! @brief ?
     *
     * @param[in] v1 ?
     * @param[in] v2 ?
     * @param[in] v3 ?
     * @return ?

     * @todo documentation to be done.
     */
    float triangle_area( const evVertex3D & v1, const evVertex3D & v2, const evVertex3D & v3);

    /*! @brief ?
     *
     * @param[in] v1 ?
     * @param[in] v2 ?
     * @param[in] v3 ?
     * @return ?

     * @todo documentation to be done.
     */
    float Det( const evVertex3D & v1, const evVertex3D & v2, const evVertex3D & v3 );

    /*! @brief ?
     *
     * @param[in] p1 ?
     * @param[in] v1 ?
     * @param[in] p2 ?
     * @param[in] v2 ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D Intersection( const evVertex3D & p1, const evVertex3D & v1, const evVertex3D & p2, const evVertex3D & v2 );

    /*! @brief ?
     *
     * @param[in] plane_point ?
     * @param[in] plane_normal ?
     * @param[in] line_point ?
     * @param[in] line_direction ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D Intersect_Plane_with_Line( const evVertex3D& plane_point,
                                                 const evVertex3D& plane_normal,
                                                 const evVertex3D& line_point,
                                                 const evVertex3D& line_direction );

    /*! @brief ?
     *
     * @param[in] a1 ?
     * @param[in] a2 ?
     * @param[in] b1 ?
     * @param[in] b2 ?
     * @param[out] result ?
     * @return ?

     * @todo documentation to be done.
     */
    friend bool Intersection_2D( const evVertex3D & a1, const evVertex3D & a2, const evVertex3D & b1, const evVertex3D & b2, evVertex3D & result );




    /*! @brief ?
     *
     * @param[in] nv ?
     * @param[in] v ?
     * @param[in] p ?
     * @return ?

     * @todo documentation to be done.
     */
    friend bool point_inside_polygon_2D( int nv, const evVertex3D * v, const evVertex3D & p);

    /*! @brief ?
     *
     * @param[in] nv ?
     * @param[in] v ?
     * @param[in] p ?
     * @return ?

     * @todo documentation to be done.
     */
    friend bool point_inside_polygon_xz( int nv, const evVertex3D * v, const evVertex3D & p);




    /*! @brief ?
     *
     * @param[in] v1 ?
     * @param[in] v2 ?
     * @return ?

     * @todo documentation to be done.
     */
    float Angle_between_Vertices( const evVertex3D & v1, const evVertex3D & v2 );




    /*! @brief where is the point on my line (A to B) which is closest to point (C)
     *
     * @param[in] A ?
     * @param[in] B ?
     * @param[in] C ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D Point_to_Line( const evVertex3D & A, const evVertex3D & B, const evVertex3D & C );




    /*! @brief mirror a point (C) on a line (A to B) in space
     *
     * @param[in] A ?
     * @param[in] B ?
     * @param[in] C ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D Mirror_on_Line( const evVertex3D & A, const evVertex3D & B, const evVertex3D & C );
    /*! @brief ?
     *
     * @param v1 ?
     * @param v2 ?
     * @param v3 ?
     * @todo documentation to be done.
     */
    void face_output_normal( const evVertex3D & v1, const evVertex3D & v2, const evVertex3D & v3 );

    /*! @brief ?
     *
     * @param v3dA ?
     * @param v3dB ?
     * @param v3dC ?
     * @todo documentation to be done.
     */
    void PlaneRotations( const evVertex3D & v3dA, const evVertex3D & v3dB, const evVertex3D & v3dC );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void glVertex() const {glVertex3f(x,y,z);};

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void glNormal() const {glNormal3d(x,y,z);};
};




// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief needed for evSpline
 *
 * @todo documentation to be done.
 */
struct tagSplNode
{
    /// @todo documentation to be done.
    double xyz[MAXSPLCOMP];
    /// @todo documentation to be done.
    double b[MAXSPLCOMP];
    /// @todo documentation to be done.
    double c[MAXSPLCOMP];
    /// @todo documentation to be done.
    double d[MAXSPLCOMP];
    /// @todo documentation to be done.
    double Length;
};
/// @todo documentation to be done.
typedef struct tagSplNode TSplNode;
/// @todo documentation to be done.
typedef TSplNode * PSplNode;





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief a simple 3d spline class.
 *
 * @todo documentation to be done.
 */
class evSpline
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    evSpline();

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~evSpline();

    /*! @brief adds a new point
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void add( double x, double y, double z );

    /*! @brief calculates the spline
     *
     * @return ?

     * @todo documentation to be done.
     */
    int calculate( void );

    /*! @brief sets tolerance
     *
     * @param[in] tol ?
     * @todo documentation to be done.
     */
    void set_tol( double tol );

    /*! @brief gets 3d coordinates of the point at a specific spline length
     *
     * @param[in] length ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D coordinates( double length );

    /*! @brief finds length of point x|y|z
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int find( double x, double y, double z );

    /*! @brief clears all points of spline
     *
     * @todo documentation to be done.
     */
    void clear( void );

    /*! @brief returns length of spline
     *
     * @return ?

     * @todo documentation to be done.
     */
    double get_length( void ) { return length; };

    /*! @brief ?
     *
     * @param[in] iNode  ?
     * @return ?

     * @todo documentation to be done.
     */
    double get_length(int iNode);

    /*! @brief extend the spline by front and back (length)
     *
     * @param[in] front ?
     * @param[in] back ?
     * @return ?

     * @todo documentation to be done.
     */
    int extend( double front, double back );

    /*! @brief get an interval for drawing straight lines
     *
     * if straight lines are drawn at this interval, it
     * is guaranteed, that the distance between any given point
     * on the lines and the corresponding point on the spline
     * doesn't exceed threshold
     * @param[in] threshold
     * @return interval for drawing straight lines
     */
    double get_interval( double threshold );

    void *PNodes;

private:
    PSplNode Node;
    PSplNode Nd1;
    PSplNode Nd2;
    double Tolerance;
    int nComp;
    double length;
};



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class CVSpline1D
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    CVSpline1D() {m_dTolerance = 0.01; m_bRecompute = true; m_iMethod = 2;};

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~CVSpline1D() {Clear();};

    /*! @brief ?
     *
     * @param[in] dVertex ?
     * @todo documentation to be done.
     */
    void AddVertex( double dVertex );

    /*! @brief ?
     *
     * @param[in] dVertex ?
     * @todo documentation to be done.
     */
    void AddStop(double dVertex);

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dVertex ?
     * @todo documentation to be done.
     */
    void InsertVertex( int iV, double dVertex );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @todo documentation to be done.
     */
    void RemoveVertex( int iV );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dVertex ?
     * @todo documentation to be done.
     */
    void MoveVertex( int iV, double dVertex );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void Clear( void );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void Recompute( void );

    /*! @brief ?
     *
     * @param[in] dTol ?
     * @todo documentation to be done.
     */
    void SetTolerance(double dTol) {
      if (dTol <= 0.0f)
        dTol = 0.01f; 
      
      m_dTolerance = dTol; Recompute();
    };

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dVertex ?
     * @todo documentation to be done.
     */
    void SetVertex( int iV, double dVertex );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetVertex( int iV ) {
        if (iV > (int)m_vecVertices.size()-1 || iV < 0) return 0.;
        return m_vecVertices[iV];
    };

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dU ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetVertex( int iV, double dU ) {
        if (iV > (int)m_vecVertices.size()-2 || iV < 0) return 0.;
        return m_vecVertices[iV] + m_vecB[iV]*dU + m_vecC[iV]*dU*dU + m_vecD[iV]*dU*dU*dU;
    };

    /*! @brief ?
     *
     * @param[in] bFlag ?
     * @return ?

     * @todo documentation to be done.
     */
    void SetRecompute( bool bFlag ) {m_bRecompute = bFlag;};

    /*! @brief ?
    *
    * @return ?

    * @todo documentation to be done.
    */
    bool GetRecompute() { return m_bRecompute; };

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int GetNrOfVertices( void ) {return static_cast<int>(m_vecVertices.size());}

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int GetNrOfStops() {return static_cast<int>(m_vecStops.size());}

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int GetStop(int iS) {return m_vecStops[iS];};

    /*! @brief ?
     *
     * @param[in] dValue ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetUForValue( double dValue );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void ExtendStart();

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void ExtendEnd();

    /*! @brief ?
     *
     * @param[in] iMethod ?
     * @todo documentation to be done.
     */
    void SetInterpolation( int iMethod ) {m_iMethod = iMethod;};

protected:
    ///
    std::vector<double> m_vecVertices;
    ///
    std::vector<double> m_vecB;
    ///
    std::vector<double> m_vecC;
    ///
    std::vector<double> m_vecD;
    ///
    std::vector<int> m_vecStops;
    ///
    double m_dTolerance;
    ///
    double m_dMin;
    ///
    double m_dMax;
    ///
    bool m_bRecompute;
    ///
    int m_iMethod;
};



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief a simple 3d spline class.
 *
 * @todo documentation to be done.
 */
class CVSpline3D
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    CVSpline3D() {m_dTolerance = 0.01; m_iSort = 0; m_bRecompute = true;};

    /*! @brief ?
     *
     * @param[in] iSort ?
     * @todo documentation to be done.
     */
    CVSpline3D( int iSort ) {m_dTolerance = 0.01; m_iSort = iSort; m_bRecompute = true;};

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~CVSpline3D() {Clear();};

    /*! @brief ?
     *
     * @param[in] v3dNew ?
     * @return ?

     * @todo documentation to be done.
     */
    int AddVertex( const evVertex3D & v3dNew );

    /*! @brief ?
     *
     * @param[in] v3dNew ?
     * @return ?

     * @todo documentation to be done.
     */
    int AddStop(const evVertex3D& v3dNew);
    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] v3dNew ?
     * @todo documentation to be done.
     */
    void InsertVertex( int iV, const evVertex3D & v3dNew );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @todo documentation to be done.
     */
    void RemoveVertex( int iV );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] v3dNew ?
     * @todo documentation to be done.
     */
    void MoveVertex( int iV, const evVertex3D & v3dNew );

    /*! @brief ?
     *
     * @param[in] dTol ?
     * @todo documentation to be done.
     */
    void SetTolerance( double dTol );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void Recompute( void );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void Clear( void );

    /*! @brief ?
     *
     * @param[in] dLength ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D GetVertex( double dLength );

     /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    double GetLength() {return m_vecLengths[m_vecLengths.size()-1];};

    /*! @brief ?
     *
     * @param[in] dLength ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetUForLength( double dLength );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D GetVertex( int iV ) {return evVertex3D((float)m_splX.GetVertex(iV), (float)m_splY.GetVertex(iV), (float)m_splZ.GetVertex(iV));};

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dU ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D GetVertex( int iV, double dU ) {return evVertex3D((float)m_splX.GetVertex(iV,dU), (float)m_splY.GetVertex(iV,dU), (float)m_splZ.GetVertex(iV,dU));};

    /*! @brief ?
     *
     * @param v3dVertex ?
     * @return ?

     * @todo documentation to be done.
     */
    bool GetVertexAtZ( evVertex3D & v3dVertex );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int GetNrOfVertices( void ) {return m_splX.GetNrOfVertices();};

    /*! @brief ?
     *
     * @param[in] bFlag ?
     * @todo documentation to be done.
     */
    void SetRecompute( bool bFlag ) {m_bRecompute = bFlag; m_splX.SetRecompute(bFlag);m_splY.SetRecompute(bFlag);m_splZ.SetRecompute(bFlag);};

    /*! @brief ?
    *
    * @return ?

    * @todo documentation to be done.
    */
    bool GetRecompute() { return m_bRecompute; };

    /*! @brief ?
     *
     * @param[in] dStart ?
     * @param[in] dEnd ?
     * @todo documentation to be done.
     */
    void Extend( double dStart, double dEnd );

    /*! @brief ?
     *
     * @param[in] iX ?
     * @param[in] iY ?
     * @param[in] iZ ?
     * @todo documentation to be done.
     */
    void SetInterpolation( int iX, int iY, int iZ ) {m_splX.SetInterpolation(iX); m_splY.SetInterpolation(iY); m_splZ.SetInterpolation(iZ);};

protected:
    CVSpline1D m_splX;
    CVSpline1D m_splY;
    CVSpline1D m_splZ;
    double m_dTolerance;
    bool m_bRecompute;
    std::vector<double> m_vecLengths;
    int m_iSort;
};





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class CVTrack: public CVSpline3D
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    CVTrack() : CVSpline3D() {m_fTimeBase = 50.;};

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~CVTrack() {Clear();};

    /*! @brief ?
     *
     * @param v3dNew ?
     * @param[in] uiTimeCode ?
     * @param[in] dHeight ?
     * @return ?

     * @todo documentation to be done.
     */
    int AddVertex( const evVertex3D & v3dNew, unsigned int uiTimeCode, double dHeight );

    /*! @brief ?
     *
     * @param v3dNew ?
     * @param[in] uiTimeCode ?
     * @param[in] dHeight ?
     * @param[in] dSpeed ?
     * @return ?

     * @todo documentation to be done.
     */
    int AddVertex( const evVertex3D & v3dNew, unsigned int uiTimeCode, double dHeight, double dSpeed );

    /*! @brief ?
     *
     * @param v3dNew ?
     * @param[in] uiTimeCode ?
     * @param[in] dHeight ?
     * @return ?

     * @todo documentation to be done.
     */
    int AddStop(const evVertex3D& v3dNew, unsigned int uiTimeCode, double dHeight);

    /*! @brief ?
     *
     * @param v3dNew ?
     * @param[in] uiTimeCode ?
     * @param[in] dHeight ?
     * @param[in] dSpeed ?
     * @return ?

     * @todo documentation to be done.
     */
    int AddStop(const evVertex3D& v3dNew, unsigned int uiTimeCode, double dHeight, double dSpeed);

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] uiTimeCode ?
     * @todo documentation to be done.
     */
    void MoveTimeCode( int iV, unsigned int uiTimeCode );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dHeight ?
     * @todo documentation to be done.
     */
    void MoveHeight( int iV, double dHeight );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dSpeed ?
     * @todo documentation to be done.
     */
    void MoveSpeed( int iV, double dSpeed );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] v3dNew ?
     * @param[in] uiTimeCode ?
     * @param[in] dHeight ?
     * @todo documentation to be done.
     */
    void MoveVertex( int iV, const evVertex3D & v3dNew, unsigned int uiTimeCode, double dHeight );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] v3dNew ?
     * @param[in] uiTimeCode ?
     * @param[in] dHeight ?
     * @param[in] dSpeed ?
     * @todo documentation to be done.
     */
    void MoveVertex( int iV, const evVertex3D& v3dNew, unsigned int uiTimeCode, double dHeight, double dSpeed );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @todo documentation to be done.
     */
    void RemoveVertex( int iV );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void CalculateSpeed( void );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetHeight( int iV ) {return m_splHeight.GetVertex(iV);};

    /*! @brief ?
     *
     * @param iV ?
     * @param dU ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetHeight( int iV, double dU ) {return m_splHeight.GetVertex(iV, dU);};

    /*! @brief ?
     *
     * @param[in] iV ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetSpeed( int iV ) {return m_splSpeed.GetVertex(iV);};

    /*! @brief ?
     *
     * @param[in] iV
     * @param[in] dU
     * @return ?

     * @todo documentation to be done.
     */
    double GetSpeed( int iV, double dU ) {return m_splSpeed.GetVertex(iV, dU);};

    /*! @brief ?
     *
     * @param[in] iV ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetTimeCode( int iV ) {return m_splTimeCode.GetVertex(iV);}

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dU ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetTimeCode( int iV, double dU ) {return m_splTimeCode.GetVertex(iV, dU);}

    /*! @brief ?
     *
     * @param[in] dValue ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetUForTimeCode( double dValue ) {return m_splTimeCode.GetUForValue(dValue);};

    /*! @brief ?
     *
     * @param[in] dValue ?
     * @return ?

     * @todo documentation to be done.
     */
    double GetLengthForTimeCode(double dValue);

    /*! @brief ?
     *
     * @param[in] fTimeBase ?
     * @return ?

     * @todo documentation to be done.
     */
    void SetTimeBase( float fTimeBase ) {m_fTimeBase = fTimeBase;};

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void Clear();

    /*! @brief ?
    *
    * @param[in] bFlag ?

    * @todo documentation to be done.
    */
    void ActivateRecompute(bool bFlag);

protected:
    ///
    CVSpline1D m_splSpeed;
    ///
    CVSpline1D m_splHeight;
    ///
    CVSpline1D m_splTimeCode;
    ///
    float m_fTimeBase;
};





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class CVSplineRef : public CVSpline3D
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    CVSplineRef() : CVSpline3D() {};

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~CVSplineRef() {Clear();};

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void Clear( void );

    /*! @brief ?
     *
     * @param v3dNew ?
     * @param[in] dReference ?
     * @todo documentation to be done.
     */
    void AddVertex( const evVertex3D & v3dNew, double dReference );

    /*! @brief ?
     *
     * @param[in] iV ?
     * @param[in] dRef ?
     * @todo documentation to be done.
     */
    void MoveRef( int iV, double dRef );

    /*! @brief ?
     *
     * @param[in] dRef ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D GetVertexAtRef( double dRef );

private:
    ///
    CVSpline1D m_splReference;
};





// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class evQuaternion
{
public:
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    evQuaternion(void)
    {
        x = 0.0;
        y = 0.0;
        z = 0.0;
        w = 1.0;
    }

    /*! @brief ?
     *
     * @param[in] rx ?
     * @param[in] ry ?
     * @param[in] rz ?
     * @todo documentation to be done.
     */
    evQuaternion( float rx, float ry, float rz )
    {
        set(rx, ry, rz);
    }

    /*! @brief copy constructor
     *
     * @param[in] src ?
     * @return ?

     * @todo documentation to be done.
     */
    evQuaternion( const evQuaternion & src )
    {
        x = src.x;
        y = src.y;
        z = src.z;
        w = src.w;
    }

    /*! @brief convert the three angles into matrix and then into quaternion.
     *
     * @param[in] rx ?
     * @param[in] ry ?
     * @param[in] rz ?
     * @todo documentation to be done.
     */
    void set( float rx, float ry, float rz );

    /*! @brief convert the matrix into quaternion.
     *
     * @param[in] mat ?
     * @todo documentation to be done.
     */
    void set( const evMatrix& mat );

    /*! @brief set the quaternion with an angle and a vertex
     *
     * @param[in] v ?
     * @param[in] angle ?
     * @todo documentation to be done.
     */
    void set( const evVertex3D & v, float angle )
    {
        evVertex3D tmp = v;
        w = fcos(angle/2);
        tmp.normalize();
        tmp *= fsin(angle/2);
        x = tmp.get_x();
        y = tmp.get_y();
        z = tmp.get_z();
    }


    /*! @brief get the tree angles
     *
     * @param[out] rx ?
     * @param[out] ry ?
     * @param[out] rz ?
     * @todo documentation to be done.
     */
    void get( float & rx, float & ry, float & rz ) const;

    /*! @brief put the quaternion into the matrix
     *
     * @param[out] matrix
     * @todo documentation to be done.
     */
    void get( evMatrix & matrix ) const;

    /*! @brief interpolate between two quarternions value must be between 0.0 and 1.0
     *
     * @param qBegin ?
     * @param qEnd ?
     * @param[in] t ?
     * @param[in] spin ?
     * @todo documentation to be done.
     */
    void interpolate( const evQuaternion& qBegin, const evQuaternion& qEnd, float t, int spin=0 );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void info( void ) const;

private:

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void unify(void)
    {
        double length = x*x + y*y + z*z + w*w;
        x /= length;
        y /= length;
        z /= length;
        w /= length;
    }

    double x, y, z, w;
};




// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief angle between two Vertices (returning Angle in !!!rad!!!)
 *
 * @param[in] v1 ?
 * @param[in] v2 ?
 * @return angle between two Vertices
 * @todo documentation to be done.
 */
inline float Angle_between_Vertices( const evVertex3D& v1, const evVertex3D& v2 )
{
    // calclulate the angle between the two vertices
    float pre_acos = (v1.get_x()*v2.get_x() +
                      v1.get_y()*v2.get_y() +
                      v1.get_z()*v2.get_z()) / sqrt(v1.len2() * v2.len2());

    // sometimes the pre_acos is too high or too low because of rounding
    if (pre_acos > 1.0)
        pre_acos = 1.0;
    else if (pre_acos < -1.0)
        pre_acos = -1.0;
    return facos(pre_acos);
}




// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @param[in] A ?
 * @param[in] B ?
 * @param[in] C ?
 * @return ?

 * @todo documentation to be done.
 */
inline evVertex3D Point_to_Line( const evVertex3D& A, const evVertex3D& B, const evVertex3D& C )
{
    evVertex3D tmp = C;
    float distance_to_c = tmp.distance_to_line(A, B);

    // the point is on the line, so return C
    if (distance_to_c == 0.0)
        return C;

    evVertex3D a_b = B - A;
    evVertex3D a_c = C - A;

    float angle = Angle_between_Vertices(a_c, a_b);

    float length_on_a_c = a_c.len() * sin((float)M_PI_2 - angle);

    a_b.normalize();
    return A + a_b * length_on_a_c;
}




// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @param[in] v3dA ?
 * @param[in] v3dB ?
 * @param[in] v3dC ?
 * @return ?

 * @todo documentation to be done.
 */
inline float DistanceToLine( const evVertex3D& v3dA, const evVertex3D& v3dB, const evVertex3D& v3dC )
{
    evVertex3D v3dD = (v3dB - v3dA)/2.;
    evVertex3D v3dLine = v3dA;
    evVertex3D v3dDist;
    double fDist = 0.0;
    v3dDist = v3dLine - v3dC;
    double fDistOld = v3dDist.len();
    bool bSolve = true;
    int iIter = 0;
    while (bSolve) {
        v3dLine += v3dD;
        v3dDist = v3dLine - v3dC;
        fDist = v3dDist.len();
        bSolve = fabs(fDist-fDistOld) > 0.01 && iIter < 1000; // FLT_EPSILON;
        if (fDist > fDistOld) {
            v3dD *= -0.5;
        }
        fDistOld = fDist;
    }
    return (float)fDist;
}

evVertex3D Intersect_Plane_with_Line( const evVertex3D& plane_point,
                                             const evVertex3D& plane_normal,
                                             const evVertex3D& line_point,
                                             const evVertex3D& line_direction );


inline void ResetToZero(float& v) { v=0.0f; }
inline void ResetToZero(int& v) { v=0; }
inline void ResetToZero(unsigned int& v) { v=0; }
inline void ResetToZero(long& v) { v=0; }
inline void ResetToZero(unsigned long& v) { v=0; }
inline void ResetToZero(bool& v) { v=false; }

inline bool value_is_equal(const float x, const float y, float epsilon = 10*FLT_EPSILON)
{
    if (x < y-epsilon || x > y+epsilon)
        return false;
    else
        return true;
}

inline bool value_is_zero(const float x)
{
    return value_is_equal(x, 0.0F);
}

inline bool value_is_equal(const double x, const double y, double epsilon = 10*DBL_EPSILON)
{
    if (x < y-epsilon || x > y+epsilon)
        return false;
    else
        return true;
}

inline bool value_is_zero(const double x)
{
    return value_is_equal(x, 0.0);
}

inline bool value_is_equal(const bool x, const bool y)
{
    return x == y;
}

inline bool value_is_equal(const int x, const int y)
{
    return x == y;
}


#endif
