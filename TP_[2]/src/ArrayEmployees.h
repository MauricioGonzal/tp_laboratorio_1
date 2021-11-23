/*
 * input.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Mauri
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	 int id;
	 char name[51];
	 char lastName[51];
	 float salary;
	 int sector;
	 int isEmpty;
	}Employee;

void Menu();

/// @fn int initEmployees(Employee*, int)
/// @brief inicializa los campos isempty en vacio
///
/// @param list lista de empleados
/// @param len tamaño de la lista
/// @return -1 si el puntero es NULL o el tamaño es menor a 1, 0 si ok
int initEmployees(Employee* list, int len);

/// @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
/// @brief agrega un empleado a la lista en la primera posicion libre
///
/// @param list lista
/// @param len tamaño
/// @param id
/// @param name
/// @param lastName
/// @param salary
/// @param sector
/// @return -1 si el puntero es NULL o el tamaño es menor a 1 o si no hay espacio, 0 si ok
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

/// @fn int createEmployee(Employee[], int, int*)
/// @brief pide todos los datos al usuario del nuevo empleado
///
/// @param list
/// @param len
/// @param id
/// @return -1 si el puntero es NULL o el tamaño es menor a 1 o si hay error en addEmployee, 0 si ok
int createEmployee(Employee list[], int len, int* id);

/// @fn void printOneEmployee(Employee)
/// @brief imprime el empleado pasado como parametro
///
/// @param employee
void printOneEmployee(Employee employee);

/// @fn int printEmployees(Employee*, int)
/// @brief imprime los empleados
///
/// @param list
/// @param length
/// @return -1 si el puntero es NULL o el tamaño es menor a 1, 0 si ok
int printEmployees(Employee* list, int length);

/// @fn int findEmployeeById(Employee*, int, int)
/// @brief busca si el id pasado como parametro existe
///
/// @param list
/// @param len
/// @param id
/// @return -1 si el puntero es NULL o el tamaño es menor a 1 o si no existe el id, index del empleado si ok
int findEmployeeById(Employee* list, int len,int id);

/// @fn int modificarEmployee(Employee[], int, int)
/// @brief modifica un empleado
///
/// @param list
/// @param len

/// @return -1 si el puntero es NULL o el tamaño es menor a 1 o si no existe el id, 0 si ok
int modificarEmployee(Employee list[], int len);

/// @fn int removeEmployee(Employee*, int, int)
/// @brief coloca el campo isempty de un empleado en vacio
///
/// @param list
/// @param len
/// @param id
/// @return -1 si el puntero es NULL o el tamaño es menor a 1 o si no existe el id, 0 si ok
int removeEmployee(Employee* list, int len, int id);

/// @fn int informesSalary(Employee[], int, float*, float*)
/// @brief informa el promedio y total de sueldos, y cuantos empleados superan el promedio
///
/// @param list
/// @param len
/// @param total
/// @param promedio
/// @return -1 si el puntero es NULL o el tamaño es menor a 1, 0 si ok
int informesSalary(Employee list[], int len, float* total, float* promedio);

/// @fn int sortEmployees(Employee*, int, int)
/// @brief ordena la lista en base al campo nombre o al campo sector
///
/// @param list
/// @param len
/// @param order 1 si es en orden ascendente, 0 si en orden descendente
/// @return -1 si el puntero es NULL o el tamaño es menor a 1, 0 si ok
int sortEmployees(Employee* list, int len, int order);

#endif /* ARRAYEMPLOYEES_H_ */
