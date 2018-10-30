
package javaodev;

import java.util.Scanner;
import java.lang.reflect.*;


/**
 *
 * @author Burak Yıldırım
 *         M.İbrahim Turan
 * 
 * @since  09/03/2018
 * <p>
 * Belirtilen Java Kaynak Dosyasını Analiz Eden Program
 * </p>
 */

public class JavaOdev {

    
    public static String isimDuzelt(String s)//String tipiyle karsilastigimizda ekrana Class.java.lang String ciktisi veriyor.Bu fonksiyonla sadece String yazmasini sagladık.
    {
        if(s.matches("^class.*"))
        {
            return "String";
        }
        else
            return s ;
    }
    public static void main(String[] args) throws ClassNotFoundException
    {   
       
        
        Scanner scan = new Scanner(System.in);
        String sinif ;
        boolean hataYok = false;
        System.out.print("Sinif ismini giriniz(uzanti olmadan): ");
       do
        {
            try //Eger sinif ismi bulunamazsa hata verecek ve gerekli uyarilari yapacak.
            {
                sinif = scan.next();
                Class c= Class.forName("test." + sinif);
                Method[] metodlar = c.getDeclaredMethods();
                Field[] degisken = c.getDeclaredFields(); 
                hataYok = true;
                int metodSayi = metodlar.length ;
                int degiskenSayi = degisken.length;
                System.out.println("Sinif Adi : " + sinif);
                System.out.println("Alt Elemanlar :" + degiskenSayi + " adet");
                for(Field f : degisken)
                {
                    f.getName();
                    f.getType();
                    System.out.println("Veri ismi : " +f.getName() + " "+ "Tipi : " + isimDuzelt(f.getType().toString()));
                }
                System.out.println("Uye fonksiyonlar : " + metodSayi + " adet");
                
                for(Method m : metodlar)
                {
           
                     Parameter[] par = m.getParameters();
                     m.getReturnType();
                     m.getParameterCount();
                     m.getDeclaringClass();
                     System.out.println("Metod ismi: " + m.getName() + "\n" + "Dönüs Tipi : " + isimDuzelt(m.getReturnType().toString()) + "\n" + "Parametre Sayisi : " + m.getParameterCount());
                       
                     if(m.getParameterCount() >= 1)
                        {
                            for(Parameter p : par)
                            {
                               
                                     System.out.println(p.getName()+ " " + isimDuzelt(p.getType().toString()));//Parametre ismini ugrasmamıza ragmen alamadik.Kod calisiyor 
                                                                                                                    //fakat ciktisi arg0,arg1 seklinde oluyor.
                            }
                        }
                       
                     System.out.println("--------------------");
                }
                
                
            }   
            catch(ClassNotFoundException cnfe)
            {
                System.out.print("Sinif Bulunamadi Lütfen Tekrar Deneyiniz : ");
                System.out.println("NOT: Analiz etmek istediginiz .java uzantili dosyayi proje icerisindeki test dosyasinin icine atmayi unutmus olabilirsiniz");
                System.out.println("Veya .java dosyasına , package test eklememis olabilirsiniz");
            }
        }while(!hataYok);
        
        
        
        
    }
    
}
