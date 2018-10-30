
#include "dugum.hpp"
#include <iostream>

#include <string.h>

using namespace std ;


	Dugum::Dugum(char karakter , int _frekans , Dugum* _sag, Dugum* _sol)
	{
		sag = _sag;
		sol = _sol;
		frekans = _frekans ;
		sembol = karakter;
		kod = "";
	}
	
	
	int Dugum::frekansGetir()
	{
		return frekans;
	}
	
	char Dugum::sembolGetir()
	{
		return sembol;
	}
	
	void Dugum::frekansDegistir(int _frekans)
	{
		frekans = _frekans;
	}
	
	void Dugum::sembolDegistir(char _sembol)
	{
		sembol = _sembol ;
	}