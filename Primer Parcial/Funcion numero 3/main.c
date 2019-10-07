#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5


typedef struct
{
    int id;
    char procesador[50];
    char marca[50];
    float precio;
}eNotebook;

void ordenarEstructura(eNotebook notebooks[], int tam);
void mostrarNotebooks(eNotebook vec[],int tam);
void mostrarNotebook(eNotebook x);

int main()
{
    eNotebook computadoras[] ={
    {5000,"intel","samsung",520.32},
    {5001,"amd","toshiba",300.65},
    {5002,"intel","lenovo",250.89},
    {5003,"amd","sentey",900.74},
    {5004,"intel","sentey",1500.68}
    };

    mostrarNotebooks(computadoras,TAM);

    ordenarEstructura(computadoras,TAM);

    printf("\n\n");

    mostrarNotebooks(computadoras,TAM);

    return 0;
}

void ordenarEstructura(eNotebook notebooks[], int tam){

    eNotebook auxiliar;

    for(int i = 0; i<tam-1;i++){
        for(int j = i+1;j<tam;j++){
            if(strcmp(notebooks[i].marca,notebooks[j].marca) > 0){
                auxiliar = notebooks[j];
                notebooks[j] = notebooks[i];
                notebooks[i] = auxiliar;

            }
        }
    }
    for(int i = 0; i<tam-1;i++){
        for(int j = i+1;j<tam;j++){
            if(notebooks[i].precio>notebooks[j].precio){
                auxiliar = notebooks[j];
                notebooks[j] = notebooks[i];
                notebooks[i] = auxiliar;
            }
        }
    }
}

void mostrarNotebook(eNotebook x){

    printf("ID: %d  procesador: %s  marca: %s   precio: %.2f\n\n"
           ,x.id
           ,x.procesador
           ,x.marca
           ,x.precio);
}

void mostrarNotebooks(eNotebook vec[],int tam){

    for(int i = 0; i<tam;i++){
        mostrarNotebook(vec[i]);
    }
}
