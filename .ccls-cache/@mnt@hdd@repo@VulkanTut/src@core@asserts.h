#pragma once

#include "../defines.h"

#include <stdlib.h>

#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED
#define debugBreak() __builtin_trap()

KAPI void report_assertion_failure(const char *expression, const char *message,
                                   const char *file, i32 line);

#define KASSERT(expr)                                                          \
  {                                                                            \
    if (expr) {                                                                \
    } else {                                                                   \
      report_assertion_failure(#expr, "", __FILE__, __LINE__);                 \
    }                                                                          \
  }

#define KASSERT_MSG(expr, message)                                             \
  {                                                                            \
    if (expr) {                                                                \
    } else {                                                                   \
      report_assertion_failure(#expr, message, __FILE__, __LINE__);            \
    }                                                                          \
  }

#ifdef _DEBUG
#define KASSERT_DEBUG(expr)                                                    \
  {                                                                            \
    if (expr) {                                                                \
    } else {                                                                   \
      report_assertion_failure(#expr, "", __FILE__, __LINE__);                 \
      debugBreak();                                                            \
    }                                                                          \
  }
#else
#define KASSERT_DEBUG(expr)
#endif

#else
#define KASSERT(expr)
#define KASSERT_MSG(expr, message)
#define KASSERT_DEBUG(expr)
#endif
