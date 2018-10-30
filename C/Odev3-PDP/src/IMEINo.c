/** 
 * 
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * @since 22.04.2018
 * <p>
 * TC kimlik ve IMEI Kontrolü yapan program simulasyonu
 * </p>
 */

#include "IMEINo.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"


ImeiNo imeiNoUret()
{
	ImeiNo i ;
	i = (ImeiNo)malloc(sizeof(struct IMEINO));
	
	int yedek[15];
	int toplam = 0;
	
	
	for(int j = 0 ; j <14 ; j++ )
	{
		
		i->imeiNO[j] = rand()%10;
	
	}
	
	for(int j = 0 ; j < 14 ; j++)
	{
		yedek[j] = i->imeiNO[j];
	}
	
	for(int i = 0 ; i < 14 ; i++)
	{
		if(i%2 !=0 )
		{
			yedek[i] = yedek[i] * 2 ;
		}
	}
	
	for(int i = 0 ; i < 14 ; i++)
    {
          if(yedek[i] >= 10)
          {
            toplam = (yedek[i] % 10) + toplam ;
            yedek[i] = yedek[i] / 10 ;
            toplam = yedek[i] + toplam ;
          }
          else
          {
            toplam = yedek[i] + toplam ;
          }
      
    }
	
	if(toplam % 10 == 0 )
    {
        i->imeiNO[14] = 0 ;
    }
    else
    {
        i->imeiNO[14] = 10 - (toplam % 10) ;
    }
	
}


const char *imeiKontrol(int index[])
{
	int yedek[15];
	int toplam = 0 ;
	int sonRakam;
	
	
		
		for(int i = 0 ; i < 14 ; i++)
		{
			yedek[i] = index[i];
		}
		
		for(int i = 0 ; i < 14 ; i++)
        {
            if(i%2 != 0)
            {
               yedek[i] = yedek[i] * 2 ;
            }
         
        }
		
		for(int i = 0 ; i < 14 ; i++)
        {
            if(yedek[i] >= 10)
            {
                toplam = (yedek[i] % 10) + toplam ;
                yedek[i] = yedek[i] / 10 ;
                toplam = yedek[i] + toplam ;
            }
            else
            {
                toplam = yedek[i] + toplam ;
            }
      
        }
		
		if(toplam % 10 == 0 )
        {
            sonRakam = 0 ;
        }
        
		else
        {
            sonRakam = 10 - (toplam % 10) ;
        }
		
		
		if(index[14] == sonRakam )
        {
              return "Gecerli";
        }
        
		else
              return "Gecersiz";
		  
		  
		  
		
	
	
}





























