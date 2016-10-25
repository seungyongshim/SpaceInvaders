#include "logger.hpp"


LogLevel Logger::m_msgLevel = LogLevel::info;

bool Logger::m_isPrint = false;

std::string Logger::GetLabel(LogLevel const & type)
{
  std::string label;
  switch(type)
  {
    case LogLevel::trace:
      label = "trace";
      break;
    case LogLevel::debug:
      label = "debug";
      break;
    case LogLevel::info:
      label = "info";
      break;
    case LogLevel::warning:
      label = "warning";
      break;
    case LogLevel::error:
      label = "error";
      break;
    case LogLevel::fatal:
      label = "fatal";
      break;
  }
  return label;
}
