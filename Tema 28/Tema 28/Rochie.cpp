#include "Rochie.h"

int Rochie::cantitate_detergent = 75;

Rochie::Rochie(int g, string ct, int ts, string c, string tc, string cg)
	: Haina(g, ct, ts, c, tc, cg)
{
	procese_permise[0] = true;
	procese_permise[1] = false;
	procese_permise[2] = true;
	procese_permise[3] = true;
	procese_permise[4] = false;
}

Rochie::Rochie(const Rochie& p)
	: Haina(p)
{
	for (int i = 0; i < numar_procese; i++)
	{
		procese_permise[i] = p.procese_permise[i];
	}
}
Rochie::~Rochie() {}

Rochie& Rochie::operator=(const Rochie& h)
{
	if (this == &h)
	{
		return *this;
	}
	Haina::operator=(h);
	return *this;
}

string Rochie::GetType()
{
	return string("Rochie");
}