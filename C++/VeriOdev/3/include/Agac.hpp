#ifndef AGAC_HPP
#define AGAC_HPP
#include <iostream>
#include "dugum.hpp"
#include <string>


using namespace std;

class Dugum;

class Agac 
{
private:




public:
	
	Dugum *kok ;
	
	Agac();//Yapici fonksiyon
	
	

	void ekle(string veri);//Agaca eleman ekler. Diger fonksiyonlarda kolaylik olsun diye bu cagirilir.
	
	
	
	void ekle(string veri, Dugum *index);//Asiri yüklenmis ekle fonksiyonu.
	
		
	
	Dugum *ara(string veri);//Belirtilen elemani agacta arar.Diger fonksiyonlarda kolaylik olsun diye bu cagirilir.
	
	
	Dugum *ara(string veri, Dugum *index);//Asiri yuklenmis ara fonksiyonu.
	
	void agaciYazdir();//agaci inorder bicimde yazdirir.
	
	void agaciYazdir(Dugum* index);//Asiri yuklenmis agaciYazdir fonksiyonu.
	
	
	void temizle();//Agactaki elemanlari temizler.
	
	
	void temizle(Dugum* index);//Asiri yuklenmis temizle fonksiyonu.
	
	
	~Agac();//Yikici fonksiyon.
	

};

#endif