#include "Timer.h"
Timer::Timer(bool fromClass) {
	M_startPoint = high_resolutionClock::now();
	m_fromClass = fromClass;
}

Timer::~Timer() { stop(); }

STime stime = {};

void Timer::stop() {
	if (m_fromClass) {
		dlong duration = time_point_cast<microseconds>(high_resolutionClock::now()).time_since_epoch().count() - time_point_cast<microseconds>(M_startPoint).time_since_epoch().count();
		double ms = duration * 0.001;
			cout << duration << " us (" << ms << "ms)" << endl;
	} else {
		stime.duration = time_point_cast<microseconds>(high_resolutionClock::now()).time_since_epoch().count() - time_point_cast<microseconds>(M_startPoint).time_since_epoch().count();
		stime.ms = stime.duration * 0.001;
	}

}

const STime getTime(){
	return stime;
}

shared_ptr<logger> Log::s_CoreLogger;
shared_ptr<logger> Log::s_UserLogger;
shared_ptr<logger> Log::s_UserBLogger;


void Log::Init() {
	set_pattern("%^[%T] %n: %v%$");
	s_CoreLogger = stdout_color_mt("ENGINE");
	s_CoreLogger->set_level(level::trace);

	s_UserLogger = stdout_color_mt("APP");
	s_UserLogger->set_level(level::trace);

	set_pattern("%^%n: %v%$");
	s_UserLogger = stdout_color_mt("GERMINY");
	s_UserLogger->set_level(level::trace);
}

