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

void mostrarServicio (eServicio servicios){

    printf("  %d      %10s      %.2f\n", servicios.id, servicios.descripcion,servicios.precio);

}

void mostrarServicios (eServicio servicios[], int tam){
    printf(" Id         Servicio        Precio\n\n");
    for(int i=0; i < tam; i++){
        mostrarServicio( servicios[i]);
    }
    printf("\n");
}

int cargarDescServicio(int id, eServicio servicios[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == servicios[i].id){
            strcpy(desc, servicios[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int buscarIdServicio(int id, eServicio servicios[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( servicios[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
