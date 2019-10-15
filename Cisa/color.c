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

int cargarDescColor(int id, eColor colores[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == colores[i].id){
            strcpy(desc, colores[i].nombreColor);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void mostrarColor (eColor colores){

    printf("  %d      %10s\n", colores.id, colores.nombreColor);

}


void mostrarColores(eColor colores[], int tam){
    printf(" Id         Color\n\n");
    for(int i=0; i < tam; i++){
        mostrarColor( colores[i]);
    }
    printf("\n");
}
