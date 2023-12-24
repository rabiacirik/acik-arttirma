//
//  main.c
//  açık arttırma
//
//  Created by Rabia Cırık on 22.12.2023.
//
#include <stdio.h>

// Veri tipleri
typedef struct musteri {
  int musteri_id;
  char musteri_adi[30];
  int teklif_fiyat;
} Musteri;

typedef struct urun {
  int urun_id;
  char urun_adi[30];
  int baslangic_fiyat;
} Urun;


void acik_artir(Musteri musteriler[], Urun urunler[], int musteri_sayisi, int urun_sayisi) {
  // Tüm müşterilerin tekliflerini sıfırlar.
  for (int i = 0; i < musteri_sayisi; i++) {
    musteriler[i].teklif_fiyat = 0;
  }

  // Tüm ürünleri sırayla gezer.
  for (int i = 0; i < urun_sayisi; i++) {
    // Ürünün başlangıç fiyatını yazdırır.
    printf("%s: %d TL\n", urunler[i].urun_adi, urunler[i].baslangic_fiyat);

    // Açık artırmanın süresini sınırlar.herkes bir teklif verir
    int sure = 1;
    while (sure > 0) {
      // Müşterilerin tekliflerini alır.
      for (int j = 0; j < musteri_sayisi; j++) {
        printf("%s, teklifinizi girin: ", musteriler[j].musteri_adi);
        scanf("%d", &musteriler[j].teklif_fiyat);
      }

      // En yüksek teklifi veren müşteriyi belirler.
      int en_yuksek_teklif = 0;
      int en_yuksek_teklif_veren_musteri = 0;
      for (int j = 0; j < musteri_sayisi; j++) {
        if (musteriler[j].teklif_fiyat > en_yuksek_teklif) {
          en_yuksek_teklif = musteriler[j].teklif_fiyat;
          en_yuksek_teklif_veren_musteri = j;
        }
      }

      // Ürünü bu müşteriye satar.
      printf("%s, ürünü %d TL'ye kazandınız.\n", musteriler[en_yuksek_teklif_veren_musteri].musteri_adi, en_yuksek_teklif);
      sure--;
    }
  }
}

int main() {
  // Musterileri olustur
  Musteri musteriler[] = {
    {1, "1.kişi",100},
    {2, "2.kişi",200},
    {3, "3.kişi",300},
  };

  // Urunleri olustur
  Urun urunler[] = {
    {1, "Tablo", 1000},
    {2, "Saat", 2000},
    {3, "Vazo", 3000}
  };

  // Musteri sayisini ve urun sayisini gir
  int musteri_sayisi = sizeof(musteriler) / sizeof(Musteri);
  int urun_sayisi = sizeof(urunler) / sizeof(Urun);

  // Acik artirmayi baslat
  acik_artir(musteriler, urunler, musteri_sayisi, urun_sayisi);

  return 0;
}
