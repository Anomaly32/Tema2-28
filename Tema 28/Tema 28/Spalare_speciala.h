#pragma once
#include "Spalare.h"
class Spalare_speciala :
	public Spalare
{
public:
	Spalare_speciala();
	~Spalare_speciala();
	void Adauga_detergent(Haina& h);
	/*void Adauga_detergent(Geaca& h);
	void Adauga_detergent(Palton& h);*/
};

