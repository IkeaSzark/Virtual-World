#pragma once
#ifndef Organizm_h
#define Organizm_h

#include<iostream>
#include<string.h>
#include"Swiat.h"

using namespace std;

class Swiat;

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int polozenie_x;
	int polozenie_y;
	int wiek;
	Swiat* swiat;
	virtual Organizm* StworzOrganizm(int x, int y, Swiat* swiat) = 0;
public:
	Organizm();
	Organizm(int sila, int inicjatywa,int x, int y, int wiek, Swiat *swiat);

	int Get_sila() const;
	int Get_inicjatywa() const;
	int Get_x() const;
	int Get_y() const;
	int Get_wiek() const;
	void Set_x(int x);
	void Set_y(int y);
	void Set_sila(int sila);
	void ZnajdzPustePola(int x, int  y, int* punktX, int* punktY, int &ile);

	virtual void Akcja() = 0;
	virtual void Kolizja(Organizm *kolidujacy) = 0;
	virtual bool Odbicie(Organizm* atakowany) = 0;
	virtual bool Ucieczka() = 0;
	virtual string GetNazwa() const = 0;
	virtual char GetSymbol() const = 0;

	virtual ~Organizm();
};


#endif // !Organizm_h

