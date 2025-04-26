#include "logger.h"
#include "assert.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

b8 initialize_logging(){
  return TRUE;
}

void shutdown_logging(){

}

void log_output(log_level level, const char *message, ...){
  const char *level_strings[] = {
    "[FATAL]: ",
    "[ERROR]: ",
    "[WARN]: ",
    "[INFO]: ",
    "[DEBUG]: ",
    "[TRACE]: ",
  };

  b8 is_error = level < 2;

  char temp[32000];
  memset(temp, 0, sizeof(temp));

  va_list arg_ptr;
  va_start(arg_ptr, message);
  vsnprintf(temp, 32000, message, arg_ptr);
  va_end(arg_ptr);

  char output_message[32000];
  sprintf(output_message, "%s%s\n", level_strings[level], temp);

  printf("%s", output_message);
}

KAPI void report_assertion_failure(const char *expression, const char *message,
                                   const char *file, i32 line) {
  log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file: %s, line: %d\n", expression, message, file, line);
}
