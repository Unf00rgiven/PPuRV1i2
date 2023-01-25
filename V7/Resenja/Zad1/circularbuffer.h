#ifndef _CIRCULAR_BUFFER_H_
#define _CIRCULAR_BUFFER_H_

#include <stdbool.h>

#define size 10

typedef int type;
#define PRINT_TYPE "d"

typedef struct{
  type* p;
  type* c;
  type buffer[size];
}CircularBuffer;

void CircularInit(CircularBuffer* cb);

void CircularPut(type data, CircularBuffer* cb);

type CircularGet(CircularBuffer* cb);

bool CircularIsFull(const CircularBuffer* cb);

bool CircularIsEmpty(const CircularBuffer* cb);

void CircularEmptyBuff(CircularBuffer* cb);

void CircularDump(const CircularBuffer* cb);

#endif