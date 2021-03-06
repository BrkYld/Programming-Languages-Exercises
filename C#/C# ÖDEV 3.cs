using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
namespace Odev3
{

    class Menuler
    {
        public void boslukBırak(string a, int genislik)
        {
            for (var i = 0; i < genislik - a.Length - 2; i++)
            {
                Console.Write(" ");
            }
        }
        public void zeminCiz(int genislik)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write(KarakterSeti.SolAltKose);

            for (var i = 0; i < genislik - 2; i++)
                Console.Write(KarakterSeti.Duz);

            Console.Write(KarakterSeti.SagAltKose);
            Console.ResetColor();
            Console.WriteLine();
        }
        public void tavanCiz(int genislik)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write(KarakterSeti.SolUstKose);

            for (var a = 2; a < genislik; a++)
            {
                Console.Write(KarakterSeti.Duz);


            }

            Console.Write(KarakterSeti.SagUstKose);
            Console.ResetColor();
            Console.WriteLine();

        }
        public void araCiz(int genislik, string yazi)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write(KarakterSeti.Dikey);
            Console.ResetColor();
            Console.Write(yazi);
            boslukBırak(yazi, genislik);
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write(KarakterSeti.Dikey);
            Console.ResetColor();
            Console.WriteLine();

        }
        public void ayracCiz(int genislik)
        {
            Console.Write(KarakterSeti.YataySagAyrac);

            for (var i = 0; i < genislik-2; i++)
                Console.Write(KarakterSeti.Duz);

            Console.Write(KarakterSeti.YataySolAyrac);

            Console.WriteLine();
        }

    }
    class KarakterSeti
    {

        public static char SolUstKose = '╔';
        public static char SagUstKose = '╗';
        public static char Duz = '═';
        public static char Dikey = '║';
        public static char SolAltKose = '╚';
        public static char SagAltKose = '╝';
        public static string YataySagAyrac = "╠";
        public static string YataySolAyrac = "╣";
    }

    class Sirket
    {
        m1 x = new m1();
        m2 y = new m2();
        
        string Adi = "Aksel Tahincilik";
        string Adres = "Kazan/Ankara";
        string telNo = "0956 589 2564";
        string eMail = "akseltahin@saumail.com";
        string web = "www.akseltahin.com.tr";
        string vergiNo = "0000";
        public void tanitimCiz()
        {
            Menuler a = new Menuler();
            Console.SetCursorPosition(50, 0);
            Console.WriteLine("AKSEL TAHINCILIK GIDA LIMITED SIRKETINE HOSGELDINIZ");
            Console.SetCursorPosition(45, 2);
            Console.WriteLine("BU PROGRAM MUSTERILERIMIZE ve BIZE ALISVERIS KOLAYLIGI SAGLAR");
            Console.SetCursorPosition(30, 4);
            Console.WriteLine(Adi + "--" + Adres + "--" + telNo + "--" + eMail + "--" + web + "--" + vergiNo);
            Console.SetCursorPosition(0, 6);
            Console.WriteLine("Musterimizseniz , vergi numaraniz ile sisteme giris yapabilirsiniz . ");
            a.tavanCiz(45);
            a.araCiz(45,x.adi+":  "+x.vergiNo);
            a.ayracCiz(45);
            a.araCiz(45, y.adi+":  "+y.vergiNo);
            a.zeminCiz(45);


        }

    }
    public class Musteri
    {
        string Adi, Adresi, telNo, eMail, Web, Bakiye, siparisTarih,VergiNo;
        public string adi
        {
            set { Adi = value; }
            get { return Adi; }
        }
        public string adresi
        {
            set { Adresi = value; }
            get { return Adresi; }
        }
        public string telno
        {
            set { telNo = value; }
            get { return telNo; }
        }
        public string email
        {
            set { eMail = value; }
            get { return eMail; }
        }
        public string web
        {
            set { Web = value; }
            get { return Web; }
        }
        
        public string bakiye
        {
            set
            {
                Bakiye = value;
            }
            get
            {
                double a = Convert.ToDouble(Bakiye);
                if (a < 0)
                {
                    return "0";
                }
                else if (a > 1000)
                {
                    return "1000";
                }
                else
                    return Bakiye;
            }
        }
        public string sipTarih
        {
            set { siparisTarih = value; }
            get { return siparisTarih; }
        }
        public string vergiNo
        {
            set { VergiNo = value; }
            get { return VergiNo; }
        }
        
        public void siparisTarihAta()
        {
            sipTarih = Convert.ToString(DateTime.Now.Day) + "/" + Convert.ToString(DateTime.Now.Month) + "/" + Convert.ToString(DateTime.Now.Year) + "--" + Convert.ToString(DateTime.Now.Hour) + ":" + Convert.ToString(DateTime.Now.Minute) + "." + Convert.ToString(DateTime.Now.Second);
        }
        public void bakiyeYukle()
        {
            double bakiyeTl = Convert.ToDouble(bakiye);
            double b;
            Console.Write("Ne Kadar Yuklemek Istersiniz? : ");

            b = Convert.ToDouble(Console.ReadLine());
            Bakiye = Convert.ToString(b + bakiyeTl);
            
            
        }
        
        public string mamulbakiyeHesapla(string dgr)
        {
            Mamul a = new Mamul();
            bakiye = Convert.ToString(Convert.ToDouble(bakiye)-Convert.ToDouble(a.mamulfiyatHesapla(dgr)) );
            return bakiye;
        }
        public string ymamulbakiyeHesapla(string dgr)
        {
            YariMamul a = new YariMamul();
            bakiye = Convert.ToString(Convert.ToDouble(bakiye) - Convert.ToDouble(a.ymamulfiyatHesapla(dgr)));
            return bakiye;
        }
        Menuler a = new Menuler();
      public  void musteriMenuCiz()
        {
            Console.WriteLine("HOSGELDINIZ ," + adi);
            a.tavanCiz(45);
            a.araCiz(45, adi);
            a.ayracCiz(45);
            a.araCiz(45, adresi);
            a.ayracCiz(45);
            a.araCiz(45, telno);
            a.ayracCiz(45);
            a.araCiz(45, email);
            a.ayracCiz(45);
            a.araCiz(45, web);
            a.ayracCiz(45);
            a.araCiz(45, vergiNo);
            a.zeminCiz(45);
            Console.WriteLine();
            a.tavanCiz(60);
            a.araCiz(60, "Bakiyeniz :" + bakiye + "TL");
            a.ayracCiz(60);
            a.araCiz(60, "Son Siparisinizi :" + sipTarih + " " + "Tarihinde yaptiniz.");
            a.zeminCiz(60);
        }

    }
    class m1 : Musteri
    {
        public m1()
        {
            
            adi = "Uzungil Sekerleme";
            adresi = "Gimat/Ankara";
            telno = "0985 356 9856";
            email = "usekerleme@saumail.com";
            web = "www.uzungil.com.tr";
            bakiye = "0";
            sipTarih = "20/04/2017-22:43.50";
            vergiNo = "1234";
        }
    }
    class m2 : Musteri
    {
        
        public m2()
        {
            
            adi = "Cumhuriyet Lezzet Dunyasi";
            adresi = "Batikent/Ankara";
            telno = "0755 893 35 24";
            email = "lezzetcd@saumail.com";
            web = "www.cld.com.tr";
            bakiye = "0";
            sipTarih = "18/03/2017-19:36.13";
            vergiNo = "4567";
        }


    }
    class Tedarikci : Musteri
    {
        public Tedarikci()
        {
            adi = "Robus International";
            adresi = "West Ham / Ingiltere";
            telno = "+1 399 657 12 20";
            email = "robus@saumail.com";
            web = "www.rınternational.com";
            sipTarih = "20/04/2017-22:43.50";
            vergiNo = "7777";
        }
    }
    class Hammadde 
    {
        string Adi, Miktari, BarkodNo, TedarikciFirma, MinSipMik,Maaliyet;
        
        public string adi
        {
            set { Adi = value; }
            get { return Adi; }
        }
        public string miktar
        {
            set { Miktari = value; }
            get { return Miktari; }
        }
        public string barkodNo
        {
            set { BarkodNo = value; }
            get { return BarkodNo; }
        }
        public string tedarikFirma
        {
            set { TedarikciFirma = value; }
            get { return TedarikciFirma; }
        }
        public string minSip
        {
            set { MinSipMik = value; }
            get { return MinSipMik; }
        }

        public string maliyet
        {
            set
            {
                Maaliyet = value;
            }
            get
            {  
               return Maaliyet;
            }
        }
       public Hammadde()
        {
            adi = " Ham Susam";
            miktar = "10000 kg";
            barkodNo = "555666";
            tedarikFirma = "Robus International";
            minSip = "5 kg";
            maliyet = "2"; //kg maliyeti.

        }

        public string maaliyetHesapla(string deger)
        {
            double dgr = Convert.ToDouble(deger);
            maliyet = Convert.ToString(Convert.ToDouble(maliyet) * (dgr + dgr / 3));

            return maliyet;

        }

    }
    class Urun
    {
        string Adi, Tarihi, Fiyat;
        public string adi
        {
            set { Adi = value; }
            get { return Adi; }
        }
        public string uretimTarih
        {
            set { Tarihi = value; }
            get
            {
                
                return Tarihi;
            }
        }
        public string uretimTarihGetir()
        {
            uretimTarih = Convert.ToString(DateTime.Now.Day) + "/" + Convert.ToString(DateTime.Now.Month) + "/" + Convert.ToString(DateTime.Now.Year) + "--" + Convert.ToString(DateTime.Now.Hour) + ":" + Convert.ToString(DateTime.Now.Minute) + "." + Convert.ToString(DateTime.Now.Second);
            return uretimTarih;
        }
        public string fiyat
        {
            set { Fiyat = value; }
            get
            {
                double a = Convert.ToDouble(Fiyat);
                if (a < 0)
                {
                    Fiyat = "0";
                    return Fiyat;
                }
                else
                    return Fiyat;
             }
        }
        public string mamulfiyatHesapla(string deger)//Urunun fiyatını ,kayip oranını,iscilik maliyetini ve kar payini katarak hesaplar.
        {
            Hammadde a = new Hammadde();
            double dgr = Convert.ToDouble(deger);
            a.maaliyetHesapla(deger);
            double malidgr = Convert.ToDouble(a.maliyet);
            fiyat = Convert.ToString((((malidgr*100/75)+ (malidgr * 100 / 75)/5))+ ((malidgr * 100 / 75) + (malidgr * 100 / 75) / 5)/10);
            
            return fiyat;
        }
        public string ymamulfiyatHesapla(string deger)
        {
            YariMamul a = new YariMamul();
            double dgr = Convert.ToDouble(deger);
            fiyat = Convert.ToString(dgr * Convert.ToDouble(a.fiyat));
            return fiyat;
        }
        Menuler a = new Menuler();
        public void UrunList()
        {
            Mamul x = new Mamul();
            YariMamul y = new YariMamul();
            a.tavanCiz(45);
            a.araCiz(45, "1- " + x.adi + " " + "Mamul" + " " + x.fiyat + " " + "TL/kg");
            a.ayracCiz(45);
            a.araCiz(45,"2- " + y.adi + " " + "Yari Mamul" + " " + y.fiyat + " " + "TL/kg");
            a.zeminCiz(45);

        }

    }
    class Mamul : Urun
    {
        public Mamul()
        {
            adi = "Tahin";
            uretimTarih = uretimTarihGetir();
            fiyat = "4,69333333333334";
        }

    }
    class YariMamul:Urun
    {
        public YariMamul()
        {
            adi = "Kavrulmus Susam";
            uretimTarih = uretimTarihGetir();
            fiyat = "2,75";
        }
        
    }
    class Program
    {

        static void Main(string[] args)
        {
            do
            {
                Console.SetWindowSize(150, 30);
                Sirket a = new Sirket();
                m1 ug = new m1();
                m2 cld = new m2();
                Mamul tahin = new Mamul();
                YariMamul kSusam = new YariMamul();
                Urun b = new Urun();
                a.tanitimCiz();
                Console.Write("Vergi No : ");
                string pass = Console.ReadLine();

                do
                {
                    if (pass == ug.vergiNo)
                    {
                        Console.Clear();
                        ug.musteriMenuCiz();
                        Console.WriteLine("1-Bakiye Yukleme");
                        Console.WriteLine("2-Urun Alma");
                        Console.WriteLine("3-Cikis");
                        Console.Write("Seciminiz : ");
                        int secim = Convert.ToInt32(Console.ReadLine());
                        if (secim == 1)
                        {
                            ug.bakiyeYukle();
                        }
                        else if (secim == 2)
                        {
                            b.UrunList();
                            Console.Write("Alacaginiz urunu seciniz : ");
                            secim = Convert.ToInt32(Console.ReadLine());
                            if (secim == 1)
                            {
                                Console.Write("Siparis edeciğiniz miktari kg cinsinden yaziniz :");
                                string siparis = Console.ReadLine();
                                tahin.mamulfiyatHesapla(siparis);
                                Console.Write("Alisveris tutariniz : " + tahin.fiyat + "TL dir. Onayliyorsanız (Evet) yaziniz(buyuk kucuk harf duyarlidir.) :");
                                string index = Console.ReadLine();
                                if (index == "Evet")
                                {
                                    ug.mamulbakiyeHesapla(siparis);
                                    if (ug.bakiye == "0")
                                    {
                                        Console.Write("Bakiyeniz yetersiz oldugu icin islem yapilamamistir.Bakiye yuklemeyi secebilirsiniz.");
                                        Thread.Sleep(3000);
                                        Console.Clear();

                                    }
                                    else
                                    {
                                        Console.WriteLine("Tesekkurler !" + " " + ug.adi + " " + "Siparisiniz tamamlanmistir. Urununuz 3 is gunu icerisinde sirketinize ulastirilacaktir. ");
                                        Console.Write("PROFILINIZE YONLENDIRILIYORSUNUZ  ");
                                        for (var i = 0; i < 5; i++)
                                        {
                                            Console.Write(">");
                                            Thread.Sleep(2000);
                                        }
                                        ug.siparisTarihAta();
                                        Console.Clear();

                                    }

                                }



                            }
                            else if (secim == 2)
                            {
                                Console.Write("Siparis edeciğiniz miktari kg cinsinden yaziniz :");
                                string siparis = Console.ReadLine();
                                kSusam.ymamulfiyatHesapla(siparis);
                                Console.Write("Alisveris tutariniz : " + kSusam.fiyat + "TL dir. Onayliyorsanız (Evet) yaziniz(buyuk kucuk harf duyarlidir.) :");
                                string index = Console.ReadLine();
                                if (index == "Evet")
                                {
                                    ug.ymamulbakiyeHesapla(siparis);
                                    if (ug.bakiye == "0")
                                    {
                                        Console.Write("Bakiyeniz yetersiz oldugu icin islem yapilamamistir.Bakiye yuklemeyi secebilirsiniz.");
                                        Thread.Sleep(3000);
                                        Console.Clear();

                                    }
                                    else
                                    {
                                        Console.WriteLine("Tesekkurler !" + " " + ug.adi + " " + "Siparisiniz tamamlanmistir. Urununuz 3 is gunu icerisinde sirketinize ulastirilacaktir. ");
                                        Console.Write("PROFILINIZE YONLENDIRILIYORSUNUZ  ");
                                        for (var i = 0; i < 5; i++)
                                        {
                                            Console.Write(">");
                                            Thread.Sleep(2000);
                                        }
                                        ug.siparisTarihAta();
                                        Console.Clear();

                                    }

                                }
                            }


                        }
                        else
                        {
                            Console.Clear();
                            break;
                        }
                            
                    }
                    else if (pass == cld.vergiNo)
                    {
                        Console.Clear();
                        cld.musteriMenuCiz();
                        Console.WriteLine("1-Bakiye Yukleme");
                        Console.WriteLine("2-Urun Alma");
                        Console.WriteLine("3-Cikis");
                        Console.Write("Seciminiz : ");
                        int secim = Convert.ToInt32(Console.ReadLine());
                        if (secim == 1)
                        {
                            cld.bakiyeYukle();
                        }
                        else if (secim == 2)
                        {
                            b.UrunList();
                            Console.Write("Alacaginiz urunu seciniz : ");
                            secim = Convert.ToInt32(Console.ReadLine());
                            if (secim == 1)
                            {
                                Console.Write("Siparis edeciğiniz miktari kg cinsinden yaziniz :");
                                string siparis = Console.ReadLine();
                                tahin.mamulfiyatHesapla(siparis);
                                Console.Write("Alisveris tutariniz : " + tahin.fiyat + "TL dir. Onayliyorsanız (Evet) yaziniz(buyuk kucuk harf duyarlidir.) :");
                                string index = Console.ReadLine();
                                if (index == "Evet")
                                {
                                    cld.mamulbakiyeHesapla(siparis);
                                    if (cld.bakiye == "0")
                                    {
                                        Console.Write("Bakiyeniz yetersiz oldugu icin islem yapilamamistir.Bakiye yuklemeyi secebilirsiniz.");
                                        Thread.Sleep(3000);
                                        Console.Clear();

                                    }
                                    else
                                    {
                                        Console.WriteLine("Tesekkurler !" + " " + cld.adi + " " + "Siparisiniz tamamlanmistir. Urununuz 3 is gunu icerisinde sirketinize ulastirilacaktir. ");
                                        Console.Write("PROFILINIZE YONLENDIRILIYORSUNUZ  ");
                                        for (var i = 0; i < 5; i++)
                                        {
                                            Console.Write(">");
                                            Thread.Sleep(2000);
                                        }
                                        cld.siparisTarihAta();
                                        Console.Clear();

                                    }

                                }



                            }
                            else if (secim == 2)
                            {
                                Console.Write("Siparis edeciğiniz miktari kg cinsinden yaziniz :");
                                string siparis = Console.ReadLine();
                                kSusam.ymamulfiyatHesapla(siparis);
                                Console.Write("Alisveris tutariniz : " + kSusam.fiyat + "TL dir. Onayliyorsanız (Evet) yaziniz(buyuk kucuk harf duyarlidir.) :");
                                string index = Console.ReadLine();
                                if (index == "Evet")
                                {
                                    cld.ymamulbakiyeHesapla(siparis);
                                    if (cld.bakiye == "0")
                                    {
                                        Console.Write("Bakiyeniz yetersiz oldugu icin islem yapilamamistir.Bakiye yuklemeyi secebilirsiniz.");
                                        Thread.Sleep(3000);
                                        Console.Clear();

                                    }
                                    else
                                    {
                                        Console.WriteLine("Tesekkurler !" + " " + cld.adi + " " + "Siparisiniz tamamlanmistir. Urununuz 3 is gunu icerisinde sirketinize ulastirilacaktir. ");
                                        Console.Write("PROFILINIZE YONLENDIRILIYORSUNUZ  ");
                                        for (var i = 0; i < 5; i++)
                                        {
                                            Console.Write(">");
                                            Thread.Sleep(2000);
                                        }
                                        cld.siparisTarihAta();
                                        Console.Clear();

                                    }

                                }
                            }


                        }
                        else
                        {
                            Console.Clear();
                            break;
                        }
                    }
                    else
                    {
                        Console.Clear();
                        Console.Write("!!Hatali Vergi Numarasi!! Eger musterimiz degilseniz bizimle iletisime gecip,kaydinizi gerceklestirebilirsiniz.Iyi gunler dileriz.");
                        Thread.Sleep(2000);
                        Console.Clear();
                        break;
                    }
                } while (true);
                
            } while (true);
            


            



        }
    }
}
