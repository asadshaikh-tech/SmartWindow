#ifndef PRIORITY_H
#define PRIORITY_H

/* ============================================================
 * shared/types/priority.h
 *
 * Arbitration order for the CCU's decision_engine when multiple
 * conditions compete for control of a window at the same time.
 * Lower numeric value = higher priority = wins the arbitration.
 *
 * Owner: CCU Developer (proposes changes)
 * Edited by: team approval required (3/3)
 * Included by: decision_engine (CCU)
 *
 * PRIORITY_NONE = 0 added for consistency with the zero-sentinel
 * pattern used elsewhere — represents "no override currently
 * active," distinct from PRIORITY_SMOKE being merely lowest-
 * numbered.
 * ============================================================ */

typedef enum
{
    PRIORITY_NONE = 0,
    PRIORITY_SMOKE,                // 1 — highest: fire/smoke safety
    PRIORITY_RAIN,                 // 2
    PRIORITY_MECHANICAL_SAFETY,    // 3 — limit switches / motor protection
    PRIORITY_MANUAL_OVERRIDE,      // 4 — user command
    PRIORITY_COMFORT,              // 5 — indoor temperature/humidity
    PRIORITY_ENERGY_SAVING         // 6 — lowest
} PriorityLevel_t;

#endif // PRIORITY_H
