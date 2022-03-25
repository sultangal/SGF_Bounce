/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2014 Vizrt Austria GmbH                                            *
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

#if ! defined( EV_PLUGIN_VizSDKCompat_H )
#define EV_PLUGIN_VizSDKCompat_H


#if ! defined( EV_REGISTER_PARAMETER_V_2 )

#define evRegisterParameterFloatEx(pszName, pszLabel,  fDefault,  fMin,  fMax,  offset,  total_size) \
        evRegisterParameterFloat(pszName, pszLabel,  fDefault,  fMin,  fMax)

#define evRegisterParameterSliderFloatEx(pszName, pszLabel,  fDefault,  fMin,  fMax,  iWidth,  offset,  total_size) \
        evRegisterParameterSliderFloat(pszName, pszLabel,  fDefault,  fMin,  fMax,  iWidth)

#define evRegisterParameterIntEx(pszName, pszLabel,  iDefault,  iMin,  iMax,  offset,  total_size) \
        evRegisterParameterInt(pszName, pszLabel,  iDefault,  iMin,  iMax)

#define evRegisterParameterSliderIntEx(pszName, pszLabel,  iDefault,  iMin,  iMax,  iWidth,  offset,  total_size) \
        evRegisterParameterSliderInt(pszName, pszLabel,  iDefault,  iMin,  iMax,  iWidth)

#define evRegisterParameterBoolEx(pszName, pszLabel, bDefault,  offset,  total_size) \
        evRegisterParameterBool(pszName, pszLabel, bDefault)

#define evRegisterParameterColorEx(pszName, pszLabel, lDefault,  offset,  total_size) \
        evRegisterParameterColor(pszName, pszLabel, lDefault)

#define evRegisterParameterRadioEx(pszName, pszLabel,  iDefault, ppszLabels,  offset,  total_size) \
        evRegisterParameterRadio(pszName, pszLabel,  iDefault, ppszLabels)

#define evRegisterParameterStringEx(pszName, pszLabel, pszDefault,  iWidgetLen,  iMaxLen, pszCheck,  offset,  total_size) \
        evRegisterParameterString(pszName, pszLabel, pszDefault,  iWidgetLen,  iMaxLen, pszCheck)

#define evRegisterParameterLabelEx(pszName, pszLabel, pszDefault,  iWidgetLen,  iWidgetHeight,  offset,  total_size) \
        evRegisterParameterLabel(pszName, pszLabel, pszDefault,  iWidgetLen,  iWidgetHeight)

#define evRegisterParameterFileSelectorEx(pszName, pszLabel, pszPathDefault, pszFile, pszFilter,  offset,  total_size) \
        evRegisterParameterFileSelector(pszName, pszLabel, pszPathDefault, pszFile, pszFilter)

#define evRegisterParameterDirSelectorEx(pszName, pszLabel, pszPathDefault,  offset,  total_size) \
        evRegisterParameterDirSelector(pszName, pszLabel, pszPathDefault)

#define evRegisterParameterTextEx(pszName, pszDefault,  iWidth,  iHeight,  offset,  total_size) \
        evRegisterParameterText(pszName, pszDefault,  iWidth,  iHeight)

#define evRegisterParameterListEx(pszName, pszLabel,  iDefault, ppszEntries,  iWidgetLen,  iHeight,  offset,  total_size) \
        evRegisterParameterList(pszName, pszLabel,  iDefault, ppszEntries,  iWidgetLen,  iHeight)

#define evRegisterParameterDropDownEx(pszName, pszLabel,  iDefault, ppszEntries,  iWidth,  iHeight,  offset,  total_size) \
        evRegisterParameterDropDown(pszName, pszLabel,  iDefault, ppszEntries,  iWidth,  iHeight)

#define evRegisterParameterImageEx2(pszName, pszLabel, pszDefaultImage, offset, total_size) \
        evRegisterParameterImage(pszName, pszLabel, pszDefaultImage)

#define evRegisterParameterImageEx3(pszName, pszLabel, pszDefaultImage, bPosActive, bRotActive, bSclActive, offset, total_size, fPosXDefault, fPosXMin, fPosXMax, fPosYDefault, fPosYMin, fPosYMax, fRotXDefault, fRotXMin, fRotXMax, fRotYDefault, fRotYMin, fRotYMax, fRotZDefault, fRotZMin, fRotZMax, fSclXDefault, fSclXMin, fSclXMax, fSclYDefault, fSclYMin, fSclYMax) \
        evRegisterParameterImageEx(pszName, pszLabel, pszDefaultImage, bPosActive, bRotActive, bSclActive, fPosXDefault, fPosXMin, fPosXMax, fPosYDefault, fPosYMin, fPosYMax, fRotXDefault, fRotXMin, fRotXMax, fRotYDefault, fRotYMin, fRotYMax, fRotZDefault, fRotZMin, fRotZMax, fSclXDefault, fSclXMin, fSclXMax, fSclYDefault, fSclYMin, fSclYMax)

#define evRegisterParameterFontEx(pszName, pszLabel, pszDefault,  offset,  total_size) \
        evRegisterParameterFont(pszName, pszLabel, pszDefault)

#define evRegisterParameterHListEx(pszName, pszLabel,  iDefault, ppszEntries, chSeparator,  iWidth,  iHeight,  offset,  total_size) \
        evRegisterParameterHList(pszName, pszLabel,  iDefault, ppszEntries, chSeparator,  iWidth,  iHeight)

#define evRegisterParameterContainerEx(pszName, pszLabel, pszDefault,  offset,  total_size) \
        evRegisterParameterContainer(pszName, pszLabel, pszDefault)

#define evRegisterParameterDataEx(name,  offset,  total_size) \
        evRegisterParameterData(name)

#define evRegisterUserData32Ex( align_requirement,  size,  offset,  total_size) \
        evRegisterUserData(size)

#endif // #if ! defined( EV_REGISTER_PARAMETER_V_2 )


#endif // EV_PLUGIN_VizSDKCompat_H
