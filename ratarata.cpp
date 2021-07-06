#include "iostream"


using namespace std;



int main()
{
   // deklarasi variabel
   int masih_ada,bilangan;
   float sum_bilangan;
   float n;
   
   float rata_rata;


   // menampilkan judul
   cout << "Program menghitung rata-rata\n";

   // memberi harga awal kondisi looping while
   masih_ada = 1;

   // memberi harga awal accumulator
   sum_bilangan = 0;

   // memberi harga awal counter
   n = 0;

   while (masih_ada==1)
   {

       // memasukan data
       cout << "Masukan bilangan:";
       cin >> bilangan;

       // menghitung jumlah nilai bilangan
       sum_bilangan = sum_bilangan+bilangan;

       // menghitung banyaknya bilangan
       n = n+1;

       cout << "Apakah data masih ada [1/0]?";
       cin >> masih_ada;
   }

   // menghitung nilai rata-rata
   rata_rata = sum_bilangan/n;

   cout << "Rata-rata: "<<rata_rata<<endl;
   printf("%f",rata_rata);
    // karena void main() maka hasilnya
    // maka tidak perlu ada return ...
    return  1;
}