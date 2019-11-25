#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* numeros;
    int* auxiliar;

    numeros = (int*) malloc( sizeof(int)* 5);
    if(numeros == NULL){
        exit(EXIT_FAILURE);
    }


    for( int i=0; i < 5; i++){
        printf("Ingrese un numero: ");
        scanf("%d", numeros + i);
    }


    for( int i=0; i < 5; i++){
        printf("%d ", *(numeros + i));

    }
    printf("\n\n");



    auxiliar = (int*) realloc(numeros, sizeof(int) *10);

    if( auxiliar == NULL){
            printf("No se pudo agrandar el array");


    }else{
        numeros = auxiliar;

     for( int i=5; i < 10; i++){
        printf("Ingrese un numero: ");
        scanf("%d", numeros + i);
    }


    for( int i=0; i < 10; i++){
        printf("%d ", *(numeros + i));

    }
    printf("\n\n");
    }

    numeros = (int*) realloc(numeros, sizeof(int)*4);

 for( int i=0; i < 10; i++){
        printf("%d ", *(numeros + i));

    }
    printf("\n\n");


    free(numeros);
    return 0;
}
