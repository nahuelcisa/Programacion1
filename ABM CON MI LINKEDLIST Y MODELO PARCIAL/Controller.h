int controller_loadFromText(char* path , LinkedList* pArrayListDominio);
int controller_loadFromBinary(char* path , LinkedList* pArrayListDominio);
int controller_addDominio(LinkedList* pArrayListDominio);
int controller_editDominio(LinkedList* pArrayListDominio);
int controller_removeDominio(LinkedList* pArrayListDominio);
int controller_ListDominio(LinkedList* pArrayListDominio);
int controller_sortDominio(LinkedList* pArrayListDominio);
int controller_saveAsText(char* path , LinkedList* pArrayListDominio);
int controller_saveAsBinary(char* path , LinkedList* pArrayListDominio);
int menuModificacion();

