#ifndef ERRORS_H
#define ERRORS_H

/* ============================================================
 * shared/types/errors.h
 *
 * Every module returns one of these.
 *
 * Owner: CCU Developer (proposes changes)
 * Edited by: team approval required (3/3)
 * Included by: every component in every node that can raise or
 *              report an error
 *
 * NOTE: ERR_FAILSAFE_ACTIVE was removed — failsafe is a system
 * MODE (see shared/types/states.h, SystemMode_t.MODE_FAILSAFE),
 * not an error in itself. Report the error that CAUSED failsafe
 * entry instead (e.g. ERR_CCU_DISCONNECTED, ERR_WIFI_DISCONNECTED).
 * ============================================================ */

typedef enum
{
    ERR_NONE = 0,

    /* --- Sensor errors --- */
    ERR_SENSOR_FAILURE,
    ERR_DHT_TIMEOUT,
    ERR_DHT_CHECKSUM,
    ERR_SMOKE_SENSOR_FAILURE,
    ERR_RAIN_SENSOR_FAILURE,
    ERR_LIMIT_SWITCH_OPEN_FAILURE,
    ERR_LIMIT_SWITCH_CLOSE_FAILURE,

    /* --- Motor errors --- */
    ERR_MOTOR_DRIVER_FAILURE,
    ERR_MOTOR_STALL,
    ERR_MOTOR_TIMEOUT,

    /* --- Connectivity errors --- */
    ERR_WIFI_DISCONNECTED,
    ERR_MQTT_DISCONNECTED,
    ERR_CCU_DISCONNECTED,

    /* --- Protocol / packet errors --- */
    ERR_PACKET_INVALID,
    ERR_PACKET_TIMEOUT,
    ERR_UNKNOWN_COMMAND,

    /* --- System errors --- */
    ERR_LOW_VOLTAGE,
    ERR_CONFIGURATION,
    ERR_SYSTEM_UNKNOWN

} Error_t;

#endif // ERRORS_H
