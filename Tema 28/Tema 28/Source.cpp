#include <iostream>
#include <string>
#include "Haina.h"
#include "Masina.h"
#include "Subclase_Haina.h"
#include "Subclase_Masina.h"
#include "Costum.h"

using namespace std;

const int nr_procese = 5;

const int nr_masini_spalare = 10;
const int nr_masini_spalare_speciala = 4;
const int nr_masini_stoarcere = 10;
const int nr_masini_uscare = 10;
const int nr_masini_calcare = 10;

const int nr_masini[nr_procese] = { nr_masini_spalare,
									nr_masini_spalare_speciala,
									nr_masini_stoarcere,
									nr_masini_uscare,
									nr_masini_calcare };

void PrimireHaineClient(int index, int& nr_haine, Haina** &haine)
{
	cout << "Clientul cu numarul de ordine " << index + 1 << " ar dori sa trimita catre procesul tehnologic urmatorul numar de haine: ";
	cin >> nr_haine;
	haine = new Haina*[nr_haine];
	cout << "Dintre care: ";
	int nr_articole = 0;
	string tip_articol;
	for (int i = 0; i != nr_haine;)
	{
		cin >> nr_articole >> tip_articol;
		if (tip_articol == "Pantaloni")
		{
			for (int j = 0; j < nr_articole; j++)
			{
				try 
				{
					Pantaloni* h = new Pantaloni();
					h->SetInfo();
					h->SetIndexClient(index);
					haine[i] = h;
					i++;
				}
				catch (bad_alloc&) 
				{
					cout << "Out of memory!";
					cin.get();
					exit(1);
				}
			}
		}
		else if (tip_articol == "Camasa")
		{
			for (int j = 0; j < nr_articole; j++)
			{
				try
				{
					Camasa* h = new Camasa();
					h->SetInfo();
					h->SetIndexClient(index);
					haine[i] = h;
					i++;
				}
				catch (bad_alloc&)
				{
					cout << "Out of memory!";
					cin.get();
					exit(1);
				}
			}
		}
		else if (tip_articol == "Rochie")
		{
			for (int j = 0; j < nr_articole; j++)
			{
				try
				{
					Rochie* h = new Rochie();
					h->SetInfo();
					h->SetIndexClient(index);
					haine[i] = h;
					i++;
				}
				catch (bad_alloc&)
				{
					cout << "Out of memory!";
					cin.get();
					exit(1);
				}
			}
		}
		else if (tip_articol == "Palton")
		{
			for (int j = 0; j < nr_articole; j++)
			{
				try
				{
					Palton* h = new Palton();
					h->SetInfo();
					h->SetIndexClient(index);
					haine[i] = h;
					i++;
				}
				catch (bad_alloc&)
				{
					cout << "Out of memory!";
					cin.get();
					exit(1);
				}
			}
		}
		else if (tip_articol == "Geaca")
		{
			for (int j = 0; j < nr_articole; j++)
			{
				try
				{
					Geaca* h = new Geaca();
					h->SetInfo();
					h->SetIndexClient(index);
					haine[i] = h;
					i++;
				}
				catch (bad_alloc&)
				{
					cout << "Out of memory!";
					cin.get();
					exit(1);
				}
			}
		}
		else if (tip_articol == "Costum")
		{
			
		}
	}
}

void PrimireHaine(int& nr_clienti, int* &nr_haine_clienti, Haina*** &haine_clienti)
{
	cout << "nr_clienti: ";
	cin >> nr_clienti;
	nr_haine_clienti = new int[nr_clienti];
	haine_clienti = new Haina * *[nr_clienti];
	for (int i = 0; i < nr_clienti; i++)
	{
		PrimireHaineClient(i, nr_haine_clienti[i], haine_clienti[i]);
	}
}

void PrintHaine(int nr_clienti, int* nr_haine_clienti, Haina*** haine_clienti)
{
	for (int i = 0; i < nr_clienti; i++)
	{
		for (int j = 0; j < nr_haine_clienti[i]; j++)
		{
			cout << haine_clienti[i][j]->GetType() << ": ";
			haine_clienti[i][j]->PrintTraseu();
			cout << haine_clienti[i][j]->GetIndexProces() << endl;
		}
	}
}

void EliberareHaine(int nr_clienti, int* nr_haine_clienti, Haina*** &haine_clienti)
{
	for (int i = 0; i < nr_clienti; i++)
	{
		for (int j = 0; j < nr_haine_clienti[i]; j++)
		{
			delete haine_clienti[i][j];
		}
	}
}

void AdaugaHaineInMasini(int& nr_masini_active, int& nr_haine, Haina** in_asteptare, Masina** masini, int nr_masini, int index_proces, int sec)
{
	for (int i = 0; i < nr_masini; i++)
	{
		for (int j = 0; j < nr_haine; j++)
		{
			if (!masini[i]->AInceput() && masini[i]->AdaugaHaina(in_asteptare[j], sec))
			{
				in_asteptare[j]->SetIndexProces(index_proces);
				in_asteptare[j] = NULL;
			}
		}
		int aux = 0;
		for (int j = 0; j < nr_haine; j++)
		{
			if (in_asteptare[j] != NULL)
			{
				in_asteptare[aux] = in_asteptare[j];
				if (aux != j)
					in_asteptare[j] = NULL;
				aux++;
			}
		}
		nr_haine = aux;
		if (masini[i]->GetNrHaine() != 0)
		{
			nr_masini_active++;
			masini[i]->SetIncepereProgram(sec);
		}
	}
}

void AdaugaHaineInAsteptare(int* nr_haine, Haina*** in_asteptare, Haina** &haine, int nr_haine_de_adaugat)
{
	for (int i = 0; i < nr_haine_de_adaugat; i++)
	{
		int ind_proc = haine[i]->GetIndexProces();
		in_asteptare[ind_proc][nr_haine[ind_proc]] = haine[i];
		nr_haine[ind_proc]++;
	}
}

void ScoatereHaineDinMasini(int& masini_active, int* nr_haine, Haina*** in_asteptare, Masina*** masini, int index_proces, int sec)
{
	for (int i = 0; i < nr_masini[index_proces]; i++)
	{
		if (masini[index_proces][i]->TerminareProgram(sec))
		{
			int nr_haine_de_adaugat = masini[index_proces][i]->GetNrHaine();
			Haina** haine = new Haina*[nr_haine_de_adaugat];
			Haina** prop = masini[index_proces][i]->GetHaine();
			for (int i = 0; i < nr_haine_de_adaugat; i++)
			{
				haine[i] = prop[i];
			}
			masini[index_proces][i]->EliminaHaine();
			masini_active--;
			for (int i = 0; i < nr_haine_de_adaugat; i++)
			{
				if (haine[i]->AvansareProces())
				{
					haine[i] = NULL;
				}
			}
			int aux = 0;
			for (int i = 0; i < nr_haine_de_adaugat; i++)
			{
				if (haine[i] != NULL)
				{
					haine[aux] = haine[i];
					if(aux != i)
						haine[i] = NULL;
					aux++;
				}
			}
			nr_haine_de_adaugat = aux;
			AdaugaHaineInAsteptare(nr_haine, in_asteptare, haine, nr_haine_de_adaugat);
		}
	}
}

void SetMemorieMasini(Masina*** &masini)
{
	masini = new Masina * *[nr_procese];

	masini[0] = new Masina * [nr_masini_spalare];
	for (int i = 0; i < nr_masini_spalare; i++)
	{
		masini[0][i] = new Spalare();
	}

	masini[1] = new Masina * [nr_masini_spalare_speciala];
	for (int i = 0; i < nr_masini_spalare_speciala; i++)
	{
		masini[1][i] = new Spalare_speciala();
	}

	masini[2] = new Masina * [nr_masini_stoarcere];
	for (int i = 0; i < nr_masini_stoarcere; i++)
	{
		masini[2][i] = new Stoarcere();
	}

	masini[3] = new Masina * [nr_masini_uscare];
	for (int i = 0; i < nr_masini_uscare; i++)
	{
		masini[3][i] = new Uscare();
	}

	masini[4] = new Masina * [nr_masini_calcare];
	for (int i = 0; i < nr_masini_calcare; i++)
	{
		masini[4][i] = new Calcare();
	}
}

void DeleteMemorieMasini(Masina*** &masini)
{
	for (int i = 0; i < nr_masini_spalare; i++)
	{
		delete masini[0][i];
	}
	delete[] masini[0];

	for (int i = 0; i < nr_masini_spalare_speciala; i++)
	{
		delete masini[1][i];
	}
	delete[] masini[1];

	for (int i = 0; i < nr_masini_stoarcere; i++)
	{
		delete masini[2][i];
	}
	delete[] masini[2];

	for (int i = 0; i < nr_masini_spalare; i++)
	{
		delete masini[3][i];
	}
	delete[] masini[3];

	for (int i = 0; i < nr_masini_spalare; i++)
	{
		delete masini[4][i];
	}
	delete[] masini[4];

	delete[] masini;
}

void ProcesTehnologic(int nr_clienti, int* nr_haine_clienti, Haina*** haine_clienti)
{
	Masina*** masini = NULL;
	SetMemorieMasini(masini);

	Haina*** in_asteptare = new Haina * *[nr_procese];
	for (int i = 0; i < nr_procese; i++)
	{
		in_asteptare[i] = new Haina * [500];
	}

	/*
	index:
	0 - Spalare
	1 - Spalare Speciala
	2 - Stoarcere
	3 - Uscare
	4 - Calcare
	5 - Terminare
	*/

	int index_asteptare[5] = { 0 };

	for (int i = 0; i < nr_clienti; i++)
	{
		for (int j = 0; j < nr_haine_clienti[i]; j++)
		{
			string type = haine_clienti[i][j]->GetType();
			if (type == "Geaca" || type == "Costum" || type == "Palton")
			{
				in_asteptare[1][index_asteptare[1]] = haine_clienti[i][j];
				index_asteptare[1]++;
			}
			else
			{
				in_asteptare[0][index_asteptare[0]] = haine_clienti[i][j];
				index_asteptare[0]++;
			}
		}
	}
	int masini_active = 0, secunde = 0;

	// PROCESUL TEHNOLOGIC --> //
	do
	{
		for (int i = 0; i < nr_procese; i++)
		{
			ScoatereHaineDinMasini(masini_active, index_asteptare, in_asteptare, masini, i, secunde);
		}
		for (int i = 0; i < nr_procese; i++)
		{
			if(index_asteptare[i] > 0)
				AdaugaHaineInMasini(masini_active, index_asteptare[i], in_asteptare[i], masini[i], nr_masini[i], i, secunde);
		}
		secunde++;
	} while (masini_active != 0);
	// --> PROCESUL TEHNOLOGIC//

	for (int i = 0; i < nr_procese; i++)
	{
		delete[] in_asteptare[i];
	}
	delete[] in_asteptare;

	DeleteMemorieMasini(masini);
}

void EliberareMemorie(int n, int* nr_haine, Haina*** &haine)
{
	for (int i = 0; i < n; i++)
	{
		delete[] haine[i];
	}
	delete[] haine;

	delete[] nr_haine;
}

int main()
{
	Haina*** haine_clienti = NULL;
	int* nr_haine_clienti = NULL;
	int nr_clienti = 0;

	PrimireHaine(nr_clienti, nr_haine_clienti, haine_clienti);
	ProcesTehnologic(nr_clienti, nr_haine_clienti, haine_clienti);
	PrintHaine(nr_clienti, nr_haine_clienti, haine_clienti);

	EliberareHaine(nr_clienti, nr_haine_clienti, haine_clienti);
	EliberareMemorie(nr_clienti, nr_haine_clienti, haine_clienti);

	return 0;
}