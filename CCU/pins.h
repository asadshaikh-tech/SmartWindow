#ifndef PINS_H
#define PINS_H

#include "driver/gpio.h"

/* ============================================================
 * CCU (Central Control Unit) — GPIO Pin Map
 * Location in repo: CCU/main/pins.h
 * Owner: Developer 2 (CCU Firmware)
 * ============================================================ */

/* --- Status LED --- */
#define CCU_LED_PIN           GPIO_NUM_2    // NOTE: boot-strapping pin.
                                             // Safe for an LED as long as it
                                             // is only driven AFTER boot and
                                             // nothing else pulls it during reset.

/* --- Button (manual override / config trigger) --- */
#define CCU_BUTTON_PIN        GPIO_NUM_4    // Digital input

#endif // PINS_H
