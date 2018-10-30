/**

*@file  		odev3  
*@description 	Belirtilen dosya yolundaki txt dosyalarını okuyan ve arama,yazdırma islemlerini yapan c++ programi.   
*@course  		1.Öğretim C Grubu  
*@assignment  	3.Ödev 
*@date  		03/12/2017  
*@author  		Burak Yıldırım     	burak.yildirim10@ogr.sakarya.edu.tr
				İbrahim Turan 		mahmut.turan@ogr.sakarya.edu.tr	
*/

#include <iostream>
#include "dugum.hpp"
#include "Agac.hpp"
#include <string.h>

using namespace std;

	class Agac;

	Dugum::Dugum(string _veri)
	{
		veri = _veri;
		sonrakiAdres = NULL;
		sagCocuk = NULL;
		solCocuk = NULL;
		agacKok = NULL;
	}
	Dugum::Dugum()
	{
		sagCocuk = NULL;
		solCocuk = NULL;
		sonrakiAdres = NULL;
		agacKok = NULL;
		ebeveyn = NULL;
		
	}

	string Dugum::veriGoster()
	{
		return veri;
	}

	void Dugum::veriDegistir(string veri_)
	{
		veri = veri_;
	}