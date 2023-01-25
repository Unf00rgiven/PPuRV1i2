#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


static const int_least32_t treshold1 = 20;
static const int_least32_t treshold2 = 30;
static const int_least32_t treshold3 = 40;


typedef struct _s
{
	int_least32_t value;
	int_least16_t index;
} val_ind_struct_t;

static val_ind_struct_t struct_array[4000];

int compare (const void * a, const void * b)
{
  int data1 = *(int *)a, data2 = *(int *)b;
  if(data1 < data2) // a < b
    return 1;
  else if(data1 == data2) // a == b
    return 0;
  else
    return -1;  // a > b
}


static void bubble_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str_array[i].value < str_array[j].value)
			{
				val_ind_struct_t tmp;

				tmp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = tmp;
			}
		}
	}
}


static void quick_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	// sort using qsort standard function
	qsort(str_array, n, sizeof(val_ind_struct_t), compare);
}

static void (*fptr[])(val_ind_struct_t* struct_array, int_least16_t n) = {bubble_sort, quick_sort};

static void print(const val_ind_struct_t* str_array, int_least16_t n, int_fast8_t treshold_index)
{
	int_least16_t i = 0;
	int_least32_t treshold;
	int_least32_t tr_array[3] = {treshold1, treshold2, treshold3};
	treshold = tr_array[treshold_index - 1];
	printf("Up to the %"PRIdFAST8". treshold: ", treshold_index);

	while (str_array[i].value > treshold && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", str_array[i].value, str_array[i].index);
		i++;
	}
	printf("\n");
}


void main()
{
	int_least16_t i;
	int_least16_t n;
	int_fast8_t treshold_index;
	int_fast8_t sort_index;
	printf("Number of elements: ");
	scanf("%"SCNdLEAST16, &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32, &(struct_array[i].value));
		struct_array[i].index = i;
		printf("\n");
	}
	printf("Trashold you want to use (1,2 or 3): ");
	scanf("%"SCNdFAST8, &treshold_index);
	printf("\n");
	printf("Sorting algorithm you want to use (1- bubble, 2- quick): ");
	scanf("%"SCNdFAST8, &sort_index);
	printf("\n");

	fptr[sort_index - 1](struct_array, n);

	print(struct_array, n, treshold_index);
}
