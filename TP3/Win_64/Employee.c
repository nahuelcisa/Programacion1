#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>

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

Employee* employee_new()
{
    Employee* nuevo = (Employee*) malloc( sizeof(Employee));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0;
    }
    return nuevo;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevo = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);

    if( nuevo != NULL)
    {
        if(employee_setId(nuevo, id) &&
                employee_setNombre(nuevo, nombreStr)&&
                employee_setHorasTrabajadas(nuevo,horasTrabajadas)&&
                employee_setSueldo(nuevo, sueldo))
        {
            // printf("Empleado creado correctamente\n");
        }
        else
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}


int employee_setId(Employee* this,int id){

    int todoOk = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if( this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int todoOk = 0;
    if( this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}
