/*
 * pedido.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#include "pedido.h"
#include "input.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define VACIO 0
#define CARGADO 1
#define PENDIENTE 0
#define COMPLETADO 1

int InicializarPedidos(ePedido listaPedidos[], int tam){
	int retorno;
	retorno=-1;
	if(listaPedidos!=NULL && tam>0){
	for(int i=0;i<tam;i++){
		if(listaPedidos[i].isEmpty!=CARGADO){
		listaPedidos[i].isEmpty= VACIO;
		listaPedidos[i].kilosTotales=0;
		listaPedidos[i].kilosHDPE=0;
		listaPedidos[i].kilosLDPE=0;
		listaPedidos[i].kilosPP=0;
		listaPedidos[i].kilosARecolectar=0;
		retorno=0;
		}
	}
	}
	return retorno;
}



