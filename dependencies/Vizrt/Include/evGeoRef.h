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

#ifndef __EV_GEOREF_H__
#define __EV_GEOREF_H__

#include "evPlugin_BASE.h"


class GEOREF : public BASE
{
public:
    int get_id();

    // Geographical (longitude, latitude,z) to position (x,y) conversion
    bool lonLat2xy(double longitude, double latitude, double height ,float& x, float& y, float& z);
    bool xy2LonLat(float x, float y, float z, double& longitude, double& latitude, double& height);

    // Normalized means that x,y are between [0,1] (i.e. for texture coordinates where image size is not important)
    // tx, ty, tz should be between [0,1]
    bool lonLat2xyNormalized(double longitude, double latitude, double height ,float& tx, float& ty, float& tz);
    bool xy2LonLatNormalized(float tx, float ty, float tz, double& longitude, double& latitude, double& height);

    // Model means "natural" values of the projection (i.e. without translating to raster=image space.. we might have no image at all)
    bool lonLat2xyModel(double longitude, double latitude, double height ,float& x, float& y, float& z);
    bool xy2LonLatModel(float x, float y, float z, double& longitude, double& latitude, double& height);

    // See EvGeoRefType above
    void get_dllName(char** dllName);
    void set_dllName(const char* dllName);

    bool getLonLatBBox(double& minLon, double& maxLon, double& minLat, double& maxLat);

    // Get parameters of various geoRefences
    void setParameterLong(const char* paramName, long val);
    void getParameterLong(const char* paramName, long& val);
    void setParameterFloat(const char* paramName, float val);
    void getParameterFloat(const char* paramName, float& val);
    void setParameterDouble(const char* paramName, double val);
    void getParameterDouble(const char* paramName, double& val);
    void setParameterString(const char* paramName, const char* str, int maxSize);
    void getParameterString(const char* paramName, const char* str, int maxSize);

    void readVGR(const char* fileName);

    long getChangeID(void);

    int copy_properties(GEOREF&);   // copy all properties from another georef
};

#endif // __EV_GEOREF_H__
