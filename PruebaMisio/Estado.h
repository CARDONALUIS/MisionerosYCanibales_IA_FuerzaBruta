#pragma once
#include <stdio.h>
#include <string.h>
#include <vector>

class Estado
{
public:
	int mI = 3;
	int cI = 3;
	int mD = 0;
	int cD = 0;
	bool bandIda = true;

	void aplicaRegla();
	bool esValido();
	bool esTerminal();
};

