#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x = 10;
   int* p = &x;
   int* q = p;

   *p = 15;



   printf("%d\n", x);

    return 0;
}
