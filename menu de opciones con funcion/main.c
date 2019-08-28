#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char menu();

int main()
{
    char seguir = 's';

    do{
            int num1 = 3;
            int num2 = 3;
            int resultado;

    switch(menu()){

     case 'a':
         printf("\nUsted eligio sumar\n");
         system("pause");
         resultado = num1 + num2;
         printf("La suma de ambos numeros es %d", resultado);
         break;

     case 'b':
        printf("\nUsted eligio restar \n");
        //system("pause");
        break;
     case 'c':
        printf("\nUsted eligio multiplicar\n");
        //system("pause");
        break;
     case 'd':
        printf("\nUsted eligio dividir\n");
        //system("pause");
        break;
     case 'e':
        printf("\nUsted eligio salir\n");
        printf("Desea salir? s/n: ");
        fflush(stdin);
        seguir = getche();
        break;

     default:
        printf("\nOpcion invalida\n\n");
        //system("pause");
        break;

     }
        system("pause");


    }while(seguir == 'n');



    return 0;
}


char menu(void){

     char opcion;

     system("cls");
     printf("-------menu de opciones-----\n");
     printf("a- Sumar\n");
     printf("b- Restar\n");
     printf("c- Multiplicar\n");
     printf("d- Dividir\n");
     printf("e- Salir\n");
     printf("-Ingrese opcion: ");
     opcion = getche();

     return(opcion);

}
