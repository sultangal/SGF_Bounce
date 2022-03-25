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

#if ! defined( EV_PLUGIN_GUI_COMMANDS_H )
#define EV_PLUGIN_GUI_COMMANDS_H

// #include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------
class CONTAINER;


// ---------------------------------------------------------------------
//
// ---------------------------------------------------------------------
/*! @brief GUI commands.
 *
 * these calls update/modify the GUI. e.g. If you assign a material (or change it) of a container
 * and you want the GUI to be updated, use "container_editor_update(container)". This will force the
 * Container Editor in the GUI to be redrawn. If you add/delete containers from the scenetree use
 * "tree_editor_update()" to have the tree editor redrawn.
 */
class GUI_COMMANDS {

public:
    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    static int tree_editor_update( void );

    /*! @brief ?
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    static int container_editor_update( CONTAINER & container );

    /*! @brief ?
     *
     * @param container ?
     * @return ?

     * @todo documentation to be done.
     */
    static int container_editor_recompute( CONTAINER & container );

    /*! @brief close or open the tree underneath container
     *
     * @param container ?
     * @param[in] value
     * @return ?

     * @todo documentation to be done.
     */
    static int container_set_open( CONTAINER & container, bool value );

    /*! @brief ?
     *
     * @param container ?
     * @param[out] value
     * @return ?

     * @todo documentation to be done.
     */
    static int container_get_open( CONTAINER & container, bool * value );

    /*! @brief send error to log
     *
     * @param[in] msg
     * @return ?

     * @todo documentation to be done.
     */
    static int send_error_msg( char * msg );

    /*! @brief opens a infobox in the GUI
    *
    * @param[in] msg the info message
    * @todo documentation to be done.
    */
    static int send_info_msg( const char * msg );

    // send command
    /*! @brief ?
     *
     * @param[in] command
     * @return ?

     * @todo documentation to be done.
     */
    static int send_command( char * command );
    // send command rebuild controllist
    /*! @brief collects all rebuild controllist commands to set it once at the end of command loop
     * @return ?
    */
    static int send_command_rebuild_controllist();
    /*! @brief ?
     *
     * IMPORTANT: if you use show_working_dialog: DON'T FORGET TO CLOSE THE WORKING DIALOG
     * AGAIN - if you don't close the working dialog, the GUI is locked until timeout (about 60 sec)!
     * show working dialog("") => only busy-clock is shown
     * If your action is long you should consider to call show_working_dialog("Text") every few seconds
     * you dont have to do a close_working_dialog() before you send the next show_working_dialog("Text"), if
     * a working dialog is active, a show_working_dialog("Text") will update it
     *
     * @param[in] msg
     * @return ?

     * @todo documentation to be done.
     */
    static int show_working_dialog( char * msg );

    /*! @brief ?
     *
     * @return ?

     * @todo documentation to be done.
     */
    static int close_working_dialog( void );
};



#endif // EV_PLUGIN_GUI_COMMANDS_H
