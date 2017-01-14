#include "header.h"

void patlamaEfektEkle(){
     strcpy(patlamaResim[0],"efektler/patlama/1.bmp");
     strcpy(patlamaResim[1],"efektler/patlama/2.bmp");
     strcpy(patlamaResim[2],"efektler/patlama/3.bmp");
     strcpy(patlamaResim[3],"efektler/patlama/4.bmp");
     strcpy(patlamaResim[4],"efektler/patlama/5.bmp");
     strcpy(patlamaResim[5],"efektler/patlama/6.bmp");
     strcpy(patlamaResim[6],"efektler/patlama/7.bmp");
     strcpy(patlamaResim[7],"efektler/patlama/8.bmp");
     strcpy(patlamaResim[8],"efektler/patlama/9.bmp");
     strcpy(patlamaResim[9],"efektler/patlama/10.bmp");
     strcpy(patlamaResim[10],"efektler/patlama/11.bmp");
     strcpy(patlamaResim[11],"efektler/patlama/12.bmp");
     strcpy(patlamaResim[12],"efektler/patlama/13.bmp");
     strcpy(patlamaResim[13],"efektler/patlama/14.bmp");
     strcpy(patlamaResim[14],"efektler/patlama/15.bmp");
     strcpy(patlamaResim[15],"efektler/patlama/16.bmp");
     strcpy(patlamaResim[16],"efektler/patlama/17.bmp");
     strcpy(patlamaResim[17],"efektler/patlama/18.bmp");
     strcpy(patlamaResim[18],"efektler/patlama/19.bmp");
     strcpy(patlamaResim[19],"efektler/patlama/20.bmp");
     strcpy(patlamaResim[20],"efektler/patlama/21.bmp");     
     }


void anaEkran(){
     
     
     char menu[3][20]={"Basla","Yuksek Puanlar","Cikis"};
     
     menuResim=load_bitmap("oyuncular/ekranTam.bmp",NULL);
     draw_sprite( tazele, menuResim, 0, 0);

    
     rectfill(tazele,_x+90,_y+70,_x+280,_y+120,makecol(222,255,222));      
     rect(tazele,_x+90,_y+70,_x+280,_y+120,makecol(255,0,0));
     textprintf_ex(tazele,font,_x+170,_y+90,makecol(255,0,0),-1,"%s",menu[0]);          
  
     rectfill(tazele,_x+90,_y+140,_x+280,_y+190,makecol(222,255,222));      
     rect(tazele,_x+90,_y+140,_x+280,_y+190,makecol(255,0,0));
     textprintf_ex(tazele,font,_x+130,_y+160,makecol(255,0,0),-1,"%s",menu[1]);
     
     rectfill(tazele,_x+90,_y+210,_x+280,_y+260,makecol(222,255,222));      
     rect(tazele,_x+90,_y+210,_x+280,_y+260,makecol(255,0,0));
     textprintf_ex(tazele,font,_x+170,_y+230,makecol(255,0,0),-1,"%s",menu[2]);
  
  
}//ana ekran


void mouseKontrol(){
                
                   
       if(mouse_b&1)  // (mouse_b & 1) Eðer mouse'un sol tuþuna týklandýysa true çevirir.
         { 
          
          
          switch (aktif) 
          {
                 case 0 : 
                      {
                       if((mouse_x>(_x+90) && mouse_y>_y+70) && (mouse_x<_x+280 && mouse_y<_y+120) )//AnaEkranda oyuna baþlayý týkladýktan sonra isim alýyoruz kullanýcýdan
                          {
                       adSoyad();
                         aktif =1;
                          }
                      
                     if((mouse_x>(_x+90) && mouse_y>_y+140) && (mouse_x<_x+280 && mouse_y<_y+190) )
                          
                          {
                          
                          yuksekSkor();
                          aktif =2;
                                          
                         }
                     
                    if((mouse_x>_x+90 && mouse_y>_y+210) && (mouse_x<_x+280 && mouse_y<_y+260))
                           {
                         
                         //oyuncular[0].Ohak==0;
                         //oyuncular[1].Ohak==0;
                         //break;
                         kapat=1;
                         //return -1;
                         
                          //END_OF_MAIN();
                           }
                 }//case 0
                 break;
                 
                case 1 : 
                      
                      {
                     
                     if((mouse_x>400 && mouse_y>400) && (mouse_x<500 && mouse_y<440) )
                           {
                           klavyeSayac=0, isimSayac1=0, isimSayac2=0, klavyeGirdisi=1;
                           oyunEkran();        
                            aktif = 0;
                           }
                        if(klavyeGirdisi>2)
                          {
                              if(mouse_x>500 && mouse_x<630 && mouse_y>290 && mouse_y<340)
                              {
                                             klavyeGirdisi=4;
                              }        
                              else if(mouse_x>640 && mouse_x<770 && mouse_y>290 && mouse_y<340)
                              {
                                            
                                             klavyeGirdisi=4;
                              }
                          }
             
                          if(klavyeGirdisi==2 && mouse_x>600 && mouse_x<750 && mouse_y>470 && mouse_y<520)
                          {
                                              aktif=2;
                          }   
                       }//case 1
                       
                 
                  case 2 : 
                      {
                       if((mouse_x>400 && mouse_y>400) && (mouse_x<500 && mouse_y<440) )
                          {
                     anaEkran();
                     aktif = 0;
                          }
                  
                 }//case 2
                 
          }//switch         
                    
    
       }
}//mouse kontrol

void ekranCagir(){
             switch(aktif)
             {
                  case 0 : anaEkran(); break ;
                  case 1 : adSoyad(); break ;
                  case 2 : yuksekSkor(); break ;
                default :            break; 
                     }
             blit(tazele,screen,0,0,0,0,1000,600);
             rest(10);                                  
             clear_to_color(tazele,makecol(255,255,255));
}//EkranCagir

void adSoyad(){ 
               blit(tazele,tazele,0,0,0,0,1000,600);
               rest(10);                                  
               clear_to_color(tazele,makecol(255,255,255));
          
             rect(tazele,80,100,560,380,makecol(255,0,0));
              
              if(keypressed())
                {
                                
                          rest(50);
                          char harf = readkey();
                          
                          if(klavyeGirdisi==1)
                          {
                              if(harf==13)
                              {
                              if(strcmp(oyuncular[0].Oad,"")!=0){
                                klavyeGirdisi=2;
                                isimSayac1=klavyeSayac;
                                klavyeSayac=0;
                                }else{
                                      klavyeGirdisi=1;
                                      isimSayac1=klavyeSayac;
                                      klavyeSayac=0;
                                      }
                              }
                              else if(klavyeSayac>0 && harf==8)
                              {
                                 oyuncular[0].Oad[klavyeSayac-1]=32;
                                 klavyeSayac--;
                              }
                              else if(klavyeSayac<40)
                              {
                                 oyuncular[0].Oad[klavyeSayac]=harf;
                                 klavyeSayac++;
                              }
                          }
                          else if(klavyeGirdisi==2)
                          {
                               if(harf==13)
                              {
                                  
                                  klavyeGirdisi=2;
                                  isimSayac2=klavyeSayac;
                                  klavyeSayac=0;
                              }
                              else if(klavyeSayac>0 && harf==8)
                              {
                                 oyuncular[1].Oad[klavyeSayac-1]=32;
                                 klavyeSayac--;
                              }
                              else if(klavyeSayac<40)
                              {
                                 oyuncular[1].Oad[klavyeSayac]=harf;
                                 klavyeSayac++;
                              }
                          }  
                        
          }              
          
          if(klavyeGirdisi==1)
          {
                 rect(tazele,290,150,500,170,makecol(255,0,0));             
          }
          else if(klavyeGirdisi==2)
          {
                 rect(tazele,290,190,500,210,makecol(255,0,0));
          }
          
          textprintf_ex(tazele,font,250,120,makecol(255,0,0),-1,"Oyuncu Bilgileri");
          textprintf_ex(tazele,font,150,160,makecol(0,0,0),-1,"1.Oyuncu Adi    : %s",oyuncular[0].Oad);              
          textprintf_ex(tazele,font,150,200,makecol(0,0,0),-1,"2.Oyuncu Adi    : %s",oyuncular[1].Oad); 
          
          
          
          if(strcmp(oyuncular[0].Oad,"")!=0 && strcmp(oyuncular[1].Oad,"")!=0){
          rectfill(tazele,400,400,500,440,makecol(222,222,222));
          rect(tazele,400,400,500,440,makecol(255,0,0));
          textprintf_ex(tazele,font,435,418,makecol(0,0,255),-1,"Onay");
          }
            
}//Ad Soyad

 void yuksekSkor(){
     int Px=100,Py=200;
     
     blit(tazele,tazele,0,0,0,0,640,480);
     rest(5);                                  
     clear_to_color(tazele,makecol(255,255,255));
      
      //left top right bottom
      
      //Oyuncularr Ve Puanlarý 
      //MaxPuan Numaralar
      
       int sayac=0, skor, puan;
       char ad[30];
       
      dosyaOku=fopen("dosyalar/skorlar.txt","r+");
      if(dosyaOku==NULL){
                    allegro_message("Skorlar Okunamadý");
      }else{
      //for (i = 0 ; i<3; i++ )
      while(sayac<3){
       fscanf(dosyaOku,"%d%s%d",&skor,ad,&puan);
        
        rectfill(tazele,Px,Py+(sayac*40),Px+20,Py+20+(sayac*40),makecol(222,255,222));      
        rect(tazele,Px,Py+(sayac*40),Px+20,Py+20+(sayac*40),makecol(255,0,0));
        textprintf_ex(tazele,font,Px+8,Py+8+(sayac*40),makecol(255,0,0),-1,"%d",sayac+1);
        
        textprintf_ex(tazele,font,Px+80,Py+5+(sayac*40),makecol(255,0,0),-1,"%s",ad);
        textprintf_ex(tazele,font,Px+300,Py+5+(sayac*40),makecol(255,0,0),-1,"%d",puan);     
        sayac++;
        }
      }//if dosya
   
     // Ýsim Puan
     rectfill(tazele,Px+60,Py-50,Px+220,Py-10,makecol(222,255,222));      
     rect(tazele,Px+60,Py-50,Px+220,Py-10,makecol(255,0,0));
     textprintf_ex(tazele,font,Px+98,Py-35,makecol(255,0,0),-1,"%s","Oyuncu Ismi");
     
     rectfill(tazele,Px+240,Py-50,Px+400,Py-10,makecol(222,255,222));      
     rect(tazele,Px+240,Py-50,Px+400,Py-10,makecol(255,0,0));
     textprintf_ex(tazele,font,Px+308,Py-35,makecol(255,0,0),-1,"%s","Puan");
     
     
     

     rectfill(tazele,400,400,500,440,makecol(222,222,222));
     rect(tazele,400,400,500,440,makecol(255,0,0));
     textprintf_ex(tazele,font,415,418,makecol(0,0,255),-1,"Menuye Don");
     
}//yuksekSkorlar
     
void oyunEkran(){
     ekranTemizle=create_bitmap(640,480);
     set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
     oyunBaslat();
}//oyunEkraný
     
void oyunBaslat(){
   
   
   
   cikis=0;  
   binaOlustur();  
   oyuncuOlustur();
   yonSec(aciSayac, 1);
  
   
  
  int i;              
  hizSayac=0;
  int hizSayisi=20; 
 
  int hizlar[hizSayisi], hiz=0;
       
       for(i=0;i<hizSayisi;i++){
               hizlar[i]=i*20;
               }
       
   int oyuncuNo;
   aciSayac=0;           
  
   while(cikis!=1){
   
  
   //saniye++;
   
   textprintf(screen, font, 10, 5, yaziRenk, "O1 > %-3d : %3d < O2 sure: %-2d",oyuncular[0].Opuan, oyuncular[1].Opuan);       
   oyuncuNo=oyuncuNoGetir();        
   
  
   if(oyuncuNo==-1){
                    
                    if(oyuncular[0].Opuan>oyuncular[1].Opuan){
                                                        allegro_message("1.Oyuncu Kazandý");
                                                        dosyayaYazdir(0);
                                                        strcpy(oyuncular[0].Oad,"");
                                                        strcpy(oyuncular[1].Oad,"");
                                                        break;      
                                                              }else if(oyuncular[0].Opuan<oyuncular[1].Opuan){
                                                                    allegro_message("2.Oyuncu Kazandý");
                                                                    dosyayaYazdir(1);
                                                                    strcpy(oyuncular[0].Oad,"");
                                                                    strcpy(oyuncular[1].Oad,"");
                                                                    break;
                                                                    }else if(oyuncular[0].Opuan==oyuncular[1].Opuan){
                                                                          allegro_message("KAZANAN YOK OYUN YENIDEN BASLIYOR");  
                                                                          blit(ekranTemizle, screen, 0,0,0,0, 640, 480);
                                                                          aciSayac=0, hizSayac=0;
                                                                          oyunBaslat();
                                                                          break;
                                                                          }
                   // allegro_message("GAMEOVER");
                    rest(30);
                    
                   // break;
                    
   }else{
      
       
   	if(key[KEY_ESC]){
                    // strcpy(oyuncular[0].Oad,"");
                    // strcpy(oyuncular[1].Oad,"");
                    cikis=1;
                               
	}else{
   	
       	
           if(key[KEY_E]){
                         
                          
                            if(hizSayac==(hizSayisi-1)){
                                            hizSayac=hizSayisi-1;
                                            }else{
                             hizSayac++;
                             }
                            
                              hiz=hizlar[hizSayac];
                              rest(120);
                              //saniye=saniye+(120/100);                   
           }else if(key[KEY_Q]){
                 if(hizSayac==0){
                                            hizSayac=0;
                                            }else{
                             hizSayac--;
                             }
                            
                              hiz=hizlar[hizSayac];
                              rest(120);              
                              saniye=saniye+(120/100);
                 
                 }else if(key[KEY_W]){
                                   
                                    if(aciSayac==64){
                                               aciSayac=64;
                                          }else if(aciSayac<64){
                                             aciSayac=aciSayac+8;
                                          }
                                     yonSec(aciSayac, oyuncuNo);
                                    
                                    
                                    rest(120);
                                    //saniye=saniye+(120/100);
           }else if(key[KEY_S]){
                                     
                                    if(aciSayac==0){
                                               aciSayac=0;
                                          }else if(aciSayac>0){
                                             aciSayac=aciSayac-8 ;
                                          }
                                    yonSec(aciSayac, oyuncuNo);
                                    
                                    
                                    rest(120);
                                    //saniye=saniye+(120/100);
           }else if(key[KEY_D]){
                                  
                                    hiz=hizlar[hizSayac];     
                                  
                                         
                                         if(hiz==0){
                                              continue;      
                                         }else{
                                         
                                        
                                         
                                         topuAt(oyuncuNo, oyuncuNo, hiz, aciSayac);
                                         
                                              
                                         }
                                         
                                         
                                         rest(120);
                                        // saniye=saniye+(120/100);
           }//key D
                 
        textprintf(screen, font, SCREEN_W - 220, 5, yaziRenk, "HizSayac : %-3d -> Hiz : %-3d",hizSayac ,hizlar[hizSayac]);     		
   	}
   		              
      }     //if gameover  
      
      
      
             
        
  }//while
  
  if(kapat==1){
               
               }else{
  remove_mouse();
  remove_keyboard();
  remove_timer(); 
  allegro_exit();
  aktif=0;
  main();
}
};

void binaOlustur(){
     int sayac=0, sayi;
     int sonBina=10;
     while(sayac<6){
                    sayi=rand()%4;
                    
                    switch(sayi){
                                 case 0:
                                      strcpy(binalar[sayac].resim,"binalar/01.bmp");
                                      binalar[sayac].yukseklik=280;
                                      binalar[sayac].genislik=100;
                                      binalar[sayac].y=SCREEN_H-280;
                                      bina[sayac]=load_bitmap(binalar[sayac].resim,NULL);
                                      draw_sprite( screen, bina[sayac], sonBina, binalar[sayac].y);
                                      binalar[sayac].x=sonBina;
                                      sonBina=sonBina+binalar[sayac].genislik+5;                                    
                                      break;
                                      
                                 case 1:
                                      strcpy(binalar[sayac].resim,"binalar/02.bmp");
                                      binalar[sayac].yukseklik=200;
                                      binalar[sayac].genislik=100;
                                      binalar[sayac].y=SCREEN_H-200;
                                      bina[sayac]=load_bitmap(binalar[sayac].resim,NULL);
                                      draw_sprite( screen, bina[sayac], sonBina, binalar[sayac].y);
                                      binalar[sayac].x=sonBina;  
                                      sonBina=sonBina+binalar[sayac].genislik+5; 
                                      break;
                                      
                                 case 2:
                                      strcpy(binalar[sayac].resim,"binalar/03.bmp");
                                      binalar[sayac].yukseklik=220;
                                      binalar[sayac].genislik=100;
                                      binalar[sayac].y=SCREEN_H-220;
                                      bina[sayac]=load_bitmap(binalar[sayac].resim,NULL);
                                      draw_sprite( screen, bina[sayac], sonBina, binalar[sayac].y);
                                      binalar[sayac].x=sonBina;  
                                      sonBina=sonBina+binalar[sayac].genislik+5; 
                                      break;
                                 case 3:
                                      strcpy(binalar[sayac].resim,"binalar/04.bmp");
                                      binalar[sayac].yukseklik=100;
                                      binalar[sayac].genislik=100;
                                      binalar[sayac].y=SCREEN_H-100;
                                      bina[sayac]=load_bitmap(binalar[sayac].resim,NULL);
                                      draw_sprite( screen, bina[sayac], sonBina, binalar[sayac].y);
                                      binalar[sayac].x=sonBina;  
                                      sonBina=sonBina+binalar[sayac].genislik+5; 
                                      break;
                                 }//switch case
                    
                   
                    
                    sayac++;
                    }//while
     
     
     
          
     
}//binaOlustur

int binaYik(int Ono, int Tx,int Ty){
     int sayac=0, resimSayac=0;
     BITMAP *binaYenile;
     
     oA=load_bitmap(oyuncular[0].Oresim,NULL);
     oB=load_bitmap(oyuncular[1].Oresim,NULL);
     
     switch(Ono){
                 case 0:
                       
                       while(sayac<6){
                        if(Tx>binalar[sayac].x && Tx<(binalar[sayac].x+100) && Ty>binalar[sayac].y && Ty<(binalar[sayac].y+binalar[sayac].yukseklik)) {
                        circlefill(screen,Tx,Ty,3,siyah);
                        for(resimSayac=0;resimSayac<21;resimSayac++){
                                                                     
                        patlama=load_bitmap(patlamaResim[resimSayac],NULL);
                        draw_sprite(screen,patlama,binalar[sayac].x,binalar[sayac].y);
                        
                       
                        
                        
                        rest(30);
                        }
                        
                        binalar[sayac].y=binalar[sayac].y+80;
                        draw_sprite(screen, bina[sayac],binalar[sayac].x,binalar[sayac].y);
                        
                        if(oyuncular[Ono].Oy+30==binalar[sayac].y-80 && oyuncular[Ono].Ox==binalar[sayac].x+43){
                         rectfill(screen,oyuncular[Ono].Ox-5,oyuncular[Ono].Oy-10,oyuncular[Ono].Ox+25,oyuncular[Ono].Oy+35,siyah);                                             
                                                                   
                        oyuncular[Ono].Oy=binalar[sayac].y-30;
                        
                        if(oyuncular[Ono].Oy>450){
                                                   oyuncular[Ono].Ohak=0;
                                                   oyuncular[!Ono].Ohak=0;
                                                  //break;
                                                   }else{
                                                         draw_sprite( screen, oA, oyuncular[Ono].Ox, oyuncular[Ono].Oy); 
                                                         }
                       
                        }else if(oyuncular[!Ono].Oy+30==binalar[sayac].y-80 && oyuncular[!Ono].Ox==binalar[sayac].x+43){
                        rectfill(screen,oyuncular[!Ono].Ox-5,oyuncular[!Ono].Oy-10,oyuncular[!Ono].Ox+25,oyuncular[!Ono].Oy+35,siyah);                                             
                                                                   
                        oyuncular[!Ono].Oy=binalar[sayac].y-30;
                        if(oyuncular[!Ono].Oy>450){
                                                   oyuncular[Ono].Ohak=0;
                                                   oyuncular[!Ono].Ohak=0;
                                                   //break;
                                                   }else{
                        draw_sprite( screen, oB, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy);
                                     }
                              }
                        
                       return 1;
                         //return 1;                                                
                              }else{
                                 sayac++;
                                 }
                                 
                         }
                 break;
                 case 1:
                      while(sayac<6){
                        if(Tx>binalar[sayac].x && Tx<(binalar[sayac].x+100) && Ty>binalar[sayac].y && Ty<(binalar[sayac].y+binalar[sayac].yukseklik)) {
                        
                        circlefill(screen,Tx,Ty,3,siyah);
                        for(resimSayac=0;resimSayac<21;resimSayac++){
                                                                     
                        patlama=load_bitmap(patlamaResim[resimSayac],NULL);
                        draw_sprite(screen,patlama,binalar[sayac].x,binalar[sayac].y);
                        rest(30);
                        }
                        
                        binalar[sayac].y=binalar[sayac].y+80;
                        draw_sprite(screen, bina[sayac],binalar[sayac].x,binalar[sayac].y);
                        
                       
                        if(oyuncular[Ono].Oy+30==binalar[sayac].y-80 && oyuncular[Ono].Ox==binalar[sayac].x+43){
                        rectfill(screen,oyuncular[Ono].Ox-5,oyuncular[Ono].Oy-10,oyuncular[Ono].Ox+25,oyuncular[Ono].Oy+35,siyah);
                        oyuncular[Ono].Oy=binalar[sayac].y-30;
                        if(oyuncular[Ono].Oy>450){
                                                  //break;
                                                  oyuncular[Ono].Ohak=0;
                                                   oyuncular[!Ono].Ohak=0;
                                                  //break;
                                                   }else{
                                                         draw_sprite( screen, oB, oyuncular[Ono].Ox, oyuncular[Ono].Oy);  
                                                         }
                        
                                           
                        }else if(oyuncular[!Ono].Oy+30==binalar[sayac].y-80 && oyuncular[!Ono].Ox==binalar[sayac].x+43){
                        rectfill(screen,oyuncular[!Ono].Ox-5,oyuncular[!Ono].Oy-10,oyuncular[!Ono].Ox+25,oyuncular[!Ono].Oy+35,siyah);                                             
                                                                   
                        oyuncular[!Ono].Oy=binalar[sayac].y-30;
                        if(oyuncular[!Ono].Oy>450){
                                                  oyuncular[Ono].Ohak=0;
                                                   oyuncular[!Ono].Ohak=0;
                                                   //break;
                                                   }else{
                        draw_sprite( screen, oA, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy);
                                     }
                              }
                       
                       return 1;
                         //return 1;                                                
                              }else{
                                 sayac++;
                                 }
                                 
                         }
                      
                      break;
                 }
                 
    
     
     }//binaYik
     
     
void oyuncuOlustur(){
	int rSayi;
	
	rSayi=rand()%3;
	

                       oyuncular[0].Ox=binalar[rSayi].x+43;
                       oyuncular[0].Oy=binalar[rSayi].y-30;
   
    oyuncular[0].Opuan=0;
    oyuncular[0].Ohak=3;
    oyuncular[0].Osira=0;
    //strcpy(oyuncular[0].Oad,"");
    strcpy(oyuncular[0].Oresim, "oyuncular/yeniO.bmp");
    strcpy(oyuncular[0].aktifResim,"oyuncular/yeniOaktif.bmp");
    
    oA=load_bitmap(oyuncular[0].Oresim,NULL);
    draw_sprite( screen, oA, oyuncular[0].Ox, oyuncular[0].Oy);
   //birinciOyuncu
  
    rSayi=rand()%3+3;
    
    oyuncular[1].Ox=binalar[rSayi].x+43;
    oyuncular[1].Oy=binalar[rSayi].y-30;
    
    //oyuncular[1].Ox=rand()%((SCREEN_W-15)-((SCREEN_W/2)+15))+((SCREEN_W/2)+15);
	//oyuncular[1].Oy=(rand()%(SCREEN_H-60))+30;
    oyuncular[1].Opuan=0;
    oyuncular[1].Ohak=3;
    oyuncular[1].Osira=0;
    //strcpy(oyuncular[1].Oad,"");
    strcpy(oyuncular[1].Oresim, "oyuncular/yeniTersO.bmp");
	strcpy(oyuncular[1].aktifResim,"oyuncular/yeniTersOaktif.bmp");
    
    oB=load_bitmap(oyuncular[1].Oresim,NULL);
    draw_sprite( screen, oB, oyuncular[1].Ox, oyuncular[1].Oy);
   
}


void topOlustur(int x, int y){
     circlefill(screen, x, y, 3, topRenk);
     }
     
     
int oyuncuNoGetir(){
    
    if(oyuncular[0].Ohak==0 && oyuncular[1].Ohak==0){
                            
          return -1;
         }else if(oyuncular[0].Osira==1){
                               
                               return 0;
                             }else if(oyuncular[1].Osira==1){
                                   
                                   return 1;
                                   }else{                                         
                                            return 1;
                                               }
    }     //oyuncu no getir
     
void yonSec(int yon, int Ono){
          
          if(Ono==0){
          
          yonResim=load_bitmap("yonler/yatay.bmp",NULL);
          rectfill(screen,oyuncular[Ono].Ox+27,oyuncular[Ono].Oy-9,oyuncular[Ono].Ox+60,oyuncular[Ono].Oy+29,siyah);
          topOlustur(oyuncular[Ono].Ox+20, oyuncular[Ono].Oy+24);
          rotate_sprite( screen, yonResim, oyuncular[Ono].Ox+27, oyuncular[Ono].Oy-9, itofix(-yon));
          
          }else if(Ono==1){
                
                yonResim=load_bitmap("yonler/tersYatay.bmp",NULL);
                rectfill(screen,oyuncular[Ono].Ox-43,oyuncular[Ono].Oy-9,oyuncular[Ono].Ox-7,oyuncular[Ono].Oy+29,siyah);
                topOlustur(oyuncular[Ono].Ox-6, oyuncular[Ono].Oy+24);
                rotate_sprite( screen, yonResim, oyuncular[Ono].Ox-40, oyuncular[Ono].Oy-9, itofix(yon));
                
                }                              
             
     }
     
     //TOPU AT
void topuAt(int Ono, int yon, int hiz, int aci){
     
     
     int yukseklik=SCREEN_H-oyuncular[Ono].Oy, zaman=0, cikisZ=0, Tx=0, Ty=0, Tx1=0, Ty1=0, oncekiTx1=0, oncekiTy1=0, oncekiTx=0, oncekiTy=0, sinir=1, vurduMu=0;
     int zSayac=0, dikeyHiz=0, yatayHiz=0, sonDikeyHiz=0, maxYatayYol=0, x=0, y=0;
     float cosA, sinA, gercekAci;
     
     int Ax=0,Ay=0,Bx=0,By=0,Cx=0,Cy=0,Dx=0,Dy=0,Ex=0,Ey=0,payda2, payda1, payda,pay, pay1, pay2;
     float egim; 
    
                                      oyuncular[Ono].Ohak--;
                                      oyuncular[Ono].Osira=0;
        
     
     switch(Ono){
                                 
                 case 0:
                 
                 oA=load_bitmap(oyuncular[Ono].aktifResim,NULL);
                 rectfill(screen,oyuncular[0].Ox,oyuncular[0].Oy,oyuncular[0].Ox+20,oyuncular[0].Oy+30,siyah);
                 draw_sprite( screen, oA, oyuncular[0].Ox, oyuncular[0].Oy);     
                      
                      
                rectfill(screen,oyuncular[Ono].Ox+27,oyuncular[Ono].Oy-9,oyuncular[Ono].Ox+60,oyuncular[Ono].Oy+29,siyah);
                 
                 x=oyuncular[Ono].Ox+20;
                 y=oyuncular[Ono].Oy+24;
               
                      gercekAci=11.25*(aci/8);
                      gercekAci=(PI/180)*gercekAci;
                      
                      cosA=cos(gercekAci);
                      sinA=sin(gercekAci);
                                   
                      zSayac=0;
                      yatayHiz=round(((hiz*cosA)/hizKat))-ruzgar;                                           
                      dikeyHiz=round(((hiz*sinA)/hizKat));
                      
                      zaman=(dikeyHiz*2)/yerCekimi;
                      
                      cikisZ=round(zaman/2);
                      
                    
                      while(zSayac<cikisZ){
                      	if(Tx>SCREEN_W || Ty>SCREEN_H){
                      		 allegro_message("Siniri Astiniz 1");
                      		 sinir=0;
                      		 break;
                      	}else{
                      	oncekiTx=Tx;
                      	oncekiTy=Ty;
						
                      	Ty=y-((dikeyHiz*zSayac)-(0.5*yerCekimi*zSayac*zSayac));
						Tx=x+(yatayHiz*zSayac);
						
						circlefill(screen,Tx,Ty,3,0);
						
					
                      if(binaYik(Ono,Tx,Ty)==1){
                                                circlefill(screen, oncekiTx, oncekiTy, 3, siyah);
                                                circlefill(screen, Tx, Ty, 3, siyah);
                                                //allegro_message("patladý");
                                                vurduMu=1;
                                                break;
                                                }
                                              
                                              
                                              
                      Cx=oyuncular[!Ono].Ox;
                      Cy=oyuncular[!Ono].Oy;
                      Dx=oyuncular[!Ono].Ox+14;
                      Dy=oyuncular[!Ono].Oy+30;
                      Ax=oncekiTx-3;
                      Ay=oncekiTy-3;
                      Bx=Tx+3;
                      By=Ty+3;
                      pay1=(Dy-Cy)*(Cx-Ax);
                      pay2=(Cy-Ay)*(Dx-Cx);
                      pay=pay1-pay2;
                      payda1=(Dy-Cy)*(Bx-Ax);
                      payda2=(By-Ay)*(Dx-Cx);
                      payda=payda1-payda2;
                     // pay=((Dy-Cy)*(Cx-Ax))-((Cy-Ay)*(Dx-Cx));
                     // payda=((Dy-Cy)*(Bx-Ax))-((By-Ay)*(Dx-Cx));
                      egim=(float)pay/payda;
                      
                      if(egim<1 && egim>-1){
                      
                     //if(egim>0){
                      Ex=round(Ax+((Bx-Ax)*egim));
                      Ey=round(Ay+((By-Ay)*egim));
                     
                    
                      
                        if(Ex<Dx && Ex>Cx){         
                                if(Ey<Cy && Ey>Dy){
                                          
                    
                      circlefill(screen, oncekiTx, oncekiTy, 3, siyah);
                      vurduMu=1;
                      
                      oyuncuVurulma(Ono);  
                           
                      oyuncular[Ono].Opuan=oyuncular[Ono].Opuan+puanHesapla(Ono,!Ono);
                      
                      
                      break;
                      }
                      
                      
                                 }
                                       
                                       }//if egim 1 -1
						
						 
                        circlefill(screen, oncekiTx, oncekiTy, 3, siyah);                     
						topOlustur(Tx,Ty);
                       
						zSayac++;
						rest(60); 
						}//if
                      }//while
                    
                    
                    if(vurduMu!=1){
                                   
                       if(sinir!=0){//sýnýr dýsýnda ise top
                                    
                                    
                       
                       if(yatayHiz==0){
                                       
                       }else{  //yatay hiz
                                               
                         
                      if(cikisZ==0){
                                    Tx=x;
                                    Ty=y;
                                    
                                    }                        
                                                                 	
                      //tepe noktasýndan sonra
                      yukseklik=SCREEN_H-Ty;
                      zSayac=0, dikeyHiz=0;
                     
                      
                      zaman=round(sqrt(yukseklik));
                      sonDikeyHiz=zaman*yerCekimi;
                      
                    while(zSayac<=zaman){
                      	
                    if(Tx1>SCREEN_W || Ty1>SCREEN_H){
                      		 allegro_message("Siniri Astiniz 2");
                      		 break;
                      }else{
                           if(Tx1==0 && Ty1==0){
                               circlefill(screen, Tx, Ty, 3, siyah);
                                     }
                                      	
                     
                      oncekiTx1=Tx1;
                      oncekiTy1=Ty1;
                      
                      Tx1=Tx+(yatayHiz*zSayac);
                      Ty1=Ty+((dikeyHiz*zSayac)+(0.5*yerCekimi*zSayac*zSayac));
                     circlefill(screen, Tx1, Ty1, 3, siyah);
                      if(binaYik(Ono,Tx1,Ty1)==1){
                                                circlefill(screen, oncekiTx1, oncekiTy1, 3, siyah);
                                                circlefill(screen, Tx1, Ty1, 3, siyah);
                                               
                                                vurduMu=1;
                                                break;
                                                }
                      
                      Cx=oyuncular[!Ono].Ox;
                      Cy=oyuncular[!Ono].Oy+30;
                      Dx=oyuncular[!Ono].Ox+14;
                      Dy=oyuncular[!Ono].Oy;
                      Ax=oncekiTx1-3;
                      Ay=oncekiTy1-3;
                      Bx=Tx1+3;
                      By=Ty1+3;
                      pay1=(Dy-Cy)*(Cx-Ax);
                      pay2=(Cy-Ay)*(Dx-Cx);
                      pay=pay1-pay2;
                      payda1=(Dy-Cy)*(Bx-Ax);
                      payda2=(By-Ay)*(Dx-Cx);
                      payda=payda1-payda2;
                     
                      egim=(float)pay/payda;
                      
                      if(egim<1 && egim>-1){
                      
                     //if(egim>0){
                      Ex=round(Ax+((Bx-Ax)*egim));
                      Ey=round(Ay+((By-Ay)*egim));
                      
                    
                    
                      
                        if(Ex<Dx && Ex>Cx){         
                                if(Ey<Cy && Ey>Dy){
                                
                                circlefill(screen, oncekiTx1, oncekiTy1, 3, siyah);
                                
                                oyuncuVurulma(Ono);
                                
                                oyuncular[Ono].Opuan=oyuncular[Ono].Opuan+puanHesapla(Ono,!Ono);
                                
                      
                                 break;
                                 }
                      }
                                       
                      }//if egim 1 -1
                    
                       circlefill(screen, oncekiTx1, oncekiTy1, 3, siyah);     
                                
                      topOlustur(Tx1,Ty1);
                                 
                      zSayac++;
                      rest(30);
                 		}
                 		
                     }//if yatayHiz 0
    		         
					}
					
                }//SÝNÝR
               
               }//vurduMU      
                      if(oyuncular[Ono].Osira==0){
                                                // aci=0
                                                 
                                                 hizSayac=0;
                                                 aciSayac=0;
                                                 oA=load_bitmap(oyuncular[Ono].Oresim,NULL);
                                                 rectfill(screen,oyuncular[0].Ox,oyuncular[0].Oy,oyuncular[0].Ox+20,oyuncular[0].Oy+30,siyah);
                                                 draw_sprite( screen, oA, oyuncular[0].Ox, oyuncular[0].Oy);
                                                 //saniye=0;
                                                 oyuncular[!Ono].Osira=1;
                                                 yonSec(aciSayac,!Ono);
                                                 }else{
                                                       
                                                       oA=load_bitmap(oyuncular[Ono].Oresim,NULL);
                                                       rectfill(screen,oyuncular[0].Ox,oyuncular[0].Oy,oyuncular[0].Ox+20,oyuncular[0].Oy+30,siyah);
                                                       draw_sprite( screen, oA, oyuncular[0].Ox, oyuncular[0].Oy);
                                                       
                                                       aciSayac=0;
                                                       
                                                       hizSayac=0;
                                                       yonSec(aciSayac,Ono);
                                                       }
                     
                      
                      break;
////////////////////////////////11111111111111///////////////////////////////////////////////////////////////////11111111111111111111111111
////////////////////////////////11111111111111///////////////////////////////////////////////////////////////////11111111111111111111111111  
////////////////////////////////11111111111111///////////////////////////////////////////////////////////////////11111111111111111111111111                        
                 case 1:
                      
                 oB=load_bitmap(oyuncular[Ono].aktifResim,NULL);
                 rectfill(screen,oyuncular[Ono].Ox,oyuncular[Ono].Oy,oyuncular[Ono].Ox+20,oyuncular[Ono].Oy+30,siyah);
                 draw_sprite( screen, oB, oyuncular[Ono].Ox, oyuncular[Ono].Oy);   
                 
                 
                    yukseklik=SCREEN_H-oyuncular[Ono].Oy, zaman=0, cikisZ=0, Tx=0, Ty=0, Tx1=0, Ty1=0, oncekiTx1=0, oncekiTy1=0, sinir=1, vurduMu=0;
                    zSayac=0, dikeyHiz=0, yatayHiz=0, sonDikeyHiz=0, maxYatayYol=0, x=0, y=0;
                    cosA=0, sinA=0, gercekAci=0;     
                 
                 rectfill(screen,oyuncular[Ono].Ox-43,oyuncular[Ono].Oy-9,oyuncular[Ono].Ox-7,oyuncular[Ono].Oy+29,siyah);
                      
                 x=oyuncular[Ono].Ox-6;
                 y=oyuncular[Ono].Oy+24;
                 
                      gercekAci=11.25*(aci/8);
                      gercekAci=(PI/180)*gercekAci;
                      
                      cosA=cos(gercekAci);
                      sinA=sin(gercekAci);
                        
                       
                                      
                      zSayac=0;
                      yatayHiz=round(((hiz*cosA)/hizKat))+ruzgar;
                      dikeyHiz=round(((hiz*sinA)/hizKat));
                      
                      zaman=(dikeyHiz*2)/yerCekimi;
                      cikisZ=round(zaman/2);
                      
                      
                      while(zSayac<cikisZ){
                      	if(Tx<0 || Ty>SCREEN_H){
                      		 allegro_message("Siniri Astiniz");
                      		 sinir=0;
                      		 break;
                      	}else{
                      	
						
						oncekiTx=Tx;
						oncekiTy=Ty;
                      	Ty=y-((dikeyHiz*zSayac)-(0.5*yerCekimi*zSayac*zSayac));
						Tx=x-(yatayHiz*zSayac);
						circlefill(screen, Tx, Ty, 3, siyah);
						 if(binaYik(Ono,Tx,Ty)==1){
                                                circlefill(screen, oncekiTx, oncekiTy, 3, siyah);
                                               
                                                vurduMu=1;
                                                break;
                                                }
						
						
                      Dx=oyuncular[!Ono].Ox;
                      Dy=oyuncular[!Ono].Oy+30;
                      Cx=oyuncular[!Ono].Ox+14;
                      Cy=oyuncular[!Ono].Oy;
                      Ax=oncekiTx-3;
                      Ay=oncekiTy-3;
                      Bx=Tx+3;
                      By=Ty+3;
                      pay1=(Dy-Cy)*(Cx-Ax);
                      pay2=(Cy-Ay)*(Dx-Cx);
                      pay=pay1-pay2;
                      payda1=(Dy-Cy)*(Bx-Ax);
                      payda2=(By-Ay)*(Dx-Cx);
                      payda=payda1-payda2;
                     // pay=((Dy-Cy)*(Cx-Ax))-((Cy-Ay)*(Dx-Cx));
                     // payda=((Dy-Cy)*(Bx-Ax))-((By-Ay)*(Dx-Cx));
                      egim=(float)pay/payda;
                      
                      if(egim<1 && egim>-1){
                      
                     //if(egim>0){
                      Ex=round(Ax+((Bx-Ax)*egim));
                      Ey=round(Ay+((By-Ay)*egim));
                      //circlefill(screen,Ex,Ey,3,7);
                      //circlefill(screen,Ax,Ay,3,9);
                      //circlefill(screen,Bx,By,3,4);
                      //textprintf(screen, font, SCREEN_W / 3 - 100, 400, 2, "Ex: %-3d Ey: %-3d Ax:%-3d Ay:%-3d Bx:%-3d By:%-3d Egim:%-3f",Ex,Ey,Ax,Ay,Bx,By,egim);
                      //textprintf(screen, font, SCREEN_W / 3 - 100, 430, 2, "Cx: %-3d Cy: %-3d Dx:%-3d Dy:%-3d",Cx,Cy,Dx,Dy);
                      //_X=Ax;
                      //_X=Ay;
                      // rest(0);
                      if(Ex<Cx && Ex>Dx){
                               
                               //allegro_message("dogru");
                               if(Ey>Cy && Ey<Dy){
                               
                         //wcirclefill(screen,Ax,Bx,3,13);
                         circlefill(screen, Tx, Ty, 3, siyah);
                         oyuncuVurulma(Ono);
                         vurduMu=1;
                      oyuncular[Ono].Opuan=oyuncular[Ono].Opuan+puanHesapla(Ono,!Ono);
                     // textprintf(screen, font, SCREEN_W / 3 - 100, 400, 2, "Vurdu 2 Ex: %-3d Ey: %-3d Ax:%-3d Ay:%-3d Bx:%-3d By:%-3d Egim:%-3f",Ex,Ey,Ax,Ay,Bx,By,egim);
                     // textprintf(screen, font, SCREEN_W / 3 - 100, 430, 2, "Cx: %-3d Cy: %-3d Dx:%-3d Dy:%-3d",Cx,Cy,Dx,Dy);
                      //rest(60);
                      
                                 break;
                                   }
                       }//if Cx
                                       
                                       }//if egim 1 -1
                                       
                      //  if(binaYik(Ono,Tx,Ty)==1){
                        //                      vurduMu=1;
                          //                    break;
                            //                  };               
                                       
						circlefill(screen, oncekiTx, oncekiTy, 3, siyah); 
						topOlustur(Tx,Ty);
						
						zSayac++;
						rest(60); 
						}//if
                      }
                    
                       if(vurduMu!=1){
                                      
                       if(sinir!=0){//top sinir disi ise
                       
                       if(yatayHiz==0){
                                       
                       }else{  
                                               
                         
                      if(cikisZ==0){
                                    Tx=x;
                                    Ty=y;
                                    
                                    }                        
                                                                 	
                      //tepe noktasýndan sonra
                      yukseklik=SCREEN_H-Ty;
                      zSayac=0, dikeyHiz=0;
                      zaman=round(sqrt(yukseklik));
                      sonDikeyHiz=zaman*2;
                      
                      
                 
                      
                    while(zSayac<=zaman){
                      	
                    if(Tx1>SCREEN_W || Ty1>SCREEN_H){
                      		 allegro_message("Siniri Astiniz 2");
                      		 break;
                      }else{
                           if(Tx1==0 && Ty1==0){
                               circlefill(screen, Tx, Ty, 3, siyah);
                                     }
                                      	
                      
                      oncekiTx1=Tx1;
                      oncekiTy1=Ty1;
                      
                      Tx1=Tx-(yatayHiz*zSayac);
                      Ty1=Ty+((dikeyHiz*zSayac)+(0.5*yerCekimi*zSayac*zSayac));
                      circlefill(screen, Tx1, Ty1, 3, siyah);
                     if(binaYik(Ono,Tx1,Ty1)==1){
                                                circlefill(screen, oncekiTx1, oncekiTy1, 3, siyah);
                                                
                                                vurduMu=1;
                                                break;
                                                }
                      
                      Dx=oyuncular[!Ono].Ox+14;
                      Dy=oyuncular[!Ono].Oy+30;
                      Cx=oyuncular[!Ono].Ox;
                      Cy=oyuncular[!Ono].Oy;
                      Ax=oncekiTx1-3;
                      Ay=oncekiTy1-3;
                      Bx=Tx1+3;
                      By=Ty1+3;
                      pay1=(Dy-Cy)*(Cx-Ax);
                      pay2=(Cy-Ay)*(Dx-Cx);
                      pay=pay1-pay2;
                      payda1=(Dy-Cy)*(Bx-Ax);
                      payda2=(By-Ay)*(Dx-Cx);
                      payda=payda1-payda2;
                    
                      egim=(float)pay/payda;
                      
                      if(egim<1 && egim>-1){
                      
                     //if(egim>0){
                      Ex=round(Ax+((Bx-Ax)*egim));
                      Ey=round(Ay+((By-Ay)*egim));
                      
                     
                    
                      
                        if(Ex<Dx && Ex>Cx){         
                               
                                if(Ey>Cy && Ey<Dy){
                      
                      circlefill(screen, oncekiTx1, oncekiTy1, 3, siyah);                   
                      oyuncuVurulma(Ono);                   
                      oyuncular[Ono].Opuan=oyuncular[Ono].Opuan+puanHesapla(Ono,!Ono);
                    
                      
                                  break;
                                  }
                      }
                                       
                      }//if egim 1 -1
                      circlefill(screen, oncekiTx1, oncekiTy1, 3, siyah);
                                   
                      topOlustur(Tx1,Ty1);
                                    
                      zSayac++;
                      rest(30);
                 		}
                 		
                     }//if yatayHiz 0
                 		
					}
					
                }//sinir
                
                }//vurduMu      
                   if(oyuncular[Ono].Osira==0){
                                  aciSayac=0;          
                                  hizSayac=0;
                                  oB=load_bitmap(oyuncular[Ono].Oresim,NULL);
                                  rectfill(screen,oyuncular[Ono].Ox,oyuncular[Ono].Oy,oyuncular[Ono].Ox+20,oyuncular[Ono].Oy+30,siyah);
                                  draw_sprite( screen, oB, oyuncular[Ono].Ox, oyuncular[Ono].Oy);  
                                  //saniye=0;
                                  oyuncular[!Ono].Osira=1;
                                  yonSec(aciSayac,!Ono);
                                              
                              }else{           //aci=0;
                              
                                              
                                              oB=load_bitmap(oyuncular[Ono].Oresim,NULL);
                                              rectfill(screen,oyuncular[Ono].Ox,oyuncular[Ono].Oy,oyuncular[Ono].Ox+20,oyuncular[Ono].Oy+30,siyah);
                                              draw_sprite( screen, oB, oyuncular[Ono].Ox, oyuncular[Ono].Oy);   
                              
                                             aciSayac=0;
                                             hizSayac=0;
                                             yonSec(aciSayac,Ono);
                                                       }
                                            break;}
     }//topu at
     
void oyuncuVurulma(Ono){
                  if(Ono==0){                  
                   
                      rest(60);
                      draw_sprite( screen, oB, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy);
                      rest(60);
                      rectfill(screen,oyuncular[!Ono].Ox,oyuncular[!Ono].Oy,oyuncular[!Ono].Ox+20,oyuncular[!Ono].Oy+30,siyah);
                      rest(60);
                      draw_sprite( screen, oB, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy);
                      rest(60);
                      rectfill(screen,oyuncular[!Ono].Ox,oyuncular[!Ono].Oy,oyuncular[!Ono].Ox+20,oyuncular[!Ono].Oy+30,siyah);
                      rest(60);
                      draw_sprite( screen, oB, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy);
                      rest(60);
                      rectfill(screen,oyuncular[!Ono].Ox,oyuncular[!Ono].Oy,oyuncular[!Ono].Ox+20,oyuncular[!Ono].Oy+30,siyah);
                      rest(60);
                      draw_sprite( screen, oB, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy); 
                      
}else if(Ono==1){
                      rest(60);
                      draw_sprite( screen, oA, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy);
                      rest(60);
                      rectfill(screen,oyuncular[!Ono].Ox,oyuncular[!Ono].Oy,oyuncular[!Ono].Ox+20,oyuncular[!Ono].Oy+30,siyah);
                      rest(60);
                      draw_sprite( screen, oA, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy);
                      rest(60);
                      rectfill(screen,oyuncular[!Ono].Ox,oyuncular[!Ono].Oy,oyuncular[!Ono].Ox+20,oyuncular[!Ono].Oy+30,siyah);
                      rest(60);
                      draw_sprite( screen, oA, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy);
                      rest(60);
                      rectfill(screen,oyuncular[!Ono].Ox,oyuncular[!Ono].Oy,oyuncular[!Ono].Ox+20,oyuncular[!Ono].Oy+30,siyah);
                      rest(60);
                      draw_sprite( screen, oA, oyuncular[!Ono].Ox, oyuncular[!Ono].Oy); 
                            
                            }   ///if 
}//oyuncu vurulma

int puanHesapla(int vuran, int vurulan){
    int puan;
    
    if((oyuncular[vuran].Oy-oyuncular[vurulan].Oy)>0){
        puan=(oyuncular[vuran].Oy-oyuncular[vurulan].Oy)*2;                                                      
    }else{
          puan=(oyuncular[vuran].Oy-oyuncular[vurulan].Oy)*1; 
          }
          
    switch(vuran){
                  case 0:
                       puan=puan+(-1*(oyuncular[vuran].Ox-oyuncular[vurulan].Ox));                      
                       break;
                       
                  case 1:
                       puan=puan+(oyuncular[vuran].Ox-oyuncular[vurulan].Ox);
                       break;                  
                  }
    
    return puan;
    
    }//puanHesapla
    
         
void dosyayaYazdir(int Ono){
     int sira=0, sayac=0, durum=0;
    
    
    dosya=fopen("dosyalar/skorlar.txt","r+");
    if(dosya==NULL)
    {
    
    allegro_message("Dosya Acilamadi 1");
    
    }else{
    while(!feof(dosya)){
                    fscanf(dosya,"%d%s%d",&skorlar[sayac].sira,skorlar[sayac].isim,&skorlar[sayac].puan);
                    
                    if(durum==0){
                  
                    if(skorlar[sayac].puan<=oyuncular[Ono].Opuan){
                                                            skorlar[sayac+1].sira=skorlar[sayac].sira+1;
                                                            strcpy(skorlar[sayac+1].isim,skorlar[sayac].isim);
                                                            skorlar[sayac+1].puan=skorlar[sayac].puan ;
                                                            
                                                            skorlar[sayac].sira=skorlar[sayac].sira;
                                                            strcpy(skorlar[sayac].isim,oyuncular[Ono].Oad);
                                                            skorlar[sayac].puan=oyuncular[Ono].Opuan;  
                                                            
                                                              sayac++;
                                                              durum=1;   
                                                                 }
                        
         }//durum
         else{
              skorlar[sayac].sira=sayac+1;
                         
              }
                    
                                                                 
                    if(sayac==9){
                                 break;
                                 }else{
                                       sayac++;
                                       }                                                
                        
    }
                         
}
    fclose(dosya);
    
    sayac=0;
    dosya=fopen("dosyalar/skorlar.txt","w+");                    
    if(dosya==NULL)
    {
    
    allegro_message("Dosya Acilamadi 2");
    
    }else{
          while(strcmp(skorlar[sayac].isim,"")!=0){
           fprintf(dosya,"%-10d%-30s%-15d\n",skorlar[sayac].sira,skorlar[sayac].isim,skorlar[sayac].puan);
                sayac++;              
                }
    }//if dosya open                          
    fclose(dosya);                       
}//dosyaya yazdir
   
                     
         
     
int main(){
   
   allegro_init(); 
         
   install_keyboard();
   install_timer();
   install_mouse();
   set_color_depth(32);
   set_window_title("Top Atma");
   srand(time(NULL));
   patlamaEfektEkle();
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
   tazele = create_bitmap(640, 480); 
   show_mouse(screen);
   //anaEkran();  	 
   	 
     while (kapat!=1) {
         ekranCagir();
         mouseKontrol();//{
                                //break;
                                //}
         
 
	}
   //ilkEkran();
   
 
   
   //remove_mouse();
   remove_keyboard();      
   allegro_exit();
}
END_OF_MAIN();

