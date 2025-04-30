#include "Internal.h"
#include <stdlib.h>

void ITickClockInit(TickClock_t* clock) { clock = (TickClock_t*)calloc(1, sizeof(TickClock_t)); }
void ITickClockShutdown(TickClock_t* clock) { if (!clock) return; free(clock); }

void ITickClockReset(TickClock_t* clock) {
	clock->last = 0;
	clock->now = 0;
	clock->counter = 0;
	clock->clock = 0;
	clock->base = 0.0f;
	clock->elapsed = 0.0f;
	clock->ticks = 0.0f;
	clock->delta = 0.0f;
}

void ITickClockStart(TickClock_t* clock) { TickClockPlatformStart(clock); }

void ITickClockStop(TickClock_t* clock) {
	TickClockPlatformStop(clock);

	++clock->clock;
	if (clock->ticks >= 1.0f) {
		clock->counter = clock->clock;
		clock->clock = 0;
		clock->ticks = 0.0f;
	}
}

float ITickClockElapsed(TickClock_t* clock) { return clock->elapsed; } 
float ITickClockDelta(TickClock_t* clock) { return clock->delta; } 
long long ITickClockFps(TickClock_t* clock) { return clock->clock; }