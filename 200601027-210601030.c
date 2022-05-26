#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
FILE *dosya,*yedek; 
struct ogrenci{
 char ad[10];
 int no, not;
 };
struct ogrenci ogr;
void ogrenciGirisi(void); 
void ogrenciSilme(void);
void ogrenciGuncelleme(void); 
void ogrenciListele(void);
void ogrenciArama(void); 
void dersListeleme(void);
void dersGirisi(void);
void dersSilme(void);
void dersKayit(void);
int main(){
do{ 
system("cls");
printf("\t\t MENU \n1- Ogrenci Girisi\n2- Ogrenci Silme \n3- Ogrenci Guncelleme \n4- Ogrenci Listele \n5- Ogrenci Ara \n6- Ders Girisi \n7- Ders Silme \n8- Ders Listeleme \n9- Ders Kaydi \n10- Cikis \n\nLutfen kullanacaginiz islemi seciniz:");
switch(getch()){
 case '1':{ 
 system("cls");
 ogrenciGirisi();
  break;
 }
 case '2':{ 
 system("cls");
 ogrenciSilme();
  break;
 }
 case '3':{ 
 system("cls");
 ogrenciGuncelleme();
  break;
 }
 case '4':{ 
 system("cls");
 ogrenciListele();
  break;
 }
 case '5':{ 
 system("cls");
 ogrenciArama();
  break;
 }
 case '6':{
 	system("cls");
 	dersGirisi();
	break;
 }
 case '7':{
 	system("cls");
 	dersSilme();
	break;
 }
 case '8':{
 	system("cls");
 	dersListeleme();
	break;
 }
 case '9':{
 	system("cls");
 	dersKayit();
	break;
 }
 case '10':{ 
    return 0;
  break;
 }
 default:{
  printf("Hatali Giris Yaptiniz.");
 }
}
}while(1);
 getch();
 return 0;
}

void ogrenciGirisi(void){
 int i=0;
 dosya=fopen("ogrenciler.txt","a+");
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
 puts("\nOgrenci bilgilerini girin: ");
 do{ 
  i++;
  fflush(stdin);
  printf("%d. Ogrencinin Adi : ",i);
  gets(ogr.ad);
  printf("%d. Ogrencinin Numarasi : ",i);
  scanf("%d",&ogr.no);
  printf("%d. Ogrencinin Notu : ",i);
  scanf("%d",&ogr.not);
  printf("\n");

  fprintf(dosya,"%s %d %d\n",ogr.ad,ogr.no,ogr.not);
  puts("Yeni bir kayit icin bir tusa, cikmak icin ESC tusuna basiniz.");
 }while(getch()!=27);
 fclose(dosya);
 puts("\nBilgiler kaydedildi devam etmek icin bir tusa basin ...");
 getch();
}

void ogrenciSilme(void){
 int numara,durum=0;
 printf("\nSilinecek ogrencinin numarasini giriniz : ");
 scanf("%d",&numara);
 dosya = fopen("ogrenciler.txt","r");
 yedek = fopen("yedek.txt","w");
 if(dosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(dosya)){
  fscanf(dosya,"%s %d %d\n",ogr.ad,&ogr.no,&ogr.not);
    if(numara != ogr.no){
     fprintf(yedek,"%s %d %d\n",ogr.ad,ogr.no,ogr.not);
     
    }
    else durum=1; 
 }
 fclose(dosya);
 fclose(yedek);
 if(durum == 1){
  remove("ogrenciler.txt");
  rename("yedek.txt","ogrenciler.txt");
  puts("Silme islemi tamamlandi devam etmek icin bir tusa basin");
 } 
 else{ 
  remove("yedek.txt"); 
  printf(" %d numarasinda bir ogrenci bulunamadi devam etmek icin bir tusa basin ...",numara);
 }
 fflush(stdin);
 getch();
}

void ogrenciGuncelleme(void){
 int numara,durum=0;
 printf("\nBilgilerini degistirmek istediginiz ogrencinin numarasini giriniz: ");
 scanf("%d",&numara);
 dosya = fopen("ogrenciler.txt","r");
 yedek = fopen("yedek.txt","w");
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);
 }
 while(!feof(dosya)){
  fscanf(dosya,"%s %d %d\n",ogr.ad,&ogr.no,&ogr.not);
  if(numara != ogr.no){
   fprintf(yedek,"%s %d %d\n",ogr.ad,ogr.no,ogr.not);
  }
  else{
   fflush(stdin);
   printf("Ogrencinin Adi : ");
      gets(ogr.ad);
      printf("Ogrencinin Numarasi : ");
      scanf("%d",&ogr.no);
      printf("Ogrencinin Notu : ");
      scanf("%d",&ogr.not);
      printf("\n");
      fprintf(yedek,"%s %d %d",ogr.ad,ogr.no,ogr.not); 
      durum=1;
  }
 }
 fclose(dosya);
 fclose(yedek);
 if(durum == 1){ 
  remove("ogrenciler.txt");
  rename("yedek.txt","ogrenciler.txt");
  puts("Ogrenci bilgileri degistirildi devam etmek icin bir tusa basiniz...");
 }
 else{
  remove("yedek.txt");
  puts("Ilgili ogenci bulunamadi devam etmek icin bir tusa basiniz...");
 }
 fflush(stdin);
 getch();
}

void ogrenciListele(void){
 dosya = fopen("ogrenciler.txt","r");
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);
 }
 while(!feof(dosya)){
  fflush(stdout);
  fscanf(dosya,"%s %d %d\n",ogr.ad,&ogr.no,&ogr.not);
   if(ogr.ad != NULL){ 
    printf("\n%s %d %d",ogr.ad,ogr.no,ogr.not);
   }
 }
 fclose(dosya);
 puts("\n Istenilen bilgiler listelendi devam etmek icin bir tusa basiniz...");
 getch();
}


void ogrenciArama(void){
 char adi[10];
 int durum=0;
 fflush(stdin);
 printf("\nOgrenci adini giriniz: ");
 gets(adi);
 dosya=fopen("ogrenciler.txt","r");
 if( dosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(dosya)){
   fscanf(dosya,"%s %d %d\n",ogr.ad,&ogr.no,&ogr.not);
   if(strcmp(ogr.ad,adi) == 0){ 
    printf("%s %d %d\n\n Devam etmek icin bir tusa basiniz...",ogr.ad,ogr.no,ogr.not);
    durum=1;
   }
  }
  fclose(dosya);
  if(durum == 0){
   puts("Kayitli ogrenci bulunamadi devam etmek icin bir tusa basiniz...");
  }
 getch();
 
}

struct dersbilgi{
	char dersadi[20];
	int akts,kod,kredi;
};

struct dersbilgi ders; 
void dersListeleme(void){

 dosya = fopen("dersler.txt","r");
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);
 }
 while(!feof(dosya)){
  fflush(stdout);
  fscanf(dosya,"%s %d %d %d\n",ders.dersadi,&ders.kod,&ders.kredi,&ders.akts);
   if(ders.dersadi != NULL){ 
    printf("\n Ders adi: %s Ders Kodu:%d Ders Kredisi:%d Ders akts:%d\n",ders.dersadi,ders.kod,ders.kredi,ders.akts);
   }
 }
 fclose(dosya);
 puts("\n Istenilen derslerin bilgileri listelendi devam etmek icin bir tusa basiniz...");
 getch();
}


void dersGirisi(void){
 int i=0;
 dosya=fopen("dersler.txt","a+");
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
 puts("\nDers bilgilerini girin: ");
 do{ 
  i++;
  fflush(stdin);
  printf("%d. Dersin Adi : ",i);
  gets(ders.dersadi);
  printf("%d. Dersin kodu : ",i);
  scanf("%d",&ders.kod);
  printf("%d. Dersin kredisi : ",i);
  scanf("%d",&ders.kredi);
   printf("%d. Dersin AKTS''si : ",i);
  scanf("%d",&ders.akts);
  printf("\n");

  fprintf(dosya,"%s %d %d %d\n",ders.dersadi,ders.kod,ders.kredi,ders.akts);
  puts("Yeni bir ders kayidi icin bir tusa, cikmak icin ESC tusuna basiniz.");
 }while(getch()!=27);
 fclose(dosya);
 puts("\nBilgiler kaydedildi devam etmek icin bir tusa basin ...");
 getch();
}


void dersSilme(void){
 int kod,durum=0;
 printf("\nSilinecek dersin kodunu giriniz : ");
 scanf("%d",&kod);
 dosya = fopen("dersler.txt","r");
 yedek = fopen("yedek.txt","w");
 if(dosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(dosya)){
  fscanf(dosya,"%s %d %d %d\n",ders.dersadi,&ders.kod,&ders.kredi,&ders.akts);
    if(kod != ders.kod){
     fprintf(yedek,"%s %d %d %d\n",ders.dersadi,ders.kod,ders.kredi,ders.akts);
     
    }
    else durum=1; 
 }
 fclose(dosya);
 fclose(yedek);
 if(durum == 1){
  remove("dersler.txt");
  rename("yedek.txt","dersler.txt");
  puts("Ders silme islemi tamamlandi devam etmek icin bir tusa basin");
 } 
 else{ 
  remove("yedek.txt"); 
  printf(" %d kodunda bir ders bulunamadi devam etmek icin bir tusa basin ...",kod);
 }
 fflush(stdin);
 getch();
}
void dersKayit(void){
	char ogrenciAd;
	int durum=0;
	dosya=fopen("ogrenciler.txt","r");
	if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
  while(!feof(dosya)){
  	fflush(stdout);
  fscanf(dosya,"%s %d %d %d\n",ogr.ad,&ogr.no,&ogr.not);
    if(dosya!=NULL ){
     fprintf(dosya,"%s %d %d %d\n",ogr.ad,ogr.no,ogr.not);
 }
    }
    fclose(dosya);
    puts("\n\nDers kaydi icin ogrenciyi seciniz. ");
    getch();
  	fflush(stdin);
  	printf("\nOgrencinin adini giriniz: ");
  	gets(ogr.ad);
  	dosya=fopen("ogrenciler.txt","r");
  	if(dosya==NULL){
  		printf("Dosya Acilamadi");
  		exit(1);
	  }
	  while(!feof(dosya)){
  fscanf(dosya,"%s %d %d %d\n",&ogr.ad,&ogr.no,&ogr.not);
    if(ogr.ad==ogrenciAd){
    	dosya=fopen("ogrenciler.txt","a+");
    	fprintf(dosya,"\n%s %d %d",ogr.ad,ogr.no,ogr.not);
 
    }
   
    
    int dersAd;
    dersListeleme();
    
    fflush(stdin);
    	printf("ders adini girinz: ");
    	scanf("%s",&dersAd);
    	dosya=fopen("dersler.txt","r");
    	
    if(dosya==NULL){
  	printf("Dosya Acilamadi");
  	exit(1);
}
	while(!feof(dosya)){
		fscanf("%s %d %d %d ",&ders.dersadi,&ders.kod,&ders.akts,&ders.kredi);
		if(ders.dersadi==dersAd){	
			fprintf(dosya,"%s",ders.dersadi);
			
		}
	}
}

		fclose(dosya);
		
	
	
	
}
