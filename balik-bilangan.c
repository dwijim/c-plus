/* ini program untuk membalik angka
 * yang terdiri dari 3 digit tidak boleh lebih
 * dan tidak boleh kurang 
 * diedit terakhir pada tanggal 1 maret 2010
 * sebelum gajian
 *                                            */

#include <stdio.h>
/* 
    ini file yang disertakan karena ada perintah :
    printf dan scanf
*/

int main()
// program bahasa c minimal terdiri dari satu fungsi
// yaitu fungsi main()

{ 
 int bilangan;
 // bilangan adalah data yang dimasukan dan akan dibalik
 
 int hasil,satuan, puluhan, ratusan;
 // satuan adalah 
 // puluhan adalah
 // ratusan adalah
 printf("Program untuk membalik bilangan 3 digit \n");
 
 printf("Masukkan suatu bilangan : ");
 scanf("%d",&bilangan);
 // memasukan bilangan yang akan dibalik melalui keyboard
 
 satuan   = bilangan % 10;
 puluhan  = ((bilangan-satuan)%100) / 10;
 ratusan  = (bilangan-((puluhan*10)+satuan)) / 100; 
 hasil    = (satuan*100)+(10*puluhan)+ratusan; 
 printf("setelah dibalik menjadi : %d \n",hasil);
 printf(" ");
 
 // karena int main, jadi hasilnya adalah bilangan bulat
 // salah satunya 8
 return 8;
 
}
