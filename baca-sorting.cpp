/*----------------------------------------------  
    program untuk membaca file teks
    dibuat oleh dwi sakethi
    file data disimpan dalam berkas teks
    dengan nama data.txt
    tanggal edit program:
     - 21 desember 2020

    program ini telah dikompile menggunakan g++
    pada sistem operasi Debian GNU Linux 10
  ---------------------------------------------- */

#include <iostream>

// untuk membaca data dari file
// atau menulis ke file
#include <fstream>

#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

// program dalam bahasa C++ paling tidak terdiri dari
// satu fungsi yaitu fungsi main()
int main()
{
       // bagian deklarasi variabel
       
       //stream untuk membaca file
       ifstream FileData;

       int bilangan_terbesar;
       int bilangan;
       int nomor,ke,i,j,c;
       int bil_array[10000];

       bilangan_terbesar = 0;
       
       //membuka file yang telah ada
       FileData.open("data.txt");

nomor = 1;
       // jika tidak ada error pada saat akses file
       if ( !FileData.fail() ) 
          {
              cout<<"Isi dari File -> "<< endl;

	      // proses pembacaan isi file ada di sini
              
	      // ulangi selama program belum mencapai 
	      // akhir konten dari file
              while ( FileData >> bilangan ) 
                 {
                    cout << "Data: " << bilangan << endl; 
                      
                      bil_array[nomor] = bilangan;
                      nomor++;

                      if (bilangan>bilangan_terbesar)
                        bilangan_terbesar = bilangan;
					    // mencari bilangan terbesar
                 }

              // tutup kembali file setelah selesai
	      FileData.close(); 
          }
        else
	  {
              cout<<"File data tidak ditemukan"<<endl;
          }
      
       cout << "Bilangan terbesar " << bilangan_terbesar << endl;
	   
      for (ke=1;ke<=nomor;ke++)
      {
        cout << bil_array[ke] << endl;

      }

      for (i=1;i<=nomor-1;i++)
      {
        // cout << bil_array[ke] << endl;
          for (j=i+1;j<=nomor;j++)
          {
            if (bil_array[j]<bil_array[i])
            {
               c = bil_array[i];
               bil_array[i]=bil_array[j];
               bil_array[j]=c;

            }
          }
      for (ke=1;ke<=nomor;ke++)
      {
        cout << bil_array[ke] << endl;

      }
          
      }

	   // akhir program
       return EXIT_SUCCESS;
}
