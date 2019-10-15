#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED

int cargarDescMarca(int id, eMarca marcas[], int tam, char desc[]);
/** \brief Carga la descripcion de la marca para mostrarlo en char y no por id
 *
 * \param id de la marca
 * \param estructura de marcas
 * \param tam de la estructura de marcas
 * \param vector para cargar la descripcion
 * \return 1 si cargo la marca perfectamente o 0 si no pudo cargarla
 *
 */
void mostrarMarcas(eMarca marcas[], int tam);
/** \brief Muestra un listado de las marcas
 *
 * \param estructura de marcas
 * \param tam de la estructura de marcas
 */
void mostrarMarca(eMarca marcas);
/** \brief muestra la descripcion de UNA marca
 *
 * \param un indice de la estructura de marcas, ejemplo marcas[i].
 *
 */

