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
#include "stdio.h"
#include "stdlib.h"
#include "time.h"



KimlikNo tcNoUret()
{
	
	KimlikNo k;
	k = (KimlikNo)malloc(sizeof(struct KIMLIKNO));
	
	
	for(int i = 0 ; i < 9 ; i++ )
	{
		
		
		k->tcNO[i] = rand()%10;
		
		
		
		if(k->tcNO[0] == 0)
		{
			k->tcNO[0] = rand()%10;
		}
		
	}
	
	k->tcNO[9] = (((k->tcNO[0] + k->tcNO[2] + k->tcNO[4] + k->tcNO[6] + k->tcNO[8])*7 )-(k->tcNO[1] + k->tcNO[3] + k->tcNO[5]+k->tcNO[7])) % 10 ;
    k->tcNO[10] =(k->tcNO[0] + k->tcNO[2] + k->tcNO[4] + k->tcNO[6] + k->tcNO[8] + k->tcNO[1] + k->tcNO[3] + k->tcNO[5]+k->tcNO[7] + k->tcNO[9]) % 10;
	
	
}

const char *tcNoKontrol(int index[])
{
	
	if(index[9] != ((((index[0] + index[2] + index[4] + index[6] + index[8])*7 )-(index[1] + index[3] + index[5]+index[7])) % 10))
	{
		
		return "Gecersiz";
	}
	else if(index[10] != ((index[0] + index[2] + index[4] + index[6] + index[8] + index[1] + index[3] + index[5] + index[7] + index[9]) % 10))
	{
		return "Gecersiz";
	}
	else
	{
		return "Gecerli";
	}
	
	
	
}