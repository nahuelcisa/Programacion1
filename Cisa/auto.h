#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;

#endif // AUTO_H_INCLUDED

int hardcodearAutos( eAuto vec[], int tam, int cantidad);
/** \brief hardcodea los indices que el usuario quiera y mientras esten cargados en la funcion con el fin de testear el ABM
 *
 * \param estructura de autos
 * \param tam de la estructura autos
 * \param cantidad de indices que se quieran hardcodear
 * \return cantidad de autos hardcodeados excitosamente
 *
 */
void inicializarAutos(eAuto autos[], int tam);
/** \brief pone los campos isEmpty de todos los indices de la estructura autos en 1 para inicializar el ABM
 *
 * \param estructura de autos
 * \param tam de la estructura de autos
 *
 */
void mostrarAutos (eAuto autos[], int tam,  eColor colores[], int tamColor, eMarca marcas[], int tamMarcas);
/** \brief Muestra un listado de los autos
 *
 * \param estructura de autos
 * \param tam de la estructura de autos
 * \param estructura de colores
 * \param tam de la estructura de colores
 * \param estructuras de marcas
 * \param tam de la estructura de marcas
 */
eAuto newAuto(int id,char patente[],int idMarca,int idColor,int modelo);
/** \brief inserta un nuevo indice a la estructura autos con datos cargados
 *
 * \param id del auto
 * \param patente
 * \param id de la marca
 * \param id del color
 * \param modelo del auto
 * \return un indice completo de estructura auto para ponerlo en un indice de la estructura del main
 *
 */
int buscarLibre(eAuto vec[], int tam);
/** \brief recorre la estructura autos para buscar un indice libre para informar si es posible cargar un nuevo auto o no al sistema
 *
 * \param estructura de autos
 * \param tam de la estructura de autos
 * \return si pudo encontrarse un indice vacio, devuelve el indice, de lo contrario devuelve -1
 *
 */
int altaAuto(eAuto autos[], int tam , eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);
/** \brief da de alta un auto si el sistema lo permite, buscando libre mediante la funcion buscar libre
 *
 * \param estructura de autos
 * \param tam estructura autos
 * \param estructura de marcas
 * \param tam estructura marcas
 * \param estructura de colores
 * \param tam estructura colores
 * \return 1 si la alta del auto fue excitosa o 0 si no se cargo excitosamente.
 *
 */
int buscarPatente(char patente[], eAuto autos[], int tam);
/** \brief busca en la estructura autos si hay una patente igual a la pasada por parametro
 *
 * \param vector el cual tenga la patente a buscar cargada
 * \param estructura de autos
 * \param tam estructura de autos
 * \return si la busqueda fue excitosa, devuelve el indice en el que se encuentra esa patente, si la patente no fue encontrada, devuelve -1
 *
 */
int modificarAuto(eAuto autos[], int tam,eColor colores[], int tamColores,eMarca marcas[],int tamMarcas);
/** \brief modifica un campo de la estructura autos en un indice en especifico
 *
 * \param estructura de autos
 * \param tam estructura autos
 * \param estructura de colores
 * \param tam estructura colores
 * \param estructura de marcas
 * \param tam estructura marcas
 * \return 1 si la modificacion del auto fue excitosa o 0 si no se modifico excitosamente.
 *
 */
int bajaAuto (eAuto autos[], int tam, eColor colores[], int tamColores,eMarca marcas[], int tamMarcas);
/** \brief da la baja logica de un auto cambiando el campo isEmpty a 1
 *
 * \param estructura de autos
 * \param tam estructura autos
 * \param estructura de colores
 * \param tam estructura colores
 * \param estructura de marcas
 * \param tam estructura marcas
 * \return 1 si la baja del auto fue excitosa o 0 si no se bajo excitosamente.
 *
 */
int buscarIdAuto(int id, eAuto autos[], int tam);
/** \brief busca en la estructura autos si hay un idAuto igual a la pasada por parametro
 *
 * \param ID a buscar en la estructura autos
 * \param estructura de autos
 * \param tam estructura de autos
 * \return si la busqueda fue excitosa, devuelve el indice en el que se encuentra ese ID, si el ID no fue encontrada, devuelve -1
 *
 */

 void mostrarAuto(eAuto x, eMarca marcas[], int tam, eColor colores[]);
 /** \brief muestra la informacion de un auto
  *
  * \param estructura autos
  * \param estructura marcas
  * \param tam vector
  * \param estructura de colores
  *
  */

