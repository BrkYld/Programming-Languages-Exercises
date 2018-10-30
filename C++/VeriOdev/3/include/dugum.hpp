#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
#include <string>
#include"Agac.hpp"

using namespace std;

class Agac;

class Dugum
{

private:

	
	string veri;
	
	

public:

	Dugum* sonrakiAdres;
	Dugum* sagCocuk;
	Dugum* solCocuk;
	Agac* agacKok; //Dugumun agac nesnesi ile baglantisi.
	Dugum* ebeveyn; //Agacdaki elemanlari silme isleminde ise yarayacak ;
	
	Dugum(string _veri);//Asiri yuklenmis yapici fonksiyon.
	
	Dugum();//Yapici fonksiyon.
	

	string veriGoster();//Dugumun tuttugu veriyi donderir.
	

	void veriDegistir(string veri_);//Dugumun icindeki veriyi degistirir.
	


	




};
#endif
