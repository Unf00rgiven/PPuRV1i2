#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

void printBinary(uint8_t* number);
void printSignedChar(int32_t num);


int main()
{
	printf("================================\n");
	printf("Exercise3\n");
	printf("================================\n");

	int i = 0;
	int32_t intNumber= 1;

	printSignedChar(-2);

	return 1;
}


void printBinary(uint8_t* number)
{
	uint8_t small = *number;
	uint8_t mask = 0x80;
	int i = 0;

	for (i = 8; i > 0; i--)
	{
		uint8_t tmp = 0;
		tmp = (small & mask) != 0;
		printf("%d", tmp);
		mask = mask >> 1;
	}
}


void printSignedChar(int32_t num)
{
	int i = 0;
	int32_t b = 0;
	int8_t a = num;

	b = a;

	printf("a = 0x%x\t(signed) c = %d\t(unsigned) c = %u\n", (uint8_t)a, a, (uint8_t)a);
	printf("(binary)\t");
	printBinary((uint8_t*)&a);

	printf("\n\n");

	uint8_t* part = (uint8_t*)&b;

	printf("b = 0x%x\t(signed) b = %d\t(unsigned) b = %u\n", b, b, (uint32_t)b);
	printf("(binary)\t");

	//---------------------------------------------------------
	//This is where you should print 32bit integer b
	//---------------------------------------------------------
	// uzmemo adresu lokacije od 32 bitne b i kastujemo je da pokazuje po 8 bita lokacije , zatim se krecemo kroz bajte i krecemo se kroz njih little end-ian princip
	for(i = 0; i < 4; i++)
	{
		printBinary((uint8_t*)&b + 3-i);
	}


	// drugi nacin sa printovanjem pomocu maske i siftovanja
	uint32_t mask = 0xff000000;
	uint32_t print= 0x00000000;

	for(i = 3; i >= 0; i--)
	{
		print = mask & b;
		print >>= (8*i);
		printBinary((uint8_t*)&print);
		mask >>= 8;
	}

	printf("\n");
}
