//
// Created by Chuyang Zhou on 1/4/2021.
//

#ifndef RELICHUNTER_LOG_H
#define RELICHUNTER_LOG_H

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class Log {
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

    inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

/* Macro for Game Engine Core */
#define GE_CORE_TRACE(...)  ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)   ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)   ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...)  ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...)  ::Log::GetCoreLogger()->fatal(__VA_ARGS__)

/* Macro for Client */
#define GE_TRACE(...)  ::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)   ::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)   ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...)  ::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...)  ::Log::GetClientLogger()->fatal(__VA_ARGS__)


#endif //RELICHUNTER_LOG_H
