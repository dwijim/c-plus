/* ini program untuk membalik angka
 * yang terdiri dari 3 digit tidak boleh lebih
 * dan tidak boleh kurang 
 * diedit terakhir pada tanggal 1 maret 2010
 * sebelum gajian
 * program ini kemudian dikonversi ke C++
 * oleh M. Fadhil Azhari, 16 Oktober 2020
 *                                            */

// menyertakan library standar input dan output
#include <iostream>

// ini sebenarnya kebiasaan kurang baik
using namespace std;
/* 
    ini file yang disertakan karena ada perintah :
    cout dan cin
*/

int main()
// program bahasa c++ minimal terdiri dari satu fungsi
// yaitu fungsi main()

{ 
 int bilangan;
 // bilangan adalah data yang dimasukan dan akan dibalik
 
 int hasil,satuan, puluhan, ratusan;
 // satuan adalah angka pertama
 // puluhan adalah angka kedua
 // ratusan adalah angka ketiga
 
cout<<"Program Untuk Membalik Bilangan 3 Digit\n";

cout<<"Masukkan Suatu Bilangan : ";
cin >> bilangan;
 // memasukan bilangan yang akan dibalik melalui keyboard

// menghitung nilai satuan 
satuan   = bilangan % 10;

// menghitung nilai puluhsan
puluhan  = ((bilangan-satuan)%100) / 10;

// menghitung nilai ratusan
ratusan  = (bilangan-((puluhan*10)+satuan)) / 100;

// membalikkan angka
hasil    = (satuan*100)+(10*puluhan)+ratusan;

// mencetak hasil
cout<<"Setelah Dibalik Menjadi : "<< hasil;
 
 // karena int main, jadi hasilnya adalah bilangan bulat
 // salah satunya 0
 return 0;
 
}
