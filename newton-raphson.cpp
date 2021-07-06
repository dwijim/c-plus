/* ---------------------------------------------------
 * program untuk menyelesaikan persamaan matematika
 * dengan menggunakan metode newton
 * 14 november 2018
 * 14 desember 2020
 * dwi sakethi
 * --------------------------------------------------- */

#include <iostream>

using namespace std;


// #include<math.h>
// karena ada fungsi-fungsi khusus matematika
// ini kalau di bahasa C


// program harus memiliki fungsi main()
int main()
{
    // deklarasi variabel
	float x_n,x_n1,f_x,f_xn,galat,f_aksen;
	int iterasi;
	FILE *hasil_txt;
    float  selisih;

    // batas untuk berhenti looping
	galat   = 0.000000000001;
    
    // awal iterasi
	iterasi = 0;
    
    // menentukan titik awal pencarian
    printf("Masukkan nilai x0 :");
    scanf("%f",&x_n);

    // fungsi f(x)
	f_x     = (x_n*x_n) - 4;
    
    // turunan fungsi f(x)
	f_aksen = 2* x_n;
    
	x_n1    = x_n-(f_x/f_aksen);

	hasil_txt = fopen("iterasi.txt","w");

    selisih = x_n1-x_n;
    if (selisih<0.0) selisih=-selisih;

    // looping selama selisih > galat
	while(selisih>=galat)
	{
		iterasi = iterasi+1;
		x_n     = x_n1;
		f_x     = (x_n*x_n)-4;
		f_aksen = 2*x_n;
		x_n1    = x_n-(f_x/f_aksen);

        selisih = x_n1-x_n;
        if (selisih<0.0) selisih=-selisih;

        printf("iterasi %d x=%f f(x)=%f selisih : %f\n",iterasi,x_n,f_x,selisih);

  	    fprintf(hasil_txt,"iterasi %d x=%f f(x)=%f \n",iterasi,x_n,f_x);

	}
	printf("--- \n");

	fclose(hasil_txt);
    
    // akhir fungsi
    return 11;
}

// (x-3)(x+2)=x2 -x -6
