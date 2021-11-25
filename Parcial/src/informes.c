/*
 * informes.c
 *
 *  Created on: 17 oct. 2021
 *      Author: Mauri
 */
#include "informes.h"

int ImprimirPedidos(ePedido listaPedidos[], eCliente listaClientes[], int tamUno, int tamDos, int indicacion ){
	int retorno;
	retorno=-1;
	if(listaClientes!=NULL && listaPedidos!=NULL && tamUno>0 && tamDos>0){
	for(int j=0;j<tamUno;j++){
		if(indicacion==1 && listaPedidos[j].isEmpty==CARGADO && listaPedidos[j].estado==PENDIENTE){
			for(int i=0; i<tamDos; i++){
				if(listaPedidos[j].idCliente==listaClientes[i].id){
					printf("\nID pedido:%d\n Cuit cliente:%s. Direccion:%s. Kilos a recolectar:%f\n", listaPedidos[j].id, listaClientes[i].cuit, listaClientes[i].direccion, listaPedidos[j].kilosARecolectar);
					retorno=0;
					break;
				}
				retorno=1;
			}
		}
		else{
			if(indicacion==2 && listaPedidos[j].isEmpty==CARGADO && listaPedidos[j].estado==COMPLETADO){
						for(int i=0; i<tamDos; i++){
							if(listaPedidos[j].idCliente==listaClientes[i].id){
								printf("\nID pedido:%d Cuit cliente:%s Direccion:%s Kilos:\nHDPE:%.2f\nLDPE:%.2f\nPP:%.2f\n", listaPedidos[j].id, listaClientes[i].cuit, listaClientes[i].direccion, listaPedidos[j].kilosHDPE, listaPedidos[j].kilosLDPE, listaPedidos[j].kilosPP);
							retorno=0;
							break;
							}
							retorno=1;
						}
					}
		}
	}
	}
	return retorno;
}

int PromediarKilosPolipropileno(eCliente listaClientes[], ePedido listaPedidos[], int tamUno, int tamDos){
	int retorno;
	int cantidadClientes;
	float totalKilosPP;
	int bandera;
	float promedioKilosPP;
	totalKilosPP=0;
	cantidadClientes=0;
	retorno=-1;

	if(listaClientes!=NULL && listaPedidos!=NULL && tamUno>0 && tamDos>0){
	for(int i=0; i<tamUno; i++){
		if(listaClientes[i].isEmpty==CARGADO){
			cantidadClientes++;
		}
	}
	for(int i=0;i<tamDos; i++){
		if(listaPedidos[i].isEmpty==CARGADO && listaPedidos[i].estado==COMPLETADO){
			totalKilosPP= totalKilosPP+listaPedidos[i].kilosPP;
			bandera=0;
		}
	}
	}

	if(cantidadClientes>0 && bandera==0){
	promedioKilosPP= totalKilosPP/cantidadClientes;
	retorno=0;
	printf("El promedio de kilos de PP es: %.2f", promedioKilosPP);
	}

	return retorno;
}
