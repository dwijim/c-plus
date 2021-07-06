/* --------------------------------------------
 * program untuk membuat kalender pada
 * suatu bulan tertentu       
 * nama file     : kalender.cpp 
 * dibuat oleh   : Muhammad Arief Islamy (1857051010)
 * edit terakhir : 19 oktober 2020 
 * -------------------------------------------- */

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#define akhir_bulan 31

int main (void)
  {
   int bulan, // bulan ke berapa 
       hari_ke // sekarang hari ke berapa
       ;
   int tanggal_satu_hari_apa; // tanggal 1 jatuh
                              // pada hari apa ?
   int sekarang_hari_ke;
       // dalam proses sekarang ada pada hari apa
       // atau hari ke berapa ?

   cout<<"kalender bulan [1, 2, 3, ..., 12] ";cin>>bulan;
   
   cout<<"tanggal 1 jatuh pada hari [1, 2, ..., 7] ";cin>>tanggal_satu_hari_apa;

   hari_ke = 1; // posisi hari dimulai hari ke-1

   cout<<"\t M\t S\t S\t R\t K\t J\t S\n";

   // tulis kosong sampai ketemu tanggal satu jatuh
   // pada hari apa
   for(hari_ke=1;hari_ke<=tanggal_satu_hari_apa-1;hari_ke++)
       {
          cout<<"\t -"; 
       }
       // posisi hari nilainya sama dengan hari ke 
       // setelah proses looping selesai
       sekarang_hari_ke = hari_ke;

   // dari posisi tanggal 1 yang jatuh pada hari apa
   // cetak tanggal sampai akhir bulan
   for(hari_ke=1;hari_ke<=akhir_bulan;hari_ke++)
      {
        cout<<"\t "<<hari_ke;
        sekarang_hari_ke++;

        // jika sudah lebih dari hari ke-7 (nilainya 8)
        // maka menulis tanggalnya pindah baris
        if (sekarang_hari_ke==8)
           {
             sekarang_hari_ke = 1;
             cout<<("\n");
           }
       
      }
             cout<<("\n");
  }
