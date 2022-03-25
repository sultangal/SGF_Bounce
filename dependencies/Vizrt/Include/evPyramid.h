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

#ifndef evPyramid_H
#define evPyramid_H




#include "evMath.h"




// ---------------------------------------------------------------------
//  evPyramid.h
// ---------------------------------------------------------------------
/*! @brief a pyramid with a triangular base.
 *
 * the pyramid is defined with the top at 0,0,0 and a triangular base.
 * the rays emitting from the top to the corner nodes of the base are defined by their tilt and pan angles.
 * the triangular base itself is defined by its side lengths, or a tripplet of 3d coordinates from the original
 * geometry.
 * if a vertex triplet and a transformation matrix are supplied the deviation of the solved triangles can
 * be calculated.
 * you can employ this information to use an iterative approch to minimize measurement inacc. (see evCalibration)
 */
class evPyramid  {

////    User implicit entries     ////
public :

    /*! @brief constructor
     *
     */
    evPyramid();

    /*! @brief destructor
     *
     */
    ~evPyramid() {};

    /*! @brief constructor
     *
     * @param[in] dPanA ?
     * @param[in] dTiltA ?
     * @param[in] dPanB ?
     * @param[in] dTiltB ?
     * @param[in] dPanC ?
     * @param[in] dTiltC ?
     * @param[in] v3dA ?
     * @param[in] v3dB ?
     * @param[in] v3dC ?
     */
    evPyramid( double dPanA, double dTiltA, double dPanB, double dTiltB, double dPanC, double dTiltC,
                const evVertex3D & v3dA, const evVertex3D & v3dB, const evVertex3D & v3dC );

    /*! @brief constructor
     *
     * @param[in] dPanA ?
     * @param[in] dTiltA ?
     * @param[in] dPanB ?
     * @param[in] dTiltB ?
     * @param[in] dPanC ?
     * @param[in] dTiltC ?
     * @param[in] dA ?
     * @param[in] dB ?
     * @param[in] dC ?
     */
    evPyramid( double dPanA, double dTiltA, double dPanB, double dTiltB, double dPanC, double dTiltC, double dA, double dB, double dC);

////    User explicit entries     ////
public :
    // Attribute accessors and mutators:

    /*! @brief set the properties of the pyramid.
     *
     * the pyramid is described by the tilt and pan angles of the rays emitting from 0,0,0
     * and the vertices of the base triangle. these vertices are describe part of the geometry
     * you want to transform into world coordinate space. they will be used to calculate the side lengths.
     * vertices and a transformation matrix are nec. to get the deviation from the original geometry.
     * @param[in] dPanA ?
     * @param[in] dTiltA ?
     * @param[in] dPanB ?
     * @param[in] dTiltB ?
     * @param[in] dPanC ?
     * @param[in] dTiltC ?
     * @param[in] v3dA ?
     * @param[in] v3dB ?
     * @param[in] v3dC ?
     */
    void SetProperties( double dPanA, double dTiltA, double dPanB, double dTiltB, double dPanC, double dTiltC,
                const evVertex3D & v3dA, const evVertex3D & v3dB, const evVertex3D & v3dC );

    /*! @brief set the properties of the pyramid.
     *
     * the pyramid is described by the tilt and pan angles of the rays emitting from 0,0,0
     * and the side lengths of the base triangle. ray a hits the corner of the triangle with the opening angle alpha.
     * side lenghts a is the opposite site. meaning its enclosed between the rays b and c. the same applies
     * for side lengths b and c respectively.
     * @param[in] dPanA ?
     * @param[in] dTiltA ?
     * @param[in] dPanB ?
     * @param[in] dTiltB ?
     * @param[in] dPanC ?
     * @param[in] dTiltC ?
     * @param[in] dA ?
     * @param[in] dB ?
     * @param[in] dC ?
     */
    void SetProperties( double dPanA, double dTiltA, double dPanB, double dTiltB, double dPanC, double dTiltC, double dA, double dB, double dC );

    /*! @brief set the pan and tilt angle the three rays emitting from the top of pyramid 0,0,0.
     *
     * @param[in] dPanA ?
     * @param[in] dTiltA ?
     * @param[in] dPanB ?
     * @param[in] dTiltB ?
     * @param[in] dPanC ?
     * @param[in] dTiltC ?
     */
    void SetRayAngles( double dPanA, double dTiltA, double dPanB, double dTiltB, double dPanC, double dTiltC );

    /*! @brief set the pan and tilt angle for a specific ray.
     *
     * @param[in] iRay ?
     * @param[in] dPan ?
     * @param[in] dTilt ?
     */
    void SetRayAngles( int iRay, double dPan, double dTilt );

    /*! @brief set the base triangle side lengths (see set properties for a description).
     *
     * @param[in] dA ?
     * @param[in] dB ?
     * @param[in] dC ?
     */
    void SetBaseSides( double dA, double dB, double dC );

    /*! @brief set the vertices of the base triangles.
     *
     * @param[in] v3dA ?
     * @param[in] v3dB ?
     * @param[in] v3dC ?
     */
    void SetBaseVertices( const evVertex3D & v3dA, const evVertex3D & v3dB, const evVertex3D & v3dC );

    /*! @brief get the nr of solutions for the given pyramid. up to 8.
     *
     * @return ?

     */
    int GetNrOfSolutions( void );

    /*! @brief set the solution. range 0 to NrOfSolutions -1
     *
     * @param[in] iSolution ?
     */
    void SetSolution( int iSolution ) {m_iSolution = iSolution;} ;

    /*! @brief increment the solution, set to 0 if the maximum was reached.
     *
     * @return ?

     */
    int IncrementSolution( void );

    /*! @brief return the current solution
     *
     * @return ?

     */
    int GetSolution( void ) const {return m_iSolution;};

    /*! @brief set a transformation matrix.
     *
     * which will be applied to the solution vertices in order to calc. the deviation.
     * @param[in] matTrans ?
     * @return ?

     */
    void SetMatrix( const evMatrix& matTrans ) {m_matTrans = matTrans; m_bMatrix = true; } ;

    /*! @brief get the ray lengths of iSolution set by SetSolution
     *
     * @param[in] dRays ?
     * @return ?

     */
    bool GetRays( double dRays[3] );

    /*! @brief get the ray lengths specifying a solution explicitely.
     *
     * @param[in] dRays ?
     * @param[in] iSolution ?
     * @return ?

     */
    bool GetRays( double dRays[3], int iSolution );

    /*! @brief get a single ray length from the curr. solution.
     *
     * @param iRay 0 gets the ray lengths to point a, 1 to b and 2 to c.
     * @return ?

     */
    double GetRay(int iRay) const;

    /*! @brief get single ray length specifying a solution explicitely.
     *
     * @param[in] iRay ?
     * @param[in] iSolution ?
     * @return ?

     */
    double GetRay( int iRay, int iSolution ) const;

    /*! @brief get the world coordinates pointed to by ray
     *
     * @param[in] iRay ?
     * @return ?

     */
    evVertex3D GetWorldCoor( int iRay ) const;

    /*! @brief ?
     *
     * @param[in] iRay ?
     * @param[in] iSolution ?
     * @return ?

     */
    evVertex3D GetWorldCoor( int iRay, int iSolution ) const;

    /*! @brief set new world coordinates averaged by an external procedure
     *
     * @param iRay ?
     * @param v3dWorld ?
     * @return ?

     */
    bool SetWorldCoor( int iRay, const evVertex3D & v3dWorld );

    /*! @brief calculate the origin in world coordinates
     *
     */
    void CalculateOrigin( void );

    /*! @brief return the calculated origin in world coordinates
     *
     * @return ?

     */
    evVertex3D GetOrigin( void ) const;

    /*! @brief ?
     *
     * @param v3dOrigin ?
     * @return ?

     */
    bool SetOrigin( const evVertex3D & v3dOrigin );

    //! set a new origin in world coordinates
//      void SetOrigin(const evVertex3D& v3dOrigin) {m_v3dOrigin = v3dOrigin; m_bOrigin = true;};

    /*! @brief calculate the object rotations.
     *
     * @return ?

     */
    void CalculateRotations( void );

    /*! @brief return the number of available rotations.
     *
     * @return ?

     */
    int GetNrOfRotations();

    /*! @brief return the rotations specified by iRot.
     *
     * @param[in] iRot ?
     * @return ?

     */
    evVertex3D GetRotations(int iRot);

    /*! @brief ?
     *
     * @return ?

     */
    double GetSideDeviation( void ) const;

    /*! @brief get the deviation between the original vertices of the base and the vertices of the current solution transformed by matrix.
     *
     * @return ?

     */
    double GetDeviation( void ) const;

    /*! @brief ?
     *
     * @param matTrans ?
     * @return ?

     */
    double GetDeviation( const evMatrix & matTrans ) const;

    /*! @brief set the best matching solution index
     *
     */
    void SetBestMatch( void ) {m_iBestMatch = m_iSolution;};

    /*! @brief ?
     *
     * @param[in] iMatch ?
     */
    void SetBestMatch( int iMatch ) {m_iBestMatch = iMatch;};

    /*! @brief ?
     *
     * @param[in] matTrans ?
     */
    void FindBestMatch( const evMatrix& matTrans );

    /*! @brief tell evPyramid to use the best match for subsequent calculations
     *
     */
    void UseBestMatch( void ) {m_iSolution = m_iBestMatch;};

    /*! @brief ?
     *
     * @param[in] iMatch ?
     */
    void SetTempBestMatch( int iMatch ) {m_iTempBestMatch = iMatch;};

    /*! @brief ?
     *
     */
    void SetTempBestMatch( void ) {m_iTempBestMatch = m_iSolution;};

    /*! @brief ?
     *
     */
    void SetBestMatchFromTemp( void ) {m_iBestMatch = m_iTempBestMatch;};


    /*! @brief ?
     *
     * @param[in] dRay
     * @param[in] dRayBSign
     * @param[in] dRayCSign
     * @return ?

     */
    double GetSide( double dRay, double dRayBSign, double dRayCSign ) {
        double dRayB = GetRayUsingCosRule(dRay,m_dCosC,m_dC,dRayBSign);
        double dRayC = GetRayUsingCosRule(dRay,m_dCosB,m_dB,dRayCSign);
        return GetAFromRaysBC(dRayB, dRayC);
    } ;

    // the match criteria for the solution
    static const double MATCH_CRITERIA;


protected :

    double m_dTiltA;
    double m_dTiltB;
    double m_dTiltC;
    double m_dPanA;
    double m_dPanB;
    double m_dPanC;
    bool m_bAngles;

    evVertex3D m_v3dA;
    evVertex3D m_v3dB;
    evVertex3D m_v3dC;
    bool m_bVertices;


    double m_dA;
    double m_dB;
    double m_dC;
    bool m_bLengths;

    evMatrix m_matTrans;
    bool m_bMatrix;


    int m_nSolutions;
    int m_iBestMatch;
    int m_iTempBestMatch;
    int m_iSolution;
    evVertex3D m_v3dWorld[3][8];
    double m_dRayLen[3][8];
    double m_dSideDeviation[8];
    evVertex3D m_v3dOrigin[8];
    bool m_bOrigin;
    evVertex3D m_v3dRotations[4][8];
    int m_nRotations[3];

    double m_matRayA[16];
    double m_matRayB[16];
    double m_matRayC[16];
    double m_dCosA;
    double m_dCosB;
    double m_dCosC;

    double GetRayUsingCosRule(double dRayA, double dCos, double dA, double dSign) const
    {
            // a^2 = l1^2+l2^2-f*l1*l2  ... cosine rule
            double h = dCos*dCos*dRayA*dRayA-4.*dRayA*dRayA+4.*dA*dA;
            if (h < 0.) {
                    // this would be a complex solution
                    h = 0.;
            }
            return (dCos*dRayA+dSign*mysqrt(h))/2.;
    };

    // get side lengths a with ray b and and ray c
    double GetAFromRaysBC(double dRayB, double dRayC) const
    {
            double x1 = dRayB*m_matRayB[8];
            double y1 = dRayB*m_matRayB[9];
            double z1 = dRayB*m_matRayB[10];
            double x2 = dRayC*m_matRayC[8];
            double y2 = dRayC*m_matRayC[9];
            double z2 = dRayC*m_matRayC[10];
            double dx = x1 - x2;
            double dy = y1 - y2;
            double dz = z1 - z2;
            return mysqrt(dx*dx+dy*dy+dz*dz);
    };
    double GetBFromRaysAC(double dRayA, double dRayC) const
    {

            double x1 = dRayA*m_matRayA[8];
            double y1 = dRayA*m_matRayA[9];
            double z1 = dRayA*m_matRayA[10];
            double x2 = dRayC*m_matRayC[8];
            double y2 = dRayC*m_matRayC[9];
            double z2 = dRayC*m_matRayC[10];
            double dx = x1 - x2;
            double dy = y1 - y2;
            double dz = z1 - z2;
            return mysqrt(dx*dx+dy*dy+dz*dz);
    };
    double GetCFromRaysAB(double dRayA, double dRayB) const
    {

            double x1 = dRayB*m_matRayB[8];
            double y1 = dRayB*m_matRayB[9];
            double z1 = dRayB*m_matRayB[10];
            double x2 = dRayA*m_matRayA[8];
            double y2 = dRayA*m_matRayA[9];
            double z2 = dRayA*m_matRayA[10];
            double dx = x1 - x2;
            double dy = y1 - y2;
            double dz = z1 - z2;
            return mysqrt(dx*dx+dy*dy+dz*dz);
    };




    bool SolveInRange(double dRayAFrom, double dRayATo,
                             double dRayBSign, double dRayCSign,
                             double &dRayA, double &dRayB, double &dRayC /*, double &dSideDeviation*/ );

    void CalculateAllRotations();
private :

};


#endif

