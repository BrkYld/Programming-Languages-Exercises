/***********************************************************************************
**                                SAKARYA �N�VERS�TES�
**                       B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                            B�LG�SAYAR M�HEND�SL��� B�L�M�
**                              PROGRAMLAMAYA G�R�� DERS�
**
**                           ��RENC� ADI: BURAK YILDIRIM
**                           ��RENC� NUMARASI:b1612.10037
**                           DERS GRUBU: B 1.��RET�M
**			Belirli Boyut Aral�klar�nda Dikd�rtgen �izen Program
*************************************************************************************/

#include <iostream>	

using namespace std;


int main()
{
	int uzunluk, geni�lik, x, y;

	char istek;

	do
	{
		system("cls");

		cout << "Uzunlugu giriniz: ";

		cin >> uzunluk;

		cout << "Genisligi giriniz: ";

		cin >> geni�lik;

		while (uzunluk > 20 || uzunluk < 0) // D�ng� bu komutu do�ru olarak alg�lad�. Biz d�ng�ye g�re yanl�� de�eri girene kadar devam edecek.
		{

			cout << "Lutfen 1-20 arasinda deger giriniz(uzunluk) : ";

			cin >> uzunluk;

		}

		while (geni�lik > 20 || geni�lik < 0)
		{

			cout << "Lutfen 1-20 arasinda deger giriniz(genislik) : ";

			cin >> geni�lik;

		}


		for (y = 1; y <= uzunluk; y++) //Bu d�ng� uzunluk de�erini ayarlayacak ve k��elerin �ak��mas�n� sa�layacak 
		{
			for (x = 1; x <= geni�lik; x++)
			{
				if (y == 1 || y == uzunluk || x == 1 || x == geni�lik)

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