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


#ifndef __EV_GEOM_H__
#define __EV_GEOM_H__



//#ifndef __EV_COMMON_H__
//    /* evCommon.h must be included first ! */
//    #include "evCommon.h"
//#endif
#include "evPlugin_PLUGINFUNC.h"
#include "evPlugin_PLUGINEXTERN.h"


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/// geometry type for evNewGeom
#define EV_TRIANGLES        1
/// geometry type for evNewGeom
#define EV_TRIANGLE_MESH    2
/// geometry type for evNewGeom
#define EV_SIMPLE_POLYGON   3
/// geometry type for evNewGeom
#define EV_COMPLEX_POLYGON  4

/// geometry type for evNewMesh
#define EV_TRIANGLE_STRIP   1
/// geometry type for evNewMesh
#define EV_TRIANGLE_FAN     2

#ifdef __cplusplus
extern "C" {
#endif


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief creates a new geometry object.
 *
 * evNewGeom creates a new geometry object.
 * @param[in] pszName the name of the geometry
 * @param[in] iType face type as follows:
              \arg \c EV_TRIANGLES each face is a triangle (good performace during
                                   animation and drawing); call the evVertex functions
                                   to specify the vertices of the triangles
              \arg \c EV_TRIANGLE_MESH each face is a triangle strip/fan (highest performance during
                                       animation and drawing); call evNewMesh, followed by calls to the
                                       evVertex functions, to define the individual triangle strips/fans
              \arg \c EV_SIMPLE_POLYGON each face is a convex polygon (acceptable performance,
                                        perfect for vertex colors)
              \arg \c EV_COMPLEX_POLYGON each face is a complex polygon; very complex geometries
                                         possible (good drawing performance, significant calculation
                                         effort during build-up, therefore slow if animated);
                                         call evNewPolygon, followed by calls to the evVertex functions,
                                         to define the individual polygons
 * @param[in] bHasNormals each vertex has its own normal
 * @param[in] bHasTxCoord each vertex has its own texture coordinate
 * @param[in] bHasColors each vertex has its own color (use with care, slow)
 * @return  true if the creation was successful, false if not.
 *
 * \warning Within an object, all faces and vertices have the same type. There is no
 *          possibility to change the face or vertex type within the same object
 *          (this restriction is related to performance and memory fragmentation issues).
 */
VIZENGINE_API bool
evNewGeom( const char *pszName, int iType, bool bHasNormals, bool bHasTxCoord, bool bHasColors );


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief creates a new extended geometry object.
 *
 * evNewGeomX creates a new extended geometry object.
 * @param[in] pszName the name of the geometry
 * @param[in] iType face type as follows:
              \arg \c EV_TRIANGLES each face is a triangle (good performace during
                                   animation and drawing); call the evVertex functions
                                   to specify the vertices of the triangles
              \arg \c EV_TRIANGLE_MESH each face is a triangle strip/fan (highest performance during
                                       animation and drawing); call evNewMesh, followed by calls to the
                                       evVertex functions, to define the individual triangle strips/fans
              \arg \c EV_SIMPLE_POLYGON each face is a convex polygon (acceptable performance,
                                        perfect for vertex colors)
              \arg \c EV_COMPLEX_POLYGON each face is a complex polygon; very complex geometries
                                         possible (good drawing performance, significant calculation
                                         effort during build-up, therefore slow if animated);
                                         call evNewPolygon, followed by calls to the evVertex functions,
                                         to define the individual polygons
 * @param[in] bHasNormals each vertex has its own normal
 * @param[in] bHasTxCoord each vertex has its own texture coordinate
 * @param[in] bHasColors each vertex has its own color (use with care, slow)
 * @param[in] bHasTangents each vertex has its own tangent (viz also calculates the corresponding binormal)
              Shader attribute access via: vizTangent and vizBinormal (don't forget to set shader requirements)
 * @return  true if the creation was successful, false if not.
 *
 * \warning Within an object, all faces and vertices have the same type. There is no
 *          possibility to change the face or vertex type within the same object
 *          (this restriction is related to performance and memory fragmentation issues).
 */
VIZENGINE_API bool
evNewGeomX( const char *pszName, int iType, bool bHasNormals, bool bHasTxCoord, bool bHasColors, bool bHasTangents );


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ends a geometry object.
 *
 * evEndGeom ends the definition of a geometry object created with
 * evNewGeom. It performs necessary optimizations and prepares the
 * geometry for rendering.
 * @return  true if the function was successful, false if not.
 */
VIZENGINE_API bool
evEndGeom( const evVertex3D* bbox_bll = NULL, const evVertex3D* bbox_fur = NULL);


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ends a geometry object.
 *
 * evEndGeomBB ends the definition of a geometry object created with
 * evNewGeom. It performs necessary optimizations and prepares the
 * geometry for rendering. In addition, it lets you specify the
 * geometry's bounding box, which is more efficient than letting
 * the engine do the work.
 * @return  true if the function was successful, false if not.
 */
VIZENGINE_API bool
evEndGeomBB(const evVertex3D* bbox_bll, const evVertex3D* bbox_fur);


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief creates a new triangle strip or mesh.
 *
 * evNewGeom creates a new triangle strip or mesh.
 * It defines a connected group of triangles, where N-2 triangles
 * are drawn.
 * @param[in] iType face type as follows:
              \arg \c EV_TRIANGLE_STRIP For odd n, vertices n, n+1, and n+2 define triangle n.
                                        For even n, vertices n+1, n, and n+2 define triangle n.
              \arg \c EV_TRIANGLE_FAN Vertices 1, n+1, and n+2 define triangle n.
 * @return The function returns true if the creation was successful, false if not.
 *
 * \warning use only if face type is EV_TRIANGLE_MESH, otherwise it will fail.
 */
VIZENGINE_API bool
evNewMesh( int iType );


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief creates a new polygon.
 *
 * evNewPolygon creates a new polygon. If face type is EV_SIMPLE_POLYGON
 * each polygon is independent and must be convex. If face type is
 * EV_COMPLEX_POLYGON, a polygon located inside another polygon defines
 * a hole. Additionally each polygon may be nonconvex.
 * @return The function returns true if the creation was successful, false if not.
 *
 * \warning use only if face type is EV_SIMPLE_POLYGON or
 *          EV_COMPLEX_POLYGON, otherwise it will fail.
 */
VIZENGINE_API bool
evNewPolygon( void );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief creates a new outline for an object.
 *
 * evNewOutline creates a new outline for an object.
 *
 * @return The function returns true if the creation was successful, false if not.
 */
VIZENGINE_API bool
evNewOutline( void );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief creates a new vertex.
 *
 * evVertex creates a new vertex.
 * @param[in] pfVertex points to an array of three floating point numbers
 *                   defining the x, y and z coordinate of the vertex.
 * @return ??
 * @todo documentation to be done.
 */
VIZENGINE_API int
evVertexP( float* pfVertex );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief creates a new vertex.
 *
 * evVertex creates a new vertex.
 * @param[in] x defining the x coordinate of the vertex.
 * @param[in] y defining the y coordinate of the vertex.
 * @param[in] z defining the z coordinate of the vertex.
 * @return ??
 * @todo documentation to be done.
 */
VIZENGINE_API int
evVertex( float x, float y, float z );

/* rne BEGIN */
VIZENGINE_API
void evVertexPointer(float *vertex,int num);
VIZENGINE_API
float* evGetVertexPointer(int num);
/* rne END */

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief defines the current normal.
 *
 * evNormal defines the current normal.
 * @param[in] pfNormal points to an array of three floating point numbers
 *                   defining the x, y and z coordinate of the normal.
 * @return ??
 * @warning must be called before the corresponding evVertexIndex. If not called before
 *          evVertexIndex, the current normal is used for the defined vertex.
 *          If the object can not hold normals, it is ignored.
 * @todo documentation to be done.
 */
VIZENGINE_API void
evNormalP( float* pfNormal );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief defines the current normal.
 *
 * evNormal defines the current normal.
 * @param[in] x defining the x coordinate of the normal.
 * @param[in] y defining the y coordinate of the normal.
 * @param[in] z defining the z coordinate of the normal.
 * @return ??
 * @warning must be called before the corresponding evVertexIndex. If not called before
 *          evVertexIndex, the current normal is used for the defined vertex.
 *          If the object can not hold normals, it is ignored.
 * @todo documentation to be done.
 */
VIZENGINE_API void
evNormal( float x, float y, float z );


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief defines the current tangent.
 *
 * evTangent defines the current tangent. Shader attribute access via: vizTangent
 * (corresponding binormal attribute: vizBinormal)
 * @param[in] pfTangent points to an array of three floating point numbers
 *                   defining the x, y and z coordinate of the tangent.
 * @return ??
 * @warning must be called before the corresponding evVertexIndex. If not called before
 *          evVertexIndex, the current tangent is used for the defined vertex.
 *          If the object can not hold tangents, it is ignored.
 * @todo documentation to be done.
 */
VIZENGINE_API void
evTangentP( float* pfTangent );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief defines the current tangent.
 *
 * evTangent defines the current tangent. Shader attribute access via: vizTangent
 * (corresponding binormal attribute: vizBinormal)
 * @param[in] x defining the x coordinate of the tangent.
 * @param[in] y defining the y coordinate of the tangent.
 * @param[in] z defining the z coordinate of the tangent.
 * @return ??
 * @warning must be called before the corresponding evVertexIndex. If not called before
 *          evVertexIndex, the current tangent is used for the defined vertex.
 *          If the object can not hold tangents, it is ignored.
 * @todo documentation to be done.
 */
VIZENGINE_API void
evTangent( float x, float y, float z );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief defines the current texture coordinate.
 *
 * evTexCoord defines the current texture coordinate.
 * @param[in] pfTxCoord points to an array of two floating point numbers
 *                      defining the s and t value of the texture coordinate.
 * @warning must be called before the corresponding evVertexIndex.
 *          If not called before evVertexIndex, the current coordinate
 *          is used for the defined vertex
 *          If the object can not hold texture vertices, it is ignored.
 */
VIZENGINE_API void
evTexCoordP( float * pfTxCoord );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief defines the current texture coordinate.
 *
 * evTexCoord defines the current texture coordinate.
 * @param[in] x defining the x coordinate of the texture.
 * @param[in] y defining the y coordinate of the texture.
 * @warning must be called before the corresponding evVertexIndex.
 *          If not called before evVertexIndex, the current coordinate
 *          is used for the defined vertex
 *          If the object can not hold texture vertices, it is ignored.
 */
VIZENGINE_API void
evTexCoord( float x, float y );



// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief defines the current color.
 *
 * evColor defines the current color.
 * @param[in] ulColor unsigned long defining the RGBA value of the color
 * @warning must be called before the corresponding evVertexIndex.
 *          If not called before evVertexIndex, the current color
 *          is used for the defined vertex
 *          If the object can not hold vertex colors, it is ignored.
 */
VIZENGINE_API void
evColor( unsigned long ulColor );



#ifdef __cplusplus
}
#endif

#endif // __EV_GEOM_H__
