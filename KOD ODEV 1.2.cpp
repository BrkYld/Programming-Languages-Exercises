/***********************************************************************************
**                                SAKARYA ÜNÝVERSÝTESÝ
**                       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                            BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                              PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**                           ÖÐRENCÝ ADI: BURAK YILDIRIM
**                           ÖÐRENCÝ NUMARASI:b1612.10037
**                           DERS GRUBU: B 1.ÖÐRETÝM
**			Belirli Boyut Aralýklarýnda Dikdörtgen Çizen Program
*************************************************************************************/

#include <iostream>	

using namespace std;


int main()
{
	int uzunluk, geniþlik, x, y;

	char istek;

	do
	{
		system("cls");

		cout << "Uzunlugu giriniz: ";

		cin >> uzunluk;

		cout << "Genisligi giriniz: ";

		cin >> geniþlik;

		while (uzunluk > 20 || uzunluk < 0) // Döngü bu komutu doðru olarak algýladý. Biz döngüye göre yanlýþ deðeri girene kadar devam edecek.
		{

			cout << "Lutfen 1-20 arasinda deger giriniz(uzunluk) : ";

			cin >> uzunluk;

		}

		while (geniþlik > 20 || geniþlik < 0)
		{

			cout << "Lutfen 1-20 arasinda deger giriniz(genislik) : ";

			cin >> geniþlik;

		}


		for (y = 1; y <= uzunluk; y++) //Bu döngü uzunluk deðerini ayarlayacak ve köþelerin çakýþmasýný saðlayacak 
		{
			for (x = 1; x <= geniþlik; x++)
			{
				if (y == 1 || y == uzunluk || x == 1 || x == geniþlik)

					cout << "*";

				else

					cout << " ";
			}

			cout << endl;
		}

		cout << "Tekrar denemek ister misiniz ? (e/h): ";

		cin >> istek;

	} while (istek == 'e');

}