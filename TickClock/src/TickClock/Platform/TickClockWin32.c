#pragma push_macro("PROJECT_CONFIG")
#define PROJECT_CONFIG 1
#include <TickClock/Base/Internal.h>
#include <Windows.h>

#if defined(PLATFORM_WIN)
static void TickClockStartWin32(TickClock_t* clock) {
	long long tick = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&tick);
	clock->base = 1.0f / tick;
	QueryPerformanceCounter((LARGE_INTEGER*)&clock->last);
}

static void TickClockStopWin32(TickClock_t* clock) {
	QueryPerformanceCounter((LARGE_INTEGER*)&clock->now);
	clock->delta = (((float)(clock->now - clock->last)) * clock->base) * 10000.0f;
	clock->elapsed += clock->delta;
	clock->ticks += clock->delta;
	clock->last = clock->now;
}

void TickClockPlatformStart(TickClock_t* clock) { TickClockStartWin32(clock); }
void TickClockPlatformStop(TickClock_t* clock) { TickClockStartWin32(clock); }

#endif // defined(PLATFORM_WIN)
#pragma pop_macro("PROJECT_CONFIG")