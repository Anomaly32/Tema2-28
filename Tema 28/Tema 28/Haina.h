#pragma once

#include <iostream>

using namespace std;

class Haina 
{
protected:
	int greutate = 0;
	string conditie_temp = "";
	int temp_spalare = 0;
	string culoare = "";
	string tip_culoare = "";
	string categorie_greutate = "";

	string traseu = "";
	int index_client = -1;
	int index_proces = -1;
	const int numar_procese = 5;
	bool procese_permise[5] = { false, false, false, false, false };
	bool terminata = false;
public:
	//Constructori: de copiere, de initializare cu numar variabil de argumente
	Haina(int g = 0, string ct = "", int ts = 0, string c = "", string tc = "", string cg = "");
	Haina(const Haina& h);
	virtual ~Haina();

	//Operatori
	Haina& operator=(const Haina& h);
	friend istream& operator>>(istream& in, Haina& h);
	friend ostream& operator<<(ostream& out, const Haina h);

	//Gettere, Settere, functie de printare
	int GetGreutate();
	virtual string GetCategorieGreutate();
	string GetConditieTemperatura();
	int GetTemperaturaSpalare();
	int GetIndexClient();
	int GetIndexProces();
	virtual bool GetCompatibilitateProces(int proces);
	string GetTipCuloare();
	virtual string GetType();

	void SetGreutate(int g);
	void SetIndexClient(int x);
	void SetIndexProces(int x);
	bool AvansareProces(); // daca returneaza true inseamna ca procesul s-a terminat
	void SetInfo();
	void AdaugaInformatiiTraseu(string info);

	void PrintInfo();
	void PrintTraseu();
};
