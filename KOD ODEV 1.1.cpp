/***********************************************************************************
**                                SAKARYA �N�VERS�TES�
**                       B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                            B�LG�SAYAR M�HEND�SL��� B�L�M�
**                              PROGRAMLAMAYA G�R�� DERS�
**
**                           ��RENC� ADI: BURAK YILDIRIM
**                           ��RENC� NUMARASI:b1612.10037
**                           DERS GRUBU: B 1.��RET�M
**           Bir Say�n�n ��indeki Tek Say�lardan Yeni Bir Say� Olu�turan Program
*************************************************************************************/

#include <iostream>

using namespace std;

int main() 
{
	int sayi ;
	
	int ilksayi; //�lk Girilen say� de�erini kaybetmemek i�in yeni bir de�i�ken tan�mlad�m.
	
	cout << "Bir sayi giriniz: ";
	
	cin >> sayi ;

	ilksayi = sayi;
	
	int basamakSayisi = 1; // Basamak say�s� 0 olamayaca�� i�in 1 de�erini atad�m.
	
	//Say� son de�erini 10 veya 10 dan k���k bir de�er alana kadar say�y� 10 a b�lecek ve basamak say�s�n� hesaplayacak
	while (sayi >= 10) 
	{
		sayi = sayi / 10;

		basamakSayisi++;
	}
	
	cout << "Yeni Sayiniz: ";
	
	// Say�n�n basamak say�s�na g�re modunu hesaplayan d�ng�y� ba�latt�m.
	
	for (int i = basamakSayisi-1 ; i >=0 ; i--) 
	{
		int mod=1; 
		
		
		for (int j = 0; j < i; j++) 
		{
			mod = mod * 10;
		}
		
		int tekSayilar = ilksayi / mod;
		
		ilksayi= ilksayi - tekSayilar*mod;
		
		
		
		if ((tekSayilar % 2) != 0) // Tek say�lar�n 2 ile b�l�m�nden kalan 0 de�ilse yazmas�n� s�yleyen komutu olu�turdum.
		{
			cout << tekSayilar;
			
		}
		
	}

			cout << endl;
		
}