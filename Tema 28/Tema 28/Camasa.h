#pragma once
#include "Haina.h"
#include <iostream>

using namespace std;

class Camasa :
	public Haina
{
public:
	static int cantitate_detergent;
	
	Camasa(int g = 0, string ct = "", int ts = 0, string c = "", string tc = "", string cg = "usoara");
	Camasa(const Camasa& p);
	~Camasa();
	Camasa& operator=(const Camasa& h);
	friend ostream& operator<<(ostream& out, const Camasa h);
	string GetType();
};

