#include <stdio.h>
#include <stdlib.h>

int sumarV4( void);

int main()
{
    int rta;

    rta = sumarV4();

    printf("La suma es %d\n\n", rta);

    return 0;
}

int sumarV4( void){

    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);

    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado = num1 + num2;

    return resultado;
}
