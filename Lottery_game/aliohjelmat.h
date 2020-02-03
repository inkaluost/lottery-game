#pragma once

//M‰‰ritet‰‰n globaalit vakiot

const int SIZE = 7;
const int SIZEY = 7;
const int RIVIMAX = 10;

//Aliohjelmien esittely


void arvonta(int lottonumerot[], int& lisanumero);
void lotto(int yksirivi[]);
void tulos(int yksirivi[], int lottonumerot[], int& lisanumero);
void syotettyarvonta(int lottonumerot[], int& lisanumero);
void tarkempitulos(int yksirivi[], int lottonumerot[], int& lisanumero);
void montariviasyotto(int montarivia[RIVIMAX][SIZE], int& laskuri);
void monenrivintarkistus(int montarivia[RIVIMAX][SIZE], int& laskuri, int lottonumerot[], int& lisanumero);
