/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaOdev4;
import java.io.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.*;
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

public class Islem 
{
    
    private final Lock alan =  new ReentrantLock();
    
    public BigInteger sonuc ;
    
    private int threadSayi = 10;//Thread sayisi bu degisken kullanilarak degistirilebilir.Ayrintili bilgi raporda mevcuttur.
    
    double sure = 0 ;
    
    public Islem()
    {
        sonuc = new BigInteger("0");
    }
    
    
    public void topla(BigInteger index)//Threadlerin senkronize edilmesi icin bu fonksiyon yazildi ve kod parcasi kilitlendi.
    {
       alan.lock();
       
        sonuc = sonuc.add(index);
        
       alan.unlock();
        
    }
    public void dosyayaYaz(Islem i)throws IOException
    {
        File dosya = new File("sonuc.txt");
        
        if(!dosya.exists())
            dosya.createNewFile();
        
        FileWriter dosyaYazici = new FileWriter(dosya,false);
        BufferedWriter yaz = new BufferedWriter(dosyaYazici);
        yaz.write(i.sonuc.toString());
        
        yaz.close();
        
    }
    public void paralelIslem(BigInteger index1 , BigInteger index2,Islem i)//Threadleri kullanarak islem yapan fonksiyon.
    {
      
       ExecutorService havuz  = Executors.newFixedThreadPool(threadSayi);
       String str = index1.toString();
       BigInteger tutucu ;
       long start = System.currentTimeMillis();
       if(str.length() < threadSayi)//hata almamak icin gereken bir kontrol kodu.
       {
           havuz.submit(new thread(new BigInteger(str),index2,i));
       }
       else
       {
       
       for(int j = 0 ; j < threadSayi ; j++)//Carpma islemini bölüyor ve threadlere gönderiyor.
       {
           
           if(j == threadSayi-1)
           {
            tutucu = new BigInteger(str.substring((str.length()/threadSayi)*j,str.length()));
           }
           else
           {
            tutucu = new BigInteger(str.substring((str.length()/threadSayi)*j,(str.length()/threadSayi)*(j+1)));
           }
           
           
           havuz.submit(new thread(tutucu,index2,i));//threadlerin olustuğu kod.
           
           
           
       }
      
       
       }

      
       havuz.shutdown();
       
       while(true)//Threadlerin kapanmasini bekliyor.
       {
        
          if (havuz.isTerminated())
          {
               break;
          }
          
          
          
       }
       long stop = System.currentTimeMillis();
       sure = (stop - start) / 1000.0;
    }
    
    public void seriIslem(BigInteger index1 , BigInteger index2 )
    {
        BigInteger tutucu ;
        String str = index1.toString();
        
       long start = System.currentTimeMillis();
       if(str.length() < threadSayi)//Hata alinmamasi icin yazılan kontrol kodu.
       {
           carp(new BigInteger(str),index2);
       }        
        
       else
       {
           for(int j = 0 ; j < threadSayi ; j++)//Carpma islemini threadSayi degiskenine bagli olarak bölüyor ve carp() fonksiyonuna gönderiyor.
       {
           
           if(j == threadSayi-1)
           {
            tutucu = new BigInteger(str.substring((str.length()/threadSayi)*j,str.length()));
           }
           else
           {
            tutucu = new BigInteger(str.substring((str.length()/threadSayi)*j,(str.length()/threadSayi)*(j+1)));
           }
           
           
           carp(tutucu,index2);
            
           
           
           
       }
           
       } 
       long stop = System.currentTimeMillis();
       sure = (stop-start)/1000.0;
        
    }
    
    public void carp(BigInteger index1 , BigInteger index2 )//Threadlerin icindeki run() fonksiyonunun aynisi.
    {
            
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
            
            

                
    }
    
}
