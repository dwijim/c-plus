/* -------------------------------------------------------------
   contoh ini telah di-compile pada sistem operasi Linux 
   dengan compiler gcc. nama file buble.c
   perintah compile : gcc buble.c -o buble -lm        
   jika tidak ada kesalahan, program dapat dijalankan dengan 
   memberikan perintah:

   ./buble

   #dwi sakethi 26 agustus 2018         
   ------------------------------------------------------------- */

// menyertakan library untuk mencetak data ke layar
#include <stdio.h>

// misalkan banyaknya data maksimal yang akan diolah ada 100 data
#define jumlah_data_maksimum 100

int main()
{
   int banyak_data;
   int data[jumlah_data_maksimum];
   int data_ke,data_setelah,bilangan_sementara;
   
   // menghapus layar
   // system("clear");

   // menanyakan banyaknya data
   printf("Banyaknya data: ");
   scanf("%d",&banyak_data);

   // looping pemasukan data
   for (data_ke=0;data_ke<banyak_data;data_ke++)
       {
        // memasukkan data ke-?
        printf("Masukkan data ke-%d : ",data_ke+1);
        scanf("%d",&data[data_ke]);

       }
   
/* pengurutan data dengan metode buble sort */

/* -------------------------------------------------
   pembandingan dilakukan dari data pertama 
   sampai dengan data terakhir-1 
   karena perbandingan terakhir adalah perbandingan
   antara data terakhir-1 dengan data terakhir
   0-1 0-2 0-3 0-4 
       1-2 1-3 1-4
           2-3 2-4
               3-4
   terlihat bahwa nilai yang sebelah kiri, 
   nilai terbesarnya adalah 3 (untuk contoh 5 data)
   sehingga batas loopingnya banyak_data-2 
   karena array dimulai dari angka 0,
   maka akhir looping harus dikurangi lagi
   ------------------------------------------------- */

/* -------------------------------------------------
   langkah pertama adalah membuat looping dengan 
   hasil angka seperti berikut: 
   0-1 0-2 0-3 0-4 
       1-2 1-3 1-4
           2-3 2-4
               3-4
   ------------------------------------------------- */

  for (data_ke=0;data_ke<=banyak_data-2;data_ke++)
   for (data_setelah=data_ke+1;
        data_setelah<=banyak_data-1;data_setelah++)

/* mengurutkan data dari kecil ke besar */
   if (data[data_setelah]<data[data_ke])

/* ditukar tempatnya, misal data[0] = 11 dan data[1]=6
   maka ditukar sehingga menjadi data[0]=6 data[1]=11  */
      {
         bilangan_sementara = data[data_ke];
         data[data_ke]      = data[data_setelah];
         data[data_setelah] = bilangan_sementara;
      }

/* cetak data hasil sorting */
   printf("Data hasil sorting dengan Bubble Short: \n");   
   for (data_ke=0;data_ke<=banyak_data-1;data_ke++)
       printf(" %2d  :  %2d \n",data_ke+1,data[data_ke]);

  // karena int main, maka harus ada return
  return 0;   
}
