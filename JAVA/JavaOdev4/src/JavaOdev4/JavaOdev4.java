/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaOdev4;

import java.io.IOException;
import java.math.BigInteger;
/**
 *
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * 
 * @since  09/05/2018
 * <p>
 * Hatalı Carpma İslemi Yapan Program
 * </p>
 */

public class JavaOdev4 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException, IOException
    {
        
       
        Islem i = new Islem();
        
        Islem j = new Islem();
        
        BigInteger x = new BigInteger("1805656456456455498979878879516554645487899999999999999999566545612312312313");
        
        BigInteger y = new BigInteger("24465465497987897897564312345646879879879879646512313564564579879879879798");
        
      
        while(true) //Sayilar Uretiliyor.
        {
           if(y.toString().length() >= 100000)//Buradan basamak sayisi ayarlanip test edilebilir. Su anda 150.000 basamaklı iki sayi üretiyor ve program yaklasik 13 saniye sürüyor.
            {                                 //Basamak sayisi arttikca program calisma süresi artacaktir.
                break;
            }
            x = x.multiply(x);
            
            y = y.multiply(y);
            
        }
         
        System.out.println("Islemler basladi... ");
        
        System.out.println("x basamak sayisi :" + x.toString().length());
        
        System.out.println("y basamak sayisi :" + y.toString().length());

        i.paralelIslem(y,x, i);

        j.seriIslem(y, x);

        i.dosyayaYaz(i);

        System.out.println("Paralel islem suresi : "+ i.sure + " saniye");
        
        System.out.println("Seri islem suresi : "+ j.sure + " saniye");
        
        System.out.println("Sonuc , sonuc.txt adli dosyaya yazildi.");
         
         
    }
    
}
