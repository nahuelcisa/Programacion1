#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cachorro.h"
#include "LinkedList.h"
#include "controller.h"


eCachorro* cachorro_new()
{
    eCachorro* nuevo = (eCachorro*) malloc( sizeof(eCachorro));
    if(nuevo != NULL)
    {
        nuevo->id_Cachorro = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->dias = 0;
        strcpy(nuevo->raza, " ");
        strcpy(nuevo->reservado, " ");
        //strcpy(nuevo->genero, " ");
        nuevo->genero = ' ';

    }
    return nuevo;
}

eCachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* dias,char* raza,char* reservado, char genero)
{
    eCachorro* nuevo = cachorro_new();

    int id;
    int vida;


    id = atoi(idStr);
    vida = atoi(dias);

    if( nuevo != NULL)
    {
        if(cachorro_setId(nuevo, id) &&
                cachorro_setNombre(nuevo, nombreStr)&&
                cachorro_setDias(nuevo,vida)&&
                cachorro_setRaza(nuevo, raza)&&
                cachorro_setReservado(nuevo,reservado)&&
                cachorro_setGenero(nuevo,genero))
        {
            // printf("Empleado creado correctamente\n");
        }
        else
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}

int cachorro_setId(eCachorro* this,int id){

    int todoOk = 0;
    if(this != NULL && id >= 0)
    {
        this->id_Cachorro = id;
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_setNombre(eCachorro* this,char* nombre)
{
    int todoOk = 0;
    if( this != NULL && nombre != NULL && strlen(nombre) < 20)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_setDias(eCachorro* this,int dias){

    int todoOk = 0;
    if(this != NULL && dias >= 0)
    {
        this->dias = dias;
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_setRaza(eCachorro* this,char* raza)
{
    int todoOk = 0;
    if( this != NULL && raza != NULL && strlen(raza) < 20)
    {
        strcpy(this->raza, raza);
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_setReservado(eCachorro* this,char* reservado)
{
    int todoOk = 0;
    if( this != NULL && reservado != NULL && strlen(reservado) < 20)
    {
        strcpy(this->reservado, reservado);
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_setGenero(eCachorro* this,char genero)
{
    int todoOk = 0;

    if( this != NULL)
    {
       // strcpy(this->genero,genero);
        this->genero = genero;
        todoOk = 1;
    }

    return todoOk;
}

int mostrarCachorro(eCachorro* e)
{
    int todoOk = 0;
    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[5];
    char genero;

    if( e != NULL)
    {
        cachorro_getId(e,&id);
        cachorro_getNombre(e,nombre);
        cachorro_getDias(e,&dias);
        cachorro_getRaza(e,raza);
        cachorro_getReservado(e,reservado);
        cachorro_getGenero(e,&genero);
        printf("%2d %10s %2d %10s %2s %c\n",id,nombre, dias,raza,reservado,genero);
        todoOk = 1;
    }

    return todoOk;
}

int listarCachorros(LinkedList* lista)
{
    int todoOk = 0;
    eCachorro* aux;
    int flag = 0;
    if(lista != NULL)
    {

        printf("Id   Nombre   Dias   Raza   Reservado   Genero\n\n");
        for( int i=0; i < ll_len(lista); i++)
        {
            aux = (eCachorro*) ll_get(lista,i);
            mostrarCachorro(aux);
            flag = 1;
        }
        if(flag == 0){
            printf("No hay cachorros cargados para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int cachorro_getId(eCachorro* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id_Cachorro;
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_getNombre(eCachorro* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_getDias(eCachorro* this,int* dias)
{
    int todoOk = 0;

    if( this != NULL && dias != NULL)
    {
        *dias = this->dias;
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_getRaza(eCachorro* this,char* raza)
{
    int todoOk = 0;

    if( this != NULL && raza != NULL)
    {
        strcpy(raza, this->raza);
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_getReservado(eCachorro* this,char* reservado)
{
    int todoOk = 0;

    if( this != NULL && reservado != NULL)
    {
        strcpy(reservado, this->reservado);
        todoOk = 1;
    }
    return todoOk;
}

int cachorro_getGenero(eCachorro* this,char* genero)
{
    int todoOk = 0;

    if( this != NULL && genero != NULL)
    {
        //strcpy(genero, this->genero);
        genero[0] = this->genero;
        todoOk = 1;
    }
    return todoOk;
}

int mostrarCallejeros(LinkedList* lista){

    int todoOk = 0;
    LinkedList* lista2 = ll_newLinkedList();

    if(lista != NULL){
        lista2 = ll_filter(lista,filtroCallejeros);
    }
    if(listarCachorros(lista2)){
        todoOk = 1;
    }
    return todoOk;
}






