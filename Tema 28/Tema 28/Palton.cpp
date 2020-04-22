#include "Palton.h"

Palton::Palton(int g, string ct, int ts, string c, string tc, string cg)
	: Haina(g, ct, ts, c, tc, cg)
{
	procese_permise[0] = false;
	procese_permise[1] = true;
	procese_permise[2] = false;
	procese_permise[3] = true;
	procese_permise[4] = false;
}

Palton::Palton(const Palton& p)
	: Haina(p)
{
	for (int i = 0; i < numar_procese; i++)
	{
		procese_permise[i] = p.procese_permise[i];
	}
}

Palton::~Palton(){}

Palton& Palton::operator=(const Palton& h)
{
	if (this == &h)
	{
		return *this;
	}
	Haina::operator=(h);
	return *this;
}

string Palton::GetType()
{
	return string("Palton");
}