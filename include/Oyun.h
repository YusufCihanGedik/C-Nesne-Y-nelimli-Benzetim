#ifndef OYUN_H
#define OYUN_H
#include<windows.h>
#include <limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Kisi.h"
#include "Dosya.h"
//nesne yönelimliye benzetmek için gerekli olan yapýlar kurucunun içersinde tanýmlanmýþtýr
struct OYUN{
	int sayitur;
    int tursayisi;
    int sayi; 
	double oran;
	double para;
	double yenipara;
	double yatirilanpara;
	double yeniyatirilanpara;
	double masabakiye;
	double yenimasabakiye;
	char* isim;
	int i;
	
	char* zenginkisi;
	int turdondur;
	//gösterici fonksiyon oluþturma h dosyasý içerisinde görevlendirilecek
		void (*anaoyun)(struct OYUN*);
		void (*delete)(struct OYUN*);
};
//Oyun yapýsnýný isimlendirme
typedef struct OYUN* Oyun;
//yapýnýn kurucu imzasý
Oyun Oyunolustur();
//kullanýlan fonksiyonun imzasi
void anaoyun (const Oyun);
void delete_Oyun(const Oyun);

#endif

