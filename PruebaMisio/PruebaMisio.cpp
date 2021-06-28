// PruebaMisio.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Estado.h"
#include <time.h>
#include <vector>

using namespace std;

int main()
{
    //cout << "Hello World!\n";
	//Estado algo = new Estado();

	Estado algo;
	Estado algoAnt;
	//vector<Estado> listEstados;
	//vector<vector<Estado>> lisdeLisEdo;
	int ite = 0, r;

	srand(time(NULL));

	while (!algo.esTerminal())
	{
		algoAnt = algo;



		if (algo.bandIda == true)
		{
			algo.aplicaRegla();
			cout << "-> Ida" << endl;
			cout << "Misionero: " << algo.mI << " Canibal: " << algo.cI <<"|-------------|Misionero: " <<algo.mD << " Canibal: " <<algo.cD;
			algo.bandIda = false;
		}
		else
		{
			algo.aplicaRegla();
			cout << "<- Regreso" << endl;
			cout << "Misionero: " << algo.mI << " Canibal: " << algo.cI << "|-------------|Misionero: " << algo.mD << " Canibal: " << algo.cD;
			algo.bandIda = true;
		}

		if (!algo.esValido())
		{
			cout << "!!Regresar a estado anterior" << endl << endl;
			algo = algoAnt;
		}		
		ite++;
	}
	
	cout << "Iteraciones : " << ite+1<<endl;

}



/*
bool esValido(string cadena)
{
	string valido = "MMMCCC";

	return true;
}*/

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
