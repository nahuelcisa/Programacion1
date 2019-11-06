#include <stdio.h>
#include <stdlib.h>

int calcular( int a, int b, int (*pFunc)(int, int));
int sumar(int x, int y);
int restar(int x, int y);
int multiplicar(int x, int y);

int main()
{
    int resultado;

    //resultado = calcular(5,7, sumar());

   // printf("El resultado del calculo es %d\n", resultado);

    resultado = calcular(5,7, multiplicar);

    printf("El resultado del calculo es %d\n", resultado);




    return 0;
}


int sumar( int x, int y){

    return x+y;
}

int restar( int x, int y){

    return x-y;
}

int multiplicar( int x, int y){

    return x*y;
}

int calcular(int a, int b, int(*pFunc)(int, int)){

int rta;

        rta = pFunc(a, b);

return rta;
}
