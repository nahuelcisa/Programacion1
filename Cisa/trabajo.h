#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    char patente[20];
    int idServicio;
    int isEmpty;
    eFecha fecha;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

eTrabajo newtrabajo(int id,char patente[],int idServicio,eFecha fecha);
/** \brief inserta un nuevo indice a la estructura trabajo con datos cargados
 *
 * \param id del trabajo
 * \param patente del vehiculo
 * \param id del servicio
 * \param fecha
 * \return un indice completo de estructura trabajo para ponerlo en un indice de la estructura del main
 *
 */

void mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos,  eServicio servicios[], int tamServicio);
/** \brief Muestra un listado de los trabajos
 *
 * \param estructura de trabajos
 * \param tam de la estructura de trabajos
 * \param estructura de servicios
 * \param tam de la estructura de servicios
 */
void mostrarTrabajo (eTrabajo trabajos,eServicio servicios[], int tamServicios);
/** \brief muestra la descripcion de UN trabajo
 *
 * \param un indice de la estructura de trabajos, ejemplo trabajos[i].
 * \param estructura de servicios
 * \param tam de la estructura de servicios
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamTrabajos, int idTrabajo, eAuto autos[], int tamAutos, eServicio servicios[], int tamServicios, eColor colores[], int tamColores, eMarca marcas[], int tamMarcas);
/** \brief da de alta un trabajo
 *
 * \param estructura de trabajos
 * \param tam estructura trabajos
 * \param id del trabajo
 * \param estructura de autos
 * \param tam estructura autos
 * \param estructura de servicios
 * \param tam estructura servicios
 * \param estructura de colores
 * \param tam estructura colores
 * \param estructura de marcas
 * \param tam estructura marcas
 * \return 1 si la alta del trabajo fue excitosa o 0 si no se cargo excitosamente.
 *
 */

void inicializarTrabajos(eTrabajo trabajos[], int tam);
/** \brief pone los campos isEmpty de todos los indices de la estructura trabajos en 1 para inicializar el ABM
 *
 * \param estructura de trabajos
 * \param tam de la estructura de trabajos
 *
 */

 int hardcodearTrabajos( eTrabajo trabajos[], int tamTrabajo, int cantidad);
/** \brief hardcodea los indices que el usuario quiera y mientras esten cargados en la funcion con el fin de testear el ABM
 *
 * \param estructura de trabajos
 * \param tam de la estructura trabajos
 * \param cantidad de indices que se quieran hardcodear
 * \return cantidad de trabajos hardcodeados excitosamente
 *
 */

