#ifndef IMEINO_H
#define IMEINO_H

struct IMEINO
{
	
	int imeiNO[15];
	
};
typedef struct IMEINO* ImeiNo;


ImeiNo imeiNoUret();
const char *imeiKontrol(int[]);


#endif