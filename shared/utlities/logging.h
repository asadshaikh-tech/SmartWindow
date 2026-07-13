#ifndef LOGGING_H
#define LOGGING_H

/* ============================================================
 * shared/utilities/logging.h
 *
 * Owner: repo lead
 * Edited by: team approval required (3/3)
 * Included by: any .c file in any component that logs
 *
 * This defines the shared severity scale only. Actual ESP_LOG
 * tag-naming convention (e.g. tag = component name in caps) is
 * a convention documented in CONTRIBUTING.md, not enforced here.
 * ============================================================ */

typedef enum
{
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL
} LogLevel_t;

#endif // LOGGING_H
