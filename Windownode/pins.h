#ifndef PINS_H
#define PINS_H

#include "driver/gpio.h"

/* ============================================================
 * Window Node — GPIO Pin Map
 * Location in repo: WindowNode/main/pins.h
 * Owner: Developer 1 (Window Node Firmware)
 * Used for both physical Window Node 1 and Window Node 2 —
 * node identity is set via shared/protocol/node_ids.h, not by
 * forking this file.
 *
 * IMPORTANT: Confirm ESP32 module variant before relying on
 * GPIO16/17 — these pins are reserved for PSRAM on WROVER
 * modules. Free to use as shown below only on WROOM modules
 * (no PSRAM).
 * ============================================================ */

/* --- DHT22 (indoor temperature/humidity) --- */
#define DHT_PIN              GPIO_NUM_18   // Stable digital pin, one-wire timing

/* --- MQ2 Smoke Sensor --- */
#define MQ2_PIN               GPIO_NUM_34   // ADC1_CH6, input-only pin

/* --- Limit Switches --- */
#define LIMIT_OPEN_PIN        GPIO_NUM_25   // Digital input
#define LIMIT_CLOSE_PIN       GPIO_NUM_26   // Digital input

/* --- BTS7960 Motor Driver --- */
#define MOTOR_RPWM_PIN        GPIO_NUM_16   // PWM capable — confirm not WROVER/PSRAM pin
#define MOTOR_LPWM_PIN        GPIO_NUM_17   // PWM capable — confirm not WROVER/PSRAM pin
#define MOTOR_REN_PIN         GPIO_NUM_27   // Digital output
#define MOTOR_LEN_PIN         GPIO_NUM_14   // Digital output

/* --- Status LED (optional) --- */
#define STATUS_LED_PIN        GPIO_NUM_23   // Output

/* ============================================================
 * Reserved — do not assign without updating this file AND
 * docs/pin-maps/window-node.md
 * ============================================================ */
// GPIO_NUM_21   // Future I2C SDA
// GPIO_NUM_22   // Future I2C SCL
// GPIO_NUM_32   // Future sensor
// GPIO_NUM_33   // Future sensor
// GPIO_NUM_35   // Spare ADC (input-only)
// GPIO_NUM_36   // Spare ADC (input-only)
// GPIO_NUM_39   // Spare ADC (input-only)

#endif // PINS_H
