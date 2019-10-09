#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAMAUTOS 10
#define TAMARCAS 5
#define TAMCOLOR 5
#define TAMSERVICIO 4
#define TAMTRABAJO 10

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct{
    int id;
    char descripcion[20];
}eMarca;

typedef struct{
    int id;
    char nombreColor[20];
}eColor;

typedef struct{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;
typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eServicio;//lavado pulido encerado completo
typedef struct{
    int id;
    char patente[10];
    int idServicio;
    int isEmpty;
    eFecha fecha;
}eTrabajo;

//funciones autos
int hardcodearAutos( eAuto vec[], int tam, int cantidad);
void inicializarAutos(eAuto autos[], int tam);
void mostrarAutos (eAuto autos[], int tam,  eColor colores[], int tamColor, eMarca marcas[], int tamMarcas);
eAuto newAuto(int id,char patente[],int idMarca,int idColor,int modelo);
int buscarLibre(eAuto vec[], int tam);
int altaAuto(eAuto autos[], int tam , eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);
int buscarPatente(char patente[], eAuto autos[], int tam);
int modificarAuto(eAuto autos[], int tam,eColor colores[], int tamColores,eMarca marcas[],int tamMarcas);
int bajaAuto (eAuto autos[], int tam, eColor colores[], int tamColores,eMarca marcas[], int tamMarcas);
int buscarIdAuto(int id, eAuto autos[], int tam);

//funciones color
int cargarDescColor(int id, eColor colores[], int tam, char desc[]);
void mostrarColores(eColor colores[], int tam);
void mostrarColor(eColor colores);

//funciones marca
int cargarDescMarca(int id, eMarca marcas[], int tam, char desc[]);
void mostrarMarcas(eMarca marcas[], int tam);
void mostrarMarca(eMarca marcas);

//funciones servicios
void mostrarServicios (eServicio servicios[], int tam);
void mostrarServicio (eServicio servicios);
int cargarDescServicio(int id, eServicio servicios[], int tam, char desc[]);
int buscarIdServicio(int id, eServicio servicios[], int tam);

//funciones trabajo
eTrabajo newtrabajo(int id,char patente[],int idServicio,eFecha fecha);
void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos,  eServicio servicios[], int tamServicio);
void mostrarTrabajo (eTrabajo trabajos,eServicio servicios[], int tamServicios);
int altaTrabajo(eTrabajo trabajos[], int tamTrabajos, int idTrabajo, eAuto autos[], int tamAutos, eServicio servicios[], int tamServicios, eColor colores[], int tamColores, eMarca marcas[], int tamMarcas);
void inicializarTrabajos(eTrabajo trabajos[], int tam);

//funciones menu
int menu();

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

    idAuto = idAuto + hardcodearAutos(vehiculos,TAMAUTOS, 9);

    char respuesta = 'n';
    do{
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
        if(altaTrabajo(trabajos,TAMTRABAJO,idTrabajo,vehiculos,TAMAUTOS,servicios,TAMSERVICIO,colores,TAMCOLOR,marcas,TAMARCAS)){
            idTrabajo++;
        }
        break;
    case 9:
        mostrarTrabajos(trabajos,TAMTRABAJO,servicios,TAMSERVICIO);
        break;
    case 10:
            printf("Confirma salir?:");
            fflush(stdin);
            respuesta = getche();
            printf("\n\n");
            break;

        default:
            printf("\nOpcion Invalida!\n\n");

}
        system("pause");
    }while(respuesta == 'n');

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
    printf("10-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

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
    printf("  %d    %10s   %10s   %s      %4d    \n",
           x.id,
           x.patente,
           descMarca,
           descColor,
           x.modelo
           );
}

int cargarDescMarca(int id, eMarca marcas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == marcas[i].id){
            strcpy(desc, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

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

void mostrarAutos (eAuto autos[], int tam,  eColor colores[], int tamColor, eMarca marcas[], int tamMarcas)
{

    int flag = 0;
    system("cls");

    printf(" ID      Patente          Marca       Color       Modelo  \n\n");

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

void mostrarMarca (eMarca marcas){

    printf("  %d      %10s\n", marcas.id, marcas.descripcion);

}

void mostrarMarcas (eMarca marcas[], int tam){
    printf(" Id         Marca\n\n");
    for(int i=0; i < tam; i++){
        mostrarMarca( marcas[i]);
    }
    printf("\n");
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
    int a;

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
        a = buscarIdAuto(id,autos,tam);
        if(a == -1){
        }else{
            printf("ya hay un vehiculo ingresado con esa id\n");
            mostrarAuto(autos[a],marcas,tam,colores);
            do{
                printf("Ingrese otro Id: ");
                scanf("%d", &id);
                a = buscarIdAuto(id,autos,tam);
            }while(a != -1);
        }

        printf("Ingrese patente: ");
        fflush(stdin);
        gets(patente);


        mostrarMarcas(marcas,tamMarcas);
        printf("Ingrese idMarca: ");
        scanf("%d", &idMarca);


    while(idMarca < 1000 && idMarca > 1005){
        printf("error.  id Marca incorrecto.\n");
        printf("Ingrese idMarca: ");
        fflush(stdin);
        scanf("%d", &idMarca);
    }



        mostrarColores(colores,tamColores);
        printf("Ingrese idColor: ");
        fflush(stdin);
        scanf("%d", &idColor);

    while(idColor < 5000 && idColor > 5005){
        printf("error.  id color incorrecto.\n");
        printf("Ingrese idColor: ");
        fflush(stdin);
        scanf("%d", &idColor);
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
    while(autos[indice].idColor < 5000 && autos[indice].idColor > 5005){
        printf("error.  id Color incorrecto.\n");
        printf("Ingrese idColor: ");
        fflush(stdin);
        scanf("%d", &autos[indice].idColor);
        }

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
        printf("No existe un Auto con esa patente\n\n");

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

int buscarIdAuto(int id, eAuto autos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( autos[i].id == id && autos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

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

eTrabajo newtrabajo(
    int id,
    char patente[],
    int idServicio,
    eFecha fecha
    )
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
    printf("  %d    %10s    %s  %2d/%2d/%4d\n\n",trabajos.id,trabajos.patente,descServicio,
           trabajos.fecha.dia,trabajos.fecha.mes,trabajos.fecha.anio);
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

void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos,  eServicio servicios[], int tamServicio)
{

    int flag = 0;
    system("cls");
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
