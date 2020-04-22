#pragma once
#include "Haina.h"
#include "Subclase_Haina.h"

class Costum 
{
private:
	Sacou sacou;
	Pantaloni pantaloni;
public:
	Costum(int g_sacou = 0, string ct_sacou = "", int ts_sacou = 0, string c_sacou = "", string tc_sacou = "", string cg_sacou = "grea",
		   int g_pantaloni = 0, string ct_pantaloni = "", int ts_pantaloni = 0, string c_pantaloni = "", string tc_pantaloni = "", string cg_pantaloni = "usoara");
	Costum(const Costum& p);
	Costum& operator=(const Costum& h);
	friend istream& operator>>(istream& in, Costum& h);
	friend ostream& operator<<(ostream& out, const Costum h);

	int GetGreutate();
	int GetGreutateSacou();
	int GetGreutatePantaloni();
	string GetConditieTemperatura();
	int GetTemperaturaSpalare();
	int GetIndexClient();
	string GetTipCuloare();

	void SetGreutate(int, int);
	void SetInfo();
	void SetIndexClient(int x);
	void PrintInfo();
	void AdaugaInformatiiTraseu(string info);
	bool GetCompatibilitateProces(int proces);
	void PrintTraseu();
	string GetType();
};

