#include "Oyun.h"
//nesne y�nelimliye benzzetmek i�in a��a��da gereken tan�mlar
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
	//i�aret eden fonk ile fonkun e�le�mesi
	this->anaoyun= &anaoyun;
	//i�aret eden fonk ile fonkun e�le�mesi
	this->delete= &delete_Oyun;
	return this;
}
void anaoyun (const Oyun this){
	//ana oyun i�erisinde dosya i�lemleri i�i yaz�lan durum
		Dosya dosya=Dosyaolustur();
		
	
	//Dosya dosya= Dosyaolustur(dosya);
	//�ekil �izdirme alan�
	print_sekilciz(dosya,13,50);
	//testgetfile ba�latma alan�
	node* head =testGetFile();
	//linked listi yazd�rna alan�
	display_list(head);
	
 	node* a;
 	a=head;
	
	 // open file
    FILE *fp = fopen("Sayilar.txt", "r");
    size_t len = 255;
    
    
    
   
    char *line = malloc(sizeof(char) * len);
   //dosya a��l�p a��lmama durumunu kontrol eden ko�ul yap�s�
    if (fp == NULL) {
        printf("can open file input1.txt!");
        return;
    }
    //dosya i�lemleri i�in gerekli while d�ng�s�
    while(fgets(line, len, fp) != NULL) {
       //sayitura line �evirerek atama i�lemi
      this->sayitur=atoi(line);
      
      
    
	int decimal, sign; 
	//en son olan zengin ki�iyi bulmak i�in tan�mlama
	double zenginkisipara=0;
	
	
		/*zenginkisipara=atof(head->para);
		zenginkisi=head->node_str;*/
	head=a;
	//sistemin d�nd��� alan
	 while (head) {
		//printf("%s\t %s\t %s\t %s \n", head->node_str,head->para,head->oran,head->sayi);
		//hesaplamlamalar i�in gerekli �iverme i�lemleri
		this->isim=head->node_str;
		//hesaplamlamalar i�in gerekli �iverme i�lemleri
		this-> para=atof(head->para);
		//hesaplamlamalar i�in gerekli �iverme i�lemleri
		this-> oran=atof(head->oran);
	//hesaplamlamalar i�in gerekli �iverme i�lemleri
		this-> sayi=atoi(head->sayi);
		
		
		
		//paras� 1000 tl alt�nda olanlar� kontrol i�lemi
		
		if(this->para<=1000){
			head = head->next;
				continue;
			}
			//kullan�c�lar�n kazand��� durumu hesaplayan b�l�m masa kaybeder	
			else if(this->sayi==this->sayitur){
				//para bakiye i�lemleri bir if d�ng�s� ile halledilmi�tir
			this->yatirilanpara=this->para*this->oran;			
				this->yenipara=this->para-this->yatirilanpara;
				this->yeniyatirilanpara=this->yatirilanpara*10;
				this->para=this->yeniyatirilanpara+this->yenipara;
				this->yenimasabakiye=this->masabakiye-this->yatirilanpara*9;
			
			}
			//kullan�c�lar�n kaybetti�i durumu hesaplayan b�l�m masa kazan�r
			else if(this->sayi!=this->sayitur){
				//para bakiye i�lemleri bir if d�ng�s� ile halledilmi�tir
				this->yatirilanpara=this->para*this->oran;
				this->yenipara=this->para-this->yatirilanpara;
				this->para=this->yenipara;
				this->yenimasabakiye=this->masabakiye+this->yatirilanpara;
			}
			 	
  			//double char*  �evirme alan�
			sprintf(head->para, "%f",  this->para);
	  	this->masabakiye=this->yenimasabakiye;
	  		//zengin ki�i hesaplayan ko�ul
			if(zenginkisipara<=atof(head->para)){
				//Zengin ki�i ve bu zengin ki�inin ad�n� bulmak i�in olu�turulan if ko�ulunun i�erisi
				zenginkisipara=atof(head->para);
				this->zenginkisi=head->node_str;
				
			}	
		
		
head = head->next;

	}
	// gerekli olan tur say�sn� ��karan b�l�m
	this->turdondur++;
	//gerekli olan �ekli yazd�ran b�l�m
	//konumlara gotozy ba�l� olarak olu�turulu ve istenen yerlere yazd�r�l�r
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
      //sistem s�f�rlma
      system("CLS");
      //konumlara gotozy ba�l� olarak olu�turulu ve istenen yerlere yazd�r�l�r
    print_sekilciz2(dosya,10,50);
    gotoxy(55,12);
  	    printf("MASA BAKIYE: %.2lf ",this->masabakiye);
  	 gotoxy(58,11);
  		printf("TUR SAYISI : %d",this->turdondur);
  	  gotoxy(60,15);
  	    printf("OYUN BITTI ");
  	  gotoxy(50,30);
      //dosya kapatma i�lemi
	  fclose(fp);
   free_list(head);

}
//y�k�c� fonsiyon kod i�erisinde olu�an yani heap ta oyun i�in ayr�lan yeri temizler
void delete_Oyun(const Oyun this) {
	if(this==NULL) return;
	free(this);
}
