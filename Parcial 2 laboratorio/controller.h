#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#endif // CONTROLLER_H_INCLUDED
int filtroMenores(void* elemento);
int cargarArchivo(LinkedList* lista, char* path);
int menu(void);
int controller_saveAsText(char* path, LinkedList* e);
int archivoMayores(LinkedList* lista);
int filtroMachos(void* elemento);
int archivosNoMachos(LinkedList* lista);
int filtroCallejeros(void* elemento);
