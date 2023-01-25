#ifndef _CEASAR_H
#define _CEASAR_H

#include <stdint.h>

void ceasarEncrypt(const char* in, char* out, int_fast16_t shift);
void ceasarDecrypt(const char* in, char* out, int_fast16_t shift);

#endif
