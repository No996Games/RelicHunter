//
// Created by Chuyang Zhou on 1/4/2021.
//

#include "Log.h"

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::Init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_CoreLogger = spdlog::stdout_color_mt("GameEngine");
    /* Set the log level to Trace */
    s_CoreLogger->set_level(spdlog::level::trace);

    s_ClientLogger = spdlog::stdout_color_mt("RelicHunter");
    /* Set the log level to Trace */
    s_ClientLogger->set_level(spdlog::level::trace);

}
