#include "Stoarcere.h"

int Stoarcere::durata_functionare = 40;

Stoarcere::Stoarcere()
{
	capacitate = 120;
}

Stoarcere::~Stoarcere()
{
	capacitate = 0;
}

bool Stoarcere::AdaugaHaina(Haina* h, int sec)
{
	if (greutate_actuala + h->GetGreutate() < capacitate)
	{
		haine[nr_haine] = h;
		h->AdaugaInformatiiTraseu("Stoarcere");
		nr_haine++;
		PornireProgram(sec);
		return true;
	}
	return false;
}

bool Stoarcere::TerminareProgram(int sec)
{
	if (functioneaza == true && sec == Stoarcere::durata_functionare + timp_pornire)
	{
		functioneaza = false;
		return true;
	}
	return false;
}

void ResetareValori()
{

}