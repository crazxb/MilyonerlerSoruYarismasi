/*Programlama ve Algoritmaya Giriş Şube 1
Hasan Arif Doğan 22181617016 , Erdem Tarık Güral 22181617002 , Furkan Emir KAYA 22181617011 
*/
#include <stdio.h>
#include <time.h> //Sleep(); komutu için
#include <stdbool.h>
#include <stdlib.h>//system("pause"); komutu için
#include <locale.h>
#include <Windows.h> //Terminalde Unicode yazı gösterebilmek için
#include <conio.h> //getch
#include <ctype.h> //toupper
#define MAX_KARAKTER 2048 //txt DOSYASINDAN BİR SATIRDA MAX KAÇ KARAKTER OKUNACAĞI 
#define CVP_ANAHTAR_U 26 //CEVAP ANAHTARI DİZİLERİNİN UZUNLUĞU

int sayac=1; //YARIŞMACININ KAÇINCI SORUDA OLDUĞUNU TAKİP EDECEK SAYAÇ
int rdm=0; //RANDOM DEĞERİN TUTULUP/ATANACAĞI DEĞİŞKEN (ÇEKİLEN SORUNUN SATIR NUMARASI BU DEĞŞİKENDE YANİ CEVAP DİZİSİNİN İNDİSİ OLARAK BUNU KULLANDIM)

char tekrar; //Yarışmayı tekrarlama değişkeni

int k=0; //Yarı yarıya jokeri kontrolü yy
int l=0; //iki cevap jokeri kontrolü ic
int m=0; //Yeni soru jokeri kontrolü ys

char isim[16]; //OYUNU OYNAYAN KULLANICININ ADI
char cevap[3]; //KULLANICININ SORUYA GİRDİĞİ CEVAP (ic,ys,yy,a,b,d,c) girilebilir
char kolayCVPA[CVP_ANAHTAR_U]={'D','A','A','A','B','C','B','A','A','D','D','B','A','D','B','B','B','A','D','C','A','C','B','C','C'}; //1-3 ARASI ÇEKİLECEK SORULARIN CEVAPLARI
char ortaCVPA[CVP_ANAHTAR_U]={'A','B','C','B','A','D','B','A','D','A','A','D','D','B','C','A','A','B','D','A','B','C','B','C','A'}; //3-7 ARASI ÇEKİLECEK SORULARIN CEVAPLARI
char zorCVPA[CVP_ANAHTAR_U]={'C','B','C','D','B','C','A','C','D','C','D','A','C','B','A','D','C','A','C','A','C','C','B','D','C'}; //7-10 ARASI ÇEKİLECEK SORULARIN CEVAPLARI

//---FONKSİYONLARIN PROTOTİPLERİ/AÇIKLAMASI---
void tanitim(void);   //KULLANICIYA OYUNUN KURALLARINI ANLATAN GİRİŞ EKRANI   <<
void cevapAl_Byap(void);   //KULLANICI CEVAP ALIP BÜYÜK HARFE DÖNDÜRÜR   <<
void tekrarOyna(void); //KULLANICININ OYUNU TEKRAR OYNAMASINI SAĞLAYAN FONKSİYON <<

void yariYariJ(void); //YARI YARIYA JOKERİ  
void ikiCevapJ(void); //İKİ CEVAP JOKERİ -BU JOKER 7. SORU DOĞRU BİLİNDİYSE KULLANILABİLİR-   <<
void yeniSoruJ(void); //YENİ SORU JOKERİ (AYNI ZORLUKTA YENİ SORU GETİRİR)   <<

void yonlendir(void); //RANDOM SAYIYI OLUŞTURUR VE SAYACA GÖRE AKIŞI kRandSoru()/oRandSoru()/zRandSoru()' YA GÖNDERİR    <<

void kRandSoru(void); //Kolay_sorular.txt DOSYASINDAN RANDOM SORU ÇEKER   <<
void kSiklar(void); //Kolay_cevaplar.txt DOSYASINDAN ÇEKİLEN SORUNUN ŞIKLARINI YAZDIRIR   <<

void oRandSoru(void); //Orta_sorular.txt DOSYASINDAN RANDOM SORU ÇEKER   <<
void oSiklar(void); //Orta_cevaplar.txt DOSYASINDAN RANDOM SORU ÇEKER   <<

void zRandSoru(void); //Zor_sorular.txt DOSYASINDAN RANDOM SORU ÇEKER   <<
void zSiklar(void); //Zor_cevaplar.txt DOSYASINDAN ÇEKİLEN SORUNUN ŞIKLARINI YAZDIRIR   <<

int CVPkontrol(void); //KULLANICI CEVABINI KONTROL EDER (ÇEKİLİP ÇEKİLMEDİĞİNİ,KULLANACAĞI JOKERLER, SORU ŞIKLARINI) 
int parEkle( int *); //SAYAC A GÖRE KAZANDIĞI PARAYI EKLER//(POİNTER KULLANILDI)   <<



//---MAİN FONKSİYONU---
int main(){
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".utf8");
    srand(time(NULL));

    do{ //Oyunu tekrar oynamamıza yarayan do while döngüsü
        int para=0; //YARIŞMACININ KAZANDIĞI PARA MİKTARI
        int *pp=&para; //Para değişkenin adresini tutan pointer
        int x; //CVPkontrol() ÜN RETURN DEĞERİNİ TUTAR

        tanitim();
        
        do{  //10. soruya kadar soruları döndüren do while döngüsü
            printf("\nŞu anda %d. sorudasın\n",sayac);
            yonlendir();
            x=CVPkontrol();
            if(x==1){
                parEkle(pp);
                sayac++;
                if(sayac<11){
                    printf("=================================\nŞu anki kazanılan para:%d\n=================================\n\n\n",para);
        
                    puts("Çekilmek istiyor musunuz?(E/H)\n\a");
                    do{ //Çekilmek isteme sırasında farklı bir veri girildiğinde tekrardan soran do while döngüsü 
                    cevapAl_Byap();
                    } while(cevap[0] != 'E' && cevap[0] != 'H');
                        if(cevap[0] == 'E'){ 
                            tekrarOyna();
                            break; 
                        }    
                    system("cls");
                    continue;
                              
                }   
            }
            else if(x==0){
                printf("Sorun yanlış.Kaybettin\nMalesef %d ₺ ile seni yolluyoruz.\n\n",para/2);
                tekrarOyna();
                break; 
            }        
        } while (sayac!=11);
    
        if(sayac==11){
            printf("Tebrikler! 10. soruyu cevaplayarak 1.000.000 ₺'nin sahibi oldunuz!\n\n\a\a\a\a");
            tekrarOyna();
        }    
    } while (tekrar == 'E');
    system("pause");
    return 0;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fONKSİYONLARIN TANIMLAMALARI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void tanitim(){
    printf("\nMerhaba! Kim Milyoner Olmak İster Yarışmasına Hoşgeldin!\nSeni daha iyi tanıyabilmemiz için lütfen adını gir: ");   
    gets(isim);
    Sleep(500); 
    system("CLS"); 
    printf("\t\t\t\t\tMerhaba "); 
    puts(isim);
    printf("\t\t\t\tYarışmada toplamda 10 soru bulunmakta.\n\t\t\tHer doğru cevabın için ödül havuzunda paran birikir.\n\tYanlış cevabında ise bu havuzundaki paranın sadece 1/2'sini alabilirsin ve ardından yarışma sona erer.\n\t\tJokerlerin için Yarı Yarıya(yy), İki Cevap(ic), Yeni Soru(ys) yazabilirsin.\n");
    printf("\t\t\t\t\tHaydi başlayalım!");
    Sleep(10000); 
    system("CLS");
}

void cevapAl_Byap(){
    gets(cevap);
    for(int i=0;i<2;i++){    
        cevap[i]=toupper(cevap[i]);
    }
}


void tekrarOyna(){
    printf("Tekrar oynamak ister misiniz? Evet(E) veya Hayır(H) tuşlayınız.\t\n\n");
    tekrar=getch();
    tekrar=toupper(tekrar);
    sayac=1, k=0, l=0, m=0;
}
//-------------------------------------------------------------------------------------JOKER FONKSİYONLARI---------------------------------------------------------------------------------------
void yariYariJ(){
    
    int rdm2=0; //rastgele  şık eleme 
    char secenekEle[4];

    int temp=0;
    rdm2=rand()%3;

    if(k==0){
        k++;

        if(sayac>=1 && sayac<=3){
            switch(kolayCVPA[rdm-1]){
                case 'A': secenekEle[0]='B';secenekEle[1]='C';secenekEle[2]='D';break;
                case 'B': secenekEle[0]='A';secenekEle[1]='C';secenekEle[2]='D';break;
                case 'C': secenekEle[0]='A';secenekEle[1]='B';secenekEle[2]='D';break;
                case 'D': secenekEle[0]='A';secenekEle[1]='B';secenekEle[2]='C';break;
            }
        }
        else if(sayac>3 && sayac<=7){
            switch(ortaCVPA[rdm-1]){
                case 'A': secenekEle[0]='B';secenekEle[1]='C';secenekEle[2]='D';break;
                case 'B': secenekEle[0]='A';secenekEle[1]='C';secenekEle[2]='D';break;
                case 'C': secenekEle[0]='A';secenekEle[1]='B';secenekEle[2]='D';break;
                case 'D': secenekEle[0]='A';secenekEle[1]='B';secenekEle[2]='C';break;
            }
        }
        else if(sayac>7 && sayac<=10){
            switch(zorCVPA[rdm-1]){
                case 'A': secenekEle[0]='B';secenekEle[1]='C';secenekEle[2]='D';break;
                case 'B': secenekEle[0]='A';secenekEle[1]='C';secenekEle[2]='D';break;
                case 'C': secenekEle[0]='A';secenekEle[1]='B';secenekEle[2]='D';break;
                case 'D': secenekEle[0]='A';secenekEle[1]='B';secenekEle[2]='C';break;
            }
        }
        
        printf("\n%c ve ",secenekEle[rdm2]);
        temp=rdm2;
        do{
        rdm2=rand()%3;
        }while(secenekEle[rdm2]==secenekEle[temp]);
        printf("%c şıkkı yanlıştır.\n",secenekEle[rdm2]);
        cevapAl_Byap();
        CVPkontrol();
    }
    
    else{
        printf("Bu jokeri tekrar kullanamazsın.\n");
        cevapAl_Byap();
        CVPkontrol();
    }
}

void ikiCevapJ(){
    
    if(l==0) 
    {        
        if(sayac>7){ //cevap yanlışsa tekrar cevap hakkı tanı CVPKontrol() fonk yolla. sayaca göre bakıp ona uygun cevap anahtarını seçer girdiği şık yanlışsa tekrar hak tanır. 
            l++;
            cevapAl_Byap();
           
            if (cevap[0]!=zorCVPA[rdm-1]){
                printf("Cevabınız yanlış,cevabı tekrar giriniz.\n");
                cevapAl_Byap();
                CVPkontrol();
            }
        }
        else{
            printf("Şu an kullanamazsın;7. soruya ulaşıp doğru bilirsen kullanılabilir.\n");
            cevapAl_Byap();
            CVPkontrol();
        }
    }
    else{
        printf("Bu jokeri tekrar kullanamazsın.\n");
        cevapAl_Byap();
        CVPkontrol();
    }
}

void yeniSoruJ(){
    
    if(m==0) //yönlendir fonk git (sayaca bak sayaca göre uygun random soru çeken fonksşyona git )
    {
        m++;
        system("cls");
        yonlendir();
        CVPkontrol();
    }
    else{
        printf("Bu jokeri tekrar kullanamazsın.\n");
        cevapAl_Byap();
        CVPkontrol(); 
    }
}
//----------------------------------------------------------------------------------YÖNLENDİRME FONKSİYONU-----------------------------------------------------------------------------------------
void yonlendir(){

    rdm=1+rand()%25;

    if(sayac>=1 && sayac<=3){
        kRandSoru();
        kSiklar();
        cevapAl_Byap();
    }
    else if(sayac>3 && sayac<=7){
        oRandSoru();
        oSiklar();
        cevapAl_Byap();
    }
    else if(sayac>7 && sayac<=10){
        zRandSoru();
        zSiklar();
        cevapAl_Byap();
    }
}
//----------------------------------------------------------------------------------SORU/ŞIK ÇEKME FONKSİYONLARI-----------------------------------------------------------------------------
void kRandSoru(){
    
    FILE *dosya;
    char gecici[MAX_KARAKTER];

    dosya=fopen("Kolay_sorular.txt","r");

    if(dosya == NULL) //Dosyayı bulamazsa uyarı verip programı sonlandırır
    {
        printf("Dosya açılamadı.\n");
        exit(1);
    }

    bool oku_devam = true;
    int okunan_satır = 1; //fgets'i kaç kere çalıştırdığımızı tutar

    do
    {
        fgets(gecici,MAX_KARAKTER,dosya);
        if(feof(dosya)) //feof() dosya sonuna geldiğinde 0 döndürür
        {
            oku_devam=false;
        }
        else if(okunan_satır==rdm)
        {
            oku_devam=false;
            
            printf("%s\n",gecici);  
        }

        okunan_satır++;

    }while(oku_devam);

    fclose(dosya); 
}

void kSiklar(){

    FILE *dosya;
    char gecici[MAX_KARAKTER];

    dosya=fopen("Kolay_cevaplar.txt","r");

    if(dosya == NULL) //Dosyayı bulamazsa uyarı verip programı sonlandırır
    {
        printf("Dosya açılamadı.\n");
        exit(1);
    }

    bool oku_devam = true;
    int okunan_satır = 1;

    do
    {
        fgets(gecici,MAX_KARAKTER,dosya);
        if(feof(dosya)) //feof() dosya sonuna geldiğinde 0 döndürür
        {
            oku_devam=false;
        }
        else if(okunan_satır==rdm)
        {
            oku_devam=false;
            printf("%s\n",gecici);
        }

        okunan_satır++;

    }while(oku_devam);

    fclose(dosya);
}

void oRandSoru(){

    FILE *dosya;
    char gecici[MAX_KARAKTER];

    dosya=fopen("Orta_sorular.txt","r");

    if(dosya == NULL) //Dosyayı bulamazsa uyarı verip programı sonlandırır
    {
        printf("Dosya açılamadı.\n");
        exit(1);
    }

    bool oku_devam = true;
    int okunan_satır = 1;

    do
    {
        fgets(gecici,MAX_KARAKTER,dosya);
        if(feof(dosya)) //feof() dosya sonuna geldiğinde 0 döndürür
        {
            oku_devam=false;
        }
        else if(okunan_satır==rdm)
        {
            oku_devam=false;
            printf("%s\n",gecici);
        }

        okunan_satır++;

    }while(oku_devam);

    fclose(dosya);
}

void oSiklar(){

    FILE *dosya;
    char gecici[MAX_KARAKTER];

    dosya=fopen("Orta_cevaplar.txt","r");

    if(dosya == NULL) //dosyayı bulamazsa uyarı verip programı sonlandırır
    {
        printf("Dosya açılamadı.\n");
        exit(1);
    }

    bool oku_devam = true;
    int okunan_satır = 1;

    do
    {
        fgets(gecici,MAX_KARAKTER,dosya);
        if(feof(dosya)) //feof() dosya sonuna geldiğinde 0 döndürür
        {
            oku_devam=false;
        }
        else if(okunan_satır==rdm)
        {
            oku_devam=false;
            printf("%s\n",gecici);
        }

        okunan_satır++;

    }while(oku_devam);

    fclose(dosya);
}

void zRandSoru(){

    FILE *dosya;
    char gecici[MAX_KARAKTER];

    dosya=fopen("Zor_sorular.txt","r");

    if(dosya == NULL) //dosyayı bulamazsa uyarı verip programı sonlandırır
    {
        printf("Dosya açılamadı.\n");
        exit(1);
    }

    bool oku_devam = true;
    int okunan_satır = 1;

    do
    {
        fgets(gecici,MAX_KARAKTER,dosya);
        if(feof(dosya)) //feof() dosya sonuna geldiğinde 0 döndürür
        {
            oku_devam=false;
        }
        else if(okunan_satır==rdm)
        {
            oku_devam=false;
            printf("%s\n",gecici);
        }

        okunan_satır++;

    }while(oku_devam);

    fclose(dosya);  
}

void zSiklar(){

    FILE *dosya;
    char gecici[MAX_KARAKTER];

    dosya=fopen("Zor_cevaplar.txt","r");

    if(dosya == NULL) //dosyayı bulamazsa uyarı verip programı sonlandırır
    {
        printf("Dosya açılamadı.\n");
        exit(1);
    }

    bool oku_devam = true;
    int okunan_satır = 1;

    do
    {
        fgets(gecici,MAX_KARAKTER,dosya);
        if(feof(dosya)) //feof() dosya sonuna geldiğinde 0 olmayan bir değer  döndürür
        {
            oku_devam=false;
        }
        else if(okunan_satır==rdm)
        {
            oku_devam=false;
            printf("%s\n",gecici);
        }

        okunan_satır++;

    }while(oku_devam);

    fclose(dosya);
}
//-------------------------------------------------------------------------------CEVAP KONTROL FONKSİYONU------------------------------------------------------------------------------------------
int CVPkontrol(void){
    if(cevap[0]=='Y' && cevap[1]=='S'){    
        yeniSoruJ();
    }
    else if(cevap[0]=='I' && cevap[1]=='C'){
        ikiCevapJ();
    }
    else if(cevap[0]=='Y' && cevap[1]=='Y'){
        yariYariJ();
    }

    { //sorunun sorulduğu zorluğun cevap anahtarıyla cevabı karşılaştır,Doğruysa 1, yanlışsa 0 döndürecek
        if (sayac>=1 && sayac<=3){
            if(cevap[0]==kolayCVPA[rdm-1])
            return 1;
            else if(cevap[0]!=kolayCVPA[rdm-1])     
            return 0;     
        }
            
        if(sayac>3 && sayac<=7){
            if(cevap[0]==ortaCVPA[rdm-1])
                return 1;
            else return 0;
        }
        if (sayac>7 && sayac<=10){
            if(cevap[0]==zorCVPA[rdm-1])
                return 1;
            else return 0;
        }
    }

return 5; //burda döndürülen değerin bi önemi yok
}
//--------------------------------------------------------------------------------PARA EKLEME FONKSİYONU------------------------------------------------------------------------------------------
int parEkle(int *pp){
    switch(sayac){
        case 1:
            *pp=1000;break;
        case 2:
            *pp=3000;break;
        case 3:
            *pp=5000;break;
        case 4:
            *pp=7000;break;
        case 5:
            *pp=15000;break;
        case 6:
            *pp=30000;break;
        case 7:
            *pp=60000;break;
        case 8:
            *pp=125000;break;
        case 9:
            *pp=250000;break;
        case 10:
            *pp=1000000;break;
    }
return *pp;
}