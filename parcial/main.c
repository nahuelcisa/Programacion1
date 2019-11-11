#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Notebook(id, procesador, marca, precio)

typedef struct{

    int id;
    char procesador[10];
    char marca[10];
    float precio;

}eNotebook;


float aplicarAumento( float valor, int porcentaje);
int contarVocales (char cadena[]);
void ordenarNotebooks(eNotebook x [], int tam);
void mostrarNotebook(eNotebook x);
void mostrarNotebooks(eNotebook x[], int tam);

int main()
{
    float x;
    int y;

    eNotebook compus[6] = {
    {1000,"amd","sentey",350.5},
    {1001,"intel","samsung",350.51},
    {1002,"intel","samsung",3900.5},
    {1003,"amd","hp",3.5},
    {1004,"intel","samsung",350.5},
    {1005,"amd","hp",30.5},
    };


   // x = aplicarAumento(100,5);

    printf("El precio final con el aumento es: %.2f\n\n", x = aplicarAumento(100,5));

    //y = contarVocales("abiertaa");

    printf("la cadena tiene %d vocales\n\n", y = contarVocales("abiertaa"));
    printf("Notebooks desordenadas.\n\n");
    mostrarNotebooks(compus,6);

    printf("\n\n");
    printf("Notebooks ordenadas\n\n");
    ordenarNotebooks(compus,6);
    printf("\n\n");
    mostrarNotebooks(compus,6);


    return 0;
}

float aplicarAumento( float valor, int porcentaje){

    float x;
    float retorno;

    x =  valor/100 * porcentaje;

    retorno = valor + x;

    return retorno;
}


int contarVocales (char cadena[]){

    int contador = 0;

    for(int i = 0; i < strlen(cadena);i++){
        if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' ||cadena[i] == 'o'|| cadena[i] == 'u'
           || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' ||cadena[i] == 'O'|| cadena[i] == 'U'){
            contador++;
        }
    }
    return contador;
}

void ordenarNotebooks(eNotebook x[], int tam){

    eNotebook aux;

    for(int i = 0; i<tam-1; i++){
        for(int j = i+1; j<tam; j++){
            if(strcmp(x[i].marca,x[j].marca) == 0 && x[i].precio > x[j].precio){
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }else if(strcmp(x[i].marca,x[j].marca) > 0){

                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }
}

void mostrarNotebook(eNotebook x){

    printf("id: %d  procesador: %10s  marca: %10s   precio:%.2f\n",x.id,x.procesador,x.marca,x.precio);
}

void mostrarNotebooks(eNotebook x[], int tam){

    for(int i = 0; i<tam;i++){
        mostrarNotebook(x[i]);
    }
}
