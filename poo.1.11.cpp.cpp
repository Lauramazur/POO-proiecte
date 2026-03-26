#include<iostream>
using namespace std;
class Medicament {
private:
	string denumire;
	string producator;
	string dataExpirare;
	double pret;
	int cantitate;
public:
	Medicament() {
		denumire = "Necunoscut";
		producator = "Necunoscut";
		dataExpirare = "Nedefinit";
		pret = 0;
		cantitate = 0;
	}
	Medicament(string d, string pr, string data, double p, int c) {
		denumire = d;
		producator = pr;
		dataExpirare = data;
		pret = p;
		cantitate = c;
	}
	Medicament(const Medicament& m) {
		denumire = m.denumire;
		producator = m.producator;
		dataExpirare=m.dataExpirare;
		pret = m.pret;
		cantitate = m.cantitate;
	}
	~Medicament() {
		cout << "Obiectul Medicament a fost distrus." << endl;
	}
	string getDenumire() {
		return denumire;
	}
	double getPret() {
		return pret;
	}
	int getCantitate() {
		return cantitate;
	}
	void setPret(double p) {
		if (p > 0)
			pret = p;
	}
	void setCantitate(int c) {
		if (c >= 1)
		cantitate = c;
	}
};
int main() {
	Medicament m1;
	Medicament m2("Citramon", "Balkan Pharmaceuticals", "17.09.28", 14.89, 30);
	Medicament m3 = m2;
	cout << "Medicament:" << m3.getDenumire() << endl;
	cout << "Pret:" << m3.getPret() << "lei" << endl;
	cout << "Cantitate:" << m3.getCantitate() << endl;
	return 0;
}
