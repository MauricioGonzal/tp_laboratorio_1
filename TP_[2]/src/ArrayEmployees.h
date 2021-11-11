/*
 * input.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Mauri
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


/*

2.2 Función addEmployees
Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
posición libre.
 \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *



int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
 return -1;
}
Ejemplo uso:
r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);


2.3 Función findEmployeeById
Busca un empleado recibiendo como parámetro de búsqueda su Id.
 \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *

int findEmployeeById(Employee* list, int len,int id)
{
 return NULL
}
Ejemplo uso:
int index = findEmployeeById(arrayEmployees, ELEMENTS,9);


2.4 Función removeEmployee
Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *

int removeEmployee(Employee* list, int len, int id)
{
 return -1;
}
Ejemplo uso:
r = removeEmployee(arrayEmployees, ELEMENTS,20);


2.5 Función sortEmployees
Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *

int sortEmployees(Employee* list, int len, int order)
{
 return 0;
}
Ejemplo uso:
r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);
2.6 Función printEmployees
Imprime el array de empleados de forma encolumnada.
 \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *

int printEmployees(Employee* list, int length)
{
 return 0;
}
Ejemplo uso:
r = printEmployees(arrayEmployees, ELEMENTS);

*/

typedef struct{
	 int id;
	 char name[51];
	 char lastName[51];
	 float salary;
	 int sector;
	 int isEmpty;
	}eEmployee;

	int initEmployees(eEmployee* empleados, int len);
	void CargarEmpleado (int* id, eEmployee empleados[], int tam);
	int addEmployee(eEmployee empleados[], int len, int id, char name[],char lastName[],float salary,int sector);
	void Imprimir (eEmployee lista[], int tam);
	void ImprimirUno(eEmployee lista);

#endif /* ARRAYEMPLOYEES_H_ */
