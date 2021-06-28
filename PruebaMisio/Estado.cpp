#include "Estado.h"
#include <iostream>
#include <ctime>
using namespace std;



void Estado::aplicaRegla()
{
	int r = rand() % (5);
	
	switch (r)
	{
	case 0://Mover un misionero
		if (bandIda == true)
		{
			if (mI >= 1 && mD<= 2)
			{
				mI--;//
				mD++;
				cout << "M: ";
			}
			else
				aplicaRegla();
		}
		else//Regresos
		{
			if (mD >= 1 && mI <=2)
			{
				mD--;
				mI++;
				cout << "M: ";
			}
			else
				aplicaRegla();
		}
		break;
	case 1://Mover un canibal
		if (bandIda == true)
		{
			if (cI >= 1 && cD<= 2)
			{
				cI--;//3-1=2
				cD++;
				cout << "C: ";
			}
			else
				aplicaRegla();
		}
		else
		{
			if (cD >= 1  && cI <=2)
			{
				cD--;
				cI++;
				cout << "C: ";
			}
			else
				aplicaRegla();
		}	
		break;
	case 2://Mover dos misioneros
		if (bandIda == true)
		{
			if (mI >= 2 && mD <=1)
			{
				mI -= 2;
				mD += 2;
				cout << "MM: ";
			}
			else
				aplicaRegla();
		}
		else
		{
			if (mD >= 2 && mI <=1)
			{
				mD -= 2;
				mI += 2;
				cout << "MM: ";
			}
			else
				aplicaRegla();
		}
		break;
	case 3://Mover un misionero y un canibal
		if (bandIda == true)
		{
			if (mI >= 1 && cI >= 1 && mD <= 2 && cD <=2)
			{
				mI--;
				cI--;
				mD++;
				cD++;
				cout << "MC: ";
			}
			else
				aplicaRegla();

		}
		else
		{
			if (mD >= 1 && cD >= 1 && mI <= 2 && cI <= 2)
			{
				mD--;
				cD--;
				mI++;
				cI++;
				cout << "MC: ";
			}
			else
				aplicaRegla();
		}
		break;
	case 4://Mover dos canibales
		if (bandIda == true)
		{
			if (cI >= 2 && cD <= 1)
			{
				cI -= 2;
				cD += 2;
				cout << "CC: ";
			}
			else
				aplicaRegla();
		}
		else
		{
			if (cD >= 2 && cI<= 1)
			{
				cD -= 2;
				cI += 2;
				cout << "CC: ";
			}
			else
				aplicaRegla();
		}
		break;
	}

}

bool Estado::esValido()
{
	int r = 0;

	if (mI == 0 || mD == 0)
	{
		cout << endl << "!!No puede comer" << endl;;
		return true;
	}
	else
	{
		if (mI >= cI && mD >= cD)
		{
			r = 0;
			cout << endl << "!!No puede comer" << endl;;
			return true;

		}
		else
		{
			r = 0;
			cout << endl << endl << "!!Si puede comer" << endl;
			return false;

		}
	}

}

bool Estado::esTerminal()
{
	if (mI == 0 && cI == 0)
	{
		cout << endl << "ESTADO VALIDO!!!!! ";
		return true;
	}
	else
		return false;
}