#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    int edad;
} ePersona;

ePersona* newPersona();
int setNombre(ePersona* a,char nombre[]);
int setEdad(ePersona* a, int edad);
int getNombre(ePersona* a, char* nombre);
int getEdad(ePersona* a, int* edad);
void agrandarLista(ePersona* a,int tam);

int main()
{
    ePersona* lista = newPersona();
    ePersona* lista2 = newPersona();
    FILE* f;
    int edad;
    char nombre[20];
    if(lista == NULL)
    {
        exit(EXIT_FAILURE);
    }

    setNombre(lista,"Nahuel");
    setEdad(lista,20);

    agrandarLista(lista,2);

    setNombre(lista+1,"Pepe");
    setEdad(lista+1,25);

    printf("----Hardcodeo----\n\n");
    for(int i = 0; i<2; i++)
    {
        getNombre(lista+i,nombre);
        getEdad(lista+i,&edad);
        printf("%s %d\n",nombre,edad);
    }

    f = fopen("personas.bin","wb");

    if(f == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fwrite(lista,sizeof(ePersona),2,f);

    fclose(f);


    FILE* j = fopen("personas.bin","rb");

    if(j == NULL)
    {
        exit(EXIT_FAILURE);
    }

    agrandarLista(lista2,2);

    fread(lista2,sizeof(ePersona),1,j);


    printf("\n\n----Leyendo el archivo----\n\n");
    for(int i = 0; i<2; i++)
    {
        getNombre(lista2+i,nombre);
        getEdad(lista2+i,&edad);
        printf("%s %d\n",nombre,edad);
    }
    fclose(j);
    free(lista);
    free(lista2);
    return 0;
}

ePersona* newPersona()
{
    ePersona* lista = (ePersona*)malloc(sizeof(ePersona));
    return lista;
}

int setNombre(ePersona* a,char nombre[])
{
    int todoOk = 0;
    if(a != NULL)
    {
        strcpy(a->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int setEdad(ePersona* a, int edad)
{
    int todoOk = 0;
    if(a!= NULL)
    {
        a->edad = edad;
        todoOk = 1;
    }
    return todoOk;
}

int getNombre(ePersona* a, char* nombre)
{
    int todoOk = 0;
    if(a != NULL && nombre != NULL)
    {
        strcpy(nombre,a->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int getEdad(ePersona* a, int* edad)
{
    int todoOk = 0;
    if(a != NULL && edad != NULL)
    {
        *edad = a->edad;
        todoOk = 1;
    }
    return todoOk;
}

void agrandarLista(ePersona* a,int tam)
{

    ePersona* aux = (ePersona*) realloc(a,sizeof(ePersona)*tam);
    if(aux != NULL)
    {
        a = aux;
    }
}
