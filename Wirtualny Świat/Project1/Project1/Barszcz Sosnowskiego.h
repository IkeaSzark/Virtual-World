#pragma once
#ifndef Barszcz_h
#define Barszcz_h

#include "Roslina.h"
#include <iostream>
#include <string.h>

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Barszcz : public Roslina {
private:
	const char symbol = 'B';
	const string nazwa = "Barszcz Sosnowskiego";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Barszcz();
	Barszcz(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;
	void Akcja() override;
	~Barszcz();
};

#endif // !Trawa_h
