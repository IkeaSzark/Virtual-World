#include "Swiat.h"
#include "Organizm.h"


#include "Zwierze.h"
#include "Roslina.h"

#include "Antylopa.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Czlowiek.h"

#include "Barszcz Sosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "Wilcza Jagoda.h"

const char ABILITY = 'e';
#define ARROW_INPUT 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

using namespace std;

Swiat::Swiat() {
	N = 20;
	M = 20;
	tura = 0;
	iloscOrganizmow = 0;
	status_czlowieka = true;
	ilosc_wydarzen = 0;
	Gracz = nullptr;
	Log = new string[7 * N * M];
	srand(time(0));
	
	GenerujPola();
}

Swiat::Swiat(int N, int M) {
	this->N = N;
	this->M = M;
	tura = 0;
	iloscOrganizmow = 0;
	status_czlowieka = true;
	ilosc_wydarzen = 0;
	Gracz = nullptr;
	Log = new string[7 * N * M];
	srand(time(0));

	GenerujPola();
}

Swiat::Swiat(std::ifstream& Plik) {
	srand(time(0));
	Plik >> this->N >> this->M;
	Plik >>  this->tura;
	Plik >> this->status_czlowieka;
	ilosc_wydarzen = 0;
	iloscOrganizmow = 0;
	Gracz == nullptr;
	Log = new string[7 * N * M];

	Organizmy = new Organizm * [N * M];
	for (int i = 0; i < N * M; ++i) {
		Organizmy[i] = nullptr;
	}
	PolaPlanszy = new Organizm * *[M];
	for (int i = 0; i < N; ++i) {
		PolaPlanszy[i] = new Organizm * [N];
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			PolaPlanszy[i][j] = nullptr;
	string nazwa;
	int x, y, sila, wiek;
	while (Plik >> nazwa) {
		if (nazwa == "Czlowiek") {
			int cooldown , snapshot;
			Plik >> x >> y >> sila >> wiek >> cooldown >> snapshot;
			Gracz = new Czlowiek(sila, 5, x, y, wiek, cooldown, snapshot, this);
			UstawPolePlanszy(x, y, Gracz);
			DodajOrganizm(Gracz);
		}
		else {
			Plik >> x >> y >> sila >> wiek;
			if (nazwa == "Antylopa") {
				UstawPolePlanszy(x, y, new Antylopa(sila, 4, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Barszcz Sosnowskiego") {
				UstawPolePlanszy(x, y, new Barszcz(sila, 0, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Guarana") {
				UstawPolePlanszy(x, y, new Guarana(sila, 0, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Lis") {
				UstawPolePlanszy(x, y, new Lis(sila, 7, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Mlecz") {
				UstawPolePlanszy(x, y, new Mlecz(sila, 0, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Owca") {
				UstawPolePlanszy(x, y, new Owca(sila, 4, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Trawa") {
				UstawPolePlanszy(x, y, new Trawa(sila, 0, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Wilcza Jagoda") {
				UstawPolePlanszy(x, y, new Jagoda(sila, 0, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Wilk") {
				UstawPolePlanszy(x, y, new Wilk(sila, 5, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
			else if (nazwa == "Zolw") {
				UstawPolePlanszy(x, y, new Zolw(sila, 1, x, y, wiek, this));
				DodajOrganizm(PolaPlanszy[x][y]);
			}
		}
	}
}

void Swiat::Sort() {
	for (int i = 0; i < iloscOrganizmow - 1; i++)
	{
		for (int j = 0; j < iloscOrganizmow - i - 1; j++)
		{
			if (Organizmy[j + 1] != nullptr) {
				if ((Organizmy[j] == nullptr || Organizmy[j]->Get_inicjatywa() < Organizmy[j + 1]->Get_inicjatywa()) )
				{
					swap(Organizmy[j], Organizmy[j + 1]);
				}
				else if (Organizmy[j]->Get_inicjatywa() == Organizmy[j + 1]->Get_inicjatywa()) {
					if (Organizmy[j]->Get_wiek() < Organizmy[j + 1]->Get_wiek()) {
						swap(Organizmy[j], Organizmy[j + 1]);
					}
				}
			}
		}
	}
}
void Swiat::GenerujStartoweOrganizmy(Organizm* org) {
	//Stworzyæ organizmy w kolejnoœci inicjatyw, po dwa z ka¿dego zwierzecia, po jednej roslinie.
	//Cz³owiek > Lis > Wilk > Antylopa > Owca > ¯ó³w > Trawa > Mlecz > Guarana > Wilcze Jagody > Barszcz
	if (iloscOrganizmow >= N * M)
		return;

	int nowe_X = -1;
	int nowe_Y = -1;
	nowe_X = rand() % N;
	nowe_Y = rand() % M;
	while (PolaPlanszy[nowe_X][nowe_Y] != nullptr) {
		nowe_X = rand() % N;
		nowe_Y = rand() % M;
	}
	if (PolaPlanszy[nowe_X][nowe_Y] == nullptr) {
		org->Set_x(nowe_X);
		org->Set_y(nowe_Y);
		PolaPlanszy[nowe_X][nowe_Y] = org;
		Organizmy[iloscOrganizmow] = org;
		++iloscOrganizmow;
		if (Czlowiek* czlowiek= dynamic_cast<Czlowiek*>(org)) {
			Gracz = dynamic_cast<Czlowiek*>(org);
		}
	}

}

void Swiat::GenerujPola() {
	Organizmy = new Organizm * [N * M];
	for (int i = 0; i < N * M; ++i) {
		Organizmy[i] = nullptr;
	}
	PolaPlanszy = new Organizm * *[M];
	for (int i = 0; i < N; ++i) {
		PolaPlanszy[i] = new Organizm * [N];
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			PolaPlanszy[i][j] = nullptr;

	//Generowanie organizmów na polach
	//Czlowiek
	GenerujStartoweOrganizmy(new Czlowiek(5,4, -1, -1, 1, 0 , 5, this));
    //Dwa lisy 
	GenerujStartoweOrganizmy(new Lis(3, 7, -1, -1, 1, this));
	GenerujStartoweOrganizmy(new Lis(3, 7, -1, -1, 1, this));
	//Dwa wilki
	GenerujStartoweOrganizmy(new Wilk(9, 5, -1, -1, 1, this));
	GenerujStartoweOrganizmy(new Wilk(9, 5, -1, -1, 1, this));
	//Dwie antylopy
	GenerujStartoweOrganizmy(new Antylopa(4, 4, -1, -1, 1, this));
	GenerujStartoweOrganizmy(new Antylopa(4, 4, -1, -1, 1, this));
	//Dwie owce
	GenerujStartoweOrganizmy(new Owca(4, 4, -1, -1, 1, this));
	GenerujStartoweOrganizmy(new Owca(4, 4, -1, -1, 1, this));
	//Dwa zolwie
	GenerujStartoweOrganizmy(new Zolw(2, 1, -1, -1, 1, this));
	GenerujStartoweOrganizmy(new Zolw(2, 1, -1, -1, 1, this));

	//Trawa
    GenerujStartoweOrganizmy(new Trawa(0, 0, -1, -1, 1, this));
	//Mlecz
	GenerujStartoweOrganizmy(new Mlecz(0, 0, -1, -1, 1, this));
	//Guarana
	GenerujStartoweOrganizmy(new Guarana(0, 0, -1, -1, 1, this));
	//Wilcza Jagoda
	GenerujStartoweOrganizmy(new Jagoda(99, 0, -1, -1, 1, this));
	//Barszcz Sosnowskiego
	GenerujStartoweOrganizmy(new Barszcz(10, 0, -1, -1, 1, this));
}

void Swiat::DodajOrganizm(Organizm* org) {
	if (iloscOrganizmow >= N * M) {
		string wydarzenie = "Plansza jest pelna!";
		Log[ilosc_wydarzen] = wydarzenie;
		++ilosc_wydarzen;
		return;
	}
	Organizmy[iloscOrganizmow] = org;
	++iloscOrganizmow;
	Sort();

}

void Swiat::UsunOrganizm(Organizm* org) {
	PolaPlanszy[org->Get_x()][org->Get_y()] = nullptr;
	for (int i = 0; i < iloscOrganizmow; ++i) {
		if (Organizmy[i] == org) {
			if (Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(org)) {
				status_czlowieka = false;
			}
			Organizmy[i] = nullptr;
			--iloscOrganizmow;
			delete org;
			Sort();
			return;
		}
	}
}

void Swiat::ZapiszSwiat() {
	std::ofstream Zapis;
	Zapis.open("ZapisGry.txt", std::ios::out);
	if (!Zapis) {
		cout <<"Nie mozna zapisac swiata"<<endl;
		return;
	}
	else {
		Zapis << N << " " << M << " " << tura << " " << status_czlowieka << endl;
		for (int i = 0; i < iloscOrganizmow; ++i) {
			if (Organizmy[i] != nullptr) {
				if (Organizmy[i]->GetNazwa() == "Czlowiek") {
					Zapis << Gracz->GetNazwa() << " " << Gracz->Get_x() << " " << Gracz->Get_y() << " ";
					Zapis << Gracz->Get_sila() << " " << Gracz->Get_wiek() << " " << Gracz->GetCooldown() << " " << Gracz->GetSnapshot() << endl;
				}
				else {
					Zapis << Organizmy[i]->GetNazwa() << " " << Organizmy[i]->Get_x() << " " << Organizmy[i]->Get_y() << " " << Organizmy[i]->Get_sila() << " ";
					Zapis << Organizmy[i]->Get_wiek() << endl;
				}
			}
		}
		Zapis.close();
		cout << "Pomyslnie zapisano gre.";
	}
};

void Swiat::DodajWydarzenie(std::string wydarzenie) {
	Log[ilosc_wydarzen] = wydarzenie;
	ilosc_wydarzen++;
};

void Swiat::WykonajTure() {

	bool start = true;
	if (status_czlowieka)
	{
		cout << endl;
		if (Gracz->GetCooldown() == 0 )
		{
			cout << "Jesli chcesz aktywowac umiejetnosc kliknij e." << endl;
		}
		
		cout << "Podaj ruch: " << endl;
		unsigned char znak = _getch();

		switch (znak)
		{
		case ABILITY:
			if (Gracz->GetCooldown() == 0)
			{
				Gracz->MagicznyEliksir();
				RysujSwiat();
			}
			else {
				cout << "Nie mozna uzyc umiejetnosci." << endl;
				znak = _getch();
			}
		case ARROW_INPUT:
			znak = _getch();
			Gracz->SetRuch(znak);
			break;
		default:
			string wydarzenie = "Zly klawisz";
			DodajWydarzenie(wydarzenie);
			start = false;
			break;
		}
	}
	if (start)
	{
		for (int i = 0; i < iloscOrganizmow; i++)
		{
			if (Organizmy[i] != nullptr) {
				Organizmy[i]->Akcja();
			}
		}
		++tura;
	}
}

void Swiat::RysujSwiat() {
	system("cls");
	cout << "|            Legenda:            |" << endl;
	cout << "|  strzalka w gore - ruch w gore |" << endl;
	cout << "|  strzalka w dol - ruch w dol   |" << endl;
	cout << "|  strzalka w lewo - ruch w lewo |" << endl;
	cout << "| strzalka w prawo - ruch w prawo|" << endl;
	cout << "|     s - zapis , l - wczytaj    |" << endl;
	cout << "|  e - umiejetnosc , q - wyjdz   |" << endl;
	cout << "|      ENTER - start tury        |" << endl;
	cout << "| Umiejetnosc - Magiczny Eliksir |" << endl;
	cout << "|           Symbole:             |" << endl;
	cout << "| A - antylopa , C - czlowiek    |" << endl;
	cout << "| L - lis , O - owca , W - wilk  |" << endl;
	cout << "|   B - barszcz sosnowskiego     |" << endl;
	cout << "|   G - Guarana , M - Mlecz      |" << endl;
	cout << "| W - Wilcza Jagoda , T - Trawa  |" << endl;
	cout << "|    Z - zolw , + - puste pole   |" << endl;
	cout << "|        Sila Gracza = " + to_string(Gracz->Get_sila()) + "         |" <<endl;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (PolaPlanszy[i][j] == nullptr || PolaPlanszy[i][j] == NULL) {
				cout << '+';
			}
			else {
				cout << PolaPlanszy[i][j]->GetSymbol();
			}
		}
		cout << endl;
	}
	for (int i = 0; i < ilosc_wydarzen; ++i) {
		cout << Log[i] << endl;
	}
	ilosc_wydarzen = 0;
	return;
}

int Swiat::GetM() const {
	return M;
}

int Swiat::GetN() const {
	return N;
}

int Swiat::GetTura() const {
	return tura;
}

int Swiat::GetIlosc() const {
	return iloscOrganizmow;
}

Organizm* Swiat::GetPolePlanszy(int x , int y) const {
	return PolaPlanszy[x][y];
}

void Swiat::SetM(int M) {
	this->M = M;
}

void Swiat::SetN(int N) {
	this->N = N;
}

void Swiat::SetTura(int tura) {
	this->tura = tura;
}

void Swiat::UstawPolePlanszy(int x, int y, Organizm* organizm) {
	PolaPlanszy[x][y] = organizm;
}

Swiat::~Swiat() {
	delete[] Log;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			delete PolaPlanszy[i][j];
		}
		delete[] PolaPlanszy[i];
	}
	delete[] PolaPlanszy;
	delete[] Organizmy;
}