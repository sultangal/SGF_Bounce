/*! @file
 * @brief this file is part of the plugin library.
 *
 */

/* ============================================================================= *
 *                                                                               *
 *  Copyright 2008 PEAK software technologies GmbH                               *
 *  All Rights Reserved.                                                         *
 *                                                                               *
 *  This is PROPRIETARY SOURCE CODE of PEAK software technologies GmbH;          *
 *  the contents of this file may not be disclosed to third parties, copied or   *
 *  duplicated in any form, in whole or in part, without the prior written       *
 *  permission of PEAK software technologies GmbH                                *
 *                                                                               *
 * ============================================================================= */

/*  CAUTION:
 *  --------
 *  This file contains no user-modifiable data
 *  Under no circumstances change anything in this file without an
 *  explicit order from an employee of PEAK software technologies GmbH
 *
 */

#if ! defined( EV_PLUGIN_UNDOREDO_H )
#define EV_PLUGIN_UNDOREDO_H

#include "api_functions.h"
#include <vector>

// ---------------------------------------------------------------------
// forward decls
// ---------------------------------------------------------------------


//=========================================================================
// UNDOREDO OBJECT
//=========================================================================
/*! @brief The viz undo/redo manager.
 *
 * This type is provided to define undo-checkpoints from within a plugin.
 */
class UNDOREDO
{
    bool m_bIsInUndoStep;

public:
    /*! @brief Default UNDOREDO constructor.
     * You need to call the Start/Done explicitly, to
     * generate undo/redo checkpoints.
     */
    UNDOREDO()  { m_bIsInUndoStep = false; }

    /*! @brief Construct UNDOREDO-object and Start.
     * This will initialize the UNDOREDO-object and invoke the Start method.
     */
    UNDOREDO(unsigned int iObjectID, const char* undoLabel = NULL) { m_bIsInUndoStep=false; Start(iObjectID, undoLabel); }

    /*! @brief Construct UNDOREDO-object and Start.
     * This will initialize the UNDOREDO-object and invoke the Start method.
     */
    UNDOREDO(const char* undoLabel, std::vector<unsigned int>& objects) { m_bIsInUndoStep=false; Start(undoLabel, objects); }

    /*! @brief UNDOREDO-destructor.
     * This will clean-up the UNDOREDO-object. If there is an open undo-checkpoint,
     * it will be closed, using Done()-method.
     */
    ~UNDOREDO() { Done(); }

public:
    /*! @brief Start a undo-checkpoint.
     * Before modifications are done, a undo-checkpoint need to be
     * defined, do enable viz's undo mechanism.
     * @param iObjectID of object that will be changed.
     * @param undoLable describes the following modifications.
     * @return true if call was successful, false if not.
     */
    bool Start(unsigned int iObjectID, const char* undoLabel = NULL) {
        if (_api__viz_start_undo_step(undoLabel, 1, &iObjectID)) {
            m_bIsInUndoStep = true;
            return true;
        }
        return false;
    }
    /*! @brief Start a undo-checkpoint.
     * Before modifications are done, a undo-checkpoint need to be
     * defined, do enable viz's undo mechanism.
     * @param undoLable describes the following modifications.
     * @param uNumberOfObjects specifies number of objects to be included in the undo-checkpoint.
     * @param ... specifies object-id's of all objects to be included in the undo-checkpoint.
     * @return true if call was successful, false if not.
     */
    bool Start(const char* undoLabel, unsigned int uNumberOfObjects, ...) {
        unsigned int* pObjectIDs = new unsigned int [uNumberOfObjects];
        va_list args;
        va_start(args, uNumberOfObjects);
        for (unsigned int i=0; i<uNumberOfObjects; ++i)
            pObjectIDs[i] = va_arg(args, unsigned int);

        if (_api__viz_start_undo_step(undoLabel, uNumberOfObjects, pObjectIDs)) {
            m_bIsInUndoStep = true;
            delete [] pObjectIDs;
            return true;
        }
        delete [] pObjectIDs;
        return false;
    }
    /*! @brief Start a undo-checkpoint.
     * Before modifications are done, a undo-checkpoint need to be
     * defined, do enable viz's undo mechanism.
     * @param undoLable describes the following modifications.
     * @param uNumberOfObjects specifies number of objects to be included in the undo-checkpoint.
     * @param ... specifies object-id's of all objects to be included in the undo-checkpoint.
     * @return true if call was successful, false if not.
     */
    bool Start(const char* undoLabel, std::vector<unsigned int>& objects) {
        if (objects.empty())
            return false;
        unsigned int& r (objects.at(0));
        if (_api__viz_start_undo_step(undoLabel, (unsigned int)objects.size(), &r)) {
            m_bIsInUndoStep = true;
            return true;
        }
        return false;
    }
    /*! @brief Finalize a undo-checkpoint.
     * After modifications have been done, the undo-checkpoint need
     * to be closed.
     */
    void Done() {
        if (m_bIsInUndoStep) {
            _api__viz_end_undo_step();
            m_bIsInUndoStep = false;
        }
    }
    /*! @brief Cancel a undo-checkpoint.
     * If the undo-checkpoint is obsolete, call Cancel,
     * to get rid of the undo-point.
     */
    void Cancel() {
        if (m_bIsInUndoStep) {
            _api__viz_cancel_undo_step();
            m_bIsInUndoStep = false;
        }
    }
};


#endif // EV_PLUGIN_UNDOREDO_H
