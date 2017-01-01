#include "Biblioteca.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main () {

	TBiblioteca b;
	inicializaBiblioteca (b);
	string opcion;
	string opcion2;
	char op;
	char op2;

	do {
		do {
			system ("cls");
			cout << endl << endl << "MENU PRINCIPAL" << endl;
			cout << "Introduzca una opcion (0-3):" << endl;
			cout << "1.- Gestion de Libros." << endl;
			cout << "2.- Gestion de Socios." << endl;	
			cout << "3.- Gestion de la Biblioteca." << endl;
			cout << "0.- Salir." << endl;
			getline (cin, opcion);
			cout << endl << endl;
		} while ((opcion != "0") && (opcion != "1") && (opcion != "2") && (opcion != "3"));

		op = opcion [0];

		switch (op) {
		case '1': do {
					system ("cls");
					cout << endl << endl <<"MENU DE LIBROS" << endl;
					cout << "Introduzca una opcion (0-4):" << endl;
					cout << "1.- Anyadir un nuevo libro." << endl;
					cout << "2.- Eliminar un nuevo libro." << endl;	
					cout << "3.- Listar todos los libros." << endl;
					cout << "4.- Mostrar los datos de un libro." << endl;
					cout << "0.- Volver al menu principal." << endl;
					getline (cin, opcion2);
					cout << endl << endl;
				} while ((opcion2 != "0") && (opcion2 != "1") && (opcion2 != "2") && (opcion2 != "3") && (opcion2 != "4"));

				op2 = opcion2 [0];

				switch (op2) {
					case '1': {
							TLibro nuevo = leerLibro();
							if (!anyadeLibro(b, nuevo))
								cout << "ERROR: Lista de libros llena" << endl;
							else
								cout << "Libro anyadido" << endl;
							}
							cin.ignore();
							system ("pause");
							break;
					case '2': {
							int numRegistro;
							do {
								cout << "Introduzca el numero de registro del libro que desea eliminar" << endl;
								cin >> numRegistro;
							} while (numRegistro < 1);
							if (!borraLibro(b, numRegistro))
								cout << "ERROR: El libro que desea borrar esta PRESTADO, o no pertenece a la biblioteca" << endl;
							else
								cout << "Libro borrado" << endl;
							}
							cin.ignore();
							system ("pause");
							break;
					case '3':
							muestraLibros (b);
							system ("pause");
							break;
					case '4': {
							int numRegistro;
							TLibro li;
							do {
								cout << "Introduzca el numero de registro del libro que desea consultar" << endl;
								cin >> numRegistro;
							} while (numRegistro < 1);
							if (!buscaLibroPorRegistro(b, numRegistro, li))
								cout << "ERROR: El libro que trata de consultar no está en la biblioteca" << endl;
							else
								muestraLibro (li);
							}
							cin.ignore();
							system ("pause");
							break;
				}
				break;

		case '2': do {
					system ("cls");
					cout << endl << endl << "MENU DE SOCIOS" << endl;
					cout << "Introduzca una opcion (0-4):" << endl;
					cout << "1.- Anyadir socio." << endl;
					cout << "2.- Eliminar socio." << endl;	
					cout << "3.- Listar socios." << endl;
					cout << "4.- Mostrar datos de un socio." << endl;
					cout << "0.- Volver." << endl;
					getline (cin, opcion2);
					cout << endl << endl;
				}while ((opcion2 != "0") && (opcion2 != "1") && (opcion2 != "2") && (opcion2 != "3") && (opcion2 != "4"));

				op2 = opcion2 [0];

				switch (op2) {
					case '1': {
							TSocio nuevo = leerSocio();
							if (!anyadeSocio(b, nuevo))
								cout << "ERROR: Lista de socios llena" << endl;
							else
								cout << "Socio anyadido" << endl;
							}
							cin.ignore();
							system ("pause");
							break;
					case '2': {
							int numCodigo;
							do {
								cout << "Introduzca el codigo de registro del socio que desea eliminar" << endl;
								cin >> numCodigo;
							} while (numCodigo < 101);
							if (!borraSocio(b, numCodigo))
								cout << "ERROR: El socio que desea borrar aún tiene prestamos, o no pertenece a la biblioteca" << endl;
							else
								cout << "Socio borrado" << endl;
							}
							cin.ignore();
							system ("pause");
							break;
					case '3':
							muestraSocios (b);
							system ("pause");
							break;
					case '4': {
							int numCodigo;
							TSocio so;
							do {
								cout << "Introduzca el codigo de registro del socio que desea consultar" << endl;
								cin >> numCodigo;
							} while (numCodigo < 101);
							if (!buscaSocioPorCodigo(b, numCodigo, so))
								cout << "ERROR: El socio que trata de consultar no pertenece a la biblioteca" << endl;
							else
								muestraSocio (so, b.libros);
							}
							cin.ignore();
							system ("pause");
							break;
				}
				break;

		case '3':  do {
					system ("cls");
					cout << endl << endl << "MENU DE BIBLIOTECA" << endl;
					cout << "Introduzca una opcion (0-4):" << endl;
					cout << "1.- Registrar un nuevo Prestamo." << endl;
					cout << "2.- Devolucion de un libro." << endl;	
					cout << "3.- Listado de prestamos." << endl;
					cout << "4.- Buscar un libro." << endl;
					cout << "0.- Volver al menu principal." << endl;
					cin >> opcion2;
					cout << endl << endl;
				}while ((opcion2 != "0") && (opcion2 != "1") && (opcion2 != "2") && (opcion2 != "3") && (opcion2 != "4"));

				op2 = opcion2 [0];

				switch (op2) {
					case '1': {
							int numCodigo;
							TSocio so;
							do {
								cout << "Introduzca el codigo de registro del socio" << endl;
								cin >> numCodigo;
							} while (numCodigo < 101);
							if (!buscaSocioPorCodigo(b, numCodigo, so))
								cout << "ERROR: El socio que ha introducido no pertenece a la biblioteca" << endl;
							else {
								int numRegistro;
								TLibro li;
								do {
									cout << "Introduzca el numero de registro del libro" << endl;
									cin >> numRegistro;
								} while (numRegistro < 1);
								if (!buscaLibroPorRegistro(b, numRegistro, li))
									cout << "ERROR: El libro que ha introducido no está en la biblioteca" << endl;
								else {
									if (li.estado != Disponible)
										cout << "ERROR: El libro no está disponible para realizar el prestamo" << endl;
									else {
										TFecha f = leerFecha();
										if (!presta (b, so.numCodigo, li.numRegistro, f))
											cout << "ERROR: El prestamo NO se ha podido realizar." << endl;
									}
								}
							}
							}
							cin.ignore();
							system ("pause");
							break;
					case '2': {
							int numCodigo;
							TSocio so;
							do {
								cout << "Introduzca el codigo de registro del socio" << endl;
								cin >> numCodigo;
							} while (numCodigo < 101);
							if (!buscaSocioPorCodigo(b, numCodigo, so))
								cout << "ERROR: El socio que ha introducido no pertenece a la biblioteca" << endl;
							else {
								int numRegistro;
								TLibro li;
								do {
									cout << "Introduzca el numero de registro del libro" << endl;
									cin >> numRegistro;
								} while (numRegistro < 1);
								if (!buscaLibroPorRegistro(b, numRegistro, li))
									cout << "ERROR: El libro que ha introducido no está en la biblioteca" << endl;
								else 
									if (!devuelve (b, so.numCodigo, li.numRegistro))
										cout << "ERROR: La operacion de devolucion que trata de realizar no es correcta." << endl;
							}
							}
							cin.ignore();
							system ("pause");
							break;
					case '3':	
							muestraPrestamos (b);
							cin.ignore();
							system ("pause");
							break;
					case '4': {
							int numRegistro;
							TLibro li;
							TSocio so;
							do {
								cout << "Introduzca el numero de registro del libro" << endl;
								cin >> numRegistro;
							} while (numRegistro < 1);
							if (!buscaLibroPorRegistro(b, numRegistro, li))
								cout << "ERROR: El libro que trata de consultar no está en la biblioteca" << endl;
							else {
								if (quienTiene(b, numRegistro, so))
									cout << "El libro lo tiene " << so.nombre << " " << so.apellidos << endl << endl;
								else
									cout << "Ese libro no lo tiene nadie" << endl << endl;
							}
							}
							cin.ignore();
							system ("pause");
							break;
				}
				break;
		}

	} while (opcion != "0");

	return 0;
}