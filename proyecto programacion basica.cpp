#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <cstring>
#include <windows.h>
#include<locale.h>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>


using namespace std;

int* numjuego, * anio, registro, n = 1;
string* nombre, * caracteristica, * descripcion, * genero, * clasificacion;
float* precio, * impuesto, * total;

void Agregar();
void Eliminar();
void Mostrar();
void Modificar();
void Archivo();

int main() {

	int opcion;
	cout << "****MOON GAMES*****" << endl;
	cout << "------------MENU---------------\n";
	cout << "1.Agregar Articulo\n";
	cout << "2.Mostrar Articulo\n";
	cout << "3.Modificar Articulo\n";
	cout << "4.Eliminar Articulo\n";
	cout << "5.Limpiar pantalla\n";
	cout << "6.Salir\n";
	cout << "\n";
	cout << "\n";
	cout << "Eliga una opcion para continuar..\n";
	cin >> opcion;

	switch (opcion) {

	case 1:
		Agregar();
		system("pause");
		return main();
		break;


	case 2:
		Mostrar();
		system("pause");
		return main();
		break;

	case 3:
		Modificar();
		system("pause");
		return main();
		break;

	case 4:
		Eliminar();
		system("pause");
		return main();
		break;

	case 5:
		system("cls");
		return main();
		break;


	case 6:
		Archivo();
		exit(1);
		break;

	default:
		cout << ("Opcion incorrecta");
		return main();
		break;
	}





}

void Agregar()
{
	cout << "Cuantos juegos desea agregar: " << endl;
	cin >> registro;
	numjuego = new int[registro];
	anio = new int[registro];
	nombre = new string[registro];
	caracteristica = new string[registro];
	descripcion = new string[registro];
	genero = new string[registro];
	clasificacion = new string[registro];
	precio = new float[registro];
	impuesto = new float[registro];
	total = new float[registro];

	for (int i = 0; i < registro; i++)
	{
		cout << "Ingrese el numero del juego: " << endl;
		cin >> numjuego[i];

		do
		{
			if (numjuego[i] == numjuego[i - n])
			{
				cout << "El juego ya existe" << endl;
				cout << "Ingrese el numero del juego" << endl;
				cin >> numjuego[i];
			}
			else
			{
				n = n + 1;

			}

		} while (n <= i);
		n = 1;
		cout << "Ingrese nombre del videojuego:\n";
		cin.ignore();
		getline(cin, nombre[i]);
		cout << "Ingrese caracteristica del videojuego: \n";
		getline(cin, caracteristica[i]);
		cout << "Ingrese descripcion del videojuego: \n";
		getline(cin, descripcion[i]);
		cout << "Ingrese clasificacion del videojuego: \n";
		getline(cin, clasificacion[i]);
		cout << "Ingrese genero del videojuego:  \n";
		getline(cin, genero[i]);
		cout << "Ingrese precio del videojuego: \n";
		cin >> precio[i];
		cout << "Ingrese año del videojuego:" << endl;
		cin >> anio[i];
		impuesto[i] = (precio[i] * .16);
		total[i] = (precio[i] + impuesto[i]);
		cout << "Su precio total es de: " << endl;
		cout << total[i];
		cout << "\n\n";

	}

}

void Mostrar()
{
	cout << "LISTA DE JUEGOS REGISTRADOS: " << endl;
	for (int i = 0; i < registro; i++)
	{
		if (numjuego[i] != 0)
		{
			cout << "NUMERO DE JUEGO: " << numjuego[i] << endl;
			cout << "Nombre del juego : " << nombre[i].c_str() << endl;
			cout << "Caracteristica: " << caracteristica[i].c_str() << endl;
			cout << "Descripcion: " << descripcion[i].c_str() << endl;
			cout << "Clasificacion: " << clasificacion[i].c_str() << endl;
			cout << "Genero: " << genero[i].c_str() << endl;
			cout << "Precio: " << precio[i] << endl;
			cout << "Año: " << anio[i] << endl;
			cout << "Impuesto: " << impuesto[i] << endl;
			cout << "Total: " << total[i];
			cout << "\n\n";

		}

	}

}

void Eliminar()
{
	int opeli;
	cout << "Ingrese el numero de juego a eliminar: " << endl;
	cin >> opeli;

	for (int i = 0; i < registro; i++)
	{
		if (opeli == numjuego[i])
		{
			numjuego[i] = 0;
			nombre[i] = "";
			caracteristica[i] = "";
			descripcion[i] = "";
			clasificacion[i] = "";
			genero[i] = "";
			precio[i] = 0;
			anio[i] = 0;
			impuesto[i] = 0;
			total[i] = 0;
		}

	}
	cout << "El videojuego que selecciono ha sido eliminado" << endl;
}

void Archivo()
{


	ofstream archivos;
	string nombreArchivo;
	nombreArchivo = "LISTA DE JUEGOS MOON GAMES";
	archivos.open(nombreArchivo.c_str(), ios::out);


	if (archivos.fail())
	{
		printf("ERROR EL ARCHIVO NO PUDO SER CREADO");
		system("pause");
		exit(1);
	}



	for (int i = 0; i < registro; i++)
	{
		archivos << "NUMERO DE JUEGO: " << numjuego[i] << "\n";
		archivos << "NOMBRE DE JUEGO: " << nombre[i] << "\n";
		archivos << "CARACTERISTICAS: " << caracteristica[i] << "\n";
		archivos << "GENERO: " << genero[i] << "\n";
		archivos << "DESCRIPCION: " << descripcion[i] << "\n";
		archivos << "CLASIFICACION: " << clasificacion[i] << "\n";
		archivos << "PRECIO UNITARIO: " << precio[i] << "\n";
		archivos << "AÑO: " << anio[i] << "\n";
		archivos << "IMPUESTO: " << impuesto[i] << "\n";
		archivos << "TOTAL: " << total[i] << "\n \n";



	}
	archivos.close();
}

void Modificar()
{
	int modd;
	int opmod;

	cout << "Ingrese la opcion que desea modificar del juego: \n1.Nombre: \n2.Caracteristica: \n3.Descripcion: \n4.Clasificacion: \n5.Genero: \n6.Precio: \n6.Año: \n7.Impuesto: \n8.Todo:\n ";
	cin >> opmod;

	do
	{
		cout << "Ingrese el numero de juego a modificar: " << endl;
		cin >> modd;

		switch (opmod)
		{
		case 1:
			for (int i = 0; i < registro; i++)
			{
				if (modd == numjuego[i])
				{
					cout << "Ingrese el nuevo nombre del juego: " << endl;
					cin.ignore();
					getline(cin, nombre[i]);
				}
			}
			break;


		case 2:
			for (int i = 0; i < registro; i++)
			{
				if (modd == numjuego[i])
				{
					cout << "Ingrese la nueva caracteristica del juego: " << endl;
					cin.ignore();
					getline(cin, caracteristica[i]);
				}
			}
			break;

		case 3:
			for (int i = 0; i < registro; i++)
			{
				if (modd == numjuego[i])
				{
					cout << "Ingrese la nueva descripcion del juego: " << endl;
					cin.ignore();
					getline(cin, descripcion[i]);
				}
			}
			break;

		case 4:
			for (int i = 0; i < registro; i++)
			{
				if (modd == numjuego[i])
				{
					cout << "Ingrese la nueva clasificacion del juego: " << endl;
					cin.ignore();
					getline(cin, clasificacion[i]);
				}
			}
			break;


		case 5:
			for (int i = 0; i < registro; i++)
			{
				if (modd == numjuego[i])
				{
					cout << "Ingrese el genero del videojuego: " << endl;
					cin.ignore();
					getline(cin, genero[i]);
				}
			}
			break;


		case 6:
			for (int i = 0; i < registro; i++)
			{
				if (modd == numjuego[i])
				{
					cout << "Ingrese el precio unitario: " << endl;
					cin >> precio[i];
					impuesto[i] = (precio[i] * .16);
					total[i] = (precio[i] + impuesto[i]);
				}
			}
			break;


		case 7:
			for (int i = 0; i < registro; i++)
			{
				if (modd == numjuego[i])
				{
					cout << "Ingrese el Año: " << endl;
					cin >> anio[i];
				}
			}
			break;


		case 8:
			for (int i = 0; i < registro; i++)
			{
				if (modd == numjuego[i])
				{
					cout << "Ingrese nombre del videojuego:\n";
					cin.ignore();
					getline(cin, nombre[i]);
					cout << "Ingrese caracteristica del videojuego: \n";
					getline(cin, caracteristica[i]);
					cout << "Ingrese descripcion del videojuego: \n";
					getline(cin, descripcion[i]);
					cout << "Ingrese clasificacion del videojuego: \n";
					getline(cin, clasificacion[i]);
					cout << "Ingrese genero del videojuego:  \n";
					getline(cin, genero[i]);
					cout << "Precio Unitario:" << endl;
					cin >> precio[i];
					impuesto[i] = (precio[i] * .16);
					total[i] = (precio[i] + impuesto[i]);
					cout << "Ingrese año del videojuego:" << endl;
					cin >> anio[i];

				}
			}
			break;

		default:
			cout << "Opcion incorrecta: " << endl;
		}

		cout << "El videojuego que selecciono ha sido modificado. " << endl;

	} while (modd < 0);

}









	
					
				
