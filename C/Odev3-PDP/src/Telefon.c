/** 
 * 
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * @since 22.04.2018
 * <p>
 * TC kimlik ve IMEI Kontrolü yapan program simulasyonu
 * </p>
 */

#include "Telefon.h"
#include "time.h"
#include "stdio.h"
#include "stdlib.h"

void telNoUret(telefon t)
{
	
	
	
	
	t->telNO[0] = 0 ;
    t->telNO[1] = 5 ;
        
	while(true)
    {
        if(6 > t->telNO[2] && t->telNO[2] > 2  )
            break;
        else
            t->telNO[2] = rand() % 10 ;
    }
        
	t->telNO[3] = rand() % 10 ;
        
	for(int i = 4 ; i < 11 ; i++ )
    {
        
		t->telNO[i] = rand() % 10 ;
		
    }
	
}

void telNoAta(const telefon t , int index[11])
{
	for(int i = 0 ; i < 11 ; i++)
	{
		
		t->telNO[i] = index[i];
		
	}
	
	
	
}

telefon telefonUret()
{
	telefon t ;
	t=(telefon)malloc(sizeof(struct TELEFON));
	telNoUret(t);
	t->i = imeiNoUret();
	
}