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

#if ! defined( EV_PLUGIN_TEXT_CONTROL_H )
#define EV_PLUGIN_TEXT_CONTROL_H

#include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CVgeomData;

//////////////////////////////////
// CV_TEXT_CONTROL
//////////////////////////////////

/*!
 * CV_TEXT_CONTROL provides two modes: global and per character.
 * Most functions return a value depending on the currently set mode.
 *
 * To use the global mode
 *     CV_TEXT_CONTROL tc;
 *     tc.setGlobalMode(true);
 *     float kerning = tc.getKerning();
 * The per character mode can be set by
 *     CV_TEXT_CONTROL tc;
 *     tc.setGlobalMode(false); // access just one character
 *     tc.setCharIndex(charIndex);
 *     float kerning = tc.getKerning();
 *
 * After initialization, per character mode is set with an invalid character value,
 * which means that the mode must be explicitly set to use the plugin.
 */
class CV_TEXT_CONTROL  : public BASE
{
public:
    friend class GEOMETRY;

    /*! @brief data type for store mapping between characters and glyphs
     *         that are not the same order in Complex Script Handling.
     */
    struct cluster
    {
        int firstChar;
        int lastChar;
        int firstGlyph;
        int lastGlyph;
        bool isLineBreak;
        bool isRTL;
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void local( void );

    /*! @brief check this text control is valid
     *
     * @return true if this is a text geometry (GEOM_TEXT)
     */
    bool valid( void ) const;

    /*! @brief get text of geometry
     *
     * @param[in] geom
     * @return ?

     * @todo documentation to be done.
     */
    CV_TEXT_CONTROL& operator=( GEOMETRY & geom );

    /*! @brief get text of container
     *
     * @param[in] cont
     * @return ?

     * @todo documentation to be done.
     */
    CV_TEXT_CONTROL& operator=( CONTAINER & cont );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    CV_TEXT_CONTROL();
    ~CV_TEXT_CONTROL();

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum
    {
        CONTROL_MODE_NONE,      /*!<  */
        CONTROL_MODE_ABSOLUTE,  /*!<  */
        CONTROL_MODE_RELATIVE   /*!<  */
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum
    {
        CONTROL_COLOR_NONE,                 /*!<  */
        CONTROL_COLOR_ABSOLUTE,             /*!<  */
        CONTROL_COLOR_RELATIVE ,            /*!<  */
        CONTROL_COLOR_ABSOLUTE_USE_ALPHA,   /*!<  */
        CONTROL_COLOR_RELATIVE_USE_ALPHA ,  /*!<  */
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum
    {
        CENTER_MODE_NONE=0,     /*!<  */
        CENTER_MODE_ABSOLUTE,   /*!<  */
        CENTER_MODE_RELATIVE,   /*!<  */

        CENTER_MODE_NW,         /*!<  */
        CENTER_MODE_N,          /*!<  */
        CENTER_MODE_NE,         /*!<  */

        CENTER_MODE_BW,         /*!< the baseline */
        CENTER_MODE_B,          /*!< the baseline */
        CENTER_MODE_BE,         /*!< the baseline */

        CENTER_MODE_W,          /*!<  */
        CENTER_MODE_C,          /*!<  */
        CENTER_MODE_E,          /*!<  */

        CENTER_MODE_SW,         /*!<  */
        CENTER_MODE_S,          /*!<  */
        CENTER_MODE_SE          /*!<  */
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
   enum  textOrientation
    {
        ORIENTATION_LEFT                = 1,    /*!<  */
        ORIENTATION_RIGHT               = 2,    /*!<  */
        ORIENTATION_CENTER              = 3,    /*!<  */
        ORIENTATION_CHAR                = 7,    /*!<  */
        ORIENTATION_JUSTIFIED           = 8,    /*!<  */
        ORIENTATION_SCALE_JUSTIFIED     = 9     /*!<  */
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum textVerticalOrientation
    {
        ORIENTATION_VERTICAL_CENTER     = 3,    /*!<  */
        ORIENTATION_VERTICAL_TOP        = 4,    /*!<  */
        ORIENTATION_VERTICAL_BOTTOM     = 5,    /*!<  */
        ORIENTATION_VERTICAL_FIRST_LINE = 6     /*!<  */
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum  textDirection
    {
        LEFT_TO_RIGHT,          /*!<  */
        RIGHT_TO_LEFT,          /*!<  */
        TOP_TO_BOTTOM,          /*!<  */
        BOTTOM_TO_TOP           /*!<  */
    };

    /*! @deprecated This enum is deprecated. Use textType instead.
     */
    enum  textStyle
    {
        STYLE_GEOMETRY = 0,     /*!< This enum value is deprecated. Use TYPE_GEOMETRY instead. */
        STYLE_TEXTURE           /*!< This enum value is deprecated. Use TYPE_TEXTURE instead. */
    };

    /*! @brief ?
    *
    * @todo documentation to be done.
    */
    enum  textType
    {
        TYPE_GEOMETRY = 0,     /*!<  */
        TYPE_TEXTURE,          /*!<  */
        TYPE_PATH              /*!<  */
    };

    /*! @brief ?
    *
    * \warning  IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
    *           Same enum in file textprop.h
    *           Make sure you update  all
    *           IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
    *
    */
    enum
    {
        fontFgIsTex             = (1 << 0),
        fontBgIsTex             = (1 << 1),
        fontFgIsSelected        = (1 << 2),
        fontBgIsSelected        = (1 << 3),
        fontFgIsValid           = (1 << 4),
        fontBgIsValid           = (1 << 5),
        fontIsDropShadow        = (1 << 6),
        fontFgIsAA              = (1 << 7),
        fontBgIsAA              = (1 << 8),
        fontFgIsUseColor        = (1 << 9),
        fontBgIsUseColor        = (1 << 10),
        fontIsUnderLine         = (1 << 11),
        fontIsUnderLineStart    = (1 << 12),
        fontIsUnderLineEnd      = (1 << 13),
        fontIsFixedKern         = (1 << 14),
        fontHasTransformation   = (1 << 15),
        fontHasAutoRotation     = (1 << 16),
        fontFgIsUseExternalAlpha = (1 << 17),
        fontBgIsUseExternalAlpha = (1 << 18),
        fontFgIsUseExternalColor = (1 << 19),
        fontBgIsUseExternalColor = (1 << 20),
        fontFgIsUseExternalGeom = (1 << 21),
        fontBgIsUseExternalGeom = (1 << 22),
        fontFgIsUseExtrudeGeom  = (1 << 23),
        fontBgIsUseExtrudeGeom  = (1 << 24),
        fontFgIsNVPR            = (1 << 25),
        fontBgIsNVPR            = (1 << 26),
        fontIsStyleSubscript    = (1 << 27),
        fontIsStyleSuperscript  = (1 << 28),
        fontIsStyleBold         = (1 << 29),
        fontIsStyleItalic       = (1 << 30),
    };


public:

    /*! @brief ?
     *
     * @param[in] val
     * @return ?

     * @todo documentation to be done.
     */
    int setTextOrientation( int val );

    /*! @brief ?
     *
     * @param[in] val
     * @return ?

     * @todo documentation to be done.
     */
    int setTextDirection( int val );

    /*! @brief ?
     *
     * @param[in] val
     * @return ?

     * @todo documentation to be done.
     */
    int setTextVerticalOrientation( int val );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int getTextOrientation( void ) ;

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int getTextDirection( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int getTextVerticalOrientation( void );


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned short getCharCode( void );

    /*! @brief ?
     *
     * @param[in] code
     * @return ?

     * @todo documentation to be done.
     */
    int setCharCode( unsigned short code );

    /*! @brief ?
     *
     * @param[in] code ?
     * @return ?

     * @todo documentation to be done.
     */
    int setNewCharCode( unsigned short code );

    /*! @brief ?
     * @deprecated this function is deprecated.
     *             please use getTotalNumberOfChars or getTotalNumberOfGlyphs.
     *
     * @return ?

     * @todo documentation to be done.
     */
    int getNumberOfCharacters( void );

    /*! @brief    To check that GEOM_TEXT is using complex script
     *            handling. Note that complex script handling might
     *            not work with some fonts. Thus, the GEOM_TEXT will
     *            switch to Font file handling instead.
     *
     * @return    true if Complex Script handling is really applied.
     *            otherwise, false.
     */
    bool isHandlingInComplextScript( void );

    /*! @brief    To get the total number of characters (not include
     *            a terminated character, '\0' or '\n'). the number
     *            shall contain clock characters which are automatically
     *            added if clock in GEOM_TEXT is enabled.
     *
     * @return    a number of total characters
     */
    size_t getTotalNumberOfCharacters( void );

    /*! @brief    To get the total number of glyphs generated by
     *            GEOM_TEXT. This number also includes glyphs of
     *            clock if clock in GEOM_TEXT is enabled.
     *
     * @return    Number of glyphs exclude terminated character.
     */
    size_t getTotalNumberOfGlyphs( void );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setCharIndex( int val )
    {
        m_CharacterIndex = val;
        m_GlyphIndex = -1;
        resetTextControl() ;
    }

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setGlyphIndex( int val )
    {
        m_CharacterIndex = -1;
        m_GlyphIndex = val;
        resetTextControl() ;
    }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool getCharValid( void );

    /*! @deprecated This function is deprecated. Use getFgType instead.
     */
    int getFgStyle();

    /*! @deprecated This function is deprecated. Use setFgType instead.
     */
    void setFgStyle(int iStyle);

    /*! @deprecated This function is deprecated. Use getBgType instead.
     */
    int getBgStyle();

    /*! @deprecated This function is deprecated. Use setBgType instead.
     */
    void setBgStyle(int iStyle);

    /*! @ get texttype (enum textType) ?
    *
    * @param[out] type ?
    * @return ?

    * @todo documentation to be done.
    */
    int getFgType();

    /*! @ set texttype (enum textType) ?
    *
    * @return ?

    * @todo documentation to be done.
    */
    void setFgType(int iType);

    /*! @ get texttype (enum textType) ?
    *
    * @return ?

    * @todo documentation to be done.
    */
    int getBgType();

    /*! @ set texttype (enum textType) ?
    *
    * @return ?

    * @todo documentation to be done.
    */
    void setBgType(int iType);

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void resetTextControl(  );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setFgAlpha( float val );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setBgAlpha( float val );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getFgAlpha( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getBgAlpha( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */

    int resetFgColor( void ) { m_chFgColorMode = CONTROL_MODE_NONE ; return setFgColor(0xffffffff);};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int resetBgColor( void ) { m_chBgColorMode = CONTROL_MODE_NONE ; return setBgColor(0xffffffff);};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int resetFgAlpha( void ) { m_chFgAlphaMode = CONTROL_MODE_NONE ; return setFgAlpha(100.0f);};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int resetBgAlpha( void ) { m_chBgAlphaMode = CONTROL_MODE_NONE ; return setBgAlpha(100.0f);};

    void resetFgColorInternal( void ) { m_chFgColorInternalMode = CONTROL_MODE_NONE ;  setFgColorInternal(0xffffffff);};
    void resetBgColorInternal( void ) { m_chBgColorInternalMode = CONTROL_MODE_NONE ;  setBgColorInternal(0xffffffff);};


    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void resetCharColor( void )
    {
        resetFgColor();
        resetBgColor();
        resetFgAlpha();
        resetBgAlpha();
        resetFgColorInternal();
        resetBgColorInternal();
    }

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void resetAllColor( void )
    {
        for(int i = 0 ; i < (int)getTotalNumberOfCharacters() ;i ++ )
        {
            setCharIndex(i);
            resetCharColor() ;
        }
    }

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int resetTextObject( void );

    /*! @brief ?
     *
     * @param[in] color ?
     * @return ?

     * @todo documentation to be done.
     */
    int setFgColor( unsigned long color );

    /*! @brief ?
     *
     * @param[in] color ?
     * @return ?

     * @todo documentation to be done.
     */
    int setBgColor( unsigned long color );

    /*! @brief ?
     *
     * @param[in] r ?
     * @param[in] g ?
     * @param[in] b ?
     * @param[in] a ?
     * @return ?

     * @todo documentation to be done.
     */
    int setFgColor( float r, float g, float b, float a = 1 );

    /*! @brief ?
     *
     * @param[in] r ?
     * @param[in] g ?
     * @param[in] b ?
     * @param[in] a ?
     * @return ?

     * @todo documentation to be done.
     */
    int setBgColor( float r, float g, float b, float a = 1 );

    /*! @brief ?
     *
     * @param[in] r ?
     * @param[in] g ?
     * @param[in] b ?
     * @param[in] a ?
     * @return ?

     * @todo documentation to be done.
     */
    int setFgColor( int r, int g, int b, int a = 255 );

    /*! @brief ?
     *
     * @param[in] r ?
     * @param[in] g ?
     * @param[in] b ?
     * @param[in] a ?
     * @return ?

     * @todo documentation to be done.
     */
    int setBgColor( int r, int g, int b, int a = 255 );


       /*! @brief ?
     *
     * @param[in] color ?
     * @return ?

     * @todo documentation to be done.
     */


   int setFgColorInternal( unsigned long color );

    /*! @brief ?
     *
     * @param[in] color ?
     * @return ?

     * @todo documentation to be done.
     */
    int setBgColorInternal( unsigned long color );

    /*! @brief ?
     *
     * @param[in] r ?
     * @param[in] g ?
     * @param[in] b ?
     * @param[in] a ?
     * @return ?

     * @todo documentation to be done.
     */
    int setFgColorInternal( float r, float g, float b, float a = 1 );

    /*! @brief ?
     *
     * @param[in] r ?
     * @param[in] g ?
     * @param[in] b ?
     * @param[in] a ?
     * @return ?

     * @todo documentation to be done.
     */
    int setBgColorInternal( float r, float g, float b, float a = 1 );

    /*! @brief ?
     *
     * @param[in] r ?
     * @param[in] g ?
     * @param[in] b ?
     * @param[in] a ?
     * @return ?

     * @todo documentation to be done.
     */
    int setFgColorInternal( int r, int g, int b, int a = 255 );

    /*! @brief ?
     *
     * @param[in] r ?
     * @param[in] g ?
     * @param[in] b ?
     * @param[in] a ?
     * @return ?

     * @todo documentation to be done.
     */
    int setBgColorInternal( int r, int g, int b, int a = 255 );


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int setTransform( void ){return setTransform(NULL);};

    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int setTransform( float x, float y , float z );

    /*! @brief ?

        @param tranform ?
        @return ?

        @todo documentation to be done.
     */
    int setTransform( float * tranform );

    /*! @brief ?

        @param[in] vertex3D
        @return ?

        @todo documentation to be done.
     */
    int setTransform( evVertex3D const & vertex3D );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned long getBgColor( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getBgColorR( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getBgColorG( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getBgColorB( void );


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned long getFgColor( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getFgColorR( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getFgColorG( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getFgColorB( void );


   /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned long getBgColorInternal( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getBgColorInternalR( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getBgColorInternalG( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getBgColorInternalB( void );


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */

      unsigned char getBgColorInternalA( void );


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned long getFgColorInternal( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getFgColorInternalR( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getFgColorInternalG( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned char getFgColorInternalB( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
     unsigned char getFgColorInternalA( void );

    /*! @brief ?
     *
     * @param[out] fontName ?
     * @return ?

     * @todo documentation to be done.
     */
    int getFgFontName( char * fontName );

    /*! @brief ?
     *
     * @param[out] fontName ?
     * @return ?

     * @todo documentation to be done.
     */
    int getBgFontName( char * fontName );

    /*! @brief ?
     *
     * @param[in] fontName ?
     * @return ?

     * @todo documentation to be done.
     */
    int setFgFont( const char * fontName );

    /*! @brief ?
     *
     * @param[in] fontName ?
     * @return ?

     * @todo documentation to be done.
     */
    int setBgFont( const char * fontName );

    /*! @brief ?
     *
     * @param[in] charStyle ?
     * @return ?

     * @todo documentation to be done.
     */
    int setCharStyle( const char * charStyle );
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int resetTransform( void ){m_chTransFormMode = CONTROL_MODE_NONE ; return setTransform(NULL);};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int setScale( void ){return setScale(NULL);};

    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int setScale( float x, float y , float z );

    /*! @brief ?
     *
     * @param tranform ?
     * @return ?

     * @todo documentation to be done.
     */
    int setScale( float * tranform );

    /*! @brief ?
     *
     * @param[in] vertex3D ?
     * @return ?

     * @todo documentation to be done.
     */
    int setScale( evVertex3D const & vertex3D );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int resetScale( void ){m_chScaleMode = CONTROL_MODE_NONE ; return setScale(NULL);};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int setRotation( void ){return setRotation(NULL);};

    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int setRotation( float x, float y , float z );

    /*! @brief ?
     *
     * @param tranform ?
     * @return ?

     * @todo documentation to be done.
     */
    int setRotation( float * tranform );

    /*! @brief ?
     *
     * @param[in] vertex3D ?
     * @return ?

     * @todo documentation to be done.
     */
    int setRotation( evVertex3D const & vertex3D );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int resetRotation( void ){m_chRotationMode = CONTROL_MODE_NONE ; return setRotation(NULL);};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int setCenter( void ){return setCenter(NULL);};

    /*! @brief ?
     *
     * @param[in] x ?
     * @param[in] y ?
     * @param[in] z ?
     * @return ?

     * @todo documentation to be done.
     */
    int setCenter( float x, float y , float z );

    /*! @brief ?
     *
     * @param tranform ?
     * @return ?

     * @todo documentation to be done.
     */
    int setCenter( float * tranform );

    /*! @brief ?
     *
     * @param[in] vertex3D ?
     * @return ?

     * @todo documentation to be done.
     */
    int setCenter( evVertex3D const & vertex3D );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int resetCenter( void ){m_chCenterMode = CONTROL_MODE_NONE ; return setCenter(NULL);};

    /*! @brief ?
     *
     * @param[in] start
     * @param[in] end
     * @return ?

     * @todo documentation to be done.
     */
    int markFgText( int start , int end );

    /*! @brief ?
     *
     * @param[in] start ?
     * @param[in] end ?
     * @return ?

     * @todo documentation to be done.
     */
    int markBgText( int start , int end );

    /*! @brief ?
     *
     * @param[in] start ?
     * @param[in] end ?
     * @return ?

     * @todo documentation to be done.
     */
    int markText( int start , int end );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void resetCharMatrics( void )
    {
        resetTransform();
        resetScale();
        resetRotation();
        resetCenter();
        m_bCenterUpdatePosition = false ;
    }

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void resetAllMatrics( void )
    {
        for(int i = 0 ; i < (int)getTotalNumberOfCharacters() ;i ++ )
        {
            setCharIndex(i);
            resetCharMatrics() ;
        }
    }

    /*! @brief ?
     *
     * @param[in] lod ?
     * @todo documentation to be done.
     */
    void resetCharGeom( int lod )
    {
        setGeomFgData( lod) ;
        setGeomBgData( lod );
    }

    /*! @brief ?
     *
     * @param[in] lod ?
     * @todo documentation to be done.
     */
    void resetAllGeom( int lod )
    {
        for(int i = 0 ; i < (int)getTotalNumberOfCharacters() ;i ++ )
        {
            setCharIndex(i);
            resetCharGeom( lod) ;
        }
    }

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    void resetAllGlyphSize( void )
    {
        for(int i = 0 ; i < (int)getTotalNumberOfCharacters() ;i ++ )
        {
            setCharIndex(i);
            setGlyphSize( 1.0f) ;
        }
    }

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setGlyphSize( float val );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getGlyphSize( void );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setIsUnderLine( bool val ) ;

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setUnderLinePos( float val );

    /*! @brief ?
     *
     * @param[in] val
     * @return ?

     * @todo documentation to be done.
     */
    int setUnderLineWidth( float val );

    /*! @brief ?
     *
     * @param[in] val
     * @return ?

     * @todo documentation to be done.
     */
    int setMarkedSize( float val );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setMarkedPosition( float val );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setMarkedDepth( float val );

    /*! @brief ?
     *
     * @param[in] val
     * @return ?

     * @todo documentation to be done.
     */
    int setFgMarkedColor( unsigned long val );

    /*! @brief ?
     *
     * @param[in] val
     * @return ?

     * @todo documentation to be done.
     */
    int setBgMarkedColor( unsigned long val );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool getIsUnderLine( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getUnderLinePos( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getUnderLineWidth( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getMarkedSize( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getMarkedPosition( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getMarkedDepth( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned long getFgMarkedColor( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    unsigned long getBgMarkedColor( void );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setUseDropShadow( bool val );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setDropShadowDir( float val );

    /*! @brief ?
     *
     * @param[in] val
     * @return ?

     * @todo documentation to be done.
     */
    int setDropShadowDis( float val );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setDropShadowZ( float val );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool  getUseDropShadow( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getDropShadowDir( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getDropShadowDis( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getDropShadowZ( void );


    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setKerning( float val );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setLineSpacing( float val );

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    int setWordSpacing( float val );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getKerning( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getLineSpacing( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getWordSpacing( void );


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharPositionX( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharPositionY( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharPositionZ( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    const float *getCharPosition( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharTransformX( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharTransformY( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharTransformZ( void );

    /*! @brief Returns the character's local offset.
     *
     * @return ?

     */
    evVertex3D getLocalCharOffset();

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    const float *getCharTransform( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharRotationX( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharRotationY( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharRotationZ( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    const float *getCharRotation( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharScaleX( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharScaleY( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharScaleZ( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    const float *getCharScale( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharAdvance( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharWidth( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharHeight( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharMaxY( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharMaxX( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharMinX( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getCharMinY( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getTextWidth( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getTextHeight( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getTextMaxY( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getTextMaxX( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getTextMinX( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    float getTextMinY( void );

    /*! @brief ?
     *
     * @param[in] lod ?
     * @return ?

     * @todo documentation to be done.
     */
    const CVgeomData * getGeomFgData( int lod );

    /*! @brief ?
     *
     * @param[in] lod ?
     * @return ?

     * @todo documentation to be done.
     */
    const CVgeomData * getGeomBgData( int lod );

    /*! @brief ?
     *
     * @param data ?
     * @param[in] lod ?
     * @return ?

     * @todo documentation to be done.
     */
    int setGeomFgData( CVgeomData * data ,int lod );

    /*! @brief ?
     *
     * @param data ?
     * @param[in] lod ?
     * @return ?

     * @todo documentation to be done.
     */
    int setGeomBgData( CVgeomData * data ,int lod );

    /*! @brief ?
     *
     * @param[in] lod ?
     * @return ?

     * @todo documentation to be done.
     */
    int setGeomFgData( int lod ) {return setGeomFgData(NULL , lod);};

    /*! @brief ?
     *
     * @param[in] lod ?
     * @return ?

     * @todo documentation to be done.
     */
    int setGeomBgData( int lod ){return setGeomBgData(NULL , lod);};

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    const unsigned short *getMultiByteText( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool getTextNeedUpdate( void );


    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    const char * getText( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int  setText( const char * text );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    int  setMultibyteText( const unsigned short * text );

/* !
    work mode
*/
    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setGlobalMode( bool val )                   {m_bGlobalMode = val ;};

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setTransformMode( unsigned char val ){m_chTransFormMode = val;};
    unsigned char getTransformMode() {return (unsigned char)( (m_iCurrentExternalMode & 0xff000000) >> 24);}

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setScaleMode( unsigned char val )    {m_chScaleMode = val;};
    unsigned char getScaleMode() {return (unsigned char)( (m_iCurrentExternalMode & 0x0000ff00) >> 8);}

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setCenterMode( unsigned char val )   {m_chCenterMode = val;};
    unsigned char setCenterMode() {return (unsigned char)( (m_iCurrentExternalMode & 0x000000ff) >> 0);}

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setRotationMode( unsigned char val ) {m_chRotationMode = val;};
    unsigned char getRotationMode() {return (unsigned char)( (m_iCurrentExternalMode & 0x00ff0000) >> 16);}


    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setFgAlphaMode( unsigned char val )  {m_chFgAlphaMode = val;};

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setFgColorMode( unsigned char val )  {m_chFgColorMode = val;};

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setBgAlphaMode( unsigned char val )  {m_chBgAlphaMode = val;};

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setBgColorMode( unsigned char val )  {m_chBgColorMode = val;};


    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
      void setFgColorInternalMode( unsigned char val )  {m_chFgColorInternalMode = val;};
      // bool  getFgColorInternalMode(  )  {return (bool)((m_iCharStatus& fontFgIsUseColor));}
     bool  getFgColorInternalMode(  )  { return (m_iCharStatus & fontFgIsUseColor) != 0; }

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */

    void setBgColorInternalMode( unsigned char val )  {m_chBgColorInternalMode = val;};
    // bool  getBgColorInternalMode(  )  {return (bool)((m_iCharStatus& fontBgIsUseColor));}
    bool  getBgColorInternalMode(  )  { return (m_iCharStatus & fontBgIsUseColor) != 0; }
    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setGlyphSizeMode( unsigned char val ){m_chGlyphSizeMode = val;};

    /*! @brief ?
     *
     * @param[in] val ?
     * @return ?

     * @todo documentation to be done.
     */
    void setCenterUpdatePosition( bool val )   {m_bCenterUpdatePosition = val;};

    bool getIgnoreOffsetsForBBCalculation ();
    void setIgnoreOffsetsForBBCalculation (bool bVal);

    /*! @brief ?
    *
    * @return true if any forground or background option is controlled externally

    * @todo documentation to be done.
    */
    bool getFgBgUseExternal()
    {
        return (m_iCharStatus & (fontFgIsUseExternalAlpha | fontBgIsUseExternalAlpha | fontFgIsUseExternalColor |
            fontBgIsUseExternalColor | fontFgIsUseExternalGeom | fontFgIsUseExtrudeGeom)) != 0;
    }

    /*! @brief ?
    *
    * @param[in] textIndices: pointer to the logical indices that will be converted to visual indices
    * @return 1 if mapping is done.

    * @todo documentation to be done.
    */
    int convertToVisualIndices(int *textIndices);

    /*! @brief get cluster of specified character index
    *
    * @return cluster
    */
    const cluster* getClusterFromChar(size_t charIndex);

    /*! @brief get cluster of specified glyph index
    *
    * @return cluster
    */
    const cluster* getClusterFromGlyph(size_t glyphIndex);

    /*! @brief ?
    *
    * @return true if the text geom is being edited

    * @todo documentation to be done.
    */
    bool getEditingActive(void);


    /*! @brief ?
    *
    * @param[in] bVal: enable calculate automatic scale
    *                  required by getMaxFontSize()
    * @return ?

    * @todo documentation to be done.
    */
    void setAutoscale(bool bVal);

    /*! @brief ?
    *
    * @param[in] fVal: default x-scale for max-size calculation
    *
    * @return ?

    * @todo documentation to be done.
    */
    void setDefaultXScale(float fVal);

    /*! @brief ?
    *
    * @param[in] fVal: default y-scale for max-size calculation
    *
    * @return ?
    */
    void setDefaultYScale(float fVal);

    void setBold(bool val);
    void setItalic(bool val);
    void setSubscript(bool val);
    void setSuperscript(bool val);

    bool isBold();
    bool isItalic();
    bool isSubscript();
    bool isSuperscript();

    /*! @brief get id of clock generator attached to this text
    *
    * @return id of clock generator, -1 if clock is disabled
    */
    int getClockGenerator();

    /*! @brief set clock
    *
    * @param[in] bUpdate: true if 
    */
    void setClockOnUpdate(bool bUpdate);
    void setFgSharpen(float fSharpen);
    void setBgSharpen(float fSharpen);

private :
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum
    {
        statusTextLength         = (1<<0 ) ,    /*!<  */
        statusTextUpdate         = (1<<1 ) ,    /*!<  */
        statusTextText           = (1<<2 ) ,    /*!<  */
        statusTextMatrics        = (1<<3 ) ,    /*!<  */
        statusTextMultiByte      = (1<<4 ) ,    /*!<  */
        statusTextColorFg        = (1<<5 ) ,    /*!<  */
        statusTextColorBg        = (1<<6 ) ,    /*!<  */
        statusTextTotalChars     = (1<<7 ) ,    /*!<  */
        statusTextTotalGlyphs    = (1<<8 ) ,    /*!<  */
        statusTextClusters       = (1<<9 ) ,    /*!<  */
    };

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    enum
    {
        statusCharMatrics       = (1<<0 ) ,     /*!<  */
        statusCharAdvance       = (1<<1 ) ,     /*!<  */
        statusCharPosition      = (1<<2 ) ,     /*!<  */
        statusCharCode          = (1<<3 ) ,     /*!<  */
        statusCharValid         = (1<<4 ) ,     /*!<  */
        statusCharColorFg       = (1<<5 ) ,     /*!<  */
        statusCharColorBg       = (1<<6 ) ,     /*!<  */
        statusCharTransform     = (1<<7 ) ,     /*!<  */
        statusCharRotation      = (1<<8 ) ,     /*!<  */
        statusCharScale         = (1<<9 )  ,     /*!<  */
        statusCharColorInternalFg   = (1<<10 ) ,     /*!<  */
        statusCharColorInternalBg       = (1<<11 )     /*!<  */

    };

    ///
    cluster*        m_pClusterList;
    ///
    cluster**       m_pCharToClusterTable;
    ///
    cluster**       m_pGlyphToClusterTable;
    ///
    size_t          m_iTotalNumberOfChars;
    ///
    size_t          m_iTotalNumberOfGlyphs;
    ///
    int             m_iNumberOfCharcters;
    ///
    const char *    m_pcText  ;
    ///
    unsigned int    m_iTextUpdateStatus ;
    ///
    unsigned int    m_iCharUpdateStatus ;
    ///
    unsigned short  m_iCharCode ;
    ///
    bool            m_bCharValid ;
    ///
    static CVgeomData   m_pGeomData ;
    ///
    unsigned char   m_chTransFormMode ;
    ///
    unsigned char   m_chScaleMode ;
    ///
    unsigned char   m_chCenterMode ;
    ///
    unsigned char   m_chRotationMode ;
    ///
    unsigned char   m_chFgColorMode ;
    ///
    unsigned char   m_chBgColorMode ;
    ///
    unsigned char   m_chFgAlphaMode ;
    ///
    unsigned char   m_chBgAlphaMode ;
    ///
    unsigned char   m_chBgColorInternalMode ;
    ///
    unsigned char   m_chFgColorInternalMode ;
    ///
    unsigned char   m_chGlyphSizeMode ;
    ///
    int             m_lastTextProgress ;
    ///
    bool            m_bCenterUpdatePosition ;
    ///
    bool            m_bGlobalMode ;
    ///
    int             m_CharacterIndex;
    ///
    int             m_GlyphIndex;
    ///
    float           m_fVertex[3] ;
    ///
    float           m_fCharPosition[3] ;
    ///
    float           m_fCharTransform[3] ;
    ///
    float           m_fCharRotation[3] ;
    ///
    float           m_fCharScale[3] ;
    ///
    float           m_fCharMatrics[4];
    ///
    float           m_fTextMatrics[4];
    ///
    float           m_fCharAdvance;
    ///
    int             m_iMarkText[2];
    ///
    unsigned short* m_pMultiByteText;
    ///
    int             m_iMultiByteAlloc ;
    ///
    unsigned long   m_iColorTextFg ;
    ///
    unsigned long   m_iColorTextBg ;
    ///
    unsigned long   m_iColorCharFg ;
    ///
    unsigned long   m_iColorCharBg ;

     ///
    unsigned long   m_iColorInternalCharFg ;
    ///
    unsigned long   m_iColorInternalCharBg ;


    unsigned long m_iCharStatus ;

    unsigned long m_iCurrentExternalMode ;







    /*! @brief ?
     *
     * @warning  IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
     *           Same enum in file geom_text.h file vslAuxTypes.h and evPlugin_TEXT_CONTROL.h
     *           Make sure you update  all
     *           IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
     *
     * @todo documentation to be done.
     */
    enum
    {
        TEXT_ID_T_TEXT = 1,                 /*!<  */
        TEXT_ID_T_RESET_TEXT,               /*!<  */
        TEXT_ID_T_MULTIBYTE_TEXT,           /*!<  */
        TEXT_ID_T_NUMBER_OF_CHARACTERS,     /*!<  */
        TEXT_ID_T_KERNING,                  /*!<  */
        TEXT_ID_T_LINE_SPACING,             /*!<  */
        TEXT_ID_T_WORD_SPACING,             /*!<  */
        TEXT_ID_T_ORIENTATION,              /*!<  */
        TEXT_ID_T_DIRECTION,                /*!<  */
        TEXT_ID_T_V_ORIENTATION,            /*!<  */
        TEXT_ID_T_UNDERLINE_POS,            /*!<  */
        TEXT_ID_T_UNDERLINE_SIZE,           /*!<  */

        TEXT_ID_T_DROP_SHADOW,              /*!<  */
        TEXT_ID_T_DROP_SHADOW_DIR,          /*!<  */
        TEXT_ID_T_DROP_SHADOW_DIST,         /*!<  */
        TEXT_ID_T_DROP_SHADOW_Z_OFFSET,     /*!<  */
        TEXT_ID_T_COLOR_FG,                 /*!<  */
        TEXT_ID_T_COLOR_BG,                 /*!<  */
        TEXT_ID_T_ALPHA_FG,                 /*!<  */
        TEXT_ID_T_ALPHA_BG,                 /*!<  */
        TEXT_ID_T_FONT_FG,                  /*!<  */
        TEXT_ID_T_FONT_BG,                  /*!<  */
        TEXT_ID_T_CHAR_STYLE,               /*!<  */
        TEXT_ID_T_GLYPH_SIZE,               /*!<  */
        TEXT_ID_T_USE_UNDERLINE,            /*!<  */
        TEXT_ID_T_TRANFORM,                 /*!<  */
        TEXT_ID_T_CENTER,                   /*!<  */
        TEXT_ID_T_ROTATION,                 /*!<  */
        TEXT_ID_T_SCALING,                  /*!<  */
        TEXT_ID_T_CENTER_UPDATE,            /*!<  */
        TEXT_ID_T_GET_GLOBAL_BB,            /*!<  */
        TEXT_ID_T_GET_PROGRESS,             /*!<  */
        TEXT_ID_T_MARK_TEXT,                /*!<  */


        TEXT_ID_C_TEXT,                     /*!<  */
        TEXT_ID_C_KERNING,                  /*!<  */
        TEXT_ID_C_WORD_SPACING,             /*!<  */
        TEXT_ID_C_DROP_SHADOW,              /*!<  */
        TEXT_ID_C_DROP_SHADOW_DIR,          /*!<  */
        TEXT_ID_C_DROP_SHADOW_DIST,         /*!<  */
        TEXT_ID_C_DROP_SHADOW_Z_OFFSET,     /*!<  */
        TEXT_ID_C_COLOR_FG,                 /*!<  */
        TEXT_ID_C_COLOR_BG,                 /*!<  */
        TEXT_ID_C_ALPHA_FG,                 /*!<  */
        TEXT_ID_C_ALPHA_BG,                 /*!<  */
        TEXT_ID_C_FONT_FG,                  /*!<  */
        TEXT_ID_C_FONT_BG,                  /*!<  */
        TEXT_ID_C_CHAR_STYLE,               /*!<  */
        TEXT_ID_C_GLYPH_SIZE,               /*!<  */
        TEXT_ID_C_USE_UNDERLINE,            /*!<  */
        TEXT_ID_C_TRANFORM,                 /*!<  */
        TEXT_ID_C_CENTER,                   /*!<  */
        TEXT_ID_C_ROTATION,                 /*!<  */
        TEXT_ID_C_SCALING,                  /*!<  */
        TEXT_ID_C_CENTER_UPDATE,            /*!<  */
        TEXT_ID_C_GEOM_FG,                  /*!<  */
        TEXT_ID_C_GEOM_BG,                  /*!<  */

        TEXT_ID_C_GET_MATRICS,              /*!<  */
        TEXT_ID_C_GET_ADVANCE,              /*!<  */
        TEXT_ID_C_GET_VALID,                /*!<  */
        TEXT_ID_C_GET_CODE,                 /*!<  */
        TEXT_ID_C_GET_POSITION,             /*!<  */
        TEXT_ID_C_GET_LOCAL_OFFSET,         /*!<  */
        TEXT_ID_C_COLOR_INTERNAL_FG,        /*!<  */
        TEXT_ID_C_COLOR_INTERNAL_BG,        /*!<  */
        TEXT_ID_C_STATUS,                   /*!<  */
        TEXT_ID_C_EXTERNAL_MODE,            /*!<  */
        TEXT_ID_T_IGNOREOFFSETFORBBCALCULATION, /*!<  */

        TEXT_ID_T_TYPE_FG,                  /*!<  */
        TEXT_ID_T_TYPE_BG,                  /*!<  */
        TEXT_ID_C_TYPE_FG,                  /*!<  */
        TEXT_ID_C_TYPE_BG,                  /*!<  */

        TEXT_ID_T_PROP_INDICES,             /*!<  */
        TEXT_ID_T_MARKED_SIZE,              /*!<  */
        TEXT_ID_T_MARKED_POSITION,          /*!<  */
        TEXT_ID_T_MARKED_COLOR_FG,          /*!<  */
        TEXT_ID_T_MARKED_COLOR_BG,          /*!<  */

        TEXT_EDITING_ACTIVATED,

        TEXT_ID_T_IS_HANDLING_IN_COMPLEXSCRIPT,
        TEXT_ID_T_TOTAL_NUMBER_OF_CHARACTERS,
        TEXT_ID_T_TOTAL_NUMBER_OF_GLYPHS,
        TEXT_ID_T_NUMBER_OF_CLUSTERS,
        TEXT_ID_T_CLUSTER_LIST,

        TEXT_ID_T_SET_AUTOSCALE,
        TEXT_ID_T_SET_DEFAULT_XSCALE,
        TEXT_ID_T_SET_DEFAULT_YSCALE,

        TEXT_ID_C_USE_BOLD,                 /*!<  */
        TEXT_ID_C_USE_ITALIC,               /*!<  */
        TEXT_ID_C_USE_SUBSCRIPT,            /*!<  */
        TEXT_ID_C_USE_SUPERSCRIPT,          /*!<  */

        TEXT_ID_G_TEXT,
        TEXT_ID_G_KERNING,
        TEXT_ID_G_WORD_SPACING,
        TEXT_ID_G_DROP_SHADOW,
        TEXT_ID_G_DROP_SHADOW_DIR,
        TEXT_ID_G_DROP_SHADOW_DIST,
        TEXT_ID_G_DROP_SHADOW_Z_OFFSET,
        TEXT_ID_G_COLOR_FG,
        TEXT_ID_G_COLOR_BG,
        TEXT_ID_G_ALPHA_FG,
        TEXT_ID_G_ALPHA_BG,
        TEXT_ID_G_FONT_FG,
        TEXT_ID_G_FONT_BG,
        TEXT_ID_G_CHAR_STYLE,
        TEXT_ID_G_GLYPH_SIZE,
        TEXT_ID_G_USE_UNDERLINE,
        TEXT_ID_G_TRANFORM,
        TEXT_ID_G_CENTER,
        TEXT_ID_G_ROTATION,
        TEXT_ID_G_SCALING,
        TEXT_ID_G_CENTER_UPDATE,
        TEXT_ID_G_GEOM_FG,
        TEXT_ID_G_GEOM_BG,
        TEXT_ID_G_GET_MATRICS,
        TEXT_ID_G_GET_ADVANCE,
        TEXT_ID_G_GET_VALID,
        TEXT_ID_G_GET_CODE,
        TEXT_ID_G_GET_POSITION,
        TEXT_ID_G_GET_LOCAL_OFFSET,
        TEXT_ID_G_COLOR_INTERNAL_FG,
        TEXT_ID_G_COLOR_INTERNAL_BG,
        TEXT_ID_G_STATUS,
        TEXT_ID_G_EXTERNAL_MODE,
        TEXT_ID_G_TYPE_FG,
        TEXT_ID_G_TYPE_BG,
        TEXT_ID_G_USE_BOLD,
        TEXT_ID_G_USE_ITALIC,
        TEXT_ID_G_USE_SUBSCRIPT,
        TEXT_ID_G_USE_SUPERSCRIPT,

        TEXT_ID_T_CLOCK_GENERATOR,
        TEXT_ID_T_CLOCK_ON_UPDATE,
        TEXT_ID_T_SHARPEN_FG,
        TEXT_ID_T_SHARPEN_BG,
        TEXT_ID_T_MARKED_DEPTH,
    };

    enum deprecated
    {
        TEXT_ID_T_STYLE_FG = TEXT_ID_T_TYPE_FG,                 /*!< deprecated, use TEXT_ID_T_TYPE_FG instead */
        TEXT_ID_T_STYLE_BG = TEXT_ID_T_TYPE_BG,                 /*!< deprecated, use TEXT_ID_T_TYPE_BG instead */
        TEXT_ID_C_STYLE_FG = TEXT_ID_C_TYPE_FG,                 /*!< deprecated, use TEXT_ID_C_TYPE_FG instead */
        TEXT_ID_C_STYLE_BG = TEXT_ID_C_TYPE_BG,                 /*!< deprecated, use TEXT_ID_C_TYPE_BG instead */
        TEXT_ID_G_STYLE_FG = TEXT_ID_G_TYPE_FG,                 /*!< deprecated, use TEXT_ID_G_TYPE_FG instead */
        TEXT_ID_G_STYLE_BG = TEXT_ID_G_TYPE_BG,                 /*!< deprecated, use TEXT_ID_G_TYPE_BG instead */
    };
};


#endif // EV_PLUGIN_TEXT_CONTROL_H
