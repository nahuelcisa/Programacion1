#include <stdio.h>
#include <stdlib.h>

void sumarV3( void );

int main()
{
    sumarV3();

    return 0;
}

void sumarV3(void){

    int num1;
    int num2;
    int resultado;



    printf("Ingrese un numero: ");
    scanf("%d", &num1);

    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado = num1 + num2;

    printf("La suma es %d\n\n", resultado);



}


