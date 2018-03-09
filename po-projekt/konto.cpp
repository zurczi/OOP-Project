
#include "konto.hpp"
#include "pracownik.hpp"
#include "czlowiek.hpp"
#include <iostream>
#include <string>



using namespace std;

konto::konto(pracownik *man,float saldopoczat){
	wlasciciel=man;
	saldo=saldopoczat;
}
void konto::wypiszwlasciciela(){
	cout<<wlasciciel->getimie()<<" "<<wlasciciel->getnazwisko();
}
//dodawanie do konta salda
konto &konto::operator+=(float zwiekszsaldo){
	this->saldo+=zwiekszsaldo;
}	
//placenie
konto &konto::operator-= (float zmniejszsaldo){
	this->saldo-=zmniejszsaldo;
}
pracownik* konto::getpracownik(){
	return wlasciciel;
}

konto::sprawdztyp(ofstream &plik){
	if (wlasciciel->getpozyczka()==0) {
		plik<<"student ";
       wlasciciel->zapisz(plik);
    }
    else if(wlasciciel->getpozyczka()==1) {
    	plik<<"programista ";
       wlasciciel->zapisz(plik);
    }
plik<<" ";
   plik << saldo;
       plik<<"\n";
}
float konto::getsaldo(){
	return saldo;
}

