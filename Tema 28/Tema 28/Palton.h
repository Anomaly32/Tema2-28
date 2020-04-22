#pragma once
#include "Haina.h"
class Palton 
	: public Haina {
public:
	Palton(int g = 0, string ct = "", int ts = 0, string c = "", string tc = "", string cg = "grea");
	Palton(const Palton& p);
	~Palton();

	Palton& operator=(const Palton& h);
	string GetType();
};

