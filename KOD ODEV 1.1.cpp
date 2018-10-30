/***********************************************************************************
**                                SAKARYA ÜNÝVERSÝTESÝ
**                       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                            BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                              PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**                           ÖÐRENCÝ ADI: BURAK YILDIRIM
**                           ÖÐRENCÝ NUMARASI:b1612.10037
**                           DERS GRUBU: B 1.ÖÐRETÝM
**           Bir Sayýnýn Ýçindeki Tek Sayýlardan Yeni Bir Sayý Oluþturan Program
*************************************************************************************/

#include <iostream>

using namespace std;

int main() 
{
	int sayi ;
	
	int ilksayi; //Ýlk Girilen sayý deðerini kaybetmemek için yeni bir deðiþken tanýmladým.
	
	cout << "Bir sayi giriniz: ";
	
	cin >> sayi ;

	ilksayi = sayi;
	
	int basamakSayisi = 1; // Basamak sayýsý 0 olamayacaðý için 1 deðerini atadým.
	
	//Sayý son deðerini 10 veya 10 dan küçük bir deðer alana kadar sayýyý 10 a bölecek ve basamak sayýsýný hesaplayacak
	while (sayi >= 10) 
	{
		sayi = sayi / 10;

		basamakSayisi++;
	}
	
	cout << "Yeni Sayiniz: ";
	
	// Sayýnýn basamak sayýsýna göre modunu hesaplayan döngüyü baþlattým.
	
	for (int i = basamakSayisi-1 ; i >=0 ; i--) 
	{
		int mod=1; 
		
		
		for (int j = 0; j < i; j++) 
		{
			mod = mod * 10;
		}
		
		int tekSayilar = ilksayi / mod;
		
		ilksayi= ilksayi - tekSayilar*mod;
		
		
		
		if ((tekSayilar % 2) != 0) // Tek sayýlarýn 2 ile bölümünden kalan 0 deðilse yazmasýný söyleyen komutu oluþturdum.
		{
			cout << tekSayilar;
			
		}
		
	}

			cout << endl;
		
}