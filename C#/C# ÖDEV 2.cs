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
**		             Diktortgenler Uretip Bunlari Oteleyebilen C# Programi
*************************************************************************************/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Odev2;
using System.Collections;

namespace b161210037
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.SetWindowSize(153, 30);

            
            
           
            
           BilgiPaneli a = new BilgiPaneli();
           SahnePaneli b = new SahnePaneli();
           KontrolPaneli c = new KontrolPaneli();
          
            b.sahneCiz();
            c.panelCiz();
            a.BilgiYaz();



            do
            {
                
                ConsoleKeyInfo keyInfo = Console.ReadKey();

                if (keyInfo.Key == ConsoleKey.A)
                {

                    
                    a.SolaOtele();
                    b.sahneCiz();
                    c.panelCiz();
                    a.BilgiYaz();

                }
                else if (keyInfo.Key == ConsoleKey.E)
                {
                    Console.Clear();
                    b.sahneCiz();
                    c.panelCiz();
                    a.Ekle();
                    a.Ciz();
                    a.BilgiYaz();


                }
                else if (keyInfo.Key == ConsoleKey.D)
                {
                    a.SagaOtele();
                    b.sahneCiz();
                    c.panelCiz();
                    a.BilgiYaz();

                }
                else if (keyInfo.Key == ConsoleKey.W)
                {
                    a.YukariOtele();
                    b.sahneCiz();
                    c.panelCiz();
                    a.BilgiYaz();
                }
                else if (keyInfo.Key == ConsoleKey.S)
                {
                    
                    a.AsagiOtele();
                    b.sahneCiz();
                    c.panelCiz();
                    a.BilgiYaz();
                }
                
            } while (a.sekilSayisi != 100);

            do
            {
                
                a.Ciz();
                Console.SetCursorPosition(0, 0);
                Console.ReadKey();
                
            } while (true);

            
            
           

           
           

            
        }

       

    }
    public class Dortgen
    {
        private int Yukseklik;

        public int yukseklik
        {

            set
            {

                Yukseklik = value;
            }
            get { return Yukseklik; }

        }

        int Genislik;

        public int genislik
        {

            set
            {

                Genislik = value;
            }
            get { return Genislik; }

        }







        private int X;

        public int x
        {

            set
            {

                X = value;
            }
            get { return X; }

        }

        private int Y;

        public int y
        {

            set
            {

                Y = value;
            }
            get { return Y; }

        }

        private int RenkPrmtr;

        public int renkPrmtr
        {

            set
            {


                RenkPrmtr = value;
            }
            get { return RenkPrmtr; }

        }

        private int SekilSayisi;
        public int sekilSayisi
        {
            set
            {
                SekilSayisi = value;
            }
            get { return SekilSayisi; }
        }


        public int[] sekilx = new int[101];
        public int[] sekily = new int[101];
        public int[] sekilgenislik = new int[101];
        public int[] sekilyukseklik = new int[101];
        public int[] sekilrenk = new int[101];
        public int[] AktifKoordinatx = new int[261];
        public int[] AktifKoordinaty = new int[261];
        public ArrayList tumKoordinatx = new ArrayList();
        public ArrayList tumKoordinaty = new ArrayList();





        public void RenkAta()
        {

            switch (renkPrmtr)
            {
                case 1: Console.ForegroundColor = ConsoleColor.Blue; break;
                case 2: Console.ForegroundColor = ConsoleColor.Cyan; break;
                case 3: Console.ForegroundColor = ConsoleColor.DarkBlue; break;
                case 4: Console.ForegroundColor = ConsoleColor.DarkCyan; break;
                case 5: Console.ForegroundColor = ConsoleColor.DarkGreen; break;
                case 6: Console.ForegroundColor = ConsoleColor.DarkMagenta; break;
                case 7: Console.ForegroundColor = ConsoleColor.DarkRed; break;
                case 8: Console.ForegroundColor = ConsoleColor.DarkYellow; break;
                case 9: Console.ForegroundColor = ConsoleColor.Green; break;
                case 10: Console.ForegroundColor = ConsoleColor.Magenta; break;
                case 11: Console.ForegroundColor = ConsoleColor.Red; break;
                case 12: Console.ForegroundColor = ConsoleColor.White; break;
                case 13: Console.ForegroundColor = ConsoleColor.Yellow; break;
                case 14: Console.ForegroundColor = ConsoleColor.DarkGray; break;
                case 15: Console.ForegroundColor = ConsoleColor.Gray; break;

            }
        }
        public void RenkYaz()
        {
            switch (renkPrmtr)
            {
                case 1: Console.Write("Renk........:Blue"); break;
                case 2: Console.Write("Renk........:Cyan"); break;
                case 3: Console.Write("Renk........:DarkBlue"); break;
                case 4: Console.Write("Renk........:DarkCyan"); break;
                case 5: Console.Write("Renk........:DarkGreen"); break;
                case 6: Console.Write("Renk........:DarkMagenta"); break;
                case 7: Console.Write("Renk........:DarkRed"); break;
                case 8: Console.Write("Renk........:DarkYellow"); break;
                case 9: Console.Write("Renk........:Green"); break;
                case 10: Console.Write("Renk........:Magenta"); break;
                case 11: Console.Write("Renk........:Red"); break;
                case 12: Console.Write("Renk........:White"); break;
                case 13: Console.Write("Renk........:Yellow"); break;
                case 14: Console.Write("Renk........:DarkGray"); break;
                case 15: Console.Write("Renk........:Gray"); break;

            }
        }

        void KoordinatOturt()//imleci atanan koordinata getirir.
        {

            Console.SetCursorPosition(x, y);
        }
        void TabanCiz()
        {
            Console.SetCursorPosition(x, y + yukseklik - 1);
            Console.Write(KarakterSeti.SolAltKose);
            for (var a = 2; a < genislik; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }
            Console.Write(KarakterSeti.SagAltKose);



        }

        void TepeCiz()
        {
            KoordinatOturt();

            Console.Write(KarakterSeti.SolUstKose);

            for (var a = 2; a < genislik; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }

            Console.Write(KarakterSeti.SagUstKose);

        }
        public void DikeyCiz()
        {

            for (var a = 1; a < yukseklik - 1; a++)
            {
                Console.SetCursorPosition(x, y + a);
                Console.Write(KarakterSeti.Dikey);

            }
            for (var a = 1; a < yukseklik - 1; a++)
            {
                Console.SetCursorPosition(x + genislik - 1, y + a);
                Console.Write(KarakterSeti.Dikey);

            }

        }

        public void Ekle()//Kullanici 'E' tusuna bastiginda sekil ekleten fonksiyon.
        {

            if (sekilSayisi == 0)
            {
                renkPrmtr = RastgeleSayi.SayiUret(1, 15);
                RenkAta();
                sekilrenk[sekilSayisi] = renkPrmtr;
                x = RastgeleSayi.SayiUret(2, 99);
                sekilx[sekilSayisi] = x;
                y = RastgeleSayi.SayiUret(2, 29);
                sekily[sekilSayisi] = y;
                genislik = RastgeleSayi.SayiUret(2, 20);
                sekilgenislik[sekilSayisi] = genislik;
                yukseklik = RastgeleSayi.SayiUret(2, 20);
                sekilyukseklik[sekilSayisi] = yukseklik;

                Kontrol(x, y, genislik, yukseklik);

                TepeCiz();
                DikeyCiz();
                TabanCiz();

                ++sekilSayisi;



                Console.SetCursorPosition(0, 0);

            }
            else
            {
                renkPrmtr = RastgeleSayi.SayiUret(1, 15);
                RenkAta();
                sekilrenk[sekilSayisi] = renkPrmtr;
                x = RastgeleSayi.SayiUret(2, 99);
                sekilx[sekilSayisi] = x;
                y = RastgeleSayi.SayiUret(2, 29);
                sekily[sekilSayisi] = y;
                for (var a = 0; a < sekilSayisi; a++)
                {
                    if (x == sekilx[a] && y == sekily[a])
                    {
                        x = RastgeleSayi.SayiUret(2, 99);
                        sekilx[sekilSayisi] = x;
                        y = RastgeleSayi.SayiUret(2, 29);
                        sekily[sekilSayisi] = y;
                    }
                    else
                        break;
                }
                genislik = RastgeleSayi.SayiUret(2, 20);
                sekilgenislik[sekilSayisi] = genislik;
                yukseklik = RastgeleSayi.SayiUret(2, 20);
                sekilyukseklik[sekilSayisi] = yukseklik;
                Kontrol(x, y, genislik, yukseklik);

                TepeCiz();
                DikeyCiz();
                TabanCiz();
                ++sekilSayisi;



                Console.SetCursorPosition(0, 0);

            }

        }

        public void Ciz()//tum dikdortgenleri sahne paneline cizer.
        {

            for (var a = 0; a < sekilSayisi; a++)
            {

                x = sekilx[a]; y = sekily[a]; genislik = sekilgenislik[a]; yukseklik = sekilyukseklik[a]; renkPrmtr = sekilrenk[a];

                RenkAta();

                TepeCiz();
                DikeyCiz();
                TabanCiz();
                Console.SetCursorPosition(0, 0);


            }


        }
        public void SolaOtele()
        {

            Console.Clear();
            x = x - 1;
            if (x < 1)
            {
                x = x + 1;
            }

            sekilx[sekilSayisi - 1] = x;
            tumKoordKaydet();
            aktifKoordKaydet(x, y, genislik, yukseklik);
            if (sekillerCarpisiyormu(x, y, genislik, yukseklik) == true)
            {
                x = x + 1;
                sekilx[sekilSayisi - 1] = x;
            }

            Ciz();



        }
        public void SagaOtele()
        {
            Console.Clear();
            x = x + 1;
            if (x + genislik - 1 > 98)
            {
                x = x - 1;
            }
            sekilx[sekilSayisi - 1] = x;
            tumKoordKaydet();
            aktifKoordKaydet(x, y, genislik, yukseklik);
            if (sekillerCarpisiyormu(x, y, genislik, yukseklik) == true)
            {
                x = x - 1;
                sekilx[sekilSayisi - 1] = x;
            }

            Ciz();
        }
        public void YukariOtele()
        {
            Console.Clear();
            y = y - 1;
            if (y < 1)
            {
                y = y + 1;
            }
            sekily[sekilSayisi - 1] = y;
            tumKoordKaydet();
            aktifKoordKaydet(x, y, genislik, yukseklik);
            if (sekillerCarpisiyormu(x, y, genislik, yukseklik) == true)
            {
                y = y + 1;
                sekily[sekilSayisi - 1] = y;
            }
            Ciz();
        }
        public void AsagiOtele()
        {
            Console.Clear();
            y = y + 1;
            if (y + yukseklik - 1 > 28)
            {
                y = y - 1;
            }
            sekily[sekilSayisi - 1] = y;
            tumKoordKaydet();
            aktifKoordKaydet(x, y, genislik, yukseklik);
            if (sekillerCarpisiyormu(x, y, genislik, yukseklik) == true)
            {
                y = y - 1;
                sekily[sekilSayisi - 1] = y;
            }
            Ciz();
        }


        public void aktifKoordKaydet(int u, int ý, int o, int p)//Aktif seklin tum koordýnatlarýný bir diziye atar.
        {

            Array.Clear(AktifKoordinatx, 0, AktifKoordinatx.Length);
            Array.Clear(AktifKoordinaty, 0, AktifKoordinaty.Length);
            int AktifkoordX = u;

            int AktifkoordY = ý;

            int AktifGenislik = o;

            int AktifYukseklik = p;

            for (var a = 0; a < AktifGenislik; a++)
            {
                AktifKoordinatx[a] = AktifkoordX;
                AktifkoordX = AktifkoordX + 1;
                AktifKoordinaty[a] = AktifkoordY;
            }
            AktifkoordX = u;
            AktifkoordY = AktifkoordY + AktifYukseklik - 1;
            for (var a = AktifGenislik + 1; a < 2 * AktifGenislik + 1; a++)
            {

                AktifKoordinaty[a] = AktifkoordY;
                AktifKoordinatx[a] = AktifkoordX;
                AktifkoordX = AktifkoordX + 1;
            }
            AktifkoordX = u;
            AktifkoordY = ý;
            for (var a = 2 * AktifGenislik + 1; a < (2 * AktifGenislik + 1) + AktifYukseklik; a++)
            {
                AktifKoordinatx[a] = AktifkoordX;
                AktifKoordinaty[a] = AktifkoordY;
                AktifkoordY = AktifkoordY + 1;

            }
            AktifkoordY = ý;
            AktifkoordX = AktifkoordX + AktifGenislik - 1;
            for (var a = (2 * AktifGenislik + 1) + AktifYukseklik; a < (2 * AktifGenislik + 1) + 2 * AktifYukseklik; a++)
            {
                AktifKoordinatx[a] = AktifkoordX;
                AktifKoordinaty[a] = AktifkoordY;
                AktifkoordY = AktifkoordY + 1;
            }






        }
        void Kontrol(int h, int j, int k, int l)//sekil sahnenin icinde mi disina mi tasiyor diye kontrol eder.
        {
            SahnePaneli a = new SahnePaneli();
            a.sKoordKaydet();
            aktifKoordKaydet(h, j, k, l);

            for (int i = 0; i < a.sahneKoordinatx.Length; i++)
            {
                for (int z = 0; z < AktifKoordinatx.Length; z++)
                {
                    if (a.sahneKoordinatx[i] == AktifKoordinatx[z] && a.sahneKoordinaty[i] == AktifKoordinaty[z] && a.sahneKoordinatx[i] != 0)
                    {

                        Ekle();
                        sekilSayisi = sekilSayisi - 1;

                    }

                }
            }

        }

        public void tumKoordKaydet()//tum dikdortgenlerin uzerýndeki koordinatlarý bir arraylist e atar.
        {
            tumKoordinatx.Clear();
            tumKoordinaty.Clear();

            for (var a = 0; a < sekilSayisi - 1; a++)
            {
                int geciciX = sekilx[a];
                int geciciY = sekily[a];
                for (var b = 0; b < sekilgenislik[a]; b++)
                {

                    tumKoordinatx.Add(geciciX);
                    geciciX = geciciX + 1;

                    tumKoordinaty.Add(geciciY);

                }
                geciciX = sekilx[a];
                for (var b = sekilgenislik[a] + 1; b < 2 * sekilgenislik[a] + 1; b++)
                {
                    geciciY = sekily[a] + sekilyukseklik[a] - 1;

                    tumKoordinaty.Add(geciciY);

                    tumKoordinatx.Add(geciciX);
                    geciciX = geciciX + 1;

                }
                geciciX = sekilx[a];
                geciciY = sekily[a];
                for (var b = 2 * sekilgenislik[a] + 1; b < (2 * sekilgenislik[a] + 1) + sekilyukseklik[a]; b++)
                {

                    tumKoordinatx.Add(geciciX);

                    tumKoordinaty.Add(geciciY);
                    geciciY = geciciY + 1;

                }
                geciciY = sekily[a];
                geciciX = sekilx[a] + sekilgenislik[a] - 1;
                for (var b = (2 * sekilgenislik[a] + 1) + sekilyukseklik[a]; b < (2 * sekilgenislik[a] + 1) + 2 * sekilyukseklik[a]; b++)
                {

                    tumKoordinatx.Add(geciciX);

                    tumKoordinaty.Add(geciciY);
                    geciciY = geciciY + 1;

                }
            }


        }
        bool sekillerCarpisiyormu(int h, int j, int k, int l)//sekillerin carpisip carpismadigini kontrol eder.
        {

            int unboxX, unboxY;

            for (var i = 0; i < tumKoordinatx.Count; i++)
            {

                unboxX = (int)tumKoordinatx[i];
                unboxY = (int)tumKoordinaty[i];
                for (int z = 0; z < AktifKoordinatx.Length; z++)
                {
                    if (unboxX == AktifKoordinatx[z] && unboxY == AktifKoordinaty[z])
                    {
                        return true;
                    }


                }

            }
            return false;

        }

    }
    class SahnePaneli
    {
        public int x = 100;
        public int y = 30;

        public void sahneCiz()
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write(KarakterSeti.SolUstKose);

            for (var a = 2; a < x; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }

            Console.Write(KarakterSeti.SagUstKose);

            for (var a = 1; a < y - 1; a++)
            {
                Console.SetCursorPosition(0, a);
                Console.Write(KarakterSeti.Dikey);

            }

            for (var a = 1; a < y - 1; a++)
            {
                Console.SetCursorPosition(0 + x - 1, a);
                Console.Write(KarakterSeti.Dikey);

            }

            Console.SetCursorPosition(0, 0 + y - 1);
            Console.Write(KarakterSeti.SolAltKose);
            for (var a = 2; a < x; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }
            Console.Write(KarakterSeti.SagAltKose);
            Console.SetCursorPosition(0, 0);
        }

        public int[] sahneKoordinatx = new int[261];
        public int[] sahneKoordinaty = new int[261];
        public int koordX = 0;
        public int koordY = 0;

        public void sKoordKaydet() // Sahne paneli uzerindeki tum koordinatlari bir diziye atacak.
        {

            for (var a = 0; a < 101; a++)
            {
                sahneKoordinatx[a] = koordX;
                koordX = koordX + 1;
                sahneKoordinaty[a] = koordY;
            }
            koordX = 0;
            for (var a = 101; a < 201; a++)
            {
                koordY = 30;
                sahneKoordinaty[a] = koordY;
                sahneKoordinatx[a] = koordX;
                koordX = koordX + 1;
            }
            koordX = 0;
            koordY = 0;
            for (var a = 201; a < 231; a++)
            {
                sahneKoordinatx[a] = koordX;
                sahneKoordinaty[a] = koordY;
                koordY = koordY + 1;

            }
            koordY = 0;
            koordX = 100;
            for (var a = 231; a < 261; a++)
            {
                sahneKoordinatx[a] = koordX;
                sahneKoordinaty[a] = koordY;
                koordY = koordY + 1;
            }



        }

    }
    class BilgiPaneli : Dortgen
    {
        public void BilgiYaz()
        {

            Console.ForegroundColor = ConsoleColor.Green;

            Console.SetCursorPosition(101, 15);
            int i = 52;
            int j = 15;

            Console.Write(KarakterSeti.SolUstKose);

            for (var a = 2; a < i; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }

            Console.Write(KarakterSeti.SagUstKose);

            for (var a = 1; a < j - 1; a++)
            {
                Console.SetCursorPosition(101, 15 + a);
                Console.Write(KarakterSeti.Dikey);

            }
            for (var a = 1; a < j - 1; a++)
            {
                Console.SetCursorPosition(101 + i - 1, 15 + a);
                Console.Write(KarakterSeti.Dikey);

            }
            Console.SetCursorPosition(101, 15 + j - 1);
            Console.Write(KarakterSeti.SolAltKose);
            for (var a = 2; a < i; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }
            Console.Write(KarakterSeti.SagAltKose);


            Console.ResetColor();
            Console.SetCursorPosition(110, 17);

            Console.Write("X...........:" + x);
            Console.SetCursorPosition(110, 19);

            Console.Write("Y...........:" + y);
            Console.SetCursorPosition(110, 21);

            Console.Write("Genislik....:" + genislik);
            Console.SetCursorPosition(110, 23);

            Console.Write("Yukseklik...:" + yukseklik);
            Console.SetCursorPosition(110, 25);

            RenkYaz();
            Console.SetCursorPosition(110, 27);
            Console.Write("Sekil Sayisi:" + sekilSayisi);

            Console.SetCursorPosition(0, 0);

        }

    }
    class KontrolPaneli
    {
        public int x = 52;
        public int y = 15;
        public void panelCiz()
        {
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.SetCursorPosition(101, 0);

            Console.Write(KarakterSeti.SolUstKose);

            for (var a = 2; a < x; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }

            Console.Write(KarakterSeti.SagUstKose);

            for (var a = 1; a < y - 1; a++)
            {
                Console.SetCursorPosition(101, 0 + a);
                Console.Write(KarakterSeti.Dikey);
            }
            for (var a = 1; a < y - 1; a++)
            {
                Console.SetCursorPosition(101 + x - 1, 0 + a);
                Console.Write(KarakterSeti.Dikey);
            }
            Console.SetCursorPosition(101, 0 + y - 1);
            Console.Write(KarakterSeti.SolAltKose);
            for (var a = 2; a < x; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }
            Console.Write(KarakterSeti.SagAltKose);

            Console.ResetColor();
            Console.SetCursorPosition(110, 2);
            Console.Write("KONTROL PANELÝ");
            Console.SetCursorPosition(110, 4);
            Console.Write("SEKIL EKLE (E)");
            Console.SetCursorPosition(110, 6);
            Console.Write("SOLA OTELE (A)");
            Console.SetCursorPosition(110, 8);
            Console.Write("SAGA OTELE (D)");
            Console.SetCursorPosition(110, 10);
            Console.Write("YUKARI OTELE (W)");
            Console.SetCursorPosition(110, 12);
            Console.Write("ASAGI OTELE (S)");
            Console.SetCursorPosition(0, 0);

        }
    }
    class KarakterSeti
    {

        public static char SolUstKose = '-';
        public static char SagUstKose = '¬';
        public static char Duz = '=';
        public static char Dikey = '¦';
        public static char SolAltKose = 'L';
        public static char SagAltKose = '-';

    }
    class RastgeleSayi
    {
        public static int SayiUret(int min, int max)
        {
            if (rastgele == null)
                rastgele = new Random();

            return rastgele.Next(min, max);
        }

        private static Random rastgele;
    }
}
