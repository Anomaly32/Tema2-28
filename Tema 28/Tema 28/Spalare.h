#pragma once
#include "Masina.h"
#include "Haina.h"
#include "Subclase_Haina.h"
#include "Costum.h"

class Spalare :
	public Masina
{
protected:
	int cantitate_detergent = 0;
	string conditie_temp = "";
	int temperatura = 0;
	string culoare_spalare = "";
	bool spalare_costume = false;
public: 
	Spalare();
	virtual ~Spalare();

	static int durata_functionare;
	int GetCantitateDetergent();
	virtual void Adauga_detergent(Haina& h);
	void ResetareValori();
	//void Adauga_detergent(Costum& h);
	bool AdaugaHaina(Haina* h, int sec);
	bool TerminareProgram(int sec);
	// setare tip de culoare in masina? sau in main?
};

