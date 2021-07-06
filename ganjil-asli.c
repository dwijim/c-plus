/* -------------------------------------------------------------
   contoh ini telah di-compile pada sistem operasi Linux 
   dengan compiler gcc. nama file jumlah_ganjil.c
   perintah compile : gcc jumlah_ganjil.c -o jumlah_ganjil        
   jika tidak ada kesalahan, program dapat dijalankan dengan 
   memberikan perintah:

   ./jumlah_ganjil

   #dwi sakethi 10 oktober 2018         
   ------------------------------------------------------------- */

// menyertakan library untuk memasukkan data dan mencetak
// data ke layar
#include <stdio.h>

// program bahasa C harus memiliki fungsi main
int main()
{
   int bilangan;
   int sisa_pembagian;
   
   // mencetak judul
   printf("Program Bilangan Ganjil/Genap \n");

   // menanyakan suatu bilangan
   printf("Masukkan suatu bilangan: ");
   scanf("%d",&bilangan);

   // menghitung sisa pembagian
   sisa_pembagian = bilangan % 2;
   
   // mencek apakah sisa pembagian sama dengan 0
   if (sisa_pembagian==0)
      {
	     printf("Bilangan genap \n");
      }
   else   
      {
	     printf("Bilangan ganjil \n");
      }
      
  // karena int main, maka harus ada return
  return 1;   
}
