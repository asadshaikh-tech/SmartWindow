#ifndef PROTOCOL_H
#define PROTOCOL_H

/* ============================================================
 * shared/protocol/protocol.h
 *
 * MQTT topic map. Locked names — never rename after Day 1.
 * Adding a new topic later is safe; renaming or removing an
 * existing one breaks every node still running old firmware.
 *
 * Owner: CCU Developer (proposes changes)
 * Edited by: team approval required (3/3)
 * Included by: mqtt_client (all nodes)
 *
 * OPEN DECISION (resolve before Day 1 lock): payload format for
 * every topic below — plain JSON (recommended: cJSON ships with
 * ESP-IDF, easy to debug with mosquitto_sub) vs raw packed binary.
 * This file only defines topic names, not payload structure.
 * ============================================================ */

#define TOPIC_CCU_STATUS         "ccu/status"
#define TOPIC_CCU_HEARTBEAT      "ccu/heartbeat"

#define TOPIC_WINDOW1_STATUS     "window1/status"
#define TOPIC_WINDOW1_COMMAND    "window1/command"

#define TOPIC_WINDOW2_STATUS     "window2/status"
#define TOPIC_WINDOW2_COMMAND    "window2/command"

#define TOPIC_ROOF_STATUS        "roof/status"
#define TOPIC_ROOF_COMMAND       "roof/command"   // added — Rooftop Node's
                                                    // command_parser needs an
                                                    // inbound topic too (e.g.
                                                    // CMD_SYNC_CONFIGURATION,
                                                    // CMD_PING)

#define TOPIC_SYSTEM_LOG         "system/log"
#define TOPIC_SYSTEM_ERROR       "system/error"

#endif // PROTOCOL_H
