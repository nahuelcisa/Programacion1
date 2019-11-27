#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "cachorro.h"
#include "controller.h"

int main()
{

    char rta = 'n';
    int flag = 0;
    LinkedList* lista = ll_newLinkedList();
    char archivo[20];
    char extension[10] = ".csv";

    do{

        switch(menu()){

    case 1:
        if(!flag){
        printf("Ingrese nombre del archivo: ");
        fflush(stdin);
        gets(archivo);
        strcat(archivo,extension);
        if(cargarArchivo(lista,archivo)){
            printf("%d Cachorros cargados con exito.\n",ll_len(lista));
        }
            flag = 1;
        }else{
            printf("Los cachorros ya estan cargados.\n");
        }
        break;
    case 2:
        if(flag){
        listarCachorros(lista);
        }else{
            printf("Primero hay que cargar los cachorros.\n");
        }
        break;
    case 3:
        if(flag){
            if(archivoMayores(lista)){
                printf("Se creo un archivo con los cachorros mayores a 45 dias.\n");
            }
        }else{
            printf("Primero hay que cargar los cachorros.\n");
        }
        break;
    case 4:
        if(flag){
            if(archivosNoMachos(lista)){
                printf("Se creo un archivo con los cachorros hembras.\n");
            }
        }else{
            printf("Primero hay que cargar los cachorros.\n");
        }
        break;
    case 5:
        if(flag){
            if(!(mostrarCallejeros(lista))){
                printf("Primero hay que cargar los cachorros.\n");
            }
        }
        break;
    case 6:
            printf("Confirma salida? s/n:");
            fflush(stdin);
            rta = getchar();
        break;
    default:

        printf("Opcion incorrecta\n\n");
        }

        system("pause");
        system("cls");

    }while(rta != 's');

    return 0;
}

