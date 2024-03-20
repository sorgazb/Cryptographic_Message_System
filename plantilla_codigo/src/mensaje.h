//
//  mensaje.h
//  Autor: Sergio Orgaz Bravo
//  Fecha: 29 abril 2022
//  Correo: sorgazbr@alumnos.unex.es
//  Descripción: Esta clase se encarga de guardar toda la información del mensaje,
//               así como el identificador, el texto y el autor del mensaje.
//

#ifndef MENSAJE_H
#define MENSAJE_H
#include <iostream>
#include <string>
using namespace std;

class Mensaje {
	string identificador;
	string texto;
	string autor;

public:

	/*
	 * CONSTRUCTOR POR DEFECTO:
	 * PRE={}
	 * POST={getIdentificador()="", getTexto()="", getAutor()=""}
	 * COMPL: O(1)
	 * DESC: Crea un mensaje con toda la informacion en cadena vacia.
	 */
	Mensaje();

	/*
	 * CONSTRUCTOR PARAMETRIZADO:
	 * PRE={}
	 * POST={getIdentificador()=identificador, getTexto()=texto, getAutor()=autor}
	 * COMPL: O(1)
	 * DESC: Crea un conductor con toda la información que le llega por parámetros.
	 */
	Mensaje(string identificador, string texto, string autor);

	// MÉTODOS MODIFICADORES:

	/*
	 * PRE={}
	 * POST={Modifica el identificador del mensaje}
	 * COMPL: O(1)
	 */
	void setIdentificador(string identificador);
	/*
	 * PRE={}
	 * POST={Modifica el texto del mensaje}
	 * COMPL: O(1)
	 */
	void setTexto(string texto);
	/*
	 * PRE={}
	 * POST={Modifica el autor del mensaje}
	 * COMPL: O(1)
	 */
	void setAutor(string autor);

	// MÉTODOS SELECTORES:

	/*
	 * PRE={}
	 * POST={Devuelve el identificador del mensaje}
	 * COMPL: O(1)
	 */
	string getIdentificador();
	/*
	 * PRE={}
	 * POST={Devuelve el texto del mensaje}
	 * COMPL: O(1)
	 */
	string getTexto();
	/*
	 * PRE={}
	 * POST={Devuelve el autor del mensaje}
	 * COMPL: O(1)
	 */
	string getAutor();

	/*
	 * PRE={}
	 * POST={Muestra por pantalla toda la información del mensaje}
	 * COMPL:O(1)
	 */
	void mostrar();

	/*
	 * DESTRUCTOR:
	 */
	~Mensaje();
};

#endif /* MENSAJE_H */
