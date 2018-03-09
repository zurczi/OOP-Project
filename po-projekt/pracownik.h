#ifndef pracownik_h
#define pracownik_h
#include <string>
#include <iostream>
#include "czlowiek.hpp"
#include <fstream>
using namespace std;

class pracownik {
private:
	string imie;
	string nazwisko;
	int nr;
	int pozyczka;
public :
	pracownik(string imie1,string nazwisko1,int nr1,int pozyczka1);
	zapisz(ofstream &plik);
	int getnr();
	string getimie();
	string getnazwisko();
	int getpozyczka();
	virtual void przywitajsie()=0;
	
};


#endif
