#include <stdio.h>
#include <stdlib.h>

#define TAM 3


typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
}eAlumno;

void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);

int main()
{
    eAlumno lista[TAM]= {
        { 1234,"juan", 20,'m', 7,8,7.5,{21,5,2018} },
        { 1231,"Lucia", 21,'f', 9,6,7.5,{12,3,2019}},
        { 1101,"Alberto", 21,'m', 2,2,2,{28,3,2019}}
        };

/*
    for(int i=0; i < TAM; i++){
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(lista[i].nombre);

    printf("Ingrese legajo:");
    scanf("%d", &lista[i].legajo);

    printf("Ingrese edad:");
    scanf("%d", &lista[i].edad);

    printf("Ingrese sexo:");
    fflush(stdin);
    scanf("%c", &lista[i].sexo);

    printf("Ingrese nota parcial 1:");
    scanf("%d", &lista[i].nota1);

    printf("Ingrese nota parcial 2:");
    scanf("%d", &lista[i].nota2);

    lista[i].promedio = (float) (lista[i].nota1 + lista[i].nota2) / 2;

    printf("Ingrese fecha ingreso: dd/mm/aaaa ");
    scanf("%d/%d/%d", &lista[i].fechaIngreso.dia, &lista[i].fechaIngreso.mes, &lista[i].fechaIngreso.anio);
    printf("Ingrese dia de ingreso: ");
    scanf("%d", &lista[i].fechaIngreso.dia);

    printf("Ingrese mes de ingreso: ");
    scanf("%d", &lista[i].fechaIngreso.mes);

    printf("Ingrese anio de ingreso: ");
    scanf("%d", &lista[i].fechaIngreso.anio);
    }

    */

    mostrarAlumnos(lista, TAM);

    ordenarAlumnos(lista, TAM);

     mostrarAlumnos(lista, TAM);

    return 0;
}

void mostrarAlumno(eAlumno x){
    printf("  %d  %s  %d  %c  %d %d %.2f %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam){

printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");
    for(int i=0; i < tam; i++){
        mostrarAlumno(vec[i]);
    }

printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam){

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++){
        for(int j= i+1; j <tam; j++){
            if( vec[i].legajo > vec[j].legajo){
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }




}
