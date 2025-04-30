#ifndef TICKCLOCK_H
#define TICKCLOCK_H

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)

	void TickClockInit(void);
	void TickClockShutdown(void);
	void TickClockStart(void);
	void TickClockStop(void);
	void TickClockReset(void);
	float TickClockElapsed(void);
	float TickClockDelta(void);
	long long TickClockFps(void);
#if defined(__cplusplus)
}
#endif // defined(__cplusplus

#endif // TICKCLOCK_H