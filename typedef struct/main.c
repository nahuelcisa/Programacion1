#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        int dia;
        int mes;
        int anio;
    }fecha;

typedef struct{
    int legajo;
    int edad;
    int nota1;
    int nota2;
    char nombre[20];
    char sexo;
    float promedio;
    fecha fechadeingreso;
}eAlumno;

int main()
{

    eAlumno alumno1 = {1234,18,5,5,"Nahuel",'m',5,{17,3,2001}};

    /*char aux[100];


    printf("Ingrese nombre: ");
    gets(aux);

    while(strlen(aux)>20){
        printf("Error. ingrese un nombre mas corto: ");
        gets(aux);
    }
    strcpy(alumno1.nombre,aux);

    printf("Ingrese legajo: ");
    scanf("%d",&alumno1.legajo);

    printf("Ingrese edad: ");
    scanf("%d",&alumno1.edad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&alumno1.sexo);

    printf("Ingrese nota primer parcial: ");
    scanf("%d",&alumno1.nota1);

    printf("Ingrese nota segundo parcial: ");
    scanf("%d",&alumno1.nota2);

    alumno1.promedio = (float) (alumno1.nota1 + alumno1.nota2)/2;

    printf("Ingrese dia de ingreso: ");
    scanf("%d",&alumno1.fechadeingreso.dia);

    printf("Ingrese mes de ingreso: ");
    scanf("%d",&alumno1.fechadeingreso.mes);

    printf("Ingrese anio de ingreso: ");
    scanf("%d",&alumno1.fechadeingreso.anio);

    system("cls");
*/


    printf("Nombre: %s\nLegajo: %d\nEdad: %d\nSexo: %c\nNota primer parcial: %d\nNota segundo parcial: %d\nPromedio: %.2f\nFecha de ingreso: %02d/%02d/%d",alumno1.nombre,alumno1.legajo,alumno1.edad,alumno1.sexo,alumno1.nota1,alumno1.nota2,alumno1.promedio,alumno1.fechadeingreso.dia,alumno1.fechadeingreso.mes,alumno1.fechadeingreso.anio);

    return 0;
}
