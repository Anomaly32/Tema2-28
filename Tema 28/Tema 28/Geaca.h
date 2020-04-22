#pragma once
#include "Haina.h"

class Geaca 
	: public Haina 
{
public:
	Geaca(int g = 0, string ct = "", int ts = 0, string c = "", string tc = "", string cg = "grea");
	Geaca(const Geaca& p);
	~Geaca();

	Geaca& operator=(const Geaca& h);
	string GetType();
};

