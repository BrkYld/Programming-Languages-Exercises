#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
#include<string>
using namespace std;

class Dugum
{
	
private:

int frekans ;
char sembol;	


public:
	string kod;
	Dugum* sag;
	
	Dugum* sol;
	
	Dugum(char karakter , int _frekans , Dugum* _sag = NULL , Dugum* _sol = NULL);
	
	int frekansGetir();
	
	char sembolGetir();
	
	void frekansDegistir(int _frekans);//frekansi bir artirir.
	
	void sembolDegistir(char _sembol);//sembolu degistirir.
	
	
	
	
	
};
#endif








































