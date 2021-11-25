/*
 * localidad.h
 *
 *  Created on: 31 oct. 2021
 *      Author: Mauri
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#define VACIO 0
#define CARGADO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int idLocalidad;
	int isEmpty;
	char localidad[51];
}eLocalidad;

int InicializarLocalidades(eLocalidad listaLocalidades[], int tam);

void ImprimirLocalidades(eLocalidad listaLocalidades[], int tam);
#endif /* LOCALIDAD_H_ */
