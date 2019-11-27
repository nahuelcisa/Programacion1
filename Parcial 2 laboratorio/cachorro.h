#ifndef CACHORRO_H_INCLUDED
#define CACHORRO_H_INCLUDED
#include "LinkedList.h"

typedef struct{

    int id_Cachorro;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[5];
    char genero;
}eCachorro;

#endif // CACHORRO_H_INCLUDED
eCachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* dias,char* raza,char* reservado, char genero);
eCachorro* cachorro_new();
int cachorro_setId(eCachorro* this,int id);
int cachorro_setNombre(eCachorro* this,char* nombre);
int cachorro_setDias(eCachorro* this,int dias);
int cachorro_setRaza(eCachorro* this,char* raza);
int cachorro_setReservado(eCachorro* this,char* reservado);
int cachorro_setGenero(eCachorro* this,char genero);
int mostrarCachorro(eCachorro* e);
int listarCachorros(LinkedList* lista);
int cachorro_getId(eCachorro* this,int* id);
int cachorro_getNombre(eCachorro* this,char* nombre);
int cachorro_getDias(eCachorro* this,int* dias);
int cachorro_getRaza(eCachorro* this,char* raza);
int cachorro_getReservado(eCachorro* this,char* reservado);
int cachorro_getGenero(eCachorro* this,char* genero);
int mostrarCallejeros(LinkedList* lista);
