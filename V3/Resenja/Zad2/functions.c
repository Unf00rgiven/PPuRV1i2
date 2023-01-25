#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "functionEg.h"

int main(void)
{
	// Recursive functions
	printf("\n");
	printf("Reqursive Fibonacci number 14 is %"PRIdLEAST32"\n", fibonacci(14));
	printf("Fibonacci number 14 is %"PRIdLEAST32"\n", fibonacci_notreqursive(14));
	printf("Factorial of 10 is %"PRIdLEAST32"\n", factorial(10));
	printf("Reqursive Factorial number 10 is %"PRIdLEAST32"\n", factorial_notreqursive(10));

	return EXIT_SUCCESS;
}
