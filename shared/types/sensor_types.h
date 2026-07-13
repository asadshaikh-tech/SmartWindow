#ifndef SENSOR_TYPES_H
#define SENSOR_TYPES_H

/* ============================================================
 * shared/types/sensor_types.h
 *
 * Owner: joint (covers both WindowNode sensors AND Rooftop
 *        Node sensors — not solely a Window Developer file)
 * Edited by: team approval required (3/3)
 * Included by: CCU (decision_engine, command_parser), WindowNode
 *              sensor components, RooftopNode sensor components
 *
 * SENSOR_UNKNOWN = 0 is deliberate — same zero-sentinel reasoning
 * as NodeID_t and Error_t.
 * ============================================================ */

typedef enum
{
    SENSOR_UNKNOWN = 0,
    SENSOR_DHT22,
    SENSOR_SMOKE,
    SENSOR_RAIN_1,
    SENSOR_RAIN_2,
    SENSOR_LIMIT_OPEN,
    SENSOR_LIMIT_CLOSE
} SensorType_t;

#endif // SENSOR_TYPES_H
