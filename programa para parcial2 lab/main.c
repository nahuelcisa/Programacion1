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
    char rta = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = NULL;
    listaEmpleados2 = ll_newLinkedList();
    int flag = 0;
    int flag2 = 0;


    if( listaEmpleados == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    do
    {
        switch(menu())
        {

        case 1:
            if(flag == 0)
            {

                if(controller_loadFromText("data.csv",listaEmpleados))
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
                if(controller_loadFromBinary("data.bin",listaEmpleados))
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
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 4:
            if(flag)
            {
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("Modificacion exitosa\n");
                }
                else if(controller_editEmployee(listaEmpleados) == -1)
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
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 6:
            if(flag)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 7:
            if(flag)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados cargados.\n");
            }
            break;
        case 8:
            if(flag)
            {
                if(controller_saveAsText("data.csv",listaEmpleados))
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
                if(controller_saveAsBinary("data.bin",listaEmpleados))
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
            if(flag)
            {
                if(controller_ClearList(listaEmpleados))
                {
                    printf("Lista vaciada con exito\n");
                }
            }
            else
            {
                printf("Hubo un error.\n");
            }
            break;
        case 11:
            if(flag)
            {
                if(controller_DeleteList(listaEmpleados))
                {
                    printf("Lista Eliminada con exito\n");
                }
            }
            else
            {
                printf("Hubo un error.\n");
            }
            break;
        case 12:
            if(flag)
            {
                if(mostrarEmpleadoEspecifico(listaEmpleados))
                {
                    printf("Empleado mostrado con exito\n");
                }
            }
            else
            {
                printf("Hubo un error.\n");
            }
            break;
        case 13:
            if(controller_isEmpty(listaEmpleados))
            {
                    printf("La lista esta vacia.\n");
            }
            else if(!controller_isEmpty(listaEmpleados))
            {
                printf("La lista tiene por lo menos un elemento cargado.\n");
            }
            break;
        case 14:
            if(flag)
            {
            if(controller_addEmployeePush(listaEmpleados))
            {
                    printf("Empleado agregado con exito.\n");
            }
            else
            {
                printf("Hubo un error.\n");
            }
            }
            break;
        case 15:
            if(flag)
            {
            if(!mostrarEmpleadoEspecificoYelimina(listaEmpleados))
            {
                    printf("Hubo un error.\n");
            }
            }
            break;
        case 16:
            if(flag)
            {
                listaEmpleados2 = controller_CloneList(listaEmpleados);
                flag2 = 1;
                printf("Lista clonada con exito.\n");
            }
            break;
        case 17:
            if(flag)
            {
                listaEmpleados2 = controller_SubList(listaEmpleados);
                flag2 = 1;
                printf("Lista clonada con exito.\n");
            }
            break;
        case 18:
            if(flag2)
            {
                if(controller_Contains(listaEmpleados2)){
                    printf("El elemento se encuentra en la lista.\n");
                }else{
                    printf("El elemento no se encuentra en la lista.\n");
                }

            }else{
                printf("Primero debe clonar la lista 1.\n");
            }
            break;
        case 19:
            if(flag && controller_ContainsAll(listaEmpleados,listaEmpleados2))
            {
                printf("La lista 1 contiene todos los elementos de la lista 2\n");
            }else{
                printf("La lista 1 NO contiene todos los elementos de la lista 2\n");
            }
            break;
        case 20:
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
    printf("10. Borrar todos los empleados de la lista.\n");
    printf("11. Eliminar la lista por completo.\n");
    printf("12. Mostrar un empleado en especifico.\n");
    printf("13. Saber si hay empleados cargado.\n");
    printf("14. Dar de alta un empleado en un indice de la lista en especifico.\n");
    printf("15. Mostrar un empleado en especifico y eliminarlo de la lista.\n");
    printf("16. Crear una nueva lista identica a la actual.\n");
    printf("17. Crear una nueva lista con el rango de empleados elegido.\n");
    printf("18. Una vez copiada la lista 2, saber si se copio un empleado en especifico.\n");
    printf("19. saber si todos los elementos de la lista 2 se encuentran en la lista 1.\n");
    printf("20. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
