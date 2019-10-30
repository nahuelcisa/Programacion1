#include <stdio.h>
#include <stdlib.h>

int main()
{

    char auxChar;
    FILE* f = fopen("pepe", "w");
    char mensaje[30] = "Esto es un mensaje";

    char cadena[30];


    if( f == NULL){
        printf("No se pudo abrir el archivo");
        system("pause");
        exit(EXIT_FAILURE);
    }
    fwrite(mensaje, sizeof(char), strlen(mensaje), f);
    //fprintf(f, "%s", mensaje);
    //fscanf(f,"%s", cadena);

   // while( !feof(f)){
    //fgets(cadena, 29, f);
    //auxChar = fgetc(f);
    //printf("%s", cadena);
    //printf("%c", auxChar);
   // fread(cadena, sizeof(char), 29, f);

  //  printf("%s", cadena);

   // }



    fclose(f);

    return 0;
}
