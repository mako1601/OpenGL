#ifndef LOG_H
#define LOG_H

#include <spdlog/spdlog.h>

#ifdef NDEBUG
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#define LOG_CRIT(...)
#define LOG_SETPATTERN(...)
#else
#define LOG_INFO(...)		spdlog::info(__VA_ARGS__)
#define LOG_WARN(...)		spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...)		spdlog::error(__VA_ARGS__)
#define LOG_CRITTICAL(...)	spdlog::critical(__VA_ARGS__)
#define LOG_SETPATTERN(...)	spdlog::set_pattern(__VA_ARGS__)
#endif

#endif //LOG_H