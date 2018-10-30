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

public class KimlikNo 
{
    
    int tcNO[] = new int[11];
    
    public int[] tcNoGetir()
    {
        return tcNO;
    }
    
    public void tcNoUret()
    {
        Random rand = new Random();
        
        for(int i = 0 ; i < tcNO.length-2 ; i++)
        {
            tcNO[i] = rand.nextInt(10);
            
            if(tcNO[0] == 0)
            {
                tcNO[0] = rand.nextInt(10);
            }
            
           
        }
        tcNO[9] = (((tcNO[0] + tcNO[2] + tcNO[4] + tcNO[6] + tcNO[8])*7 )-(tcNO[1] + tcNO[3] + tcNO[5]+tcNO[7])) % 10 ;
        tcNO[10] =(tcNO[0] + tcNO[2] + tcNO[4] + tcNO[6] + tcNO[8] + tcNO[1] + tcNO[3] + tcNO[5]+tcNO[7] + tcNO[9]) % 10;
         
    }
   
    
    public String tcNoKontrol(int[] index)
    {
        if(index.length != 11)
        {
             return "Gecersiz";
        }
        else if(index[9] != (((index[0] + index[2] + index[4] + index[6] + index[8])*7 )-(index[1] + index[3] + index[5]+index[7])) % 10)
        {
             return "Gecersiz";
        }
        else if(index[10] != (index[0] + index[2] + index[4] + index[6] + index[8] + index[1] + index[3] + index[5] + index[7] + index[9]) % 10)
        {
            return "Gecersiz";
        }
        else
        {
            return "Gecerli";
        }
    }
    
    
}
