/* ---------------------------------------
 * program untuk mencetak suatu tulisan
 * sebanyak n kali
 * dwi sakethi, 21 september 2026
 * nama file : ilkom.cpp
 * compile : g++ ilkom.cpp -o ulang
 * --------------------------------------- */

#include "iostream"
// karena ada perintah cin dan cout

using namespace std;
// untuk mempermudah penulisan perintah


// program dalam bahasa c++ minimal terdiri dari
// satu fungsi yaitu fungsi main()
int main()
{
   //deklarasi variabel yang digunakan
   short int baris, tulisan_ke;

   //deklarasi variabel tipe string
   string tulisan;

   // menanyakan tulisan yang akan dicetak
   // karena string jadi menggunakan getline
   cout << "Tulisan yang akan dicetak : ";
   getline(cin, tulisan);

   // menanyakan akan dicetak berapa kali
   cout << "Berapa baris : ";
   cin >> baris;

   // looping dengan for karena sudah jelas jumlah looping-nya
   for (tulisan_ke=1;tulisan_ke<=baris;tulisan_ke++)
   {
      cout << tulisan << "\n";
      // mencetak tulisan
   }

   return 37;
   // akhir program menghasilan bilang int
}
