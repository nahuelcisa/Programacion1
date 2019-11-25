#include <stdio.h>
#include <stdlib.h>

typedef struct{

    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;

float aplicarDescuento(float precio);

int contarCaracteres(char cadena[], char car);

int main()
{
   float precioFinal = aplicarDescuento(100);

  // printf("%.2f", precioFinal);

  printf("%d\n", contarCaracteres("obeliscooooooo", 'b'));

    return 0;
}


float aplicarDescuento(float precio){

    return precio * .95;

}


int contarCaracteres(char cadena[], char car){

int contador = 0;
/*int i =0;

    while( cadena[i] != '\0'){
        if( cadena[i]== car ){
            contador++;
        }
        i++;
    }*/

    for( int i=0; i < strlen(cadena); i++){
        if( cadena[i]== car ){
            contador++;
        }
    }

return contador;
}

void ordenarNotebook( eNotebook lista[], int tam){

eNotebook aux;

for(int i=0; i < tam-1; i++){
    for(int j= i+1; j < tam; j++){
        if( strcmp(lista[i].marca, lista[j].marca) == 0 && lista[i].precio > lista[j].precio){
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
        else if(  strcmp(lista[i].marca, lista[j].marca)>0){
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
    }
}



}

