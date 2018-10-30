
/***********************************************************************************
**                                SAKARYA ÜNÝVERSÝTESÝ
**                       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                            BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                              PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**                           ÖÐRENCÝ ADI: BURAK YILDIRIM
**                           ÖÐRENCÝ NUMARASI:b1612.10037
**                           DERS GRUBU: B 1.ÖÐRETÝM
**		 Belirlenen Hýzda ve Karakterde Animasyon Yapan Program
*************************************************************************************/




#include <time.h>	

#include<iostream>

#include<Windows.h>

#include<string>

using namespace std;

enum RENK
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};

void renkYaz(int karakterRenk)
{
	int arkaplan = 0;

	int sonRenk;

	sonRenk = (16 * arkaplan) + karakterRenk;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sonRenk);
}


void yaz(char karakter,RENK renkÝsmi )
{
	renkYaz(renkÝsmi);
	cout << karakter;
	renkYaz(WHITE);
}

int main()
{
	char dizi[100] = { '>','<' };

	char karakter;

	int i = 0;

	int a = 0;
	
	int hiz;

	int boyut;

	cout << "Boyutu giriniz: ";

	cin >> boyut;

	cout << "Karakteri giriniz: ";

	cin >> karakter;

	cout << "Hizi giriniz(1-10 arasi): ";

	cin >> hiz;

// Bu dongu sonsuz kez donerek programin hic kapanmamasini sagliyor.
	while (true)
	{

		system("cls");

		for (int j = 0; j < boyut; j++) // '>' karakterinin hareketini belirleyen dongu.
		{

			if (i == j)
				yaz(dizi[0],LIGHTGREEN);
			else
				yaz(karakter,LIGHTCYAN);
		}

		i++;
		if (i == boyut ) // eger '>' isaretin hareket alani bitmisse demek oluyor.
		{
			
			i = boyut;
			
			while (i > 0) // bu dongu ile i sifirlanana kadar '<' karakteri hareket edecek.
			{
				system("cls");
				for (int a = 0; a < boyut; a++) // '<' karakterinin geriye dogru hareket etmesini saglayan dongu.
				{
					if (i == a + 1)
						yaz(dizi[1],LIGHTGREEN);
					else
						yaz(karakter,LIGHTCYAN);
				}
				
				i--;
				
				Sleep(hiz * 100); // animasyonun gorunur olmasi icin kullanici tarafindan belirlenen hizi 100 ile carpiyor.
				
			}
			
		}
		
		Sleep(hiz * 100);
	}
}















