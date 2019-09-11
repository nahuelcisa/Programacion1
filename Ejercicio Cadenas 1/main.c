#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41];
    char auxiliar[100];
    int i = 0;

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(auxiliar);

    while( strlen(auxiliar) > 19){

        printf("Error. Nombre demasiado largo. Reingrese: ");
        fflush(stdin);
        gets(auxiliar);
    }
    strcpy(nombre,auxiliar);


    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(auxiliar);

    while( strlen(auxiliar) > 19){

        printf("Error. Apellido demasiado largo. Reingrese: ");
        fflush(stdin);
        gets(auxiliar);
    }
    strcpy(apellido,auxiliar);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0] = toupper(nombreCompleto[0]);



    while( nombreCompleto[i] != '\0' ){
        if(nombreCompleto[i] == ' '){
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
            }
            i++;
        }

    printf("%s",nombreCompleto);


    return 0;
}
