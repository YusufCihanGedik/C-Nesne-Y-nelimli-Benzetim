#ifndef DOSYA_H
#define DOSYA_H
#include<windows.h>
#include <limits.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//Nesne y�nelimliye benzetmek i�in olu�turulan kurucu fonksiyonun i�erik k�sm�
struct DOSYA{
	int rows;
	int columns;
	int i;
	int j;
	int x;
	int y;
	int a;
    int b;
	int c;
	//H dosyalar� i�erisinde tan�mlanan c dosyalar�nda kullan�lan i�aret�i fonksiyon imzalar�
	void (*print_sekilciz)(struct DOSYA* ,int,int);
	void (*print_sekilciz2)(struct DOSYA* ,int,int);
	void (*delete)(struct DOSYA*);
	
};
//Kurucu fonk adland�rma
typedef struct DOSYA* Dosya;
Dosya Dosyaolustur();
//C dosyalar� i�in kulland���m�z fonksiyon imza k�s�mlar�
//bu fonksiyon ba�liklar� sayes�nde c dosyalar�nda i�lem ger�ekle�tirebiliriz
void gotoxy ();
//C dosyalar� i�in kulland���m�z fonksiyon imza k�s�mlar�
//bu fonksiyon ba�liklar� sayes�nde c dosyalar�nda i�lem ger�ekle�tirebiliriz
//�ekil �izme ba�l�k dosyas�
void print_sekilciz(const Dosya,int,int);
//C dosyalar� i�in kulland���m�z fonksiyon imza k�s�mlar�
//bu fonksiyon ba�liklar� sayes�nde c dosyalar�nda i�lem ger�ekle�tirebiliriz
//�ekil �izme ba�l�k dosyas� 2
void print_sekilciz2(const Dosya,int,int);
//C dosyalar� i�in kulland���m�z fonksiyon imza k�s�mlar�
//bu fonksiyon ba�liklar� sayes�nde c dosyalar�nda i�lem ger�ekle�tirebiliriz
//Y�k�c� fonksiyon ba�l�k dosyas�
void delete_Dosya(const Dosya);
#endif

