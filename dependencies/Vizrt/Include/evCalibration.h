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

#ifndef evCalibration_H
#define evCalibration_H


#include "evPyramid.h"
#include <vector>
using std::vector;

//----------------------------------------------------------------------------
// evCalibration.h
//----------------------------------------------------------------------------
typedef vector<evPyramid*> PYRAMIDVEC;
typedef vector<int> INTVEC;

/*! @brief evCalPoint contains the camera pan and tilt angles and optionally the world coordinates of the looked at point.
 *
 */
class evCalPoint {
public:
    //! default constructor
    evCalPoint();

    //! copy constructor
    evCalPoint(const evCalPoint& rp)
    {
        m_v3dLocal = rp.m_v3dLocal;
        m_dPan = rp.m_dPan;
        m_dTilt = rp.m_dTilt;
        m_bAnglesSet = rp.m_bAnglesSet;
    }

    /*! @brief ?
     *
     * @param[in] fX
     * @param[in] fY
     * @param[in] fZ
     * @todo documentation to be done.
     */
    evCalPoint(float fX, float fY, float fZ)
    {
        m_v3dLocal.x = fX;
        m_v3dLocal.y = fY;
        m_v3dLocal.z = fZ;
        m_bAnglesSet = false;
    }

    /*! @brief constructor with world coordinates supplied.
     *
     * @param[in] v3dPos world coordinates
     */
    evCalPoint( const evVertex3D& v3dPos )
    {
        m_v3dLocal = v3dPos;
        m_bAnglesSet = false;
    }

    /*! @brief constructor with world coordinates and pan and tilt angles supplied.
     *
     * @param[in] v3dPos world coordinates
     * @param[in] dPan pan angle
     * @param[in] dTilt tilt angle
     */
    evCalPoint( const evVertex3D& v3dPos, double dPan, double dTilt )
    {
            m_v3dLocal = v3dPos;
            m_dPan = dPan;
            m_dTilt = dTilt;
            m_bAnglesSet = true;
    }

    /*! @brief constructor with world coordinates and pan and tilt angles supplied.
     *
     * @param[in] fX
     * @param[in] fY
     * @param[in] fZ
     * @param[in] dPan pan angle
     * @param[in] dTilt tilt angle
     */
    evCalPoint( float fX, float fY, float fZ, double dPan, double dTilt )
    {
        m_v3dLocal.x = fX;
        m_v3dLocal.y = fY;
        m_v3dLocal.z = fZ;
        m_dPan = dPan;
        m_dTilt = dTilt;
        m_bAnglesSet = true;
    }

    /*! @brief constructor with pan and tilt angles.
     *
     * @param[in] dPan pan angle
     * @param[in] dTilt tilt angle
     */
    evCalPoint( double dPan, double dTilt )
    {
        m_dPan = dPan;
        m_dTilt = dTilt;
        m_bAnglesSet = true;
    }

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~evCalPoint() { m_vecPyramids.clear(); }

    /*! @brief set the world coordinates.
     *
     * @param[in] v3dWorld world coordinates
     */
    void SetWorldCoor(const evVertex3D& v3dWorld) {m_v3dWorld = v3dWorld;};

    /*! @brief set pan and tilt.
     *
     * @param[in] dPan pan angle
     * @param[in] dTilt tilt angle
     */
    void SetAngles(double dPan, double dTilt)
    {
        m_dPan = dPan;
        m_dTilt = dTilt;
        m_bAnglesSet = true;
    }

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void ResetAngles() {m_bAnglesSet = false;};

    /*! @brief return the world coordinates.
     *
     * @return the world coordinates
     */
    evVertex3D GetWorldCoor() const {return m_v3dWorld;};

    /*! @brief set the local coordinates.
     *
     * @param[in] v3dLocal local coordinates
     */
    void SetLocalCoor(const evVertex3D& v3dLocal) {m_v3dLocal = v3dLocal; m_bAnglesSet = false;};

    /*! @brief return the local coordinates.
     *
     * @return the local coordinates
     */
    evVertex3D GetLocalCoor() const {return m_v3dLocal;};

    /*! @brief get the pan angle.
     *
     * @return the pan angle
     */
    double GetPan() const {return m_dPan;};

    /*! @brief get the tilt angle.
     *
     * @return the tilt angle
     */
    double GetTilt() const {return m_dTilt;};

    /*! @brief add a pyramid to the list of pyramids involved to calc. this point.
     *
     * @param[in] pPyramid
     */
    void AddPyramid( evPyramid * pPyramid ) {m_vecPyramids.push_back(pPyramid);};

    /*! @brief add the ray index for the last pyramid.
     *
     * @param[in] iRay
     */
    void AddRay( int iRay ) {m_vecRays.push_back(iRay);};

    /*! @brief return the nr of pyramids involved to find a solution for this point.
     *
     * @return number of pyramids
     */
    int GetNrOfPyramids() const {return (int) m_vecPyramids.size();};

    /*! @brief return a pyramid from the list pointed to by i
     *
     * @param[in] i
     * @return a pyramid from the list pointed to by i
     */
    evPyramid* GetPyramid( int i ) {return m_vecPyramids[i];};

    /*! @brief return the corresponding ray
     *
     * @param[in] i
     */
    int GetRay( int i ) {return m_vecRays[i];};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool AreAnglesSet() const {return m_bAnglesSet;};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool IsValid() const {return m_bValid;};

    /*! @brief ?
     *
     * @param[in] bFlag ?
     * @todo documentation to be done.
     */
    void SetValid( bool bFlag ) {m_bValid = bFlag;};

protected:
    evVertex3D m_v3dLocal;
    evVertex3D m_v3dWorld;
    double m_dPan;
    double m_dTilt;
    bool m_bAnglesSet;
    bool m_bValid;
    PYRAMIDVEC m_vecPyramids;
    INTVEC m_vecRays;
};

typedef vector<evCalPoint*> CALPOINTVEC;

/*! @brief calibration class
 *
 * evCalibration calculates the world coordinates of a gemoetry with at least 4 control points.
        use this class in the following way.
        o add at least 4 control points with the pan and tilt angles of the camera looking at these points.
          optionally you can supply local coordinates of the control points (-> mapping)
        o sectorize the geometry by DefineFace
          Note: the control point index starts with 0 !!!
        o call Solve()
        if local coordinates for the control points where given, you can retrieve the objects transformation
        by calling:
        o GetOrigin()
        o GetRotations()
 *
 */
class evCalibration  {

public :
    // Constructors and destructors:
    evCalibration();
    ~evCalibration();

public :
    /*! @brief add a control point with world coordinates.
     *
     * @param[in] v3dPos
     * @param[in] dPan
     * @param[in] dTilt
     * @return ?

     * @todo documentation to be done.
     */
    int AddControlPoint( const evVertex3D& v3dPos, double dPan, double dTilt );

    /*! @brief add a control point where only the pan and tilt angle are known.
     *
     * @param[in] dPan pan value
     * @param[in] dTilt tilt value
     * @return ?

     * @todo documentation to be done.
     */
    int AddControlPoint( double dPan, double dTilt );

    /*! @brief define a triangular face with the indices iA, iB and iC being valid control points.
     *
     * define a triangular face of the object, which needs to be calibrated.
     * this face will be used as the triangular base for a pyramid (evPyramid)
     * at least two such faces must be present for the calibration to work
     *     attention!! use this method only if the world coordinates of the control points are known.
     * @param[in] iA integer face A
     * @param[in] iB integer face B
     * @param[in] iC integer face C
     * @return ?

     * @todo documentation to be done.
     */
    int DefineFace( int iA, int iB, int iC );

    /*! @brief define a triangular face with side lengths. dA is the length opposite angle A.
     *
     * define a triangular face of the object, which needs to be calibrated.
     * this face will be used as the triangular base for a pyramid (evPyramid)
     * at least two such faces must be present for the calibration to work
     * @param[in] iA integer face A
     * @param[in] iB integer face B
     * @param[in] iC integer face C
     * @param[in] dA double face A
     * @param[in] dB double face B
     * @param[in] dC double face C
     * @return ?

     * @todo documentation to be done.
     */
    int DefineFace( int iA, double dA, int iB, double dB, int iC, double dC );

    /*! @brief ?
     *
     * @param[in] iPt pt value
     * @param[in] dPan pan value
     * @param[in] dTilt tilt value
     * @return ?

     * @todo documentation to be done.
     */
    int SetAngles( int iPt, double dPan, double dTilt );

    /*! @brief try to solve the calibration
     *
     * @param[in] bAccurate
     * @return ?

     * @todo documentation to be done.
     */
    int Solve( bool bAccurate );

    /*! @brief ?
     *
     * @param[in] iTotalSolutions ?
     * @return ?

     * @todo documentation to be done.
     */
    int SolveForCoordinates( int iTotalSolutions );

    /*! @brief ?
     *
     * @param[in] iTotalSolutions ?
     * @return ?

     * @todo documentation to be done.
     */
    int SolveForTransformationFast( int iTotalSolutions );

    /*! @brief ?
     *
     * @param[in] iTotalSolutions ?
     * @return ?

     * @todo documentation to be done.
     */
    int SolveForTransformationAccurate( int iTotalSolutions );

    /*! @brief return the origin of the structure.
     *
     * this value can only be retrieved if the world coordinates are known.
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D GetOrigin( void ) const {return m_v3dOrigin;};

    /*! @brief return the rotations of the structure.
     *
     * this value can only be retrieved if the world coordinates are known.
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D GetRotations( void ) const {return m_v3dRotations;};

    /*! @brief ?
     *
     * @param[in] iCP ?
     * @return ?

     * @todo documentation to be done.
     */
    evVertex3D GetWorldCoor(int iCP) const;

    /*! @brief ?
     *
     * @param[in] iCP ?
     * @return ?

     * @todo documentation to be done.
     */
    bool IsWorldCoorValid(int iCP) const;

    /*! @brief ?
     *
     * @param[in] n3dModel ?
     * @return ?

     * @todo documentation to be done.
     */
    void SetModelNormal(const evVertex3D& n3dModel) {m_n3dModel = n3dModel;};

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void Reset( void );

protected:
    // Attributes
    PYRAMIDVEC m_vecPyramids;
    CALPOINTVEC m_vecPoints;
    bool m_bSolved;
    bool m_bVertices;
    evVertex3D m_v3dOrigin;
    evVertex3D m_v3dRotations;
    evVertex3D m_n3dModel;
};


#endif
