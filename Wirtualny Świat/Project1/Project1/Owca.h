#pragma once
#ifndef Owca_h
#define Owca_h

#include "Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Owca : public Zwierze {
private:
	const char symbol = 'O';
	const string nazwa = "Owca";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Owca();
	Owca(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;
	bool Odbicie(Organizm* kolidjacy) override;
	bool Ucieczka() override;

	~Owca();
};

#endif // !Owca_h

