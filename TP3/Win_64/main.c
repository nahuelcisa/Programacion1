#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    char rta = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();

    if( listaEmpleados == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)){
                    printf("Empleados cargados con exito\n");
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin",listaEmpleados)){
                    printf("Empleados cargados con exito\n");
                }
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:

                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:

                break;
            case 8:
                if(controller_saveAsText("data.csv",listaEmpleados)){
                    printf("Empleados Guardados en modo texto con exito\n");
                }
                break;
            case 9:
                if(controller_saveAsBinary("data.bin",listaEmpleados)){
                    printf("Empleados Guardados en modo binario con exito\n");
                }
                break;
            case 10:

                break;

        }

        system("pause");
        system("cls");

    }while(rta != 'n');
    return 0;
}

int menu(){
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
