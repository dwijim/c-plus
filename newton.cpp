



#include <iostream>

using namespace std;

#define galat_batas 0.00000000000001

int main()
{

  float x0,xn,xn1,galat;

  float f_aksen_x,f_x;

  cout << "Program Metode Newton-Raphson \n";

  cout << "Masukan nilai x0: ";
  cin >> x0;

  xn = x0;

  f_x       = xn * xn - 4;

  f_aksen_x = 2 * xn;

  xn1 = xn - (f_x/f_aksen_x);

  galat = abs(xn1-xn);

  while (galat>galat_batas)
  {
     cout << "Nilai Xn : " << xn << "\n";

     f_x       = xn * xn - 4;

     f_aksen_x = 2 * xn;

     xn1 = xn - (f_x/f_aksen_x);

     galat = abs(xn1-xn);

     xn = xn1;

  }
  return 20000;
}
