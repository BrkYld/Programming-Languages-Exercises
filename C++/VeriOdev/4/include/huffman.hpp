#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <string>
#include "dugum.hpp"
using namespace std ;

	class Huffman
	{
		private:
			string metin;
			
		public:
			string aranan;
			Dugum* kok;
			void dosyaOku();// deneme.txt nin icindeki dosyayi okur ve tek satira indirger.
			void frekansHesapla(string _metin);
			void agacOlustur(Dugum* dizi[] , int uzunluk);
			void Sirala(Dugum* dizi[],int uzunluk);
			void kodlamaYap(Dugum* _kok,string kod);
			void tabloYaz(Dugum* _kok);
			void Ara(Dugum* _kok , char _karakter);
			void Kodla();
			void sikistir(string s);
	};


#endif







































