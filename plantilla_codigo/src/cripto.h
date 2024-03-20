/*
 * cripto.h
 *  Autor: Sergio Orgaz Bravo
 *  Fecha: 29 abril 2022
 *  Correo: sorgazbr@alumnos.unex
 *  Descripción: Definición de la clase Cripto, esta clase contiene entre otros atributos
 *               el árbol de mensajes y los algoritmos necesarios para realizar las operaciones
 *               del menú principal.
 */

#ifndef __CRIPTO_H
#define __CRIPTO_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "bstree.h"
#include "keyvalue.h"
#include "mensaje.h"
#include "listapi.h"

class Cripto {
   
private:
	BSTree<KeyValue<string, Mensaje*>> *arbolM;
	BSTree<KeyValue<char, char>> *arbolCambiarCaractres;
	int passwd;

	/*
	 * PRE={Que el fichero de texto se haya abierto correctamente}
	 * POST={Se encarga de cargar todo el fichero de texto a la clase principal}
	 * COMPL: O(n)
	 * DESC: Se encarga de leer toda la informacion del fichero de texto y dejarla a disposición del usuario.
	 */
	void cargarMensajes();

	/*
	 * PRE={}
	 * POST={Se encarga de devolver los archivos al fichero de texto con todos los cambios realizados}
	 * COMPL: O(1)
	 * DESC: Se encarga de escribir en el fichero de texto toda la información y guardar todos los cambios realizados sobre este.
	 */
	void escribirFichero();

	/*
	 * PRE={Que el arbol de mensajes no esté vacio}
	 * POST={Recorre el arbol para poder escribir en el fichero de texto}
	 * COMPL: O(n)
	 * DESC: Se encarga de recorrer el arbol en preOrden para poder escribir en el fichero de texto.
	 */
	void recorridoEscribirFichero(BSTree<KeyValue<string, Mensaje*>> *arbol, ofstream &flujoCripto);

	/*
	 * PRE={Que el arbol de mensajes no esté vacio}
	 * POST={Recorre el arbol y muestra todos los mensajes que contiene}
	 * COMPL: O(n)
	 * DESC: Se encarga de recorrer el arbol en inOrden para mostrar los mensajes de menor identificador a mayor.
	 */
	void mostrarTodosMensajesPriv(BSTree<KeyValue<string, Mensaje*>> *arbol);

	/*
	 * PRE={Que el arbol de mensajes no esté vacio}
	 * POST={Recorre el arbol en busca del identificador del mensaje a borrar}
	 * COMPL: O(log n)
	 * DESC: Recorre el arbol de mensajes en preOrden en busca del identificador del mensaje que queremos borrar,
	 *       una vez encontrado ese identifiacdor lo devuelve por parámetros.
	 */
	bool borrarMensajePriv(BSTree<KeyValue<string, Mensaje*>> *arbol, KeyValue<string, Mensaje*> &mensaje, string identificador);

	/*
	 * PRE={Que el arbol de mensajes no esté vacio}
	 * POST={Recorre el arbol en busca del identificador del mensaje que queremos mostrar}
	 * COMPL: O(log n)
	 * DESC: Recorre el arbol de mensajes en preOrden en busca del identificador del mensaje que queremos mostrar,
	 *       una vez encontrado ese identificador lo devuelve por parámetros
	 */
	bool buscarMensajePriv(BSTree<KeyValue<string, Mensaje*>> *arbol, KeyValue<string, Mensaje*> &mensaje, string identificador);

	/*
	 * PRE={Que el arbol de mensajes no esté vacio}
	 * POST={Recorre el arbol en busca de todos los mensajes que ha escrito el autor que indicamos}
	 * COMPL: O(n)
	 * DESC: Recorre el arbol en inOrden en busca de todos los mensajes que ha escrito el autor que indicamos por parametros,
	 *       una vez encontrados los inserta en una lista de mensajes, estos son insertados de menor a mayor identificador, ya
	 *       que el recorrido que realizamos es inOrden.
	 */
	void mostrarListaAutorPriv(BSTree<KeyValue<string, Mensaje*>> *arbol, string autor, ListaPI<Mensaje*>*lMensajes);

	/*
	 * PRE={Que el arbol de caractres no esté vacio}
	 * POST={Recorre el arbol en busca de las letras del mensaje a codificar}
	 * COMPL: O(log n)
	 * DESC: Busca la letra sin codificar en el arbol y la devuleve codificada
	 */
	bool codificarMensajePriv(BSTree<KeyValue<char, char>> *arbol, char letraO, char &letraS);

	/*
	 * PRE={Que el arbol de caracteres no esté vacio}
	 * POST={Recorre el arbol en busca de las letras del mensaje a decodificar}
	 * COMPL: O(n)
	 * DESC: Busca la letra codificada y la devuelve decodificada
	 */
	bool decodificarMensajePriv(BSTree<KeyValue<char, char>> *arbol, char letraO, char &letraS);
   
public:

   // PRE  = { }
   // POST = { passwd = 0 }
   // DESC:  Carga datos de mensajes en el sistema.
   // COMPL: O(1)
         Cripto      ();
      
   // PRE  = { }
   // POST = { this->passwd = passwd % 26, if (passwd==0) then 1 }
   // DESC:  Establece una contraseña y la guarda codificada. En realidad, es un
   //        desplazamiento de cada una de las 26 letras entre 1 y 25.
   // COMPL: O(n)
   void  cambiarContrasenia (int passwd);

   /*
    * PRE={}
    * POST={Inserta en el arbol de mensajes un nuevo mensaje}
    * COMPL: O(1)
    * DESC: Inserta un nuevo mensaje en el sistema a partir de su identificador, texto y autor.
    */
   void insertarMensaje(string identificador, string texto, string autor);

   /*
    * PRE={Que el arbol de mensajes no esté vacio y exista el identificador}
    * POST={Si el identificador del mensaja que queremos borrar está en el arbol lo borra}
    * COMPL:O(1)
    * DESC: Borra un mensaje dado su identificador.
    */
   void borrarMensaje();

   /*
    * PRE={Que el arbol de mensajes no este vacio y exista el identificador}
    * POST={Si el identificador del mensaje está en el arbol muestra ese mensaje}
    * COMPL: O(1)
    * DESC: Busca un mensaje por su identificador, devuelve el mensaje y lo muestra por pantalla.
    */
   void buscarMensaje();

   /*
    * PRE={Que el arbol de mensajes no esté vacio}
    * POST={Muestra todos los mensajes del arbol}
    * COMPL: O(1)
    * DESC: Muestra todos los mensajes.
    */
   void mostrarTodosMensajes();

   /*
    * PRE={Que el arbol de mensajes no esté vacio}
    * POST={Muestra una lista con todos los mensajes del autor que le pasamos por parametros}
    * COMPL: O(1)
    * DESC: Devuelve una lista con todos los mensajes de un autor y los muestra por pantalla.
    */
   void mostrarListaAutor(ListaPI<Mensaje* >*&lMensajes);

   /*
    * PRE={Que el arbol de caractres no esté vacio(NULL) y que el mensaje esté en el arbol}
    * POST={Codifica el mensaje que le indicamos}
    * COMPL: O(n)
    * DESC: Utiliza un arbol de caractres para sustituir las letras del mensaje por otras.
    */
   void codificarMensaje();

   /*
    * PRE={Que el mensaje a decodificar exista}
    * POST={Decodifica el mensaje que le indicamos}
    * COMPL: O(n)
    * DESC: Cambia cada letra del mensaje codificado por las letras originales.
    */
   void decodificarMensaje();

   /*
    * DESCTRUCOR:
    * PRE={}
    * POST={Libera el espacio de la memoria}
    * COMPL: O(n)
    * DESC:
    */
   ~Cripto();

};


#endif /* __CRIPTO_H */
