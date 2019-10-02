 // agregar a la definicion d comida un float que se llame precio
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"
#include "comida.h"
#include "almuerzo.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMAL 20

int menu();
int menuInformes();
void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC,eAlmuerzo almuerzo[], int tAlmuerzos, eComidas comidas[], int tComidas);
void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int cantidadAlumnosCarrera(eAlumno alumnos[], int tam,int idCarrera);
void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void carreraMasCursada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarComidasFechaDeterminada(eAlmuerzo almuerzo[], int tamAl,eComidas comidas[], int tComidas);
int cantidadAlmuerzoCarrera(int idCarrera, eAlmuerzo almuerzo[], int tAlmuerzo, eAlumno alumnos[], int tAlumnos);
void CantidadAlmuerzoXCarrera(eAlmuerzo almuerzo[], int tAlmuerzo, eAlumno alumnos[], int tAlumnos, eCarrera carreras[], int tCarrera);
void CarreraAmanteMilanesa(eAlmuerzo almuerzo[], int tAlmuerzo, eAlumno alumnos[],int tAlumnos,eCarrera carreras[], int tCarreras);
int filtroAlmuerzoMilanesa (int idCarrera, eAlmuerzo almuerzo[], int tAlmuerzo, eAlumno alumnos[],int tAlumnos);
void totalDeudaXAlumno(eComidas comidas[], int tComidas ,eAlumno alumnos[], int tAlumno, eAlmuerzo almuerzos[], int tAlmuerzo,eCarrera carreras[], int tCarrera);

int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComidas comidas[TAMCOM]= {{5000,"Bife",250},{5001,"Fideos",180},{5002,"Pizza",200},{5003,"Arroz",160},{5004,"Milanesa",220}};
    eAlumno lista[TAM];
    eAlmuerzo almuerzos[TAMAL];
    char salir = 'n';

    inicializarAlumnos(lista, TAM);
    inicializarAlmuerzos(almuerzos, TAMAL);

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

            InformesAlumnos(lista, TAM, carreras, TAMC,almuerzos,TAMAL,comidas,TAMCOM);
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
            if(altaAlmuerzo(almuerzos,TAMAL,idAlmuerzo,lista,TAM,comidas,TAMCOM,carreras,TAMC)){
                idAlmuerzo++;
            }
            break;

        case 11:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            printf("\n\n");
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
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de alumnos por Carrera\n");
    printf("4-Mostrar La Carrera con mas incriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Mostrar Almuerzos de una fecha determinada\n");
    printf("10-Listar Alumnos que comieron milanesa\n");
    printf("11-Listar cantidad de almuerzos por carrera\n");
    printf("12-Carrera amante de las milanesas\n");
    printf("13-Informe deuda alumno seleccionado\n");
    printf("14-Recaudacion x venta comida seleccionada\n");
    printf("20-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    //     printf("4-Mostrar Mejor Promedio General\n");


    return opcion;
}

void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, eAlmuerzo almuerzo[], int tAlmuerzos, eComidas comidas[], int tComidas)
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
            printf("Informe 8\n");
            break;
        case 9:
            mostrarComidasFechaDeterminada(almuerzo,tAlmuerzos,comidas,tComidas);
            break;
        case 11:
            CantidadAlmuerzoXCarrera(almuerzo,tAlmuerzos,alumnos,tam,carreras,tamC);
            break;
        case 12:
            CarreraAmanteMilanesa(almuerzo,tAlmuerzos,alumnos,tam,carreras,tamC);
            break;
        case 13:
            totalDeudaXAlumno(comidas,tComidas,alumnos,tam,almuerzo,tAlmuerzos,carreras,tamC);
            break;

        case 20:
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
    // aca mostramos carreras y obtenemos el idCarrera
    // y llamamos a mostrarAlumnosCarrera
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
            if( (mayor < alumnos[j].promedio && alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id) || ( flag == 0  && alumnos[j].idCarrera == carreras[i].id)){
                mayor = alumnos[j].promedio;
                flag = 1;
            }
         }

         printf("Promedio: %.2f\n\n", mayor);
         mayor = 0;
         flag = 0;
    }
}

void mostrarComidasFechaDeterminada(eAlmuerzo almuerzo[], int tamAl,eComidas comidas[], int tComidas){

    eAlmuerzo fechaPedida;

    printf("Ingrese fecha: ");
    scanf("%d/%d/%d",&fechaPedida.fecha.dia,&fechaPedida.fecha.mes,&fechaPedida.fecha.anio);

    for(int i = 0; i< tamAl; i++){
        if((almuerzo[i].fecha.dia == fechaPedida.fecha.dia) && (almuerzo[i].fecha.mes == fechaPedida.fecha.mes) && (almuerzo[i].fecha.anio == fechaPedida.fecha.anio) ){
            mostrarComidas(comidas,tComidas);
        }else{
            printf("No hay comidas para mostrar en esa fecha\n");
        }
    }
}

int cantidadAlmuerzoCarrera(int idCarrera, eAlmuerzo almuerzo[], int tAlmuerzo, eAlumno alumnos[],int tAlumnos){

    int retorno = 0;


    for(int i=0; i<tAlumnos;i++){
        if(idCarrera == alumnos[i].idCarrera && alumnos[i].isEmpty == 0){
        for(int j = 0; j < tAlmuerzo; j++){
            if(alumnos[i].legajo == almuerzo[j].legajo){
                retorno++;
            }
        }
    }
}
        return retorno;

}

void CantidadAlmuerzoXCarrera(eAlmuerzo almuerzo[], int tAlmuerzo, eAlumno alumnos[], int tAlumnos, eCarrera carreras[], int tCarrera){

    int totales;

    for(int i = 0; i < tCarrera; i++){

           totales =  cantidadAlmuerzoCarrera(carreras[i].id,almuerzo,tAlmuerzo,alumnos,tAlumnos);
           printf("Carrera:%s\nTotal:%d\n\n",carreras[i].descripcion,totales);

    }
}

void CarreraAmanteMilanesa(eAlmuerzo almuerzo[], int tAlmuerzo, eAlumno alumnos[],int tAlumnos,eCarrera carreras[], int tCarreras){

    int cantidades[tCarreras];
    int mayor;
    int flag = 0;
    char desc[20];

    system("cls");
    printf("***** Carrera amante de las milanesas *****\n\n");

    for(int i = 0; i<tCarreras;i++){
            cantidades[i] = filtroAlmuerzoMilanesa(carreras[i].id,almuerzo,tAlmuerzo,alumnos,tAlumnos);
        }

    for(int i=0; i < tCarreras; i++)
    {
        if( mayor < cantidades[i] || flag==0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }

    for(int i=0; i < tCarreras; i++)
    {
        if( cantidades[i]== mayor)
        {

            cargarDescCarrera( carreras[i].id, carreras, tCarreras, desc);
            printf("%s : %d milanesas\n", desc, mayor);

        }
    }
}

int filtroAlmuerzoMilanesa (int idCarrera, eAlmuerzo almuerzo[], int tAlmuerzo, eAlumno alumnos[],int tAlumnos){

    int retorno = 0;


    for(int i=0; i<tAlumnos;i++){
        if(idCarrera == alumnos[i].idCarrera && alumnos[i].isEmpty == 0){
        for(int j = 0; j < tAlmuerzo; j++){
            if(alumnos[i].legajo == almuerzo[j].legajo && almuerzo[j].idComida == 5004){
                retorno++;
            }
        }
    }
}
        return retorno;
}

void totalDeudaXAlumno(eComidas comidas[], int tComidas ,eAlumno alumnos[], int tAlumno, eAlmuerzo almuerzos[], int tAlmuerzo,eCarrera carreras[], int tCarrera){

    int leg;
    float deuda;
    int flag = 0;


    mostrarAlumnos(alumnos,tAlumno,carreras,tCarrera);
    printf("Ingrese legajo: ");
    scanf("%d",&leg);

        for(int i = 0;i < tAlumno; i++){
            if(alumnos[i].legajo == leg && alumnos[i].isEmpty == 0){
                for(int j = 0; j<tAlmuerzo; j++){
                    if(alumnos[i].legajo == almuerzos[j].legajo && almuerzos[j].isEmpty == 0){
                        for(int k = 0; k<tComidas; k++){
                            if(comidas[k].id == almuerzos[j].idComida){
                                deuda = deuda + comidas[k].precio;
                                flag = 1;
                            }
                        }
                    }
                }

            }

        }
    if(flag == 1){
        printf("La deuda del alumno es: %4.2f\n\n",deuda);
    }else{
            printf("Legajo incorrecto.\n");}
}
