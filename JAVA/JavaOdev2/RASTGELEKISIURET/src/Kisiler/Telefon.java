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

public class Telefon 
{
    private int telNO[] = new int[11];
    
    public IMEINo imei = new IMEINo() ;
   
   public int[] telNoGetir()
   {
       return telNO;
   }
   
   public void telNoAta(int[] index)
   {
       System.arraycopy(index, 0 , telNO ,0 , 11);
   }
   
   public void telNoUret()
    {
        Random rand = new Random();
        telNO[0] = 0 ;
        telNO[1] = 5 ;
        while(true)
        {
           if(6 > telNO[2] && telNO[2] > 2  )
                    break;
           else
               telNO[2] = rand.nextInt(10);
        }
        telNO[3] = rand.nextInt(10);
        for(int i = 4 ; i < telNO.length ; i++ )
        {
            telNO[i] = rand.nextInt(10);
        }
    }
  
    
}
