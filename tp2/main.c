#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 10

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} employee;
//funciones para menu
int menu();

//funciones para empleados
void mostrarEmpleado(employee x);
void mostrarEmpleados(employee vec[], int tam);
void inicializarEmpleados(employee vec[], int tam);
int hardcodearEmpleados(employee vec[], int tam, int cantidad);
int buscarLibre(employee vec[], int tam);
employee newEmpleado(int id,char nombre[],char apellido[],float salario,int sector);
int altaEmpleado(employee vec[], int tam, int id);
int buscarEmpleado (int id, employee vec[], int tam);
int modificarEmpleado(employee empleado[], int tam);
int bajaEmpleado(employee vec[], int tam);
void ordenarEmpleados(employee empleados[],int tam);
void salarioPromedio(employee empleados[], int tam);
void informeEmpleado(employee empleados[],int tam);

int main()
{
    int id = 20000;
    char salir = 'n';
    employee empleados[TAM];
    inicializarEmpleados(empleados,TAM);
    id = id + hardcodearEmpleados(empleados,TAM,9);

    do{
        switch(menu())
        {
        case 1:
            if(altaEmpleado(empleados,TAM,id)){
                id++;
            }
            break;
        case 2:
            modificarEmpleado(empleados,TAM);
            break;
        case 3:
            bajaEmpleado(empleados,TAM);
            break;
        case 4:
            informeEmpleado(empleados,TAM);
            break;

        case 5:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            printf("\n\n");
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }while(salir == 'n');

    return 0;
}

int menu(){

    int opcion;

    system("cls");
    printf("****** ABM Empleados *******\n\n");
    printf("1-Alta Empleado\n");
    printf("2-Modificar Empleado\n");
    printf("3-Baja Empleado\n");
    printf("4-Informes Empleados\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(employee x){

    printf(" %d  %10s       %10s      %10.2f       %2d\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector
           );
}

void mostrarEmpleados(employee vec[], int tam){

    int flag = 0;

    system("cls");

    printf(" Id          Nombre         Apellido        Salario     Sector \n\n");

    for(int i = 0; i<tam;i++){

        if(vec[i].isEmpty == 0){
        mostrarEmpleado(vec[i]);
        flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay Empleados que mostrar\n");
    }

    printf("\n\n");
}

void inicializarEmpleados(employee vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int hardcodearEmpleados(employee vec[], int tam, int cantidad)
{
    int cont = 0;

    employee suplentes[]=
    {
        { 20000, "Juan", "Mendez", 15432.69, 1,0},
        { 20001, "Elias", "Calvo", 16733.20, 3,0},
        { 20002, "Kevin", "Rodriguez", 10513.32, 2,0},
        { 20003, "Sebastian", "Sosa", 23756.78, 5,0},
        { 20004, "Giuliana", "Perez", 19265.48, 1,0},
        { 20005, "Carlos", "Ruiz", 5923.90, 2,0},
        { 20006, "Nahuel", "Cisa", 14839, 3,0},
        { 20007, "Raul", "Diaz", 9156.67, 5,0},
        { 20008, "Marcelo", "Di Toro", 21598.07, 1,0},
        { 20009, "Ernesto", "Cabalo", 18956.24, 2,0},
        { 20010, "Pablo", "Lezcano", 23589.68, 4,0}
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

int altaEmpleado(employee vec[], int tam, int id){

    int todoOk = 0;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int indice;

    system("cls");

    printf("*****Alta Empleado*****\n\n");
    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(apellido);

        printf("Ingrese salario: ");
        fflush(stdin);
        scanf("%f", &salario);

        printf("Ingrese sector: ");
        scanf("%d", &sector);

        vec[indice] = newEmpleado(id,nombre,apellido,salario,sector);
        todoOk = 1;
        system("cls");
        printf("\nAlta Excitosa!\n\n");
    }
    return todoOk;
}

int buscarLibre(employee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

employee newEmpleado(int id,char nombre[],char apellido[],float salario,int sector)
{

    employee al;

    al.id = id;
    strcpy( al.name, nombre);
    strcpy( al.lastName, apellido);
    al.salary = salario;
    al.sector = sector;
    al.isEmpty = 0;

    return al;
}



int modificarEmpleado(employee empleado[], int tam){

    int todoOk = 0;
    int id;
    int indice;
    system("cls");
    printf("***** Modificar Empleado *****\n\n");
    mostrarEmpleados(empleado,tam);
    printf("\nIngrese id: ");
    scanf("%d", &id);
    int opcion;

    indice = buscarEmpleado(id,empleado,tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }else{
        system("cls");
        printf(" Id          Nombre         Apellido        Salario     Sector \n\n");
        mostrarEmpleado(empleado[indice]);
        printf("\n\n");
        printf("1- Modificar Nombre\n");
        printf("2- Modificar Apellido\n");
        printf("3- Modificar Salario\n");
        printf("4- Modificar Sector\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
    case 1:
            printf("Ingrese Nuevo Nombre: ");
            fflush(stdin);
            gets(empleado[indice].name);
            break;
    case 2:
            printf("Ingrese Nuevo Apellido: ");
            fflush(stdin);
            gets(empleado[indice].lastName);
            break;
    case 3:
            printf("Ingrese Nuevo Salario: ");
            fflush(stdin);
            scanf("%f",&empleado[indice].salary);
            break;
    case 4:
            printf("Ingrese Nuevo Sector: ");
            fflush(stdin);
            scanf("%d",&empleado[indice].sector);
            break;
    case 5:
            printf("Se ha cancelado la modificacion ");
            break;

    }
    todoOk = 1;
    system("cls");
    printf("\nModificacion excitosa!!\n\n");
}
    return todoOk;
}


int buscarEmpleado (int id, employee vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaEmpleado(employee vec[], int tam){

    int todoOk = 0;
    int indice;
    char confirma;
    int id;

    system("cls");
    printf("*****Baja Empleado*****\n\n");
    mostrarEmpleados(vec,tam);
    printf("Ingrese ID: ");
    scanf("%d", &id);
    indice = buscarEmpleado(id,vec,tam);

    if( indice == -1)
    {
        printf("No existe un empleado con ese numero de ID\n\n");
    }
    else
    {
        printf(" Id          Nombre         Apellido        Salario     Sector \n\n");
        mostrarEmpleado(vec[indice]);
        printf("\n\n");
        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }
    return todoOk;
}

void ordenarEmpleados(employee empleados[],int tam){

    employee auxiliar;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if(strcmp(empleados[i].lastName,empleados[j].lastName) == 1){

                auxiliar = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = auxiliar;
            }
        }
}
    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if(empleados[i].sector > empleados[j].sector){

                auxiliar = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = auxiliar;
            }
        }
}
    printf("Empleados ordenados por apellido y sector.\n\n");
    mostrarEmpleados(empleados,tam);
}


void informeEmpleado(employee empleados[],int tam){

    int opcion;
    system("cls");
    printf("*****Informes Empleados*****\n\n");

        printf("1- Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
        printf("2- Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
        printf("3- salir\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:

            ordenarEmpleados(empleados,tam);
            break;
        case 2:
            salarioPromedio(empleados,tam);
            break;
        case 3:
            printf("Volvio al menu.\n\n");
            break;
    }

}

void salarioPromedio(employee empleados[], int tam){

    float promedio;
    int cont = 0;

    for(int i = 0; i < tam; i++){
        promedio = (promedio + empleados[i].salary);
        if(empleados[i].salary > promedio){
            cont ++;
        }
    }

    promedio = promedio / tam;
    for(int i = 0; i < tam; i++){
        if(empleados[i].salary > promedio){
            cont ++;
        }
    }

    printf("El salario promedio es : %.2f\n",promedio);
    printf("La cantidad de empleados que su salario es mayor que el salario promedio es : %d\n",cont);
}
