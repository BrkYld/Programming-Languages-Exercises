/** 
 * 
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * @since 22.04.2018
 * <p>
 * TC kimlik ve IMEI Kontrolü yapan program simulasyonu
 * </p>
 */


#include "RastgeleKisi.h"
#include "stdio.h"
#include "stdlib.h"

RastgeleKisi kisiUret()
{
	RastgeleKisi r ;
	
	r =(RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	r->kisiler = kisiOlustur();
	
	FILE* dosya ;
	dosya = fopen("Kisiler.txt" , "a");
	
	for(int i = 0 ; i < 11 ; i++)
	{
		fprintf(dosya,"%d",r->kisiler->kimlik->tcNO[i]);
	}
	fprintf(dosya," ");
	fprintf(dosya,r->kisiler->isimSoyisim);
	fprintf(dosya," ");
	fprintf(dosya,"%d",r->kisiler->yas);
	fprintf(dosya," ");
	
	for(int i = 0 ; i < 11 ; i++)
	{
		fprintf(dosya,"%d",r->kisiler->telefon->telNO[i]);
	}
	fprintf(dosya," ");
	fprintf(dosya,"(");
	for(int i = 0 ; i < 15 ; i++)
	{
		fprintf(dosya,"%d",r->kisiler->telefon->i->imeiNO[i]);
	}
	fprintf(dosya,")");
	fprintf(dosya,"\n");
	
	
	fclose(dosya);
	
}