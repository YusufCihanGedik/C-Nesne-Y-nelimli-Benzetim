

#include "Kisi.h"
	node*  testGetFile() {

    // dosya a�ma ve veri okuma i�lemin ger�ekle�ti�i k�s�m
    FILE *fp = fopen("Kisiler.txt", "r");
    size_t len = 255;
   
    // hat i�in malloc belle�e ihtiya� var, de�ilse segmentasyon hatas� olu�acak.
    char *line = malloc(sizeof(char) * len);
    // hat i�in malloc belle�e ihtiya� var, de�ilse segmentasyon hatas� olu�acak.
   
    // dosyan�n var olup olmad���n� kontrol edin (ve a�abilirsiniz) veya de�il
    
     //Ana algoritma i�lemleri i�in kullan�lacak de�i�kenlerin char* olarak olu�turulmu� hali
     char* isim;
   char* para1;
   char* oran1;
   char* sayi1;
   char *token;
   
	char isimler[30];
	char input[MAX_STR_LEN];
	
	node *head, *newNode;
	
	head = NULL;
	
		
   
   int a=0;
   
    while(fgets(line, len, fp) != NULL ) {
    	
       // printf("%s", line);
        //ay�rma i�lemi i�in karakter tan�mlama
   const char s[2] = "#";
  //Sistemdeki de�i�kenlerin atanmas� ii�in olu�turulan linked list
   token = strtok(line, s);
   		isim=token;
   		newNode = (node*)malloc(sizeof(node)); //linkes liste ekleme b�l�mleri
		strcpy(newNode->node_str, isim);
		newNode->next = NULL; //Kuyru�un bir sornak�ini bo� atama b�l�m�
   		 //karaktere ba�l� olarak ay�rma i�lemi
	token = strtok(NULL, s);
	para1=token;
		strcpy(newNode->para, para1); //para1 newnode->para ya kopyalama k�sm�
		
	//printf("%s\n :",para1);
	token = strtok(NULL, s);
	oran1=token;
		strcpy(newNode->oran, oran1);//kopyalama k�sm�
	//printf("%s\n :",oran);
	token = strtok(NULL, s);
	sayi1=token;
		strcpy(newNode->sayi ,sayi1); //kopyalama k�sm�
	//printf("%s\n :",sayi);
    head = add_node(head, newNode);
    }
    
 	//display_list(head);
	fclose(fp);
	    return head;
}
//yukr�da kullan�lan ekleme k�sm�n�n arka plnada �al��an kod k�sm�
struct link_node *add_node(struct link_node	*list, struct link_node *node){
	struct link_node *prev, *next;
	if (!list) {
		list = node;
	}
	else {
		prev = NULL;
		next = list;
		while (next ) {
			prev = next;
			next = next->next;
		}
		if (!next) {
			prev->next = node;
		}
		else {
			if (prev) {
				node->next = prev->next;
				prev->next = node;
			}
			else {
				node->next = list;
				list = node;
			}
		}
	}
	return list;
}
//Y�k�c� fonksiyon heap i�erisinde ayr�lan alan� temizleme k�sm�
void free_list(node *head) {
	node *prev = head;
	node *cur = head;
	while (cur) {
		prev = cur;
		cur = prev->next;
		free(prev);
	}
}
//linked list i�in bir sonrakini atmama ve yazd�rma k�sm�
void display_list(struct link_node *head) {
	while (head) {
		//printf("%s\t %s\t %s\t %s\n",head->node_str,head->para,head->oran,head->sayi);
		head = head->next;
	}
}
