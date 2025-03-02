#pragma once
#ifndef Zwierze_h
#define Zwierze_h

#include "Organizm.h"

using namespace std;

class Swiat;
class Organizm;

class Zwierze : public Organizm
{
private:

protected:
	virtual Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override = 0;
public:
	Zwierze();
	Zwierze(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	void Rozmnarzanie();
	virtual bool Odbicie(Organizm* atakowany) override = 0;
	virtual bool Ucieczka() override = 0;
	void Kolizja(Organizm *kolidujacy) override;
	void Akcja() override;
	virtual string GetNazwa() const override = 0;
	virtual char GetSymbol() const override = 0;

	~Zwierze();
};


#endif // !Zwierze_h
