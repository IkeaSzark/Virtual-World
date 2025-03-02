#pragma once
#ifndef Swiat_h
#define Swiat_h

#include<iostream>
#include<fstream>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<string>


class Organizm;
class Czlowiek;
class Swiat {
private:
	int N;
	int M;
	int tura;
	int iloscOrganizmow;
	Organizm*** PolaPlanszy;
	Organizm** Organizmy;
	Czlowiek* Gracz;
	void GenerujPola();
	void GenerujStartoweOrganizmy(Organizm *org);
	void Sort();
	bool status_czlowieka;

	std::string* Log;
	int ilosc_wydarzen;

public:
	Swiat();
	Swiat(int N , int M);
	Swiat(std::ifstream& Plik);

	int GetN() const;
	int GetM() const;
	int GetTura() const;
	int GetIlosc() const;
	Organizm* GetPolePlanszy( int x , int y) const;
	void SetN(int N);
	void SetM(int M);
	void SetTura(int tura);
	void UstawPolePlanszy(int x, int y, Organizm* organizm);
	
	
	void DodajOrganizm(Organizm* organizm);
	void UsunOrganizm(Organizm* organizm);
	void DodajWydarzenie(std::string log);
	void WykonajTure();
	void RysujSwiat();

	void ZapiszSwiat();

	~Swiat();
};
#endif
