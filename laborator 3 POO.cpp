#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Bilet {
protected:
	int nr_bilet;
	string oraStart;
	string oraSfarsit;
public:
	Bilet(int nr, string start, string sfarsit) {
		nr_bilet = nr;
		oraStart = start;
		oraSfarsit = sfarsit;
}
	int calculeazaDurata() {
		int h1 = (oraStart[0] - '0') * 10 + (oraStart[1] - '0');
		int m1 = (oraStart[3] - '0') * 10 + (oraStart[4]-'0');
		int h2 = (oraSfarsit[0] - '0') * 10 + (oraSfarsit[1] - '0');
		int m2 = (oraSfarsit[3] - '0') * 10 + (oraSfarsit[4] - '0');
		int minStart = h1 * 60 + m1;
		int minSfarsit = h2 * 60 + m2;
		int durata = minSfarsit - minStart;
		return minSfarsit - minStart;
	}
	virtual float calculeazaCost() = 0;
	virtual ~Bilet(){}
};
class BiletStandart :public Bilet {
public:
	BiletStandart(int nr, string start, string sfarsit) :Bilet(nr, start, sfarsit) {}
		float calculeazaCost() {
			return(calculeazaDurata() / 60.0) * 2;
		}
	
};
class Abonament :public Bilet {
public:
	Abonament(int nr,string start,string sfarsit):Bilet(nr,start,sfarsit){}
	float calculeazaCost() {
		return 50.0;
	}
};
class BiletReducere :public Bilet {
public:
	BiletReducere(int nr, string start, string sfarsit) :Bilet(nr, start, sfarsit) {}
	float calculeazaCost() {
		return (calculeazaDurata() / 60.0) * 1.0;
	}
};
class BiletTuristic :public Bilet {
public:
	BiletTuristic(int nr,string start,string sfarsit):Bilet(nr,start,sfarsit){}
	float calculeazaCost() {
		return 10.0;
	}
};
int main() {
	ifstream fin("bilete.txt");
	string tip, start, sfarsit;
	int nr;
	Bilet* b = NULL;
	cout << "Tip\t\tNumar\tDurata\tCost" << endl;
	cout << "--------------------------------------------" << endl;
	while (fin >> tip >> nr >> start >> sfarsit) {
		if (tip == "BiletStandard") b = new BiletStandart(nr, start, sfarsit);
		else if (tip == "Abonament") b = new Abonament(nr, start, sfarsit);
		else if (tip == "BiletReducere") b = new BiletReducere(nr, start, sfarsit);
		else if (tip == "BiletTuristic") b = new BiletTuristic(nr, start, sfarsit);

		if (b != NULL) {
			cout << tip << "\t" << nr << "\t" << b->calculeazaDurata() << " min\t" << b->calculeazaCost() << " lei" << endl;
			delete b;
			b = NULL;
		}
	}
	fin.close();
	return 0;
}