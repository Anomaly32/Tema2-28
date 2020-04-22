#pragma once
#include "Masina.h"
class Uscare :
	public Masina
{
public:
	static int durata_functionare;
	Uscare();
	~Uscare();
	bool AdaugaHaina(Haina* h, int sec);
	bool TerminareProgram(int sec);
	void ResetareValori();
};

