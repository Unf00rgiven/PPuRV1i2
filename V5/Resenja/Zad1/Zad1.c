#include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int_least16_t string_lenght(char* array)
{
    int_least16_t i = 0;
    while(array[i] != '\0')
    {
        i++;
    }
    return i;
}

void stringTrim(char* str)
{
    int_least16_t i = 0, lenght = 0, j = 0;

    while(str[i] == ' ') i++;
    lenght = string_lenght(str) - 1;
    for(j = i; j <= lenght; j++)
    {
        str[j - i] = str[j];
    }

    while(str[lenght] == ' ')
    {
        lenght--;
    }

    str[lenght+1] = '\0';

}

uint8_t extractSubstring(const char* inStr, char* outStr, uint_least32_t beginning, uint_least32_t end);
{

}

int main()
{
    /* 1. zadatak
    int_least16_t i = 0;
    char* array = (char*)malloc(sizeof(char));
    printf("Unesite rec ili recenicu: ");
    scanf("%s", array);
    i = string_lenght(array);
    printf("Broj karaktera je: %"PRIdLEAST16"\n", i);*/

    char string[] = "  Ognjen  ";
    // 2. zadatak
    stringTrim(string);
    printf("Trimovan string:%s.\n", string);


}