#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int mostrarEmpleado( Employee* e)
{
    int todoOk = 0;

    if( e != NULL)
    {

        printf("%d %s %d %d\n", e->id, e->nombre, e->horasTrabajadas,e->sueldo);
        todoOk = 1;
    }

    return todoOk;

}
