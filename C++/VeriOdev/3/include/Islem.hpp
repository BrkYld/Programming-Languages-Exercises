#ifndef ISLEM_HPP
#define ISLEM_HPP
#include<iostream>
#include<dirent.h>
#include"dugum.hpp"
#include"Agac.hpp"
#include"Liste.hpp"
#include<fstream>

 
 using namespace std;

class Islem //main fonksiyonda ilgili islemlerin yapildigi sinif. Tum siniflari birbirine baglar.
{
private:
	
	Liste *a;
	
	
public:

	Islem();//Yapici fonksiyon
	
	void islemleriYap(string konum);//kullanici dosya yolu verdiginde bu fonksiyon cagirilir ve listeleme ve agac olusturma islemlerini baslatir.
	
	void bul(string aranan);//Aranan kelimenin bulunmasi icin gerekli islemleri baslatir.
	
	void yazdir();//ekrana listedeki elemanlari(agaclar da dahil) teker teker yazdirir.
	
	~Islem();//Yikici fonksiyon.
	
};
#endif