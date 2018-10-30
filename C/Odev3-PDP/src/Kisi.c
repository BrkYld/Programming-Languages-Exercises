/** 
 * 
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * @since 22.04.2018
 * <p>
 * TC kimlik ve IMEI Kontrolü yapan program simulasyonu
 * </p>
 */


#include "Kisi.h" 
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

void isimAta(Kisi ki)
{
	
	FILE* dosya ;
	
	
	dosya = fopen("random_isimler.txt" , "r");
	
	int index = rand() % 3000;
       
	   if(index == 0)
	   {
		  index = 254;
	   }
	
	int i = 0;
	char *str,*str2;
	
	char c[50];
	
	while(!feof(dosya))
	{
	
		str = fgets(c,50,dosya);
		
		
		if(i == index)
		{
			
				str2 = strtok(c,"\n");
				strcpy(ki->isimSoyisim,str2);
				
			
			
			fclose(dosya);
			
			
			
			break;
		}
		
		i++;
	
	}
	
	
}

void yasAta(Kisi ka)
{
	
	int _yas = rand() % 100 ;
	ka->yas = _yas ;
	
}

Kisi kisiOlustur()
{
	Kisi k ;
	k = (Kisi)malloc(sizeof(struct KISI));
	isimAta(k);
	yasAta(k);
	k->telefon = telefonUret();
	k->kimlik = tcNoUret();
}

	
           
	