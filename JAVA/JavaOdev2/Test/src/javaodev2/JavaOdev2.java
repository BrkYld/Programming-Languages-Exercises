/** 
 * 
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * @since 01.04.2018
 * <p>
 * TC kimlik ve IMEI Kontrolü yapan program simulasyonu
 * </p>
 */

package javaodev2;
import Kisiler.*;
import java.io.*;
import java.util.Scanner;


public class JavaOdev2 
{

    
    public static void main(String[] args) throws IOException
    {
     
       Scanner scan = new Scanner(System.in);
       Rastgelekisi kisiler = new Rastgelekisi();
       Kisi kisi = new Kisi();
       
       do
       {
            System.out.println("1 - Rastgele Kisi Uret");
            System.out.println("2 - Uretilmis Dosyayi Kontrol Et");
            System.out.println("3 - Cikis");
            System.out.print("Secim : ");
             int secim = scan.nextInt();
       
       
       
            if(secim == 1)
            {
                System.out.print("Kac kisi uretilsin ? : ");
                int kisiSayi = scan.nextInt() ;
                File dosya = new File("Kisiler.txt");
                if (!dosya.exists()) 
                {
                dosya.createNewFile();
                }
                 BufferedWriter yaz = new BufferedWriter(new FileWriter(dosya, true));
                 for(int i = 0 ; i < kisiSayi ; i++)
                 {
                     yaz.write(kisiler.RastgeleKisiUret());
                     yaz.newLine();
                 }
                 
                 
                 yaz.close();
            }
            else if(secim == 2)
            {
                String str ;
                String satir[];
                int tcNO[] = new int [11];
                int imei[] = new int[15];
            
                String yedek;
                BufferedReader oku = new BufferedReader(new FileReader("Kisiler.txt"));
            
                while((str = oku.readLine()) != null )
                {
                    yedek = str ;
                    satir = str.split(" ");
                    System.out.println(satir[1] + " " +  satir[2]);
                
                    for(int i = 0 ; i < 11 ; i++)
                    {
                    if(satir[0].length() != 11)
                        break;
                        
                    tcNO[i] = Integer.parseInt(satir[0].substring(i, i+1));
                    }
                    if(satir[0].length() != 11)
                    {
                        System.out.println("TC :" + satir[0] + "(" + "Gecersiz" + ")");
                    }
                    else
                    {
                        System.out.println("TC :" + satir[0] + "(" + kisi.kimlik.tcNoKontrol(tcNO) + ")");
                    }
                
                
                
                    for(int i = 0 ; i < 15 ; i++)
                    {
                        if(satir[5].length() != 17)
                            break;
                        imei[i] = Integer.parseInt(satir[5].substring(i+1,i+2));
                    }
               
                    if(satir[5].length() != 17)
                    {
                        System.out.println("IMEI :" + satir[5].substring(1,satir[5].length()-1) + "(" + "Gecersiz" + ")");
                    }
                    else
                    {
                        System.out.println("IMEI :" + satir[5].substring(1,satir[5].length()-1) + "(" + kisi.telefon.imei.imeiKontrol(imei) + ")");
                    }
               
                
                }
            
            }
       
            else
            {
            
                break;
            }
       
        
           System.out.println();
       
           
           
       }while(true);
       
       
       
       
       
       
    }
    
}
