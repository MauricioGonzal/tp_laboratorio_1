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

int initEmployees(Employee* list, int len);

int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

int createEmployee(Employee list[], int len, int* id);

void printOneEmployee(Employee employee);

int printEmployees(Employee* list, int length);

int findEmployeeById(Employee* list, int len,int id);

int modificarEmployee(Employee list[], int len, int i);

int removeEmployee(Employee* list, int len, int id);

int informesSalary(Employee list[], int len, float* total, float* promedio);


int sortEmployees(Employee* list, int len, int order);

#endif /* ARRAYEMPLOYEES_H_ */
