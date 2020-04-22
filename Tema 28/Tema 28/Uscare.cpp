#include "Uscare.h"

int Uscare::durata_functionare = 30;

Uscare::Uscare()
{
	capacitate = 30;
}

Uscare::~Uscare()
{
	capacitate = 0;
}

bool Uscare::AdaugaHaina(Haina* h, int sec)
{
	if (nr_haine + 1 < capacitate)
	{
		haine[nr_haine] = h;
		h->AdaugaInformatiiTraseu("Uscare");
		nr_haine++;
		PornireProgram(sec);
		return true;
	}
	return false;
}

bool Uscare::TerminareProgram(int sec)
{
	if (functioneaza == true && sec == Uscare::durata_functionare + timp_pornire)
	{
		functioneaza = false;
		return true;
	}
	return false;
}

void Uscare::ResetareValori()
{
	Masina::ResetareValori();
}