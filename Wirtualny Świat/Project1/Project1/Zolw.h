#pragma once
#ifndef Zolw_h
#define Zolw_h

#include "Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Zolw : public Zwierze {
private:
	const char symbol = 'Z';
	const string nazwa = "Zolw";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Zolw();
	Zolw(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;
	bool Odbicie(Organizm* atakowany) override;
	bool Ucieczka() override;
	void Akcja() override;
	~Zolw();
};

#endif

