```c++
const char *input_string = "sua_string_aqui"; // Substitua pela string desejada
size_t input_length = strlen(input_string);
unsigned long long int hash_value;

calculate_bitwise_hash(input_string, input_length, &hash_value);

std::cout << "Valor inteiro do hash: " << hash_value << std::endl;
```

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
