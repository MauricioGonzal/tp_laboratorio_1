/*
 * nexo.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#include "nexo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int CrearPedido(ePedido listaPedidos[], eCliente listaClientes[], int tam, int tamDos, int* id, int idValor){
	int retorno;
	int auxId;
	float auxKilos;
	char kilosTotales[21];
	retorno=-1;


	auxId= LoadInt("Ingrese el id de un cliente: ");


	for(int i=0; i<tamDos;i++){
		if(listaClientes[i].isEmpty==CARGADO && auxId==listaClientes[i].id){
			retorno=1;
			for(int j=0;j<tam;j++){
			if(listaPedidos[j].isEmpty==VACIO){
			idValor= idValor+1;
			*id= idValor;
			listaPedidos[j].isEmpty= CARGADO;
			listaPedidos[j].id= idValor;
			listaPedidos[j].idCliente=auxId;
			PedirYValidarNumero(kilosTotales, "Ingrese los kilos a recolectar");
			auxKilos= atof(kilosTotales);
			listaPedidos[j].kilosARecolectar= auxKilos;
			listaPedidos[j].estado=PENDIENTE;
			listaClientes[i].CantidadPedidosPendientes= listaClientes[i].CantidadPedidosPendientes+1;
			listaPedidos[j].kilosTotales= listaPedidos[j].kilosTotales+ auxKilos;
			retorno=0;
			break;
			}
			}


		}

	}

	return retorno;
}

int AltaDeCliente(eCliente listaClientes[], eLocalidad localidades[], int tam, int* id, int idValor, int tamDatos){
	int retorno;
	int retornoValidacion;
	int validacionTamanio;
	retorno=-1;

if(listaClientes!=NULL && tam>0){
	for(int i=0; i<tam; i++){
		if(listaClientes[i].isEmpty==VACIO){
			idValor= idValor+1;
			*id= idValor;
			listaClientes[i].id= idValor;
			LoadString("Ingrese el nombre de la empresa: ", listaClientes[i].nombreEmpresa);
			do{
			LoadString("Ingrese el cuit: ", listaClientes[i].cuit);
			if(strlen(listaClientes[i].cuit)!=11){
				printf("El dato ingresado no es un cuit valido.\n");
				validacionTamanio=-1;
			}
			else{
				validacionTamanio=0;
			}
			retornoValidacion=ValidarNumero(listaClientes[i].cuit);
			}while(retornoValidacion==-1 || validacionTamanio==-1);
			LoadString( "Ingrese la direccion de la empresa: ", listaClientes[i].direccion);
			ImprimirLocalidades(localidades, 10);

			listaClientes[i].idLocalidad=LoadInt("ingrese el id de la localidad a la que pertenece");
			AdjudicarLocalidad(listaClientes[i], listaClientes[i].localidad, localidades, 10);
			printf("%s", listaClientes[i].localidad);
			listaClientes[i].isEmpty= CARGADO;
			printf("Se creo el cliente con el id Nro. %d\n", idValor);
			retorno=0;
			break;
		}
		retorno=1;
	}
}
	return retorno;

}


int AdjudicarLocalidad(eCliente cliente, char clienteLocalidad[], eLocalidad listaLocalidades[], int tam){
	int retorno;
	retorno=0;
	for(int i=0; i<tam; i++){
		if(listaLocalidades[i].isEmpty==CARGADO && listaLocalidades[i].idLocalidad== cliente.idLocalidad){
			strcpy(clienteLocalidad, listaLocalidades[i].localidad);

			break;
		}
	}
	return retorno;
}



int ProcesarResiduos(ePedido listaPedidos[], eCliente listaClientes[], int tam, int tamDos){
	int retorno;
	char kilosHDPE[10];
	char kilosLDPE[10];
	char kilosPP[10];
	float auxHDPE;
	float auxLDPE;
	float auxPP;
	retorno=-1;
	int id;
	id= LoadInt("ingrese el id del pedido que desea procesar");
	for(int i=0; i<tam;i++){
		if(id==listaPedidos[i].id){
			PedirYValidarNumero(kilosHDPE, "Ingrese los kilos procesados de HDPE: ");
			PedirYValidarNumero(kilosLDPE, "Ingrese los kilos procesados de LDPE: ");
			PedirYValidarNumero(kilosPP,"Ingrese los kilos procesados de PP: ");

			auxHDPE= atof(kilosHDPE);
			auxLDPE= atof(kilosLDPE);
			auxPP= atof(kilosPP);
			while(auxPP+auxLDPE+auxHDPE>listaPedidos[i].kilosTotales){
				printf("Error. Los kilos procesados superan los kilos totales del cliente.\n");
				auxHDPE= LoadFloat("Ingrese los kilos procesados de HDPE: ");
				auxLDPE= LoadFloat("Ingrese los kilos procesados de LDPE: ");
				auxPP= LoadFloat("Ingrese los kilos procesados de PP: ");
			}

			listaPedidos[i].kilosHDPE= auxHDPE;
			listaPedidos[i].kilosLDPE= auxLDPE;
			listaPedidos[i].kilosPP=auxPP;
			listaPedidos[i].estado= COMPLETADO;

			for(int j=0; j<tamDos; j++){
				if(listaClientes[j].id==listaPedidos[i].idCliente){
					listaClientes[j].cantidadPedidosCompletados= listaClientes[j].cantidadPedidosCompletados+1;
					break;
				}
			}

			retorno=0;
			break;
		}
		retorno=1;
	}
	return retorno;
}



