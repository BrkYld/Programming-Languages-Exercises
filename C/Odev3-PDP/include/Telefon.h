#ifndef TELEFON_H
#define TELEFON_H

#include "IMEINo.h"

struct TELEFON
{
	int telNO[11];
	ImeiNo i ;
};
typedef struct TELEFON* telefon;

void telNoUret(const telefon);
void telNoAta(const telefon,int[11]);
telefon telefonUret();


#endif