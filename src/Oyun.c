#include "Oyun.h"
//nesne yönelimliye benzzetmek için aþþaðýda gereken tanýmlar
Oyun Oyunolustur(){
	Oyun this;
	this = (Oyun)malloc(sizeof(struct OYUN));
	this->i=0;
	this->isim;
	this->masabakiye=0;
	this->oran=0;
	this->para=0;
	this->sayi=0;
	this->sayitur;
	this->tursayisi=0;
	this->yatirilanpara=0;
	this->yenimasabakiye=0;
	this->yenipara=0;
	
	this->zenginkisi;
	this->turdondur=0;
	this->yeniyatirilanpara=0;
	//iþaret eden fonk ile fonkun eþleþmesi
	this->anaoyun= &anaoyun;
	//iþaret eden fonk ile fonkun eþleþmesi
	this->delete= &delete_Oyun;
	return this;
}
void anaoyun (const Oyun this){
	//ana oyun içerisinde dosya iþlemleri içi yazýlan durum
		Dosya dosya=Dosyaolustur();
		
	
	//Dosya dosya= Dosyaolustur(dosya);
	//Þekil çizdirme alaný
	print_sekilciz(dosya,13,50);
	//testgetfile baþlatma alaný
	node* head =testGetFile();
	//linked listi yazdýrna alaný
	display_list(head);
	
 	node* a;
 	a=head;
	
	 // open file
    FILE *fp = fopen("Sayilar.txt", "r");
    size_t len = 255;
    
    
    
   
    char *line = malloc(sizeof(char) * len);
   //dosya açýlýp açýlmama durumunu kontrol eden koþul yapýsý
    if (fp == NULL) {
        printf("can open file input1.txt!");
        return;
    }
    //dosya iþlemleri için gerekli while döngüsü
    while(fgets(line, len, fp) != NULL) {
       //sayitura line çevirerek atama iþlemi
      this->sayitur=atoi(line);
      
      
    
	int decimal, sign; 
	//en son olan zengin kiþiyi bulmak için tanýmlama
	double zenginkisipara=0;
	
	
		/*zenginkisipara=atof(head->para);
		zenginkisi=head->node_str;*/
	head=a;
	//sistemin döndüðü alan
	 while (head) {
		//printf("%s\t %s\t %s\t %s \n", head->node_str,head->para,head->oran,head->sayi);
		//hesaplamlamalar için gerekli çiverme iþlemleri
		this->isim=head->node_str;
		//hesaplamlamalar için gerekli çiverme iþlemleri
		this-> para=atof(head->para);
		//hesaplamlamalar için gerekli çiverme iþlemleri
		this-> oran=atof(head->oran);
	//hesaplamlamalar için gerekli çiverme iþlemleri
		this-> sayi=atoi(head->sayi);
		
		
		
		//parasý 1000 tl altýnda olanlarý kontrol iþlemi
		
		if(this->para<=1000){
			head = head->next;
				continue;
			}
			//kullanýcýlarýn kazandýðý durumu hesaplayan bölüm masa kaybeder	
			else if(this->sayi==this->sayitur){
				//para bakiye iþlemleri bir if döngüsü ile halledilmiþtir
			this->yatirilanpara=this->para*this->oran;			
				this->yenipara=this->para-this->yatirilanpara;
				this->yeniyatirilanpara=this->yatirilanpara*10;
				this->para=this->yeniyatirilanpara+this->yenipara;
				this->yenimasabakiye=this->masabakiye-this->yatirilanpara*9;
			
			}
			//kullanýcýlarýn kaybettiði durumu hesaplayan bölüm masa kazanýr
			else if(this->sayi!=this->sayitur){
				//para bakiye iþlemleri bir if döngüsü ile halledilmiþtir
				this->yatirilanpara=this->para*this->oran;
				this->yenipara=this->para-this->yatirilanpara;
				this->para=this->yenipara;
				this->yenimasabakiye=this->masabakiye+this->yatirilanpara;
			}
			 	
  			//double char*  çevirme alaný
			sprintf(head->para, "%f",  this->para);
	  	this->masabakiye=this->yenimasabakiye;
	  		//zengin kiþi hesaplayan koþul
			if(zenginkisipara<=atof(head->para)){
				//Zengin kiþi ve bu zengin kiþinin adýný bulmak için oluþturulan if koþulunun içerisi
				zenginkisipara=atof(head->para);
				this->zenginkisi=head->node_str;
				
			}	
		
		
head = head->next;

	}
	// gerekli olan tur sayýsný çýkaran bölüm
	this->turdondur++;
	//gerekli olan þekli yazdýran bölüm
	//konumlara gotozy baðlý olarak oluþturulu ve istenen yerlere yazdýrýlýr
	gotoxy(58,11);
    	printf("SANSLI SAYI: %d  ",this->sayitur);
	gotoxy(58,15);
  		printf("TUR SAYISI : %d",this->turdondur);
		gotoxy(58,16);
  	    printf("MASA BAKIYE: %.2lf ",this->masabakiye);
  	  gotoxy(85,16);
  	    printf("Tl ");
		gotoxy(54,19);
    	printf("EN ZENGIN KISI:");
    	gotoxy(54,20);
		printf("%s        ",this->zenginkisi);
	gotoxy(49,21);
		printf("BAKIYESI: %.2lf ", zenginkisipara);
		gotoxy(50,30);
		Sleep(95);
           //printf("%.2f\n",masabakiye );
      }
      //sistem sýfýrlma
      system("CLS");
      //konumlara gotozy baðlý olarak oluþturulu ve istenen yerlere yazdýrýlýr
    print_sekilciz2(dosya,10,50);
    gotoxy(55,12);
  	    printf("MASA BAKIYE: %.2lf ",this->masabakiye);
  	 gotoxy(58,11);
  		printf("TUR SAYISI : %d",this->turdondur);
  	  gotoxy(60,15);
  	    printf("OYUN BITTI ");
  	  gotoxy(50,30);
      //dosya kapatma iþlemi
	  fclose(fp);
   free_list(head);

}
//yýkýcý fonsiyon kod içerisinde oluþan yani heap ta oyun için ayrýlan yeri temizler
void delete_Oyun(const Oyun this) {
	if(this==NULL) return;
	free(this);
}
