# __TickClock Overview__
**A high resolution clock library written in C.**

## __Technical information__:
- Does not use exceptions
- Does not depend on other libraries outside of native libraries
- Does not require CRT
- Easy to implement into a class wrapper

__**Currently only supports Windows platform.**__
  
## __How to use TickClock__:
Include the proper `TickClock.lib` library file in your projects dependencies.
If you are making an x86 build, include the library from the `x86` directory, likewise, include the library from the `x64` directory if you are making an x64 build.
Then include the `TickClock.h` header file in your project. 

### __Example code below__:
```cpp
#include <stdio.h>
#include "TickClock.h"

int main(int argc, char* argv[]) {
    TickClockInit();
    TickClockStart();

    // @TODO: Some code here

    TickClockStop();

    printf("Elapsed time: %.2f", TickClockElapsed());
    TickClockShutdown();
    return 0;
}
```

Example code for a simple class wrapper for TickClock:
```cpp
class CTickClock {
public:
  CTickClock(void) { TickClockInit(); }
  ~CTickClock() { TickClockShutdown(); }

  void reset(void) { TickClockReset(); }
  void start(void) { TickClockStart(); }
  void stop(void) { TickClockStop(); }
  float elapsed(void) { return TickClockElapsed(); }
  float delta(void) { return TickClockDelta(); }
  long long fps(void) { return TickClockFps(); }
};
```

## Build from source:

**Windows (Visual Studio)**:

Download the source code, open up the viusal studio solution file and build it from there.

