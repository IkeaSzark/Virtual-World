#include "Zwierze.h"
#include "Swiat.h"
#include <string>
//inne includy jak rzeczy beda sie robic
const int GORA = 0;
const int DOL = 1;
const int LEWO = 2;
const int PRAWO = 3;

Zwierze::Zwierze() :Organizm() {

};

Zwierze::Zwierze(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) :Organizm(sila, inicjatywa, x, y, wiek, swiat) {

};

void Zwierze::Rozmnarzanie() {
	int* punktyX = new int[4];
	int* punktyY = new int[4];
	std::string wydarzenie = "";
	int ilosc = 0;
	this->ZnajdzPustePola(this->polozenie_x, this->polozenie_y, punktyX, punktyY, ilosc);

	if (ilosc != 0) {
		int wylosowany = rand() % ilosc;
		Organizm* nowy = this->StworzOrganizm(punktyX[wylosowany], punktyY[wylosowany], this->swiat);
		swiat->UstawPolePlanszy(punktyX[wylosowany], punktyY[wylosowany], nowy);
		swiat->DodajOrganizm(nowy);
		wydarzenie = "["+ to_string(this->Get_x()) + " " + to_string(this->Get_y()) +"] Organizm " + this->GetNazwa() + " rozmnaza sie!";
		swiat->DodajWydarzenie(wydarzenie);
	}
	else {
		wydarzenie = "Organizm " + this->GetNazwa() + " nie ma miejsca by sie rozmnozyc!";
		swiat->DodajWydarzenie(wydarzenie);
	}
	delete[] punktyX;
	delete[] punktyY;
};

void Zwierze::Akcja() {
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
		//Ruch w Gore
		punktyX[ile] = polozenie_x;
		punktyY[ile] = polozenie_y - 1;
		ile++;
	}
	if (polozenie_y + 1 < swiat->GetM())
	{
		//Ruch w Dol
		punktyX[ile] = polozenie_x;
		punktyY[ile] =polozenie_y + 1;
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
};

bool Zwierze::Odbicie(Organizm* atakowany) {
	return false;
};

void Zwierze::Kolizja(Organizm* kolidujacy) {
	std::string wydarzenie;
	if (this->GetNazwa() == kolidujacy->GetNazwa()) {
		wydarzenie = "[" + to_string(this->Get_x()) + " " + to_string(this->Get_y()) + "] Zwierzeta tego samego gatunku! Gatunek: " + this->GetNazwa();
		swiat->DodajWydarzenie(wydarzenie);
		if(this->Get_wiek() != 0 && kolidujacy->Get_wiek() != 0)
		   Rozmnarzanie();
		return;
	}
	else {
		if (kolidujacy->Odbicie(this)) {
			wydarzenie = "["+ to_string(this->Get_x()) + " " + to_string(this->Get_y()) + "] Zowl odbil atak zwierzêcia : " + this->GetNazwa() + " ";
			swiat->DodajWydarzenie(wydarzenie);
			return;
		}
		else if (kolidujacy->Ucieczka()) {
			wydarzenie = "["+ to_string(this->Get_x()) + " " + to_string(this->Get_y()) +"] Antylopa probuje uciec!";
			swiat->DodajWydarzenie(wydarzenie);
			int temp_x = kolidujacy->Get_x();
			int temp_y = kolidujacy->Get_y();
			int* punktyX = new int[4];
			int* punktyY = new int[4];
			int ilosc = 0;
			kolidujacy->ZnajdzPustePola(this->polozenie_x, this->polozenie_y, punktyX, punktyY, ilosc);
			if (ilosc != 0) {
				int wylosowany = rand() % ilosc;
				kolidujacy->Set_x(punktyX[wylosowany]);
				kolidujacy->Set_y(punktyY[wylosowany]);
				swiat->UstawPolePlanszy(punktyX[wylosowany], punktyY[wylosowany], kolidujacy);
				swiat->UstawPolePlanszy(this->polozenie_x, this->polozenie_y, nullptr);
				swiat->UstawPolePlanszy(temp_x, temp_y, this);
				this->polozenie_x = temp_x;
				this->polozenie_y = temp_y;
				delete[] punktyX;
				delete[] punktyY;
				return;
			}
			delete[] punktyX;
			delete[] punktyY;
		}
		else if (kolidujacy->GetNazwa() != "Jagoda") {
			int temp_x;
			int temp_y;

			wydarzenie = "[" + to_string(this->Get_x()) + " " + to_string(this->Get_y()) + "] Kolizja organizmu " + this->GetNazwa() + " oraz " + kolidujacy->GetNazwa();
			swiat->DodajWydarzenie( wydarzenie);
		     if (sila >= kolidujacy->Get_sila()) {
			  
			 wydarzenie = "[" + to_string(this->Get_x()) + " " + to_string(this->Get_y()) + "] " + this->GetNazwa() + " wygral i zabil " + kolidujacy->GetNazwa();
		 	  swiat->DodajWydarzenie(wydarzenie);
			  
			  if (kolidujacy->GetNazwa() == "Guarana") {
				  wydarzenie = "[" + to_string(this->Get_x()) + " " + to_string(this->Get_y()) + "] " + this->GetNazwa() + " zjadl Guarane!";
				  swiat->DodajWydarzenie(wydarzenie);
				  sila += 3;
			  }

			  temp_x = kolidujacy->Get_x();
			  temp_y = kolidujacy->Get_y();
			  swiat->UsunOrganizm(kolidujacy);
			  swiat->UstawPolePlanszy(temp_x, temp_y, this);
			  swiat->UstawPolePlanszy(polozenie_x, polozenie_y, nullptr);
			  polozenie_x = temp_x;
			  polozenie_y = temp_y;
			
			 }
			 else {
				 wydarzenie = "[" + to_string(this->Get_x()) + " " + to_string(this->Get_y()) + "] " + this->GetNazwa() + " przegral z " + kolidujacy->GetNazwa() + " i zostal zabity";
				 swiat->DodajWydarzenie(wydarzenie);
				 swiat->UsunOrganizm(this);
			 
			 }
		}
		else {
			wydarzenie = "["+ to_string(this->Get_x()) + " " + to_string(this->Get_y()) +"] Organizm zjadl " + kolidujacy->GetNazwa() + " i umarl!";
			swiat->DodajWydarzenie( wydarzenie );
			swiat->UsunOrganizm(this);
		}
	}
};

Zwierze::~Zwierze() {
};