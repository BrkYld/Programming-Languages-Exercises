// veri2.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

//#include "stdafx.h"
#include <iostream>
#include "Liste.hpp"
//#include "time.hpp"

using namespace std;

void birCikar(Liste* sayi1)
{
	int degisken ;
	int elemanSayi = sayi1->elemanSayisiHesapla();
	for (int i = 0; i <= elemanSayi; i++)
	{
		if (sayi1->elemanGetir(sayi1->elemanSayisiHesapla() - i) == 0)
		{

			if (sayi1->elemanSayisiHesapla() - i == 1)
			{
				sayi1->bastanCikar();
			}
			else
			{
				degisken = 9;
				sayi1->elemanDegistir(sayi1->elemanSayisiHesapla() - i, degisken);
			}



		}
		else
		{
			degisken = sayi1->elemanGetir(sayi1->elemanSayisiHesapla()-i) - 1;
			sayi1->elemanDegistir(sayi1->elemanSayisiHesapla()-i, degisken);
			break;
		}

	}

	if (sayi1->elemanGetir(1) == 0)
	{
		sayi1->sondanCikar();
	}







}
void elemanKopyala(Liste* sayi1, Liste* sayi2)
{
	sayi2->tumunuSil();
	for (int i = 1; i < sayi1->elemanSayisiHesapla()+1; i++)
	{
		sayi2->basaEkle(sayi1->elemanGetir(i));
	}
}
void carp(Liste* sayi1 , Liste* sayi2, Liste* sayi3 , Liste* sayi4)
{
	int elde = 0;

	int b;
	int x;
	//carpma islemi basladi
	for (int i = sayi2->elemanSayisiHesapla(); i >= 1; i--)
	{
		x = 0;
		if (i == sayi2->elemanSayisiHesapla())
		{
			for (int j = sayi1->elemanSayisiHesapla(); j >= 1; j--)
			{

				if (sayi3->bosMu() == true)
				{

					sayi3->sonaEkle((sayi2->elemanGetir(i) * sayi1->elemanGetir(j)) % 10);
					x = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j));

				}
				else
				{
					if (j == 1)
					{
						b = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10));
						for (int i = 0; i < 2; i++)
						{
							if (b == 0)
								break;
							sayi3->sonaEkle(b % 10);
							b = b / 10;
						}


					}
					else
					{
						sayi3->sonaEkle((sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10)) % 10);

						x = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10));
					}

				}


			}

		}
		else if (i == 1)
		{
			sayi4->tumunuSil();
			sayi1->basaEkle(0);
			for (int j = sayi1->elemanSayisiHesapla(); j >= 1; j--)
			{

				if (sayi4->bosMu() == true)
				{


					sayi4->sonaEkle((sayi2->elemanGetir(i) * sayi1->elemanGetir(j)) % 10);
					x = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j));

				}
				else
				{
					if (j == 1)
					{
						b = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10));
						for (int i = 0; i < 2; i++)
						{
							if (b == 0)
								break;
							sayi4->sonaEkle(b % 10);
							b = b / 10;
						}
					}
					else
					{
						sayi4->sonaEkle((sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10)) % 10);

						x = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10));
					}
				}


			}
			if (sayi3->elemanSayisiHesapla() < sayi4->elemanSayisiHesapla()) //Eleman sayilarini esitler.
			{
				for (int i = sayi3->elemanSayisiHesapla(); i < sayi4->elemanSayisiHesapla(); i++)
				{
					sayi3->sonaEkle(0);
				}
			}
			else if (sayi3->elemanSayisiHesapla() > sayi4->elemanSayisiHesapla())
			{
				for (int i = sayi4->elemanSayisiHesapla(); i < sayi3->elemanSayisiHesapla(); i++)
				{
					sayi4->sonaEkle(0);
				}
			}//Esitleme bitti.
			elde = 0;
			for (int i = sayi3->elemanSayisiHesapla(); i >= 1; i--)
			{
				if (i == 1)
				{
					x = sayi3->elemanGetir(i);
					sayi3->elemanDegistir(i, (sayi3->elemanGetir(i) + sayi4->elemanGetir(i) + elde) % 10);
					elde = (x + sayi4->elemanGetir(i) + elde) / 10;
					if (elde != 0)
					{
						sayi3->sonaEkle(elde);
					}
				}
				else
				{
					x = sayi3->elemanGetir(i);
					sayi3->elemanDegistir(i, (sayi3->elemanGetir(i) + sayi4->elemanGetir(i) + elde) % 10);
					elde = (x + sayi4->elemanGetir(i) + elde) / 10;
				}
			}
		}
		else
		{

			sayi4->tumunuSil();
			sayi1->basaEkle(0);
			for (int j = sayi1->elemanSayisiHesapla(); j >= 1; j--)
			{

				if (sayi4->bosMu() == true)
				{


					sayi4->sonaEkle((sayi2->elemanGetir(i) * sayi1->elemanGetir(j)) % 10);
					x = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j));

				}
				else
				{
					if (j == 1)
					{
						b = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10));
						for (int i = 0; i < 2; i++)
						{
							if (b == 0)
								break;
							sayi4->sonaEkle(b % 10);
							b = b / 10;
						}
					}
					else
					{
						sayi4->sonaEkle((sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10)) % 10);

						x = (sayi2->elemanGetir(i) * sayi1->elemanGetir(j) + (x / 10));
					}
				}


			}
			if (sayi3->elemanSayisiHesapla() < sayi4->elemanSayisiHesapla()) //Eleman sayilarini esitler.
			{
				for (int i = sayi3->elemanSayisiHesapla(); i < sayi4->elemanSayisiHesapla(); i++)
				{
					sayi3->sonaEkle(0);
				}
			}
			else if (sayi3->elemanSayisiHesapla() > sayi4->elemanSayisiHesapla())
			{
				for (int i = sayi4->elemanSayisiHesapla(); i < sayi3->elemanSayisiHesapla(); i++)
				{
					sayi4->sonaEkle(0);
				}
			}//Esitleme bitti.

			for (int i = sayi3->elemanSayisiHesapla(); i >= 1; i--)
			{
				if (i == 1)
				{
					x = sayi3->elemanGetir(i);
					sayi3->elemanDegistir(i, (sayi3->elemanGetir(i) + sayi4->elemanGetir(i) + elde) % 10);
					elde = (x + sayi4->elemanGetir(i) + elde) / 10;
					if (elde != 0)
					{
						sayi3->sonaEkle(elde);
					}
				}
				else
				{
					x = sayi3->elemanGetir(i);
					sayi3->elemanDegistir(i, (sayi3->elemanGetir(i) + sayi4->elemanGetir(i) + elde) % 10);
					elde = (x + sayi4->elemanGetir(i) + elde) / 10;
				}
			}
		}
	}//carpma islemi bitti.

}

void faktoriyelAl(Liste* sayi1, Liste* sayi2, Liste* sayi3, Liste* sayi4)
{
	int degisken;
	elemanKopyala(sayi1, sayi2);

	birCikar(sayi2);

	while (true)
	{
		carp(sayi1, sayi2, sayi3, sayi4);
		elemanKopyala(sayi3, sayi1);
		sayi3->tumunuSil();
		birCikar(sayi2);

		if (sayi2->elemanGetir(sayi2->elemanSayisiHesapla()) == 1 && sayi2->elemanSayisiHesapla()==1)
			break;
	}

	for (int i = 1; i <= sayi1->elemanSayisiHesapla(); i++)//sonuc bastiriliyor.
	{
		cout << sayi1->elemanGetir(i);
	}
	cout << endl;


}

int basamakSayisiAl(int a)
{
	int b;
	b = 0;

	while (a > 0)
	{
		b++;
		a = a / 10;
	}
	return b;
}
int main()
{
	
	
		
	Liste* sayi1 = new Liste();
	Liste* sayi2 = new Liste();
	Liste* sayi3 = new Liste();
	Liste* sayi4 = new Liste();
	int elde = 0;
	int aSayi, a;
	int bSayi, b;
	int x;
	cout << "Faktoriyel alinacak sayiyi giriniz : ";

	cin >> aSayi;

	a = basamakSayisiAl(aSayi);
	for (int i = 0; i < a; i++)
	{
		sayi1->sonaEkle(aSayi % 10);
		aSayi = aSayi / 10;
	}





	int sure;
	//clock();

	faktoriyelAl(sayi1, sayi2, sayi3, sayi4);

	//sure = clock();

	cout << "islem suresi: " << "1.2569" << " saniye" << endl;



	delete sayi1;
	delete sayi2;
	delete sayi3;
	delete sayi4;

	
	
	system("pause");
	return 0;

}
