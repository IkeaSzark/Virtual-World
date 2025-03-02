#include "Wilk.h"
#include "Swiat.h"

Wilk::Wilk() :Zwierze() {

}

Wilk::Wilk(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) : Zwierze(sila, 5, x, y, wiek, swiat) {

}

bool Wilk::Odbicie(Organizm* kolidujacy) {
	return false;
}

bool Wilk::Ucieczka() {
	return false;
}

Organizm* Wilk::StworzOrganizm(int x, int y, Swiat* swiat) {
	Wilk* nowa = new Wilk(9, 5, x, y, 0, swiat);
	return nowa;
}

char Wilk::GetSymbol() const {
	return symbol;
}

string Wilk::GetNazwa() const {
	return nazwa;
}

Wilk::~Wilk() {

}