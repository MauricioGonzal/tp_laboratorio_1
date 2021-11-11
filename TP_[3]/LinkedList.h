/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
//construye la lista en memoria dinamica
LinkedList* ll_newLinkedList(void);

//cuenta cuantos elementos
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//agrega un elemento generico a la lista
int ll_add(LinkedList* this, void* pElement);

//devuelve un elemento dentro de la lista pasandole el index
void* ll_get(LinkedList* this, int index);

//reemplaza un elemento dentro de la lista
int ll_set(LinkedList* this, int index,void* pElement);

//remueve un elemento dentro de la lista
int ll_remove(LinkedList* this,int index);

//limpia la lista
int ll_clear(LinkedList* this);

//limpia la lista y la elimina
int ll_deleteLinkedList(LinkedList* this);

//devuelve la posicion en la lista de un elemento en particular
int ll_indexOf(LinkedList* this, void* pElement);

//si la lista esta llena o no
int ll_isEmpty(LinkedList* this);

//pone un elemento dentro de la lista
int ll_push(LinkedList* this, int index, void* pElement);

//elimina un elemento y lo devuelve
void* ll_pop(LinkedList* this,int index);

//si el elemento que yo pase a la funcion esta en la lista
int ll_contains(LinkedList* this, void* pElement);

//si una lista esta contenida en otra
int ll_containsAll(LinkedList* this,LinkedList* this2);

//devuelve un pedazo de la lista desde el from a to
LinkedList* ll_subList(LinkedList* this,int from,int to);

//devuelve una copia de la lista en memoria
LinkedList* ll_clone(LinkedList* this);

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
