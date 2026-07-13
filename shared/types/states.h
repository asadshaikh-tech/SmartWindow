#ifndef STATES_H
#define STATES_H

/* ============================================================
 * shared/types/states.h
 *
 * Owner: CCU Developer (proposes changes)
 * Edited by: team approval required (3/3)
 * Included by: window_controller (WindowNode), decision_engine
 *              (CCU), node_registry (CCU)
 * ============================================================ */

/* Physical condition of the window. Public, cross-node summary
 * — this is what CCU sees. (Internal motor driver state lives
 * in WindowNode/components/motor/include/motor.h instead —
 * that detail never needs to leave the node.) */
typedef enum
{
    WINDOW_UNKNOWN = 0,
    WINDOW_OPEN,
    WINDOW_CLOSED,
    WINDOW_OPENING,
    WINDOW_CLOSING,
    WINDOW_STOPPED,
    WINDOW_ERROR
} WindowState_t;

/* System control mode — separate from window position.
 *
 * MODE_UNINITIALIZED = 0 is deliberate: a freshly booted node
 * that has not yet received CMD_SYNC_CONFIGURATION should NOT
 * silently default into running full automatic motor control
 * on stale/default thresholds. Application logic (added later)
 * should treat MODE_UNINITIALIZED as "hold position, do nothing
 * until configured," not as an alias for MODE_AUTO. */
typedef enum
{
    MODE_UNINITIALIZED = 0,
    MODE_AUTO,
    MODE_MANUAL,
    MODE_FAILSAFE
} SystemMode_t;

#endif // STATES_H
