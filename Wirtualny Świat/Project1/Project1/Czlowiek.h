#pragma once
#ifndef Czlowiek_h
#define Czlowiek_h

#include "Zwierze.h"

using namespace std;

class Swiat;
class Organizm;
class Zwierze;

class Czlowiek : public Zwierze {
private:
	const char symbol = 'C';
	const string nazwa = "Czlowiek";
	int cooldown;
	int snapshot;
	bool zyje = true;
	Organizm* StworzOrganizm(int x, int y, Swiat* swiat) override;
	void Przesun(int nowyX, int nowyY);
	char ruch; 
	
    public:
	Czlowiek();
	Czlowiek(int sila, int inicjatywa, int x, int y, int wiek, int cooldown , int snapshot,Swiat* swiat);

	char GetSymbol() const override;
	string GetNazwa() const override;
	void Akcja() override;
	void MagicznyEliksir();
	int GetCooldown() const;
	void SetCooldown(int cooldown);
	int GetSnapshot() const;
	char GetRuch() const;
	void SetRuch(char ruch);
	bool Odbicie(Organizm* kolidjacy) override;
	bool Ucieczka() override;

	~Czlowiek();
};

#endif // !Czlowiek_h

