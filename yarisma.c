#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

int Kolay_Sorular(int okunacak_satir);
int Kolay_Cevaplar(int okunacak_satir);
int Orta_Sorular(int okunacak_satir);
int Orta_Cevaplar(int okunacak_satir);
int Zor_Sorular(int okunacak_satir);
int Zor_Cevaplar(int okunacak_satir);
int Para_Havuzu(int *genel_sayac);

char Kolay_CevapAnahtari[26]={'D','A','A','A','B','C','B','A','A','D','D','B','A','D','B','B','B','A','D','C','A','C','B','C','C'};
char Orta_CevapAnahtari[26]={'A','B','C','B','A','D','B','A','D','A','A','D','D','B','C','A','A','B','D','A','D','C','B','C','A'};
char Zor_CevapAnahtari[26]={'C','B','C','D','B','C','A','C','D','C','D','A','C','B','A','D','C','A','C','A','C','C','B','D','C'};

int okunacak_satir = 0;
int para_odulu=0;
char tekrar;

#define MAX_SATIR 2048


int main(){
//----------------------------------------------------------------------------------------------------//
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".utf8");
//----------------------------------------------------------------------------------------------------//
char isim[30];
    printf("Merhaba! Kim Milyoner Olmak İster Yarışmasına Hoşgeldin!\nSeni daha iyi tanıyabilmemiz için lütfen adını gir: ");   
gets(isim);
Sleep(500); 
system("CLS"); 
    printf("Merhaba "); 
puts(isim);
    printf("Yarışmada toplamda 10 soru bulunmakta.\nHer doğru cevabın için ödül havuzunda paran birikir.\nYanlış cevabında ise bu havuzundaki paranın sadece 1/3'ünü alabilirsin ve ardından yarışma sona erer.\n");
    printf("\t\t\t\tHaydi başlayalım!");
Sleep(10000); 
system("CLS");
//----------------------------------------------------------------------------------------------------//
do{    
char ch;
int *genel_sayac=0;
 for(int sayac1=0; sayac1<3; sayac1++){
    Kolay_Sorular(okunacak_satir);
    Kolay_Cevaplar(okunacak_satir);     
    printf("Cevabınız: ");
    ch = getch(); 
    ch = toupper(ch);
    if(ch != Kolay_CevapAnahtari[*genel_sayac]){ 
        printf("Yarışmadan elendiniz!\nÖdülünüz: %d ₺\n", para_odulu);
    }
    else if(ch == Kolay_CevapAnahtari[*genel_sayac]){
        continue;
    }
    system("CLS");
    *genel_sayac++;
}
 for(int sayac2=0; sayac2<4; sayac2++){
    Orta_Sorular(okunacak_satir);
    Orta_Cevaplar(okunacak_satir);     
    printf("Cevabınız: ");
    ch = getch(); 
    ch = toupper(ch);
    if(ch != Orta_CevapAnahtari[*genel_sayac]){ 
        printf("Yarışmadan elendiniz!\nÖdülünüz: %d ₺\n", para_odulu);
    }
    else if(ch == Orta_CevapAnahtari[*genel_sayac]){
        continue;
    }
    system("CLS");
    *genel_sayac++;
}
 for(int sayac3=0; sayac3<3; sayac3++){
    Zor_Sorular(okunacak_satir);
    Zor_Cevaplar(okunacak_satir);     
    printf("Cevabınız: ");
    ch = getch(); 
    ch = toupper(ch);
    if(ch != Zor_CevapAnahtari[*genel_sayac]){ 
        printf("Yarışmadan elendiniz!\nÖdülünüz: %d ₺\n", para_odulu);
    }
    else if(ch == Zor_CevapAnahtari[*genel_sayac]){
        continue;
    }
    system("CLS");
    *genel_sayac++;
}
    printf("Tebrikler! 10. soruyu cevaplayarak 1000000 ₺'nin sahibi oldunuz!\n");
    printf("Tekrar oynamak ister misiniz? Evet(E) veya Hayır(H) tuşlayınız.\t");
    tekrar=getch();
    tekrar=toupper(tekrar);
}
while(tekrar == 'E');     
    system("pause");
    return 0;
}
//----------------------------------------------------------------------------------------------------//
int Kolay_Sorular(int okunacak_satir){
    FILE *Kolay_S;

    char buffer[MAX_SATIR];

    Kolay_S = fopen("Kolay_Sorular.txt", "r");
    
   
    printf("Okunan satır: ");    //Okunan satır olaylarını çöz.
    scanf("%d", &okunacak_satir);

    if(Kolay_S == NULL){
        printf("Dosya açılırken hata oldu.\n");
        return 1;
    }

    bool okumaya_devam = true;
    int okunan_satir = 1;
    do{
        fgets(buffer,MAX_SATIR, Kolay_S);

        if(okunan_satir == okunacak_satir){
            okumaya_devam = false;
            printf("%s", buffer);
        }
        okunan_satir++;
    }
    while(okumaya_devam);
    fclose(Kolay_S);
}

int Kolay_Cevaplar(int okunacak_satir){
    FILE *Kolay_C;

    char buffer[MAX_SATIR];

    Kolay_C = fopen("Kolay_Cevaplar.txt", "r");
    
   
    printf("Okunan satır: ");
    scanf("%d", &okunacak_satir);

    if(Kolay_C == NULL){
        printf("Dosya açılırken hata oldu.\n");
        return 1;
    }

    bool okumaya_devam = true;
    int okunan_satir = 1;
    do{
        fgets(buffer,MAX_SATIR, Kolay_C);

        if(okunan_satir == okunacak_satir){
            okumaya_devam = false;
            printf("%s", buffer);
        }
        okunan_satir++;
    }
    while(okumaya_devam);
    okunacak_satir++;
    fclose(Kolay_C);
}
//----------------------------------------------------------------------------------------------------//
int Orta_Sorular(int okunacak_satir){
    FILE *Orta_S;

    char buffer[MAX_SATIR];

    Orta_S = fopen("Orta_Sorular.txt", "r");
    
   
    printf("Okunan satır: ");
    scanf("%d", &okunacak_satir);

    if(Orta_S == NULL){
        printf("Dosya açılırken hata oldu.\n");
        return 1;
    }

    bool okumaya_devam = true;
    int okunan_satir = 1;
    do{
        fgets(buffer,MAX_SATIR, Orta_S);

        if(okunan_satir == okunacak_satir){
            okumaya_devam = false;
            printf("%s", buffer);
        }
        okunan_satir++;
    }
    while(okumaya_devam);
    fclose(Orta_S);
}

int Orta_Cevaplar(int okunacak_satir){
    FILE *Orta_C;

    char buffer[MAX_SATIR];

    Orta_C = fopen("Orta_Cevaplar.txt", "r");
    
   
    printf("Okunan satır: ");
    scanf("%d", &okunacak_satir);

    if(Orta_C == NULL){
        printf("Dosya açılırken hata oldu.\n");
        return 1;
    }

    bool okumaya_devam = true;
    int okunan_satir = 1;
    do{
        fgets(buffer,MAX_SATIR, Orta_C);

        if(okunan_satir == okunacak_satir){
            okumaya_devam = false;
            printf("%s", buffer);
        }
        okunan_satir++;
    }
    while(okumaya_devam);
    okunacak_satir++;
    fclose(Orta_C);
    
}
//----------------------------------------------------------------------------------------------------//
int Zor_Sorular(int okunacak_satir){
    FILE *Zor_S;

    char buffer[MAX_SATIR];

    Zor_S = fopen("Zor_Sorular.txt", "r");
    
   
    printf("Okunan satır: ");
    scanf("%d", &okunacak_satir);

    if(Zor_S == NULL){
        printf("Dosya açılırken hata oldu.\n");
        return 1;
    }

    bool okumaya_devam = true;
    int okunan_satir = 1;
    do{
        fgets(buffer,MAX_SATIR, Zor_S);

        if(okunan_satir == okunacak_satir){
            okumaya_devam = false;
            printf("%s", buffer);
        }
        okunan_satir++;
    }
    while(okumaya_devam);
    fclose(Zor_S);
}

int Zor_Cevaplar(int okunacak_satir){
    FILE *Zor_C;

    char buffer[MAX_SATIR];

    Zor_C = fopen("Orta_Cevaplar.txt", "r");
    
   
    printf("Okunan satır: ");
    scanf("%d", &okunacak_satir);

    if(Zor_C == NULL){
        printf("Dosya açılırken hata oldu.\n");
        return 1;
    }

    bool okumaya_devam = true;
    int okunan_satir = 1;
    do{
        fgets(buffer,MAX_SATIR, Zor_C);

        if(okunan_satir == okunacak_satir){
            okumaya_devam = false;
            printf("%s", buffer);
        }
        okunan_satir++;
    }
    while(okumaya_devam);
    okunacak_satir++;
    fclose(Zor_C);
    
}
//----------------------------------------------------------------------------------------------------//
int Para_Havuzu(int *genel_sayac){
        switch(*genel_sayac){
        case 0:
            para_odulu=0;break;    
        case 1:
            para_odulu=1000;break;
        case 2:
            para_odulu=3000;break;
        case 3:
            para_odulu=5000;break;
        case 4:
            para_odulu=7500;break;
        case 5:
            para_odulu=15000;break;
        case 6:
            para_odulu=30000;break;
        case 7:
            para_odulu=60000;break;
        case 8:
            para_odulu=125000;break;
        case 9:
            para_odulu=250000;break;
        case 10:
            para_odulu=1000000;break;
    }
return para_odulu;
}
//----------------------------------------------------------------------------------------------------//
