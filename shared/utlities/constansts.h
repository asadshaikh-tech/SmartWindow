#ifndef CONSTANTS_H
#define CONSTANTS_H

/* ============================================================
 * shared/utilities/constants.h
 *
 * Universal constants that are structural/formatting in nature —
 * NOT behavior tuning values (those belong in
 * shared/config/thresholds.h instead). Rule of thumb: if
 * changing this value is a calibration decision, it's a
 * threshold; if changing it is a buffer-overflow risk, it's a
 * constant.
 *
 * Owner: repo lead
 * Edited by: team approval required (3/3) — buffer sizes in
 *            particular affect memory layout across components
 * Included by: mqtt_client, command_parser (all nodes), any
 *              component doing serial/debug I/O
 * ============================================================ */

/* --- Debug console (USB serial monitor, not device-to-device comms) --- */
#define DEBUG_UART_BAUD_RATE        115200

/* --- MQTT payload sizing --- */
#define MAX_MQTT_TOPIC_LEN          64
#define MAX_MQTT_PAYLOAD_LEN        256

/* --- Misc string buffer sizes --- */
#define MAX_NODE_NAME_LEN           16
#define FIRMWARE_VERSION_STRING_LEN 16

#endif // CONSTANTS_H
