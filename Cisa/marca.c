#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"


void mostrarMarca (eMarca marcas){

    printf("  %d      %10s\n", marcas.id, marcas.descripcion);

}

void mostrarMarcas (eMarca marcas[], int tam){
    printf(" Id         Marca\n\n");
    for(int i=0; i < tam; i++){
        mostrarMarca( marcas[i]);
    }
    printf("\n");
}

int cargarDescMarca(int id, eMarca marcas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == marcas[i].id){
            strcpy(desc, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
