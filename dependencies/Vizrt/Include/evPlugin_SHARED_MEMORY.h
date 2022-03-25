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

#if ! defined( EV_PLUGIN_SHARED_MEMORY_H )
#define EV_PLUGIN_SHARED_MEMORY_H

#include "evMath.h"
#include "evPlugin_BASE.h"
#include "evPlugin_RGBAColor.h"


// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------



///////////////////////
// class STRING_TYPE //
///////////////////////

/*! @brief A string class.
*
* This is a simple string class that's used to pass strings from
* the plugin to the engine and vice versa. Unlike std::string, it
* is designed to work across DLL boundaries.
*/
class STRING_TYPE
{
public:
    friend class VARIANT_VAR;

    STRING_TYPE();
    STRING_TYPE(const STRING_TYPE& s);
    STRING_TYPE(const char* s);

    ~STRING_TYPE();

    STRING_TYPE& operator=(const STRING_TYPE& s);
    STRING_TYPE& operator=(const char* s);

    void clear();

    STRING_TYPE& operator+=(const STRING_TYPE& s);
    STRING_TYPE& operator+=(const char* s);

    const char* c_str() const;

    size_t get_length() const;

private:
    THeapArray<char> chars;
};


/////////////////////////
// class SHARED_MEMORY //
/////////////////////////

/*! @brief Shared memory.
*
* This is string-indexed map holding VARIANT_VAR objects.
* It is particularly useful for implementing data sharing between
* plugins and scripts. In the script, the equivalent class is
* called SharedMemory.
*
* Every scene has a SHARED_MEMORY object, accessible via SCENE's
* get_shared_memory method (in the script: Scene.Map). In addition,
* there is a global SHARED_MEMORY object, accessible via
* VIZ::get_global_shared_memory (in the script: Sytem.Map).
*/
class SHARED_MEMORY : public BASE
{
public:
    SHARED_MEMORY() { }
    SHARED_MEMORY(int id) : BASE(id) { }

    bool is_valid();

    bool has_key(const char* key);
    bool create_key(const char* key);
    bool delete_key(const char* key);

    bool set_value(const char* key, const VARIANT_VAR& value);
    bool get_value(const char* key, VARIANT_VAR& value);

    /*! @brief Sets value via the corresponding transport mechanism (e.g. GraphicHub). This prevents possible re-triggering of the PLUGIN_SHARED_MEMORY_VARIABLE_CHANGED callback.
    *
    * @param[in] key
    * @param[in] value
    * @return true if successful
    */
    bool set_value_delayed(const char* key, const VARIANT_VAR& value);

    /*! @brief Causes PLUGIN_SHARED_MEMORY_VARIABLE_CHANGED to be invoked whenever
     * the variable identified by 'key' is changed. If 'key' is an empty string (""),
     * PLUGIN_SHARED_MEMORY_VARIABLE_CHANGED is called whenever any variable in
     * the map is changed.
     * Similarly, PLUGIN_SHARED_MEMORY_VARIABLE_DELETED will be called in response to "key"
     * (or any variable) being deleted from the map.
     *
     * @param[in] key
     * @return true if successful
     */
    bool register_changed_callback(const char* key);

    /*! @brief Removes the binding set up by RegisterChangedCallback.
     *
     * @param[in] key
     * @return true if successful
     */
    bool unregister_changed_callback(const char* key);

    /*! @brief Gets all keys.
     *
     * @param[out] keys The array the keys will be written into.
     * @return true if successful
     */
    bool get_keys(THeapArray<STRING_TYPE>& keys);
};



class VARIANT_VAR_ARRAY; //forward declaration

///////////////////////
// class VARIANT_VAR //
///////////////////////

/*! @brief A variant variable.
*
* Objcts of this type act as variant variables, meaning they
* can hold values of any type. All objects stored in a SHARED_MEMORY
* object are VARIANT_VAR objects.
*/
class VARIANT_VAR
{
public:
    friend class SHARED_MEMORY;
    friend class SCRIPTFUNCTION;

    VARIANT_VAR();
    VARIANT_VAR(const VARIANT_VAR& src);
    explicit VARIANT_VAR(bool value);
    explicit VARIANT_VAR(int value);
    explicit VARIANT_VAR(double value);
    explicit VARIANT_VAR(const evVertex3D& value);
    explicit VARIANT_VAR(const evMatrix& value);
    explicit VARIANT_VAR(const RGBAColor& value);
    explicit VARIANT_VAR(const BASE& value);
    explicit VARIANT_VAR(const STRING_TYPE& value);
    explicit VARIANT_VAR(const char* value);
    explicit VARIANT_VAR(const VARIANT_VAR_ARRAY& value);

    ~VARIANT_VAR();

    VARIANT_VAR& operator=(const VARIANT_VAR& src);

    void set(bool value);
    void set(int value);
    void set(double value);
    void set(const evVertex3D& value);
    void set(const evMatrix& value);
    void set(const RGBAColor& value);
    void set(const BASE& value);
    void set(const STRING_TYPE& value);
    void set(const char* value);
    void set(const VARIANT_VAR_ARRAY& value);

    bool get(bool& value) const;
    bool get(int& value) const;
    bool get(double& value) const;
    bool get(evVertex3D& value) const;
    bool get(evMatrix& value) const;
    bool get(RGBAColor& value) const;
    bool get(BASE& value) const;
    bool get(STRING_TYPE& value) const;
    bool get(VARIANT_VAR_ARRAY& value) const;

    void clear();

private:
    STRING_TYPE str;
};

///////////////////////
// VARIANT_VAR_ARRAY //
///////////////////////

/*! @brief An array of shared memory variables.
*
* This helper class let's you create a VARIANT_VAR object that is
* an array of VARIANT_VAR objects.
*/
class VARIANT_VAR_ARRAY
{
public:
    VARIANT_VAR_ARRAY();
    VARIANT_VAR_ARRAY(const VARIANT_VAR_ARRAY& src);
    ~VARIANT_VAR_ARRAY();

    VARIANT_VAR_ARRAY& operator=(const VARIANT_VAR_ARRAY& src);

    size_t get_size() const;

    const VARIANT_VAR& operator[](size_t index) const;
    VARIANT_VAR& operator[](size_t index);

    void append(const VARIANT_VAR& element);

    void clear();

private:
    THeapArray<VARIANT_VAR> array;
};




#endif // EV_PLUGIN_SHARED_MEMORY_H
