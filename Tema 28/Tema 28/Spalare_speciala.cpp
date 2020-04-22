#include "Spalare_speciala.h"

Spalare_speciala::Spalare_speciala()
{
	capacitate = 200;
}

Spalare_speciala::~Spalare_speciala()
{
	capacitate = 0;
}

void Spalare_speciala::Adauga_detergent(Haina& h)
{
	string tip_articol = h.GetType();
	if (tip_articol == "Geaca")
	{
		cantitate_detergent += 100 * h.GetGreutate();
		greutate_actuala += h.GetGreutate();
		h.AdaugaInformatiiTraseu("Spalare_speciala");
	}
	if (tip_articol == "Palton")
	{
		cantitate_detergent += 100 * h.GetGreutate();
		greutate_actuala += h.GetGreutate();
		h.AdaugaInformatiiTraseu("Spalare_speciala");
	}
}

//void Spalare_speciala::Adauga_detergent(Geaca& h)
//{
//	cantitate_detergent += 100 * h.GetGreutate();
//	greutate_actuala += h.GetGreutate();
//	h.AdaugaInformatiiTraseu("Spalare_speciala");
//}
//
//void Spalare_speciala::Adauga_detergent(Palton& h)
//{
//	cantitate_detergent += 100 * h.GetGreutate();
//	greutate_actuala += h.GetGreutate();
//	h.AdaugaInformatiiTraseu("Spalare_speciala");
//}