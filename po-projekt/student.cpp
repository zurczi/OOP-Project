#include "student.hpp"
#include "pracownik.hpp"
#include "czlowiek.hpp"



student::student(string imie1,string nazwisko1,int nr1,int pozyczka1):pracownik(imie1,nazwisko1,nr1,pozyczka1){
}

void student::przywitajsie(){
	cout<< "Siema";
}
