#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int_least8_t foo();
// da bi bila globalna promenljiva moramo ovde da je deklarisemo
// inace moramo da saljemo x po referenci da bi se odnosilo na istu vreednost to jest referencu
// inace ce biti lokalne promenljive
// int_least_t x; a 14 red obrisati
// takodje se brisu argumenti iz foo

int_least8_t x;

int main(void)
{
	printf("Local variable scope\n");
	//int_least8_t x;

	x = 42;
	foo(x);
	printf("After calling foo: x = %d\n", x);

	return EXIT_SUCCESS;
}

int_least8_t foo()
{
	x = 101;
	printf("Inside foo: x = %d\n", x);
	return x;
}
