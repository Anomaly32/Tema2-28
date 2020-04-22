#include "Haina.h"

Haina::Haina(int g, string ct, int ts, string c, string tc, string cg)
	: greutate(g), conditie_temp(ct), temp_spalare(ts), culoare(c), tip_culoare(tc), categorie_greutate(cg) {}

Haina::Haina(const Haina& h)
{
	greutate = h.greutate;
	conditie_temp = h.conditie_temp;
	temp_spalare = h.temp_spalare;
	culoare = h.culoare;
	tip_culoare = h.tip_culoare;
	categorie_greutate = h.categorie_greutate;
}

Haina::~Haina()
{
	greutate = 0;
	conditie_temp = "";
	temp_spalare = 0;
	culoare = "";
	tip_culoare = "";
	categorie_greutate = "";
	traseu = "";
	index_client = -1;
}

Haina& Haina::operator=(const Haina& h)
{
	if (this == &h)
	{
		return *this;
	}
	greutate = h.greutate;
	conditie_temp = h.conditie_temp;
	temp_spalare = h.temp_spalare;
	culoare = h.culoare;
	tip_culoare = h.tip_culoare;
	categorie_greutate = h.categorie_greutate;
	return *this;
}

istream& operator>>(istream& in, Haina& h)
{
	cout << endl << "greutate = ";
	in >> h.greutate;
	cout << "temperatura de spalare (sub / peste) = ";
	in >> h.conditie_temp >> h.temp_spalare;
	cout << "culoare = ";
	in >> h.culoare;
	cout << "tip culoare (deschisa / inchisa) = ";
	in >> h.tip_culoare;
	cout << "categorie greutate (usoara / grea) = ";
	in >> h.categorie_greutate;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Haina h)
{
	out << "greutate = " << h.greutate << " kg\n";
	out << "temperatura de spalare = " << h.conditie_temp << " " <<  h.temp_spalare << " grade\n";
	out << "culoare = " << h.culoare << endl;
	out << "tip culoare = " << h.tip_culoare << endl;
	out << "categorie greutate = " << h.categorie_greutate << endl << endl;
	return out;
}

int Haina::GetGreutate()
{
	return greutate;
}

string Haina::GetCategorieGreutate()
{
	return categorie_greutate;
}

string Haina::GetTipCuloare()
{
	return tip_culoare;
}

string Haina::GetConditieTemperatura()
{
	return conditie_temp;
}

int Haina::GetTemperaturaSpalare()
{
	return temp_spalare;
}

int Haina::GetIndexClient()
{
	return index_client;
}

int Haina::GetIndexProces()
{
	return index_proces;
}

bool Haina::GetCompatibilitateProces(int proces)
{
	return procese_permise[proces];
}

void Haina::SetGreutate(int g)
{
	greutate = g;
}

void Haina::SetIndexProces(int x)
{
	index_proces = x;
}

void Haina::SetInfo()
{
	cout << "greutate = ";
	cin >> greutate;
	cout << "temperatura de spalare = ";
	cin >> conditie_temp >> temp_spalare;
	cout << "culoare = ";
	cin >> culoare;
	cout << "tip culoare = ";
	cin >> tip_culoare;
	cout << "categorie greutate (usoara / grea) = ";
	cin >> categorie_greutate;
	cout << endl;
}

void Haina::PrintInfo()
{
	cout << "Informatii:" << endl;
	cout << "greutate = " << greutate << " kg\n";
	cout << "temperatura de spalare = " << conditie_temp << " " << temp_spalare << " grade\n";
	cout << "culoare = " << culoare << endl;
	cout << "tip culoare = " << tip_culoare << endl;
	cout << "categorie greutate = " << categorie_greutate << endl << endl;
}

void Haina::SetIndexClient(int x)
{
	index_client = x;
}

bool Haina::AvansareProces()
{
	index_proces++;
	while (!procese_permise[index_proces] && index_proces != 5)
	{
		index_proces++;
	}
	if (index_proces == 5)
	{
		terminata = true;
		return true;
	}
	return false;
}

void Haina::AdaugaInformatiiTraseu(string info)
{
	traseu += " --> " + info;
}

void Haina::PrintTraseu()
{
	cout << traseu << endl;
}

string Haina::GetType()
{
	return string("Haina");
}