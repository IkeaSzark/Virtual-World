#pragma once
#ifndef Wilk_h
#define Wilk_h

#include "Zwierze.h"


using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Wilk : public Zwierze {
private:
	const char symbol = 'W';
	const string nazwa = "Wilk";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Wilk();
	Wilk(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;
	bool Odbicie(Organizm* kolidjacy) override;
	bool Ucieczka() override;

	~Wilk();
};

#endif // !Wilk_h

