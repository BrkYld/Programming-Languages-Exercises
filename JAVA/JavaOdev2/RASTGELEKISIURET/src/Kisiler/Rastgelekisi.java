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


public class Rastgelekisi 
{
    
   
      
   public String RastgeleKisiUret() throws FileNotFoundException,IOException
   {
       Kisi kisiler = new Kisi();
       kisiler.kimlik.tcNoUret();
       String tcNO = "";
       for(int i =0 ; i< kisiler.kimlik.tcNoGetir().length ; i++)
       {
           tcNO = tcNO + Integer.toString(kisiler.kimlik.tcNoGetir()[i]) ;
       }
       kisiler.telefon.imei.imeiUret();
       String imei = "" ;
       for(int i =0 ; i< kisiler.telefon.imei.imeiNOGetir().length ; i++)
       {
           imei = imei + Integer.toString(kisiler.telefon.imei.imeiNOGetir()[i]) ;
       }
       kisiler.telefon.telNoUret();
       String telNO = "";
       for(int i =0 ; i< kisiler.telefon.telNoGetir().length ; i++)
       {
           telNO = telNO + Integer.toString(kisiler.telefon.telNoGetir()[i]) ;
       }
       
       kisiler.yasAta();
       String yas = Integer.toString(kisiler.yasGetir());
       kisiler.isimAta();
       return tcNO + " " + kisiler.isimGetir() + " " + yas + " " + telNO + " " + "(" + imei + ")" ;
   } 
  
    
   
    
   
    
    
   
       
    
    
    
}
