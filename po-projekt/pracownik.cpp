#include "pracownik.h"
#include <string>
#include <iostream>
#include "czlowiek.hpp"


pracownik::pracownik(string imie1,string nazwisko1,int nr1,int pozyczka1){
	imie=imie1;
	nazwisko=nazwisko1;
	nr=nr1;
	pozyczka=pozyczka1;
}
pracownik::zapisz(ofstream& plik){
	plik<<imie<<" "<<nazwisko<<" "<<nr;
}

int pracownik::getnr(){
	return nr;
}
string pracownik::getimie(){
	return imie;
}
string pracownik::getnazwisko(){
	return nazwisko;
}
int pracownik::getpozyczka(){
	return pozyczka;
}
