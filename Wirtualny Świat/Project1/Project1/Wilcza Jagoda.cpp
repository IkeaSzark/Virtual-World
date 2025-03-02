#include "Wilcza Jagoda.h"
#include "Swiat.h"

Jagoda::Jagoda() :Roslina() {

}

Jagoda::Jagoda(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) :Roslina(sila, 0, x, y, wiek, swiat) {

}

char Jagoda::GetSymbol() const {
	return symbol;
}

string Jagoda::GetNazwa() const {
	return nazwa;
}

Organizm* Jagoda::StworzOrganizm(int x, int y, Swiat* swiat) {
	Jagoda* nowa = new Jagoda(99, 0, x, y, 0, swiat);
	return nowa;
}

Jagoda::~Jagoda() {

}