#ifndef student_hpp
#define student_hpp
#include <string>
#include <iostream>
#include "pracownik.h"
#include "czlowiek.hpp"
#include <fstream>
class student:public pracownik  {
	private:
		int pozyczka;
	public:
		student(string imie1,string nazwisko1,int nr1,int pozyczka1);
		void przywitajsie();
	};
		#endif
