#pragma once
#include "Masina.h"
class Stoarcere :
	public Masina
{
public:
	static int durata_functionare;
	Stoarcere();
	~Stoarcere();
	bool AdaugaHaina(Haina* h, int sec);
	bool TerminareProgram(int sec);
	void ResetareValori();
};

