#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int cargarDescColor(int id, eColor colores[], int tam, char desc[]);
/** \brief Carga la descripcion del color para mostrarlo en char y no por id
 *
 * \param id del color
 * \param estructura de colores
 * \param tam de la estructura de colores
 * \param vector para cargar la descripcion
 * \return 1 si cargo la marca perfectamente o 0 si no pudo cargarla
 *
 */
void mostrarColores(eColor colores[], int tam);
/** \brief Muestra un listado de los colores
 *
 * \param estructura de colores
 * \param tam de la estructura de colores
 */
void mostrarColor(eColor colores);
/** \brief muestra la descripcion de UN color
 *
 * \param un indice de la estructura de colores, ejemplo colores[i].
 *
 */
