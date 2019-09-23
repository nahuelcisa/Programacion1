#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 2

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty;
}eAlumno;

void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno alumnos[], int tam);
int buscarLibre(eAlumno alumnos[], int tam);
int buscarAlumno(int legajo, eAlumno alumnos[], int tam);
int altaAlumno(eAlumno alumnos[], int tam);
int altaAlumnoAuto(eAlumno alumnos[], int tam,int legajo);
eAlumno newAlumno (int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha);
int bajaAlumno(eAlumno alumnos[], int tam);
int modificarAlumnoNota(eAlumno alumnos[],int tam);
int menu();
int menuModificarNota();

int main()
{
    eAlumno lista[TAM];
    int legajo = 20000;
    char salir = 'n';
    //int todoOk;

    inicializarAlumnos(lista,TAM);

    do{

        switch(menu()){

    case 1:
            //altaAlumno(lista,TAM);
            if(altaAlumnoAuto(lista,TAM,legajo)){
                legajo++;
            }
        break;
    case 2:
        bajaAlumno(lista,TAM);
        break;
    case 3:
        modificarAlumnoNota(lista,TAM);
        break;
    case 4:
        mostrarAlumnos(lista,TAM);
        break;
    case 5:
        printf("Ordenar Alumnos\n");
        //aca va el alta alumno
        break;
    case 6:
        printf("Informes\n");
        //aca va el alta alumno
        break;
    case 7:
        printf("Confirma salida? s/n: ");
        fflush(stdin);
        salir = getche();
        printf("\n");
        //aca va el alta alumno
        break;
    default:
        printf("Opcion invalida\n\n");
}
    system("pause");

}while(salir == 'n');

    return 0;
}

void mostrarAlumno(eAlumno x){
    printf(" %d%10s    %d    %c      %d     %d      %.2f   %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam){

    int flag = 0;

    printf("Legajo   Nombre   Edad  Sexo  Nota1 Nota2 Promedio  FIngreso\n");
    for(int i=0; i < tam; i++){
            if(vec[i].isEmpty == 0){
        mostrarAlumno(vec[i]);
        flag = 1;
        }
    }

    if(flag == 0){

        printf("\n---No hay alumnos que mostrar.---");
}
printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam){

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++){
        for(int j= i+1; j <tam; j++){
            if( vec[i].legajo > vec[j].legajo){
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

int menu(){

int opcion;

    system("cls");
    printf("Menu de Opciones \n\n");
    printf("1- Alta Alumno\n");
    printf("2- Baja Alumno\n");
    printf("3- Modificar Alumno\n");
    printf("4- Listar Alumno\n");
    printf("5- Ordenar Alumno\n");
    printf("6- Informes\n");
    printf("7- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

return opcion;
}

void inicializarAlumnos(eAlumno alumnos[], int tam){

    for(int i = 0; i < tam; i++){
        alumnos[i].isEmpty = 1;
    }
}

int buscarLibre(eAlumno alumnos[], int tam){

    int indice = -1;

    for(int i = 0; i < tam; i++){
        if(alumnos[i].isEmpty /*== 1*/){
            indice = i;
            break;
        }
    }
        return indice;
}

int buscarAlumno(int legajo, eAlumno alumnos[], int tam){

    int indice = -1;

    for(int i = 0; i < tam; i++){
        if(alumnos[i].isEmpty == 0 && alumnos[i].legajo == legajo){
            indice = i;
            break;
        }
    }
        return indice;
}

int altaAlumno(eAlumno alumnos[], int tam){

    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int nota1;
    int nota2;
    char sexo;
    char nombre[20];

    eFecha fecha;


    indice = buscarLibre(alumnos, tam);

    system("cls");
    printf("**** Alta Alumno ****\n\n");

    if(indice == -1){
        printf("Sistema Completo. No se pueden agregar mas alumnos\n");
        system("pause");
    }else{
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarAlumno(legajo,alumnos,tam);

        if( esta != -1){
            printf("Legajo ya registrado\n");
            mostrarAlumno(alumnos[esta]);
            system("pause");
        }else{
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombre);

                printf("Ingrese edad:");
                fflush(stdin);
                scanf("%d", &edad);

                printf("Ingrese sexo:");
                fflush(stdin);
                scanf("%c",&sexo);

                printf("Ingrese nota parcial 1:");
                fflush(stdin);
                scanf("%d",&nota1);

                printf("Ingrese nota parcial 2:");
                fflush(stdin);
                scanf("%d", &nota2);

                printf("Ingrese fecha ingreso: dd/mm/aaaa ");
                fflush(stdin);
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                    //luego de validar todos los datos, hacer lo que se hace a continuacion:

                alumnos[indice] = newAlumno(legajo,nombre,sexo,edad,nota1,nota2,fecha);
                todoOk = 1;

        }
    }
            return todoOk;
}

eAlumno newAlumno (int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha){

    eAlumno nuevoAlumno;

            nuevoAlumno.legajo = legajo;
            strcpy(nuevoAlumno.nombre,nombre);
            nuevoAlumno.edad = edad;
            nuevoAlumno.sexo = sexo;
            nuevoAlumno.nota1 = n1;
            nuevoAlumno.nota2 = n2;
            nuevoAlumno.promedio = (float) ( n1 + n2 ) / 2;
            nuevoAlumno.fechaIngreso = fecha;
            nuevoAlumno.isEmpty = 0;

            return nuevoAlumno;
}


int bajaAlumno(eAlumno alumnos[], int tam){

    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    system("cls");
    printf("**** Baja Alumno ****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo,alumnos,tam);

    if(indice == -1){
        printf("No tenemos registrado ese legajo.\n");
        system("pause");
    }else{
        mostrarAlumno(alumnos[indice]);
        printf("Confirma baja? s/n: ");
        fflush(stdin);
        confirma = getche();
    }
        if(confirma == 's'){
            alumnos[indice].isEmpty = 1;
            printf("Se ha eliminado el alumno.\n");
            printf("\n\n");
            todoOk = 1;
    }else{
        printf("Se ha cancelado la baja\n");
    }
    system("pause");
    return todoOk;
}

int modificarAlumnoNota(eAlumno alumnos[],int tam){

    int todoOk = 0;
    int indice;
    int legajo;
    int nota1;
    int nota2;
    char confirma;


    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo,alumnos,tam);

    if (indice == -1){

        printf("No tenemos registrado ese legajo.\n");
        system("pause");
    }else{
        mostrarAlumno(alumnos[indice]);
        printf("Confirma alumno? s/n:");
        fflush(stdin);
        confirma = getche();
    }

    if(confirma == 's'){

        switch(menuModificarNota()){

    case 1:
            printf("Ingrese nueva nota: ");
            scanf("%d", &nota1);
            alumnos[indice].nota1 = nota1;
            alumnos[indice].promedio = (float) (alumnos[indice].nota1+alumnos[indice].nota2) / 2;
            break;

    case 2:
            printf("Ingrese nueva nota: ");
            scanf("%d", &nota2);
            alumnos[indice].nota2 = nota2;
            alumnos[indice].promedio = (float) (alumnos[indice].nota1+alumnos[indice].nota2) / 2;
            break;
        }
        todoOk = 1;

    }else{
        printf("Se ha cancelado la operacion.\n");
    }

    return todoOk;
}


int menuModificarNota(){

int opcion;

    system("cls");
    printf("Elija que quiere modificar.\n\n");
    printf("1- Nota primer parcial.\n");
    printf("2- Nota segundo parcial.\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int altaAlumnoAuto(eAlumno alumnos[], int tam,int legajo){

    int todoOk = 0;
    int indice;
    int edad;
    int nota1;
    int nota2;
    char sexo;
    char nombre[20];

    eFecha fecha;


    indice = buscarLibre(alumnos, tam);

    system("cls");
    printf("**** Alta Alumno ****\n\n");

    if(indice == -1){
        printf("Sistema Completo. No se pueden agregar mas alumnos\n");
        system("pause");
    }else{
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombre);

                printf("Ingrese edad:");
                scanf("%d", &edad);

                printf("Ingrese sexo:");
                fflush(stdin);
                scanf("%c",&sexo);

                printf("Ingrese nota parcial 1:");
                scanf("%d",&nota1);

                printf("Ingrese nota parcial 2:");
                scanf("%d", &nota2);

                printf("Ingrese fecha ingreso: dd/mm/aaaa ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                //luego de validar todos los datos, hacer lo que se hace a continuacion:

                alumnos[indice] = newAlumno(legajo,nombre,sexo,edad,nota1,nota2,fecha);
                todoOk = 1;

        }

        return todoOk;
}



