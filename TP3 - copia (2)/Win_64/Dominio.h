#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char dominio[128];
    int anio;
    char tipo;
}eDominio;

eDominio* dominio_new();

eDominio* dominio_newParametros(char* idStr,char* dominioStr,char* anioStr,char tipo);

//void employee_delete();

int dominio_setId(eDominio* this,int id);
int dominio_getId(eDominio* this,int* id);

int dominio_setDominio(eDominio* this,char* dominio);
int dominio_getDominio(eDominio* this,char* dominio);

int dominio_setAnio(eDominio* this,int anio);
int dominio_getAnio(eDominio* this,int* anio);

int dominio_setTipo(eDominio* this,char tipo);
int dominio_getTipo(eDominio* this,char* tipo);

int mostrarDominio( eDominio* e);

int sortByID(void*, void*);
int sortByDominio(void*, void*);
int sortByAnio(void*, void*);
int sortByTipo(void*, void*);
#endif // employee_H_INCLUDED
