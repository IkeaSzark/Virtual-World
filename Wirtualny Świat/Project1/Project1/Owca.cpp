#include "Owca.h"
#include "Swiat.h"

Owca::Owca() :Zwierze() {

}

Owca::Owca(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) : Zwierze(sila, 4, x, y, wiek, swiat) {

}

bool Owca::Odbicie(Organizm* kolidujacy) {
	return false;
}

bool Owca::Ucieczka() {
	return false;
}

Organizm* Owca::StworzOrganizm(int x, int y, Swiat* swiat) {
	Owca* nowa = new Owca(4, 4, x, y, 0, swiat);
	return nowa;
}

char Owca::GetSymbol() const {
	return symbol;
}

string Owca::GetNazwa() const {
	return nazwa;
}

Owca::~Owca() {

}