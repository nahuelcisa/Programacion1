#include <stdio.h>
#include <stdlib.h>

void sumarV2(int a, int b);

int main()
{
    int num1;
    int num2;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);

    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    sumarV2(num1, num2);

    return 0;
}

void sumarV2(int a, int b)
{

    int rta;

    rta = a + b;

    printf("La suma es %d\n\n", rta);

}
