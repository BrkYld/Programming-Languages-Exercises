//Vigenere Sifreleme ornegi

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Sifre 
{
public:
	Sifre(string alfabe, string sifreKelimesi);
	Sifre();

	string sifrele(string);
	string sifrecoz(string);
	void sifreKelimesiAta(string);
	string sifreKelimesiGetir();
	void alfabeAta(string);
	string alfabeGetir();
	

private:
	string alfabe;
	string sifreKelimesi;
};

Sifre::Sifre(string atanacakAlf, string atanacakSif) 
{
	alfabe = atanacakAlf;
	sifreKelimesi = atanacakSif;
}
Sifre::Sifre() 
{
	alfabe = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	sifreKelimesi = "";
}
string Sifre::sifrecoz(string metin)
{
	string uzunSifre;
	string orjMetin;
	stringstream ss, ss2;
	int i = 0;
	int a = 0;
	while (i != metin.length())
	{
		if (a == sifreKelimesi.length()) a = 0;

		ss << sifreKelimesi[a];

		a++;
		i++;
	}
	uzunSifre = ss.str();

	int indis = 0;

	while (true)//sifre cozme isleminin baslamasi.
	{
		if (indis == metin.length()) 
		{
			break;
		}
		i = 0; a = 1;
		while (true)//degerler okunup sayımlar yapiliyor. Bu sayimlara gore sifreli metin geri sardirilacak.
		{
			if (metin[indis] == alfabe[i]) {
				break;
			}
			else i++;
		}
		while (true)
		{
			if (uzunSifre[indis] == alfabe[a-1]) 
			{
				break;
			}
			else a++;

		}

		if (i - a  < 0)
		{
			ss2 << alfabe[i + alfabe.length() - a ];
		}
		else
			ss2 << alfabe[i - a];

		indis++;
	}
	orjMetin = ss2.str();
	return orjMetin;
}
string Sifre::sifrele(string metin)
{
	string uzunSifre;
	string sifrelenmisKelime;
	stringstream ss;
	int i = 0;
	int a = 0;
	while (i != metin.length())//sifrenin girilen metin kadar tekrarlanmasi.
	{
		if (a == sifreKelimesi.length()) a = 0;

		ss << sifreKelimesi[a];

		a++;
		i++;
	}
	uzunSifre = ss.str();

	char vigenereMatris[100][100];//Sifrelemek icin vigerene matrisi olustur.
	for (int i = 0; i < 100; i++) 
	{
		for (int j = 0; j < 100; j++)
		{
			vigenereMatris[i][j] = ' ';
		}
	}
	vigenereMatris[0][0] = ' ';
	a = 0;
	int b = 0;
	for (int i = 0; i < alfabe.length(); i++) //matrise deger atama
	{
		for (int j = 0; j < alfabe.length()+1; j++)
		{
			if (i == 0) 
			{
				if (a == alfabe.length()) a = 0;
				vigenereMatris[i][j + 1] = alfabe[a];
				a++;
			}
			else
			{
				if (b == alfabe.length()) b = 0;
				vigenereMatris[i][j] = alfabe[b];
				b++;
			}
		}
	}
	
	a = 0; b = 0;
	stringstream ss2;
	for (int i = 0; i < metin.length(); i++) //sifreleme isleminin yapildigi dongu
	{
		a = 0; b = 0;
		while (metin[i] != vigenereMatris[0][a]) 
		{
			a++;
		}
		while (uzunSifre[i] != vigenereMatris[b][0])
		{
			b++;
		}
		ss2 << vigenereMatris[a][b];
	}
	sifrelenmisKelime = ss2.str();
	return sifrelenmisKelime;
}
void Sifre::sifreKelimesiAta(string atanacak) 
{
	sifreKelimesi = atanacak;
}
string Sifre::sifreKelimesiGetir() 
{
	return sifreKelimesi;
}
void Sifre::alfabeAta(string atanacak) 
{
	alfabe = atanacak;
}
string Sifre::alfabeGetir()
{
	return alfabe;
}


int main()
{
	Sifre vigenere;
	string alfabe, sifre, kelime, sifreliKelime;
	cout << "Alfabe giriniz :";
	cin >> alfabe;
	for (int i = 0; i < alfabe.length() ; i++) //Alfabede turkce karakter , ozel karakter kontrolu yapiliyor.
	{
			if (vigenere.alfabeGetir().find(alfabe[i],0) > vigenere.alfabeGetir().length() ) 
			{
				cout << "HATALI ALFABE GIRISI";
				return 0;
			}
	}
	vigenere.alfabeAta(alfabe);
	cout << "Sifre giriniz :";
	cin >> sifre;
	for (int i = 0; i < sifre.length(); i++)//Sifre dogrulamasi. Alfabede bulunmayan karakter var mi diye kontrol ediliyor.
	{
		if (vigenere.alfabeGetir().find(sifre[i], 0) > vigenere.alfabeGetir().length())
		{
			cout << "HATALI SIFRE GIRISI";
			return 0;
		}
	}
	vigenere.sifreKelimesiAta(sifre);
	cout << "Sifrelenecek kelimeyi giriniz :";
	cin >> kelime;
	for (int i = 0; i < kelime.length(); i++)//Kelime dogrulamasi. Alfabede bulunmayan karakter var mi diye kontrol ediliyor.
	{
		if (vigenere.alfabeGetir().find(kelime[i], 0) > vigenere.alfabeGetir().length())
		{
			cout << "HATALI KELIME GIRISI";
			return 0;
		}
	}
	cout << "/////////////////////////////////////\n";
	sifreliKelime = vigenere.sifrele(kelime);
	cout << "ALFABE			   :" << vigenere.alfabeGetir() << endl
		 << "SIFRE			   :" << vigenere.sifreKelimesiGetir() << endl
		 << "METIN			   :" << kelime << endl
		 << "SIFRELENMIS METIN          :" << sifreliKelime << endl
		 << "DESIFRE METIN              :" << vigenere.sifrecoz(sifreliKelime) << endl;


	system("pause");
	return 0; 
}

