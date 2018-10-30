/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

/**
 *
 * @author Yıldırım
 */
public class insan
{
    public String insanAd;
    int insanYas;
    
    public void Ağla()
    {
       System.out.println("AGLA");
    }
    
    public String adGetir(int ad,String soyAd)
    {
        return insanAd;
    }
    
    private int yasGetir()
    {
        return insanYas;
    }
    
    public void adDegistir(String yeniAd)
    {
        insanAd = yeniAd;
    }
    
}
