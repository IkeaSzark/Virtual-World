#pragma once
#ifndef Guarana_h
#define Guarana_h

#include "Roslina.h"


using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Guarana : public Roslina {
private:
	const char symbol = 'G';
	const string nazwa = "Guarana";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Guarana();
	Guarana(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;

	~Guarana();
};

#endif // !Trawa_h
