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


int buscarLibreTrabajo(eTrabajo trabajo[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( trabajo[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaTrabajo(eTrabajo trabajos[], int tamTrabajos, int idTrabajo, eAuto autos[], int tamAutos, eServicio servicios[], int tamServicios, eColor colores[], int tamColores, eMarca marcas[], int tamMarcas)
{
    int todoOk = 0;
    int indice;
    char patente[20] ;
    int idServicio;
    eFecha fecha;

    system("cls");

    printf("*****Alta Trabajo*****\n\n");

    indice = buscarLibreTrabajo(trabajos,tamTrabajos);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarAutos(autos,tamAutos,colores,tamColores,marcas,tamMarcas);
        printf("Ingrese patente del auto: ");
        fflush(stdin);
        gets(patente);

        while(buscarPatente(patente,autos,tamAutos) == -1){
            printf("Error. patente no cargada en el sistema.\n");
            printf("Reingrese patente: ");
            fflush(stdin);
            gets(patente);
            buscarPatente(patente,autos,tamAutos);
            }

        mostrarServicios(servicios,tamServicios);
        printf("Ingrese ID servicio: ");
        fflush(stdin);
        scanf("%d",&idServicio);
        while(buscarIdServicio(idServicio,servicios,tamServicios) == -1){
            printf("Error. id erronea. reingrese: ");
            scanf("%d",&idServicio);
        }

        printf("Ingrese Fecha dd/mm/aaa: ");
        fflush(stdin);
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);


        trabajos[indice] = newtrabajo(idTrabajo,patente,idServicio,fecha);
        todoOk = 1;
        printf("Alta Trabajo exitosa!!\n\n");
    }

    return todoOk;
}

eTrabajo newtrabajo(int id,char patente[],int idServicio,eFecha fecha)
{

    eTrabajo al;
    al.id = id;
    strcpy(al.patente,patente);
    al.idServicio = idServicio;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}

void mostrarTrabajo (eTrabajo trabajos,eServicio servicios[], int tamServicios){
    char descServicio[20];
    cargarDescServicio(trabajos.idServicio,servicios,tamServicios,descServicio);
    printf("  %d    %10s        %s      %2d/%2d/%4d\n\n",trabajos.id,trabajos.patente,descServicio,
           trabajos.fecha.dia,trabajos.fecha.mes,trabajos.fecha.anio);
}


void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos,  eServicio servicios[], int tamServicio)
{

    int flag = 0;

    printf("***** Listado Trabajos *****\n\n");

    printf(" IdTrabajo    Patente       Servicio    Fecha\n\n");

    for(int i=0; i < tamTrabajos; i++)
    {
        if( trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i],servicios,tamServicio);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay trabajos que mostrar\n");
    }

    printf("\n\n");
}

void inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int hardcodearTrabajos( eTrabajo trabajos[], int tamTrabajo, int cantidad)
{
    int cont = 0;

    eTrabajo suplentes[] =
    {
        {60000, "AA097DB",20000,0,{30,9,2019}},
        {60001, "JOL136",20001,0,{30,9,2019}},
        {60002, "JOL136",20002,0,{30,9,2019}},
        {60003, "AB148CV",20002,0,{30,9,2019}},
        {60004, "AA097DB",20003,0,{30,9,2019}},
        {60005, "JOL136",20003,0,{1,10,2019}},
        {60006, "AB148CV",20000,0,{1,10,2019}},
        {60007, "AUE883",20001,0,{1,10,2019}},
        {60008, "AC192AB",20001,0,{1,10,2019}},
        {60009, "GNQ963",20000,0,{2,10,2019}},
        {60010, "JOL136",20003,0,{3,10,2019}}
    };

    if( cantidad <= 10 && tamTrabajo >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            trabajos[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

