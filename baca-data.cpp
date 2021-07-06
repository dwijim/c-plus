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
       
       bilangan_terbesar = 0;
       
       //membuka file yang telah ada
       FileData.open("data.txt");

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
	   
	   // akhir program
       return EXIT_SUCCESS;
}
