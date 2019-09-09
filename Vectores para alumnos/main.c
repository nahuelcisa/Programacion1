#include <stdio.h>
#include <stdlib.h>
#define TAM 1

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam );
void mostrarAlumno(int leg, int age, int sex, int n1, int n2, float prom);

int main()
{
    int legajos[TAM];
    int edades [TAM];
    char sexos [TAM];
    int notap1 [TAM];
    int notap2 [TAM];
    float promedios [TAM];


    for(int i = 0; i < TAM; i++)
    {

        printf("Ingrese legajo: ");
        fflush(stdin);
        scanf("%d", &legajos[i]);

        printf("Ingrese edad: ");
        fflush(stdin);
        scanf("%d", &edades[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese nota primer parcial: ");
        fflush(stdin);
        scanf("%d", &notap1[i]);

        printf("Ingrese nota segundo parcial: ");
        fflush(stdin);
        scanf("%d", &notap2[i]);

        promedios[i] = (float) (notap1[i] + notap2[i]) / 2;
    }

    mostrarAlumnos(legajos,edades,sexos,notap1,notap2,promedios,TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam )
{

    printf("Legajo  Edad  Sexo  Nota1  Nota2  Promedio \n\n");
    for(int i = 0; i < tam; i++)
    {
    printf(" %d      %d      %c     %d      %d       %.2f\n",leg[i],age[i],sex[i],n1[i],n2[i],prom[i]);
    }
    printf("\n\n");

}


void mostrarAlumno(int leg, int age, int sex, int n1, int n2, float prom){

printf(" %d      %d      %c     %d      %d       %.2f\n",leg,age,sex,n1,n2,prom);

    printf("\n\n");

}
