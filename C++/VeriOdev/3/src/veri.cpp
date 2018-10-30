/**

*@file  		odev3  
*@description 	Belirtilen dosya yolundaki txt dosyalarını okuyan ve arama,yazdırma islemlerini yapan c++ programi.   
*@course  		1.Öğretim C Grubu  
*@assignment  	3.Ödev 
*@date  		09/12/2017  
*@author  		Burak Yıldırım     	burak.yildirim10@ogr.sakarya.edu.tr
				İbrahim Turan 		mahmut.turan@ogr.sakarya.edu.tr	
*/


#include<iostream>
#include <dirent.h>
#include <string>
#include<string.h>
#include<locale.h>
#include"Agac.hpp"
#include"Liste.hpp"
#include"Islem.hpp"

using namespace std;


	



int main()
{
	
	
	
	DIR *dir;
    struct dirent *ent;
	
	string dosyaYolu ;
	string kelime ; 
	string uzanti ;
	int kontroLindex = 0 ;
	int secim ;
	cout << " DOSYA YOLU(Dosya yolunda Turkce karakter kulanmayiniz): " ;
	cin >> dosyaYolu;
	
	
	
	if ((dir = opendir(dosyaYolu.c_str())) == NULL)//Dosya yolu varmi diye kontrol edilen kisimin baslangici.
	{
		cout << "Dosya Bulunamadi" << endl ;
		system("pause");
		return 0 ;
	}//...Sonu
	while ((ent = readdir(dir)) != NULL) //Dosya yolunda metin belgesi varmi diye kontrol edilen kisimin baslangici.
	{
		
		kelime = ent->d_name ;
		
		if(strlen(kelime.c_str()) >= 5 )
		{
			uzanti = kelime.substr(strlen(kelime.c_str())-4,strlen(kelime.c_str())-1);
		}
		
		if(uzanti == ".txt")
		{
			kontroLindex++;
			
		}
		
		
	}
	
	if(kontroLindex == 0)
	{
			cout << "METIN BELGESI BULUNAMADI " << endl;
			system("pause");
			return 0 ;
			
	}//...Sonu
	
	
	Islem *x = new Islem ;
	x->islemleriYap(dosyaYolu);
	
	do
	{
		
		cout << endl << "1.Arama Yap" << endl << "2.Listele" << endl << "3.Cikis" << endl << "Secim: ";
	
		cin >> secim ;
		
		if(secim == 1)
		{
			cout << "Hangi kelimeyi ariyorsunuz ? : " ;
		
			cin >> kelime ;
		
			x->bul(kelime);
	
		}
		else if(secim == 2)
		{
			
			cout << endl ;
		
			x->yazdir();
		
		}
		else
			break;
	
	
		}while(true);
	
	
		delete x ;
   
		system("pause");
    
		return 0;
	
	
	

	
}
	
	
	
	
	

