#include "Costum.h"

Costum::Costum(int g_sacou, string ct_sacou, int ts_sacou, string c_sacou, string tc_sacou, string cg_sacou,
	int g_pantaloni, string ct_pantaloni, int ts_pantaloni, string c_pantaloni, string tc_pantaloni, string cg_pantaloni)
	: sacou(Sacou(g_sacou, ct_sacou, ts_sacou, c_sacou, tc_sacou, cg_sacou)),
	  pantaloni(Pantaloni(g_pantaloni, ct_pantaloni, ts_pantaloni, c_pantaloni, tc_pantaloni, cg_pantaloni))
{}

Costum::Costum(const Costum& p)
	: sacou(Sacou(p.sacou)), pantaloni(Pantaloni(p.pantaloni))
{}

Costum& Costum::operator=(const Costum& h)
{
	if (this == &h)
	{
		return *this;
	}
	sacou.operator=(h.sacou);
	pantaloni.operator=(h.pantaloni);
	return *this;
}

istream& operator>>(istream& in, Costum& h)
{
	cout << "Sacou:\n";
	in >> h.sacou;
	cout << "Pantaloni:\n";
	in >> h.pantaloni;
	return in;
}

ostream& operator<<(ostream& out, const Costum h)
{
	out << "\nCostum:\n";
	out << "Sacou:\n";
	out << h.sacou;
	out << "\nPantaloni:\n";
	out << h.pantaloni << endl;
	return out;
}

int Costum::GetGreutate()
{
	return sacou.GetGreutate() + pantaloni.GetGreutate();
}

int Costum::GetGreutateSacou()
{
	return sacou.GetGreutate();
}

int Costum::GetGreutatePantaloni()
{
	return pantaloni.GetGreutate();
}

string Costum::GetTipCuloare()
{
	return pantaloni.GetTipCuloare();
}

bool Costum::GetCompatibilitateProces(int proces)
{
	return sacou.GetCompatibilitateProces(proces);
}

string Costum::GetConditieTemperatura()
{
	return pantaloni.GetConditieTemperatura();
}

int Costum::GetTemperaturaSpalare()
{
	return pantaloni.GetTemperaturaSpalare();
}

int Costum::GetIndexClient()
{
	return pantaloni.GetIndexClient();
}

void Costum::SetIndexClient(int x)
{
	pantaloni.SetIndexClient(x);
}

void Costum::SetGreutate(int g_sacou, int g_pantaloni)
{
	sacou.SetGreutate(g_sacou);
	pantaloni.SetGreutate(g_pantaloni);
}

void Costum::SetInfo()
{
	cout << "Costum:\n1) Sacou:\n";
	cin >> sacou;
	cout << "2) Pantaloni:\n";
	cin >> pantaloni;
}

void Costum::PrintInfo()
{
	cout << "Informatii:" << endl;
	cout << "Costum:\n1) Sacou:\n";
	cout << sacou << endl;
	cout << "2) Pantaloni:\n";
	cout << pantaloni << endl;
}

void Costum::AdaugaInformatiiTraseu(string info)
{
	sacou.AdaugaInformatiiTraseu(info);
	pantaloni.AdaugaInformatiiTraseu(info);
}

void Costum::PrintTraseu()
{
	sacou.PrintTraseu();
}

string Costum::GetType()
{
	return string("Costum");
}