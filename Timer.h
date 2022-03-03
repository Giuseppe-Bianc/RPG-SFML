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

using dlong = long long;

using high_resolutionTime = time_point<high_resolution_clock>;
using high_resolutionClock = high_resolution_clock;

struct STime {
	dlong duration = 0;
	double ms = 0;
};

const STime getTime();

class Timer {
public:
	explicit Timer(bool fromClass);
	~Timer();
	void stop();
private:
	high_resolutionTime M_startPoint;
	bool m_fromClass = true;
};

class Log {
public:
	static void Init();

	inline static shared_ptr<logger>& GetCoreLogger() { return s_CoreLogger; }
	inline static shared_ptr<logger>& GetUserLogger() { return s_UserLogger; }
	inline static shared_ptr<logger>& GetUserBLogger() { return s_UserBLogger; }
private:
	static shared_ptr<logger> s_CoreLogger;
	static shared_ptr<logger> s_UserLogger;
	static shared_ptr<logger> s_UserBLogger;
};

#define TIME_IT(x) { Timer timer(true); x;}
#define TIME_ITSNL(x) { Timer timer(false); x;}

#define CORE_TRACE(...) Log::GetCoreLogger()->trace(__VA_ARGS__)
#define APP_TRACE(...)  Log::GetUserLogger()->trace(__VA_ARGS__)
#define USER_TRACE(...) Log::GetUserBLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)  Log::GetCoreLogger()->info(__VA_ARGS__)
#define APP_INFO(...)   Log::GetUserLogger()->info(__VA_ARGS__)
#define USER_INFO(...)  Log::GetUserBLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)  Log::GetCoreLogger()->warn(__VA_ARGS__)
#define APP_WARN(...)   Log::GetUserLogger()->warn(__VA_ARGS__)
#define USER_WARN(...)  Log::GetUserBLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) Log::GetCoreLogger()->error(__VA_ARGS__)
#define APP_ERROR(...)  Log::GetUserLogger()->error(__VA_ARGS__)
#define USER_ERROR(...) Log::GetUserBLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define APP_FATAL(...)  Log::GetUserLogger()->fatal(__VA_ARGS__)
#define USER_FATAL(...) Log::GetUserBLogger()->fatal(__VA_ARGS__)

#define CORE_TIMESN_TRACE(x,...) TIME_ITSNL(x) Log::GetCoreLogger()->trace(__VA_ARGS__)
#define APP_TIMESN_TRACE(x,...)  TIME_ITSNL(x) Log::GetUserLogger()->trace(__VA_ARGS__)
#define USER_TIMESN_TRACE(x,...) TIME_ITSNL(x) Log::GetUserBLogger()->trace(__VA_ARGS__)
#define CORE_TIMESN_INFO(x,...)  TIME_ITSNL(x) Log::GetCoreLogger()->info(__VA_ARGS__)
#define APP_TIMESN_INFO(x,...)   TIME_ITSNL(x) Log::GetUserLogger()->info(__VA_ARGS__)
#define USER_TIMESN_INFO(x,...)  TIME_ITSNL(x) Log::GetUserBLogger()->info(__VA_ARGS__)
#define CORE_TIMESN_WARN(x,...)  TIME_ITSNL(x) Log::GetCoreLogger()->warn(__VA_ARGS__)
#define APP_TIMESN_WARN(x,...)   TIME_ITSNL(x) Log::GetUserLogger()->warn(__VA_ARGS__)
#define USER_TIMESN_WARN(x,...)  TIME_ITSNL(x) Log::GetUserBLogger()->warn(__VA_ARGS__)
#define CORE_TIMESN_ERROR(x,...) TIME_ITSNL(x) Log::GetCoreLogger()->error(__VA_ARGS__)
#define APP_TIMESN_ERROR(x,...)  TIME_ITSNL(x) Log::GetUserLogger()->error(__VA_ARGS__)
#define USER_TIMESN_ERROR(x,...) TIME_ITSNL(x) Log::GetUserBLogger()->error(__VA_ARGS__)
#define CORE_TIMESN_FATAL(x,...) TIME_ITSNL(x) Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define APP_TIMESN_FATAL(x,...)  TIME_ITSNL(x) Log::GetUserLogger()->fatal(__VA_ARGS__)
#define USER_TIMESN_FATAL(x,...) TIME_ITSNL(x) Log::GetUserBLogger()->fatal(__VA_ARGS__)

