#include "Oyun.h"
/**
*
* @author Yusuf Cihan Gedik cihan.gedik@ogr.sakarya.edu.tr
* @since 06.05.2022
* <p>
* 2/A
* </p>
*/
int main(){
	//main k�sm� bu k�s�mda ana oyun �al��ma yeri
	//olu�turulan yap�lardan de�ikneler olu�turarak yazd�rma i�leminin eksiksizz ger�ekle�ti�i alan
node*head;
Dosya dosya;
Oyun oyun = Oyunolustur();
oyun->anaoyun(oyun);
//y�k�c� fonksiyonlar ile beraber heapta kaplanan alanlar�n temizlendi�i k�s�m
	free(oyun);
	free(dosya);
	free_list(head);
	return 0;	

}
