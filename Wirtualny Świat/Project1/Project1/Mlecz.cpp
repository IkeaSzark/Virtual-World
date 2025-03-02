#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz() :Roslina() {

}

Mlecz::Mlecz(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) :Roslina(sila, 0, x, y, wiek, swiat) {

}

char Mlecz::GetSymbol() const {
	return symbol;
}

string Mlecz::GetNazwa() const {
	return nazwa;
}
void Mlecz::Akcja() {
	if (wiek == 0) {
		++wiek;
		return;
	}
	Roslina::Akcja();
	--wiek;
    Roslina::Akcja();
	--wiek;
	Roslina::Akcja();
}
Organizm* Mlecz::StworzOrganizm(int x, int y, Swiat* swiat) {
	Mlecz* nowa = new Mlecz(0, 0, x, y, 0, swiat);
	return nowa;
}

Mlecz::~Mlecz() {

}