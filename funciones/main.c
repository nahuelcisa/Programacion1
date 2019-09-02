#include <stdio.h>
#include <stdlib.h>

int getIntRange(int*, char*, char*,  int, int, int);

int main()
{
    int numero;
    int todoOk;

    todoOk = getIntRange( &numero, "Ingrese edad ", "Error. Reingrese edad ", 18, 65, 3);

    if( todoOk == 0){
        printf("No ingreso un numero valido");
    }
    else{
        printf("El numero ingresado es %d\n", numero);
    }

    return 0;
}

int getIntRange(int* num, char* mensaje, char* mensajeError, int min, int max, int intentos){

   int auxiliar;
   int todoOk =0;


    printf("%s", mensaje);
    scanf("%d", &auxiliar);


    while( auxiliar < min || auxiliar > max){
              intentos--;
        if( intentos == 0){
            break;
        }

        printf("%s", mensajeError);
        scanf("%d", &auxiliar);

    }
    if( intentos != 0){
        *num = auxiliar;
        todoOk = 1;
    }
    return todoOk;
}
