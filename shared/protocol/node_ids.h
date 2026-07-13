#ifndef NODE_IDS_H
#define NODE_IDS_H

/* ============================================================
 * shared/protocol/node_ids.h
 *
 * Fixed identity assigned to each physical node.
 *
 * Owner: CCU Developer (proposes changes)
 * Edited by: never changes after Day 1 lock — this is a hard
 *            identity table, not a tunable.
 * Included by: node_registry (CCU), every node's app_main.c
 *              (for self-identification)
 *
 * NODE_ID_UNKNOWN = 0 is deliberate: a zero-initialized or
 * corrupted buffer must never be mistaken for a valid node
 * (e.g. silently resolving to NODE_CCU).
 * ============================================================ */

typedef enum
{
    NODE_ID_UNKNOWN = 0,
    NODE_CCU,
    NODE_WINDOW_1,
    NODE_WINDOW_2,
    NODE_ROOF
} NodeID_t;

#endif // NODE_IDS_H
