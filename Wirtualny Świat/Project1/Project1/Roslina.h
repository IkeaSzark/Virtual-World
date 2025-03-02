#pragma once
#ifndef Roslina_h
#define Roslina_h

#include "Organizm.h"

using namespace std;

class Swiat;
class Organizm;

class Roslina : public Organizm {
protected:
	 virtual Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override = 0;

public:
	Roslina();
	Roslina(int sila, int inicjatywa , int x , int y , int wiek, Swiat* swiat);

	void Akcja() override;
	void Kolizja(Organizm* kolidujacy) override;
	virtual char GetSymbol() const override = 0;
	virtual string GetNazwa() const override = 0;
	bool Odbicie(Organizm* atakowany) override;
	bool Ucieczka() override;


	~Roslina();
};

#endif // !Roslina_h

