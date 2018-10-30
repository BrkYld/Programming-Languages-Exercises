/**

*@file  		odev3  
*@description 	Belirtilen dosya yolundaki txt dosyalarını okuyan ve arama,yazdırma islemlerini yapan c++ programi.   
*@course  		1.Öğretim C Grubu  
*@assignment  	3.Ödev 
*@date  		08/12/2017  
*@author  		Burak Yıldırım     	burak.yildirim10@ogr.sakarya.edu.tr
				İbrahim Turan 		mahmut.turan@ogr.sakarya.edu.tr	
*/


#include<iostream>
#include<dirent.h>
#include"Agac.hpp"
#include"Liste.hpp"
#include<fstream>
#include"Islem.hpp"

using namespace std;



	Islem::Islem()
	{
		a = new Liste();
	}
	
	
	void Islem::islemleriYap(string konum)
	{
		a->elemanYerlestir(konum);
		
	}
	
	void Islem::bul(string aranan)
	{
		
		for(int i = 1 ; i < a->elemanSayisiHesapla()+1;i++)
		{
			if(a->elemanAdresGetir(i)->agacKok->ara(aranan) != NULL)
			{
				cout << "Aradiginiz kelime " << a->elemanAdresGetir(i)->veriGoster() << " dosyasinda bulundu" << endl ;
			}
			else 
			{
				cout << "Aradiginiz kelime " << a->elemanAdresGetir(i)->veriGoster() << " dosyasinda bulunamadi" << endl ;
			}
				
		}
		
		
	}
	
	
	
	void Islem::yazdir()
	{
		
		for(int i = 1; i < a->elemanSayisiHesapla()+1;i++)
		{
			cout << a->elemanGetir(i) << ":" << endl ;
			a->elemanAdresGetir(i)->agacKok->agaciYazdir() ;
			cout << endl ;
		}
		
	}
			
			
		
		
		
		
	Islem::~Islem()
	{
		delete a;
	}