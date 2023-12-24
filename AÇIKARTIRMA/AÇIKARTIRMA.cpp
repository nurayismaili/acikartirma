#include <stdio.h>
#include <stdlib.h>
//sturct yradýmýyla daha sonradan da kullanacaðým bazý deðiþkenler tanýmlýyorum
//typedef yardýmýyla da struct içinde yazdýðým deðiþkenleri sonradan deðiþtirebileceðim
typedef struct acikattirma {
    int teklifsirasi;
    char teklifvereninadi[40];
    //40 karakterlik bir yer ayýrdým fazla olmuþ olabilir ama þirket adý kullnýldýðýný düþünürsek uygun olabilir
    int teklifi;
    // ,ihalelerim çok büyük deðil:)
} 
acikartirma;
//burada hata aldýðým için bunu yazdým
int main() {
    acikartirma aa;
    int enbuyukteklif = 0;  // E
    int kazanansira = 0;   // Kazananýn teklif sýrasýný takip eden deðiþken

    char cevap;

    printf("*********Acik Artirmaya Hosgeldiniz*********\n\n");
    printf("Baslangic degeri giriniz: ");
    //açýk arttýrmayý yapan kiþi ürün için bir baþlangýç deðeri girmeli ki alýcý adaylarý bu deðere göre teklifte bulunsun
    int baslangic;
    scanf("%d", &baslangic);

    printf("\nBaslangic degeri: %d\n\n", baslangic);
    printf("Verilen teklif baslangic degerinden buyuk olmalidir.\n\n");
    //burada kullnýcýdan baþlangýç deðerrinden daha küçük bir deðer girmemesini istedim
    while (1) {
        printf("Yeni teklif var mi? (v/y): ");
        scanf(" %c", &cevap);
    /*burada diðer teklif verenlere yeni bir tekliflerinin olup olmadýðýný soruyorum 
	buna cevap vermeleri için cevap adýnda bir deðiþken tanýmlýyorum*/
	//burada bir döngü açýyorum ki yeni teklifler verdikçe tekrar yeni teklif olup olmadýðýný sorsun
        if (cevap == 'v' || cevap == 'V') {
            printf("Yeni teklif var\n ");
            printf("------------------------------------------------\n");
        //v veya V girilirse yeni teklif vernin adý ,numarasý ve teklifi alýnacak
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
// y veya Y girilirse yeni teklif olmadýðýný ve açýk artýrmayý kazanan kiþinin adý teklif numarasý ve ödeyeceði tutar ekrana yazdýrýlacak
            if (kazanansira != 0) {
                printf("En buyuk teklif: %d\n", enbuyukteklif);
                printf("Kazananin adi: %s\n", aa.teklifvereninadi);
                printf("Kazananin teklif sirasi: %d\n", kazanansira);
                printf("Kazananin odeyecegi tutar: %d\n", enbuyukteklif);
            } else {
                printf("Henüz kazanan bir teklif yok.\n");
            }

            break; // Döngüden çýkmasýný saðlýyorum break komutuyla
        }
    }

    return 0;
}
