 #include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


static const int_least32_t treshold = 20;

static int_least32_t values[4000];
static int_least16_t indexes[4000];

typedef struct{
	int_least16_t index;
	int_least16_t values;
	int_least16_t counter;
}str;

static void sort(int_least32_t* values, int_least16_t* indexes, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] < values[j])
			{
				int_least32_t tmp;
				int_least16_t tmp1;

				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp1 = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp1;
			}
		}
	}
}


static void treshold_array(const int_least32_t* values, const int_least16_t* indexes, int_least16_t n, str* array)
{
	int_least16_t i= 0, k = 0;

	for (i = 0; i < n; i++)
	{
		if(values[i] < treshold && (values[i]%2 ==0))
		{

			array[k].index = indexes[i];
			array[k].values = values[i];
			array->counter++;
			k++;
			printf("%d\n", i);
		}
	}
}


void main()
{
	int_least16_t i;
	int_least16_t n;
	printf("Number of elements: ");
	scanf("%"SCNdLEAST16, &n);
	printf("\n");

	str array[4000];
	array->counter = 0;

	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32, &values[i]);
		indexes[i] = i;
		printf("\n");
	}
	sort(values, indexes, n);

	treshold_array(values, indexes, n, array);

	for(i = 0; i < array->counter; i++)
	{
		printf("%"PRIdLEAST32". element strukture ima vrednost:%"PRIdLEAST32", sa indeksom:%"PRIdLEAST32"\n", i, array[i].values, array[i].index);
	}


}
