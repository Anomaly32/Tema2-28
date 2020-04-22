#include "Spalare.h"

int Spalare::durata_functionare = 120;

Spalare::Spalare()
{
	capacitate = 100;
}

Spalare::~Spalare()
{
	capacitate = 0;
}

int Spalare::GetCantitateDetergent()
{
	return cantitate_detergent;
}

void Spalare::Adauga_detergent(Haina& h)
{
	string tip_articol = h.GetType();
	if (tip_articol == "Pantaloni")
	{
		if (h.GetTipCuloare() == "inchisa")
		{
			cantitate_detergent += 2 * Pantaloni::cantitate_detergent;
		}
		else
		{
			cantitate_detergent += Pantaloni::cantitate_detergent;
		}
		greutate_actuala += h.GetGreutate();
		h.AdaugaInformatiiTraseu("Spalare");
	}
	else if (tip_articol == "Camasa")
	{
		cantitate_detergent += Camasa::cantitate_detergent;
		greutate_actuala += h.GetGreutate();
		h.AdaugaInformatiiTraseu("Spalare");
	}
	else if (tip_articol == "Rochie")
	{
		cantitate_detergent += Rochie::cantitate_detergent;
		greutate_actuala += h.GetGreutate();
		h.AdaugaInformatiiTraseu("Spalare");
	}
	else
	{
		cout << "TIP NECUNOSCUT, POSIBIL TIP DE BAZA" << endl;
	}
}

//void Spalare::Adauga_detergent(Costum& h)
//{
//	if (h.GetTipCuloare() == "inchisa")
//	{
//		cantitate_detergent += 2 * Pantaloni::cantitate_detergent;
//	}
//	else
//	{
//		cantitate_detergent += Pantaloni::cantitate_detergent;
//	}
//	cantitate_detergent += 100 * h.GetGreutateSacou();
//	greutate_actuala += h.GetGreutate();
//}

bool Spalare::AdaugaHaina(Haina* h, int sec)
{
	if (greutate_actuala + h->GetGreutate() < capacitate)
	{
		if (nr_haine == 0)
		{
			conditie_temp = h->GetConditieTemperatura();
			culoare_spalare = h->GetTipCuloare();
		}
		if (conditie_temp == "sub")
		{
			if (h->GetTemperaturaSpalare() < temperatura)
			{
				temperatura = h->GetTemperaturaSpalare();
			}
		}
		else
		{
			if (h->GetTemperaturaSpalare() > temperatura)
			{
				temperatura = h->GetTemperaturaSpalare();
			}
		}
		Adauga_detergent(*h);
		haine[nr_haine] = h;
		nr_haine++;
		PornireProgram(sec);
		return true;
	}
	return false;
}

bool Spalare::TerminareProgram(int sec)
{
	if (functioneaza == true && sec == Spalare::durata_functionare + timp_pornire)
	{
		greutate_actuala = 0;
		functioneaza = false;
		return true;
	}
	return false;
}

void Spalare::ResetareValori()
{
	cantitate_detergent = 0;
	conditie_temp = "";
	temperatura = 0;
	culoare_spalare = "";
	spalare_costume = false;
	Masina::ResetareValori();
}