#include <stdio.h>
#include <stdlib.h>
//sturct yrad�m�yla daha sonradan da kullanaca��m baz� de�i�kenler tan�ml�yorum
//typedef yard�m�yla da struct i�inde yazd���m de�i�kenleri sonradan de�i�tirebilece�im
typedef struct acikattirma {
    int teklifsirasi;
    char teklifvereninadi[40];
    //40 karakterlik bir yer ay�rd�m fazla olmu� olabilir ama �irket ad� kulln�ld���n� d���n�rsek uygun olabilir
    int teklifi;
    // ,ihalelerim �ok b�y�k de�il:)
} 
acikartirma;
//burada hata ald���m i�in bunu yazd�m
int main() {
    acikartirma aa;
    int enbuyukteklif = 0;  // E
    int kazanansira = 0;   // Kazanan�n teklif s�ras�n� takip eden de�i�ken

    char cevap;

    printf("*********Acik Artirmaya Hosgeldiniz*********\n\n");
    printf("Baslangic degeri giriniz: ");
    //a��k artt�rmay� yapan ki�i �r�n i�in bir ba�lang�� de�eri girmeli ki al�c� adaylar� bu de�ere g�re teklifte bulunsun
    int baslangic;
    scanf("%d", &baslangic);

    printf("\nBaslangic degeri: %d\n\n", baslangic);
    printf("Verilen teklif baslangic degerinden buyuk olmalidir.\n\n");
    //burada kulln�c�dan ba�lang�� de�errinden daha k���k bir de�er girmemesini istedim
    while (1) {
        printf("Yeni teklif var mi? (v/y): ");
        scanf(" %c", &cevap);
    /*burada di�er teklif verenlere yeni bir tekliflerinin olup olmad���n� soruyorum 
	buna cevap vermeleri i�in cevap ad�nda bir de�i�ken tan�ml�yorum*/
	//burada bir d�ng� a��yorum ki yeni teklifler verdik�e tekrar yeni teklif olup olmad���n� sorsun
        if (cevap == 'v' || cevap == 'V') {
            printf("Yeni teklif var\n ");
            printf("------------------------------------------------\n");
        //v veya V girilirse yeni teklif vernin ad� ,numaras� ve teklifi al�nacak
            printf("Teklif sahibinin numarasi: ");
            scanf("%d", &aa.teklifsirasi);

            printf("Teklif sahibinin adi: ");
            scanf("%s", aa.teklifvereninadi);

            printf("Teklifi: ");
            scanf("%d", &aa.teklifi);

            if (aa.teklifi > enbuyukteklif) {
                enbuyukteklif = aa.teklifi;
                kazanansira = aa.teklifsirasi;
            }
        } else if (cevap == 'y' || cevap == 'Y') {
            printf("Yeni teklif yok\n");
// y veya Y girilirse yeni teklif olmad���n� ve a��k art�rmay� kazanan ki�inin ad� teklif numaras� ve �deyece�i tutar ekrana yazd�r�lacak
            if (kazanansira != 0) {
                printf("En buyuk teklif: %d\n", enbuyukteklif);
                printf("Kazananin adi: %s\n", aa.teklifvereninadi);
                printf("Kazananin teklif sirasi: %d\n", kazanansira);
                printf("Kazananin odeyecegi tutar: %d\n", enbuyukteklif);
            } else {
                printf("Hen�z kazanan bir teklif yok.\n");
            }

            break; // D�ng�den ��kmas�n� sa�l�yorum break komutuyla
        }
    }

    return 0;
}
