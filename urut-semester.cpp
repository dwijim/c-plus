/* ---------------------------------------------------
 * program bubble short menggunakan bahasa C++
 * dibuat oleh dwi sakethi
 * 9 desember 2020
 * program ini digunakan untuk mengurutkan data array
 * dari angka kecil ke angka besar
 * proses ngodingnya dapat disimak di youtube
 * 
 * ---------------------------------------------------
 * */
 
// menentukan jumlah data maksimum
#define jumlah_data 7

// karena ada cout, maka perlu ini
#include <iostream>

// ini sebenarnya tidak dianjurkan
using namespace std;

// program bahasa C++ paling tidak terdiri dari
// satu fungsi, yaitu fungsi main()
int main()
{	
// deklarasi variabel yang digunakan di dalam program
int baris,kanan;
int angka_kiri,angka_kanan;
string nilai_sementara;
string nilai[jumlah_data];

// data ditulis di sini, supaya tidak capai memasukkan data
// melalui keyboard
nilai[0] = "01";
nilai[1] = "03";
nilai[2] = "02";
nilai[3] = "10";
nilai[4] = "04";
nilai[5] = "08";
nilai[6] = "06";

/* --------------------------------------------------
 * menampilkan data awal
 * -------------------------------------------------- */

cout << "Sebelum di-sorting " <<endl;

for(baris=0;baris<jumlah_data;baris++)
{
  cout << "Nilai : "<< nilai[baris]<<endl;
}

// proses bubble short dari kecil ke besar
for (baris=1;baris<jumlah_data;baris++)
{
  kanan = jumlah_data+1-baris;
  cout << baris << " - " << kanan << " : ";
  for (angka_kiri=1;angka_kiri<kanan;angka_kiri++)
  {
    angka_kanan = angka_kiri+1;
    cout << angka_kiri << " - " << angka_kanan << "  ";
	
	/* -------------------------------------------------
	   jika data di sebelah kiri lebih besar dari data
	   di sebelah kanan, maka posisinya ditukar
	   ------------------------------------------------- */
    if (nilai[angka_kiri-1]>nilai[angka_kanan-1])
      {
         nilai_sementara      = nilai[angka_kiri-1];
	     nilai[angka_kiri-1]  = nilai[angka_kanan-1];
	     nilai[angka_kanan-1] = nilai_sementara;
      }
  }
  cout << endl;
}

cout << "Setelah di-sorting " <<endl;
for(baris=0;baris<jumlah_data;baris++)
{
  cout << "Nilai : "<< nilai[baris]<<endl;
}

// akhir program
// karena int main(), jadi boleh diisi dengan 1
return 1;
}

