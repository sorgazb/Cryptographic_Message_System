/*
 * prog_principal.cpp
 *  Autor: Sergio Orgaz Bravo
 *  Fecha: 29 abril 2022
 *  Correo: sorgazbr@alumnos.es
 *  Descripción: Clase Principal
 */

#include <iostream>
#include <fstream>
#include <string>

#include "cripto.h"

using namespace std;


// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu() {

	int opcion;

	do {
		cout << endl;
		cout << "______________ MENU PRINCIPAL ______________"<< endl << endl;

	  cout << "     1. Insertar mensaje                   " << endl;
      cout << "     2. Borrar mensaje                     " << endl;
      cout << "     3. Buscar mensaje y mostrar           " << endl;
      cout << "     4. Mostrar todos                      " << endl;
      cout << "     5. Mensajes por autor                 " << endl;
      cout << "                                           " << endl;
      cout << "     6. Cambiar PIN                        " << endl;
      cout << "     7. Codificar un mensaje               " << endl;
      cout << "     8. Decodificar un mensaje             " << endl;
		cout <<                                                  endl;
		cout << "     0. Finalizar.                         " << endl;
		cout << "                        Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 8));

	return opcion;
}

// Programa principal: 
int main() {
	int opcion;
	bool fin=false;
	string identificador, texto, autor;
	Cripto *cripto= new Cripto;
	ListaPI<Mensaje*> *lMensajes= nullptr;
	int pin;
   
   
	do {
		opcion = menu();

		switch (opcion) {
			case 1:
				cout<<"OPCION 1 -> INSERTAR MENSAJE: "<<endl;
				cout<<"Introduce el ID del mensaje: "<<endl;
				getline(cin,identificador);
				cout<<"Introduce el texto del mensaje: "<<endl;
				getline(cin,texto);
				cout<<"Introduce el autor del mensaje: "<<endl;
				getline(cin,autor);
				cripto->insertarMensaje(identificador, texto, autor);
				break;

			case 2:
				cout<<"OPCION 2 -> BORRAR MENSAJE: "<<endl;
				cripto->borrarMensaje();
				break;

			case 3:
				cout<<"OPCION 3 -> BUSCAR MENSAJE Y MOSTRAR: "<<endl;
				cripto->buscarMensaje();
				break;

			case 4:
				cout<<"OPCION 4 -> MOSTRAR TODOS: "<<endl;
				cripto->mostrarTodosMensajes();
				break;

			case 5:
				cout<<"OPCION 5 -> MENSAJES POR AUTOR: "<<endl;
				cripto->mostrarListaAutor(lMensajes);
				break;

			case 6:
				cout<<"OPCION 6 -> CAMBIAR PIN: "<<endl;
				cout<<"Introduce el PIN a cambiar: "<<endl;
				cin>>pin;
				cripto->cambiarContrasenia(pin);
				break;

			case 7:
				cout<<"OPCION 7 -> CODIFICAR UN MENSAJE: "<<endl;
				cripto->codificarMensaje();
				break;

			case 8:
				cout<<"OPCION 8 -> DECODIFICAR UN MENSAJE: "<<endl;
				cripto->decodificarMensaje();
				break;

			case 0:
				fin = true;
				delete cripto;
				delete lMensajes;
				break;

			default:
				break;

		}
		
	} while (!fin);

	return 0;
}


