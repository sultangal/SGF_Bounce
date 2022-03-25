/*! @file
 * @brief this file is part of the plugin library.
 *
 * @todo this file needs documentation.
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

#ifndef __CVgeomData_h__
#define __CVgeomData_h__


#include "evPlugin_vizError.h"

#include <cstdlib>

class EV_SUBGEOM ;


/*! @brief ?
 *
 * @todo documentation to be done.
 */
struct CVgeomVertex
{
    float   x;
    float   y;
    float   z;
};

/*! @brief ?
 *
 * @todo documentation to be done.
 */
struct CVgeomVertexData
{
    CVgeomVertex v ;
    CVgeomVertex n ;
    CVgeomVertex t ;
    unsigned long c ;
};

/*! @brief ?
 *
 * @todo documentation to be done.
 */
struct CVgeomMesh
{
    int no_vertices ;
    int meshtype ;
};

/*! @brief ?
 *
 * @todo documentation to be done.
 * @todo check malloc and free usage here. get rid and use new[]/delete[] instead?
 */
class CVgeomData
{
public:
    /*! @brief ?
     *
     *
     * @todo documentation to be done.
     */
    CVgeomData()
    {
        m_bHasNormals = m_bHasTex = m_bHasColors = false ;
        m_iNofVertices = m_iNofMesh = 0 ;
        m_GeomMesh = NULL ;
        m_geomVertexData = NULL ;
        m_verticesAlloc = m_meshAlloc = 0 ;
    }

    /*! @brief ?
     *
     *
     * @todo documentation to be done.
     */
    ~CVgeomData()
    {
        m_bHasNormals = m_bHasTex = m_bHasColors = false ;
        m_iNofVertices = m_iNofMesh = 0 ;
        free(m_GeomMesh ) ;
        free(m_geomVertexData) ;
        m_verticesAlloc = m_meshAlloc = 0 ;
    }

    /*! @brief ?
     *
     * @param geom geometry
     * @return ?

     *
     * @todo documentation to be done.
     */
    bool buildVertexData( EV_SUBGEOM * geom );

    /*! @brief ?
     *
     * @param geom geometry
     *
     * @todo documentation to be done.
     */
    void rebuildGeomVertexData( EV_SUBGEOM * geom );

    /*! @brief ?
     *
     * @param[in] size sizeof geometry
     *
     * @todo documentation to be done.
     */
    void allocGeomVertexData( int size )
    {
        if(!m_geomVertexData)
        {
            (m_geomVertexData = (CVgeomVertexData* ) calloc(size,sizeof(CVgeomVertexData )));
            if (!m_geomVertexData)
                    ErrorExit(vizError::noMemory);

            m_verticesAlloc = size;
        }
        else
        {
            if(size > m_verticesAlloc )
            {
                (m_geomVertexData = (CVgeomVertexData* ) realloc(m_geomVertexData, size  * sizeof(CVgeomVertexData)));
                if (!m_geomVertexData)
                        ErrorExit(vizError::noMemory);

                m_verticesAlloc = size ;
            }
        }
    }

    /*! @brief ?
     *
     * @param[in] size of geometry
     *
     * @todo documentation to be done.
     */
    void allocMesh( int size )
    {
        if(!m_GeomMesh)
        {
            (m_GeomMesh = (CVgeomMesh* ) calloc(size,sizeof(CVgeomMesh )));
            if (!m_GeomMesh)
                    ErrorExit(vizError::noMemory);

            m_meshAlloc = size;
        }
        else
        {
            if(size > m_meshAlloc )
            {
                (m_GeomMesh = (CVgeomMesh* ) realloc( m_GeomMesh, size  * sizeof( CVgeomMesh )));
                if (!m_GeomMesh)
                        ErrorExit(vizError::noMemory);

                m_meshAlloc = size ;
            }
        }
    }

    /*! @brief ?
     *
     * @param[in] source assignment from that parameter
     * @return ?

     *
     * @todo documentation to be done.
     */
    CVgeomData& operator=( const CVgeomData * source )
    {
        if( source == NULL )
        {
            m_iNofVertices = m_iNofMesh = 0 ;
            return *this;
        }
        if( source->m_verticesAlloc > m_verticesAlloc )
        {
            allocGeomVertexData( source->m_verticesAlloc );
        }
        if( source->m_meshAlloc > m_meshAlloc )
        {
            allocMesh( source->m_meshAlloc );
        }
        m_bHasNormals   = source->m_bHasNormals;
        m_bHasTex       = source->m_bHasTex ;
        m_bHasColors    = source->m_bHasColors ;
        m_iNofVertices  = source->m_iNofVertices ;
        m_iNofMesh      = source->m_iNofMesh ;
        int i;
        for( i = 0 ; i <  m_iNofMesh ; i++ )
        {
            m_GeomMesh[i] =  source->m_GeomMesh[i] ;
        }
        for( i = 0 ; i < m_iNofVertices; i++ )
        {
            m_geomVertexData[i] =  source->m_geomVertexData[i] ;
        }
        for( i = 0 ; i < 3 ; i ++ )
        {
            m_fBottomLeftBack[i] = source->m_fBottomLeftBack[i] ;
            m_fTopRightFront[i] =  source->m_fTopRightFront[i] ;
        }
        return *this;
    }

    /*! @brief ?
     *
     * @return ?

     *
     * @todo documentation to be done.
     */
    float getBottomLeftBackX( void ){ return m_fBottomLeftBack[0]; }

    /*! @brief ?
     *
     * @return ?

     *
     * @todo documentation to be done.
     */
    float getBottomLeftBackY( void ){ return m_fBottomLeftBack[1]; }

    /*! @brief ?
     *
     * @return ?

     *
     * @todo documentation to be done.
     */
    float getBottomLeftBackZ( void ){ return m_fBottomLeftBack[2]; }

    /*! @brief ?
     *
     * @return ?

     *
     * @todo documentation to be done.
     */
    float getTopRightFrontX( void ){ return m_fTopRightFront[0]; }

    /*! @brief ?
     *
     * @return ?

     *
     * @todo documentation to be done.
     */
    float getTopRightFrontY( void ){ return m_fTopRightFront[1]; }

    /*! @brief ?
     *
     * @return ?

     *
     * @todo documentation to be done.
     */
    float getTopRightFrontZ( void ){ return m_fTopRightFront[2]; }

    /*! @brief ?
     *
     * @return ?

     *
     * @todo documentation to be done.
     */
    const float *getBottomLeftBack( void ){ return m_fBottomLeftBack; }

    /*! @brief ?
     *
     * @return ?

     *
     * @todo documentation to be done.
     */
    const float *getTopRightFront( void ){ return m_fTopRightFront; }

    ///
    CVgeomMesh * m_GeomMesh ;
    ///
    CVgeomVertexData * m_geomVertexData ;
    ///
    bool m_bHasNormals ;
    ///
    bool m_bHasTex ;
    ///
    bool m_bHasColors ;
    ///
    bool m_bHasTangents ;
    ///
    int m_iNofVertices ;
    ///
    int m_iNofMesh ;

private:
    int m_verticesAlloc;
    int m_meshAlloc;
    float m_fBottomLeftBack[3];
    float m_fTopRightFront[3];
};

#endif
