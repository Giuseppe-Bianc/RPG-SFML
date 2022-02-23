#include "Timer.h"
Timer::Timer() {
	M_startPoint = high_resolutionClock::now();
}

Timer::~Timer() { stop(); }

void Timer::stop() {
	dlong duration = time_point_cast<microseconds>(high_resolutionClock::now()).time_since_epoch().count() - time_point_cast<microseconds>(M_startPoint).time_since_epoch().count();
	double ms = duration * 0.001;

	cout << duration << " us (" << ms << "ms)" << endl;
}

shared_ptr<logger> Log::s_CoreLogger;
shared_ptr<logger> Log::s_UserLogger;


void Log::Init() {
	set_pattern("%^[%T] %n: %v%$");
	s_CoreLogger = stdout_color_mt("ENGINE");
	s_CoreLogger->set_level(level::trace);

	s_UserLogger = stdout_color_mt("APP");
	s_UserLogger->set_level(level::trace);
}

