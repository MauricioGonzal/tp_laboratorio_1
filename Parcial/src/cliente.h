/*
 * cliente.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <stdio.h>



typedef struct{
	int id;
	char nombreEmpresa[51];
	char cuit[51];
	char direccion[51];
	int isEmpty;
	char localidad[51];
	int idLocalidad;
	int CantidadPedidosPendientes;
	int cantidadPedidosCompletados;
}eCliente;

/// @fn int InicializarArrayClientes(eCliente[], int)
/// @brief Inicializa los campos .isEmpty e cantidadPedidosPendientes en 0
/// @param listaClientes
/// @param tam
/// @return 0 si esta ok, -1 si el puntero es NULL o el tamaño es menor a 1
int InicializarArrayClientes(eCliente listaClientes[], int tam);

/// @fn int AltaDeCliente(eCliente[], int, int*, int, int)
/// @brief ingresa un cliente en la primera posicion vacia de la lista
/// @param listaClientes
/// @param tam
/// @param id puntero a la variable id
/// @param idValor
/// @param tamDatos
/// @return 0 si esta ok, -1 si el puntero es NULL, el tamaño es menor a 1 o 1 si no se encuentra lugar disponible


/// @fn int ImprimirListaClientes(eCliente[], int)
/// @brief busca los clientes activos y los imprime
/// @param lista
/// @param tam
/// @return 0 si esta OK, -1 si el puntero es NULL, el tamaño es menor a 1 o 1 si no se encuentran clientes cargados
int ImprimirListaClientes(eCliente lista[], int tam);

/// @fn void ImprimirUnCliente(eCliente)
/// @brief Imprime un cliente con su id, nombre de empresa, direccion y cantidad de pedidos pendientes
/// @param cliente
void ImprimirUnCliente(eCliente cliente);

/// @fn int ModificarCliente(eCliente[], int)
/// @brief pide un id y es capaz de modificar direccion y localidad
/// @param lista
/// @param tam
/// @return 0 si esta OK, -1 si el puntero es NULL, el tamaño es menor a 1 o 1 si no se encuentra el cliente con el id ingresado
int ModificarCliente(eCliente lista[],int tam);

/// @fn int BajaCliente(eCliente[], int)
/// @brief pide un id y si lo encuentra activo cambia el campo IsEmpty a vacio
/// @param lista
/// @param tam
/// @return 0 si esta OK, -1 si el puntero es NULL o el tamaño es menor a 1, o 1 si no se encuentra el cliente con el id ingresado
int BajaCliente(eCliente lista[], int tam);

int BuscarLocalidad(eCliente listaClientes[], int tam);

int BuscarClienteConMasPedidosPorTipo(eCliente listaClientes[], int tamUno, int indicacion);
#endif /* CLIENTE_H_ */
