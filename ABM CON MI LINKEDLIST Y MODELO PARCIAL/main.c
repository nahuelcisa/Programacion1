#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Dominio.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
    char rta = 'n';
    LinkedList* listaDominio = ll_newLinkedList();
    int flag = 0;
    char path[20];
    char extension[5] = ".csv";

    if( listaDominio == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese nombre del archivo: ");
    fflush(stdin);
    gets(path);

    strcat(path,extension);

    do
    {
        switch(menu())
        {

        case 1:
            if(flag == 0)
            {

                if(controller_loadFromText(path,listaDominio))
                {
                    printf("Empleados cargados con exito\n");
                }
                flag = 1;
            }
            else
            {
                printf("Los empleados ya han sido cargados.\n");
            }
            break;
        case 2:
            if(flag ==0)
            {
                if(controller_loadFromBinary("datos.bin",listaDominio))
                {
                    printf("Empleados cargados con exito\n");
                }
                flag = 1;
            }
            else
            {
                printf("Los empleados ya han sido cargados.\n");
            }
            break;
        case 3:
            if(flag)
            {
                controller_addDominio(listaDominio);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 4:
            if(flag)
            {
                if(controller_editDominio(listaDominio))
                {
                    printf("Modificacion exitosa\n");
                }
                else if(controller_editDominio(listaDominio) == -1)
                {
                    printf("Se cancelo la modificacion\n");
                }
                else
                {
                    printf("Error. no se completo la modificacion\n");
                }
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 5:
            if(flag)
            {
                controller_removeDominio(listaDominio);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 6:
            if(flag)
            {
                controller_ListDominio(listaDominio);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 7:
            if(flag)
            {
                controller_sortDominio(listaDominio);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 8:
            if(flag)
            {
                if(controller_saveAsText(path,listaDominio))
                {
                    printf("Empleados Guardados en modo texto con exito\n");
                }
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 9:
            if(flag)
            {
                if(controller_saveAsBinary("datos.bin",listaDominio))
                {
                    printf("Empleados Guardados en modo binario con exito\n");
                }
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 10:
            printf("Confirma salida? s/n ");
            fflush(stdin);
            rta = getchar();
            break;
        default:
            printf("opcion invalida.\n");
            break;

        }

        system("pause");
        system("cls");

    }
    while(rta != 's');
    return 0;
}

int menu()
{
    int opcion;

    printf("*****       Menu De Inicio      *****\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
