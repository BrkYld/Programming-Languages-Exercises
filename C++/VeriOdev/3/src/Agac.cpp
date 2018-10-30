/**

*@file  		odev3  
*@description 	Belirtilen dosya yolundaki txt dosyalarını okuyan ve arama,yazdırma islemlerini yapan c++ programi.   
*@course  		1.Öğretim C Grubu  
*@assignment  	3.Ödev 
*@date  		07/12/2017  
*@author  		Burak Yıldırım     	burak.yildirim10@ogr.sakarya.edu.tr
				İbrahim Turan 		mahmut.turan@ogr.sakarya.edu.tr	
				
*/

#include <iostream>
#include <string.h>
#include "Agac.hpp"
#include "dugum.hpp"

	
	
	using namespace std;
	
	
	
	
	class Dugum;
	
	
	
	Agac::Agac()
	{
	kok = NULL;
	}
	

	void Agac::ekle(string veri)
	{
		if(kok == NULL)
		{
		kok = new Dugum();
		kok->veriDegistir(veri);
		}
	

		else 
		{
		ekle(veri,kok);
		}
	
	}
	
	
	void Agac::ekle(string veri, Dugum *index) 
	{ 
		if (strcmp(veri.c_str(), index->veriGoster().c_str()) > 0)
		{ 
			if (index->sagCocuk == NULL) 
			{ 
				index->sagCocuk = new Dugum; 
				index->sagCocuk->veriDegistir(veri); 
				index->sagCocuk->ebeveyn = index ;
				
				
			}
			else 
				ekle(veri, index->sagCocuk); 
		}
		else 
		{ 
			if (index->solCocuk == NULL) 
			{ 
				index->solCocuk = new Dugum; 
				index->solCocuk->veriDegistir(veri); 
				index->solCocuk->ebeveyn = index;
			}
			else 
				ekle(veri, index->solCocuk);
		}
	}
	
	Dugum* Agac::ara(string veri) 
	{ 
		return ara(veri, kok); 
	}
	
	Dugum* Agac::ara(string veri, Dugum *index) 
	{
		if (index == NULL) 
			return NULL; //Eğer gönderilen düğüm boşsa boş dönder
		if (veri == index->veriGoster()) 
			return index; //eğer veri düğümdeki veriye eşitse düğümü dönder.
 
		if (strcmp(veri.c_str(), index->veriGoster().c_str())>0)
		{
			
			return ara(veri, index->sagCocuk); //eğer veri düğümdeki veriden büyükse arama fonksiyonuna veriyi ve sağdaki düğümü gönder.
		}
			
		else 
		{
			
			return ara(veri, index->solCocuk); //eğer büyük değilse ?! yani küçükse. ?! veriyi ve soldaki düğümü gönder.
		}
			
	}
	void Agac::agaciYazdir()
	{
		return agaciYazdir(kok);
	}
	void Agac::agaciYazdir(Dugum* index)
	{
		
		if(index == NULL)
		{
			cout << "" ;
		}
		else
		{
			
			agaciYazdir(index->solCocuk);
			cout << index->veriGoster() << " " ;
			agaciYazdir(index->sagCocuk);
				
		}
		
		
	}
	
	void Agac::temizle()
	{
		temizle(kok);
	}
	
	void Agac::temizle(Dugum* index)
	{
		
		
		Dugum* tutucu ;
		if(index != kok)
		{
			tutucu = index->ebeveyn;
		}
		else
		{
			tutucu = kok;
		}
		
		if(index == NULL)
		{
			cout << "" ;
		}
		else
		{
			if(index->solCocuk != NULL)
			{
				temizle(index->solCocuk);
			}
			else 
			{
				if(index->sagCocuk != NULL)
				{
					temizle(index->sagCocuk);
				}
				else
				{
					
					if(index != kok)
					{
						if(index == tutucu->solCocuk)
						{
						tutucu->solCocuk = NULL;
						}
						else
						{
						tutucu->sagCocuk = NULL ;
						}
					
						delete index;
						temizle(tutucu);
					}
					else 
					{
						delete index;
					}
						
					
				}
				
			}
			
		}
		
		
	}
	
	Agac::~Agac()
	{
		temizle();
	}
