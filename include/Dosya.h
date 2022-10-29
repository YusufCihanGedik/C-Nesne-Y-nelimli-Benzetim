#ifndef DOSYA_H
#define DOSYA_H
#include<windows.h>
#include <limits.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//Nesne yönelimliye benzetmek için oluþturulan kurucu fonksiyonun içerik kýsmý
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
	//H dosyalarý içerisinde tanýmlanan c dosyalarýnda kullanýlan iþaretçi fonksiyon imzalarý
	void (*print_sekilciz)(struct DOSYA* ,int,int);
	void (*print_sekilciz2)(struct DOSYA* ,int,int);
	void (*delete)(struct DOSYA*);
	
};
//Kurucu fonk adlandýrma
typedef struct DOSYA* Dosya;
Dosya Dosyaolustur();
//C dosyalarý için kullandýðýmýz fonksiyon imza kýsýmlarý
//bu fonksiyon baþliklarý sayesýnde c dosyalarýnda iþlem gerçekleþtirebiliriz
void gotoxy ();
//C dosyalarý için kullandýðýmýz fonksiyon imza kýsýmlarý
//bu fonksiyon baþliklarý sayesýnde c dosyalarýnda iþlem gerçekleþtirebiliriz
//þekil çizme baþlýk dosyasý
void print_sekilciz(const Dosya,int,int);
//C dosyalarý için kullandýðýmýz fonksiyon imza kýsýmlarý
//bu fonksiyon baþliklarý sayesýnde c dosyalarýnda iþlem gerçekleþtirebiliriz
//þekil çizme baþlýk dosyasý 2
void print_sekilciz2(const Dosya,int,int);
//C dosyalarý için kullandýðýmýz fonksiyon imza kýsýmlarý
//bu fonksiyon baþliklarý sayesýnde c dosyalarýnda iþlem gerçekleþtirebiliriz
//Yýkýcý fonksiyon baþlýk dosyasý
void delete_Dosya(const Dosya);
#endif

