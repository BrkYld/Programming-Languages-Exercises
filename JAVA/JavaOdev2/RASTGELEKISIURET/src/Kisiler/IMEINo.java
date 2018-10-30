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


import java.util.Random;

public class IMEINo
{
  
  private int imeiNO[] = new int[15];
  public int[] imeiNOGetir()
  {
    return imeiNO;
  }
  public void imeiUret()
  {
      Random rand = new Random();
      int yedek[] = new int[15];
      int toplam = 0 ;
      
      for(int i = 0 ; i < imeiNO.length-1 ; i++)
      {
        imeiNO[i] = rand.nextInt(10);
          
      }
      
      System.arraycopy(imeiNO, 0 , yedek ,0 , 15);
      
      for(int i = 0 ; i < yedek.length-1 ; i++)
      {
          if(i%2 != 0)
          {
            yedek[i] = yedek[i] * 2 ;
          }
         
      }
      for(int i = 0 ; i < yedek.length-1 ; i++)
      {
          if(yedek[i] >= 10)
          {
            toplam = (yedek[i] % 10) + toplam ;
            yedek[i] = yedek[i] / 10 ;
            toplam = yedek[i] + toplam ;
          }
          else
          {
            toplam = yedek[i] + toplam ;
          }
      
      }
      
      if(toplam % 10 == 0 )
      {
        imeiNO[14] = 0 ;
      }
      else
      {
        imeiNO[14] = 10 - (toplam % 10) ;
      }
      
  }
  
  
  public String imeiKontrol(int[] index)
  {
      int yedek[] = new int[15];
      int toplam = 0 ;
      int sonRakam ;
      if(index.length != 15)
      {
          return "Gecersiz";
      }
      else
      {
          System.arraycopy(index, 0 , yedek ,0 , 15);
      
          for(int i = 0 ; i < yedek.length-1 ; i++)
          {
             if(i%2 != 0)
             {
                yedek[i] = yedek[i] * 2 ;
             }
         
          }
          for(int i = 0 ; i < yedek.length-1 ; i++)
          {
            if(yedek[i] >= 10)
            {
                toplam = (yedek[i] % 10) + toplam ;
                yedek[i] = yedek[i] / 10 ;
                toplam = yedek[i] + toplam ;
            }
            else
            {
                toplam = yedek[i] + toplam ;
            }
      
          }
      
          if(toplam % 10 == 0 )
          {
            sonRakam = 0 ;
          }
          else
          {
            sonRakam = 10 - (toplam % 10) ;
          }
          
          if(index[14] == sonRakam )
          {
              return "Gecerli";
          }
          else
              return "Gecersiz";
      }
      
      
  }
  
  
    
    
}
