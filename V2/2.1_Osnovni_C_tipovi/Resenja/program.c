#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


enum tresholds_t
{
	TRESHOLDS_FIRST = 10,
	TRESHOLDS_SECOND,
	TRESHOLDS_THIRD = 20
};


void sort(int_least16_t* values, uint_least16_t* indexes, uint_least16_t  n)
{
	int_fast16_t i;
	int_fast16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] - values[j] < 0)
			{
				int tmp;
				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp;
			}
		}
	}
}


void print(int_least16_t* values, uint_least16_t* indexes, uint_least16_t n)
{
	int_fast16_t i = 0;
	printf("Up to the first treshold: ");
	while (values[i] > TRESHOLDS_THIRD && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	printf("Up to the second treshold: ");
	while (values[i] > TRESHOLDS_SECOND && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	printf("Up to the third treshold: ");
	while (values[i] > TRESHOLDS_FIRST && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
}


void main()
{
	int_least16_t values[30000];
	uint_least16_t indexes[30000];
	uint_fast16_t i;
	uint_least16_t n;
	printf("Number of elements: ");
	scanf("%"SCNuLEAST16"", &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"SCNuFAST16".element: ", i);
		scanf("%"SCNiLEAST16"", &values[i]);
		indexes[i] = i;
		printf("\n");
	}

	sort(values, indexes, n);

	print(values, indexes, n);
}

// koristili smo least jer nam je to najmanje potreban broj bita da predstavimo max 30k indexa i vrednosti niza i time stedeli memoriju, a fast smo koristili da bi optimizovali program 
