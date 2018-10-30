#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	
	int sayi1 ;
	
	int sayi2 ;
	
	printf("Merhaba, once islem yapmak istediginiz sayilari giriniz.\n" );
	
	printf("1.Sayi : ") ;
	
	scanf("%d",&sayi1);
	
	printf("2.Sayi : ");
	
	
	scanf("%d",&sayi2);
	char tP;
	
	do
	{
		int secim ;
	
	
		printf("Yapmak istediginiz islemi seciniz \n");
		
		printf("1 - Toplama\n" );
		printf("2 - Cikarma\n");
		printf("3 - Carpma\n");
		printf("4 - Bolme\n");
		
		printf("seciminiz = ");
		scanf("%d",&secim);
		
		if(secim == 1)
		{
			printf("Sonuc: ");
			printf("%d",sayi1+sayi2);
			printf("\n");
			printf("Tekrar Secim Yapmak ister misiniz(e/h) : ");
			scanf("%c", &tP);
		}
		else if(secim == 2)
		{
			printf("Sonuc: ");
			printf("%d",sayi1-sayi2);
			printf("\n");
			printf("Tekrar Secim Yapmak ister misiniz(e/h) : ");
			scanf("%c", &tP);
		}
		else if(secim == 3)
		{
			printf("Sonuc: ");
			printf("%d",sayi1*sayi2);
			printf("\n");
			printf("Tekrar Secim Yapmak ister misiniz(e/h) : ");
			scanf("%c", &tP);
		}
		else if(secim == 4)
		{
			printf("Sonuc: ");
			printf("%d",sayi1/sayi2);
			printf("\n");
			printf("Tekrar Secim Yapmak ister misiniz(e/h) : ");
			scanf("%c", &tP);
		}
		else
		{
				printf("Hatali islem yaptiniz. !!! \n");
				printf("Tekrar Secim Yapmak ister misiniz(e/h) : ");
				scanf("%c", &tP);
		}
		
		
		scanf("%c", &tP);
		
		system("CLS");
	
		
	
	
	}while(tP == 'e');
		
	
	
	
	
	
		return 0 ;
	
}