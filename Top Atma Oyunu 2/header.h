#include <allegro.h>
#include <stdio.h>


#define RUZGAR 2
#define PI 3.14159265359
#define topRenk makecol(178, 89, 0)
#define siyah makecol(0,0,0)
#define yaziRenk makecol(0,140,0)

struct oyuncu{
       int Ox, Oy, Opuan, Ohak, Osira;
       char Oresim[30], aktifResim[30], Oad[20];
       
} oyuncular[2];

struct bina{
       int x, y, yukseklik, genislik;
       char resim[30];
       }binalar[6];

struct yuksekSkorlar{
       int sira, puan;
       char isim[20];
       }skorlar[10];

//BITMAP *screen;

BITMAP *bina[6];       
BITMAP *yonResim, *oA, *oB;
BITMAP *ekranTemizle, *patlama, *tazele, *menuResim;

  FONT *font1;
  FONT *font2;

FILE *dosya, *dosyaOku;
int yerCekimi=2, kontrol, hizKat=5, hizSayac;
int aciSayac=0, ruzgar=1, cikis=0, saniye=10, kapat=0;

int klavyeSayac=0,klavyeGirdisi=1,isimSayac2=0,isimSayac1=0;//klavye islemleri   
int aktif =0;
int _x = 135,_y=80 ;

//char menu[3][20]={"Basla","Yuksek Puanlar","Cikis"};  // Menü Elemanlarýnýn Ýsimleri


char patlamaResim[21][50];
//time_t baslangic, bitis;


 void anaEkran();
 void yuksekSkor();
 void adSoyad(); 
 void mouseKontrol();
 void ekranCagir();

void patlamaEfektEkle();
void oyunEkran();
void oyunBaslat();
void binaOlustur();
int binaYik(int,int,int);
void oyuncuOlustur();
void topOlustur(int, int );
void yonSec(int, int);
void topuAt(int, int, int, int);
void kontrolOyuncu(int);
int oyuncuNoGetir();
int puanHesapla(int,int);
void dosyayaYazdir(int);
void oyunBitir();
void oyuncuVurulma(int);
