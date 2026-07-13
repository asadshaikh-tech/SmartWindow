#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include "node_ids.h"
#include "sensor_types.h"
#include "errors.h"
#include "states.h"

/* ============================================================
 * shared/types/types.h
 *
 * Struct field layouts used to exchange data between nodes and
 * CCU. Field names/types only — no functions, no serialization
 * code. How these get turned into bytes (JSON vs packed binary)
 * is the same OPEN DECISION flagged in protocol.h/commands.h;
 * these structs describe the SHAPE either way.
 *
 * Owner: joint (CCU Developer proposes, all review)
 * Edited by: team approval required (3/3)
 * Included by: command_parser (all nodes), decision_engine (CCU),
 *              any component publishing/receiving MQTT payloads
 * ============================================================ */

/* Common header every message carries, regardless of topic —
 * lets the receiver identify sender and freshness before even
 * looking at the payload body. */
typedef struct
{
    NodeID_t node_id;
    uint32_t timestamp;      // seconds since node boot — epoch/NTP sync TBD
} MessageHeader_t;

/* One sensor reading. Used for individual sensor values inside a
 * larger status payload (a node reports several of these at once). */
typedef struct
{
    SensorType_t sensor_type;
    float value;
    Error_t status;           // ERR_NONE if the reading is valid
} SensorReading_t;

/* Full status payload a Window Node or Rooftop Node publishes to
 * its <node>/status topic. */
typedef struct
{
    MessageHeader_t header;
    WindowState_t window_state;   // meaningless for RoofNode — leave WINDOW_UNKNOWN
    SystemMode_t mode;
    Error_t last_error;
    uint32_t uptime_seconds;
    // Individual SensorReading_t values are expected to accompany
    // this in the actual payload — exact array/field encoding is
    // part of the JSON-vs-binary decision, not fixed here yet.
} NodeStatusReport_t;

#endif // TYPES_H
