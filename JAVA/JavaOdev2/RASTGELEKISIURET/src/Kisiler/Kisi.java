/** 
 * 
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * @since 01.04.2018
 * <p>
 * TC kimlik ve IMEI Kontrolü yapan program simulasyonu
 * </p>
 */

package Kisiler;


import java.io.*;
import java.util.Random;

public class Kisi 
{
    
   private String isimSoyİsim ;
   public String isimGetir()
   {
       return isimSoyİsim;
   }
   public void isimAta() throws FileNotFoundException,IOException
   {
       Random rand = new Random();
       FileReader dosya = new FileReader("random_isimler.txt");
       BufferedReader br = new BufferedReader(dosya);
       int index = rand.nextInt(3000);
       if(index == 0)
            index = 254;
       int i = 0;
       String str;
       while((str = br.readLine()) != null )
       {
           if(i == index)
           {
               isimSoyİsim = str;
               br.close();
               break;
           }
           i++;
       }

        
   }
  
   private int yas;
   public int yasGetir()
   {
       return yas;
   }
   public void yasAta()
   {
       Random rand = new Random();
       yas = rand.nextInt(100);
   }
   
   
   public KimlikNo kimlik = new KimlikNo();
   
   public Telefon telefon = new Telefon();
    
    
    
}
