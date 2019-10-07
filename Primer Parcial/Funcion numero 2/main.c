#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int contarCaracteres(char cadena[],char caracter);
int main()
{
    char nombre[20];
    char letra;
    int x;

    printf("Ingrese su nombre: ");
    gets(nombre);

    printf("Ingrese la letra que desea contar: ");
    scanf("%c",&letra);

    x = contarCaracteres(nombre,letra);
    printf("La letra seleccionada aparece: %d veces",x);

    printf("\n\n");


    return 0;

}

int contarCaracteres(char cadena[],char caracter){

    int contador = 0;

    for(int i = 0; i<20;i++){

        if(cadena[i] == caracter){
            contador++;
        }
    }

    return contador;
}
