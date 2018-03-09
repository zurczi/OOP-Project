#ifndef programista_hpp
#define programista_hpp
#include <string>
#include <iostream>
#include "pracownik.h"
#include <fstream>
#include "czlowiek.hpp"
class programista:public pracownik  {
	int pozyczka;
	public:
		programista(string imie1,string naziwsko1,int nr1,int pozyczka1);
void przywitajsie();
	};
		#endif
