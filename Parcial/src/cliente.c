/*
 * cliente.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */
#include "cliente.h"
#define VACIO 0
#define CARGADO 1
#include "input.h"
#include "nexo.h"

#include <string.h>


int InicializarArrayClientes(eCliente listaClientes[], int tam){
	int retorno;
	retorno=-1;
	if(listaClientes!=NULL && tam>0){
	for(int i=0; i<tam; i++){
		{
		listaClientes[i].isEmpty= VACIO;
		listaClientes[i].CantidadPedidosPendientes=0;
		listaClientes[i].cantidadPedidosCompletados=0;
		}
	}
	retorno=0;
	}
	return retorno;
}







int ModificarCliente(eCliente lista[], int tam){
	int retorno;

	retorno=-1;

	int id;
	id= LoadInt("Ingrese el id que desea modificar: ");
	if(lista!=NULL && tam>0){
	for(int i=0;i<tam; i++){

		if(lista[i].isEmpty==CARGADO && id==lista[i].id){
			LoadString("ingrese la nueva direccion: ", lista[i].direccion);

			retorno=0;

			break;
		}
		retorno=1;
	}
	}



	return retorno;
}

int BajaCliente(eCliente lista[], int tam){
	int retorno;
	int opcion;
	int id;

	retorno=-1;


	id= LoadInt("Ingrese el id que desea dar de baja");
	printf("Seguro que desea eliminar al cliente?\n1.SI.\n2.NO");
	scanf("%d", &opcion);

	if(lista!=NULL && tam>0 && opcion==1){
	for(int i=0;i<tam; i++){

		if(lista[i].isEmpty==CARGADO && id==lista[i].id ){

			lista[i]= lista[i+1];
			lista[i+1].isEmpty= VACIO;
			retorno=0;

			break;
		}
		retorno=1;
	}
	}


	return retorno;
}



int ImprimirListaClientes(eCliente lista[], int tam){
	int retorno;


	retorno=-1;
	if(lista!=NULL && tam>0){
	retorno=1;

	for(int i=0; i<tam; i++){

		if(lista[i].isEmpty==CARGADO){

		ImprimirUnCliente(lista[i]);

		retorno=0;
		}

	}
	}


	return retorno;
}

void ImprimirUnCliente(eCliente cliente){



	printf("\nID: %d\n NOMBRE: %s DIRECCION: %s LOCALIDAD: %s CANTIDAD DE PEDIDOS PENDIENTES: %d\n", cliente.id, cliente.nombreEmpresa, cliente.direccion, cliente.localidad, cliente.CantidadPedidosPendientes);


}


int BuscarLocalidad(eCliente listaClientes[], int tam){
	int retorno;

	retorno=-1;
	char localidad[51];
	int pedidosTotalesLocalidad;
	pedidosTotalesLocalidad=0;
	LoadString("ingrese localidad", localidad);

	if(listaClientes!=NULL && tam>0){
		for(int i=0;i<tam; i++){


		/*if(listaClientes[i].isEmpty==CARGADO && strcmp(listaClientes[i].localidad, localidad)==0){*/



				pedidosTotalesLocalidad= pedidosTotalesLocalidad+ listaClientes[i].CantidadPedidosPendientes;

				retorno=0;

			//}


	}
	}


		printf("los pedidos para la localidad ingresada son %d\n", pedidosTotalesLocalidad);


	return retorno;
}

int BuscarClienteConMasPedidosPorTipo(eCliente listaClientes[], int tamUno, int indicacion){
	int retorno;
	int cantidadPedidos;
	int idCliente;
	if(indicacion==1){
	for(int i=0; i<tamUno; i++){
		if(listaClientes[i].isEmpty==CARGADO && i==0){
			cantidadPedidos= listaClientes[i].CantidadPedidosPendientes;
			idCliente= listaClientes[i].id;
		}
		else{
			if(listaClientes[i].isEmpty==CARGADO && listaClientes[i].CantidadPedidosPendientes>cantidadPedidos){
				cantidadPedidos= listaClientes[i].CantidadPedidosPendientes;
				idCliente= listaClientes[i].id;
			}
		}
	}


	for(int i=0; i<tamUno; i++){
		if(listaClientes[i].id==idCliente){
			printf("El cliente con mas pedidos pendientes es: ");
			ImprimirUnCliente(listaClientes[i]);
		}
	}
	}
	if(indicacion==2){
		for(int i=0; i<tamUno; i++){
				if(listaClientes[i].isEmpty==CARGADO && i==0){
					cantidadPedidos= listaClientes[i].cantidadPedidosCompletados;
					idCliente= listaClientes[i].id;
				}
				else{
					if(listaClientes[i].isEmpty==CARGADO && listaClientes[i].cantidadPedidosCompletados>cantidadPedidos){
						cantidadPedidos= listaClientes[i].cantidadPedidosCompletados;
						idCliente= listaClientes[i].id;
					}
				}
			}


			for(int i=0; i<tamUno; i++){
				if(listaClientes[i].id==idCliente){
					printf("El cliente con mas pedidos completados es: ");
					ImprimirUnCliente(listaClientes[i]);
				}
			}
	}
	return retorno;
}
