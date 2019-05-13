// Voorbeeld: Polymorfisme via een referentie
#include <iostream>
#include <string>
using namespace std;



class Figuur {
protected:
	char symbool;
public:
	Figuur(char symbool = '*')
		: symbool(symbool) {
	}

	void setSymbool(char sym) {
		symbool = sym;
	}

	virtual void teken() const = 0;      // zuiver virtuele functie
};

class Rechthoek : public Figuur {
private:
	int breedte, hoogte;
public:
	Rechthoek(int breedte, int hoogte)
		: breedte(breedte), hoogte(hoogte) {
	};
	void teken() const;
	int oppervlak() const;
};

class Driehoek : public Figuur {
private:
	int grootte;
public:
	Driehoek(int grootte)
		: grootte(grootte) {
	};
	void teken() const;
};

// Functie met een referentie als argument
void tekenFiguur(Figuur &f) {
	f.teken();

	const Rechthoek *pRechthoek = dynamic_cast<Rechthoek *>(&f);
	if (pRechthoek != nullptr) {
		cout << pRechthoek->oppervlak() << endl;
	}
}

int main() {
	Rechthoek rh(6, 2);
	Driehoek dh(5);
	dh.setSymbool('b');

	tekenFiguur(rh);
	tekenFiguur(dh);
	cin.get();
}


// Implementatie van de lidfuncties als in voorbeeld 15.3

// Implementatie
void Rechthoek::teken() const {
	// Maak een regel met symbolen, gescheiden door een spatie
	// Bijvoorbeeld:
	// * * * * * * * * *
	string regel;
	for (int k = 0; k < breedte; ++k) {
		regel += symbool;
		regel += ' ';
	}
	// Zet de zojuist gemaakte regels onder elkaar
	for (int r = 0; r < hoogte; ++r) {
		cout << regel << endl;
	}
}

int Rechthoek::oppervlak() const {
	return breedte * hoogte;
}

void Driehoek::teken() const {
	// Maak een regel bestaande uit een aantal spaties,
	// gevolgd door een symbool en een spatie, bijvoorbeeld:
	// _______*    (spaties zijn hier weergegeven met _)
	string regel;
	for (int k = 0; k < grootte; ++k)
		regel += ' ';
	regel += symbool;
	regel += ' ';

	// Zet een aantal regels onder elkaar
	for (int r = 0; r < grootte; ++r) {
		cout << regel << endl;
		// Verwijder het eerste karakter uit de regel
		regel.erase(0, 1);
		// Voeg aan het eind een symbool en een spatie toe
		regel += symbool;
		regel += ' ';
	}


}

