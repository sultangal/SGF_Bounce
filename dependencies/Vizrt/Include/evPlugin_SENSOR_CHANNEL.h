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

#if ! defined( EV_PLUGIN_SENSOR_CHANNEL_H )
#define EV_PLUGIN_SENSOR_CHANNEL_H

// #include "evPlugin_BASE.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


/*! @brief deprecated SENSOR_CHANNEL OBJECT
 *
 *  This class exists only to maintain backward compatibility with 2.8 plugin source code.
 *
 */
class SENSOR_CHANNEL
{
public:
    SENSOR_CHANNEL()
        : object_id( -1 )
    {}


    /*! @brief get the id of a channel.

        @param[in] sensor_name ?
        @param[in] channel_name ?
        @return ?

        get the id of a channel using the name of the sensor and the channel
        the SENSOR_CHANNEL object points to that channel if the call was successful
        sensor channel has a sensor name and a sensor channel
        he sensor name is used to group channels to one device.
        e.g. a sensor "Joystick" can have several channels "Horizontal", "Vertical", "Button1"...
     */
    int get_sensor(const char *sensor_name, const char* channel_name);

    /*! @brief get the id of a a free channel.

        @return ?

        get the id of a a free channel (active flag==false)
        the SENSOR_CHANNEL object points to that channel if the call was successful
     */
    int get_free_sensor(void);

    /*! @brief get a free sensor.

        @param[in] sensor_name ?
        @param[in] channel_name ?
        @param[in] type ?
        @return ?

        get a free sensor and set the type, sensor_name and channel_name.
     */
    int register_new_sensor(const char* sensor_name, const char* channel_name, int type);

    /*! @brief change the sensor active flag.

        @param[in] active ?
        @return ?

        change the sensor active flag. Is this channel in use, or is it free
     */
    int set_active(bool active);

    /*! @brief ?
     *
     * @param[out] active ?
     * @return ?

     */
    int get_active(bool* active);

    /*! @brief the type describes the dataformat of the channel
     *
     *
     */
    enum SensorDataType
    {
        UNDEFINED
        , BOOL
        , INT
        , FLOAT
        , DOUBLE
    };
    int set_type(int type);
    int get_type(int* type);


    /*! @brief change sensor name and channel name
     *
     * @param[in] name ?
     * @return ?


     */
    int set_sensor_name(const char* name);

    /*! @brief ?
     *
     * @param[out] name ?
     * @return ?

     */
    int get_sensor_name(const char** name);

    /*! @brief ?
     *
     * @param[in] name ?
     * @return ?

     */
    int set_channel_name(const char* name);

    /*! @brief ?
     *
     * @param[out] name ?
     * @return ?

     */
    int get_channel_name(const char** name);


    /*! @brief put data into a channel and get data out of it

        @param[in] data ?
        @return ?

        put data into a channel and get data out of it
     */
    int set_data_bool(bool data);

    /*! @brief ?
     *
     * @param[out] data ?
     * @return ?

     */
    int get_data_bool(bool* data);

    /*! @brief ?
     *
     * @param[in] data ?
     * @return ?

     */
    int set_data_int(int data);

    /*! @brief ?
     *
     * @param[out] data ?
     * @return ?

     */
    int get_data_int(int* data);

    /*! @brief ?
     *
     * @param[in] data ?
     * @return ?

     */
    int set_data_float(float data);

    /*! @brief ?
     *
     * @param[out] data ?
     * @return ?

     */
    int get_data_float(float* data);

    /*! @brief ?
     *
     * @param[in] data ?
     * @return ?

     */
    int set_data_double(double data);

    /*! @brief ?
     *
     * @param data ?
     * @return ?

     */
    int get_data_double(double* data);

    /*! @brief check with valid, if the object in plugin is valid (connection to viz)
     *
     * @return ?

     *
     */
    int valid();

private:
    int object_id;
};



#endif //EV_PLUGIN_SENSOR_CHANNEL_H
