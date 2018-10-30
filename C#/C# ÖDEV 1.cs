
/***********************************************************************************
**                                SAKARYA �N�VERS�TES�
**                       B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**                            B�LG�SAYAR M�HEND�SL��� B�L�M�
**                           NESNEYE DAYALI PROGLAMLAMA DERS�
**                             2016 - 2017 BAHAR D�NEM�
**
**                           ��RENC� ADI: BURAK YILDIRIM
**                           ��RENC� NUMARASI:b1612.10037
**                           DERS GRUBU: B 1.��RET�M
**		             Matris ve String �slemleri Yapabilen C# Program�
*************************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Odev1
{

    class Matris
    {
        public void matrisIslemler()

        {
            string Satir;

            Console.WriteLine(".::Matris Islemleri Menusu::.");

            Console.WriteLine("Matrisin satir sayisini giriniz(1 ile 10 arasi olmali):...");

            Satir = Console.ReadLine();

            Console.Clear();

            Console.WriteLine(".::Matris Islemleri Menusu::.");

            int Satir�nt = Convert.ToInt32(Satir);

            string [] Degerler = new string[100]; // Satir sayisi sinirindan dolayi en fazla 100 elemanli olacaktir.

            if( Satir�nt < 10 && Satir�nt > 0)
            {

                int indis = 0;
                
                Console.WriteLine("Matris Degerlerini Giriniz ");
                
                for (var i = 1; i < Satir�nt + 1; i++)// Matrisin Satir ve Sutun degerlerini kullanicidan alan dongu.
                {
                    for (var j = 1; j < Satir�nt + 1; j++)

                    {

                        Console.WriteLine("[" + i + "," + j + "]" + "="  );

                        Degerler[indis] = Console.ReadLine();

                        ++indis;

                    }

                }

                Console.Clear();

                Console.WriteLine(".::Matris Islemleri Menusu::.");

                indis = 0;
                
                for (var i = 1; i < Satir�nt + 1; i++)// Matrisin Satir ve Sutun degerlerini yazdiran dongu (�rn. [1,6] = 8)
                {
                    for (var j = 1; j < Satir�nt + 1; j++)
                    {

                         Console.WriteLine("[" + i + "," + j + "]" + "=" + Degerler[indis] + "\n");

                        ++indis;

                    }

                }
                
                int c = 0;

                for ( var a = 0; a < Satir�nt  ; a++)// Matrisi Yazdiran Dongu
                {

                    for( var b = 0; b < Satir�nt; b++)
                    {
                        Console.Write(Degerler[c] + " ");

                        ++c;
                    }

                    Console.Write("\n");

                }

                string secim ;

                Console.Write(" 1 - Satir En Buyuk" + "\n" + " 2 - Satir Toplam" + "\n");

                Console.Write(" Seciminiz : ");

                secim = Console.ReadLine();

                int secim�nt = Convert.ToInt32(secim);

                int[] Degerler�nt = new int[100];

                for (var a = 0; a < Satir�nt * Satir�nt; a++) // string tanimli kullanici girdilerini teker teker int e donusturur.
                {

                    Degerler�nt[a] = Convert.ToInt32(Degerler[a]);

                }

                if (secim�nt == 1)
                {

                    c = Satir�nt; // Bu de�i�keni sadece parametre olarak kullan�yorum.

                    int d = 0;

                    int e = Satir�nt - 1;

                    int[] satirBuyuk = new int[10];

                    for (var a = 0; a < Satir�nt * Satir�nt + 1; a = a + Satir�nt)
                    {

                        Array.Sort(Degerler�nt, a, c);

                        satirBuyuk[d] = Degerler�nt[e];

                        ++d;

                        e = e + Satir�nt;
                    }

                    Console.WriteLine("Sonucunuz : ");

                    for (var a = 0; a < Satir�nt; a++)
                    {

                        Console.Write(satirBuyuk[a] + " ");

                    }

                }

                else if (secim�nt == 2)
                {

                    int[] satirToplam = new int[10];

                    int d = 0;

                    int e = 0;

                    for (var a = 0; a < Satir�nt; a++)
                    {
                        for (var i = 0; i < Satir�nt; i++)

                        {
                            satirToplam[d] = satirToplam[d] + Degerler�nt[e];
                            e++;
                        }

                        d++;
                    }

                    Console.WriteLine("Sonucunuz : ");

                    for (var a = 0; a < Satir�nt; a++)
                    {
                        Console.Write(satirToplam[a] + " ");
                    }

                }

                else if (secim�nt == 0)
                    Console.WriteLine("!! Secenekler 1 den baslamaktad�r !! ");

                else
                    Console.WriteLine(" !! Yaln�zca iki secenek sunulmustur. Lutfen tekrar deneyiniz !! ");

            }

            else
                Console.WriteLine(" Hatali Satir Sayisi Girdiniz !!!");

        }

    }
    class String
    {
        public void stringIslemler()
        {

            string kelime;

            string harf;

            char cHarf;

            Console.WriteLine(".::String Islemleri Menusu");

            Console.Write("Islem yapacak Stringi giriniz:  ");

            kelime = Console.ReadLine();

            Console.Write("�stenen Harfi Giriniz: ");

            harf = Console.ReadLine();

            cHarf = Convert.ToChar(harf);

            char[] karakterler = kelime.ToCharArray();

            int strBoyut = karakterler.Length; //Kullanilan stringin boyutunu olcen metod.

            int[] elemanSapta = new int[100]; // aranan harfin stringin kac�nc� elemanlar�nda oldugunu tutacak olan dizi.

            int p = 0;
            
            for (int a = 0; a <strBoyut; a++)
            {

                if (karakterler[a] == cHarf)
                {
                    elemanSapta[p] = a ;
                    p++;
                }
    
            }

            if (p == 2)
            {

                Console.WriteLine("1 - Ara Metni Tersten Yaz");

                Console.WriteLine("2 - Ara Metni Tekrarli Yaz");

                Console.Write(" Seciminiz: ");

                int secim = Convert.ToInt32(Console.ReadLine());

                string araMetin = kelime.Substring(elemanSapta[0] + 1, elemanSapta[1] - elemanSapta[0] - 1); // Ara metni bulmak i�in kullan�lan metod.

                char[] araKarakter = araMetin.ToCharArray();

                int araBoyut = araMetin.Length;

                if (secim == 1)
                {
                    int e = araBoyut - 1;

                    for (int a = 0; a < araBoyut; a++)
                    {

                        Console.Write(araKarakter[e]);

                        --e;

                    }

                    Console.WriteLine();
                }

                else if (secim == 2)
                {
                    for (var a = 0; a < 5; a++)
                    {
                        Console.WriteLine(araMetin);
                    }

                }
                else
                    Console.WriteLine(" !!! Yalnizca iki secenek sunulmustur. Lutfen dikkat ediniz !!!");

            }
            else
                Console.WriteLine("Belirlediginiz harf hatalidir. Metin icinde 2 tane olmasina ozen g�steriniz.");
                      
        }



    }

    class Program
    {

        
        static void Main(string[] args)
        {

              do
              {

                  Matris m = new Matris();

                  String s = new String();

                  Console.WriteLine("..::Islemler::..");

                  string secim;

                  Console.Write(" 1 - Matris �slemleri " + "\n" + " 2 - String �slemleri " + "\n" + " 3 - Cikis " + "\n" + "Seciminiz: ");

                  secim = Console.ReadLine();

                  int secim�nt = Convert.ToInt32(secim);

                if (secim�nt == 1)
                {
                    do
                    {
                        string kSecim;

                        Console.Clear();

                        m.matrisIslemler();

                        Console.Write("Yeniden baslamak icin 0 , Ana menuye donmek icin herhangi bir tusa basiniz : ");

                        kSecim = Console.ReadLine();

                        int kucukSecim = Convert.ToInt32(kSecim);

                        if (kucukSecim != 0)
                        {
                            Console.Clear();
                            break;
                        }

                    } while (true);

                }

                else if (secim�nt == 2)
                {

                    do
                    {
                        string kSecim;

                        Console.Clear();

                        s.stringIslemler();

                        Console.Write("Yeniden baslamak icin 0 , Ana menuye donmek icin herhangi bir tusa basiniz : ");

                        kSecim = Console.ReadLine();

                        int kucukSecim = Convert.ToInt32(kSecim);

                        if (kucukSecim != 0)
                        {
                            Console.Clear();
                            break;
                        }

                    } while (true);

                }

                else
                    break;

                Console.Clear();

              } while (true);

            }

    }

   
}

