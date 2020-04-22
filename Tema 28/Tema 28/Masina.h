#pragma once

#include <iostream>
#include "Subclase_Haina.h"
#include "Haina.h"
#include "Costum.h"

using namespace std;

class Masina
{
protected:
	int greutate_actuala = 0;
	int timp_pornire = 0;
	int capacitate = 0;
	int nr_haine = 0;
	Haina* haine[100] = {};
	bool functioneaza = false;
public:
	Masina();
	virtual ~Masina();
	void SetNrHaine(int n = 0);
	int GetNrHaine();
	void PrintHaine();
	Haina** GetHaine();
	virtual bool AdaugaHaina(Haina* h, int sec);
	bool AInceput();
	virtual void ResetareValori();
	void SetIncepereProgram(int sec);
	virtual void PornireProgram(int sec);
	virtual bool TerminareProgram(int sec) = 0;
	void EliminaHaine();
};

