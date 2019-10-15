#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

void mostrarServicios (eServicio servicios[], int tam);
/** \brief Muestra un listado de los servicios
 *
 * \param estructura de servicios
 * \param tam de la estructura de servicios
 */
void mostrarServicio (eServicio servicios);
/** \brief muestra la descripcion de UN servicio
 *
 * \param un indice de la estructura de servicios, ejemplo servicios[i].
 *
 */
int cargarDescServicio(int id, eServicio servicios[], int tam, char desc[]);
/** \brief Carga la descripcion del servicio para mostrarlo en char y no por id
 *
 * \param id del servicio
 * \param estructura de servicios
 * \param tam de la estructura de servicios
 * \param vector para cargar la descripcion
 * \return 1 si cargo la marca perfectamente o 0 si no pudo cargarla
 *
 */
int buscarIdServicio(int id, eServicio servicios[], int tam);
/** \brief busca en la estructura de servicios un servicio que sea igual al id pasado por parametro
 *
 * \param id del servicio a buscar
 * \param estructura de servicios
 * \param tam de la estructura de servicios
 * \return indice en el cual se encuentra ese servicio con esa id pasada o -1 si no pudo encontrarlo
 *
 */

