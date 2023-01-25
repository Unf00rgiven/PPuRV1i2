#include "functionEg.h"


int_least32_t factorial(int_least16_t n)
{
	if(n == 0) return 1;
	else
	{
		return (n*factorial(n-1));
	}
}

int_least32_t factorial_notreqursive(int_least16_t n)
{
	if(n == 0) return 1;

	int_least32_t f = 1;
	while(n > 0)
	{
		f *= n;
		n--;
	}
	return f;
}

int_least32_t fibonacci(int_least16_t n)
{
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return (fibonacci(n-1) + fibonacci(n-2));
}

int_least32_t fibonacci_notreqursive(int_least16_t n)
{
	int_least32_t f[n+1];
	int i;

	f[0] = 0;
	f[1] = 1;

	for (i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}
