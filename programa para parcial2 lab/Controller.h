int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_ClearList(LinkedList* pArrayListEmployee);
int controller_DeleteList(LinkedList* pArrayListEmployee);
int controller_isEmpty(LinkedList* pArrayListEmployee);
int controller_addEmployeePush(LinkedList* pArrayListEmployee);
LinkedList* controller_CloneList(LinkedList* pArrayListEmployee);
LinkedList* controller_SubList(LinkedList* pArrayListEmployee);
int controller_Contains(LinkedList* pArrayListEmployee);
int controller_ContainsAll(LinkedList* pArrayListEmployee, LinkedList* pArrayListEmployee2);
int menuModificacion();

