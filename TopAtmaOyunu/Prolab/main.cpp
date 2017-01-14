#include <allegro.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265359

BITMAP *Adam,*Top,*Arkaplan,*skor;
BITMAP *buffer,*buffer2,*Rüzgar;
FILE *dosya;
SAMPLE * giris =load_sample("sound/anasayfa.wav");
SAMPLE * bravo =load_sample("sound/bravo.wav");
SAMPLE * kirilma = load_sample("sound/kýrýlma.wav");

int rüzgar=15;
int atissayisi1=0,atissayisi2=0;
int sayac=50;
int aci=45;
int bina,binasayisi;
int Skorlar[3];
int skorgecici;
int adam1,adam2;
float topkordi1x,topkordi1y,topkordi2x,topkordi2y;
int puan1=0,puan2=0;
int binabaslangickordi[10][3];


int cizim();
void Puanlar(void);
void Skor(int );
void oyuncuatis1(void);
void oyuncuatis2(void);
void anasayfa(void);


void main()
{
	
	dosya=fopen("Skorlar.txt","r");
	int t=0;
	while(!feof(dosya)){
	
	fscanf(dosya,"%d\n",&Skorlar[t]);
	t++;
	}
	fclose(dosya);

	anasayfa();
}
END_OF_MAIN();


int cizim(){

srand(time(NULL));
Adam = load_bitmap( "img/deneme2.bmp", NULL);
giris =load_sample("sound/anasayfa.wav");
Rüzgar=load_bitmap("img/arrow.bmp",NULL);

	
	stop_sample(giris);
	play_sample(giris,125,128,1000,0);

clear_to_color(screen,makecol(255,255,255) );
int test=0;
binasayisi=(rand()%5)+6;
adam2=(rand()%(binasayisi/2))+(binasayisi/2);
adam1=rand()%(binasayisi/2);
int baslangic=0;

for(int i=0;i<binasayisi;i++){

bina=(rand()%200)+280;


rectfill(screen,baslangic,bina,baslangic+(800/binasayisi)+test,bina+200,makecol(237,28,36));
binabaslangickordi[i][0]=baslangic;
binabaslangickordi[i][1]=bina;
binabaslangickordi[i][2]=baslangic+(800/binasayisi)+test;

if ( adam1==i ){
draw_sprite( screen, Adam, baslangic+36, bina-69);
topkordi1x=baslangic+65;
topkordi1y=bina-66;
}
if ( adam2==i ){
draw_sprite( screen, Adam, baslangic+36, bina-69);
topkordi2x=baslangic+30;
topkordi2y=bina-60;
}
baslangic=baslangic+(800/binasayisi);
test=test+5;
}
draw_sprite( screen, Rüzgar,200, 25);
textprintf_ex(screen,font,200,15,makecol(125,0,200),-1,"Ruzgar %d m/s",rüzgar);

show_mouse(screen);
while(!key[KEY_ESC]){

textout_ex(screen, font, "1.OYUNCU ", 20, 30,makecol(237,28,36), -1);
textout_ex(screen, font, "2.OYUNCU", 20, 60,makecol(237,28,36), -1);

rectfill(screen,100,25,170,45,makecol(237,28,36));
textout_ex(screen, font, "ATIS", 120, 32,makecol(255, 255, 0), -1);

rectfill(screen,100,55,170,75,makecol(237,28,36));
textout_ex(screen, font, "ATIS", 120, 62,makecol(255, 255, 0), -1);

rectfill(screen,100,85,170,105,makecol(237,28,36));
textout_ex(screen, font, "CIKIS", 115, 92,makecol(255, 255, 0), -1);



if(mouse_x>100 && mouse_x<170 && mouse_y>80 && mouse_y<100 && (mouse_b & 1))
{
	exit(1);
}



if(mouse_x>100 && mouse_x<170 && mouse_y>20 && mouse_y<40 && (mouse_b & 1))
{
	if(atissayisi1==3 || atissayisi1>3) continue;
	oyuncuatis1();

}


if(mouse_x>100 && mouse_x<170 && mouse_y>50 && mouse_y<70 && (mouse_b & 1))
{
	if(atissayisi2==3 || atissayisi2>3) continue;
	oyuncuatis2();

}

if ((atissayisi2==3 || atissayisi2>3) && (atissayisi1==3 || atissayisi1>3) ) {

	stop_sample(giris);
	stop_sample(bravo);
if (puan1>puan2) {
	Skor(puan1);
	allegro_message("Oyunu %d puanla sol taraf kazandý",puan1);
	puan1=0;
	puan2=0;
	break;

}
else if(puan2>puan1){
	Skor(puan2);
	allegro_message("Oyunu %d puanla sol taraf kazandý",puan2);
	puan1=0;
	puan2=0;
	break;

}
else if(puan1==puan2){ 
	allegro_message("Malesef oyun %d--%d berabere bitti.",puan1,puan2);
	puan1=0;
	puan2=0;
	break;

}

}


textout_ex(screen, font, "PUAN1", 400, 30,makecol(237,28,36), -1);
rectfill(screen,440,25,480,45,makecol(237,28,36));
textprintf_ex(screen,font,450,32,makecol(255,255,0),-1,"%d",puan1);


textout_ex(screen, font, "PUAN2", 400,60,makecol(237,28,36), -1);
rectfill(screen,440,55,480,75,makecol(237,28,36));
textprintf_ex(screen,font,450,62,makecol(255,255,0),-1,"%d",puan2);


if(key[KEY_UP])
sayac++;
else if(key[KEY_DOWN])
sayac--;

else if(key[KEY_LEFT])
aci--;
else if(key[KEY_RIGHT])
aci++;
	rest(75);

textout_ex(screen, font, "HIZ", 600, 30,makecol(237,28,36), -1);
rectfill(screen,630,25,690,45,makecol(237,28,36));
textprintf_ex(screen,font,650,32,makecol(255,255,0),-1,"%d",sayac);

textout_ex(screen, font, "ACI", 600, 60,makecol(237,28,36), -1);
rectfill(screen,630,55,690,75,makecol(237,28,36));
textprintf_ex(screen,font,650,62,makecol(255,255,0),-1,"%d",aci);

rest(5);



}


}

void oyuncuatis1(){

	float radyan;
	Top = load_bitmap( "img/top3.bmp", NULL);
	float hiz1=sayac;
	radyan=(PI/180)*aci;
	buffer=create_bitmap(800,480);
	float hizx=hiz1*cos(radyan)+rüzgar;
	float hizy=hiz1*sin(radyan);
	float acc=10,dt=0.1;
	float yuk,x,y;
	yuk= (hizy*hizy)/(2*acc);
    float a,b;
	x=topkordi1x;
	y=topkordi1y;
	a=topkordi1y+yuk;
	
	while(x<800 && y<480 && y>0){
	
	hizy=hizy-acc*dt;
	rectfill(screen,x,y,x+10,y+12,makecol(255,255,255));
	x=x+(hizx*dt);
	y=y-(hizy*dt)+0.5*acc*(dt*dt);
	draw_sprite(screen,Top,x,y);
	
	if(x+10>topkordi2x && x+12<(topkordi2x+28) && y>topkordi2y && y<(topkordi2y+69))  {
		bravo = load_sample("sound/bravo.wav");
		stop_sample(giris);
		play_sample(bravo,255,128,1000,0);
		puan1=(puan1+50)*(atissayisi1+1); 
		rectfill(screen,x,y,x+10,y+12,makecol(255,255,255));
		atissayisi1++;
		break;
		}

	if(x>800 || y<0 || x<0)
	{
		rectfill(screen,x,y,x+10,y+12,makecol(255,255,255));
		atissayisi1++;
		break;
	} 

	for(int k=0;k<binasayisi;k++){
	
		if(x>binabaslangickordi[k][0] && x<(binabaslangickordi[k][0]+binabaslangickordi[k][2]) && y>binabaslangickordi[k][1] ){
	
			rectfill(screen,x,y,x+10,y+12,makecol(255,255,255));
			atissayisi1++;
			return ;
		
	}
	}
	
	rest(25);
		}

}


void oyuncuatis2(){
	
	float radyan;
	Top = load_bitmap( "img/top3.bmp", NULL);
	float hiz1=sayac;
	radyan=(PI/180)*(180-aci);
	float hizx=hiz1*cos(radyan)-rüzgar;
	float hizy=hiz1*sin(radyan);
	float acc=10,dt=0.1;
	float yuk,x,y;
    yuk= (hizy*hizy)/(2*acc);
    float a,b;
	x=topkordi2x;
	y=topkordi2y;
	a=topkordi2y+yuk;
	
	while(x>0 && y<480 && y>0){
	
    hizy=hizy-acc*dt;
	rectfill(screen,x,y,x+10,y+12,makecol(255,255,255));
	x=x+(hizx*dt);
	y=y-(hizy*dt)+0.5*acc*(dt*dt);
	draw_sprite(screen,Top,x,y);
	
	if(x<(topkordi1x-5) && x>(topkordi1x-28) && y<(topkordi1y+69) && y>(topkordi1y))  {
		bravo = load_sample("sound/bravo.wav");
		stop_sample(giris);
		play_sample(bravo,255,128,1000,0);
		puan2=(puan2+50)*(atissayisi2+1); 
		rectfill(screen,x,y,x+10,y+12,makecol(255,255,255));
		atissayisi2++;
		break;
		}
	if(x<0 || y<0 || x>800)
	{
		rectfill(screen,x,y,x+10,y+12,makecol(255,255,255));
		atissayisi2++;
		break;
	} 

	for(int k=0;k<binasayisi;k++){
	
	if(x>binabaslangickordi[k][0] && x<(binabaslangickordi[k][0]+binabaslangickordi[k][2]) 
		&& y>binabaslangickordi[k][1] ){
	
	rectfill(screen,x,y,x+10,y+12,makecol(255,255,255));
	
	atissayisi2++;
			return ;
		
	}
	}
	
	rest(25);
		}

}

void Skor(int x){

	dosya=fopen("Skorlar.txt","w+");
	if (x>Skorlar[0]) {
						skorgecici=Skorlar[0];
						Skorlar[0]=x;
						x=skorgecici;
					
						}
	if (x>Skorlar[1]) {
						skorgecici=Skorlar[1];
						Skorlar[1]=x;
						x=skorgecici;
					
						}
	if (x>Skorlar[2]) {
						skorgecici=Skorlar[2];
						Skorlar[2]=x;
						x=skorgecici;
					
						}
	
	for(int k=0;k<3;k++) fprintf(dosya,"%d\n",Skorlar[k]);

	fclose(dosya);


}

void Puanlar(){

	install_keyboard();
	install_mouse();
	FONT * font1;
	font1=load_font("font/f01.pcx",NULL,NULL);
	skor = load_bitmap( "img/skorlar.bmp", NULL);
	buffer2=create_bitmap(800,480);

	clear_to_color(screen,makecol(255,255,255));
	draw_sprite(screen,skor,0,0);
	textprintf_ex(screen,font1,500,100,makecol(0,200,0),-1,"1 -->> %d",Skorlar[0]);
	textprintf_ex(screen,font1,500,120,makecol(0,200,0),-1,"2 -->> %d",Skorlar[1]);
	textprintf_ex(screen,font1,500,140,makecol(0,200,0),-1,"3 -->> %d",Skorlar[2]);
	show_mouse(screen);
	
	while(!key[KEY_ESC]){
		if(mouse_x>695 && mouse_x<765 && mouse_y>349 && mouse_y<379 && (mouse_b & 1))
		{
	
			exit(1);

		}
	}
}

void anasayfa(){

	allegro_init();
	install_keyboard();
	install_mouse();
	set_color_depth(32);
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
	set_window_title("TOP ATMA OYUNU");
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 480, 0, 0);
	clear_to_color(screen,makecol(0,0,0));

	buffer=create_bitmap(800,480);
	Arkaplan=load_bitmap("img/arkaplan.bmp",NULL);
	clear_to_color(screen,makecol(0,0,0));
	clear_to_color(buffer,makecol(0,0,0));
	draw_sprite(buffer,Arkaplan,0,0);
	blit(buffer,screen,0,0,0,0,800,480);
	
	show_mouse(screen);
	while(!key[KEY_ESC]){
			if(mouse_x>30 && mouse_x<220 && mouse_y>210 && mouse_y<250 && (mouse_b & 1))
			{
				cizim();
			}
			if(mouse_x>585 && mouse_x<775 && mouse_y>210 && mouse_y<250 && (mouse_b & 1))
			{
				exit(1);
			}
			if(mouse_x>330 && mouse_x<460 && mouse_y>105 && mouse_y<130 && (mouse_b & 1))
			{
				Puanlar();
			}
}

	clear_bitmap(buffer);

}