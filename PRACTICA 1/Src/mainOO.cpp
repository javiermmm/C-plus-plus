#include "BibliotecaOO.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main () {

	CBiblioteca b = CBiblioteca ();

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
							CLibro nuevo = CLibro::leerLibro();
							if (!b.anyadeLibro(nuevo))
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
							if (!b.borraLibro(numRegistro))
								cout << "ERROR: El libro que desea borrar esta PRESTADO, o no pertenece a la biblioteca" << endl;
							else
								cout << "Libro borrado" << endl;
							}
							cin.ignore();
							system ("pause");
							break;
					case '3':	
							b.muestraLibros ();
							system ("pause");
							break;
					case '4': {
							int numRegistro;
							CLibro li;
							do {
								cout << "Introduzca el numero de registro del libro que desea consultar" << endl;
								cin >> numRegistro;
							} while (numRegistro < 1);
							if (!b.buscaLibroPorRegistro(numRegistro, li))
								cout << "ERROR: El libro que trata de consultar no esta en la biblioteca" << endl;
							else
								li.muestraLibro ();
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
							CSocio nuevo = CSocio::leerSocio();
							if (!b.anyadeSocio(nuevo))
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
							if (!b.borraSocio(numCodigo))
								cout << "ERROR: El socio que desea borrar aún tiene prestamos, o no pertenece a la biblioteca" << endl;
							else
								cout << "Socio borrado" << endl;
							}
							cin.ignore();
							system ("pause");
							break;
					case '3':
							b.muestraSocios ();
							system ("pause");
							break;
					case '4': {
							int numCodigo;
							CSocio so;
							do {
								cout << "Introduzca el codigo de registro del socio que desea consultar" << endl;
								cin >> numCodigo;
							} while (numCodigo < 101);
							if (!b.buscaSocioPorCodigo(numCodigo, so))
								cout << "ERROR: El socio que trata de consultar no pertenece a la biblioteca" << endl;
							else
								so.muestraSocio (b.dameLibros());
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
							CSocio so;
							do {
								cout << "Introduzca el codigo de registro del socio" << endl;
								cin >> numCodigo;
							} while (numCodigo < 101);
							if (!b.buscaSocioPorCodigo(numCodigo, so))
								cout << "ERROR: El socio que ha introducido no pertenece a la biblioteca" << endl;
							else {
								int numRegistro;
								CLibro li;
								do {
									cout << "Introduzca el numero de registro del libro" << endl;
									cin >> numRegistro;
								} while (numRegistro < 1);
								if (!b.buscaLibroPorRegistro(numRegistro, li))
									cout << "ERROR: El libro que ha introducido no esta en la biblioteca" << endl;
								else {
									if (li.dameEstado() != CLibro::Disponible)
										cout << "ERROR: El libro no está disponible para realizar el prestamo" << endl;
									else {
										CFecha f = CFecha::leerFecha();
										if (!b.presta (so.dameNumCodigo(), li.dameNumRegistro(), f))
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
							CSocio so;
							do {
								cout << "Introduzca el codigo de registro del socio" << endl;
								cin >> numCodigo;
							} while (numCodigo < 101);
							if (!b.buscaSocioPorCodigo(numCodigo, so))
								cout << "ERROR: El socio que ha introducido no pertenece a la biblioteca" << endl;
							else {
								int numRegistro;
								CLibro li;
								do {
									cout << "Introduzca el numero de registro del libro" << endl;
									cin >> numRegistro;
								} while (numRegistro < 1);
								if (!b.buscaLibroPorRegistro(numRegistro, li))
									cout << "ERROR: El libro que ha introducido no esta en la biblioteca" << endl;
								else 
									if (!b.devuelve (so.dameNumCodigo(), li.dameNumRegistro()))
										cout << "ERROR: La devolución que trata de realizar NO es correcta." << endl;
							}
							}
							cin.ignore();
							system ("pause");
							break;
					case '3': 
							b.muestraPrestamos ();
							cin.ignore();
							system ("pause");
							break;
					case '4': {
							int numRegistro;
							CLibro li;
							CSocio so;
							do {
								cout << "Introduzca el numero de registro del libro" << endl;
								cin >> numRegistro;
							} while (numRegistro < 1);
							if (!b.buscaLibroPorRegistro(numRegistro, li))
								cout << "ERROR: El libro que trata de consultar no esta en la biblioteca" << endl;
							else {
								if (b.quienTiene(numRegistro, so))
									cout << "El libro lo tiene " << so.dameNombre() << " " << so.dameApellidos() << endl << endl;
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