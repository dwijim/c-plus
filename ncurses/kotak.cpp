#include <ncurses.h>

void kotak(short int baris1,short int kolom1,
              short int baris2,short int kolom2)
{
    short int baris,kolom;

  // mencetak karakter pokok kiri atas
  mvaddch(baris1,kolom1,ACS_ULCORNER);
  
  // mencetak garis mendatar
  for (kolom=kolom1+1;kolom<=kolom2-1;kolom++)
      {
        mvaddch(baris1,kolom,ACS_HLINE);
      }
  // mencetak karakter pokok kiri atas
  mvaddch(baris1,kolom2,ACS_URCORNER);

  // mencetak garis vertikal
  for (baris=baris1+1;baris<=baris2-1;baris++)
      {
        mvaddch(baris,kolom2,ACS_VLINE);
      }
  // mencetak karakter pokok kanan bawah
  mvaddch(baris2,kolom2,ACS_LRCORNER);

  // mencetak garis mendata di bagian bawah
  // dari atas ke bawah
  for (kolom=kolom2-1;kolom>=kolom1+1;kolom--)
      {
        mvaddch(baris2,kolom,ACS_HLINE);
      }

  // mencetak karakter pokok kiri bawah
  mvaddch(baris2,kolom1,ACS_LLCORNER);

  // mencetak garis vertikal di sebelah kiri
  for (baris=baris2-1;baris>=baris1+1;baris--)
      {
        mvaddch(baris,kolom1,ACS_VLINE);
      }
  
  // return null;
}

int main()
{

  initscr();

  kotak(1,1,24,79);

  kotak(15,55,20,75);

  kotak(2,15,10,40);

  getch();
  endwin();
  return 116;  
}