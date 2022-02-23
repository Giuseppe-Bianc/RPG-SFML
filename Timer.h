#pragma once

#include <iostream>
#include <chrono>
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#pragma warning(pop)


using namespace std;
using namespace spdlog;
using namespace chrono;

typedef long long dlong;

using high_resolutionTime = time_point<high_resolution_clock>; 
using high_resolutionClock = high_resolution_clock;


class Timer {
public:
	Timer();
	~Timer();
	void stop();

private:
	high_resolutionTime M_startPoint;
};

class Log {
public:
	static void Init();

	inline static shared_ptr<logger>& GetCoreLogger() { return s_CoreLogger; }
	inline static shared_ptr<logger>& GetUserLogger() { return s_UserLogger; }
private:
	static shared_ptr<logger> s_CoreLogger;
	static shared_ptr<logger> s_UserLogger;
};

#define TIME_IT(x) { Timer timer; x;}

#define CORE_TRACE(...) Log::GetCoreLogger()->trace(__VA_ARGS__)
#define APP_TRACE(...)  Log::GetUserLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)  Log::GetCoreLogger()->info(__VA_ARGS__)
#define APP_INFO(...)   Log::GetUserLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)  Log::GetCoreLogger()->warn(__VA_ARGS__)
#define APP_WARN(...)   Log::GetUserLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) Log::GetCoreLogger()->error(__VA_ARGS__)
#define APP_ERROR(...)  Log::GetUserLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define APP_FATAL(...)  Log::GetUserLogger()->fatal(__VA_ARGS__)

