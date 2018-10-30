/**

*@file  		odev3  
*@description 	Belirtilen dosya yolundaki txt dosyalarını okuyan ve arama,yazdırma islemlerini yapan c++ programi.   
*@course  		1.Öğretim C Grubu  
*@assignment  	3.Ödev 
*@date  		03/12/2017  
*@author  		Burak Yıldırım     	burak.yildirim10@ogr.sakarya.edu.tr
				İbrahim Turan 		mahmut.turan@ogr.sakarya.edu.tr	

*/
	
	#include "Liste.hpp"
	#include <iostream>
	#include "dugum.hpp"
	#include <string.h>
	
	using namespace std;
	
	Liste::Liste()
	{
		ilkAdres = NULL ;
		sonAdres = NULL;
	}

	void Liste::sonaEkle(string a , string konum)
	{
		if (bosMu() == true) //Liste bosmu degilmi kontrol ediyor.
		{
			ilkAdres = new Dugum(a);
			sonAdres = ilkAdres;
			agacOlustur(konum);
		}
		else
		{
			Dugum* yeniEleman = new Dugum(a);
			sonAdres->sonrakiAdres = yeniEleman;
			sonAdres = yeniEleman;
			agacOlustur(konum);
		}
		

	}
	
	void Liste::sondanCikar() 
	{
		Dugum* tutucu = ilkAdres;
		Dugum* silinenEleman = new Dugum();
		if (elemanSayisiHesapla() > 1) 
		{
			while (tutucu->sonrakiAdres->sonrakiAdres != NULL)
			{

				tutucu = tutucu->sonrakiAdres;
			}
			silinenEleman = tutucu->sonrakiAdres;
			tutucu->sonrakiAdres = NULL;
			sonAdres = tutucu;
			delete silinenEleman->agacKok;
			delete silinenEleman;
		}


	}

	bool Liste::bosMu()
	{
		if (ilkAdres == NULL)
			return true;
		else
			return false;
	}

	int Liste::elemanSayisiHesapla()
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
	
	string Liste::elemanGetir(int index)
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
	
	Dugum* Liste::elemanAdresGetir(int index)
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
				return tutucu ;

			}
			else
			{
				cout << "LISTEDE ELEMAN YOK " << endl;
				return 0;
			}
		}
		
	}

	void Liste::tumunuYazdir()
	{
		if (bosMu() == false)
		{
			Dugum* tutucu = ilkAdres;
			while (tutucu->sonrakiAdres != NULL)
			{
				cout << tutucu->veriGoster()<<endl;
				tutucu = tutucu->sonrakiAdres;
				if (bosMu() == true)
				{
					break;
				}
			}
			cout << tutucu->veriGoster() << endl;
			
		}
		else
			cout << "LISTEDE ELEMAN YOK " << endl;

	}
	void Liste::elemanYerlestir(string konum)
	{
	DIR *dir;
    struct dirent *ent;
	string isim;
	
	string uzanti = "";
	
    if ((dir = opendir(konum.c_str())) == NULL)
	{
		cout << "Dosya Bulunamadi" << endl ;
		
	}
       

    while ((ent = readdir(dir)) != NULL)
	{
		
		isim = ent->d_name ;
		
		if(strlen(isim.c_str()) >= 5 )
		{
			uzanti = isim.substr(strlen(isim.c_str())-4,strlen(isim.c_str())-1);
		}
		
		if(uzanti == ".txt")
		{
			
			sonaEkle(isim,konum);
			
		}
		
		
		
	}
        

    closedir(dir);
	}
	
	void Liste::agacOlustur(string konum) 
	{
		Agac* yeniAgac = new Agac();
		agacaYerlestir(yeniAgac,sonAdres,konum);
		sonAdres->agacKok = yeniAgac;
		
	}
	
	void Liste::agacaYerlestir(Agac *index,Dugum* sonEleman ,string konum) 
	{
		
		
		ifstream dosya1;
		string isim;
		dosya1.open(konum+"\\"+ sonEleman->veriGoster() , std::fstream::in | std::fstream::out | std::fstream::app);
			
		
				while (dosya1 >> isim) 
				{
		
					index->ekle(isim);
					
				
				}
				
	
	}	

	void Liste::tumunuSil()
	{

		Dugum* silinecekEleman = new Dugum();
		silinecekEleman = ilkAdres;
		while (elemanSayisiHesapla() > 1)
		{
			sondanCikar();
		}
		delete silinecekEleman->agacKok;
		delete silinecekEleman;
		ilkAdres = NULL;
	}

	Liste::~Liste()
	{
		tumunuSil();
		delete ilkAdres;

	}
