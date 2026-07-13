#ifndef PINS_H
#define PINS_H

#include "driver/gpio.h"

/* ============================================================
 * Rooftop Node — GPIO Pin Map
 * Location in repo: RooftopNode/main/pins.h
 * Owner: Developer 3 (PCB Design + Rooftop Node Firmware)
 * ============================================================ */

/* --- DHT22 (outdoor temperature/humidity) --- */
#define DHT_PIN               GPIO_NUM_18   // Stable digital pin, one-wire timing

/* --- FC-37 Rain Sensor --- */
#define RAIN_SENSOR1_PIN      GPIO_NUM_34   // ADC1_CH6, input-only pin
#define RAIN_SENSOR2_PIN      GPIO_NUM_35   // ADC1_CH7, input-only pin
#define RAIN_DIGITAL_PIN      GPIO_NUM_25   // Digital threshold output

#endif // PINS_H
