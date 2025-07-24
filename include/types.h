#ifndef TYPES_H
#define TYPES_H

#include<stdint.h>

typedef enum { 
    false, 
    true
} bool;

typedef uint8_t byte;   // shorthand for 8-bit unsigned integer
typedef uint16_t word;  // shorthand for 16-bit unsigned integer
typedef uint32_t dword; // shorthand for 32-bit unsigned integer

#endif