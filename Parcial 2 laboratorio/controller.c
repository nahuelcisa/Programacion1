#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cachorro.h"
#include "controller.h"


int menu(void){

    int opcion;

    printf("*****       Menu De Inicio      *****\n\n");
    printf("1. Cargar archivo.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Filtrar menores de 45 dias.\n");
    printf("4. Filtrar machos.\n");
    printf("5. Generar listado de callejeros\n");
    printf("6. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int cargarArchivo(LinkedList* lista, char* path){

    int todoOk = 0;
    FILE* f;
    char buffer[6][100];
    int cant;
    eCachorro* aux = NULL;


    if(lista != NULL && path != NULL){

        f = fopen(path, "r");

        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return todoOk;
        }

    fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);
        while(!feof(f))
        {
            cant = fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);

        if(cant == 6){

            aux = cachorro_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5][0]);
            if( aux != NULL)
                {
                    ll_add(lista,aux);

                }
            }
            else
            {
                break;
            }
        }

        todoOk = 1;


    }
    return todoOk;
}

int filtroMenores(void* elemento){

    int todoOk = 0;

    eCachorro* cach;
    cach = (eCachorro*)elemento;
    int dias;
    cachorro_getDias(cach,&dias);

    if(dias >= 45){
        todoOk = 1;
    }
    return todoOk;
}

int controller_saveAsText(char* path, LinkedList* e)
{

    int todoOk = 0;
    int cant;
    FILE* f;
    eCachorro* aux = NULL;


    if(e!= NULL && path != NULL){

        f = fopen(path,"w");
        if(f == NULL){
            return todoOk;
        }

        fprintf(f,"ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero\n");
        for(int i = 0; i < ll_len(e); i++){
            aux = ll_get(e,i);

            cant = fprintf(f,"%2d %10s %2d %10s %2s %c\n",aux->id_Cachorro,aux->nombre,aux->dias,aux->raza,aux->reservado,aux->genero);
            if(cant < 1){
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

int archivoMayores(LinkedList* lista){

    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(lista,filtroMenores);

    if(controller_saveAsText("mayores45.csv",lista2)){
        todoOk = 1;
    }

        return todoOk;
}

int filtroMachos(void* elemento){

    int todoOk = 0;
    eCachorro* cach;
    cach = (eCachorro*)elemento;
    char genero;
    cachorro_getGenero(cach,&genero);

    if(genero != 'M'){
        todoOk = 1;
    }
    return todoOk;
}

int archivosNoMachos(LinkedList* lista){

    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(lista,filtroMachos);

    if(controller_saveAsText("CachorrosHembras.csv",lista2)){
        todoOk = 1;
    }

        return todoOk;
}

int filtroCallejeros(void* elemento){

    int todoOk = 0;
    eCachorro* cach;
    cach = (eCachorro*)elemento;
    char raza[20];
    cachorro_getRaza(cach,raza);
    //char a[20] = "Callejeros";

    if(strcmp(raza,"Callejero") == 0){
        todoOk = 1;
    }
    return todoOk;
}

