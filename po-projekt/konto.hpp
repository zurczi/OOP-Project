#ifndef konto_hpp
#define konto_hpp
#include <string>
#include <iostream>
#include "pracownik.h"
#include <vector>
#include <fstream>

using namespace std;
class konto {
	private:
	float saldo;
	pracownik *wlasciciel; 
	public: 
	konto(pracownik *man,float saldopoczat);
    konto &operator +=(float zwiekszsaldo);//dodawanie do konta
	konto &operator-=(float zmniejszsaldo);//float wartosc posilku placenie
	void wypiszwlasciciela();
	pracownik* getpracownik();
	sprawdztyp(ofstream &plik);
	float getsaldo();
};
		
		
		
		#endif
