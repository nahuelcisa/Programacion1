#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   /* char nombre[10];
    char auxCad[100];


    printf("Ingrese nombre: ");

    gets(auxCad);

    while( strlen(auxCad) > 9){

        printf("Error. nombre demasiado largo. Reingrese: ");

        gets(auxCad);
    }

    strcpy(nombre,auxCad);

    printf("%s",nombre);*/



    char n1[10] = "Juan";
    char n2[20] = "Juan";
    int x;
    int y;

    x = strcmp(n1,n2);
    y = stricmp(n1,n2);

    printf("x = %d \ny = %d\n", x,y);



   /* char n1[10] = "juan";
    char n2[10] = "ALBERTO";

    //strupr(n1);
    //n1[0] = toupper(n1[0]);
    strlwr(n2);

    printf("%s\n%s",n1,n2);*/




    return 0;
}
