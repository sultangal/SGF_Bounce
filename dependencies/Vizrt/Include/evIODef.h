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

#ifndef __EVIODEF_H__
#define __EVIODEF_H__



#ifdef _WIN32
    #include <windows.h>
    #include <Zmouse.h>
#else
    #include <X11/keysym.h>
    #include <X11/keysymdef.h>
#endif


/*! @brief keys 'A'-'Z' and '0'-'9'
 *
 * @todo documentation to be done.
 */
enum KEY_Codes
{
#ifdef _WIN32
    KEY_A = 0x41,   /*!< keycode for ascii a for ms windows */
#else
    KEY_A = 0x61,   /*!< keycode for ascii a for x windows/unix */
#endif
    /*! keycodes for ascii b-z follows
     */
    KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L,
    KEY_M, KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,

    /*! keycodes for numeric 0-9 follows
     */
    KEY_0 = 0x30, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9
};


// special keys

#ifdef _WIN32 //======= constants for ms windows systems =============>>
    /// navigation key labeled Home
    #define KEY_HOME                VK_HOME
    /// navigation key labeled End
    #define KEY_END                 VK_END
    /// navigation key labeled Page Up
    #define KEY_PAGEUP              VK_PRIOR
    /// navigation key labeled Page Down
    #define KEY_PAGEDN              VK_NEXT
    /// navigation key labeled Up
    #define KEY_UP                  VK_UP
    /// navigation key labeled Down
    #define KEY_DOWN                VK_DOWN
    /// navigation key labeled Left
    #define KEY_LEFT                VK_LEFT
    /// navigation key labeled Right
    #define KEY_RIGHT               VK_RIGHT
    /// key labeled Insert
    #define KEY_INSERT              VK_INSERT
    /// key labeled Delete
    #define KEY_DELETE              VK_DELETE
    /// key on the numpad labeled Delete
    #define KEY_NUM_DELETE          VK_NUM_DELETE
    /// key '5' on the numpad labeled Begin
    #define KEY_BEGIN               VK_CLEAR        // Num. 5
    /// key on the numpad labeled Multiply
    #define KEY_MULTIPLY            VK_MULTIPLY
    /// key on the numpad labeled Divide
    #define KEY_DIVIDE              VK_DIVIDE

    /// key labeled Esacpe
    #define KEY_ESCAPE              VK_ESCAPE
    /// Return key
    #define KEY_RETURN              VK_RETURN
    /// Enter key (located on the numpad)
    #define KEY_ENTER               VK_RETURN
    /// @todo documentation to be done.
    #define KEY_SEPARATOR           VK_SEPARATOR
    /// Space key
    #define KEY_SPACE               VK_SPACE
    /// key labeled Backspace
    #define KEY_BACKSPACE           VK_BACK

// modifier keys ...
    /// modifier key labeled Control
    #define KEY_CONTROL             VK_CONTROL
    /// modifier key labeled Menu
    #define KEY_MENU                VK_MENU
    /// modifier key labeled Alt
    #define KEY_ALT                 KEY_MENU
    /// modifier key labeled Shift
    #define KEY_SHIFT               VK_SHIFT

// function keys ...
    /// function key F1
    #define KEY_F1                  VK_F1
    /// function key F2
    #define KEY_F2                  VK_F2
    /// function key F3
    #define KEY_F3                  VK_F3
    /// function key F4
    #define KEY_F4                  VK_F4
    /// function key F5
    #define KEY_F5                  VK_F5
    /// function key F6
    #define KEY_F6                  VK_F6
    /// function key F7
    #define KEY_F7                  VK_F7
    /// function key F8
    #define KEY_F8                  VK_F8
    /// function key F9
    #define KEY_F9                  VK_F9
    /// function key F10
    #define KEY_F10                 VK_F10
    /// function key F11
    #define KEY_F11                 VK_F11
    /// function key F12
    #define KEY_F12                 VK_F12

    /// key labeled Print Screen
    #define KEY_PRINT_SCREEN        VK_PRINTSCREEN
    /// key labeled Scroll Lock
    #define KEY_SCROLL_LOCK         VK_SCROLL
    /// key labeled Pause
    #define KEY_PAUSE               VK_PAUSE

// number keys ...
    /// navigation key on the numpad labeled Insert
    #define NUMPAD_INSERT           VK_NUMPAD0
    /// navigation key on the numpad labeled End
    #define NUMPAD_END              VK_NUMPAD1
    /// navigation key on the numpad labeled Down
    #define NUMPAD_DOWN             VK_NUMPAD2
    /// navigation key on the numpad labeled Page Down
    #define NUMPAD_PGDN             VK_NUMPAD3
    /// navigation key on the numpad labeled Left
    #define NUMPAD_LEFT             VK_NUMPAD4
    /// key '5' on the numpad labeled Begin
    #define NUMPAD_BEGIN            VK_NUMPAD5
    /// navigation key on the numpad labeled Right
    #define NUMPAD_RIGHT            VK_NUMPAD6
    /// navigation key on the numpad labeled Home
    #define NUMPAD_HOME             VK_NUMPAD7
    /// navigation key on the numpad labeled Up
    #define NUMPAD_UP               VK_NUMPAD8
    /// navigation key on the numpad labeled Page Up
    #define NUMPAD_PGUP             VK_NUMPAD9

#else //============== constants for unix/X-windows systems =============>>

    /// navigation key labeled Home
    #define KEY_HOME            XK_Home
    /// navigation key labeled End
    #define KEY_END             XK_End
    /// navigation key labeled Page Up
    #define KEY_PAGEUP          XK_Prior
    /// navigation key labeled Page Down
    #define KEY_PAGEDN          XK_Next
    /// navigation key labeled Up
    #define KEY_UP              XK_Up
    /// navigation key labeled Down
    #define KEY_DOWN            XK_Down
    /// navigation key labeled Left
    #define KEY_LEFT            XK_Left
    /// navigation key labeled Right
    #define KEY_RIGHT           XK_Right
    /// key labeled Insert
    #define KEY_INSERT          XK_Insert
    /// key labeled Delete
    #define KEY_DELETE          XK_Delete
    /// key on the numpad labeled Delete
    #define KEY_NUM_DELETE      XK_KP_Delete
    /// key '5' on the numpad labeled Begin
    #define KEY_BEGIN           XK_Begin
    /// key on the numpad labeled Multiply
    #define KEY_MULTIPLY        XK_KP_Multiply
    /// key on the numpad labeled Divide
    #define KEY_DIVIDE          XK_KP_Divide

    /// key labeled Esacpe
    #define KEY_ESCAPE          XK_Escape
    /// Return key
    #define KEY_RETURN          XK_Return
    /// Enter key (located on the numpad)
    #define KEY_ENTER           XK_KP_Enter
    /// @todo documentation to be done.
    #define KEY_SEPARATOR       XK_KP_Separator
    /// Space key
    #define KEY_SPACE           XK_space
    /// key labeled Backspace
    #define KEY_BACKSPACE       XK_BackSpace

// modifier keys ...
    /// modifier key labeled Control
    #define KEY_CONTROL         XK_Control_L
    /// modifier key labeled Menu
    #define KEY_MENU            XK_Alt_L
    /// modifier key labeled Alt
    #define KEY_ALT             KEY_MENU
    /// modifier key labeled Shift
    #define KEY_SHIFT           XK_Shift_L

// function keys ...
    /// function key F1
    #define KEY_F1              XK_F1
    /// function key F2
    #define KEY_F2              XK_F2
    /// function key F3
    #define KEY_F3              XK_F3
    /// function key F4
    #define KEY_F4              XK_F4
    /// function key F5
    #define KEY_F5              XK_F5
    /// function key F6
    #define KEY_F6              XK_F6
    /// function key F7
    #define KEY_F7              XK_F7
    /// function key F8
    #define KEY_F8              XK_F8
    /// function key F9
    #define KEY_F9              XK_F9
    /// function key F10
    #define KEY_F10             XK_F10
    /// function key F11
    #define KEY_F11             XK_F11
    /// function key F12
    #define KEY_F12             XK_F12

    /// key labeled Print Screen
    #define KEY_PRINT_SCREEN    XK_Sys_Req
    /// key labeled Scroll Lock
    #define KEY_SCROLL_LOCK     XK_Scroll_Lock
    /// key labeled Pause
    #define KEY_PAUSE           XK_Pause

// number keys ...
    // navigation key on the numpad labeled Insert
    #define NUMPAD_INSERT       XK_KP_Insert
    /// navigation key on the numpad labeled End
    #define NUMPAD_END          XK_KP_End
    /// navigation key on the numpad labeled Down
    #define NUMPAD_DOWN         XK_KP_Down
    /// navigation key on the numpad labeled Page Down
    #define NUMPAD_PGDN         XK_KP_Next
    /// navigation key on the numpad labeled Left
    #define NUMPAD_LEFT         XK_KP_Left
    /// key '5' on the numpad labeled Begin
    #define NUMPAD_BEGIN        XK_KP_Begin
    /// navigation key on the numpad labeled Right
    #define NUMPAD_RIGHT        XK_KP_Right
    /// navigation key on the numpad labeled Home
    #define NUMPAD_HOME         XK_KP_Home
    /// navigation key on the numpad labeled Up
    #define NUMPAD_UP           XK_KP_Up
    /// navigation key on the numpad labeled Page Up
    #define NUMPAD_PGUP         XK_KP_Prior

#endif


// defines for events flags ...

#ifndef _WIN32
    /// left mouse button
    #define MK_LBUTTON              0x0001
    /// right - mouse -
    #define MK_RBUTTON              0x0002
    /// shift modifier
    #define MK_SHIFT                0x0004
    /// control modifier
    #define MK_CONTROL              0x0008
    /// middle mouse button
    #define MK_MBUTTON              0x0010

    /*! @brief ?
     * @todo documentation to be done.
     */
    struct tagPOINT
    {
        int x;
        int y;
    };
    typedef struct tagPOINT POINT;

    /*! @brief ?
     * @todo documentation to be done.
     */
    struct tagPOINTS
    {
        short int x;
        short int y;
    };
    typedef struct tagPOINTS POINTS;

    /*!
     * some windows message constants ...
     * (defined by ms-windows, we need them for irix aswell)
     */
    /// keyboard
    #define WM_KEYDOWN          KeyPress
    ///  keyboard
    #define WM_KEYUP            KeyRelease
    /// input focus
    #define WM_SETFOCUS         EnterNotify
    /// input focus
    #define WM_KILLFOCUS        LeaveNotify
    /// mouse move
    #define WM_MOUSEMOVE        MotionNotify

    /// mouse click events start value
    #define WM_MOUSEFIRST       0x0200
    /// left mouse button down
    #define WM_LBUTTONDOWN      0x0201
    /// left mouse button up
    #define WM_LBUTTONUP        0x0202
    /// left mouse button double click
    #define WM_LBUTTONDBLCLK    0x0203
    /// right mouse button down
    #define WM_RBUTTONDOWN      0x0204
    /// right mouse button up
    #define WM_RBUTTONUP        0x0205
    /// right mouse button double click
    #define WM_RBUTTONDBLCLK    0x0206
    /// middle mouse button down
    #define WM_MBUTTONDOWN      0x0207
    /// middle mouse button up
    #define WM_MBUTTONUP        0x0208
    /// middle mouse button double click
    #define WM_MBUTTONDBLCLK    0x0209
    /// mouse click events end value
    #define WM_MOUSELAST        0x020A

#endif



#ifndef WM_XBUTTONDOWN
/*! this should be defined in <winuser.h>, if not, you have not installed
 * the platform sdk!
 *      pragma message ("warning: you should install the latest platform sdk and make its include path the first to be searched!")
 */
    #define VK_XBUTTON1        0x05
    #define VK_XBUTTON2        0x06
    #define XBUTTON1           0x0001
    #define XBUTTON2           0x0002
    #define MK_XBUTTON1        0x0020
    #define MK_XBUTTON2        0x0040
    #define WM_XBUTTONDOWN     0x020B
    #define WM_XBUTTONUP       0x020C
    #define WM_XBUTTONDBLCLK   0x020D
    #define WM_NCXBUTTONDOWN   0x00AB
    #define WM_NCXBUTTONUP     0x00AC
    #define WM_NCXBUTTONDBLCLK 0x00AD

#endif


#ifndef MK_ALT
    /// menu key
    #define MK_ALT            0x20
#endif

#ifndef MAKEPOINTS
    #define MAKEPOINTS(l)       (*((POINTS*)&(l)))
#endif

#ifndef MAKELONG
    #define MAKELONG(a, b)      ((long)(((unsigned short)(a)) | ((unsigned long)((unsigned short)(b))) << 16))
    #define LOWORD(l)           ((unsigned short)(l))
    #define HIWORD(l)           ((unsigned short)(((unsigned long)(l) >> 16) & 0xFFFF))
#endif

#endif
