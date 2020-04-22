#include "Pantaloni.h"

int Pantaloni::cantitate_detergent = 50;

Pantaloni::Pantaloni(int g, string ct, int ts, string c, string tc, string cg)
	: Haina(g, ct, ts, c, tc, cg)
{
	procese_permise[0] = true;
	procese_permise[1] = false;
	procese_permise[2] = true;
	procese_permise[3] = true;
	procese_permise[4] = true;
}

Pantaloni::Pantaloni(const Pantaloni& p)
	: Haina(p)
{
	for (int i = 0; i < numar_procese; i++)
	{
		procese_permise[i] = p.procese_permise[i];
	}
}

Pantaloni::~Pantaloni() {}

Pantaloni& Pantaloni::operator=(const Pantaloni& h)
{
	if (this == &h)
	{
		return *this;
	}
	Haina::operator=(h);
	return *this;
}

string Pantaloni::GetType()
{
	return string("Pantaloni");
}