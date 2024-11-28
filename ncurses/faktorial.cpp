#include <ncurses.h>
#include <iostream>

using namespace std;

long int faktorial(short int bilangan)
{
   short int proses;
   long int hasil;
   hasil = 1;
   for (proses=1;proses<=bilangan;proses++) 
       {
         hasil = (hasil*proses);
//         cout << hasil << endl;
       }  
   return hasil;
}

void main()
{ 
  long int kombinasi;
  cout << "Faktorial 3 " << endl;
  cout << faktorial(3)<< endl;;
getch();
  kombinasi = faktorial(7)/(faktorial(3)*(faktorial(7-3)));
  cout << "Kombinasi " << endl;
  cout << kombinasi;
  getch();
  kombinasi = faktorial(10)/(faktorial(5)*(faktorial(10-5)));
  cout << "Kombinasi " << endl;
  cout << kombinasi;
  getch();
//  return 10;  
}