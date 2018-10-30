#include "huffman.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "dugum.hpp"

using namespace std;

 
	void Huffman::dosyaOku()
	{
		string satir;
		ifstream dosya("dene.txt");
		
		while (getline(dosya,satir))
		{
			
			
			for(int i = 0 ; i<satir.length() ; i++)
			{
				if(satir[i] == ' ')
				{
					satir[i] = '@' ;
				}
			}
			
			metin = metin + satir;
			
			metin = metin + '>';
			
			
		}
		dosya.close();
		
		frekansHesapla(metin);
		
	}
	void Huffman::frekansHesapla(string _metin)
	{
		Dugum* dugumler[100];
		for(int i = 0 ; i<100 ; i++)
		{
			dugumler[i] = NULL;
		}
		char b[35];
		int index = 0 ;
		int tutucu = 0;
		int diziUzunluk ;
		bool varmi = false;
		for(int i = 0 ; i<35;i++)
		{
			b[i] = 0;
		
		}
		for(int i = 0 ; i < _metin.length() ; i++)
		{
			varmi = false;
			index = 0 ;
			for(int x = 0 ; x < 35 ; x++)
			{
				if(_metin[i] == b[x])
				{
					varmi = true;
				}
				
			}		
		
			for(int c = 0 ; c < _metin.length() ; c++)
			{
				if(varmi)
					break;
			
				if(_metin[i] == _metin[c])
				{
					index++;
				}
				b[tutucu] = _metin[i];		
		
			}
			
			if(b[tutucu] != 0)
			{
				
				dugumler[tutucu] = new Dugum(b[tutucu] , index);
				
				tutucu++;
				
			}
			
			
		}
		
		agacOlustur(dugumler,tutucu);
		
	}
	
	void Huffman::agacOlustur(Dugum* dizi[],int uzunluk)
	{
		int frekTop = 0; 
		Sirala(dizi,uzunluk);
		for(int i = 0 ; i < uzunluk; i++)
		{
			frekTop = dizi[i]->frekansGetir() + frekTop;
		}
		
		int ilkDeger = 0;
		int ikinciDeger = 1;
		while(true)
		{
			
			uzunluk++;
			
			dizi[uzunluk-1] = new Dugum(0,dizi[ilkDeger]->frekansGetir() + dizi[ikinciDeger]->frekansGetir() , dizi[ilkDeger],dizi[ikinciDeger]);
			
			Sirala(dizi,uzunluk);
			
			if(dizi[uzunluk-1]->frekansGetir() == frekTop)
			{
				kok = dizi[uzunluk-1];
				
				break;
			}
			ilkDeger++;
			ilkDeger++;
			ikinciDeger++;
			ikinciDeger++;
			
		}
		
		
		kodlamaYap(kok,"");
		tabloYaz(kok);
		Kodla();
		
		
	}
	
	void Huffman::Sirala(Dugum* dizi[],int uzunluk)
	{
		
		
        Dugum* yedek = new Dugum(' ' , 0);
        for(int k = 0 ;k < uzunluk;k++)
        {
            for(int l=0;l<uzunluk;l++)
            {
                if (dizi[l]->frekansGetir() > dizi[k]->frekansGetir())    
                {                       
                    
                    yedek->sembolDegistir(dizi[l]->sembolGetir());
					yedek->frekansDegistir(dizi[l]->frekansGetir());
					yedek->sol = dizi[l]->sol;
					yedek->sag = dizi[l]->sag;
					dizi[l]->sembolDegistir(dizi[k]->sembolGetir());
					dizi[l]->frekansDegistir(dizi[k]->frekansGetir());
					dizi[l]->sol = dizi[k]->sol;
					dizi[l]->sag = dizi[k]->sag;
					dizi[k]->sembolDegistir(yedek->sembolGetir());
					dizi[k]->frekansDegistir(yedek->frekansGetir());
					dizi[k]->sol = yedek->sol;
					dizi[k]->sag = yedek->sag;
				
                }
				
				
				
            }
				
        }
		
		for(int k = 0 ; k < uzunluk ; k++)
		{
			for(int l = 0 ; l < uzunluk ; l++)
			{
				
				if(dizi[k]->frekansGetir() == dizi[l]->frekansGetir())
				{
					if(dizi[k]->sembolGetir() == 0)
					{
						
						if(k>l)
						{
							yedek->sembolDegistir(dizi[l]->sembolGetir());
							yedek->frekansDegistir(dizi[l]->frekansGetir());
							yedek->sol = dizi[l]->sol;
							yedek->sag = dizi[l]->sag;
							
							dizi[l]->sembolDegistir(dizi[k]->sembolGetir());
							dizi[l]->frekansDegistir(dizi[k]->frekansGetir());
							dizi[l]->sol = dizi[k]->sol;
							dizi[l]->sag = dizi[k]->sag;
							
							dizi[k]->sembolDegistir(yedek->sembolGetir());
							dizi[k]->frekansDegistir(yedek->frekansGetir());
							dizi[k]->sol = yedek->sol;
							dizi[k]->sag = yedek->sag;
							
							
							
								
						}
						
							
							
						
						
					}
				}
				
				
				
			}
			
			
		}
		
		
		
		
		delete yedek;
	}
	
	void Huffman::kodlamaYap(Dugum* _kok ,string kod)
	{
		if(_kok->sag != NULL && _kok->sol != NULL)
		{
			kodlamaYap(_kok->sol,kod+'0');
			kodlamaYap(_kok->sag,kod+'1');
		}
		else
		{
			
			_kok->kod = kod;
		}
		
		
		
	}
	
	void Huffman::tabloYaz(Dugum* _kok)
	{
		fstream dosya ;
		dosya.open("tablo.txt", ios::in | ios::app);
		if(_kok->sag != NULL && _kok->sol != NULL)
		{
			tabloYaz(_kok->sol);
			tabloYaz(_kok->sag);
		}
		else
		{
			dosya << _kok->sembolGetir() << ":" << _kok->kod << endl;
		} 
		
		dosya.close();
	}
	
	void Huffman::Ara(Dugum* _kok , char _karakter)
	{
		
		if(_kok->sag != NULL && _kok->sol != NULL)
		{
			 Ara(_kok->sol,_karakter);
			 Ara(_kok->sag,_karakter);
		}
		else
		{
			if(_kok->sembolGetir() == _karakter)
				aranan = _kok->kod ;
			
			
		} 
		
	}
	
	void Huffman::Kodla()
	{
		fstream dosya ;
		string data;
		dosya.open("kodlar.txt", ios::in | ios::app);
		
		for(int i = 0 ; i < metin.length(); i++)
		{
			Ara(kok,metin[i]);
			dosya << aranan ;
		
		}
		dosya.close();
		
		dosya.open("kodlar.txt");
		
		dosya >> data ;
		if(data.length()%8 == 0 )
		{
	
			sikistir(data);

		}
		else
		{
			while(data.length()%8!=0)
			{
				data = data + "0" ;
			
			}
		
			sikistir(data);
		}		
		
		
		dosya.close();
		remove("kodlar.txt");
	}
	void Huffman::sikistir(string s) //char dizisindeki her elemanin 8 bitini degistirerek dat dosyasinin icine atar.8 byte lik kod dizisi Boylece dat dosyasinin icinde 
						//8 bit olarak saklanmis olur.
	{
  
		char rv [s.length()]; 
		int index = 0 ;
		fstream dosya ;
		dosya.open("Islemler.dat", ios::binary | ios::in | ios::app );
		for(int i = 0 ; i < s.length() ; i++)
		{
			rv[i] = 0;// bitler = 00000000
		}
		for(int i=0; i<s.length(); i++) 
		{
			if(index == s.length())
			{
					break;
			}
			for(int a = 0 ; a < 8 ; a++)
			{
		
				rv[i] <<= 1; // Byte'i sola kaydır. 
				if(s[index] == '1') 
				{ // siradaki bit 1 ise
				rv[i] |= 1; // byte'ın sağına bir bit ekler. // bitler = 00000001
				} 
				index++;
			}
		
			dosya << rv[i];//
	  
		}
   dosya.close();
	}	
	void kodOku()
	{
		ifstream kayit ;
		ifstream dosya ;
		dosya.open("Islemler.dat" , ios::binary);
		string myString = "";
		string satir;
		string okuma ="" ;
		while (getline(dosya,satir))//bilgisayar dat dosyasina gonderdigimiz bitleri ASCII kodlari olarak algilayip bir karsilik ariyor ve notepad gibi programlarla actigimizda // bize bu karsiliklari gosteriyor. Burada dosyayi acip bunlari stringe atiyoruz.
		{
			myString = myString + satir;
		}				
	
	
		for (int i = 0; i < myString.length(); i++)
		{
			okuma = okuma + bitset<8>(myString.c_str()[i]);//her bir elemanin bit karsiliğini (aslinda bizim gonderdigimiz bitler) okuyup stringe ceviriyor.
		}
		
		kayit.open("tablo.txt");
		
		for(int i = 0 ; i<okuma.length() ; i++ )
		{
		
			
			
		}
	
		
		
		kayit.close();
		dosya.close();
		
	}

	
	
	
	
	
	