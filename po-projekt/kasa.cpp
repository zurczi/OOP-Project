#include <string>
#include <iostream>
#include "pracownik.hpp"
#include "student.hpp"
#include "programista.hpp"
#include "konto.hpp"
#include <vector>
#include <fstream>
#include "czlowiek.hpp"
using namespace std;
template <class Temp>
class Kasa {
	private:
	vector <Temp*> konta;
	public:

void sumujsaldo(){
			int i;
			float lacznesaldo;
			for (i=0;i<konta.size();i++){
			lacznesaldo+=konta[i]->getsaldo();
			}
			cout <<"\n Saldo kasy wynosi:" <<lacznesaldo;
		};
//dodaj konto 
void dodaj_konto(Temp* nowekonto){
	konta.push_back(nowekonto);
}
//usun konto
void usun_konto(int nrprac){
	int i;
	for (i=0;i!=konta.size();i++){
		if(nrprac==konta[i]->getpracownik()->getnr()){
			if(konta[i]->getsaldo()<0)
			cout<<"Nie mo¿na usun¹æ konta o ujemnym saldzie!";
			else {
			konta.erase(konta.begin()+i);	
			cout<<"Usunieto konto o podanym nr";
			break;}
		}
		
	}
	
	if (i==konta.size()){
		cout<<"Nie znaleziono konta o podanym nr";
	}	

}


void edytuj_konto(int nrprac,float zmiana){
	int i;
	for (i=0;i<konta.size();i++){
		if(nrprac==(konta[i]->getpracownik()->getnr()))
		{
			*konta[i]+=zmiana;
			break;
		}
	}
	if (i==konta.size()){
		cout<<"Nie znaleziono konta o podanym nr";
	}	
}

void stankont(){//wyswietlania
		int i;
		for (i=0;i<konta.size();i++){
			cout<<"\n";
			cout<<konta[i]->getpracownik()->getnr()<<". "<<konta[i]->getpracownik()->getimie()<<" "<<konta[i]->getpracownik()->getnazwisko();
			cout<<" stan konta="<<konta[i]->getsaldo();
		}}
		
void przelew(int komu,int odkogo,float ile){
	try{
	
	int i,komui=-1,odkogoi=-1;
	for(i=0;i!=konta.size();i++){
		if (komu==konta[i]->getpracownik()->getnr())		
				komui=i;
		if(odkogo==konta[i]->getpracownik()->getnr())
		odkogoi=i;
		}
		if (odkogoi==-1 || komui==-1)
		cout<<"Nie znaleziono pracownika";
		else {
	if ((konta[komui]->getpracownik()->getpozyczka()==0 )||( konta[odkogoi]->getpracownik()->getpozyczka()==0)) {
       cout<<"\nStudent nie ma pozwolenia na wykonywanie przelewow\n";}
       else{
		if((konta[odkogoi]->getsaldo())>ile){
				*konta[komui]+=ile;
				*konta[odkogoi]-=ile;
				cout<<"Wykonano przelew\n";
			
			}
			else {
			cout<<"\nNie mozna od tej osoby pozyczyc\n";
	
		}
		}}
		throw 10;}
		catch (int i){
			if(i==10){
			}
		}
		}
		
		
void odczyt(){

		ifstream plik;
		string imie,nazwisko,typ;
		float saldo;
		int nr;
	
		try {
			
			plik.open("dane.txt");
		
			      if (plik.good()) {
                while(!plik.eof()){
                
                    plik >>typ>>imie >> nazwisko>>nr>>saldo;
                    
                    if(plik.eof()) break;
                    if(typ=="programista"){
                    	int pozyczka1=1;
                        programista *nowyprogramista = new programista(imie,nazwisko,nr,pozyczka1);
                        konto *nowekonto = new konto(nowyprogramista,saldo);
                        dodaj_konto(nowekonto);
                    }
                    else if(typ=="student"){
                    	int pozyczka1=0;
                        student *nowystudent = new student(imie,nazwisko,nr,pozyczka1);
                        konto *nowekonto = new konto(nowystudent,saldo);
                        dodaj_konto(nowekonto);
                    }
                }}}
                catch(...){
                	cout<<"Nie uda³o siê otworzyæ pliku";
				}
                plik.close();
			}
			
	void zapis(){
		int i;
	ofstream plik;
	plik.open("dane.txt");
	for(i=0;i<konta.size();i++)	{
	konta[i]->sprawdztyp(plik);	
	}	
	}
};
		

