#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int saglik = 100;
    int enerji = 100;
    int yemek = 0;
    int siginak = 0;
    char komut;
    srand(time(NULL));

    printf("=== Hayatta Kalma Simulator ===\n");
    printf("Komutlar:\n");
    printf("A - Avlan\nS - Siginak Ara\nE - Envanteri Goruntule\nR - Dinlen\nF - Tehlike Dalgasi\nP - Sifreli Ilerleme\nY - Yemek Ye\nX - Cikis\n");
    printf("Oyuna baslamadan once ipuclari!   Random gelicek tehlike dalgalarina dikkat et! Ayrica ilk Sifreli ilerleme kismina ilerle.");
    printf("Random Tehlike dalgalari cok can ve enerji goturur!");

    while (1) {
        printf("\n[Durum] Saglik:%d Enerji:%d Yemek:%d Siginak:%d\n", saglik, enerji, yemek, siginak);
        printf("Komut giriniz: ");
        scanf(" %c", &komut);

        switch (komut) {
            case 'A': // Avlan
                enerji -= 10;
                printf("Avlanmaya ciktin. Enerjin 10 azaldi.\n");

                if ((rand() % 2 == 0) && enerji > 20) {
                    yemek++;
                    printf("Av basarili! Yemek buldun.\n");
                } else if ((rand() % 3 == 0) || enerji < 30) {
                    saglik -= 10;
                    printf("Av sirasinda yaralandin! Sagligin 10 azaldi.\n");
                } else {
                    printf("Av basarisiz, hicbir sey bulamadin.\n");
                }
                break;

                 case 'S': // Siginak ara
                 if (siginak == 1) {
                    printf("Zaten bir siginagin var.\n");
                     } else {
                    int sans = rand() % 100;
                       if (sans > 60) {
                         siginak = 1;
                      printf("Siginak buldun! Artik guvendesin.\n");
                    } else {
                         enerji -= 10; // ? Sýðýnak bulunamadýðýnda enerji azalýyor
                      printf("Siginak aradin ama bulamadin. Enerjin 10 azaldi.\n");
                }
                }
                break;

            case 'E': // Envanter
                printf("=== Envanter ===\n");
                printf("Saglik: %d\nEnerji: %d\nYemek: %d\nSiginak: %s\n",
                       saglik, enerji, yemek, siginak ? "Var" : "Yok");
                break;

            case 'R': // Dinlen
                if (siginak == 1) {
                    enerji += 15;
                    saglik += 10;
                    if (enerji > 100) enerji = 100;
                    if (saglik > 100) saglik = 100;
                    printf("Siginakta dinlendin. Enerjin ve sagligin artti.\n");
                } else {
                    enerji += 5;
                    if (enerji > 100) enerji = 100;
                    printf("Acik alanda dinlendin. Enerjin biraz artti.\n");
                }
                break;

            case 'F': // Manuel tehlike dalgasi
                printf("Tehlike dalgasi basliyor!\n");
                {
                    int i;
                    int basari = 0;
                    for (i = 0; i < 5; i++) {
                        int olay = rand() % 3;
                        if (olay == 0) {
                            saglik -= 5;
                            printf("Dalga %d: Sagligin 5 azaldi.\n", i+1);
                        } else if (olay == 1) {
                            enerji -= 5;
                            printf("Dalga %d: Enerjin 5 azaldi.\n", i+1);
                        } else {
                            printf("Dalga %d: Kacmayi basardin!\n", i+1);
                            basari = 1;
                        }
                    }
                    if (basari) {
                        printf("Kodu bulmak icin aniden karsina cikicak olan tehlike dalgasaini yenmelisin.\n");
                         printf("Yuzde uc sansi vardir!!\n");
                    }
                }
                break;

             case 'P': // Sifreli ilerleme
{
                           char sifre;
                printf("Ipucu : Eger sifreyi bulmak istiyorsan tehlikeli seylerle ugrasmalisin...\n\n");
                printf("Sifreyi bilmiyorsan 'E' tusuna basarak geri donebilirsin.\n");
                printf("Engeli asmak icin dogru karakteri gir: ");
                scanf(" %c", &sifre);

             if (sifre == 'E') {
               printf("Geri donmeyi sectin. Sifreli ilerleme iptal edildi, ana menuye donuyorsun.\n");
               break; // Ceza yok, ana menüye dön
    }

                if (sifre != 'Z') {
                   printf("Sifreyi yanlis bildiniz! Enerji -10, Saglik -20\n");
                enerji -= 10;
                saglik -= 20;
    }           else {
                   printf("Dogru! Karsiniza gizli bir kapi acildi ve birsuru altin buldunuz!! Oyunu bitirdiniz!\n");
         return 0;
    }
}
break;  

            case 'Y': // Yemek ye
                if (yemek > 0) {
                    yemek--;
                    enerji += 10;
                    if (enerji > 100) enerji = 100;
                    printf("Yemek yedin! Enerjin 10 artti.\n");
                } else {
                    printf("Yemegin yok! Yemek bulmadan yiyemezsin.\n");
                }
                break;

            case 'X': // Cikis
                printf("Oyundan cikiliyor...\n");
                return 0;

            default:
                printf("Gecersiz komut!\n");
                break;
        }

        // Enerji 0 kontrolü
        if (enerji <= 0) {
            printf("Enerjin tukendi. Oyun bitti!\n");
            break;
        }

        // Saglik kontrolu
        if (saglik <= 0) {
            printf("Sagligin tukendi. Oyun bitti!\n");
            break;
        }

        // RANDOM TEHLIKE DALGASI
if (rand() % 100 < 3 ) { // %3 ihtimalle otomatik dalga
    printf("\n!!! Beklenmedik bir tehlike dalgasi basladi !!!\n");
    printf("Cok kotu bir saldiriya maruz kaldin ancak sifreli ilerleme kisminin sifresini buldun... Sifre : Z.\n");

    // Saðlýk azaltma
    saglik -= 30;
    printf("Ani saldiri! Sagligin 30 azaldi.\n");

    // Enerji azaltma
    enerji -= 15;
    printf("Ani saldiri! Enerjin 15 azaldi.\n");
     }
    }
    return 0;
  }  
