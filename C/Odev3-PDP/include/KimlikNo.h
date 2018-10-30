#ifndef KIMLIKNO_H
#define KIMLIKNO_H




struct KIMLIKNO
{
	
	int tcNO[11] ;
	
	
};
typedef struct KIMLIKNO* KimlikNo;


KimlikNo tcNoUret();
const char *tcNoKontrol(int[]);




#endif