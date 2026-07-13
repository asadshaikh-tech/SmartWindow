#ifndef COMMON_H
#define COMMON_H

/* ============================================================
 * shared/utilities/common.h
 *
 * Tiny, generic macros with ZERO domain meaning. If a macro
 * knows anything about windows, sensors, or MQTT, it does not
 * belong here — put it in the component that owns that concept.
 *
 * Owner: repo lead
 * Edited by: adding a new generic macro just needs a heads-up to
 *            the team (so people know it exists instead of
 *            redefining their own copy) — not a full 3/3 review
 * Included by: any component that needs a generic helper
 * ============================================================ */

#define MIN(a, b)            (((a) < (b)) ? (a) : (b))
#define MAX(a, b)            (((a) > (b)) ? (a) : (b))
#define CLAMP(x, lo, hi)     (MIN(MAX((x), (lo)), (hi)))

#define ARRAY_SIZE(arr)      (sizeof(arr) / sizeof((arr)[0]))

#define UNUSED(x)            (void)(x)   // silence unused-parameter warnings

#endif // COMMON_H
