#include <stdio.h>

int main()
{
    int i;
    int x;
    int y;

    for(i = 0; i < 5; i++)
    {
        // lokalne promenljive ne uticu na prethodne x i y
        int x = 0;
        static int y = 0;
        // static govori da je samo jednom inicijalizuje na 0
        printf("x=%d, y=%d\n", x++, y++);
    }

    printf("\nx=%d, y%d\n", x++, y++);

    return 0;
}