#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>

using namespace std;

class Dugum
{

private:


	int veri;


public:

	Dugum(int _veri)
	{
		veri = _veri;
		sonrakiAdres = NULL;
	}
	Dugum()
	{
		sonrakiAdres = NULL;
	}

	int veriGoster()
	{
		return veri;
	}

	void veriDegistir(int veri_)
	{
		veri = veri_;
	}


	Dugum* sonrakiAdres;




};
#endif
