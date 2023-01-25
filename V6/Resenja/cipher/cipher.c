#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ceasar.h"
#include "rot13.h"

#define CEASAR_SHIFT  3

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
