#ifndef LISTE_HPP
#define LISTE_HPP
#include <iostream>
#include"dugum.hpp"
#include"Agac.hpp"
#include<string>
#include<dirent.h>
#include<fstream>

using namespace std;

class Liste //Liste islemlerinin yapildigi sinif.
{
public:

	Dugum* ilkAdres ;
	Dugum* sonAdres	;

	Liste();//Yapici fonksiyon
	
	void sonaEkle(string a , string konum);//Listenin sonuna eleman ekler.
	
	void sondanCikar();//Listenin sonundan eleman cikarir. 
	
	bool bosMu();//Liste bosmu diye kontrol eder.
	
	int elemanSayisiHesapla();//Listenin eleman sayisini hesaplar.
	
	
	string elemanGetir(int index);//Listeden istenilen elemani getirir.
	
	
	Dugum* elemanAdresGetir(int index);//Listeden istenilen elemanin adresini dondurur.
	

	void tumunuYazdir();//Listedeki elemanlari ekrana yazar.
	
	void elemanYerlestir(string konum);//Belirtilen konumdaki dosya isimlerini listeye ekler.
	
	
	void agacOlustur(string konum); //Bir agac olusturur ve listedeki gerekli dugume baglar.
	
	
	void agacaYerlestir(Agac *index,Dugum* sonEleman ,string konum);//Agacin bagli oldugu dugumun dosyasini acar ve kelimeleri agaca ekler.
	
	void tumunuSil();//Listeyi temizler.
	
	~Liste();//Yikici fonksiyon.
	



};
#endif
