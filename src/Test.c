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
	//main kýsmý bu kýsýmda ana oyun çalýþma yeri
	//oluþturulan yapýlardan deðikneler oluþturarak yazdýrma iþleminin eksiksizz gerçekleþtiði alan
node*head;
Dosya dosya;
Oyun oyun = Oyunolustur();
oyun->anaoyun(oyun);
//yýkýcý fonksiyonlar ile beraber heapta kaplanan alanlarýn temizlendiði kýsým
	free(oyun);
	free(dosya);
	free_list(head);
	return 0;	

}
