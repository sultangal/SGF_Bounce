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

#if !defined(AFX_VWheel_H__F033D211_D76E_11D5_92B8_080069133B30__INCLUDED_)
#define AFX_VWheel_H__F033D211_D76E_11D5_92B8_080069133B30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
// VWheel.h : header file
//
#endif // _MSC_VER > 1000
#include <afxctl.h>         // MFC support for ActiveX Controls
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>       // MFC support for Internet Explorer 4 Comon Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>         // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// CVWheel window

class CVWheel : public CSliderCtrl
{
// Construction
public:
    CVWheel();

// Attributes
public:
    float m_fPhiStep;
    float m_fPhiOffset;
    float m_fPhiOffsetStep;
    float m_fScale;
    int m_iPixStep;
    CPoint m_ptLast;
    CRect m_rcBorder;
    CRect m_rcWheel;

// Operations
public:
    void PostMessageToParent(const int nTBCode) const;
    void SetResolution(int iResolution) {m_iResolution = iResolution;};
    void SetCheck(int iCheck) {m_iCheck = iCheck; Invalidate(FALSE);};

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CVWheel)
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CVWheel();

    // Generated message map functions
protected:
    //{{AFX_MSG(CVWheel)
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    //}}AFX_MSG
    int m_iResolution;
    int m_iCheck;
    bool m_bDraging;
    bool m_bVertical;
    CDC memDC;
    CBitmap bitmap;

    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VWheel_H__F033D211_D76E_11D5_92B8_080069133B30__INCLUDED_)
