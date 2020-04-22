#pragma once

#include "Haina.h"
#include <iostream>

using namespace std;

class Pantaloni :
	public Haina
{
public:
	static int cantitate_detergent;

	Pantaloni(int g = 0, string ct = "", int ts = 0, string c = "", string tc = "", string cg = "usoara");
	Pantaloni(const Pantaloni& p);
	~Pantaloni();
	Pantaloni& operator=(const Pantaloni& h);
	string GetType();
};

