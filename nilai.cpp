
#include "iostream"

#define jumlah_data 10

using namespace std;

int main()
{
  float nilai[jumlah_data];
  short int data_ke;

  nilai[0] = 7.5;
  nilai[1] = 3.1;
  nilai[2] = 5.0;
  nilai[3] = 4.6;
  nilai[4] = 9.1;
  nilai[5] = 7.8;
  nilai[6] = 8.3;
  nilai[7] = 2.8;
  nilai[8] = 1.3;
  nilai[9] = 4.7;

  for (data_ke=0;data_ke<jumlah_data;data_ke++)
      {
         cout << "Nilai ke-"<<data_ke+1<<" = " << nilai[data_ke] ;
	 if (nilai[data_ke]<6.0)
		 cout << " tidak lulus" << endl;
	 else
                 cout << " lulus " << endl;		 
      }

  return 1;
}

