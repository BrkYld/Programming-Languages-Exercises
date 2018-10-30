/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaOdev4;
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

public class thread extends Thread
{
    Islem islem;//Thread de olusan sonucu bir class degiskenine atmak icin parametre aliyor.
    private BigInteger index1;
    private BigInteger index2;
   
   
    public thread(BigInteger Index , BigInteger index , Islem i)
    {
        index1 = Index; 
        index2 = index;
        islem = i ;
        
    }
   
    
    @Override
    public void run()//Run fonksiyonu ici İslem sinifindaki carp() Fonksiyonunun aynisi olacak sekilde tasarlandi.
    {
        
         BigInteger sonuc = BigInteger.valueOf(0);
         while(true)
            {
                if(index1.compareTo(BigInteger.valueOf(10)) < 0)
                {
                 
                    
                    
                   
                    sonuc = sonuc.add(index1.multiply(index2));
                    
                    
                    break;
                }
                else
                {
                    
                    sonuc = sonuc.add(index2.multiply(index1.mod(BigInteger.valueOf(10))));
                    index1 = index1.divide(BigInteger.valueOf(10));
                    
                   
                    
                }
        
      
            }
         
         islem.topla(sonuc);
    }
   
    
    
    
    
}
