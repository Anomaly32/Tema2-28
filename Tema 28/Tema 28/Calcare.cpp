#include "Calcare.h"

Calcare::Calcare()
{
	capacitate = 1;
}

Calcare::~Calcare()
{
	capacitate = 0;
}

void Calcare::Determinare_durata(Haina& h)
{
	if (h.GetType() == string("Camasa"))
	{
		Calcare::durata_calcare = 120 * h.GetGreutate();
	}
	else if (h.GetType() == string("Pantaloni"))
	{
		Calcare::durata_calcare = 90 * h.GetGreutate();
	}
	else 
	{
		cout << "TIP DE HAINA NECUNOSCUT, POSIBIL TIP DE BAZA" << endl;
	}
}

void Calcare::Determinare_durata(Costum& h)
{
	Calcare::durata_calcare = 150 * h.GetGreutateSacou() + 90 * h.GetGreutatePantaloni();
}

bool Calcare::AdaugaHaina(Haina* h, int sec)
{
	haine[nr_haine] = h;
	nr_haine++;
	Determinare_durata(*h);
	h->AdaugaInformatiiTraseu("Calcare");
	PornireProgram(sec);
	functioneaza = true;
	return true;
}

void Calcare::PornireProgram(int sec)
{
	if (nr_haine == capacitate)
	{
		SetIncepereProgram(sec);
	}
}

bool Calcare::TerminareProgram(int sec)
{
	if (functioneaza == true && sec == Calcare::durata_calcare + timp_pornire)
	{
		functioneaza = false;
		return true;
	}
	return false;
}

void Calcare::ResetareValori()
{
	durata_calcare = 0;
	Masina::ResetareValori();
}