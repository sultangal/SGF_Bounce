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

#pragma once
#ifndef __T_HEAP_ARRAY_H__
#define __T_HEAP_ARRAY_H__




#include <windows.h>
#include <assert.h>

/*! @brief {brief description}
 *
 * THeapArray maintains a dynamically allocated array of objects of type T. The memory is
 * allocated using Win32 API functions (HeapAlloc, HeapReAlloc, HeapFree), which ensures that
 * objects of THeapArray can be safely passed across DLL boundaries within a process.
 *
 * Use 'SetSize' to resize the array, and the index operator to access individual elements.
 */
template <class T>
class THeapArray
{
public:

    /*! @brief default constructor.
     *
     * constructs an empty array.
     */
    THeapArray() { InitMembers(); }

    /*! @brief ?
     *
     * constructs array of size elements.
     * @param[in] size number of elements the array should have room for.
     * @return ?

     */
    THeapArray(size_t size) { InitMembers(); SetSize(size); }

    /*! @brief copy constructor.
     *
     * the ciopy constructor does _not_ make a copy of heapArray but simply
     * acquires ownership of it.
     * @param[in] heapArray riught hand side.
     * @return ?

     */
    THeapArray(const THeapArray& heapArray) { InitMembers(); *this = heapArray; }

    /*! @brief destructor.
     *
     * removes all elements.
     */
    ~THeapArray() { Clear(); }

    /*! @brief assignment operator
     *
     * The assignment operator does not duplicate a THeapArray object but simply transfers
     * ownership of the underlying memory block from one THeapArray object to another one.
     * (This bahavior is similar to that of the std::auto_ptr class.)
     * @param[in] heapArray right hand side
     */
    THeapArray& operator=(const THeapArray& heapArray);

    /*! @brief removes all elements.
     *
     * deallocates all elements.
     * @return true if successful. false otherwise.
     * @todo documentation to be done.
     */
    void Clear();

    /*! @brief get number of elements.
     *
     * return the number of elements in the vector. this is the number of allocated
     * elements and not necessarily equivalent to the number of assigned elements.
     * @return number of elements.
     */
    size_t GetSize() const { return m_size; }

    /*! @brief set number of elements.
     *
     * makes sure there is room for  size number of elements in the array.
     * @param[in] size number of elements to allocate.
     * @return true if successful. false otherwise.
     */
    void SetSize(size_t size);

    void AppendElement(const T& element);

    void AppendElements(const T* elements, size_t count);

    /*! @brief validate index into array.
     *
     * determines if idx is in the allowed range for this array.
     * @param[in] idx number of element to be accessed.
     * @return true if it is a valid index, false otherwise.
     */
    bool IsValidIndex(size_t idx) const { return idx < m_size; }

    /*! @brief return element.
     *
     * retrieve the element at the index idx.
     * @param[in] idx index into the array.
     * @return const reference to the element at index idx.
     * @todo documentation to be done.
     */
    const T& operator[](size_t idx) const { assert(IsValidIndex(idx)); return m_mem[idx]; }

    /*! @brief return element.
     *
     * retrieve the element at the index idx.
     * @param[in] idx index into the array.
     * @return reference to the element at index idx.
     * @todo documentation to be done.
     */
    T& operator[](size_t idx) { assert(IsValidIndex(idx)); return m_mem[idx]; }

private:
    void InitMembers()
    {
        m_mem = NULL; m_size = 0; m_capacity = 0;
    }

    void EnsureCapacity(size_t capacity);

    T* m_mem;
    size_t m_size;
    size_t m_capacity;
};

template <class T>
THeapArray<T>& THeapArray<T>::operator=(const THeapArray<T>& heapArray)
{
    SetSize(heapArray.GetSize());
    for (size_t i=0; i<m_size; i++)
        (*this)[i] = heapArray[i];

    return *this;
}

template <class T>
void THeapArray<T>::Clear()
{
    if (m_mem != NULL)
    {
        SetSize(0);
        ::HeapFree(::GetProcessHeap(), 0, m_mem);
        m_mem = NULL;
        m_capacity = 0;
    }
}

template <class T>
void THeapArray<T>::SetSize(size_t size)
{
    if (size > m_size)
    {
        EnsureCapacity(size);
        for (size_t i=m_size; i<size; i++)
            new (&m_mem[i]) T;
    }
    else
    {
        for (size_t i=size; i<m_size; i++)
            m_mem[i].~T();
    }

    m_size = size;
}

template <class T>
void THeapArray<T>::AppendElement(const T& element)
{
    if (m_size >= m_capacity)
        EnsureCapacity(m_size * 2 + 1);
    new (&m_mem[m_size++]) T(element);
}

template <class T>
void THeapArray<T>::AppendElements(const T* elements, size_t count)
{
    size_t requiredSize = m_size + count;
    if (requiredSize > m_capacity)
        EnsureCapacity(requiredSize + m_size);
    for (size_t i=0; i<count; i++)
        new (&m_mem[m_size + i]) T(elements[i]);
    m_size = requiredSize;
}

template <class T>
void THeapArray<T>::EnsureCapacity(size_t capacity)
{
    if (capacity > m_capacity)
    {
        T* newMem = (T*)::HeapAlloc(::GetProcessHeap(), 0, capacity * sizeof(T));

        if (m_mem != NULL)
        {
            for (size_t i=0; i<m_size; i++)
            {
                new (&newMem[i]) T(m_mem[i]);
                m_mem[i].~T();
            }

            ::HeapFree(::GetProcessHeap(), 0, m_mem);
        }

        m_mem = newMem;
        m_capacity = capacity;
    }
}

#endif
