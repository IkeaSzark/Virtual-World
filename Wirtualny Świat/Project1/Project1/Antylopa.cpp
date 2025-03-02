#include "Antylopa.h"
#include "Swiat.h"


Antylopa::Antylopa() :Zwierze() {

}

Antylopa::Antylopa(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) : Zwierze(sila, 4, x, y, wiek , swiat) {

}

bool Antylopa::Odbicie(Organizm *kolidujacy) {
	return false;
}

bool Antylopa::Ucieczka() {
	int chance = rand() % 2 + 1;
	if (chance == 1)
		return true;
	else return false;
}

Organizm* Antylopa::StworzOrganizm(int x, int y, Swiat* swiat) {
	Antylopa* nowa = new Antylopa(4, 4, x, y, 0 ,swiat);

	return nowa;
}

void Antylopa::Kolizja(Organizm* kolidujacy) {
	if (Ucieczka() && kolidujacy->Get_sila() > sila && kolidujacy->GetNazwa() != nazwa) {
		string wydarzenie;
		wydarzenie = "Antylopa uciekla!";
		swiat->DodajWydarzenie( wydarzenie);
		//Funkcja znajdz puste pole
	}
	else
		Zwierze::Kolizja(kolidujacy);
}

void Antylopa::RuchAntylopy(int* punktyX, int* punktyY , int &ile) {
	if (polozenie_y - 1 >= 0) {
		//Ruch w Gore
		punktyX[ile] = polozenie_x;
		punktyY[ile] = polozenie_y - 1;
		ile++;
	}
	if (polozenie_y + 1 < swiat->GetM()) {
		//Ruch w Dol
		punktyX[ile] = polozenie_x;
		punktyY[ile] = polozenie_y + 1;
		ile++;
	}
	if (polozenie_x - 1 > 0) {
		//Ruch w Lewo
		punktyX[ile] = polozenie_x - 1;
		punktyY[ile] = polozenie_y;
		ile++;
	}
	if (polozenie_x + 1 < swiat->GetN()) {
		//Ruch w Prawo
		punktyX[ile] = polozenie_x + 1;
		punktyY[ile] = polozenie_y;
		ile++;
	}
	if (polozenie_y - 2 >= 0) {
		//Ruch dwa w Gore
		punktyX[ile] = polozenie_x;
		punktyY[ile] = polozenie_y - 2;
		ile++;
	}
	if (polozenie_y + 2 < swiat->GetM()) {
		//Ruch dwa w Dol
		punktyX[ile] = polozenie_x;
		punktyY[ile] = polozenie_y + 2;
		ile++;
	}
	if (polozenie_x - 2 > 0) {
		//Ruch dwa w Lewo
		punktyX[ile] = polozenie_x - 2;
		punktyY[ile] = polozenie_y;
		ile++;
	}
	if (polozenie_x + 2 < swiat->GetN()) {
		//Ruch dwa w Prawo
		punktyX[ile] = polozenie_x + 2;
		punktyY[ile] = polozenie_y;
		ile++;
	}
	if (polozenie_y - 1 >= 0 && polozenie_x - 1 > 0) {
		//Ruch w Gore i Lewo
		punktyX[ile] = polozenie_x - 1;
		punktyY[ile] = polozenie_y - 1;
		ile++;
	}
	if (polozenie_y + 1 < swiat->GetM() && polozenie_x - 1 > 0) {
		//Ruch w Dol i Lewo
		punktyX[ile] = polozenie_x + 1;
		punktyY[ile] = polozenie_y - 1;
		ile++;
	}
	if (polozenie_y - 1 >= 0 && polozenie_x + 1 < swiat->GetN()) {
		//Ruch w Gore i Prawo
		punktyX[ile] = polozenie_x - 1;
		punktyY[ile] = polozenie_y + 1;
		ile++;

	}
	if (polozenie_y + 1 < swiat->GetM() && polozenie_x + 1 < swiat->GetN()) {
		//Ruch w Dol i Prawo
		punktyX[ile] = polozenie_x + 1;
		punktyY[ile] = polozenie_y + 1;
		ile++;
	}
}

void Antylopa::Akcja() {
	if (wiek == 0) {
		++wiek;
		return;
	}
	int* punktyX = new int[12];
	int* punktyY = new int[12];
	int ile = 0;
	++wiek;
	RuchAntylopy(punktyX, punktyY, ile);
	if (ile > 0)
	{
		int wylosowany = rand() % ile;
		if (swiat->GetPolePlanszy(punktyX[wylosowany], punktyY[wylosowany]) == nullptr) {
			swiat->UstawPolePlanszy(punktyX[wylosowany], punktyY[wylosowany], this);
			swiat->UstawPolePlanszy(polozenie_x, polozenie_y, nullptr);
			polozenie_x = punktyX[wylosowany];
			polozenie_y = punktyY[wylosowany];
		}
		else {
			Kolizja(swiat->GetPolePlanszy(punktyX[wylosowany], punktyY[wylosowany]));
		}
	}
	delete[] punktyX;
	delete[] punktyY;
}

char Antylopa::GetSymbol() const {
	return symbol;
}

string Antylopa::GetNazwa() const {
	return nazwa;
}

Antylopa::~Antylopa() {

}