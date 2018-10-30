#ifndef top_hpp
#define top_hpp

#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;

class Top
{

private :

	string top = "(d-_-b)";
	int renkIndeks = rand() % 14 + 1;
	

public:
	
	
	string topGetir() 
	{
		return top;
	}
	
	void renkBelirle() 
	{
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), renkIndeks);
		
	}
		

		
};
	
	
#endif






