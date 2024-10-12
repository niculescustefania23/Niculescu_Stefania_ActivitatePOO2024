#include<iostream>

using namespace std;





//structura
//pointeri
//vectori
//transmiterea unui vector ca parametru
//citirea unui vector


struct Tara {
	char* denumire;
	int nrlocuitori;
	string capitala;
	bool areIesireLaMare;
};

void afisarePointeriLaTara(Tara tara) {

}

void afisarePointeriLaTara(Tara* pt) {
	cout << "Nume:" << pt->denumire << endl;
	cout << "Numar locuitori:" << pt->nrlocuitori << endl;
	cout << "Capitala:" << pt->capitala << endl;
	cout << "Are iesire la mare:" << (pt->areIesireLaMare ? "DA" : "NU") << endl;

}



//op ternar
Tara* citirePointeriLaTara() {
	Tara* p = new Tara();
	cout << "capitala:";
	cin >> p->capitala;
	cout << "Denumire:";
	char buffer[100];
	cin >> buffer;
	p->capitala = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);

	cout << "Numar locuitori:";
	cin >> p->nrlocuitori;

	cout << "Are iesire la mare? (0-NU; 1-DA)";
	cin >> p->areIesireLaMare;


	return p;

}
int main() {
	Tara tara;
	tara.areIesireLaMare = false;


	Tara* pTara;
	pTara = new Tara();
	pTara->areIesireLaMare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1];
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania");
	pTara->nrlocuitori = 200;


	afisarePointeriLaTara(pTara);

	delete[]pTara->denumire;
	delete pTara;

	Tara* p2Tara = citirePointeriLaTara(); //citire pointeri la tara
	afisarePointeriLaTara(p2Tara);//afisare pointeri la tara

	Tara* vector;
	vector = new Tara[2];//alocare dinamica

	delete[]vector;

	int nrPointeri = 2;
	//vector de pointeri
	Tara** pointeri;
	pointeri = new Tara * [nrPointeri];
	for (int i = 0; i < nrPointeri; i++) {
		pointeri[i] = citirePointeriLaTara();

	}

	//procesare
	for (int i = 0; i < nrPointeri; i++) {
		afisarePointeriLaTara(pointeri[i]);

	}


	//procesare
	for (int i = 0; i < nrPointeri; i++) {
		delete[]pointeri[i]->denumire;
		delete pointeri[i];
	}

	delete[]pointeri;
}
