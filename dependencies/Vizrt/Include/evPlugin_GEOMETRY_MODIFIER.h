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

#if ! defined( EV_PLUGIN_GEOMETRY_MODIFIER_H )
#define EV_PLUGIN_GEOMETRY_MODIFIER_H

//=========================================================================
// GEOMETRY_MODIFIER OBJECT
//=========================================================================
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class GEOMETRY_MODIFIER
{
public:
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    GEOMETRY_MODIFIER( void ) { object = NULL; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void*& getObject( void ) { return object; }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void geoInit( void );

    /*! @brief ?
     *
     * @param[out] numVertices ?
     * @param[out] numMeshes ?
     * @param[out] hasNormals ?
     * @param[out] hasTexCoords ?
     * @param[out] hasColors ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetInfo( int& numVertices, int& numMeshes, bool& hasNormals, bool& hasTexCoords, bool& hasColors );

    /*! @brief ?
     *
     * @param[in] nmesh ?
     * @param meshPtr ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGotoMesh( int nmesh, float*& meshPtr );

    /*! @brief ?
     *
     * @param meshPtr ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoNextMesh( float*& meshPtr );

    /*! @brief ?
     *
     * @param meshPtr ?
     * @param meshType ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetMeshType( float * meshPtr, int& meshType );

    /*! @brief ?
     *
     * @param meshPtr ?
     * @param numVertices ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetNumMeshVertices( float* meshPtr, int& numVertices );

    /*! @brief ?
     *
     * @param meshPtr ?
     * @param[in] nvertex ?
     * @param vertexPtr ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGotoVertex(float* meshPtr, int nvertex, float*& vertexPtr);

    /*! @brief ?
     *
     * @param meshPtr ?
     * @param vertexPtr ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoNextVertex( float* meshPtr, float*& vertexPtr );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param x ?
     * @param y ?
     * @param z ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetVertex( float* vertexPtr, float& x, float& y, float& z );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] numVertices ?
     * @param vertices ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetVertices( float* vertexPtr, int numVertices, float* vertices );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param x ?
     * @param y ?
     * @param z ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoSetVertex( float* vertexPtr, float x, float y, float z );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] numVertices ?
     * @param vertices ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoSetVertices( float* vertexPtr, int numVertices, float* vertices );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param x ?
     * @param y ?
     * @param z ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetNormal( float* vertexPtr, float& x, float& y, float& z );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] numNormals ?
     * @param normals ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetNormals( float* vertexPtr, int numNormals, float* normals );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoSetNormal( float* vertexPtr, float x, float y, float z );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] numNormals ?
     * @param normals ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoSetNormals(float* vertexPtr, int numNormals, float* normals);

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param s ?
     * @param t ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetTexCoord(float* vertexPtr, float& s, float& t);
    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param numTexCoords ?
     * @param texCoords?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetTexCoords(float* vertexPtr, int numTexCoords, float* texCoords);
    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] s ?
     * @param[in] t ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoSetTexCoord(float* vertexPtr, float s, float t);
    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] numTexCoords ?
     * @param texCoords ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoSetTexCoords(float* vertexPtr, int numTexCoords, float* texCoords);

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param color ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetColor( float* vertexPtr, unsigned long int& color );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] numColors ?
     * @param colors ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoGetColors(float* vertexPtr, int numColors, unsigned long int * colors);

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] color ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoSetColor( float* vertexPtr, unsigned long int color );

    /*! @brief ?
     *
     * @param vertexPtr ?
     * @param[in] numColors ?
     * @param colors ?
     * @return ?

     * @todo documentation to be done.
     */
    void geoSetColors( float* vertexPtr, int numColors, unsigned long int * colors );


protected:
    void * object;
};


#endif // EV_PLUGIN_GEOMETRY_MODIFIER_H
