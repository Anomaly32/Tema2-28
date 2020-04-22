#pragma once
#include "Haina.h"
#include <iostream>

using namespace std;

class Sacou :
	public Haina
{
public:
	Sacou(int g = 0, string ct = "", int ts = 0, string c = "", string tc = "", string cg = "grea");
	Sacou(const Sacou& p);
	~Sacou();

	Sacou& operator=(const Sacou& h);
	string GetType();
};
