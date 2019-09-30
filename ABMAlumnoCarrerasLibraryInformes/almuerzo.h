#include "alumno.h"
#include "comida.h"

#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{
    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;
#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo vec[], int tam);
int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComidas comidas[], int tamC);
void mostrarAlmuerzo(eAlmuerzo x, eComidas comidas[], int tam);
eAlmuerzo newAlmuerzo(int id,int leg, int idComida, eFecha fecha);
int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzo, int idAlmuerzo, eAlumno alumnos[], int tAlumnos, eComidas comidas[], int tComida, eCarrera carreras[], int tCarrera);
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);
