#ifndef THRESHOLDS_H
#define THRESHOLDS_H

/* ============================================================
 * shared/config/thresholds.h
 *
 * Owner: CCU Developer (Dev 2) — primary, since decision_engine
 *        is the main consumer of most values here.
 * Edited by: ANY developer may tune the numeric value of a
 *            constant that their own component consumes (e.g.
 *            Dev 1 adjusting SMOKE_DETECTION_THRESHOLD after
 *            bench-testing the MQ2) — no team approval needed
 *            for value changes. Adding, removing, or renaming a
 *            constant DOES need a heads-up to the team, since
 *            other components may reference it by name.
 * Included by: window_controller (WindowNode), decision_engine
 *              (CCU), individual sensor components on any node
 *
 * These are compiled-in DEFAULTS. CMD_SYNC_CONFIGURATION
 * (shared/protocol/commands.h) lets CCU override live values at
 * runtime without a firmware reflash — this file is the fallback
 * a node uses if it has never received that command, or has lost
 * connection to CCU and is running on local fail-safe logic.
 *
 * ALL VALUES BELOW ARE PLACEHOLDERS. Replace during hardware
 * calibration/bench testing — do not treat as final.
 * ============================================================ */

/* --- Indoor climate (DHT22, Window Node) — auto-mode comfort logic --- */
#define TEMP_OPEN_THRESHOLD_C          28.0f   // open window above this temp
#define TEMP_CLOSE_THRESHOLD_C         24.0f   // close window below this temp
#define HUMIDITY_OPEN_THRESHOLD_PCT    70.0f   // open window above this humidity
#define HUMIDITY_CLOSE_THRESHOLD_PCT   40.0f   // close window below this humidity

/* --- Smoke (MQ2, Window Node) --- */
#define SMOKE_DETECTION_THRESHOLD      2000    // raw ADC counts (0-4095, 12-bit)
#define SMOKE_DEBOUNCE_COUNT           3       // consecutive readings before triggering

/* --- Rain (FC-37, Rooftop Node) --- */
#define RAIN_DETECTION_THRESHOLD       1500    // raw ADC counts (0-4095, 12-bit)
#define RAIN_DEBOUNCE_COUNT            3       // consecutive readings before triggering

/* --- Limit switches (Window Node) --- */
#define LIMIT_SWITCH_DEBOUNCE_MS       50

/* --- Motor safety (BTS7960 + worm gear motor, Window Node) --- */
#define MOTOR_SAFETY_TIMEOUT_MS        15000   // force-stop if neither limit
                                                // switch reached within this time

/* --- Connectivity / liveness (all nodes) --- */
#define WIFI_RECONNECT_INTERVAL_MS     5000
#define MQTT_RECONNECT_INTERVAL_MS     5000
#define HEARTBEAT_INTERVAL_MS          10000
#define NODE_OFFLINE_TIMEOUT_MS        30000   // CCU's node_registry marks a
                                                // node NODE_OFFLINE if no
                                                // message received within this

#endif // THRESHOLDS_H
