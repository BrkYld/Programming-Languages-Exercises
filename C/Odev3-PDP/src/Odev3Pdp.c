/** 
 * 
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * @since 22.04.2018
 * <p>
 * TC kimlik ve IMEI Kontrolü yapan program simulasyonu
 * </p>
 */

#include "KimlikNo.h"
#include "IMEINo.h"
#include "RastgeleKisi.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"


int main()
{
	
	
	srand(time(NULL));
	RastgeleKisi rastgele ;
	
	do
	{
		printf("1 - Rastgele Kisi Uret\n");
        printf("2 - Uretilmis Dosyayi Kontrol Et\n");
        printf("3 - Cikis\n");
        printf("Secim : ");
		
		int secim ;
		scanf("%d",&secim);
		
		if(secim == 1)
		{
			printf("Kac kisi uretilsin ? : ");
            int kisiSayi ;
			scanf("%d",&kisiSayi);
			
			for(int i = 0 ; i < kisiSayi ; i++)
			{
				rastgele = kisiUret();
			}
			
			
		}
		else if(secim == 2)
		{
			FILE* dosya ;
			dosya = fopen("Kisiler.txt" , "r");
			int tc[11] ;
			int imei[15];
			char ch;
			int index ;
			while(!feof(dosya))
			{
				index = 0 ;
				for(int i = 0 ; i < 11 ; i++)
				{
					
					ch = getc(dosya);
					if(ch == EOF)
						break;
						
					tc[i] = ch - '0';
				}
				printf("T.C Kimlik Kontrol\n");
				for(int i = 0 ; i < 11 ; i++)
				{
					
					
					printf("%d",tc[i]);
						
				}
				printf(" ");
				printf(tcNoKontrol(tc));
				printf("\n");
				
				while(true)
				{
					ch = getc(dosya);
					if(ch == ' ')
					{
						index++;
						if(index==5)
						{
							ch = getc(dosya);
							break;
						}
					}
					if(ch == EOF)
						break;
				}
				for(int i = 0 ; i < 15 ; i++)
				{
					ch = getc(dosya);
					if(ch == EOF)
						break;
						
					imei[i] = ch - '0';
					
				}
				printf("IMEI Kontrol\n");
				for(int i = 0 ; i < 15 ; i++)
				{
					
					
					printf("%d",imei[i]);
						
				}
				printf(" ");
				printf(imeiKontrol(imei));
				printf("\n");
				
				
				ch = getc(dosya);
				if(ch =='\0')
					break;
				ch = getc(dosya);
				if(ch == EOF)
					break;
				
					
			}
		}
		else
			break;
		
	}while(true);
	
	system("pause");
	return 0;
}