/*
 * localidad.c
 *
 *  Created on: 31 oct. 2021
 *      Author: Mauri
 */

#include "localidad.h"

int InicializarLocalidades(eLocalidad listaLocalidades[], int tam){
	int retorno;
	for(int i=0; i<tam; i++){
		if(listaLocalidades[i].isEmpty!=CARGADO){
			listaLocalidades[i].isEmpty=VACIO;
		}
	}
	return retorno;
}

void ImprimirLocalidades(eLocalidad listaLocalidades[], int tam){
	for(int i=0; i<tam; i++){
		if(listaLocalidades[i].isEmpty==CARGADO){

			printf("ID localidad: %d %s\n",listaLocalidades[i].idLocalidad, listaLocalidades[i].localidad);
		}
	}
}
