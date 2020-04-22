#include "Camasa.h"

int Camasa::cantitate_detergent = 67;

Camasa::Camasa(int g, string ct, int ts, string c, string tc, string cg)
	: Haina(g, ct, ts, c, tc, cg) 
{
	procese_permise[0] = true;
	procese_permise[1] = false;
	procese_permise[2] = true;
	procese_permise[3] = true;
	procese_permise[4] = true;
}

Camasa::Camasa(const Camasa& p)
	: Haina(p) 
{
	for (int i = 0; i < numar_procese; i++)
	{
		procese_permise[i] = p.procese_permise[i];
	}
}

Camasa::~Camasa(){}

Camasa& Camasa::operator=(const Camasa& h)
{
	if (this == &h)
	{
		return *this;
	}
	Haina::operator=(h);
	return *this;
}

string Camasa::GetType()
{
	return string("Camasa");
}

ostream& operator<<(ostream& out, const Camasa h)
{
	out << "Informatii camasa:\n";
	out << (Haina)h << endl;
	return out;
}