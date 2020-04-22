#include "Masina.h"

Masina::Masina() {}

Masina::~Masina() {}

void Masina::SetNrHaine(int n)
{
	nr_haine = n;
}

int Masina::GetNrHaine()
{
	return nr_haine;
}

Haina** Masina::GetHaine()
{
	return haine;
}

void Masina::PrintHaine()
{
	for (int i = 0; i < nr_haine; i++)
	{
		cout << *haine[i] << endl;
	}
}

bool Masina::AdaugaHaina(Haina* h, int sec)
{
	if(greutate_actuala + h->GetGreutate() < capacitate)
	{
		haine[nr_haine] = h;
		nr_haine++;
		PornireProgram(sec);
		return true;
	}
	return false;
}

bool Masina::AInceput()
{
	return functioneaza;
}

void Masina::PornireProgram(int sec)
{
	if (greutate_actuala > capacitate / 2)
	{
		SetIncepereProgram(sec);
	}
}

void Masina::SetIncepereProgram(int sec)
{
	if (functioneaza == false)
	{
		timp_pornire = sec;
		functioneaza = true;
	}
}

void Masina::EliminaHaine()
{
	for (int i = 0; i < nr_haine; i++)
	{
		haine[i] = NULL;
	}
	nr_haine = 0;
}

void Masina::ResetareValori()
{
	greutate_actuala = 0;
	timp_pornire = 0;
	nr_haine = 0;
	for (int i = 0; i < 100; i++)
	{
		haine[i] = NULL;
	}
	functioneaza = false;
}