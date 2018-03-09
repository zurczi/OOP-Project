#include <string>
#include <iostream>
#include "pracownik.hpp"
#include "programista.hpp"
#include "czlowiek.hpp"

programista::programista(string imie1,string nazwisko1,int nr1,int pozyczka1):pracownik(imie1,nazwisko1,nr1,pozyczka1){
}
void programista::przywitajsie(){
	cout<<"Dzieñ dobry";
}
