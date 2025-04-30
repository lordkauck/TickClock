#include "Internal.h"
#include "TickClock.h"

TickClock_t* g_Clock = 0;

void TickClockInit(void) { ITickClockInit(g_Clock); }
void TickClockShutdown(void) { ITickClockShutdown(g_Clock); }

void TickClockStart(void) { ITickClockStart(g_Clock); }
void TickClockStop(void) { ITickClockStop(g_Clock); }
void TickClockReset(void) { ITickClockReset(g_Clock); }
float TickClockElapsed(void) { return ITickClockElapsed(g_Clock); }
float TickClockDelta(void) { return ITickClockDelta(g_Clock); } 
long long TickClockFps(void) { return ITickClockFps(g_Clock); }
