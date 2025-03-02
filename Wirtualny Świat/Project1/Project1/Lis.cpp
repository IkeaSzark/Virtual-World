#include "Lis.h"
#include "Swiat.h"


Lis::Lis() :Zwierze() {

}

Lis::Lis(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) : Zwierze(sila, 7, x, y, 0, swiat) {

}

bool Lis::Odbicie(Organizm* kolidujacy) {
	return false;
}

bool Lis::Ucieczka() {
	return false;
}

void Lis::Akcja() {
	if (wiek == 0) {
		++wiek;
		return;
	}
	int* punktyX = new int[4];
	int* punktyY = new int[4];
	int ile = 0;
	++wiek;
	if (polozenie_y - 1 >= 0)
	{
		//Ruch w Dol
		punktyX[ile] = polozenie_x;
		punktyY[ile] = polozenie_y - 1;
		ile++;
	}
	if (polozenie_y + 1 < swiat->GetM())
	{
		//Ruch w Gore
		punktyX[ile] = polozenie_x;
		punktyY[ile] = polozenie_y + 1;
		ile++;
	}
	if (polozenie_x - 1 > 0)
	{
		//Ruch w Lewo
		punktyX[ile] = polozenie_x - 1;
		punktyY[ile] = polozenie_y;
		ile++;
	}
	if (polozenie_x + 1 < swiat->GetN())
	{
		//Ruck w Prawo
		punktyX[ile] = polozenie_x + 1;
		punktyY[ile] = polozenie_y;
		ile++;
	}

	if (ile > 0)
	{
		int wylosowany = rand() % ile;
		while (swiat->GetPolePlanszy(punktyX[wylosowany], punktyY[wylosowany]) != nullptr) {
			if(swiat->GetPolePlanszy(punktyX[wylosowany], punktyY[wylosowany])->Get_sila() > this->sila)
				wylosowany = rand() % ile;
			else {
				Kolizja(swiat->GetPolePlanszy(punktyX[wylosowany], punktyY[wylosowany]));
				break;
			}
		}
		if (swiat->GetPolePlanszy(punktyX[wylosowany], punktyY[wylosowany]) == nullptr) {
			swiat->UstawPolePlanszy(punktyX[wylosowany], punktyY[wylosowany], this);
			swiat->UstawPolePlanszy(polozenie_x, polozenie_y, nullptr);
			polozenie_x = punktyX[wylosowany];
			polozenie_y = punktyY[wylosowany];
		}
	}
	delete[] punktyX;
	delete[] punktyY;
}

Organizm* Lis::StworzOrganizm(int x, int y, Swiat* swiat) {
	Lis* nowa = new Lis(3, 7, x, y, 0, swiat);
	return nowa;
}

char Lis::GetSymbol() const {
	return symbol;
}

std::string Lis::GetNazwa() const {
	return nazwa;
}

Lis::~Lis() {

}