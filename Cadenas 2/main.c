#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarNombres(char mat [] [20]);

int main()
{
    char nombres [5] [20];
    //5 = filas, 20 = caracteres.

    for(int i = 0; i < TAM ; i++){
    printf("Ingrese un nombre: ");
    fflush(stdin);
    gets(nombres[i]);
    }

    for(int i = 0; i < TAM ; i++){

        printf("%s\n",nombres[i]);
    }
    printf("\n\n");

    return 0;
}
