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

#if ! defined( EV_PLUGIN_VIZ_H )
#define EV_PLUGIN_VIZ_H

// #include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class SHARED_MEMORY;
class SCENE;
class TOUCH_TRACE;

// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief ?
 *
 * @todo documentation to be done.
 */
class VIZ {
public:

    enum vizEditor
    {
        RENDERER = 0,
        EDITOR,
        POST
    };

    enum  vizLayer
    {
        BACK_LAYER = 0,
        MAIN_LAYER,
        FRONT_LAYER
    };

    enum  vizComputerType // (rne) Ported from 2.8pl3
    {
        VIZ_IRIX = 0,
        VIZ_VIDEO,
        VIZ_PANASONIC,
        VIZ_PC,
        VIZ_TWC,
        VIZ_SGIPC,
        VIZ_CHYRON_DUET,
        VIZ_UNKONWN
    };

    enum BGL_Level 
    { 
        BGL_INACTIVE = 0,
        BGL_IMAGES = 1,
        BGL_OBJECTS_AND_IMAGES = 2,
        BGL_SCENES_AND_OBJECTS_AND_IMAGES = 3
    };

    static vizComputerType get_computer_type(); // (rne) Ported from 2.8pl3

    // get GPU ID on which the current viz instance is running on
    /*! @brief ?
     *
     * @param[out] id ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_gpu_device(int &id);

    // get the number of available gpu devices
    /*! @brief ?
     *
     * @param[out] count ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_number_of_gpus(int &count);

    // get GPU ID on which the current viz instance is running on
    /*! @brief ?
     *
     * @param[out] id ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_engine_instance(int & instance);

    // is Everest in on_air mode
    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_is_on_air( bool * value );

    // is Viz running in nle mode
    static int get_is_nle(bool* value);

    // is Everest in post render mode and recording
    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_is_post_recording( bool * value );

    //
    /*! @brief ?
    *
    * @param[in] samples ?
    * @param[out] buffer ?
    * @return ?

    * @todo documentation to be done.
    */
    static int get_audio_mix_post(int samples, int channels, int buffer_size, char * buffer);

    //
    /*! @brief ?
    *
    * @param[out] value ?
    * @return ?

    * @todo documentation to be done.
    */
    static int get_post_supports_audio( bool * value );

    /*! @brief ?
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_post_current_time( float * value );

    static unsigned int get_current_timecode();
    static unsigned int get_post_timecode();

    /*! @brief send a command to Everest and get the answer
     *
     * @param[in] command ?
     * @param[out] answer ?
     * @return ?

     * @todo documentation to be done.
     */
    static int send_command( const char * command, const char ** answer );

    /*! @brief send the answer to a command which was received by viz.
     *
     * viz will not answer to this command anymore. Use only if you know what you are doing!
     * @param[in] msg ?
     * @return ?

     * @todo documentation to be done.
     */
    static int send_answer( const char * msg );

    /*! @brief works like the send_answer, but send an error message instead
     *
     * @param[in] msg ?
     * @return ?

     * @todo documentation to be done.
     */
    static int send_error( const char * msg );

    /*! @brief get the system id of the machine we are running on.
     *
     *  (sysinfo on UNIX, dongle id on NT).
     * @param[out] id ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_sysid( const char ** id );

    /*! @brief get the id of the main renderer
    *
    * @param[out] id object id
    * @return ?

    * @todo documentation to be done.
    */
    static int get_renderer_id(int &id);

    /*! @brief get the refresh rate which is set in the config
    *
    * @param[out] value ?
    * @return ?

    * @todo documentation to be done.
    */
    static int get_config_refreshrate(double *value);

    /*! @brief get the current refresh rate
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_refreshrate( double * value );

    /*! @brief -- Deprecated -- get the current retrace counter
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_retracecounter( unsigned long * value );

        /*! @brief get the current retrace counter
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_retracecounter( uint64_t * value );
    /*! @brief get the current output field dominance
     *
     * @param[out] bEven ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_output_field_dominance(bool *bEven);

    /*! @brief returns true if the current output is interlaced or false for progressive mode
     *
     * @param[out] bInterlaced ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_output_interlaced(bool *bInterlaced);

    enum eOutputFormat {
        VIZ_INVALID = -1
        , VIZ_INACTIVE = 0
        , VIZ_COMP_480I_5994
        , VIZ_COMP_576I_5000
        , VIZ_SDI_480I_5994_SMPTE259_NTSC
        , VIZ_SDI_576I_5000_SMPTE259_PAL
        , VIZ_SDI_720P_5994_SMPTE296
        , VIZ_SDI_720P_6000_SMPTE296
        , VIZ_SDI_1035I_5994_SMPTE260
        , VIZ_SDI_1035I_6000_SMPTE260
        , VIZ_SDI_1080I_5000_SMPTE295
        , VIZ_SDI_1080I_5000_SMPTE274
        , VIZ_SDI_1080I_5994_SMPTE274
        , VIZ_SDI_1080I_6000_SMPTE274
        , VIZ_SDI_1080PSF_23976_SMPTE274
        , VIZ_SDI_1080PSF_2400_SMPTE274
        , VIZ_SDI_1080PSF_2500_SMPTE274
        , VIZ_SDI_1080P_23976_SMPTE274
        , VIZ_SDI_1080P_2400_SMPTE274
        , VIZ_SDI_1080P_2500_SMPTE274
        , VIZ_SDI_1080P_2997_SMPTE274
        , VIZ_SDI_1080P_3000_SMPTE274
        , VIZ_SDI_720P_5000_SMPTE296
        , VIZ_SDI_720P_3000_SMPTE296
        , VIZ_SDI_720P_2997_SMPTE296
        , VIZ_SDI_720P_2500_SMPTE296
        , VIZ_SDI_720P_2400_SMPTE296
        , VIZ_SDI_720P_2398_SMPTE296
        , VIZ_SDI_1080P_5000_SMPTE424M
        , VIZ_SDI_1080P_5994_SMPTE424M
        , VIZ_SDI_1080P_6000_SMPTE424M
        , VIZ_SDI_2048P_24_00_SMPTE372
        , VIZ_SDI_2048P_25_00_SMPTE372
        , VIZ_SDI_2048P_29_97_SMPTE372
        , VIZ_SDI_2048P_30_00_SMPTE372
        , VIZ_SDI_2160P_2500_UHDTV1
        , VIZ_SDI_2160P_2997_UHDTV1
        , VIZ_SDI_2160P_3000_UHDTV1
        , VIZ_SDI_2160P_5000_SMPTE2036_UHDTV1
        , VIZ_SDI_2160P_5994_SMPTE2036_UHDTV1
        , VIZ_SDI_2160P_6000_SMPTE2036_UHDTV1
        , VIZ_SDI_2160P_5000_SMPTE425_5_UHDTV1
        , VIZ_SDI_2160P_5994_SMPTE425_5_UHDTV1
        , VIZ_SDI_2160P_5000_4K
        , VIZ_SDI_2160P_5994_4K
        , VIZ_SDI_2160P_6000_4K
        , VIZ_FULL_SCREEN
        , VIZ_USER_DEFINED
        , VIZ_STREAM
        , VIZ_GFX
        , VIZ_SUPER
        , VIZ_IMAGE
        , keVizVideoSystemLAST
    };
    enum eStereoMode{
        STEREO_OFF = 0,
        STEREO_QUAD_BUFFERED,
        STEREO_LEFT_EYE,
        STEREO_RIGHT_EYE,
        STEREO_SIDE_BY_SIDE_LEFT_FIRST,
        STEREO_SIDE_BY_SIDE_RIGHT_FIRST,
        STEREO_OVER_UNDER_LEFT_TOP,
        STEREO_OVER_UNDER_RIGHT_TOP,
        STEREO_ROW_INTERLACED_LEFT_TOP,
        STEREO_ROW_INTERLACED_RIGHT_TOP,
        STEREO_COL_INTERLACED_LEFT_FIRST,
        STEREO_COL_INTERLACED_RIGHT_FIRST,
        STEREO_ANAGLYPH,
        STEREO_ALIOSCOPY};

    /*! @brief get the current video output format
     *
     * @return eOutputFormat ?

     * @todo documentation to be done.
     */
    static eOutputFormat get_output_format();

    /*! @brief get the current stereo mode
     *
     * @return eOutputFormat ?

     * @todo documentation to be done.
     */
    static eStereoMode get_stereo_mode();

    /*! @brief get the redering window width and height
     *
     * @param[out] width ?
     * @param[out] height ?
     * @return true if size of window could be queried, false if no editor or no window handle exists

     * @todo documentation to be done.
     */
    static int get_window_size( int * width, int * height );

    static int get_output_to_render_ratio( float * ratioX, float * ratioY );

    /*! @brief  get the time (in seconds) that has passed since viz was started
     *
     * @param[out] value ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_elapsed_time(double* value);

    // get the post rendering window width and height
    static int get_post_window_size(int *width, int *height);

       // set the rendering window cursor
    static int set_window_cursor(int cursor);

    /*! @brief This routine tries to convert path
     *
     *  This routine tries to convert path using the rules under
     *  viz config -> image file name convert, and returns
     *  the new path if successful, otherwise NULL.
     *  use paths with '/' like c:/temp (or c:\\temp) because \\t is tab
     * @param[in] orig_path ?
     * @return ?

     * @todo documentation to be done.
     */
    static const char* config_convert_path( const char * orig_path );

    /*! @brief License for plugins
     *
     * @param[in] feature ?
     * @param[out] enabled ?
     * @return ?

     * @todo documentation to be done.
     */
    static int is_feature_enabled( int feature, bool * enabled );

    /*! @brief License for plugins
    *
    * @param[out] on ?
    * @return ?

    * @todo documentation to be done.
    */
    static int is_vga_mode(bool * on);

    /*! @brief get the current mouse position
     *
     * @param[in] win_id ?
     * @param[out] xpos ?
     * @param[out] ypos ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_cur_mousepos( int win_id, int * xpos, int * ypos );

    /*! @brief get the current mouse position undeformed (inverse lense deformation)
     *
     * @param[in] win_id ?
     * @param[out] xpos ?
     * @param[out] ypos ?
     * @return ?

     * @todo documentation to be done.
     */
    static int get_cur_mousepos_undeformed( int win_id, int * xpos, int * ypos );

    /*! @brief ?
     *
     * @param[in] imageName ?
     * @return ?

     * @todo documentation to be done.
     */
    static int is_importable_picture( const char * imageName );

    /*! @brief import an image.
     *
     * @param[in] imageName ?
     * @param format ?
     * @param width ?
     * @param height ?
     * @param data ?
     * @return ?

     * @todo documentation to be done.
     */
    static int import_image( const char * imageName, int * format, int * width, int * height, unsigned char ** data );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    static int done_import_image( void );

    static int get_aspect(float *value);
    static int get_out_renderer_size(int *w , int *h ); // (rne) Ported from 2.8pl3
    static int get_out_renderer_buffer_size(int *w , int *h );
    static int get_panasonic_video_data(int x, int y, int width,int height, unsigned char ** data ); // (rne) Ported from 2.8pl3

    //! @brief Gets the global shared memory map used.
    static int get_global_shared_memory(SHARED_MEMORY& sm);

    //! @brief Gets the distributed shared memory map used.
    static int get_distributed_shared_memory(SHARED_MEMORY& sm);

    enum EFontCode
    {
        EV_FONT_DEFAULT = 0,
        EV_FONT_JIS,
        EV_FONT_SJIS,
        EV_FONT_EUC,
        EV_FONT_UNICODE,
        EV_FONT_UTF_8
    };

    static int get_font_encoding(EFontCode* pFontCode);

    /*! brief Gets the filename of a pool object.
     */
    static int get_filename_of_pool_object(const char* location, char* returnBuffer, int bufferLength);

    /*! brief Gets the full path of a pool object.
     */
    static int get_path_of_pool_object(const char* location, bool addPoolPrefix, char* returnBuffer, int bufferLength);

    /*! brief Gets the filename of a db file specified by its uuid.
     */
    static int get_filename_of_uuid(const char* uuidString, char* returnBuffer, int bufferLength);

    /*! brief Gets the full path of a db file specified by its uuid.
     */
    static int get_path_of_uuid(const char* uuidString, char* returnBuffer, int bufferLength);

    /*! brief Gets all full paths of a db file specified by its uuid. <returnBuffer> contains all paths using '\n' as a delimeter.
    */
    static int get_paths_of_uuid(const char* uuidString, char* returnBuffer, int bufferLength);

    /*! brief Gets the UUUD of a db file specified by its full path.
    */
    static int get_uuid_of_path(const char* pathString, char* returnBuffer, int bufferLength);

    static int load_scene(const char *sceneName, SCENE &scene);

    static int    set_show_object_bounding_box(bool v);
    static int    get_show_object_bounding_box(bool *v);

    /*! brief Gets Map Server Parameters.
     */
    static int    getMapServerParameters(bool *bActive , const char ** ServerIp, const char ** UserName,
                                         const char ** Password, const char ** DefaultProject,
                                         int *iDefaultImageWidth, int *iDefaultImageHeight);
    /*! brief Sets Map Server Parameters.
     */
    static int   setMapServerParameters(bool bActive , const char * ServerIp, const char * UserName,
                                        const char * Password, const char * DefaultProject,
                                        int iDefaultImageWidth, int iDefaultImageHeight);
    /*! Viz folders
    */
    static int getTemporaryFilesPath(const char ** path);
    __declspec(deprecated(" this is a deprecated function. Please use getClipDataDirectory()")) 
    static int getClipDataDirectoryA(std::string & strClipDataDir);
    static int getClipDataDirectory(std::wstring & strClipDataDir);
    __declspec(deprecated(" this is a deprecated function. Please use getVizProgramDataFolder()"))
        static int getVizProgramDataFolderA(std::string & strVizDataFolder);
    static int getVizProgramDataFolder(std::wstring & strVizDataFolder);

    /*! Plugins can also send feedback commands
     */
    static int send_feedback_command(const char* str);

    /*! Get the number of current command, like "222 TREE*GET*OBJECT" will return 222
     */
    static int get_command_number(int* commandNumber);

    /*! brief Gets loaded scene from a layer in a editor
     */
    static int get_scene(vizEditor editor, vizLayer layer, SCENE & scene);

    /*! brief Sets scene in editor's layer
     */
    static int set_scene(vizEditor editor, vizLayer layer, const char * scene);

    /*! brief Sets scene in editor's layer
     */
    static int set_scene(vizEditor editor, vizLayer layer, SCENE & scene);

    /*! brief clear scene from a editor's layer
     */
    static int clear_editor(vizEditor editor, vizLayer layer);

    /*! brief unload scene
     */
    static int unload_scene(const char * scene);

    /*! brief unload scene
     */
    static int unload_scene(SCENE & scene);

    /*! brief execute hit test
     *
     * hit_test performs a hit testing operation at screen position x/y.
     * The stroke ID is used to distinct between the different hits on
     * all the objects. As soon as the test is done PLUGIN_HIT_TEST_RESULT
     * will be called with a list of the picked objects.
     */
    static int hit_test(int iStrokeID, int iPosX, int iPosY);

    static int send_attribution_list(int iAttributionSize,
                                    const char ** chAttributionNamesList,
                                    const char * chAttributionMain ,
                                    int iAttributionMainValue);

    /*! brief returns the Trace with the passed Trace ID
     */
    static int get_trace(unsigned int iTraceID, TOUCH_TRACE& trace);

    /*! brief returns the Trace with the passed index
     */
    static int get_trace_by_index(unsigned int iIndex, TOUCH_TRACE& trace);

    /*! brief returns the number of all active Traces
     */
    static int get_trace_count(unsigned int& iTraceCount);

    /*! brief gets the background loading level. BGL_INACTIVE = background loading off, BGL_IMAGES = background loading for images, BGL_OBJECTS_AND_IMAGES = background loading for images and geometries
    */
    static int get_background_loading_level(BGL_Level& level);

    /*! brief get the number of texture image units (GL_MAX_TEXTURE_IMAGE_UNITS)
    */
    static int get_number_of_texture_image_units(int& unit_count);

    /*!brief get the current render scale
    */
    static int get_render_scale(float& render_scale);

    /*!brief get location path of specified object id.
    */
    static int get_location_path(int objectId, const char** locationPath);
};

//! Deprecated. Use VIZ instead of EVEREST.
typedef VIZ EVEREST;


#endif // EV_PLUGIN_VIZ_H

