#include <iostream>
#include <time.h>
#include "aliohjelmat.h"


using namespace std;






int main()
{
	int lottonumerot[SIZE];								//Arvottu lottorivi
	int yksirivi[SIZEY];								//Käyttäjän rivi
	int montarivia[RIVIMAX][SIZE];						//Käyttäjän monta riviä
	int lisanumero = 0;									//Lisänumero
	int laskuri = 0;									//Apulaskuri useamman rivin tarkistukseen
	char valinta = '1';									//Valikossa liikkumiseen
	
	srand(time(NULL));
	

	

	while (valinta != 'L' && valinta != 'l')
	{
		cout << "LOTTOPELISIMULAATTORI" << endl;				// Muodostetaan valikko 
		cout << "=====================" << endl;
		cout << endl;
		cout << "Toiminnot:" << endl;
		cout << "1) Oikean lottorivin arvonta" << endl;
		cout << "2) Yhden rivin lotto" << endl;
		cout << "3) Yhden rivin lotto arvotulla tuloksella " << endl;
		cout << "4) Useamman rivin lotto arvotulla tuloksella " << endl;
		cout << "l/L) Lopeta" << endl;
		cout << endl;
		cout << "valintasi: ";
		cin >> valinta;
		cout << endl;

		switch(valinta)															// Valinnan mukaan 
	{													
		case '1': arvonta(lottonumerot, lisanumero);							// Jos valinta on 1, suoritetaan arvonta -aliohjelma
				break;
		case '2': syotettyarvonta(lottonumerot, lisanumero); 
				lotto(yksirivi);
				tulos(yksirivi,lottonumerot, lisanumero);					//Aliohjelma, jossa syötetään ja tarkistetaan oikea rivi ja käyttäjän rivi
				break;
		case '3': cout << "Lottorivi arvottu lisanumeroineen " << endl;
				lotto(yksirivi);
				cout << "Tulos " << endl;
				arvonta(lottonumerot, lisanumero);
				tarkempitulos(yksirivi, lottonumerot, lisanumero);

				break;

		case '4': cout << "Lottorivi arvottu lisanumeroineen " << endl;
				montariviasyotto(montarivia, laskuri);
				cout << "Tulos: " << endl;
				arvonta(lottonumerot, lisanumero);
				monenrivintarkistus(montarivia, laskuri, lottonumerot, lisanumero);
				break;

		case 'l': break;											// Jos arvonta on l tai L ohlema lopetetaan 
		case 'L': break;
		default: 	cout << "Error !!!" << endl;					// Ohlema pyörii kohdassa niin kauan kunnes valinta on 1, l tai L
					cout << "Valitse joko 1,2,l tai L " << endl;

	}
	}

		
	

	
	
	return 0;
}
		

	
		
	


	
	


