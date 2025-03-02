#pragma once
#ifndef Antylopa_h
#define Antylopa_h

#include "Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Antylopa : public Zwierze {
private:
	const char symbol = 'A';
	const string nazwa = "Antylopa";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Antylopa();
	Antylopa(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;
	bool Ucieczka() override;
	void Akcja() override;
	void RuchAntylopy(int* punktyX, int* punktyY, int &ile);
	void Kolizja(Organizm* kolidujacy) override;
	bool Odbicie(Organizm* kolidjacy) override;


	~Antylopa();
};

#endif // !Antylopa_h