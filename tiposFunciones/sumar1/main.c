#include <stdio.h>
#include <stdlib.h>

int sumarV1(int a, int b);

int main()
{
    int resultado;
    int num1;
    int num2;

     printf("Ingrese un numero: ");
    scanf("%d", &num1);

    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

   resultado =  sumarV1(num1, num2);

   printf("La suma es %d\n\n", resultado);

    return 0;
}

int sumarV1(int num1, int num2){

    int resultado;

    resultado = num1 + num2;

    return resultado;

}
