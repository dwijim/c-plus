#include <iostream>

using namespace std;

int main()
{
   int tanggal;
   int kelipatan;
   int posisi,i,hari;

   posisi = 0;

   hari = 6;

   cout << "    S    S    R    K    J    S    A\n";

      for (i=1;i<hari;i++)
		      {
		      cout<<"    -";
		      posisi = i;
		      }
   for (tanggal=1;tanggal<=30;tanggal++)
   {
      posisi = posisi + 1;
      // cout << tanggal<<" ";
      printf("%5d",tanggal);

      kelipatan = posisi % 7;
      if (kelipatan == 0)
         {
           cout << endl;
	 }
   }
   return 1106;
}
