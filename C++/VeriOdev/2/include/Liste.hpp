#ifndef LISTE_HPP
#define LISTE_HPP
#include <iostream>
#include"dugum.hpp"

using namespace std;
class Liste
{
public:

	Dugum* ilkAdres;
	Dugum* sonAdres;

	Liste()
	{
		ilkAdres = NULL;
		sonAdres = NULL;
	}

	Liste(int a)
	{
		Dugum* bas = new Dugum(a);
		ilkAdres = bas;
		sonAdres = bas;
	}

	void sonaEkle(int a)
	{
		if (bosMu() == true) //Liste bosmu degilmi kontrol ediyor.
		{
			ilkAdres = new Dugum(a);
			sonAdres=ilkAdres;
		}
		else
		{
			Dugum* yeniEleman = new Dugum(a);
			sonAdres->sonrakiAdres = yeniEleman;
			sonAdres = yeniEleman;
		}

	}
	void basaEkle(int a)
	{
		if (bosMu() == true) //Liste bosmu degilmi kontrol ediyor.
		{
			ilkAdres = new Dugum(a);
			sonAdres = ilkAdres;
		}
		else
		{
			Dugum* tutucu;
			tutucu = ilkAdres;
			Dugum* yeniEleman = new Dugum(a);
			yeniEleman->sonrakiAdres = tutucu;
			ilkAdres = yeniEleman;
		}

	}

	void bastanCikar()
	{
		if (bosMu() == true) //Liste bosmu degilmi kontrol ediyor.
		{
			cout << " LISTEDE ELEMAN YOK" << endl;
		}
		else
		{
			Dugum* tutucu;
			tutucu = ilkAdres;
			Dugum* silinecekEleman = new Dugum();
			silinecekEleman = tutucu;
			ilkAdres = tutucu->sonrakiAdres;
			delete silinecekEleman;
		}
	}
	void sondanCikar() // Listenin sonundan eleman cikarir.
	{
		Dugum* tutucu = ilkAdres;
		Dugum* silinenEleman = new Dugum();
		if (elemanSayisiHesapla() > 1) {
			while (tutucu->sonrakiAdres->sonrakiAdres != NULL)
			{

				tutucu = tutucu->sonrakiAdres;
			}
			silinenEleman = tutucu->sonrakiAdres;
			tutucu->sonrakiAdres = NULL;
			sonAdres = tutucu;
			delete silinenEleman;
		}


	}

	bool bosMu()
	{
		if (ilkAdres == NULL)
			return true;
		else
			return false;
	}

	int elemanSayisiHesapla()
	{
		int elemanSayi = 1;
		Dugum* tutucu = ilkAdres;
		if (bosMu() == true)
		{
			return 0;
		}

		while (tutucu->sonrakiAdres != NULL)
		{

			elemanSayi++;
			tutucu = tutucu->sonrakiAdres;

		}
		return elemanSayi;
	}
	void elemanDegistir(int index , int yeniVeri)
	{
		if (elemanSayisiHesapla() < index)
		{
			cout << "Eleman Bulunamadi ! " << endl;


		}
		else
		{
			int temp = 0;
			if (bosMu() == false)
			{
				index = elemanSayisiHesapla() - index + 1;
				temp++;
				Dugum* tutucu = ilkAdres;
				while (tutucu->sonrakiAdres != NULL)
				{

					if (temp == index)
					{
						break;
					}
					tutucu = tutucu->sonrakiAdres;

					temp++;
				}
				tutucu->veriDegistir(yeniVeri);

			}
			else
			{
				cout << "LISTEDE ELEMAN YOK " << endl;

			}
		}
	}
	int elemanGetir(int index)
	{

		if (elemanSayisiHesapla() < index)
		{
			cout << "Eleman Bulunamadi ! " << endl;
			return 0;

		}
		else
		{
			int temp = 0;
			if (bosMu() == false)
			{
				index = elemanSayisiHesapla() - index + 1;
				temp++;
				Dugum* tutucu = ilkAdres;
				while (tutucu->sonrakiAdres != NULL)
				{

					if (temp == index)
					{
						break;
					}
					tutucu = tutucu->sonrakiAdres;

					temp++;
				}
				return tutucu->veriGoster();

			}
			else
			{
				cout << "LISTEDE ELEMAN YOK " << endl;
				return 0;
			}
		}

	}

	void tumunuYazdir()
	{
		if (bosMu() == false)
		{
			Dugum* tutucu = ilkAdres;
			while (tutucu->sonrakiAdres != NULL)
			{
				cout << tutucu->veriGoster();
				tutucu = tutucu->sonrakiAdres;
				if (bosMu() == true)
				{
					break;
				}
			}
			cout << tutucu->veriGoster();
			cout << endl;
		}
		else
			cout << "LISTEDE ELEMAN YOK " << endl;

	}

	void tumunuSil()
	{

		Dugum* silinecekEleman = new Dugum();
		silinecekEleman = ilkAdres;
		while (elemanSayisiHesapla() > 1)
		{
			sondanCikar();
		}
		delete silinecekEleman;
		ilkAdres = NULL;
	}

	~Liste()
	{
		tumunuSil();
		delete ilkAdres;

	}



};
#endif
