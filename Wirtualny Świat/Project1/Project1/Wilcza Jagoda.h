#pragma once
#ifndef Wilcza Jagoda_h
#define Wilcza Jagoda_h

#include "Roslina.h"

using namespace std;

class Swiat;
class Organizm;
class Roslina;

class Jagoda : public Roslina {
private:
	const char symbol = 'J';
	const string nazwa = "Wilcza Jagoda";
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
public:
	Jagoda();
	Jagoda(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;

	~Jagoda();
};

#endif // !Wilcza Jagoda_h
