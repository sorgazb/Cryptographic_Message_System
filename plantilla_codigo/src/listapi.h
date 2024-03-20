/*
 * ListaPI.h
 *
 *  Created on: 30/03/2022
 *      Author: Juan A. Rico (jarico@unex.es)
 */

#ifndef LISTAPI_H_
#define LISTAPI_H_


#include <cstdlib>



using namespace std;


template <class TipoDato>
class ListaPI {

private:

	class Nodo {

	public:

		TipoDato  dato;
		Nodo     *siguiente;
		Nodo     *anterior;

		Nodo (const TipoDato &dato) {
			this->dato      = dato;
			this->siguiente = nullptr;
			this->anterior  = nullptr;
		}
	};

	Nodo *inicio;
	Nodo *fin;
	Nodo *pI;


public:

    /* DESC:   Crea una lista con punto de interes vacia
     * PRE:    Pre  = { }
     * POST:   Post = { vacia(lista) = true }
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	ListaPI ();

    /* DESC:   Consulta si la lista esta vacia
     * PRE:    Pre  = {}
     * POST:   Post = {}
     * PARAM:  -
     * RET:    True:  lista vacia
     *         FALSE: lista no vacia
     * COMP:   O(1)
     */
	bool  vacia ();

    /* DESC:   Coloca el PI al inicio de la lista
     * PRE:    Pre  = {}
     * POST:   Post = {enInicio() == true}
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  moverInicio ();

	/* DESC:   Coloca el PI en el ultimo elemento de la lista
    * PRE:    Pre  = {}
    * POST:   Post = { enFin() == true }
    * PARAM:  -
    * RET:    -
    * COMP:   O(1)
    */
	void  moverUltimo ();

    /* DESC:   Coloca el PI apuntando al siguiente elemento de la lista
     * PRE:    Pre  = {}
     * POST:   Post = {}
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  avanzar ();

    /* DESC:   Coloca el PI apuntando al anterior elemento de la lista
     * PRE:    Pre  = {}
     * POST:   Post = {}
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  retroceder ();

    /* DESC:   Consulta si el PI apunta al elemento inicial de la lista
     * PRE:    Pre  = {}
     * POST:   Post = {}
     * PARAM:  -
     * RET:    True:  consultar(pi) = primero
     *         False: consultar(pi) != primero
     * COMP:   O(1)
     */
	bool  enInicio ();

    /* DESC:   Consulta si el PI apunta al ultimo elemento de la lista
     * PRE:    Pre  = {}
     * POST:   Post = {}
     * PARAM:  -
     * RET:    True:  consultar(pi) = ultimo
     *         False: consultar(pi) != ultimo
     * COMP:   O(1)
     */
	bool  enUltimo ();

    /* DESC:   Consulta si el PI apunta despues del ultimo elemento de la lista
     * PRE:    Pre  = {}
     * POST:   Post = {}
     * PARAM:  -
     * RET:    True:  consultar(pi) = avanzar(ultimo)
     *         False: consultar(pi) != avanzar(ultimo)
     * COMP:   O(1)
     */
	bool  enFin ();

    /* DESC:   Inserta un elemento en la lista, justo delante del PI
     * PRE:    Pre  = {}
     * POST:   Post = { consultar(retroceder(PI)) = dato }
     * PARAM:  Input: dato -> Elemento a insertar
     * RET:    -
     * COMP:   O(1)
     */
	void  insertar (const TipoDato &dato);

	/* DESC:   Devuelve el elemento de la lista apuntado por el PI
    * PRE:    Pre  = { vacia(lista) == false }
    * POST:   Post = {}
    * PARAM:  Output: dato -> Elemento PI
    * RET:    -
    * COMP:   O(1)
    */
   void  consultar (TipoDato &dato);

   /* DESC:   Devuelve el elemento de la lista apuntado por el PI
    * PRE:    Pre  = { vacia(lista) == false }
    * POST:   Post = {}
    * PARAM:  -
    * RET:    Elemento PI
    * COMP:   O(1)
    */
   TipoDato& consultar ();

   
	/* DESC:   Borra el elemento de la lista apuntado por el PI
    * PRE:    Pre  = {vacia(lista) = false}
    * POST:   Post = {consultar(PI) == consultar(avanzar())}
    * PARAM:  -
    * RET:    -
    * COMP:   O(1)
    */
	void  borrar ();

	/* DESC:   Libera la memoria ocupada por los nodos de la lista
    * PRE:    Pre  = {}
    * POST:   Post = {vacia(lista) == true}
    * PARAM:  -
    * RET:    -
    * COMP:   O(n)
    */
     ~ListaPI();

};




template <class TipoDato>
ListaPI<TipoDato>::ListaPI () {
	inicio = nullptr;
	fin    = nullptr;
	pI     = nullptr;
}

template <class TipoDato>
bool ListaPI<TipoDato>::vacia () {
	return (inicio == nullptr);
}

template <class TipoDato>
void ListaPI<TipoDato>::moverInicio (){
	pI = inicio;
}

template <class TipoDato>
void ListaPI<TipoDato>::moverUltimo (){
	pI= fin;
}

template <class TipoDato>
void ListaPI<TipoDato>::avanzar () {

	if (pI != nullptr) {
		pI = pI->siguiente;
	}
}

template <class TipoDato>
void ListaPI<TipoDato>::retroceder (){

	if (pI != inicio) {
		if (pI != nullptr) {
			pI = pI->anterior;
		} else {
			pI = fin;
		}
	}
}

template <class TipoDato>
bool ListaPI<TipoDato>::enInicio (){
	return (pI == inicio);
}

template <class TipoDato>
bool ListaPI<TipoDato>::enUltimo (){
	return (pI == fin);
}

template <class TipoDato>
bool ListaPI<TipoDato>::enFin (){
	return (pI == nullptr);
}

template <class TipoDato>
void ListaPI<TipoDato>::consultar (TipoDato &dato){

	if (pI != nullptr) {
		dato = pI->dato;
	}
}

template <class TipoDato>
TipoDato& ListaPI<TipoDato>::consultar() {

   // Esta excepción evita Warning en compilación
   if (this->pI == nullptr) {
     throw "Elemento invalido.";
   }
   return pI->dato;
}

template <class TipoDato>
void ListaPI<TipoDato>::insertar (const TipoDato &dato) {

	Nodo *nuevo = new Nodo (dato);

	if (pI == nullptr){

		if (vacia()) { // Lista vacia
			nuevo->siguiente = pI;
			inicio = nuevo;
			fin    = nuevo;
		} else { // pI apunta al elemento siguiente al ultimo: el nodo se inserta al final
			nuevo->anterior = fin;
			fin->siguiente  = nuevo;
			fin = nuevo;
		}

	} else {

		if (pI->anterior == nullptr) { // Insercion el primero de la lista
			inicio = nuevo;
			nuevo->siguiente = pI;
			nuevo->anterior = nullptr;
			pI->anterior = nuevo;
		} else {  // Insercion en posicion intermedia
			nuevo->anterior  = pI->anterior;
			nuevo->siguiente = pI;
			(pI->anterior)->siguiente = nuevo;
			pI->anterior = nuevo;
		}

	}

	// El PI apunta al nuevo nodo insertado
	// pI = nuevo;
}

template <class TipoDato>
void ListaPI<TipoDato>::borrar () {

	Nodo *pAux;

	if (!vacia() && !enFin()) {

		pAux=pI;

		if (pI == inicio) // El nodo a borrar es el primero
			inicio = inicio->siguiente;
		if (pI == fin)    // El nodo a borrar es el ultimo
			fin = fin->anterior;

		pI = pI->siguiente; // El PI apunta al siguiente

		if (pAux->anterior!=nullptr)
			(pAux->anterior)->siguiente = pI;
		if (pAux->siguiente!=nullptr)
			pI->anterior = pAux->anterior;

		delete pAux;
	}
}

template <class TipoDato>
ListaPI<TipoDato>::~ListaPI() {
	moverInicio();
		while (!vacia())
			borrar();

	inicio = nullptr;
	fin    = nullptr;
	pI     = nullptr;
}




#endif /* LISTAPI_H_ */
