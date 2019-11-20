#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Dominio.h"
#include <string.h>

int mostrarDominio( eDominio* e)
{
    int todoOk = 0;

    if( e != NULL)
    {
        printf("%d %s %d %c\n", e->id, e->dominio, e->anio,e->tipo);
        todoOk = 1;
    }

    return todoOk;
}

eDominio* dominio_new()
{
    eDominio* nuevo = (eDominio*) malloc( sizeof(eDominio));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->dominio, " ");
        nuevo->anio = 0;
        nuevo->tipo = ' ';
    }
    return nuevo;
}

eDominio* dominio_newParametros(char* idStr,char* dominioStr,char* anioStr,char tipo)
{
    eDominio* nuevo = dominio_new();
    int id;
    int anio;

    id = atoi(idStr);
    anio = atoi(anioStr);

    if( nuevo != NULL)
    {
        if(
                dominio_setId(nuevo, id) &&
                dominio_setDominio(nuevo, dominioStr)&&
                dominio_setAnio(nuevo,anio)&&
                dominio_setTipo(nuevo, tipo))
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


int dominio_setId(eDominio* this,int id){

    int todoOk = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int dominio_setDominio(eDominio* this,char* dominio)
{
    int todoOk = 0;
    if( this != NULL && dominio != NULL && strlen(dominio) < 128)
    {
        strcpy(this->dominio, dominio);
        todoOk = 1;
    }
    return todoOk;
}

int dominio_setAnio(eDominio* this,int anio){

    int todoOk = 0;
    if( this != NULL && anio >= 0)
    {
        this->anio = anio;
        todoOk = 1;
    }
    return todoOk;
}

int dominio_setTipo(eDominio* this,char tipo)
{
    int todoOk = 0;
    if( this != NULL && tipo != NULL && (tipo == 'A' || tipo == 'M'))
    {
        this->tipo = tipo;
        todoOk = 1;
    }
    return todoOk;
}

int dominio_getId(eDominio* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int dominio_getDominio(eDominio* this,char* dominio)
{
    int todoOk = 0;

    if( this != NULL && dominio != NULL)
    {
        strcpy(dominio, this->dominio);
        todoOk = 1;
    }
    return todoOk;
}

int dominio_getAnio(eDominio* this,int* anio)
{
    int todoOk = 0;

    if( this != NULL && anio != NULL)
    {
        *anio = this->anio;
        todoOk = 1;
    }
    return todoOk;
}

int dominio_getTipo(eDominio* this,char* tipo)
{
    int todoOk = 0;

    if( this != NULL && tipo != NULL)
    {
        *tipo = this->tipo;
        todoOk = 1;
    }
    return todoOk;
}

int sortByID(void* dominio1, void* dominio2){

int retorno = 0;

if(dominio1 != NULL && dominio2 != NULL){

if(((eDominio*)dominio1)->id > ((eDominio*)dominio2)->id)
{
 retorno =  1;
}
if(((eDominio*)dominio1)->id < ((eDominio*)dominio2)->id)
{
 retorno =  -1;
}

}else{
    return -2;
}
    return retorno;
}

int sortByDominio(void* dominio1, void* dominio2){

    int retorno = -2;

    eDominio* dom1;
    eDominio* dom2;

    dom1 = (eDominio*)dominio1;
    dom2 = (eDominio*)dominio2;

    if(dominio1 != NULL && dominio2 != NULL){

            retorno = strcmp(dom1->dominio, dom2->dominio);

    }
    return retorno;
}

int sortByAnio(void* dominio1, void* dominio2){

int retorno = 0;

if(dominio1 != NULL && dominio2 != NULL){

if(((eDominio*)dominio1)->anio > ((eDominio*)dominio2)->anio)
{
 retorno =  1;
}
if(((eDominio*)dominio1)->anio < ((eDominio*)dominio2)->anio)
{
 retorno =  -1;
}

}else{
    return -2;
}
    return retorno;
}


int sortByTipo(void* dominio1, void* dominio2){

    int retorno = 0;

if(dominio1 != NULL && dominio2 != NULL){

if(((eDominio*)dominio1)->tipo > ((eDominio*)dominio2)->tipo)
{
 retorno =  1;
}
if(((eDominio*)dominio1)->tipo < ((eDominio*)dominio2)->tipo)
{
 retorno =  -1;
}

}else{
    return -2;
}
    return retorno;
}

