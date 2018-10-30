#ifndef KISI_H
#define KISI_H

#include "KimlikNo.h"
#include "Telefon.h"

struct KISI
{
	char isimSoyisim[50];
	int yas;
	KimlikNo kimlik;
	telefon telefon;
};
typedef struct KISI* Kisi ;

	
		
	Kisi kisiOlustur();
	void isimAta(Kisi);
	void yasAta(Kisi);




#endif