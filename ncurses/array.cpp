#define jumlah_data 5

// karena ada proses cetak ke layar dan
// pemasukan data via keyboard
#include <iostream>


using namespace std;

int main()
{
  float nilai_akhir[jumlah_data];
  
  int data_ke;
  
  for (data_ke=0;data_ke<jumlah_data;data_ke++)
   {
     cout << "Masukkan data ke-"<<data_ke+1;
   }

  return 1;
}
