#include <stdio.h>
#include <stdlib.h>

int getIntRange(char*,char*, int, int, int , int);

int main()
{


    printf("%d",getIntRange("Ingrese nota ", "Error. Ingrese nota valida. ", 1,10,3,-1));


    return 0;
}

int getIntRange(char* mensaje, char* mensajeError, int min, int max, int intentos, int retornoError){

    int num;
    int contador = 0;

    printf("%s", mensaje);
    scanf("%d", &num);


        while(num < min || num > max){

        printf("%s", mensajeError);
        scanf("%d", &num);



        if(contador==intentos){
            break;
        }

        contador++;
    }


    if(contador == intentos){
        return retornoError;
    }else{
    return num;
    }
}


