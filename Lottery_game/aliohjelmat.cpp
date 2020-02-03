#include <iostream>
#include <time.h>
#include "aliohjelmat.h"

using namespace std;



void arvonta(int lottonumerot[], int& lisanumero)										// Aliohjelma arvonta arpoo lottonumerot
{
																				

	lisanumero = (rand() % 39 + 1);														// Arvotaan lisänumero

	for (int i = 0; i < SIZE; i++)														//Arvotaan lottonumerot
	{
		lottonumerot[i] = (rand() % 39 + 1);						
		for (int j = 0; j < i; j++)
		{
			if (lottonumerot[i] == lottonumerot[j] || lottonumerot[i] == lisanumero)	//Tarkistetaan samojen numeroiden varalta
			{
				i--;

				break;

			}
		}
	}


	cout << "lottonumerot: ";															//Tulostetaan lottonumerot
	for (int i = 0; i < SIZE; i++)
	{
		cout << lottonumerot[i] << " ";
	}

	cout << endl;

	cout << "lisanumero: " << lisanumero << endl;			//Tulostetaan lisänumero
	cout << endl;

	
}


void lotto(int yksirivi[])									//Syötetään oma rivi
{

	
	cout << "Anna oma rivi: ";
	
	for (int i = 0; i < SIZEY; i++)
	{
		
		
		cin >> yksirivi[i];
		
	}

	
}

void tulos(int yksirivi[], int lottonumerot[], int& lisanumero)						//Tarkistetaan syötetyn rivin numerot
{
	int laskuri=0;																	//osumalaskurin alustaminen alkuarvoon
	int lisanumerolaskuri=0;														//Lisänumerolaskurin alustaminen alkuarvoon

	for (int i = 0; i < SIZEY; i++)													//Tarkistetaan oman rivin numerot solu kerrallaan										
	{
		for (int j = 0; j < SIZEY; j++)												//Lisää laskuriin, jos oikein
		{
			if (lottonumerot[j] == yksirivi[i])
			{
				laskuri++;

				

			}
		}
		if (lisanumero == yksirivi[i])									//Jos lisänumero oikein, lisää laskuriin
		{
			lisanumerolaskuri++;
		}
	}
	if (laskuri < 4)													//Jos alle 4 oikein, tulostaa "ei voittoa"
	{
		cout << "Tulos: ei voittoa" << endl;
	}

	else																//Muussa tapauksessa tulostaa "voitto"
	{
		cout << "Tulos : voitto " << endl;								
	}
}

void syotettyarvonta(int lottonumerot[], int& lisanumero)				//Aliohjelma, jolla tarkistetaan rivin tarkistuksen toiminta			
{
	cout << "Anna arvottu lottorivi: ";
	
	for (int i = 0; i < SIZE; i++)										//SYötetään haluttu lottorivi
	{
		cin >> lottonumerot[i];
	}
	cout << endl << "Anna arvottu lisanumero: ";
	cin >> lisanumero;													//Syötetään haluttu lisänumero
}

void tarkempitulos(int yksirivi[],int lottonumerot[], int& lisanumero)				//ALiohjelma antaa tarkemman tuloksen
{
	int laskuri = 0;																//Alustetaan laskurit alkuarvoon
	int lisanumerolaskuri = 0;

	for (int i = 0; i < SIZEY; i++)													//Rivin tarkistus solu kerrallaan osumien varalta									
	{
		for (int j = 0; j < SIZEY; j++)
		{
			if (lottonumerot[j] == yksirivi[i])
			{
				laskuri++;															//Lisätään laskuriin, jos osuma

			}
		}
	}
	if (laskuri < 4)																	//Tulostetaan "ei voittoa", jos laskuri alle 4
	{
		cout << "Ei voittoa " << endl;
	}

	else if (laskuri >= 4)													//Muussa tapauksessa laskuri määrä oikein
	{																		//tai laskurin määrä + lisänumerolaskuri
		if (lisanumerolaskuri == 0)
		{
			cout << laskuri << " oikein" << endl;
		}

		if (lisanumerolaskuri == 1)
		{
			cout << laskuri << " + " << lisanumerolaskuri << "oikein" << endl;
		}
	}   
}

void montariviasyotto(int montarivia[RIVIMAX][SIZE], int& laskuri)						//Aliohjelmassa käyttäjä voi syöttää
																						//Yhden tai useamman rivin
{
	int i;																				
	int j;
	
		for (i = 0; i < RIVIMAX; i++)													//Aloitetaan rivien syöttö (max 10 riviä)
		{
			cout << "Anna oma " << laskuri + 1 << ". rivi: ";							//Kysytään käyttäjältä lottoriviä

		


			for ( j = 0; j < SIZE; j++)					
			{
				cin >> montarivia[i][j];												//Otetaan käyttäjän rivi sisään

				if (montarivia[i][0] == 0)												//Kun käyttäjä syöttää 0, lopetetaan rivin tallennus
				{
					break;

				}
					

			}
			if (montarivia[i][0] == 0)													//Lopetetaan rivien kysely
			{
				break;

			}

			laskuri++;											//Lasketaan rivien määrää myöhempää tarkistusta ja tulostamista varten

		}
		

	}
	



void monenrivintarkistus(int montarivia[RIVIMAX][SIZE], int& laskuri, int lottonumerot[], int& lisanumero)	
{
	int temp;
	int lisanumerolaskuri = 0;
	int osumalaskuri = 0;
	
for(int a = 0; a < laskuri; a++){												//Järjestetään numerojärjestykseen
	for (int j = 0; j < SIZE-1; j++) {
		for (int k = 0; k < SIZE-1; k++) {
			if (montarivia[a][k] > montarivia[a][k+1]) {
				
				temp = montarivia[a][k];
				montarivia[a][k] = montarivia[a][k+1];
				montarivia[a][k+1] = temp;
			}
		}
	}
}



for (int i = 0; i < laskuri; i++)								//Käsitellään vain niin monta riviä kuin laskurissa on
{
	cout << i + 1 << ". Kayttajan rivi: ";						//Käyttäjän syöttämien rivien tulostus			
	for (int a = 0; a < SIZE; a++)								
	{
		cout << montarivia[i][a] << " ";

	}

	cout << endl;


	for (int j = 0; j < SIZE; j++)								//Käyttäjän syöttämän rivin numerot
	{



		for (int k = 0; k < SIZE; k++)							//Oikean rivin numerot
		{
			if (lottonumerot[k] == montarivia[i][j])			
			{
				osumalaskuri++;									//Kasvatetaan osumalaskuria, jos käyttäjän syötössä samoja numeroita
			}													//kuin oikeassa rivissä

			if (montarivia[i][j] == lisanumero)					
			{
				lisanumerolaskuri++;							//Kasvatetaan lisänumerolaskuria, jos käyttäjän syötössä sama numero
			}													//kuin oikeassa rivissä

		}
	}


	if (osumalaskuri < 4)
	{
		cout << "Ei voittoa " << endl;											//Jos osumalaskuri on pienempi kuin 4, tulostetaan 
	}																			//"ei voittoa"

	else if (osumalaskuri >= 4)													//Muussa tapauksessa osumalaskurin verran oikein
	{
		if (lisanumerolaskuri == 0)
		{
			cout << osumalaskuri << " oikein" << endl;
		}
		if (lisanumerolaskuri > 0)
		{
			cout << osumalaskuri << " + " << lisanumerolaskuri << " oikein" << endl;		//Jos lisanumerolaskuri suurempi kuin 0
		}																					//Tulostetaan osumalaskurin + lisanumerolaskurin
	}																						//verran oikein
	osumalaskuri = 0;																		//Tuloksen tulostumisen jälkeen nollataan laskurit
	lisanumerolaskuri = 0;
}
}

