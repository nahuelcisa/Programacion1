#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "comida.h"
void mostrarComidas(eComidas comidas[], int tam){
    printf(" Id         Descripcion     precio\n\n");
    for(int i=0; i < tam; i++){
        mostrarComida( comidas[i]);
    }
    printf("\n");
}

void mostrarComida (eComidas comidas){

    printf("  %d    %10s        %4.2f\n", comidas.id, comidas.descripcion,comidas.precio);

}

int cargarDescComida(int id, eComidas comidas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == comidas[i].id){
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
