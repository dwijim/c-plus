/* --------------------------------------------------------
   program untuk mencari bilangan terbesar 
   untuk pengembangan, misalnya mencari bilangan terkecil
   carilah ide sendiri ...
   
   dibuat pada hari Selasa, 25 September 2019
   berkas ini harus diberi nama bilanganterbesar.java
   
   -------------------------------------------------------- */

// kelas untuk pemasukan data   
import java.util.Scanner;

public class bilanganterbesar {

       /**
        * @param args
          di dalam fungsi main
        */
       public static void main(String[] args) {
              // TODO Auto-generated method stub
             
              // mendeklarasikan bilangan untuk data masukan
              int bilangan;
              
              // mendeklarasikan bilangan untuk menyimpan nilai
              // bilangan terbesar dan diberi nilai awal sekecil-kecilnya
              int bilangan_terbesar;
              bilangan_terbesar = 0;
             
              // mendeklarasikan untuk pertanyaan apakah masih ada data
              String DataMasihAda;
              
              // mendeklarasikan variabel untuk kondisi looping
              boolean terus = true;
              
       do {   
              // pemasukan data
              Scanner input_bilangan = new Scanner (System.in);
              System.out.print("Masukan bilangannya : ");
              bilangan = input_bilangan.nextInt();
              
              /* --------------------------------------------------
                 membandingkan nilai bilangan terbesar dengan
                 nilai yang baru saja dimasukkan
                 jika nilai bilangan yang baru dimasukkan 
                 lebih besar dari nilai bilangan terbesar maka
                 nilai bilangan terbesar diisi dengan nilai
                 bilangan yang baru saja dimasukkan
                 -------------------------------------------------- */
              if (bilangan>bilangan_terbesar) 
                  bilangan_terbesar = bilangan;   
                 
              Scanner input_string = new Scanner (System.in);
              System.out.print("Apakah data masih ada [ya/tidak]? ");
              DataMasihAda = input_string.nextLine();
              // System.out.print(DataMasihAda);'
              
           } while (DataMasihAda.equalsIgnoreCase("ya"));

            // menampilkan hasil bilangan terbesar
            System.out.println("Bilangan terbesar : " + bilangan_terbesar);
            
          } // akhir fungsi main

} // akhir class utama
