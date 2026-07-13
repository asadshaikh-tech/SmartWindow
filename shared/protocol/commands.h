#ifndef COMMANDS_H
#define COMMANDS_H

/* ============================================================
 * shared/protocol/commands.h
 *
 * Commands exchanged between CCU and the Window Nodes / Rooftop
 * Node over MQTT (see shared/protocol/protocol.h for topics).
 *
 * Owner: CCU Developer (proposes changes)
 * Edited by: team approval required (3/3) — this is a frozen
 *            contract consumed by every node's command_parser.
 * Included by: command_parser (all nodes), command_dispatcher (CCU)
 *
 * FROZEN as of Day 1 lock. Do not reorder or remove existing
 * values after lock — only append new ones at the end, so any
 * node still running older firmware can't silently misinterpret
 * a shifted value.
 *
 * OPEN DECISION (resolve before Day 1 lock): is this enum sent
 * over MQTT as a JSON string (e.g. "command":"CMD_OPEN_WINDOW")
 * or as a raw integer? If JSON, reordering below is harmless.
 * If raw integer, treat the numeric values as permanently fixed.
 * ============================================================ */

typedef enum
{
    CMD_NONE = 0,

    /* --- Motion commands --- */
    CMD_OPEN_WINDOW,
    CMD_CLOSE_WINDOW,
    CMD_STOP_WINDOW,

    /* --- Status / liveness --- */
    CMD_GET_STATUS,
    CMD_PING,
    CMD_ACK,

    /* --- Mode control --- */
    CMD_ENABLE_AUTO_MODE,
    CMD_ENABLE_MANUAL_MODE,

    /* --- Maintenance --- */
    CMD_RESET_NODE,          // Soft reset: re-init internal state/components
                              // without a power cycle. If your team does not
                              // need a distinct soft-reset path, drop this and
                              // keep only CMD_REBOOT_NODE — decide before lock.
    CMD_REBOOT_NODE,         // Hard reset: esp_restart()
    CMD_SYNC_CONFIGURATION,  // Push updated thresholds/settings to node
    CMD_CALIBRATE_LIMITS,    // Learn open/close end positions

    /* --- Safety overrides (highest priority, bypass normal state machine) --- */
    CMD_EMERGENCY_CLOSE,
    CMD_EMERGENCY_OPEN

} Command_t;

#endif // COMMANDS_H
