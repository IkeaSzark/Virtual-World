#include "Zolw.h"
#include "Swiat.h"

Zolw::Zolw() :Zwierze() {

}

Zolw::Zolw(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) : Zwierze(sila, 1, x, y, wiek, swiat) {

}
void Zolw::Akcja() {
	if (wiek == 0) {
		++wiek;
		return;
	}
	int los = rand() % 100;
	if (los < 25) {
		Zwierze::Akcja();
	}
	else {
		++wiek;
		return;
	}
}

bool Zolw::Odbicie(Organizm *atakujacy) {
	if (atakujacy->Get_sila() < 5)
		return true;
	else
		return false;
}

bool Zolw::Ucieczka() {
	return false;
}

Organizm* Zolw::StworzOrganizm(int x, int y, Swiat* swiat) {
	Zolw* nowa = new Zolw(3, 1, x, y, 0,swiat);
	return nowa;
}

char Zolw::GetSymbol() const {
	return symbol;
}

string Zolw::GetNazwa() const {
	return nazwa;
}

Zolw::~Zolw() {
};