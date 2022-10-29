

#include "Kisi.h"
	node*  testGetFile() {

    // dosya açma ve veri okuma iþlemin gerçekleþtiði kýsým
    FILE *fp = fopen("Kisiler.txt", "r");
    size_t len = 255;
   
    // hat için malloc belleðe ihtiyaç var, deðilse segmentasyon hatasý oluþacak.
    char *line = malloc(sizeof(char) * len);
    // hat için malloc belleðe ihtiyaç var, deðilse segmentasyon hatasý oluþacak.
   
    // dosyanýn var olup olmadýðýný kontrol edin (ve açabilirsiniz) veya deðil
    
     //Ana algoritma iþlemleri için kullanýlacak deðiþkenlerin char* olarak oluþturulmuþ hali
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
        //ayýrma iþlemi için karakter tanýmlama
   const char s[2] = "#";
  //Sistemdeki deðiþkenlerin atanmasý iiçin oluþturulan linked list
   token = strtok(line, s);
   		isim=token;
   		newNode = (node*)malloc(sizeof(node)); //linkes liste ekleme bölümleri
		strcpy(newNode->node_str, isim);
		newNode->next = NULL; //Kuyruðun bir sornakýini boþ atama bölümü
   		 //karaktere baðlý olarak ayýrma iþlemi
	token = strtok(NULL, s);
	para1=token;
		strcpy(newNode->para, para1); //para1 newnode->para ya kopyalama kýsmý
		
	//printf("%s\n :",para1);
	token = strtok(NULL, s);
	oran1=token;
		strcpy(newNode->oran, oran1);//kopyalama kýsmý
	//printf("%s\n :",oran);
	token = strtok(NULL, s);
	sayi1=token;
		strcpy(newNode->sayi ,sayi1); //kopyalama kýsmý
	//printf("%s\n :",sayi);
    head = add_node(head, newNode);
    }
    
 	//display_list(head);
	fclose(fp);
	    return head;
}
//yukrýda kullanýlan ekleme kýsmýnýn arka plnada çalýþan kod kýsmý
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
//Yýkýcý fonksiyon heap içerisinde ayrýlan alaný temizleme kýsmý
void free_list(node *head) {
	node *prev = head;
	node *cur = head;
	while (cur) {
		prev = cur;
		cur = prev->next;
		free(prev);
	}
}
//linked list için bir sonrakini atmama ve yazdýrma kýsmý
void display_list(struct link_node *head) {
	while (head) {
		//printf("%s\t %s\t %s\t %s\n",head->node_str,head->para,head->oran,head->sayi);
		head = head->next;
	}
}
