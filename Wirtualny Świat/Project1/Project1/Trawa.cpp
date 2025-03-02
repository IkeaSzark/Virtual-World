#include "Trawa.h"
#include "Swiat.h"

Trawa::Trawa() :Roslina() {

}

Trawa::Trawa(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) :Roslina(sila, 0, x, y, wiek, swiat) {

}

char Trawa::GetSymbol() const{
	return symbol;
}

string Trawa::GetNazwa() const {
	return nazwa;
}

Organizm* Trawa::StworzOrganizm(int x , int y , Swiat *swiat) {
	Trawa* nowa = new Trawa(0, 0, x, y, 0 ,swiat);
	return nowa;
}

Trawa::~Trawa() {

}