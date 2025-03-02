

#include "Swiat.h"
#include <conio.h>
#define ENTER 13


const char SAVE = 's';
const char LOAD = 'l';
const char ABILITY = 'e';
const char QUIT = 'q';
const char DEFAULT = '1';
const char CUSTOM = '2';

using namespace std;

int main() {
	system("cls");
	cout << "|        Wirtualny Œwiat         |" << endl;
	cout << "|    Filip Weso³owski 193486     |" << endl;
	cout << "|            Legenda:            |" << endl;
	cout << "| 1 - 20x20 , 2 - podaj rozmiar  |" << endl;
	cout << "|  q - wyjdŸ , l - wczytaj gre   |" << endl;

	char input;
	int N, M;
	Swiat* gra = nullptr;
	input = _getch();
	while (input != QUIT && input != LOAD && input != CUSTOM && input != DEFAULT) {
		input = _getch();
	}
	switch (input) {
	case QUIT:
	{
		return 0;
	}
	case DEFAULT: {
		gra = new Swiat();
		break;
	}
	case CUSTOM: {
		system("cls");
		cout << "Podaj wysokosc: ";
		cin >> N;
		cout << "Podaj szerokosc: ";
		cin >> M;
		gra = new Swiat(N, M);
		break;
	}
	case LOAD: {
		std::ifstream Zapis;
		Zapis.open("ZapisGry.txt", std::ios::in);
		if (!Zapis) {
			cout << "Nie ma zapisanego swiata!";
			return 0;
		}
		gra = new Swiat(Zapis);
		break;
	}
	}

	gra->RysujSwiat();
	while (input != QUIT) {
		input = _getch();
		switch (input) {
		case ENTER: {
			gra->WykonajTure();
			gra->RysujSwiat();
			break;
		}

		case QUIT: {
			return 0;
		}
		case SAVE: {
			gra->ZapiszSwiat();
			break;
		}
		case LOAD: {
			std::ifstream Zapis;
			Zapis.open("ZapisGry.txt", std::ios::in);
			if (!Zapis) {
				cout << "Nie ma zapisanego swiata!";
				return 0;
			}
			delete gra;
			gra = new Swiat(Zapis);
			gra->RysujSwiat();
			break;
		}
		}
	}
	return 0;
}
