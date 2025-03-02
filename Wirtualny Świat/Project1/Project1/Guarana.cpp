#include "Guarana.h"
#include "Swiat.h"


Guarana::Guarana() :Roslina() {

}

Guarana::Guarana(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) :Roslina(sila, 0, x, y, wiek, swiat) {

}

char Guarana::GetSymbol() const {
	return symbol;
}

string Guarana::GetNazwa() const {
	return nazwa;
}

Organizm* Guarana::StworzOrganizm(int x, int y, Swiat* swiat) {
	Guarana* nowa = new Guarana(0, 0, x, y, 0 ,swiat);
	return nowa;
}

Guarana::~Guarana() {

}