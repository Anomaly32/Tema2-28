#include "Sacou.h"

Sacou::Sacou(int g, string ct, int ts, string c, string tc, string cg)
	: Haina(g, ct, ts, c, tc, cg)
{
	procese_permise[0] = false;
	procese_permise[1] = true;
	procese_permise[2] = false;
	procese_permise[3] = true;
	procese_permise[4] = true;
}

Sacou::Sacou(const Sacou& p)
	: Haina(p)
{
	for (int i = 0; i < numar_procese; i++)
	{
		procese_permise[i] = p.procese_permise[i];
	}
}

Sacou::~Sacou() {}

Sacou& Sacou::operator=(const Sacou& h)
{
	if (this == &h)
	{
		return *this;
	}
	Haina::operator=(h);
	return *this;
}

string Sacou::GetType()
{
	return string("Sacou");
}