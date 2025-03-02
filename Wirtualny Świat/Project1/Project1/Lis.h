#pragma once
#ifndef Lis_h
#define Lis_h

#include "Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Lis : public Zwierze {
private:
	const char symbol = 'L';
	string nazwa = "Lis";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Lis();
	Lis(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	std::string GetNazwa() const override;
	bool Odbicie(Organizm* kolidjacy) override;
	bool Ucieczka() override;
	void Akcja() override;


	~Lis();
};

#endif // !Lis_h
