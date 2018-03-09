#include "konto.hpp"
#include "kasa.cpp"
#include "pracownik.h"
#include "student.hpp"
#include "programista.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "menu.cpp"
#include <fstream>
#include "czlowiek.hpp"
using namespace std;
Kasa <konto> *kasaglowna=new Kasa<konto>();
void nowekonto()
{
	cout<<"Kto bedzie wlascicielem konta?\n 1.programista\n2.student\n";
	int wlasciciel,nr;
	float saldo=0;
	cin>>wlasciciel;
	string imie,nazwisko;
	cout<<"\n";
	cout<<"Do kogo nalezy nowe konto podaj imie i nazwisko i nr pracownika\n";
	cin >>imie>>nazwisko>>nr;
	cout<<"Podaj saldo poczatkowe konta\n";
	cin>>saldo;
	konto *nowekonto;
	student *nowystudent;
	programista *nowyprogramista;
	if(wlasciciel==1){
		int pozyczka1=1;
		nowyprogramista=new programista(imie,nazwisko,nr,pozyczka1);
		nowekonto=new konto(nowyprogramista,saldo);
		cout<<nowyprogramista->getpozyczka();
		kasaglowna->dodaj_konto(nowekonto);
	}
	else {
		int pozyczka1=0;
		nowystudent=new student(imie,nazwisko,nr,pozyczka1);
		nowekonto=new konto(nowystudent,saldo);
		kasaglowna->dodaj_konto(nowekonto);
	}
	cout<<"\nDodano konto\n";
}






int main()
{

	kasaglowna->odczyt();
cout <<"Witamy w kasie\n";
int wybor=0;
do {
	do {
	
		menu();
		cin>>wybor;
			
	}while(wybor<0||wybor>5);
	switch(wybor){
		//1.dodaj konto
		case 1:{
			nowekonto();
			kasaglowna->zapis();
			break;
		}
		//2.usun konto
		case 2:{
			cout<<"\nKogo konto chcesz usuanc?Podaj numer pracownika:\n";
			int nrprac;
			cin>>nrprac;
			kasaglowna->usun_konto(nrprac);
			kasaglowna->zapis();
			break;
		}
		//3.Edytuj saldo konta
		case 3:{
			cout<<"\nKogo saldo konta chcesz edytowac?Podaj numer pracownika\n";
			int nrprac;
			float zmiana;

			cin>>nrprac;
			cout<<"\nJesli chcesz wyplacic podaj ujemna liczbe a jesli wplacic to dodatnia\n";
			cin>>zmiana;
			kasaglowna->edytuj_konto(nrprac,zmiana);
			kasaglowna->zapis();
			break;
		}
		//4.Wykonaj przelew miedzy kontami 
		case 4:{
			int komu,odkogo;
			float ile;
			cout<<"\nKomu chcesz przelac?Podaj nr pracownika.\n";
			cin>>komu;
			cout<<"\nOd kogo chcesz pozyczyc?Podaj nr pracownika\n";
			cin>>odkogo;
			cout<<"\nIle chcesz przelac?\n";
			cin>>ile;
			kasaglowna->przelew(komu,odkogo,ile);
			kasaglowna->zapis();
			break;
		}
		//5.wyswietl stan kasy i salda wszystkich kont
		case 5:{
			cout<<"\n Stan kasy: ";
			kasaglowna->sumujsaldo();
			cout<<"\nStan wszystkich kont\n";
			kasaglowna->stankont();
			kasaglowna->zapis();
			break;
		}
		//wyjdz 
		case 0:{
			
			break;
		}
		
	}
}while (wybor!=0);

return 0;
}
