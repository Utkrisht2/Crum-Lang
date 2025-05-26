
#ifndef INCLUDE_LOG_H
#define INCLUDE_LOG_H

#include <iostream>
#include <stdio.h>
#include <string>

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define CRITICAL 3
#define ERROR 4

#ifndef LOGLEVEL
#define LOGLEVEL WARNING
#endif

class Log {
public:
  bool operator&(std::ostream &stream) {
    stream << std::endl;
    return true;
  }
};

inline std::string log_level_to_str(const int log_level) {
  char buf[12];
  std::string str = "";

  switch (log_level) {
  case DEBUG:
    str = "[DEBUG]";
    break;
  case INFO:
    str = "[INFO]";
    break;
  case WARNING:
    str = "[WARNING]";
    break;
  case ERROR:
    str = "[ERROR]";
    break;
  case CRITICAL:
    str = "[CRITICAL]";
    break;
  default:
    break;
  }

  sprintf(buf, "%-9s ", str.c_str());
  return buf;
}

/* If the minimum log level requirement is satisfied then prints the log
message. This works because the & operator has lower precedence than the
<< operator, therefore the stream output is evaluated before the Log
class is initialised. */
#define LOG(log_level)                                                         \
  log_level >= LOGLEVEL &&Log() & std::cerr << log_level_to_str(log_level)     \
                                            << ": "

#endif
