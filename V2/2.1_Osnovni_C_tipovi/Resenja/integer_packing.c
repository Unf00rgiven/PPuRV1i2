#include <stdio.h>

// ukoliko prosirujemo broj na vise bita ako je negativan dodajemo mu jedinice sa leve a ako je pozitivan nule
// zato stavljamo masku da bi ponistili jedinice kod broja kojeg ne siftujemo
// bitske manipulacije se rade u unsigned al moze da radi

int main(void)
{
	printf("================================\n");
	printf("Exercise2\n");
	printf("================================\n");

	int high = 0xFFFFEEEE;
	int low = 0xDDDDCCCC;
	long long big = 0LL;
	long long lowMask = 0x00000000FFFFFFFFLL;

	big = high;
	printf("added high : %llX\n", big);
	big = big << 32;
	printf("shifted by 32 : %llX\n", big);
	big += lowMask & low;
	printf("added low %llX\n", big);

	return 0;
}
