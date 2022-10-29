#ifndef KISI_H
#define KISI_H
#define MAX_STR_LEN 80
#include<windows.h>
#include <limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//nesne y�nelimliye benzetmek i�in gerekli olan yap�lar kurucunun i�ersinde tan�mlanm��t�r
typedef struct link_node {
	char node_str[MAX_STR_LEN];
	struct link_node *next;
	char oran[100];
	char sayi[15];
	char para[200];
	
} node;
//kurucu icin imza tan�mlama
node*  testGetFile();
//gerekli fonksiyonlar�n imzalari

int compare_node(struct link_node *n1, struct link_node *n2);
//gerekli fonksiyonlar�n imzalari
struct link_node *add_node(struct link_node	*list, struct link_node *node);
//gerekli fonksiyonlar�n imzalari
void display_list(struct link_node *head);
//gerekli fonksiyonlar�n imzalari
//heap alan� bo�altmak i�in y�k�c� fonksiyon
void free_list(node *head);

#endif
