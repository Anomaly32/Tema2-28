#pragma once
#include "Haina.h"
#include <iostream>

using namespace std;

class Rochie :
	public Haina
{
public:
	static int cantitate_detergent;

	Rochie(int g = 0, string ct = "", int ts = 0, string c = "", string tc = "", string cg = "usoara");
	Rochie(const Rochie& p);
	~Rochie();

	Rochie& operator=(const Rochie& h);
	string GetType();
};

