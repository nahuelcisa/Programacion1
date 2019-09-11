#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam );
void mostrarAlumno(int leg, int age, int sex, int n1, int n2, float prom);
void ordenarAlumnosLeg(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam );
void ordenarAlumnosSexo(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam );
void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);

int main()
{
    int legajos[TAM] = {123,45,789,321,546};
    int edades [TAM] = {20,25,18,31,29};
    char sexos [TAM] = {'f','m','f','f','m'};
    int notap1 [TAM] = {5,6,7,8,9};
    int notap2 [TAM] = {5,2,7,2,9};
    float promedios [TAM] = {5,4,7,5,9};


   /* for(int i = 0; i < TAM; i++)
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
*/


    mostrarAlumnos(legajos,edades,sexos,notap1,notap2,promedios,TAM);

    ordenarAlumnosLeg(legajos,edades,sexos,notap1,notap2,promedios,TAM);

    mostrarAlumnos(legajos,edades,sexos,notap1,notap2,promedios,TAM);

    ordenarAlumnosSexLeg(legajos,edades,sexos,notap1,notap2,promedios,TAM);

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

void ordenarAlumnosLeg(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam ){

    int auxInt;
    char auxChar;
    float auxFloat;

        for(int i = 0 ; i < tam - 1 ; i++ ){
            for(int j = i + 1 ; j < tam ; j++ ){

                if(leg[i] > leg[j]){

                    auxInt = leg[i];
                    leg[i] = leg[j];
                    leg[j] = auxInt;

                    auxInt = age[i];
                    age[i] = age[j];
                    age[j] = auxInt;

                    auxChar = sex[i];
                    sex[i] = sex[j];
                    sex[j] = auxChar;

                    auxInt = n1[i];
                    n1[i] = n1[j];
                    n1[j] = auxInt;

                    auxInt = n2[i];
                    n2[i] = n2[j];
                    n2[j] = auxInt;

                    auxFloat = prom[i];
                    prom[i] = prom[j];
                    prom[j] = auxFloat;
                    }
                }
            }
        }


void ordenarAlumnosSexo(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam ){
    int auxInt;
    char auxChar;
    float auxFloat;

        for(int i = 0 ; i < tam - 1 ; i++ ){
            for(int j = i + 1 ; j < tam ; j++ ){

                if(sex[i] > sex[j]){

                    auxInt = leg[i];
                    leg[i] = leg[j];
                    leg[j] = auxInt;

                    auxInt = age[i];
                    age[i] = age[j];
                    age[j] = auxInt;

                    auxChar = sex[i];
                    sex[i] = sex[j];
                    sex[j] = auxChar;

                    auxInt = n1[i];
                    n1[i] = n1[j];
                    n1[j] = auxInt;

                    auxInt = n2[i];
                    n2[i] = n2[j];
                    n2[j] = auxInt;

                    auxFloat = prom[i];
                    prom[i] = prom[j];
                    prom[j] = auxFloat;
                    }
                }
            }
        }

void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    int auxInt;
    float auxFloat;
    char auxChar;
    int swap = 0;

    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){

            if( sex[i] > sex[j]){
                    swap = 1;
            }
            else if( sex[i] == sex[j] && leg[i] > leg[j]){

                    swap = 1;
            }

            if( swap ){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;
            }

            swap = 0;
        }
    }
}

