#pragma once
#ifndef Mlecz_h
#define Mlecz_h

#include "Roslina.h"


using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Mlecz : public Roslina {
private:
	const char symbol = 'M';
	const string nazwa = "Mlecz";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Mlecz();
	Mlecz(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);
	void Akcja() override;
	char GetSymbol() const override;
	string GetNazwa() const override;

	~Mlecz();
};

#endif // !Trawa_h
