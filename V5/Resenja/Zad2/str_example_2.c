#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct _my_struct
{
	char text[20];
	uint_least16_t num;
} my_struct;

int main()
{
	my_struct ms;
	char strBuf[100] = "This text is too long for struct member text";
	ms.num = 55555;

	// Error situation (stack problem)
	printf("\nCopying longer string to shorter\n");
	// posto imamo 20 mesta kopiramo do 19. indexa to radi strncpy inace pokusava da upise vise stvari nego sto ima prostora
	strncpy(ms.text, strBuf, 19);
	printf("my_struct text=%s, num=%"PRIuLEAST16"\n", ms.text, ms.num);


	// Check if strings are equal
	printf("\nComparing two strings\n");
	char str1[20] = "This is text 1";
	char str2[20] = "This is text 2";
	// <0 ako je drugi vec, >0 ako je prvi veci, = 0 ako je jednako 0
	if (strcmp(str1, str2) == 0)
	{
		printf("Strings are equal\n");
	}
	else
	{
		printf("Strings are not equal\n");
	}

	// Tokenizing
	printf("\nTokenizing string by space delimiter\n");
	char* s = "one two three four five";
	// ne mozemo da menjamo string literal, tj on je const zato kod puca
	// menjamo ga tako sto dodamo char s[] =""
	printf("string for tokenizing: \"%s\" \n", s);
	// ovde puca
	char* token = strtok(s, " ");
	printf("after 1st step, string is: \"%s\" \n", s);

	printf("token: %s\n", token);
	while (token != NULL)
	{
	    token = strtok(NULL, " ");
	    printf("token: %s\n", token);
	}

	return 1;
}
