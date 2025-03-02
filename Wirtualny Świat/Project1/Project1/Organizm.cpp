#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm() {
	sila = 0;
	inicjatywa = 0;
	polozenie_x = -1;
	polozenie_y = -1;
	wiek = 1;
	swiat = nullptr;
}
Organizm::Organizm(int sila, int inicjatywa, int x, int y, int wiek ,Swiat* swiat) {
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->wiek = wiek;
	polozenie_x = x;
	polozenie_y = y;
	this->swiat = swiat;
}
int Organizm::Get_sila() const {
	return sila;
}

int Organizm::Get_inicjatywa() const {
	return inicjatywa;
}

int Organizm::Get_wiek() const {
	return wiek;
}

int Organizm::Get_x() const {
	return polozenie_x;
}

int Organizm::Get_y() const {
	return polozenie_y;
}

void Organizm::Set_x(int x) {
	polozenie_x = x;
	return;
}

void Organizm::Set_y(int y) {
	polozenie_y = y;
	return;
}

void Organizm::Set_sila(int sila) {
	this->sila = sila;
	return;
}

void Organizm::ZnajdzPustePola(int x, int  y, int* punktX, int* punktY, int& ile) {
	if (y - 1 >= 0 && swiat->GetPolePlanszy(x, y - 1) == nullptr) {
		//Sprawdzenie czy gora jest wolna
		punktX[ile] = x;
		punktY[ile] = y-1;
		++ile;
	}
	if (y + 1 < swiat->GetM() && swiat->GetPolePlanszy(x, y + 1) == nullptr) {
		//Sprawdzenie czy dol jest wolny
		punktX[ile] = x;
		punktY[ile] = y+1;
		++ile;
	}
	if (x - 1 >= 0 && swiat->GetPolePlanszy(x - 1, y) == nullptr) {
		//Sprawdzenie czy lewo jest wolne
		punktX[ile] = x-1;
		punktY[ile] = y;
		++ile;
	}
	if (x + 1 < swiat->GetN() && swiat->GetPolePlanszy(x + 1, y) == nullptr) {
		//Sprawdzenie czy prawo jest wolne
		punktX[ile] = x+1;
		punktY[ile] = y;
		++ile;
	}

}

bool Organizm::Odbicie(Organizm* atakowany) {
	return false;
}

Organizm::~Organizm() {
};