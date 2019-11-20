#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"
#include "Dominio.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListDominio)
{
    int todoOk = 0;
    FILE* f;
    char buffer[3][100];
    int cant;
    int cont = 0;
    eDominio* aux = NULL;

    if(path != NULL && pArrayListDominio != NULL)
    {

        f = fopen(path, "r");

        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return todoOk;
        }
        fscanf(f,"%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

        while(!feof(f))
        {
//fscanf devuelve la cantidad de variables que pudo leer

            cant = fscanf(f,"%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

            if( cant == 3)
            {
                aux = dominio_newParametros(buffer[0], buffer[1], buffer[2],' ');
//atoi hace el parseint, convierte string a int, atof lo mismo pero en float
                if( aux != NULL)
                {
                    ll_add(pArrayListDominio,aux);
                    cont++;

                }
            }
            else
            {
                break;
            }
            printf("CONTADOR VALE: %d",cont);
        }

        todoOk = 1;
    }

    int tam;
    tam = ll_len(pArrayListDominio);
    printf("%d ",tam);
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListDominio)
{
    int todoOk = 0;
    FILE* f;
    int cant;
    eDominio* aux = NULL;

    if(path != NULL && pArrayListDominio != NULL)
    {

        f = fopen(path, "rb");

        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return todoOk;
        }


        while(!feof(f))
        {
            aux = dominio_new();
            if(aux != NULL){
           cant =  fread( aux , sizeof(eDominio),    1   ,  f );

            if(cant == 1){
                ll_add(pArrayListDominio,aux);
        }

    }else{
        break;
    }
        }
        fclose(f);
        todoOk = 1;
    }

    int tam;
    tam = ll_len(pArrayListDominio);
    printf("%d ",tam);
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addDominio(LinkedList* pArrayListDominio)
{
    int todoOk = 0;
    char buffer[3][20];
    char tipo;
    eDominio* filtro = NULL;
    int flagFor = 0;

    if(pArrayListDominio != NULL){

        printf("        ********        ALTA DOMINIO       ********       \n\n\n");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(buffer[0]);
        for(int i = 0;i<ll_len(pArrayListDominio);i++){
            filtro = (eDominio*) ll_get(pArrayListDominio,i);
            if(filtro->id == atoi(buffer[0])){
                printf("ID YA CARGADA EN EL SISTEMA\n");
                flagFor = 1;
                break;
            }
        }
        if(flagFor == 1 ){
            while(filtro->id == atoi(buffer[0])){
                printf("Reingrese un ID valido:");
                fflush(stdin);
                gets(buffer[0]);
            }
        }

        printf("Ingrese dominio:");
        fflush(stdin);
        gets(buffer[1]);

        printf("Ingrese anio:");
            fflush(stdin);
            gets(buffer[2]);
        while(atoi(buffer[2])< 0){
            printf("ERROR. El anio no puede ser menor a 0.\nReingrese:");
            fflush(stdin);
            gets(buffer[2]);
        }
        printf("Ingrese Tipo:");
            fflush(stdin);
            scanf("%c",&tipo);


        ll_add(pArrayListDominio,dominio_newParametros(buffer[0],buffer[1],buffer[2],tipo));

        todoOk = 1;

    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editDominio(LinkedList* pArrayListDominio)
{
    int todoOk = 0;
    char buffer[1][20];
    eDominio* filtro = NULL;
    eDominio* aux = NULL;
    char flagFor = 'n';
    int nuevoID;
    char nuevoDominio[30];
    int nuevoAnio;
    char nuevoTipo;

    if(pArrayListDominio != NULL){

        printf("        ********        MODIFICACION DOMINIO       ********       \n\n\n");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(buffer[0]);
        for(int i = 0;i<ll_len(pArrayListDominio);i++){
            filtro = (eDominio*) ll_get(pArrayListDominio,i);
            if(filtro->id == atoi(buffer[0])){
                printf("Id   Dominio   Anio   Tipo\n\n");
                mostrarDominio(filtro);
                printf("confirma? \ns/n\nElija opcion:");
                flagFor = getchar();
                break;

            }
        }
if(flagFor == 's'){
        switch(menuModificacion()){

        case 1:
                printf("Ingrese nuevo ID: ");
                scanf("%d",&nuevoID);
                for(int i = 0; i< ll_len(pArrayListDominio);i++){
                    aux = (eDominio*) ll_get(pArrayListDominio,i);
                    if(aux->id == nuevoID){
                        while(aux->id == nuevoID){
                            printf("ERROR. id ya cargado en el sistema. reingrese:");
                            scanf("%d",&nuevoID);
                        }
                    }

                }
                filtro->id = nuevoID;
            break;

        case 2:
                printf("Ingrese nuevo Dominio: ");
                fflush(stdin);
                gets(nuevoDominio);
                strcpy(filtro->dominio,nuevoDominio);
            break;

        case 3:
                printf("Ingrese nuevo anio: ");
                scanf("%d",&nuevoAnio);
                while(nuevoAnio<0){
                    printf("ERROR. El anio no puede ser menor a cero. Reingrese:");
                    scanf("%d",&nuevoAnio);
                }
                filtro->anio = nuevoAnio;
            break;

        case 4:
                printf("Ingrese nuevo tipo: ");
                scanf("%c",&nuevoTipo);
                filtro->tipo = nuevoTipo;
            break;

        case 5:
                todoOk = -1;
                return todoOk;
            break;


        default:
            printf("Opcion invalida.");
            break;
        }

}else{
        todoOk = -1;
        return todoOk;
}

        todoOk = 1;

    }


    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeDominio(LinkedList* pArrayListDominio)
{

    int todoOk = 0;
    char buffer[1][20];
    eDominio* filtro = NULL;
    int flagFor = 0;
    int indice;

    if(pArrayListDominio != NULL){

        printf("        ********        BAJA DOMINIO       ********       \n\n\n");
        printf("Ingrese ID:");
        fflush(stdin);
        gets(buffer[0]);
        for(int i = 0;i<ll_len(pArrayListDominio);i++){
            filtro = (eDominio*) ll_get(pArrayListDominio,i);
            if(filtro->id == atoi(buffer[0])){
                printf("confirma? \n1: si\n0: cancelar\nElija opcion:");
                scanf("%d",&flagFor);
                indice = i;
                break;

            }
        }
        if(flagFor == 1){
            ll_remove(pArrayListDominio,indice);
            printf("Dominio dado de baja exitosamente\n\n");
        }else{
            printf("Se cancelo la operacion\n\n");
        }
            todoOk = 1;

        }



    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListDominio(LinkedList* pArrayListDominio)
{
    int todoOk = 0;
    eDominio* aux;
    int flag = 0;
    if(pArrayListDominio != NULL)
    {

        printf("Id   Dominio   Anio   Tipo\n\n");
        for( int i=0; i < ll_len(pArrayListDominio); i++)
        {
            aux = (eDominio*) ll_get(pArrayListDominio,i);
            mostrarDominio(aux);
            flag = 1;
        }
        if(flag == 0){
            printf("No hay dominios cargados para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortDominio(LinkedList* pArrayListDominio)
{

    int todoOk = 0;
    int opcion;
    char rta = 'n';
    int orden;

    if(pArrayListDominio != NULL){

        printf("        ********        ORDENAR Dominios       ********       \n\n\n");
        printf("1- Ordenar por ID\n");
        printf("2- Ordenar por Dominio\n");
        printf("3- Ordenar por Anio\n");
        printf("4- Ordenar por Tipo\n");
        printf("5- Volver al menu\n");
        printf("Elija opcion:");
        scanf("%d",&opcion);

        switch(opcion){

        case 1:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListDominio,sortByID,orden);
            break;

        case 2:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListDominio,sortByDominio,orden);
            break;

        case 3:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListDominio,sortByAnio,orden);
            break;

        case 4:
            printf("Ordena de forma descendente o ascendente?\n1 ascendente 0 descendente: ");
            scanf("%d",&orden);
            ll_sort(pArrayListDominio,sortByTipo,orden);
            break;
        case 5:
            printf("Confirma? s/n ");
            fflush(stdin);
            rta = getchar();
            if(rta == 's'){
                break;
            }
            break;

        default:
            printf("Opcion incorrecta.\n");
            system("pause");
            break;
        }

     todoOk = 1;
}
        return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListDominio)
{

    int todoOk = 0;
    int cant;
    FILE* f;
    eDominio* aux = NULL;

    if(pArrayListDominio!= NULL && path != NULL ){

        f = fopen(path,"w");
        if(f == NULL){
            return todoOk;
        }
        fprintf(f,"id,dominio,anio,tipo\n");
        for(int i = 0; i < ll_len(pArrayListDominio); i++){
            aux = ll_get(pArrayListDominio,i);
            cant = fprintf(f,"%d,%s,%d,%c\n",aux->id,aux->dominio,aux->anio,aux->tipo);
            if(cant < 1){
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListDominio)
{
    int todoOk = 0;
    int cant;
    FILE* f;

    if(pArrayListDominio!= NULL && path != NULL ){

        f = fopen(path,"wb");
        if(f == NULL){
            return todoOk;
        }
        for(int i = 0; i < ll_len(pArrayListDominio); i++){
            cant = fwrite( ll_get(pArrayListDominio,i) , sizeof(eDominio)  ,   1  , f);
            if(cant < 1){
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }

    return todoOk;

}

int menuModificacion(){

    int opcion;

    printf("    *****   MENU MODIFICACION   *****\n\n\n");
    printf("1- Modificar ID\n");
    printf("2- Modificar Dominio\n");
    printf("3- Modificar Anio\n");
    printf("4- Modificar Tipo\n");
    printf("5- Volver al menu\n");
    printf("Elija opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

