#include "ceasar.h"

#include <string.h>
#include <assert.h>
#include <ctype.h>

#define CEASAR_KEY 26
#define LC_FIRST 'a'
#define LC_LAST	 'z'
#define UC_FIRST 'A'
#define UC_LAST  'Z'

const char key = CEASAR_KEY;

static char encryptChar(char ch, int_fast16_t shift)
{
	return ((ch - 'a') + shift) % key + 'a';
}

static char decryptChar(char ch)
{
	return (ch % key + 'a');
}

static uint8_t isLower(char letter)
{
	if(letter >= LC_FIRST && letter <= LC_LAST) {
		return 1;
	} else {
		return 0;
	}
}

static uint8_t isUpper(char letter)
{
	if(letter >= UC_FIRST && letter <= UC_LAST) {
		return 1;
	} else {
		return 0;
	}
}

void ceasarEncrypt(const char* in, char* out, int_fast16_t shift)
{
	int i = 0;
	int inLength = strlen(in);

	assert(out != NULL);

	for (i = 0; i < inLength; i++)
	{
		char c = in[i];
		if (isLower(c) || isUpper(c))
		{
			c = tolower(c);
			out[i] = encryptChar(c, shift);
		}
		else
		{
			out[i] = in[i];
		}
	}
	out[i] = '\0';
}

void ceasarDecrypt(const char* in, char* out, int_fast16_t shift)
{
	int i = 0;
	int inLength = strlen(in);

	assert(out != NULL);

	for (i = 0; i < inLength; i++)
	{
		char c = in[i];
		if (isLower(c) || isUpper(c))
		{
			c = tolower(c);
			if ((c = c - 'a' - shift) < 0)
			{
				c += key;
			}
			out[i] = decryptChar(c);
		}
		else
		{
			out[i] = in[i];
		}
	}
	out[i] = '\0';
}
