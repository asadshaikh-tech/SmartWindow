#ifndef CONFIG_H
#define CONFIG_H

/* ============================================================
 * shared/config/config.h
 *
 * Global, build-time feature toggles consumed by ALL THREE
 * firmware projects (CCU, WindowNode, RoofNode). Not for
 * per-sensor tuning values — those belong in thresholds.h.
 *
 * Owner: repo lead
 * Edited by: team approval required (3/3) — every toggle here
 *            affects all three projects simultaneously
 * Included by: every node's app_main.c, and any component that
 *              needs to branch on a feature flag
 *
 * NOTE — node identity is NOT set here. Which physical unit a
 * given WindowNode build targets (Window 1 vs Window 2) is a
 * per-build concern local to that project (e.g. sdkconfig or a
 * project-local define in WindowNode/main/), not a shared
 * global. This file only holds flags that mean the same thing
 * on every node.
 * ============================================================ */

/* --- Firmware / config versioning ---
 * Reported in CMD_GET_STATUS responses so CCU can tell which
 * build a node is running. Bump on every release. */
#define FIRMWARE_VERSION_MAJOR     0
#define FIRMWARE_VERSION_MINOR     1
#define FIRMWARE_VERSION_PATCH     0

/* Bump this whenever the CMD_SYNC_CONFIGURATION payload SHAPE
 * changes (fields added/removed) — lets a node detect it received
 * a config payload from a CCU build it doesn't understand, rather
 * than silently misreading it. */
#define CONFIG_SCHEMA_VERSION      1

/* --- Debug / development toggles --- */
#define DEBUG_MODE                 1   // 1 = verbose logging enabled, 0 = production
#define ENABLE_LOCAL_FAILSAFE      1   // 1 = node keeps running safety logic locally
                                        // (smoke/rain/limit) if CCU/MQTT is unreachable

/* --- Future features (disabled by default — do not enable
 * until the corresponding component actually exists) --- */
#define ENABLE_OTA                 0   // Firmware-over-MQTT (see docs Future Expansion)
#define ENABLE_MQTT_TLS            0

#endif // CONFIG_H
