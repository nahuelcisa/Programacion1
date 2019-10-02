#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMAL 20

typedef struct{

    int id;
    char descripcion[20];

}eComida;

typedef struct{

    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;

}eAlmuerzo;

int menu();
int menuInformes();
void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int cantidadAlumnosCarrera(eAlumno alumnos[], int tam,int idCarrera);
void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void carreraMasCursada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);

// Prototipos Comidas
void mostrarComidas(eComida comidas[], int tam);
void mostrarComida(eComida comida);

// Prototipos Almuerzos
void inicializarAlmuerzos(eAlmuerzo amluerzos[], int tam);
int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC);
int cargarDescComida(int id, eComida comidas[], int tam, char desc[]);
eAlmuerzo newAlmuerzo(int id, int leg, int idComida, eFecha fecha);
int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzo, int idAlmuerzo, eAlumno alumnos[], int tAlumno, eComida comidas[], int tComida, eCarrera carreras[], int tCarrera);
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);

int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComida comidas[TAMCOM]= {{5000,"Bife"},{5001,"Fideos"},{5002,"Pizza"}, {5003,"Arroz"},{5004,"Milanesa"}};
    eAlumno lista[TAM];
    eAlmuerzo almuerzos[TAMAL];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);
    inicializarAlmuerzos( almuerzos, TAMAL);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 9);

    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMAL, 10);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 5:
            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            InformesAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

         case 8:
            mostrarComidas(comidas, TAMCOM);
            break;

         case 9:
            mostrarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM);
            break;

         case 10:
           if (altaAlmuerzo(almuerzos, TAMAL, idAlmuerzo, lista, TAM, comidas, TAMCOM, carreras, TAMC)){
            idAlmuerzo++;
           }
           break;

        case 12:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Mostrar Comidas\n");
    printf("9-Mostrar Almuerzos\n");
    printf("10-Alta Almuerzo\n");
    printf("12-Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Informes *******\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de alumnos por Carrera\n");
    printf("4-Mostrar La Carrera con mas incriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    char salir = 'n';
    system("cls");
    printf("***** Informes Alumnos ****\n\n");

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosDeUnaCarrera(alumnos, tam, carreras, tamC);
            break;

        case 2:
            mostrarAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 3:
            mostrarCantidadAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 4:
            carreraMasCursada(alumnos, tam, carreras, tamC);
            break;

        case 5:
            mejoresPromediosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 6:
            printf("Informe 6\n");
            break;

        case 7:
            printf("Informe 7\n");
            break;

        case 8:
            printf("Informe 7\n");
            break;

        case 9:
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



void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int idCarrera;
    system("cls");
    printf("***Carreras***\n\n");
    mostrarCarreras(carreras, tamC);
    printf("Ingrese id carrera: ");
    scanf("%d", &idCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);

}

void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera)
{

    char desc[20];
    int flag = 0;
    cargarDescCarrera(idCarrera, carreras, 20,desc);

    printf("Carrera: %s\n\n", desc);

    for(int i=0; i < tam; i++)
    {
        if( alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
            flag = 1;
        }
    }
    if( flag == 0)
    {
        printf("No hay Alumnos cursando %s", desc);
    }
    printf("\n\n");
}

void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    system("cls");
    printf("***Listado de Alumnos por Carrera***\n\n");

    for(int i=0; i < tamC; i++)
    {
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }

    printf("\n\n");
}

void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int contador = 0;
    char desc[20];

    system("cls");
    printf("***Cantidad de Alumnos por Carrera***\n\n");

    // Recorro vector de carreras
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
        printf("Carrera: %s\n\n", desc);

        for(int j= 0; j < tam; j++)
        {
            if( alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad: %d\n\n", contador);
        contador = 0;
    }
    printf("\n\n");
}

int cantidadAlumnosCarrera(eAlumno alumnos[], int tam,int idCarrera)
{
    int cant = 0;

    for(int i= 0; i < tam; i++ )
    {
        if(alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            cant++;
        }
    }
    return cant;
}

void carreraMasCursada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int cantidades[tamC];
    int mayor;
    int flag = 0;
    char desc[20];

    for( int i=0; i < tamC; i++)
    {
        cantidades[i] = cantidadAlumnosCarrera(alumnos, tam, carreras[i].id);
    }


    for(int i=0; i < tamC; i++)
    {
        if( mayor < cantidades[i] || flag==0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }

    for(int i=0; i < tamC; i++)
    {
        if( cantidades[i]== mayor)
        {

            cargarDescCarrera( carreras[i].id, carreras, tamC, desc);
            printf("Carrera: %s %d alumnos\n", desc, mayor);

        }
    }
}

void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    char desc[20];
    float mayor;
    int flag = 0;
    system("cls");
    printf("***Mejores Promedios por Carrera***\n\n");

    for( int i=0; i < tamC; i++){
         cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
         printf("Carrera: %s\n\n", desc);

         for(int j=0; j < tam; j++){
            if( ((mayor < alumnos[j].promedio && alumnos[j].isEmpty == 0) && (alumnos[j].idCarrera == carreras[i].id)) || ( flag == 0  && alumnos[j].idCarrera == carreras[i].id)){
                mayor = alumnos[j].promedio;
                flag = 1;
            }
         }

         printf("Promedio: %.2f\n\n", mayor);
         mayor = 0;
         flag = 0;
    }
}




void mostrarComidas(eComida comidas[], int tam){
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarComida( comidas[i]);
    }
    printf("\n");
}

void mostrarComida(eComida comida){

    printf("  %d      %10s\n", comida.id, comida.descripcion);

}

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        almuerzos[i].isEmpty = 1;
    }
}

int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        { 60000, 20005, 5004,{30,9,2019}, 0},
        { 60001, 20003, 5000,{30,9,2019}, 0},
        { 60002, 20001, 5004,{30,9,2019}, 0},
        { 60003, 20000, 5002,{30,9,2019}, 0},
        { 60004, 20004, 5003,{30,9,2019}, 0},
        { 60005, 20005, 5004,{1,10,2019}, 0},
        { 60006, 20003, 5004,{1,10,2019}, 0},
        { 60007, 20006, 5001,{1,10,2019}, 0},
        { 60008, 20000, 5002,{1,10,2019}, 0},
        { 60009, 20005, 5004,{2,10,2019}, 0},
        { 60010, 20001, 5000,{2,10,2019}, 0}};

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

void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tam)
{
    char descComida[20];

    cargarDescComida(x.idComida, comidas, tam, descComida);
    printf("  %d  %d  %10s   %02d/%02d/%d\n",
           x.id,
           x.legajo,
           descComida,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio
           );
}

void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC)
{

    int flag = 0;
    system("cls");
    printf("**** Listado Almuerzos ****\n\n");
    printf(" IdAlmuerzo  Legajo  Comida     Fecha\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlmuerzo(vec[i], comidas, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay almuerzos que mostrar\n");
    }

    printf("\n\n");
}

int cargarDescComida(int id, eComida comidas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == comidas[i].id){
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzo, int idAlmuerzo, eAlumno alumnos[], int tAlumno, eComida comidas[], int tComida, eCarrera carreras[], int tCarrera)
{
    int todoOk = 0;
    int indice;
    int legajo;
    int idComida;
    eFecha fecha;

    system("cls");
    printf("*****Alta Almuerzo*****\n\n");

    indice = buscarLibreAlmuerzo(almuerzos, tAlmuerzo);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarAlumnos(alumnos, tAlumno, carreras, tCarrera);
        printf("Ingrese legajo alumno: ");
        scanf("%d", &legajo);

        mostrarComidas(comidas, tComida);
        printf("Ingrese id Comida: ");
        scanf("%d", &idComida);

        printf("Ingrese fecha: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);


        almuerzos[indice] = newAlmuerzo(idAlmuerzo, legajo, idComida, fecha);
        todoOk = 1;
        printf("Alta Almuerzo exitosa!!\n\n");
    }

    return todoOk;
}

eAlmuerzo newAlmuerzo( int id, int leg, int idComida, eFecha fecha)
{
    eAlmuerzo al;
    al.id = id;
    al.legajo = leg;
    al.idComida = idComida;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}

int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam)
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


