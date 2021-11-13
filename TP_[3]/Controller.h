#include <string.h>

/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief
///
/// @param path archivo de texto
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return -1 si algun puntero parametro es NULL, 1 si no se pueden cargar los datos desde el data.csv y 0 si ok
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
///
/// @param path archivo binario
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return 0 si ok, -1 si algun puntero es NULL o si aun el archivo binario no puede ser creado y 1 si hubo error en la funcion parser_EmployeeFromBinary
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_addEmployee(LinkedList*)
/// @brief Alta de empleados
///
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return 0 si ok, -1 si el puntero es NULL y 1 si no se encuentra espacio para crear un empleado o si algun dato fue mal ingresado por el usuario
int controller_addEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_editEmployee(LinkedList*)
/// @brief  Modificar datos de empleado
///
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return -1 si el puntero parametro es NULL, 1 si no existe el empleado con el id ingresado, 0 si ok
int controller_editEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_removeEmployee(LinkedList*)
/// @brief Baja de empleado
///
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return -1 si el puntero parametro es NULL, 1 si el id no existe y 0 si ok
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_ListEmployee(LinkedList*)
/// @brief Listar empleados
///
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return -1 si el puntero parametro es NULL, 1 si employee_listarEmpleados no se concreta, 0 si ok
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_sortEmployee(LinkedList*)
/// @brief  Ordenar empleados
///
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return -1 si el puntero parametro es NULL, 1 si elegirCriterioDeOrdenamiento no se concreta o 0 si ok
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief  Guarda los datos de los empleados en el archivo data.csv (modo texto).
///
/// @param path archivo
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return 0 si ok, -1 si algun puntero parametro es NULL o 1 si no hay espacio para abrir el archivo o la funcion guardarArchivo no se concreta
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
///
/// @param path archivo
/// @param pArrayListEmployee puntero de tipo linkedList a la lista de empleados
/// @return 0 si ok, -1 si algun puntero parametro es NULL, 1 si no hay espacio para abrir el archivo o la funcion guardarArchivo no se concreta
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


