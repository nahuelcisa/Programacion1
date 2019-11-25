#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);

int main()
{
    int x = 10;
    int y = 7;

    printf("En main x: %d  y: %d\n\n", x, y);

    swap( &x, &y);

    printf("En main x: %d  y: %d\n\n", x, y);
    return 0;
}

void swap(int* a, int* b){
// a guarda la direccion de memoria de x de main
// b guarda la direccion de memoria de y de main
int aux;

aux = *a;
  *a = *b;
  *b = aux;
    printf(" En swap x: %d  y: %d\n\n", *a, *b);
}
