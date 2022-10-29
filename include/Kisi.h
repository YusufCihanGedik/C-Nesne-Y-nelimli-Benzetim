#ifndef KISI_H
#define KISI_H
#define MAX_STR_LEN 80
#include<windows.h>
#include <limits.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//nesne yönelimliye benzetmek için gerekli olan yapýlar kurucunun içersinde tanýmlanmýþtýr
typedef struct link_node {
	char node_str[MAX_STR_LEN];
	struct link_node *next;
	char oran[100];
	char sayi[15];
	char para[200];
	
} node;
//kurucu icin imza tanýmlama
node*  testGetFile();
//gerekli fonksiyonlarýn imzalari

int compare_node(struct link_node *n1, struct link_node *n2);
//gerekli fonksiyonlarýn imzalari
struct link_node *add_node(struct link_node	*list, struct link_node *node);
//gerekli fonksiyonlarýn imzalari
void display_list(struct link_node *head);
//gerekli fonksiyonlarýn imzalari
//heap alaný boþaltmak için yýkýcý fonksiyon
void free_list(node *head);

#endif
