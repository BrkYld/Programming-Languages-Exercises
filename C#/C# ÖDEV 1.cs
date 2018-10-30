
/***********************************************************************************
**                                SAKARYA ÜNÝVERSÝTESÝ
**                       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                            BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                           NESNEYE DAYALI PROGLAMLAMA DERSÝ
**                             2016 - 2017 BAHAR DÖNEMÝ
**
**                           ÖÐRENCÝ ADI: BURAK YILDIRIM
**                           ÖÐRENCÝ NUMARASI:b1612.10037
**                           DERS GRUBU: B 1.ÖÐRETÝM
**		             Matris ve String Ýslemleri Yapabilen C# Programý
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

            int SatirÝnt = Convert.ToInt32(Satir);

            string [] Degerler = new string[100]; // Satir sayisi sinirindan dolayi en fazla 100 elemanli olacaktir.

            if( SatirÝnt < 10 && SatirÝnt > 0)
            {

                int indis = 0;
                
                Console.WriteLine("Matris Degerlerini Giriniz ");
                
                for (var i = 1; i < SatirÝnt + 1; i++)// Matrisin Satir ve Sutun degerlerini kullanicidan alan dongu.
                {
                    for (var j = 1; j < SatirÝnt + 1; j++)

                    {

                        Console.WriteLine("[" + i + "," + j + "]" + "="  );

                        Degerler[indis] = Console.ReadLine();

                        ++indis;

                    }

                }

                Console.Clear();

                Console.WriteLine(".::Matris Islemleri Menusu::.");

                indis = 0;
                
                for (var i = 1; i < SatirÝnt + 1; i++)// Matrisin Satir ve Sutun degerlerini yazdiran dongu (örn. [1,6] = 8)
                {
                    for (var j = 1; j < SatirÝnt + 1; j++)
                    {

                         Console.WriteLine("[" + i + "," + j + "]" + "=" + Degerler[indis] + "\n");

                        ++indis;

                    }

                }
                
                int c = 0;

                for ( var a = 0; a < SatirÝnt  ; a++)// Matrisi Yazdiran Dongu
                {

                    for( var b = 0; b < SatirÝnt; b++)
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

                int secimÝnt = Convert.ToInt32(secim);

                int[] DegerlerÝnt = new int[100];

                for (var a = 0; a < SatirÝnt * SatirÝnt; a++) // string tanimli kullanici girdilerini teker teker int e donusturur.
                {

                    DegerlerÝnt[a] = Convert.ToInt32(Degerler[a]);

                }

                if (secimÝnt == 1)
                {

                    c = SatirÝnt; // Bu deðiþkeni sadece parametre olarak kullanýyorum.

                    int d = 0;

                    int e = SatirÝnt - 1;

                    int[] satirBuyuk = new int[10];

                    for (var a = 0; a < SatirÝnt * SatirÝnt + 1; a = a + SatirÝnt)
                    {

                        Array.Sort(DegerlerÝnt, a, c);

                        satirBuyuk[d] = DegerlerÝnt[e];

                        ++d;

                        e = e + SatirÝnt;
                    }

                    Console.WriteLine("Sonucunuz : ");

                    for (var a = 0; a < SatirÝnt; a++)
                    {

                        Console.Write(satirBuyuk[a] + " ");

                    }

                }

                else if (secimÝnt == 2)
                {

                    int[] satirToplam = new int[10];

                    int d = 0;

                    int e = 0;

                    for (var a = 0; a < SatirÝnt; a++)
                    {
                        for (var i = 0; i < SatirÝnt; i++)

                        {
                            satirToplam[d] = satirToplam[d] + DegerlerÝnt[e];
                            e++;
                        }

                        d++;
                    }

                    Console.WriteLine("Sonucunuz : ");

                    for (var a = 0; a < SatirÝnt; a++)
                    {
                        Console.Write(satirToplam[a] + " ");
                    }

                }

                else if (secimÝnt == 0)
                    Console.WriteLine("!! Secenekler 1 den baslamaktadýr !! ");

                else
                    Console.WriteLine(" !! Yalnýzca iki secenek sunulmustur. Lutfen tekrar deneyiniz !! ");

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

            Console.Write("Ýstenen Harfi Giriniz: ");

            harf = Console.ReadLine();

            cHarf = Convert.ToChar(harf);

            char[] karakterler = kelime.ToCharArray();

            int strBoyut = karakterler.Length; //Kullanilan stringin boyutunu olcen metod.

            int[] elemanSapta = new int[100]; // aranan harfin stringin kacýncý elemanlarýnda oldugunu tutacak olan dizi.

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

                string araMetin = kelime.Substring(elemanSapta[0] + 1, elemanSapta[1] - elemanSapta[0] - 1); // Ara metni bulmak için kullanýlan metod.

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
                Console.WriteLine("Belirlediginiz harf hatalidir. Metin icinde 2 tane olmasina ozen gösteriniz.");
                      
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

                  Console.Write(" 1 - Matris Ýslemleri " + "\n" + " 2 - String Ýslemleri " + "\n" + " 3 - Cikis " + "\n" + "Seciminiz: ");

                  secim = Console.ReadLine();

                  int secimÝnt = Convert.ToInt32(secim);

                if (secimÝnt == 1)
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

                else if (secimÝnt == 2)
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

