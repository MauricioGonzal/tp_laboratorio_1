/*
 ============================================================================
 Name        : Parcial.c
 Author      : mauricio gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "pedido.h"
#include "input.h"
#include "nexo.h"
#include "informes.h"
#include "localidad.h"
#define TAMCLIENTES 100
#define TAMPEDIDOS 1000
#define TAMDATOS 25
#define VACIO 0
#define CARGADO 1
#define PENDIENTE 0
#define COMPLETADO 1

int main(void) {
	setbuf(stdout, NULL);
	eCliente clientes[TAMCLIENTES];
	ePedido pedidos[TAMPEDIDOS];
	eLocalidad localidades[10]= {{1, CARGADO, "lanus"}, {2, CARGADO, "avellaneda"},{3, CARGADO, "Gerli"},{4, CARGADO, "Banfield"}, {5, CARGADO, "LOMAS"}};

	int idCliente;
	int idPedido;
	int opcion;
	int opcionSalida;
	idCliente=0;
	idPedido=0;
	VerificacionRetorno(InicializarArrayClientes(clientes, TAMCLIENTES), "Limpiando lista de clientes...\n", "No se pudo realizar la operacion");
	VerificacionRetorno(InicializarPedidos(pedidos, TAMPEDIDOS), "Limpiando lista de pedidos...\n", "No se pudo realizar la operacion");
	InicializarLocalidades(localidades, 10);

	do{
	Menu();
	LoadIntRange("Ingrese una opcion", &opcion, 13);

	switch(opcion){
	case 1:
		VerificarTresRetornos(AltaDeCliente(clientes, localidades, TAMCLIENTES, &idCliente, idCliente, TAMDATOS), "El alta se dio exitosamente\n", "No hay espacio disponible\n", "No se pudo dar de alta. Verifique los datos.\n");

		break;
	case 2:
		ImprimirListaClientes(clientes, TAMCLIENTES);
		VerificarTresRetornos(ModificarCliente(clientes, TAMCLIENTES), "La modificacion se dio exitosamente.\n", "No se encontro el cliente con el id ingresado\n", "No se pudo realizar la modificacion. Verifique los datos.\n");
		break;
	case 3:
		ImprimirListaClientes(clientes, TAMCLIENTES);
		VerificarTresRetornos(BajaCliente(clientes, TAMCLIENTES), "La baja del sistema se dio exitosamente\n",  "No se encontro el cliente con el id ingresado\n", "No se pudo dar de baja. Verifique los datos.\n");
		break;
	case 4:
		ImprimirListaClientes(clientes, TAMCLIENTES);
		VerificarTresRetornos(CrearPedido(pedidos, clientes, TAMPEDIDOS, TAMCLIENTES, &idPedido, idPedido), "El pedido de recoleccion se creo exitosamente.\n", "No se encontro el cliente con el id ingresado\n", "No se pudo crear el pedido.\n");
		break;
	case 5:
		ImprimirPedidos(pedidos, clientes, TAMPEDIDOS, TAMCLIENTES, 1);
		VerificarTresRetornos(ProcesarResiduos(pedidos, clientes, TAMPEDIDOS, TAMCLIENTES ), "El pedido se proceso exitosamente.\n", "No se encontro el pedido con el id ingresado\n", "No se pudo procesar el pedido. Verifique los datos.\n");
		break;
	case 6:
		VerificarTresRetornos(ImprimirListaClientes(clientes, TAMCLIENTES), "La operacion se realizo exitosamente.\n", "No se ingresaron clientes\n", "La operacion no pudo realizarse. Verifique los datos ingresados.\n");
		break;
	case 7:
		VerificarTresRetornos(ImprimirPedidos(pedidos, clientes, TAMPEDIDOS, TAMCLIENTES,1), "La operacion se realizo exitosamente.\n", "No se encontraron pedidos en esta categoria\n", "La operacion no pudo realizarse. Verifique los datos ingresados.\n");
		break;
	case 8:
		VerificarTresRetornos(ImprimirPedidos(pedidos, clientes, TAMPEDIDOS, TAMCLIENTES, 2), "La operacion se realizo exitosamente.\n", "No se encontraron pedidos en esta categoria\n", "La operacion no pudo realizarse. Verifique los datos ingresados.\n");
		break;
	case 9:
		VerificacionRetorno(BuscarLocalidad(clientes, TAMCLIENTES), "La operacion se realizo exitosamente.\n", "La operacion no pudo realizarse. Verifique los datos ingresados.\n");
		break;
	case 10:
		VerificarTresRetornos(PromediarKilosPolipropileno(clientes, pedidos, TAMCLIENTES, TAMPEDIDOS), "La operacion se realizo exitosamente.\n", "No hay pedidos en estado COMPLETADO", "La operacion no pudo realizarse. Verifique los datos ingresados.\n");
		break;
	case 11:
		BuscarClienteConMasPedidosPorTipo(clientes, TAMCLIENTES, 1);
		break;
	case 12:
		BuscarClienteConMasPedidosPorTipo(clientes, TAMCLIENTES, 2);
		break;


	case 13:
		opcionSalida= SalirDelPrograma();
		break;

	}

	}while(opcionSalida!=1);


	return EXIT_SUCCESS;
}






/*
3) Agregar los siguientes informes:
a) Cliente con más pedidos pendientes.
b) Cliente con más pedidos completados.*/



