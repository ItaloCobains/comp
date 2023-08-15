lib

make .hpp

make .cpp

g++ -c HelloWorldLib.cpp -o HelloWorldLib.o
ar rcs libHelloWorldLib.a HelloWorldLib.o

# With C

```h
#ifndef HELLOLIB_H
#define HELLOLIB_H

#ifdef __cplusplus
extern "C" {
#endif

void printHello();

#ifdef __cplusplus
}
#endif

#endif // HELLOLIB_H

```

```c
#include <stdio.h>
#include "HelloLib.h"

void printHello() {
    printf("Hello from C library!\n");
}

```

gcc -c HelloLib.c -o HelloLib.o
ar rcs libHelloLib.a HelloLib.o
