#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "autoss.h"
#include "marca.h"
int hardcodearAutos( eAuto vec[], int tam, int cantidad)
{
    int cont = 0;

    eAuto suplentes[]=
    {
        { 100, "AA097DB", 1000, 5000,2016,0},
        { 101, "AUE883", 1003, 5000,2016,0},
        { 102, "MBV897", 1004, 5000,2016,0},
        { 103, "OCO641", 1002, 5000,2016,0},
        { 104, "AC186JB", 1001, 5000,2016,0},
        { 105, "JOL136", 1000, 5000,2016,0},
        { 106, "HOK782", 1004, 5000,2016,0},
        { 107, "AB148CV", 1003, 5000,2016,0},
        { 108, "AC192AB", 1003, 5000,2016,0},
        { 109, "GNQ963", 1002, 5000,2016,0},
        { 110, "JAL546", 1001, 5000,2016,0}
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarAuto(eAuto x, eMarca marcas[], int tam, eColor colores[])
{
    char descMarca[20];
    char descColor[20];

    cargarDescMarca(x.idMarca, marcas, tam, descMarca);
    cargarDescColor(x.idColor, colores, tam, descColor);
    printf("  %d  %10s   %s      %s    %4d    \n",
           x.id,
           x.patente,
           descMarca,
           descColor,
           x.modelo
           );
}
void mostrarAutos (eAuto autos[], int tam,  eColor colores[], int tamColor, eMarca marcas[], int tamMarcas)
{

    int flag = 0;
    system("cls");

    printf(" ID    Patente    Marca   Color  Modelo  \n\n");

    for(int i=0; i < tam; i++)
    {
        if( autos[i].isEmpty == 0)
        {
            mostrarAuto(autos[i],marcas,tam,colores);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay Autos que mostrar\n");
    }

    printf("\n\n");
}

void inicializarAutos(eAuto autos[], int tam){
    for(int i = 0; i < tam; i++)
    {
        autos[i].isEmpty = 1;
    }
}

int altaAuto(eAuto autos[], int tam , eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int todoOk = 0;
    int indice;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int id;

    system("cls");

    printf("*****Alta Auto*****\n\n");

    indice = buscarLibre(autos, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese id del Auto: ");
        scanf("%d", &id);

        printf("Ingrese patente: ");
        fflush(stdin);
        gets(patente);


        mostrarMarcas(marcas,tamMarcas);
        printf("Ingrese idMarca: ");
        scanf("%d", &idMarca);
    while(idMarca < 1000 && idMarca > 1005){
            printf("error. id marca incorrecto.");
        }

        mostrarColores(colores,tamColores);
        printf("Ingrese idColor: ");
        fflush(stdin);
        scanf("%d", &idColor);
        while(idColor < 5000 && idColor > 5005){
            printf("error. id color incorrecto.");
        }

        printf("Ingrese modelo(anio): ");
        scanf("%d", &modelo);

        autos[indice] = newAuto(id,patente,idMarca,idColor,modelo);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

int buscarLibre(eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

eAuto newAuto(int id,char patente[],int idMarca,int idColor,int modelo)
{

    eAuto al;

    al.id = id;
    strcpy( al.patente, patente);
    al.idMarca = idMarca;
    al.idColor = idColor;
    al.modelo = modelo;
    al.isEmpty = 0;

    return al;
}

int modificarAuto(eAuto autos[], int tam,eColor colores[], int tamColores,eMarca marcas[],int tamMarcas){

    int todoOk = 0;
    char patente[20];
    int indice;
    system("cls");
    printf("***** Modificar Auto *****\n\n");
    mostrarAutos(autos,tam,colores,tamColores,marcas,tamMarcas);
    printf("\nIngrese patente: ");
    fflush(stdin);
    gets(patente);
    int opcion;

    indice = buscarPatente(patente,autos,tam);

    if( indice == -1)
    {
        printf("No existe un auto con esa patente en el sistema\n\n");

    }else{
        system("cls");
        printf(" ID    Patente    Marca   Color  Modelo  \n\n");
        mostrarAuto(autos[indice],marcas,tam,colores);
        printf("\n\n");
        printf("1- Modificar Color\n");
        printf("2- Modificar Modelo\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
    case 1:
            mostrarColores(colores,tamColores);
            printf("Ingrese nuevo id Color: ");
            fflush(stdin);
            scanf("%d",&autos[indice].idColor);
            break;
    case 2:
            printf("Ingrese Nuevo modelo: ");
            fflush(stdin);
            scanf("%d",&autos[indice].modelo);
            break;

    case 3:
            printf("Se ha cancelado la modificacion ");
            break;

    }
    todoOk = 1;
    system("cls");
    printf("\nModificacion excitosa!!\n\n");
}
    return todoOk;
}

int buscarPatente(char patente[], eAuto autos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( strcmp(autos[i].patente,patente) == 0 && autos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaAuto (eAuto autos[], int tam, eColor colores[], int tamColores,eMarca marcas[], int tamMarcas)
{
    int todoOk = 0;
    char patente[20];
    int indice;
    char confirma;
    system("cls");
    printf("***** Modificar Auto *****\n\n");
    mostrarAutos(autos,tam,colores,tamColores,marcas,tamMarcas);
    printf("\nIngrese patente: ");
    fflush(stdin);
    gets(patente);

    indice = buscarPatente(patente,autos,tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {
        mostrarAuto(autos[indice],marcas,tam,colores);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            autos[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}
