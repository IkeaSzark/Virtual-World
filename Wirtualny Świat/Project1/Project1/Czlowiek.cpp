#include "Czlowiek.h"
#include "Swiat.h"


#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

Czlowiek::Czlowiek() :Zwierze() {
	cooldown = 0;
	snapshot = 5;
	ruch = NULL;
}

Czlowiek::Czlowiek(int sila, int inicjatywa, int x, int y, int wiek , int cooldown , int snapshot ,Swiat* swiat) : Zwierze(sila, 4, x, y, wiek ,swiat) {
	this->cooldown = cooldown;
	this->snapshot = snapshot;
	ruch = NULL;
}

void Czlowiek::Przesun(int nowyX, int nowyY) {
	if (swiat->GetPolePlanszy(nowyX, nowyY) == nullptr) {
		swiat->UstawPolePlanszy(nowyX, nowyY, this);
		swiat->UstawPolePlanszy(polozenie_x, polozenie_y, nullptr);
		polozenie_x = nowyX;
		polozenie_y = nowyY;
	}
	else {
		Kolizja(swiat->GetPolePlanszy(nowyX, nowyY));
	}
}

void Czlowiek::Akcja() {

	++wiek;
	if (ruch == DOWN_ARROW)
	{
		//Ruch w Dol
			if (polozenie_x + 1 < swiat->GetN()) {
				Przesun(polozenie_x + 1, polozenie_y);
			}
	}
	else if (ruch == UP_ARROW)
	{
		//Ruch w Gore
		if (polozenie_x - 1 >= 0) {
			Przesun(polozenie_x -1, polozenie_y);
		}

	}
	else if (ruch == LEFT_ARROW)
	{
		//Ruch w Lewo
		if (polozenie_y - 1 >= 0) {
			Przesun(polozenie_x, polozenie_y - 1);
		}


	}
		else if (ruch == RIGHT_ARROW)
		{
			//Ruck w Prawo
		if (polozenie_y + 1 < swiat->GetM()) {
			Przesun(polozenie_x, polozenie_y + 1);
		}
		}
	if (cooldown > 0) {
		if (sila > snapshot) {
			--sila;
		}
		else {
			--cooldown;
		}
	}
	return;
}

void Czlowiek::MagicznyEliksir() {
	if (cooldown == 0) {
		cout << "Uzyto Magicznego Eleksiru!"<<endl;
		snapshot = sila;
		sila = 10;
		cooldown = 5;
		return;
	}
	else return;
}

char Czlowiek::GetSymbol() const {
	return symbol;
}

string Czlowiek::GetNazwa() const {
	return nazwa;
}

int Czlowiek::GetCooldown() const {
	return cooldown;
}

int Czlowiek::GetSnapshot() const {
	return snapshot;
}

void Czlowiek::SetCooldown(int cooldown) {
	this->cooldown = cooldown;
}

char Czlowiek::GetRuch() const {
	return ruch;
}

void Czlowiek::SetRuch(char ruch) {
	this->ruch = ruch;
}

bool Czlowiek::Odbicie(Organizm* kolidujacy) {
	return false;
}

bool Czlowiek::Ucieczka() {
	return false;
}

Organizm* Czlowiek::StworzOrganizm(int x , int y , Swiat *swiat) {
	return nullptr;
}

Czlowiek::~Czlowiek() {

}