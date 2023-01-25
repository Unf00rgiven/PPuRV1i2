#include <stddef.h>
#include <assert.h>

#include "rot13.h"
#include "ceasar.h"


#define ROT13 13

void rot13Encrypt(const char* in, char* out)
{
	assert(out != NULL);
	ceasarEncrypt(in, out, ROT13);
}

void rot13Decrypt(const char* in, char* out)
{
	assert(out != NULL);
	ceasarDecrypt(in, out, ROT13);
}