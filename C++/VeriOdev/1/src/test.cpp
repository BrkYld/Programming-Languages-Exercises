#include <iostream>
#include "top.h"
#include<string.h>
#include <string>
using namespace std;


int main()
{


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	int diziUzunluk;
	int secim;
	

	cout << "Dizi Uzunlugunu Giriniz : ";

	cin >> diziUzunluk;

	Top **a = new Top*[diziUzunluk];

	for (int i = 0; i < diziUzunluk; i++)
	{

		a[i] = new Top();
	
	}

	do
	{
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "1-" << "Yer degistir ." << endl;
		cout << "2-" << "Diziyi yazdir ." << endl;
		cout << "3-" << "Cikis ." << endl;
		cout << ">>Secim : ";

		cin >> secim;

		if (secim == 1)
		{
			int index1 = 0 ;
			int index2 = 0 ;
			while(true)
			{
				cout << "1.index : "  ;
				cin >> index1 ;
				cout << "2.index : " ;
				cin >> index2 ;
				if(index1 > diziUzunluk-1 || index2 > diziUzunluk-1)
				{
					cout << "Eleman bulunamadi. Lutfen dizinin 1. elemaninin indexini 0 aliniz." << endl;
				}
				else
					break;
			}
			
			
			Top *gecici1;
			Top *gecici2;
			int tutucu1,tutucu2 ;
			for (int i = 0; i < diziUzunluk; i++)
			{
				
				if(i == index1)
				{
					gecici1 = a[i];
					tutucu1 = i ;
				}
				
				if(i == index2)
				{
					gecici2 = a[i];
					tutucu2 = i ;
				}
				
				
				
			

			}
			
				
			a[tutucu1] = gecici2;
			a[tutucu2] = gecici1;
			
			
				
			cout << "Dizi ters cevrildi." << endl;
		}
		else if (secim == 2)
		{
			cout << "Dizideki toplar : " << endl;
			for (int i = 0; i < diziUzunluk; i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "[" << i << "]" << "->";
				a[i]->renkBelirle();
				cout << a[i]->topGetir() << " " << a[i] << endl;

			}
		}
		else if (secim == 3)
		{
			delete[] a;
			break;
		}
			

		else
		{
			cout << "LUTFEN SECIMINIZI GOZDEN GECIRINIZ " << endl;
		}


	} while (true);


	

	return 0;

	system("pause");
}

