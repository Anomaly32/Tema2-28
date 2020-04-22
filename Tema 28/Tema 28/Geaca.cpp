#include "Geaca.h"

Geaca::Geaca(int g, string ct, int ts, string c, string tc, string cg)
	: Haina(g, ct, ts, c, tc, cg)
{
	procese_permise[0] = false;
	procese_permise[1] = true;
	procese_permise[2] = false;
	procese_permise[3] = true;
	procese_permise[4] = false;
}

Geaca::Geaca(const Geaca& p)
	: Haina(p)
{
	for (int i = 0; i < numar_procese; i++)
	{
		procese_permise[i] = p.procese_permise[i];
	}
}

Geaca::~Geaca() {}

Geaca& Geaca::operator=(const Geaca& h)
{
	if (this == &h)
	{
		return *this;
	}
	Haina::operator=(h);
	return *this;
}

string Geaca::GetType()
{
	return string("Geaca");
}