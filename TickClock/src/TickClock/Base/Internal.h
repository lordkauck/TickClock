#ifndef TICKCLOCK_INTERNAL_H
#define TICKCLOCK_INTERNAL_H

#pragma push_macro("PROJECT_CONFIG")
#define PROJECT_CONFIG 1
#include <Project/ProjectBase.h>

typedef struct CTickClock {
	long long last;
	long long now;
	long long counter;
	long long clock;
	float base;
	float elapsed;
	float ticks;
	float delta;
}TickClock_t;

extern TickClock_t* g_Clock;

void ITickClockInit(TickClock_t* clock);
void ITickClockShutdown(TickClock_t* clock);
void ITickClockStart(TickClock_t* clock);
void ITickClockStop(TickClock_t* clock);
void ITickClockReset(TickClock_t* clock);
void TickClockPlatformStart(TickClock_t* clock);
void TickClockPlatformStop(TickClock_t* clock);
float ITickClockElapsed(TickClock_t* clock);
float ITickClockDelta(TickClock_t* clock);
long long ITickClockFps(TickClock_t* clock);

#pragma pop_macro("PROJECT_CONFIG")
#endif // TICKCLOCK_INTERNAL_H
