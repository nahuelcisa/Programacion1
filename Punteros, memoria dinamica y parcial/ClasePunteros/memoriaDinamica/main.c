#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;

    p = (int*) malloc( sizeof(int));

    if( p == NULL)
    {
        exit(EXIT_FAILURE);
    }

    *p = 38;

    printf("%d\n", *p);


    int x;

    x = 38;
    printf("%d\n", x);


    return 0;
}
