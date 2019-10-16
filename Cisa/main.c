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

#define TAMAUTOS 15
#define TAMARCAS 5
#define TAMCOLOR 5
#define TAMSERVICIO 4
#define TAMTRABAJO 15

//funciones informes
void informesAutos(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicio);
void mostrarAutosDeUnaMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas,eColor colores[]);
void mostrarAutosMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, int idMarca,eColor colores[]);
void mostrarAutosXMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[]);
void mostrarCantidadAutosXMarca(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarcas);
void servicioMasPedido(eAuto autos[], int tamAutos, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajos);
int cantidadAutosServicio(eTrabajo trabajos[], int tamTrabajos,int idServicio);
void mostrarTrabajosFechaDeterminada(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios);
void mostrarCantidadAutosXColor(eAuto autos[], int tamAuto, eColor colores[], int tamColores);
void mostrarAutosNegros(eAuto autos[], int tamAutos, eColor colores[],int tamColores, eMarca marcas[], int tamMarcas);
void mostrarAutoMarcaSel(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas,eColor colores[]);
void trabajosAUnAuto(eAuto autos[], int tamAutos, eTrabajo trabajos[], int tamTrabajos,eColor colores[], int tamColores,eMarca marcas[], int tamMarcas,eServicio servicios[], int tamServicios);

//funciones menu
int menu();
int menuInformes();

int main()
{
    int idAuto = 100;
    int idTrabajo = 60000;
    eMarca marcas[] = { {1000,"Renault"},{1001,"Fiat"}, {1002,"Ford"}, {1003,"Chevrolet"}, {1004,"Peugeot"}};
    eColor colores[] = {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eServicio servicios[] = {{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}};
    eAuto vehiculos[TAMAUTOS];
    eTrabajo trabajos[TAMTRABAJO];

    inicializarAutos(vehiculos,TAMAUTOS);
    inicializarTrabajos(trabajos,TAMTRABAJO);

    idAuto = idAuto + hardcodearAutos(vehiculos,TAMAUTOS, 10);
    idTrabajo = idTrabajo + hardcodearTrabajos(trabajos,TAMTRABAJO,10);

    char respuesta = 'n';
    do
    {
        switch(menu())
        {
        case 1:
            altaAuto(vehiculos,TAMAUTOS,marcas,TAMARCAS,colores,TAMCOLOR);
            break;
        case 2:
            modificarAuto(vehiculos,TAMAUTOS,colores,TAMCOLOR,marcas,TAMARCAS);
            break;
        case 3:
            bajaAuto(vehiculos,TAMAUTOS,colores,TAMCOLOR,marcas,TAMARCAS);
            break;
        case 4:
            mostrarAutos(vehiculos,TAMAUTOS,colores,TAMCOLOR,marcas,TAMARCAS);
            break;
        case 5:
            mostrarMarcas(marcas,TAMARCAS);
            break;
        case 6:
            mostrarColores(colores,TAMCOLOR);
            break;
        case 7:
            mostrarServicios(servicios,TAMSERVICIO);
            break;
        case 8:
            if(altaTrabajo(trabajos,TAMTRABAJO,idTrabajo,vehiculos,TAMAUTOS,servicios,TAMSERVICIO,colores,TAMCOLOR,marcas,TAMARCAS))
            {
                idTrabajo++;
            }
            break;
        case 9:
            mostrarTrabajos(trabajos,TAMTRABAJO,servicios,TAMSERVICIO);
            break;
        case 10:
            informesAutos(vehiculos,TAMAUTOS,marcas,TAMARCAS,colores,TAMCOLOR,trabajos,TAMTRABAJO,servicios,TAMSERVICIO);
            break;
        case 11:
            printf("Confirma salir?:");
            fflush(stdin);
            respuesta = getche();
            printf("\n\n");
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
            fflush(stdin);

        }
        system("pause");
    }
    while(respuesta == 'n');

    return 0;
}


int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Autos *******\n\n");
    printf("1-Alta auto\n");
    printf("2-Modificar auto\n");
    printf("3-Baja auto\n");
    printf("4-Listar autos\n");
    printf("5-Listar Marcas\n");
    printf("6-Liscar Colores\n");
    printf("7-Listar servicios\n");
    printf("8-Alta trabajo\n");
    printf("9-Listar trabajos\n");
    printf("10-Informes\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Informes *******\n\n");
    printf("1-Mostrar Autos de color negro\n");
    printf("2-Mostrar Autos de una Marca\n");
    //printf("2-Mostrar Autos por Marca\n");
    //printf("3-Mostrar Cantidad de autos por Marca\n");
    //printf("3-Mostrar todos los trabajos efectuados al auto seleccionado\n");
    //printf("4-Mostrar La Marca con mas Autos\n");
    printf("3-Mostrar Servicio mas pedido\n");
    printf("4-Mostrar Trabajos de una fecha determinada\n");
    //printf("6-Mostrar Cantidad de autos por Color\n");
    printf("7-Informe 7\n");
    printf("8-Informe 8\n");
    printf("9-Informe 9\n");
    printf("10-Informe 10\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informesAutos(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicio)
{
    char salir = 'n';
    printf("***** Informes ABM AUTOS ****\n\n");

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAutosNegros(autos,tamAutos,colores,tamColores,marcas,tamMarcas);
            break;

        case 2:
            //mostrarAutosXMarca(autos,tamAutos,marcas,tamMarcas,colores);
            mostrarAutoMarcaSel(autos,tamAutos,marcas,tamMarcas,colores);
            break;

       /* case 3:
            //mostrarCantidadAutosXMarca(autos,tamAutos,marcas,tamMarcas);
            trabajosAUnAuto(autos,tamAutos,trabajos,tamTrabajos,colores,tamColores,marcas,tamMarcas,servicios,tamServicio);
            break;
*/
        case 3:
            servicioMasPedido(autos,tamAutos,servicios,tamServicio,trabajos,tamTrabajos);
            break;

        case 4:
            mostrarTrabajosFechaDeterminada(trabajos,tamTrabajos,servicios,tamServicio);
            break;

        case 6:
            mostrarCantidadAutosXColor(autos,tamAutos,colores,tamColores);
            break;

        case 7:
            printf("Informe 7\n");
            break;

        case 8:
            printf("Informe 8\n");
            break;
        case 9:
            printf("Informe 9\n");
            break;
        case 10:
            printf("Informe 10\n");
            break;
        case 15:
            mostrarAutosDeUnaMarca(autos,tamAutos,marcas,tamMarcas,colores);
            break;
        case 11:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getchar();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}

void mostrarAutosDeUnaMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas,eColor colores[])
{
    int idMarca;
    system("cls");
    printf("***Marcas***\n\n");
    mostrarMarcas(marcas, tamMarcas);
    printf("Ingrese id Marca: ");
    scanf("%d", &idMarca);
    mostrarAutosMarca(autos,tamAutos,marcas,tamMarcas,idMarca,colores);
}

void mostrarAutosMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, int idMarca,eColor colores[])
{

    char desc[20];
    int flag = 0;
    cargarDescMarca(idMarca, marcas, 20,desc);

    printf("Marca: %s\n\n", desc);
    printf(" ID      Patente          Marca       Color       Modelo  \n\n");
    for(int i=0; i < tamAutos; i++)
    {
        if( autos[i].isEmpty == 0 && autos[i].idMarca == idMarca)
        {
            mostrarAuto(autos[i],marcas,tamAutos,colores);
            flag = 1;
        }
    }
    if( flag == 0)
    {
        printf("No hay Autos %s", desc);
    }
    printf("\n\n");
}

void mostrarAutosXMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[])
{

    system("cls");
    printf("***Listado de Autos por Marca***\n\n");

    for(int i=0; i < tamMarcas; i++)
    {
        mostrarAutosMarca(autos,tamAutos,marcas,tamMarcas,autos[i].idMarca,colores);
    }

    printf("\n\n");
}

void mostrarCantidadAutosXMarca(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarcas)
{

    int contador = 0;
    char desc[20];

    system("cls");
    printf("***Cantidad de Autos por Marca***\n\n");

    // Recorro vector de carreras
    for(int i=0; i < tamMarcas; i++)
    {
        cargarDescMarca(marcas[i].id,marcas,tamMarcas,desc);
        printf("Marca: %s\n\n", desc);

        for(int j= 0; j < tamAuto; j++)
        {
            if( autos[j].isEmpty == 0 && autos[j].idMarca == marcas[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad: %d\n\n", contador);
        contador = 0;
    }
    printf("\n\n");
}

void servicioMasPedido(eAuto autos[], int tamAutos, eServicio servicios[], int tamServicio, eTrabajo trabajos[], int tamTrabajos)
{

    int cantidades[tamServicio];
    int mayor;
    int flag = 0;
    char desc[20];

    for( int i=0; i < tamServicio; i++)
    {
        cantidades[i] = cantidadAutosServicio(trabajos,tamTrabajos,servicios[i].id);
    }


    for(int i=0; i < tamServicio; i++)
    {
        if( mayor < cantidades[i] || flag==0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }

    for(int i=0; i < tamServicio; i++)
    {
        if( cantidades[i]== mayor)
        {

            cargarDescServicio(servicios[i].id,servicios,tamServicio,desc);
            printf("El servicio mas pedido es: %s\nSe pidio %d veces\n",desc,mayor);

        }
    }
}

int cantidadAutosServicio(eTrabajo trabajos[], int tamTrabajos,int idServicio)
{
    int cant = 0;

    for(int i= 0; i < tamTrabajos; i++ )
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].idServicio == idServicio)
        {
            cant++;
        }
    }
    return cant;
}

void mostrarTrabajosFechaDeterminada(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios)
{

    eTrabajo fechaPedida;
    int cont = 0;

    printf("Ingrese fecha dd/mm/aaaa: ");
    scanf("%d/%d/%d",&fechaPedida.fecha.dia,&fechaPedida.fecha.mes,&fechaPedida.fecha.anio);
    printf(" IdTrabajo    Patente       Servicio    Fecha\n\n");
    for(int i = 0; i< tamTrabajos; i++)
    {
        if((trabajos[i].fecha.dia == fechaPedida.fecha.dia) && (trabajos[i].fecha.mes == fechaPedida.fecha.mes) && (trabajos[i].fecha.anio == fechaPedida.fecha.anio) && (trabajos[i].isEmpty == 0))
        {
            mostrarTrabajo(trabajos[i],servicios,tamServicios);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay Trabajos para mostrar en esa fecha\n");
    }
}

void mostrarCantidadAutosXColor(eAuto autos[], int tamAuto, eColor colores[], int tamColores)
{

    int contador = 0;
    char desc[20];

    system("cls");
    printf("***Cantidad de Autos por Color***\n\n");

    // Recorro vector de carreras
    for(int i=0; i < tamColores; i++)
    {
        cargarDescColor(colores[i].id,colores,tamColores,desc);
        printf("Color: %s\n\n", desc);

        for(int j= 0; j < tamAuto; j++)
        {
            if( autos[j].isEmpty == 0 && autos[j].idColor == colores[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad: %d\n\n", contador);
        contador = 0;
    }
    printf("\n\n");
}


void mostrarAutosNegros(eAuto autos[], int tamAutos, eColor colores[],int tamColores, eMarca marcas[], int tamMarcas){

    printf(" ID      Patente          Marca       Color       Modelo  \n\n");

    for(int i = 0; i<tamAutos; i++){

        if((autos[i].idColor == 5000) && (autos[i].isEmpty == 0)){
            mostrarAuto(autos[i],marcas,tamAutos,colores);
        }
    }
}

void mostrarAutoMarcaSel(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas,eColor colores[]){

    int idMarca;
    system("cls");
    printf("*** Auto de una marca ***\n\n");

    mostrarMarcas(marcas,tamMarcas);
    printf("\nSeleccione ID marca:");
    scanf("%d",&idMarca);

    while(idMarca < 1000 || idMarca > 1005){
        printf("error.  id Marca incorrecto.\n");
        printf("Ingrese idMarca: ");
        fflush(stdin);
        scanf("%d", &idMarca);
    }

    printf(" ID      Patente          Marca       Color       Modelo  \n\n");
    for(int i = 0; i < tamAutos; i++){

        if(autos[i].idMarca == idMarca && autos[i].isEmpty == 0){
            mostrarAuto(autos[i],marcas,tamAutos,colores);
        }
    }

}

void trabajosAUnAuto(eAuto autos[], int tamAutos, eTrabajo trabajos[], int tamTrabajos,eColor colores[], int tamColores,eMarca marcas[], int tamMarcas,eServicio servicios[], int tamServicios){

    char pat[20];

    system("cls");
    printf("*** Trabajos a un auto seleccionado\n\n");
    mostrarAutos(autos,tamAutos,colores,tamColores,marcas,tamMarcas);
    printf("\nElija Patente: ");
    fflush(stdin);
    gets(pat);

    for(int i = 0; i<tamAutos; i++){
        if(autos[i].patente == pat && autos[i].isEmpty == 0){
            for(int j = 0; j<tamTrabajos; j++){
                if(trabajos[j].patente == autos[i].patente && trabajos[j].isEmpty == 0){
                    for(int k = 0; k < tamServicios; k++){
                        if(servicios[k].id == trabajos[j].idServicio){
                            mostrarServicio(servicios[k]);
                        }
                    }
                }
            }
        }
    }

}
