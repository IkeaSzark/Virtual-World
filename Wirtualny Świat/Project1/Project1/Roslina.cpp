#include "Roslina.h"
#include "Swiat.h"

using namespace std;

Roslina::Roslina() :Organizm() {

};

Roslina::Roslina(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) :Organizm(sila, inicjatywa, x, y, wiek ,swiat) {

};

bool Roslina::Odbicie(Organizm* o) {
	return false;
}

bool Roslina::Ucieczka() {
	return false;
}

//mo¿e lepszym pomys³em jest osobno ka¿dej klasie zrobiæ akcje a ¿eby nie includowaæ klas pochodnych?
void Roslina::Akcja() {
	string wydarzenie;
	if (wiek == 0) {
		++wiek;
		return;
	}
	int zasianie = rand() % 10;
	if(zasianie < 3) {
		int* punktX = new int[4];
		int* punktY = new int[4];

		int ilosc = 0;
		this->ZnajdzPustePola(this->polozenie_x, this->polozenie_y, punktX, punktY, ilosc);

		if (ilosc != 0) {
			int wylosowany = rand() % ilosc;
			Organizm* nowy = this->StworzOrganizm(punktX[wylosowany], punktY[wylosowany], swiat);
			swiat->UstawPolePlanszy(punktX[wylosowany], punktY[wylosowany], nowy);
			swiat->DodajOrganizm(nowy);
			wydarzenie = "[" + to_string(this->Get_x()) + " " + to_string(this->Get_y()) + "]Organizm " + this->GetNazwa() + " rozprzestrzenia sie!";
			swiat->DodajWydarzenie( wydarzenie );
		}
		else {
			wydarzenie = "[" + to_string(this->Get_x()) + " " + to_string(this->Get_y()) + "]Organizm " + this->GetNazwa() + " nie ma miejsca by sie rozprzestrzenic!";
			swiat->DodajWydarzenie(wydarzenie);
		}
		delete[] punktX;
		delete[] punktY;
	}
	++wiek;
}
void Roslina::Kolizja(Organizm* o) {
	return;
}

Roslina::~Roslina() {

}