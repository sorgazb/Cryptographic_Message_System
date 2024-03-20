/*
 * cripto.cpp
 *  Autor: Sergio Orgaz Bravo
 *  Fecha: 29 abril 2022
 *  Correo: sorgazbr@alumnos.unex
 *  Descripcion: Desarrollo de la clase Cripto.
 */

#include <iostream>
#include <fstream>
#include <string>

#include "cripto.h"


using namespace std;




// ******************************************************************
//                       OPERACIONES PRIVADAS
// ******************************************************************

void Cripto::cargarMensajes() {
	Mensaje *m;
	string identificador;
	string texto;
	string autor;
	ifstream flujoCripto;
	flujoCripto.open("mensajes.csv");
	if(flujoCripto.is_open()){
		while(!flujoCripto.eof()){
			getline(flujoCripto, identificador, '#');
			if(!flujoCripto.eof()){
				getline(flujoCripto, texto, '#');
				getline(flujoCripto, autor);
				insertarMensaje(identificador, texto, autor);
			}
		}
		flujoCripto.close();
	}
}

void Cripto::escribirFichero() {
	ofstream flujoCripto;
	flujoCripto.open("mensajes.csv");
	if(flujoCripto.is_open()){
		recorridoEscribirFichero(arbolM, flujoCripto);
		flujoCripto.close();
	}
}

void Cripto::recorridoEscribirFichero(BSTree<KeyValue<string, Mensaje*> > *arbol, ofstream &flujoCripto) {
	Mensaje *m;
	BSTree<KeyValue<string, Mensaje*>> *arbolAux;
	KeyValue<string, Mensaje*> mensaje;
	if(!arbol->empty()){
		mensaje= arbol->root();
		m= mensaje.value();
		flujoCripto<<m->getIdentificador()<<"#"<<m->getTexto()<<"#"<<m->getAutor()<<endl;
		arbolAux= arbol->left();
		if(arbolAux!=nullptr){
			recorridoEscribirFichero(arbolAux, flujoCripto);
		}
		arbolAux= arbol->right();
		if(arbolAux!=nullptr){
			recorridoEscribirFichero(arbolAux, flujoCripto);
		}
	}
}

void Cripto::mostrarTodosMensajesPriv(BSTree<KeyValue<string, Mensaje*>> *arbol) {
	BSTree<KeyValue<string, Mensaje*>> *arbolAux;
	if(!arbol->empty()){

		arbolAux= arbol->left();
		if(arbolAux!=nullptr){
			mostrarTodosMensajesPriv(arbolAux);
		}
		Mensaje *m;
		KeyValue<string, Mensaje*> mensaje;
		mensaje= arbol->root();
		m= mensaje.value();
		m->mostrar();
		arbolAux= arbol->right();
		if(arbolAux!=nullptr){
			mostrarTodosMensajesPriv(arbolAux);
		}
	}
}

bool Cripto::borrarMensajePriv(BSTree<KeyValue<string, Mensaje*> > *arbol, KeyValue<string, Mensaje*> &mensaje, string identificador) {
	bool enc= false;
	BSTree<KeyValue<string, Mensaje*>> *arbolAux;
	KeyValue<string, Mensaje*> aux;
	if(!arbol->empty()){
		aux= arbol->root();
		if(aux.key()==identificador){
			mensaje=aux;
			enc=true;
		}
		else{
			if(identificador < aux.key()){
				arbolAux= arbol->left();
				if(arbolAux!=NULL){
					enc=borrarMensajePriv(arbolAux, mensaje, identificador);
				}
			}
			else{
				arbolAux= arbol->right();
				if(arbolAux!=NULL){
					enc=borrarMensajePriv(arbolAux, mensaje, identificador);
				}
			}
		}
	}
	return enc;
}

bool Cripto::buscarMensajePriv(BSTree<KeyValue<string, Mensaje*> > *arbol, KeyValue<string, Mensaje*> &mensaje, string identificador) {
	bool enc=false;
	BSTree<KeyValue<string, Mensaje*>> *arbolAux;
	KeyValue<string, Mensaje*> aux;
	if(!arbol->empty()){
		aux= arbol->root();
		if(aux.key()==identificador){
			mensaje=aux;
			enc=true;
		}
		else{
			if(identificador < aux.key()){
				arbolAux= arbol->left();
				if(arbolAux!=NULL){
					enc=buscarMensajePriv(arbolAux, mensaje, identificador);
				}
			}
			else{
				arbolAux= arbol->right();
				if(arbolAux!=NULL){
					enc=buscarMensajePriv(arbolAux, mensaje, identificador);
				}
			}
		}
	}
	return enc;
}

void Cripto::mostrarListaAutorPriv(BSTree<KeyValue<string, Mensaje*> > *arbol, string autor, ListaPI<Mensaje*> *lMensajes) {
	BSTree<KeyValue<string, Mensaje*>> *arbolAux;
	KeyValue<string, Mensaje*> mensaje;
	Mensaje *m;
	if(!arbol->empty()){
		arbolAux= arbol->left();
		if(arbolAux!=nullptr){
			mostrarListaAutorPriv(arbolAux, autor, lMensajes);
		}
		mensaje= arbol->root();
		m= mensaje.value();
		if(m->getAutor()==autor){
			lMensajes->insertar(m);
		}
		arbolAux= arbol->right();
		if(arbolAux!=nullptr){
			mostrarListaAutorPriv(arbolAux, autor, lMensajes);
		}
	}
}

bool Cripto::codificarMensajePriv(BSTree<KeyValue<char, char> > *arbol, char letraO, char &letraS) {
	bool enc=false;
	KeyValue<char, char> letra;
	BSTree<KeyValue<char, char>> *letraAux;
	if(!arbol->empty()){
		letra= arbol->root();
		if(letra.key()==letraO){
			letraS= letra.value();
			enc= true;
		}
		else{
			if(letraO < letra.key()){
				letraAux= arbol->left();
				if(letraAux!=nullptr){
					enc=codificarMensajePriv(letraAux, letraO, letraS);
				}
			}
			else{
				letraAux= arbol->right();
				if(letraAux!=nullptr){
					enc=codificarMensajePriv(letraAux, letraO, letraS);
				}
			}
		}
	}
	return enc;
}

bool Cripto::decodificarMensajePriv(BSTree<KeyValue<char, char> > *arbol, char letraO, char &letraS) {
	bool enc=false;
	BSTree<KeyValue<char, char>> *letraAux;
	KeyValue<char, char> letra;
	if(!arbol->empty()){
		letra= arbol->root();
		if(letra.value()==letraO){
			enc=true;
			letraS=letra.key();
		}
		else{
			letraAux= arbol->left();
			if(letraAux!=nullptr){
				enc=decodificarMensajePriv(letraAux, letraO, letraS);
			}
			if(!enc){
				letraAux= arbol->right();
				if(letraAux!=nullptr){
					enc=decodificarMensajePriv(letraAux, letraO, letraS);
				}
			}
		}
	}
	return enc;
}


// ******************************************************************
//                       INTERFAZ PUBLICA
// ******************************************************************


Cripto::Cripto () {
	arbolM= new BSTree<KeyValue<string, Mensaje*>>;
	arbolCambiarCaractres= new BSTree<KeyValue<char, char>>;
	passwd=0;
	cargarMensajes();
}

void Cripto::cambiarContrasenia (int passwd) {
   
   // 1. Si cambiamos la contraseña, tenemos que rehacer el árbol de coddificación.
   
   // TODO: eliminar y crear un nuevo árbol
	if(arbolCambiarCaractres!=nullptr){
		delete arbolCambiarCaractres;
	}
	arbolCambiarCaractres= new BSTree<KeyValue<char, char>>;
   
   // 2. Cambiar la contraseña
   this->passwd = passwd % 26;
   if (this->passwd == 0) { // No permitimos que sea 0.
      this->passwd++;
   }
   
   // Letras al árbol.
   // El orden de las letras en el vector hace que el árbol resultante
   // este equilibrado:
   char c_origen  [26] = {'m', 'g', 's', 'd', 'j', 'p', 'w', 'b', 'e',
                          'h', 'k', 'n', 'r', 'u', 'y', 'a', 'c', 'f',
                          'i', 'l', 'o', 'q', 't', 'v', 'x', 'z' };
         
   for (int i = 0; i < 26; i++) {
      
      char letraO, letraS;
      
      letraO = c_origen[i];
      letraS = (((int(letraO) - 97) + this->passwd) % 26) + 97;
      
      // TODO: crear KeyValue e insertar en el árbol.
      KeyValue<char, char> cambiarCaracteres(letraO, letraS);
      arbolCambiarCaractres->insert(cambiarCaracteres);
      
   }

}

void Cripto::insertarMensaje(string identificador, string texto, string autor) {
	Mensaje *m= new Mensaje(identificador, texto, autor);
	KeyValue<string, Mensaje*> mensaje(identificador,m);
	arbolM->insert(mensaje);
}

void Cripto::borrarMensaje() {
	string identificador;
	cout<<"Introduce el ID del mensaje a borrar: "<<endl;
	getline(cin, identificador);
	Mensaje *m;
	KeyValue<string, Mensaje*> mensaje;
	if(!arbolM->empty()){
		if(borrarMensajePriv(arbolM, mensaje, identificador)){
			arbolM->remove(mensaje);
			m= mensaje.value();
			cout<<"Mensaje borrado."<<endl;
			delete m;
		}
		else{
			cout<<"Error.No existe ningun mensaje con ese ID."<<endl;
		}
	}
}

void Cripto::buscarMensaje() {
	string identificador;
	cout<<"Introduce el ID del mensaje a buscar: "<<endl;
	getline(cin,identificador);
	Mensaje *m;
	KeyValue<string, Mensaje*> mensaje;
	if(!arbolM->empty()){
		if(buscarMensajePriv(arbolM, mensaje, identificador)){
			m= mensaje.value();
			m->mostrar();
		}
		else{
			cout<<"Error.No existe ningun mensaje con ese ID."<<endl;
		}
	}
}

void Cripto::mostrarTodosMensajes() {
	if(!arbolM->empty()){
		mostrarTodosMensajesPriv(arbolM);
	}
}

void Cripto::mostrarListaAutor(ListaPI<Mensaje*> *&lMensajes) {
	Mensaje *m;
	string autor;
	if(!arbolM->empty()){
		cout<<"Introduce el nombre del autor a buscar: "<<endl;
		getline(cin,autor);
		lMensajes= new ListaPI<Mensaje*>;
		mostrarListaAutorPriv(arbolM, autor, lMensajes);
		if(lMensajes!=nullptr){
			lMensajes->moverInicio();
			while(!lMensajes->enFin()){
				lMensajes->consultar(m);
				m->mostrar();
				lMensajes->avanzar();
			}
			delete lMensajes;
		}
	}
}

void Cripto::codificarMensaje() {
	string identificador;
	cout<<"Introduce el ID del mensaje a codificar: "<<endl;
	getline(cin, identificador);
	Mensaje *m;
	KeyValue<string, Mensaje*> mensaje;
	string texto;
	char letraCambiada;
	if(arbolCambiarCaractres!=nullptr){
		if(buscarMensajePriv(arbolM, mensaje, identificador)){
			m= mensaje.value();
			texto= m->getTexto();
			if(this->passwd!=0){
				for(int i=0; i<texto.length(); i++){
					if(codificarMensajePriv(arbolCambiarCaractres, texto[i], letraCambiada)){
						texto[i]= letraCambiada;
					}
				}
				m->setTexto(texto);
				cout<<"Mensaje codificado."<<endl;
			}
			else{
				cout<<"Error.Para codificar el mensaje se necesita cambiar el PIN "<<endl;
			}
		}
		else{
			cout<<"Error.No existe ningún mensaje con ese ID."<<endl;
		}
	}
}

void Cripto::decodificarMensaje() {
	string identificador;
	cout<<"Introduce el ID del mensaje a decodificar: "<<endl;
	getline(cin, identificador);
	Mensaje *m;
	KeyValue<string, Mensaje*> mensaje;
	string texto;
	char letraCambiada;
	if(buscarMensajePriv(arbolM, mensaje, identificador)){
		m= mensaje.value();
		texto= m->getTexto();
		for(int i=0; i<texto.length(); i++){
			if(decodificarMensajePriv(arbolCambiarCaractres, texto[i], letraCambiada)){
				texto[i]=letraCambiada;
			}
		}
		m->setTexto(texto);
		cout<<"Mensaje decodificado."<<endl;
	}
	else{
		cout<<"Error.No existe ningún mensaje con ese ID."<<endl;
	}
}

Cripto::~Cripto() {
	escribirFichero();
	Mensaje *m;
	KeyValue<string, Mensaje*> mensaje;
	while(arbolM->empty()){
		mensaje= arbolM->root();
		arbolM->remove(mensaje);
		m= mensaje.value();
		delete m;
	}
	delete arbolM;
	if(arbolCambiarCaractres!=nullptr){
		delete arbolCambiarCaractres;
	}
}
