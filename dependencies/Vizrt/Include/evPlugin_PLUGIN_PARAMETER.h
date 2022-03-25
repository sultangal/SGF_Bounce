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

#if ! defined( EV_PLUGIN_PLUGIN_PARAMETER_H )
#define EV_PLUGIN_PLUGIN_PARAMETER_H

// #include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class TEXT_CHARACTER_PROPERTY;
class PLUGIN_INSTANCE;

//=========================================================================
// PLUGIN_PARAMETER OBJECT
//=========================================================================

/*! @brief ?
 *
 * This class is used to get connection to the geometry and the function plugins - so you can
 * manipulate them within your plugin!
 * @todo documentation to be done.
 */
class PLUGIN_PARAMETER
{
private:
    /// type of parameter (float, int ...)
    int data_type;
    /// name of geom plugin
    char* plugin_name;
    /// name of field in plugin
    char* field_name;
    /// byte offset in data of plugin
    int byte_offset;
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    union union_data {
        float f_data;           ///< float_data
        int i_data;             ///< int_data
        bool b_data;            ///< bool_data
        unsigned long l_data;   ///< long_data
        char* cp_data;          ///< charpointer_data

        union_data() : cp_data(NULL) { }
        };
    union union_data    data;
    int min;        ///< min value of parameter (when string -> length)
    int max;        ///< max value of parameter (when string -> length)
    int okay;       ///< flag if everything went okay
    int     m_iIndex;           // the index of the field in the  plugin
    bool    m_bNotify;          // should I Notify the pluign on change

public:
    /*! @brief ?
     *
     * @param[in] plugin_name ?
     * @param[in] field_name ?

     * @todo documentation to be done.
     */
    PLUGIN_PARAMETER( char const * plugin_name = NULL, char const * field_name = NULL );

    /*! @brief ?
     *
     * @param[in] plugin_instance ?
     * @param[in] field_name ?

     * @todo documentation to be done.
     */
    PLUGIN_PARAMETER( PLUGIN_INSTANCE& plugin_instance, char const * field_name);

    /*! @brief ?
     *
     * @param old right hand side
     * @todo documentation to be done.
     */
    PLUGIN_PARAMETER( PLUGIN_PARAMETER & old );

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    ~PLUGIN_PARAMETER( void );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    void Cleanup( void );

    /*! @brief initialize a Plugin Parameter to a Plugin/Field does the same as the constructor
     *
     * @param[in] plugin_name ?
     * @param[in] field_name ?
     * @return ?

     * @todo documentation to be done.
     */
    int Init( char const * plugin_name, char const * field_name);

    /*! @brief initialize a Plugin Instance Parameter to a Field
     *
     * @param[in] field_name ?
     * @return ?

     * @todo documentation to be done.
     */
    int Init( PLUGIN_INSTANCE& plugin_instance, char const * field_name);

    /*! @brief is parameter valid
     *
     * @return ?

     * @todo documentation to be done.
     */
    bool valid( void ) const;

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    const PLUGIN_PARAMETER& operator=( const int value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    const PLUGIN_PARAMETER& operator=( const float value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    const PLUGIN_PARAMETER& operator=( const bool value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    const PLUGIN_PARAMETER& operator=( const char * value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    const PLUGIN_PARAMETER& operator=( const double value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    const PLUGIN_PARAMETER& operator=( const unsigned long value );

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    const PLUGIN_PARAMETER& operator=( const unsigned int value );

    /*! @brief for compatibility with 2.7
     *
     * @param tchp ?
     * @return ?

     * @todo documentation to be done.
     */
    void operator=( TEXT_CHARACTER_PROPERTY & tchp );

    // cast-operator
    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    operator int() const;

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    operator float() const;

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    operator const char*() const;

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    operator bool() const;

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    operator unsigned long() const;

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    operator double() const;

    /*! @brief ?
     *
     * @todo documentation to be done.
     */
    operator unsigned int() const;

    // + operator
    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    float operator+( const float value ) const;

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int operator+( const int value ) const;

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    double operator+( const double value ) const;

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    float operator-( const float value ) const;

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    int operator-( const int value ) const;

    /*! @brief ?
     *
     * @param[in] value ?
     * @return ?

     * @todo documentation to be done.
     */
    double operator-( const double value ) const;

    /*! @brief print the values of this class
     *
     * @return ?

     * @todo documentation to be done.
     */
    void print( void ) const;

    /*! @brief print all parameters of all geom plugins
     *
     * @return ?

     * @todo documentation to be done.
     */
    static int print_info( void );

    /*! @brief print all parameters of the geom plugin 'plugin_name'
     *
     * @param plugin_name ?
     * @return ?

     * @todo documentation to be done.
     */
    static int print_info( char * plugin_name );

    int setNotify();                        //enable Notify the target pluign when you change is value
                                            // can be called only after Init

    /*! @brief ?
     *
     *
     * @todo documentation to be done.
     */
    enum eDataType  {
        EV_FLOAT = 1,                   /*!<  */
        EV_INT,                         /*!<  */
        EV_BOOL,                        /*!<  */
        EV_COLOR,                       /*!<  */
        EV_RADIO,                       /*!<  */
        EV_PUSHBUTTON,                  /*!<  */
        EV_FILE_SEL,                    /*!<  */
        EV_STRING,                      /*!<  */
        EV_DIR_SEL,                     /*!<  */
        EV_INFOTEXT,                    /*!<  */
        EV_TEXT,                        /*!<  */
        EV_LISTBOX,                     /*!<  */
        EV_IMAGE,                       /*!<  */
        EV_FONT,                        /*!<  */
        EV_HLISTBOX,                    /*!<  */
        EV_CONT,                        /*!<  */
        EV_DATA,                        /*!<  */
        EV_SUBSTANCE,                   /*!<  */
        EV_IMAGE_EX = 28,               /*!<  */
        EV_SLIDER_FLOAT = 29,           /*!<  */
        EV_SLIDER_INT = 30,             /*!<  */
        EV_DROPDOWNBOX = 31,            /*!<  */
        EV_CHARACTER_PROPERTY=99        /*!<  */
    };

    /*! @brief ?
     *
     *
     * ImageEx data type
        @see evRegisterParameterImageEx
     */
    typedef struct _IMAGE_EX
    {
        char    *sImg;
        float   fPosXY[2];
        float   fRotXYZ[3];
        float   fSclXY[2];
    } IMAGE_EX;


    /********* only for internal use !!!! ******************/
    /*! @brief ?
     *
     *
     * @return
     * @note for internal use only.
     * @todo documentation to be done.
     */
    int get_data_type( void ) const                 { return data_type; }    /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    const char* get_plugin_name( void ) const       { return plugin_name; }  /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    const char* get_field_name( void ) const       { return field_name; }  /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    int get_byte_offset( void ) const               { return byte_offset; }  /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    const void* get_data( void ) const              { return &data; }                /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    void* get_data( void )                          { return &data; }                /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    float get_data_float( void ) const              {  return data.f_data; }  /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    int get_data_int( void ) const                  { return data.i_data; }  /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    bool get_data_bool( void ) const                { return data.b_data; }  /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    unsigned long get_data_ulong( void ) const      { return data.l_data;}       /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    const char* get_data_charp( void ) const        { return data.cp_data;}  /**/

    /*! \internal @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    int get_max( void ) const                       { return max; }                  /**/

    /*! @brief ?
     *
     * @return ?

     * @note for internal use only.
     * @todo documentation to be done.
     */
    int get_min( void ) const                       { return min; }                  /**/



    int     get_index()         { return m_iIndex; }             /**/
    bool    get_notify()            { return m_bNotify; }            /**/

    /*! @brief ?
    *
    * @note for internal use only.
    * @todo documentation to be done.
    */
    void init_data( void );     /**/
    /********* only for internal use !!!! ******************/
};

#endif // EV_PLUGIN_PLUGIN_PARAMETER_H
