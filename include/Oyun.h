#ifndef OYUN_H
#define OYUN_H
#include<windows.h>
#include <limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Kisi.h"
#include "Dosya.h"
//nesne y�nelimliye benzetmek i�in gerekli olan yap�lar kurucunun i�ersinde tan�mlanm��t�r
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
	//g�sterici fonksiyon olu�turma h dosyas� i�erisinde g�revlendirilecek
		void (*anaoyun)(struct OYUN*);
		void (*delete)(struct OYUN*);
};
//Oyun yap�sn�n� isimlendirme
typedef struct OYUN* Oyun;
//yap�n�n kurucu imzas�
Oyun Oyunolustur();
//kullan�lan fonksiyonun imzasi
void anaoyun (const Oyun);
void delete_Oyun(const Oyun);

#endif

