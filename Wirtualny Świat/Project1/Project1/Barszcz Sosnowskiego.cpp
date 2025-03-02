#include "Barszcz Sosnowskiego.h"
#include "Swiat.h"
#include "Zwierze.h"


Barszcz::Barszcz() :Roslina() {

}

Barszcz::Barszcz(int sila, int inicjatywa, int x, int y, int wiek, Swiat* swiat) :Roslina(sila, 0, x, y, wiek, swiat) {

}

char Barszcz::GetSymbol() const {
	return symbol;
}

string Barszcz::GetNazwa() const {
	return nazwa;
}
Organizm* Barszcz::StworzOrganizm(int x, int y, Swiat* swiat) {
	Barszcz* nowa = new Barszcz(10, 0, x, y, 0 ,swiat);
	return nowa;
}

void Barszcz::Akcja() {
	if (polozenie_y - 1 >= 0)
	{
		//Gora
		if (Zwierze* organizm = dynamic_cast<Zwierze*>(swiat->GetPolePlanszy(polozenie_x, polozenie_y - 1))) {
			swiat->UsunOrganizm(swiat->GetPolePlanszy(polozenie_x, polozenie_y - 1));
		}
	}
	if (polozenie_y + 1 < swiat->GetM())
	{
		//Dol
		if (Zwierze* organizm = dynamic_cast<Zwierze*>(swiat->GetPolePlanszy(polozenie_x, polozenie_y + 1))) {
			swiat->UsunOrganizm(swiat->GetPolePlanszy(polozenie_x, polozenie_y + 1));
		}

	}
	if (polozenie_x - 1 > 0)
	{
		//Lewo
		if (Zwierze* organizm = dynamic_cast<Zwierze*>(swiat->GetPolePlanszy(polozenie_x - 1, polozenie_y))) {
			swiat->UsunOrganizm(swiat->GetPolePlanszy(polozenie_x - 1, polozenie_y));
		}
	}
	if (polozenie_x + 1 < swiat->GetN())
	{
		//Prawo
		if (Zwierze* organizm = dynamic_cast<Zwierze*>(swiat->GetPolePlanszy(polozenie_x + 1, polozenie_y))) {
			swiat->UsunOrganizm(swiat->GetPolePlanszy(polozenie_x + 1, polozenie_y));
		}

	}
	Roslina::Akcja();
}

Barszcz::~Barszcz() {

}