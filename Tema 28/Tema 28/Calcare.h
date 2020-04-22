#pragma once
#include "Masina.h"
#include "Haina.h"
#include "Subclase_Haina.h"
#include "Costum.h"

class Calcare :
	public Masina
{
private:
	int durata_calcare = 0;
public:
	Calcare();
	~Calcare();

	void Determinare_durata(Haina& h);
	void Determinare_durata(Costum& h);
	bool AdaugaHaina(Haina* h, int sec);
	void PornireProgram(int sec);
	void ResetareValori();
	bool TerminareProgram(int sec);
};

