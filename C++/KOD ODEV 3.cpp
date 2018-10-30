#include<iostream>
#include<Windows.h>
#include<string>
#include<stdlib.h>
#include <time.h>

using namespace std;

char DUZCIZGI = 205;
char SOLUSTKOSE = 201;
char SAGUSTKOSE = 187;
char DIKEYCIZGI = 186;
char ASAGIAYRAC = 203;
char SOLALTKOSE = 200;
char SAGALTKOSE = 188;
char YUKARIAYRAC = 202;


void hucreCiz() 
{
	srand(time(0));
	int sayi[10];

	char karakter[24] = { 'A','B','C','D','E','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Y','Z','X','Q' };

	for (int i = 0; i < 10; i++)
	{
		sayi[i] = rand() % 10;
	}

	int hucreSayisi = 8;
	int i = 0;
	
	cout << SOLUSTKOSE;
	
	while (i < hucreSayisi-1) 
	{
		cout << DUZCIZGI << DUZCIZGI << DUZCIZGI << ASAGIAYRAC;
	
		i++;
	}

	cout << DUZCIZGI << DUZCIZGI << DUZCIZGI << SAGUSTKOSE << endl;

	int j = 0;

	while (j < hucreSayisi) 
	{
		cout << DIKEYCIZGI << " " << sayi[rand()%10] << " ";
	
		j++;
	}
	cout << DIKEYCIZGI << endl;

	int a = 0;
	
	while (a < hucreSayisi) 
	{
		cout << DIKEYCIZGI << " " << karakter[rand()%23] << " ";
	
		a++;
	}

	cout << DIKEYCIZGI << endl << SOLALTKOSE;

	int b = 0;

	while (b < hucreSayisi-1) 
	{
		cout << DUZCIZGI << DUZCIZGI << DUZCIZGI << YUKARIAYRAC;
	
		b++;
	}

	cout << DUZCIZGI << DUZCIZGI << DUZCIZGI << SAGALTKOSE << endl;

}



int main() 
{
	
	hucreCiz();

}