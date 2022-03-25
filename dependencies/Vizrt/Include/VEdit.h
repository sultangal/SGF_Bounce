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

#if !defined(AFX_VEdit_H__B8661310_F651_4172_ADB7_3FBF8A49E59F__INCLUDED_)
#define AFX_VEdit_H__B8661310_F651_4172_ADB7_3FBF8A49E59F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VEdit.h : header file
//
#include <afxctl.h>         // MFC support for ActiveX Controls
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>       // MFC support for Internet Explorer 4 Comon Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>         // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

extern void AFXAPI DDX_VizFloat(CDataExchange* pDX, int nIDC, float& value);
/////////////////////////////////////////////////////////////////////////////
// CVEdit window

class CVEdit : public CEdit
{
// Construction
public:
    CVEdit();

// Attributes
public:

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CVEdit)
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CVEdit();
    void SetResolution(float fResolution) {m_fResolution = fResolution;};
    void SetRange(float fMin, float fMax) {m_fMin = fMin; m_fMax = fMax;};
    enum EditType {EDIT_INT, EDIT_FLOAT};
    void SetEditType(EditType which) {m_EditType = which;};
    bool IsChanging() {return m_bButtonDown;};

    // Generated message map functions
protected:
    //{{AFX_MSG(CVEdit)
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    //}}AFX_MSG
    CPoint m_ptLast;
    bool m_bButtonDown;
    bool m_bValueChanged;
    float m_fValue;
    float m_fResolution;
    float m_fMin;
    float m_fMax;
    EditType m_EditType;

    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VEdit_H__B8661310_F651_4172_ADB7_3FBF8A49E59F__INCLUDED_)
