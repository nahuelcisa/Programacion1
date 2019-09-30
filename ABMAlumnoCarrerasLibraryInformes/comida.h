#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eComidas;
#endif // COMIDA_H_INCLUDED

void mostrarComidas(eComidas comidas[], int tam);
void mostrarComida (eComidas comidas);
int cargarDescComida(int id, eComidas comidas[], int tam, char desc[]);
