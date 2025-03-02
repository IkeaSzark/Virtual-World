#pragma once
#ifndef Trawa_h
#define Trawa_h

#include "Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Trawa : public Roslina {
private:
	const char symbol = 'T';
	const string nazwa = "Trawa";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Trawa();
	Trawa(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;

	~Trawa();
};

#endif // !Trawa_h

