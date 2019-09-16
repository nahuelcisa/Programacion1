#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 5
#define COLUMNAS 20

void mostrarNombres( char mat[][20], int filas);
void ordenarNombres( char mat[][20], int filas);

int main()
{

    char nombres[FILAS][COLUMNAS] =
    { "Juan",
      "Manuel",
      "Alicia",
      "Sofia",
      "Claudia"
    };
    char auxCad[100];

    /*
    for(int i=0; i < FILAS; i++){
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(auxCad);

        while(strlen(auxCad) >19){
            printf("Nombre demasiado largo. Maximo 19 caracteres\nReingrese nombre: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(nombres[i], auxCad);
    }*/
    printf("Nombres desordenados\n");
    mostrarNombres(nombres, FILAS);

    ordenarNombres(nombres, FILAS);

    printf("Nombres ordenados\n");
    mostrarNombres(nombres, FILAS);

    return 0;
}

void mostrarNombres( char mat[][20], int filas){
    for(int i=0; i < filas; i++){
        printf("%s\n", mat[i]);
    }
    printf("\n\n");
}
void ordenarNombres( char mat[][20], int filas){
char aux[20];

    for(int i=0; i < filas -1; i++){
        for( int j = i +1; j < filas; j++){
            if(strcmp(mat[i], mat[j]) > 0){

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);

            }
        }
    }



}
