#include "circularbuffer.h"
#include <stdio.h>



void CircularInit(CircularBuffer* cb)
{
  cb -> c = cb -> buffer;
  cb -> p = cb -> buffer;
}

void CircularPut(type data, CircularBuffer* cb)
{
  *(cb -> p) = data;
  if( (cb -> p) < (cb -> buffer + size)) cb -> p += 1;
  else cb -> p = cb -> buffer;
}

type CircularGet(CircularBuffer* cb)
{
  type x;
  x = *(cb -> c);
  if( (cb -> c) < (cb -> buffer + size)) cb -> c += 1;
  else cb -> c = cb -> buffer;
  return x;
}

bool CircularIsFull(const CircularBuffer* cb)
{
  if( (cb -> c - 1) == cb -> p) return true;
  else if(cb -> c == (cb -> buffer) && cb -> p == (cb -> buffer + size)) return true;
  else return false;
}

bool CircularIsEmpty(const CircularBuffer* cb)
{
  if(cb -> c == cb -> p) return true;
  else return false;
}

void CircularEmptyBuff(CircularBuffer* cb)
{
  cb -> c = cb -> buffer;
  cb -> p = cb -> buffer;
}

void CircularDump(const CircularBuffer* cb)
{
  for(int i = 0; i < size; i++)
  {
    printf("%"PRINT_TYPE"\n", *(cb -> buffer + i));
  }
}


int main()
{

    CircularBuffer bufferStruct;

    CircularInit(&bufferStruct);
    CircularPut(4, &bufferStruct);
    CircularPut(2, &bufferStruct);
    CircularPut(1, &bufferStruct);
    CircularPut(9, &bufferStruct);
    CircularPut(40, &bufferStruct);
    CircularPut(4, &bufferStruct);

    CircularDump(&bufferStruct);
    CircularEmptyBuff(&bufferStruct);


}