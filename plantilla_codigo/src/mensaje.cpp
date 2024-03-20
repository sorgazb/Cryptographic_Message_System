//
//  mensaje.cpp
//  Autor: Sergio Orgaz Bravo
//  Fecha: 29 abril 2022
//  Correo: sorgazbr@alumnos.unex
//  Descripción: Esta clase se encarga de guardar toda la información del mensaje,
//               así como el identificador, el texto y el autor del mensaje.
//

#include "mensaje.h"

Mensaje::Mensaje() {
	identificador="";
	texto="";
	autor="";
}

Mensaje::Mensaje(string identificador, string texto, string autor) {
	this->identificador=identificador;
	this->texto=texto;
	this->autor=autor;
}

void Mensaje::setIdentificador(string identificador) {
	this->identificador=identificador;
}

void Mensaje::setTexto(string texto) {
	this->texto=texto;
}

void Mensaje::setAutor(string autor) {
	this->autor=autor;
}

string Mensaje::getIdentificador() {
	return identificador;
}

string Mensaje::getTexto() {
	return texto;
}

string Mensaje::getAutor() {
	return autor;
}

void Mensaje::mostrar() {
	cout<<identificador<<" # "<<texto<<" # "<<autor<<endl;
}

Mensaje::~Mensaje() {
}
