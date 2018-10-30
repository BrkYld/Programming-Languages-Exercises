
#include "huffman.hpp"
#include "dugum.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	

    
	Huffman* a = new Huffman(); 
	
	a->dosyaOku();
	
	
	delete a ;
	
	
		
	system("pause");
	return 0 ;
}