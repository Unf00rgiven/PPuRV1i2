#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <ctype.h>

#define CEASAR_SHIFT  3
#define LC_FIRST 'a'
#define LC_LAST	 'z'
#define UC_FIRST 'A'
#define UC_LAST  'Z'
#define CEASAR_KEY 26
#define ROT13 13

const char key = CEASAR_KEY;

char encryptChar(char ch, int_fast16_t shift)
{
	return ((ch - 'a') + shift) % key + 'a';
}

char decryptChar(char ch)
{
	return (ch % key + 'a');
}

uint8_t isLower(char letter)
{
	if(letter >= LC_FIRST && letter <= LC_LAST) {
		return 1;
	} else {
		return 0;
	}
}

uint8_t isUpper(char letter)
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

int main(void)
{
	char in[100] = "the QUICK brown FOX jumps over THE lazy DOG";
	char encrypted[100];
	char decrypted[100];

	printf("Ceasar cipher (shift %d) :\n", CEASAR_SHIFT);
	ceasarEncrypt(in, encrypted, CEASAR_SHIFT);
	printf("Original: %s\nencrypted: %s\n", in, encrypted);
	ceasarDecrypt(encrypted, decrypted, CEASAR_SHIFT);
	printf("decrypted: %s\n", decrypted);
	printf("\n");

	strcpy(encrypted,"");
	strcpy(decrypted,"");
	printf("ROT13:\n");
	rot13Encrypt(in, encrypted);
	printf("Original: %s\nencrypted: %s\n", in, encrypted);
	rot13Decrypt(encrypted, decrypted);
	printf("decrypted: %s\n", decrypted);
	printf("\n");

	return EXIT_SUCCESS;
}
