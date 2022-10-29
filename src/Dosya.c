#include "Dosya.h"
//oluþturulan kurucu fonksýyon
//bo kurucu fonk sayesinde biz nesne yonlelimli programlamalarin içerdiði özellikleri bir nevi kazandýrýrýz
Dosya Dosyaolustur(){
	Dosya this;
	this = (Dosya)malloc(sizeof(Dosya));
	this->rows;
	this->columns;
	this->i;
	this->j;
	this->print_sekilciz=&print_sekilciz;
	this->print_sekilciz2=&print_sekilciz2;
	this->delete= &delete_Dosya;
	return this;
}
//kod içerisinde konumsal alanlerýn ayarlandýðý lan
void gotoxy (int x, int y){
	COORD CRD;
	CRD.X=x;
	CRD.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD );
	
}
//þekil çizdirme fonksiyonu
void print_sekilciz(const Dosya this,int rows1,int columns1){	
    	 
      this->rows=rows1;
	   this->columns=columns1;
    //satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	 int i,j;
    for(i = 0; i <this->rows; i++)
    {
        for(j = 0; j < this->columns; j++)
	{
		//satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	  if(i == 0 ||i == this->rows-1|| j == this->columns-2 ||j == this->columns-1)
	  {
	  	
	  	gotoxy(40+j,10+i);
		printf("#");
		
		
	  }
	  //satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	   else if(i == 3 || i == this->rows-1 ||j == 1 || j == this->columns-1)
	  {
	  	
	  	gotoxy(40+j,10+i);
		printf("#");
		
	  }
	  //satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	  else if(i == 4 || i == this->rows-1 ||j == 0 || j == this->columns-1)
	  {
	  	 
	  	gotoxy(40+j,10+i);
		printf("#");
		
	  }
	  //satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	  else if(i == 8 || i ==this->rows-1 || j == 0 ||j == this->columns-1)
	  {
		printf("-");
		
	  }
	  
	  else
	  {
	  	
		printf(" ");
	  }          
        }
        
        gotoxy(40+j,20+i);
        printf("\n");
    
    }
	}
	
	
	//satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	void print_sekilciz2(const Dosya this,int rows1,int columns1){	
    	 
     this->rows=rows1;
	 this->columns=columns1;
    int i,j;
	 //satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
    for(i = 0; i <this->rows; i++)
    {
        for(j = 0; j < this->columns;j++)
	{
		//satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	  if(i == 0 || i == this->rows-1|| j == this->columns-2 || j == this->columns-1)
	  {
	  	
	  	gotoxy(40+j,10+i);
		printf("#");
		
		
	  }
	  //satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	   else if(i == 0 || i == this->rows-1 || j == 1 || j == this->columns-1)
	  {
	  	//satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	  	gotoxy(40+j,10+i);
		printf("#");
		
	  }
	  else if(i == 0 || i == this->rows-1 || j == 0 || j == this->columns-1)
	  {
	  	//satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
	  	gotoxy(40+j,10+i);
		printf("#");
		
	  }
	  else if(i == 4 ||  i == this->rows-1 || j == 0 || j == this->columns-1)
	  {
	  	//satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
		printf("-");
		
	  }
	  
	  else
	  {
	  	//satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
		printf(" ");
	  }          
        }
        //satir ve sütunlara baðlý olarak þekil çizdirme koþullarý
        gotoxy(40+j,20+i);
        printf("\n");
    
    }
 	
	}
	//Dosya iþlemleri için hepata kapladýklarý alanlar için oluþtururlan yýkýcý fonsiyon
	void delete_Dosya(const Dosya this) {
	if(this==NULL) return;
	free(this);
}

