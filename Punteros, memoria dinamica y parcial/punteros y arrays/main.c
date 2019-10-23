#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numeros[]= { 3,2,7,8,5};

   printf("Ingrese un numero: ");
   scanf("%d", numeros + 3);

    for(int i=0; i < 5; i++){
   printf("%d\n", *(numeros + i));
    }
    return 0;
}
