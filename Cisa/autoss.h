#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;
#endif // AUTOS_H_INCLUDED
int hardcodearAutos( eAuto vec[], int tam, int cantidad);
void inicializarAutos(eAuto autos[], int tam);
void mostrarAutos (eAuto autos[], int tam,  eColor colores[], int tamColor, eMarca marcas[], int tamMarcas);
eAuto newAuto(int id,char patente[],int idMarca,int idColor,int modelo);
int buscarLibre(eAuto vec[], int tam);
int altaAuto(eAuto autos[], int tam , eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);
int buscarPatente(char patente[], eAuto autos[], int tam);
int modificarAuto(eAuto autos[], int tam,eColor colores[], int tamColores,eMarca marcas[],int tamMarcas);
int bajaAuto (eAuto autos[], int tam, eColor colores[], int tamColores,eMarca marcas[], int tamMarcas);
