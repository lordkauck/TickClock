# TickClock
**A high resolution clock library written in C.**

**Currently only supports Windows platform.**

## How to use TickClock:
Include the proper `TickClock.lib` library file in your projects dependencies.
If you are making an x86 build, include the library from the `x86` directory, likewise, include the library from the `x64` directory if you are making an x64 build.
Then include the `TickClock.h` header file in your project. 
### Example code below:
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


## To build from source:
Download the source code, open up the viusal studio solution file and build it from there.

