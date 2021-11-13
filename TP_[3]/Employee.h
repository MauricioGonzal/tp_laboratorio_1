




#ifndef employee_H_INCLUDED

#define employee_H_INCLUDED
#include "input.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// @fn Employee employee_new*()
/// @brief reserva memoria dinamica para un dato de tipo empleado e inicializa sus campos
///
/// @return el puntero a employee inicializado
Employee* employee_new();

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief cambia los campos inicializados del employee por los datos de los parametros
///
/// @param idStr id en formato string
/// @param nombreStr nombre
/// @param horasTrabajadasStr horas trabajadas en formato string
/// @param sueldo en formato string
/// @return el puntero a employee creado
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/// @fn int employee_delete(Employee*)
/// @brief libera el espacio del empleado eliminado
///
/// @param this puntero de tipo employee
/// @return -1 si el puntero parametro es NULL o 0 si esta todo ok
int employee_delete(Employee* empleado);

/// @fn int employee_setId(Employee*, int)
/// @brief setea el campo id
///
/// @param this puntero de tipo employee
/// @param id valor por el que se va a reemplazar el dato del campo id
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_setId(Employee* this,int id);

/// @fn int employee_getId(Employee*, int*)
/// @brief obtiene el campo id
///
/// @param this puntero de tipo employee
/// @param id puntero de tipo entero en donde se va a colocar el valor obtenido
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_getId(Employee* this,int* id);

/// @fn int employee_setNombre(Employee*, char*)
/// @brief setea el campo nombre
///
/// @param this puntero de tipo employee
/// @param nombre valor que va a reemplazar al que se encuentra en el campo nombre
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_setNombre(Employee* this,char* nombre);

/// @fn int employee_getNombre(Employee*, char*)
/// @brief obtiene el dato que esta en el campo nombre
///
/// @param this puntero de tipo employee
/// @param nombre puntero de tipo char* en donde se va a colocar el valor obtenido
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_getNombre(Employee* this,char* nombre);

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief setea el campo horasTrabajadas
///
/// @param this puntero de tipo employee
/// @param horasTrabajadas  valor que va a reemplazar al que se encuentra en el campo horasTrabajadas
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief obtiene el valor que se encuentra en el campo horasTrabajadas
///
/// @param this puntero de tipo employee
/// @param horasTrabajadas nombre puntero de tipo int en donde se va a colocar el valor obtenido
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// @fn int employee_setSueldo(Employee*, int)
/// @brief setea el campo sueldo
///
/// @param this ppuntero de tipo employee
/// @param sueldo valor que va a reemplazar al que se encuentra en el campo sueldo
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_setSueldo(Employee* this,int sueldo);

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief obtiene el valor que se encuentra en el campo sueldo
///
/// @param this puntero de tipo employee
/// @param sueldo puntero de tipo int donde se va a colocar el valor obtenido
/// @return -1 si el puntero parametro es NULL o 0 si todo ok
int employee_getSueldo(Employee* this,int* sueldo);

/// @fn int CrearEmpleado(Employee*)
/// @brief setea los campos del empleado pasado como parametro
///
/// @param pEmpleado puntero de tipo employee
/// @return -1 si el puntero parametro es NULL, 1 si el usuario ingresa numeros en el campo nombre y 0 si esta todo ok
int CrearEmpleado(Employee* pEmpleado);

/// @fn int employee_compareByName(void*, void*)
/// @brief compara el campo nombre entre dos datos de tipo employee
///
/// @param e1 puntero de tipo employee
/// @param e2 puntero de tipo employee
/// @return -1 si e1 es menor que e2, 0 si son iguales, 1 si e1 es mayor que e2
int employee_compareByName(void* e1, void* e2);

/// @fn int employee_compareById(void*, void*)
/// @brief compara el campo id entre dos datos de tipo employee
///
/// @param e1 puntero de tipo employee
/// @param e2 puntero de tipo employee
/// @return -1 si e1 es menor que e2, 0 si son iguales, 1 si e1 es mayor que e2
int employee_compareById(void* e1, void* e2);

/// @fn int employee_compareBySalary(void*, void*)
/// @brief compara el campo sueldo entre dos datos de tipo employee
///
/// @param e1 puntero de tipo employee
/// @param e2 puntero de tipo employee
/// @return -1 si e1 es menor que e2, 0 si son iguales, 1 si e1 es mayor que e2
int employee_compareBySalary(void* e1, void* e2);

/// @fn int employee_compareByHours(void*, void*)
/// @brief compara el campo horasTrabajadas entre dos datos de tipo employee
///
/// @param e1 puntero de tipo employee
/// @param e2 puntero de tipo employee
/// @return -1 si e1 es menor que e2, 0 si son iguales, 1 si e1 es mayor que e2
int employee_compareByHours(void* e1, void* e2);

/// @fn int editEmployee(LinkedList*)
/// @brief edita los campos sueldo y horas de un empleado
///
/// @param pArrayListEmployee
/// @return -1 si el puntero parametro es NULL, 1 si no se encuentra el id, 0 si ok
int editEmployee(LinkedList* pArrayListEmployee);

/// @fn int elegirCriterioDeOrdenamiento(int*, int*)
/// @brief le da al usuario las opciones para ordenar la lista
///
/// @param opcion criterio de ordenamiento
/// @param opcionDos de forma ascendente o descendente
/// @return -1 si los punteros parametro son NULL o 0 si ok
int elegirCriterioDeOrdenamiento(int *opcion, int* opcionDos);

/// @fn Employee buscarIdEmpleado*(LinkedList*, int, int, int*)
/// @brief analiza si encuentra el id que recibe en la lista
///
/// @param pArrayListEmployee
/// @param len
/// @param id
/// @param auxI
/// @return dato de tipo employee, sera NULL si no encuentra coincidencia
Employee* buscarIdEmpleado(LinkedList* pArrayListEmployee, int len, int id, int* auxI);

/// @fn int guardarArchivo(LinkedList*, FILE*, int, int)
/// @brief guarda la lista en los archivos
///
/// @param lista
/// @param pFile
/// @param indicacion 0 si se quiere guardar en binario y 1 si se quiere guardar en texto
/// @param len
/// @return -1 si algun puntero parametro es NULL, 1 si no se encuentra espacio y 0 si esta ok
int guardarArchivo(LinkedList* lista, FILE* pFile, int indicacion, int len);

/// @fn int employee_listarEmpleados(LinkedList*, int)
/// @brief imprime la lista
///
/// @param lista
/// @param len
/// @return -1 si el puntero parametro es NULL, 1 si algun  puntero empleado que se obtiene es NULL, 0 si esta ok
int employee_listarEmpleados(LinkedList* lista, int len);

/// @fn void employee_listarUnEmpleado(Employee*)
/// @brief imprime un empleado
///
/// @param empleado a imprimir
void employee_listarUnEmpleado(Employee* empleado);

#endif // employee_H_INCLUDED
