/*
nama file : pacman-posisi-awal-fleksibel.cpp

Labirin Pac-Man polos menggunakan karakter garis tabel (box drawing) dan ncurses
Kompilasi : g++ -std=c++17 -Wall -O2 pacman-posisi-awal-fleksibel.cpp -o coba -lncursesw
Jalankan  : ./coba       (tekan tombol ESC untuk keluar)
Catatan   : butuh terminal UTF-8 dan library ncursesw (libncursesw5-dev / ncurses-devel)

dimodifikasi oleh dwi sakethi

*/
#include <ncurses.h>

#include <clocale>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// '#' = dinding, ' ' = jalan, '-' = pintu rumah hantu
// Ubah isi array ini untuk membuat labirin sendiri (semua baris harus sama panjang).
static const vector<string> LABIRIN = {
    "###################",
    "#        #        #",
    "# ## ### # ### ## #",
    "#                 #",
    "# ## # ##### # ## #",
    "#    #   #   #    #",
    "#### ### # ### ####",
    "#### #       # ####",
    "#### # ##-## # ####",
    "     # #   # #     ",
    "#### # ##### # ####",
    "#### #       # ####",
    "#### ### # ### ####",
    "#    #   #   #    #",
    "# ## # ##### # ## #",
    "#                 #",
    "# ## ### # ### ## #",
    "#        #        #",
    "###################",
};

static const int TINGGI = LABIRIN.size();
static const int LEBAR = LABIRIN[0].size();

static const int PASANGAN_DINDING = 1;
static const int PASANGAN_PINTU = 2;

static bool adalahDinding(int baris, int kolom) {
    if (baris < 0 || baris >= TINGGI || kolom < 0 || kolom >= LEBAR) return false;
    return LABIRIN[baris][kolom] == '#' || LABIRIN[baris][kolom] == '-';
}

// Di luar papan dianggap "terbuka" agar bingkai terluar tetap tergambar penuh
static bool adalahTerbuka(int baris, int kolom) {
    if (baris < 0 || baris >= TINGGI || kolom < 0 || kolom >= LEBAR) return true;
    return !adalahDinding(baris, kolom);
}

// Dua sel dinding bertetangga disambung garis jika berada di tepi (outline) blok dinding,
// yaitu bila salah satu sel di sisi sampingnya terbuka. Bagian dalam blok tebal dikosongkan.
// (db, dk) = selisih baris dan kolom menuju sel tetangga.
static bool tersambung(int baris, int kolom, int db, int dk) {
    int barisTetangga = baris + db, kolomTetangga = kolom + dk;
    if (!adalahDinding(barisTetangga, kolomTetangga)) return false;
    if (db == 0)
        return adalahTerbuka(baris - 1, kolom) || adalahTerbuka(baris - 1, kolomTetangga) ||
               adalahTerbuka(baris + 1, kolom) || adalahTerbuka(baris + 1, kolomTetangga);
    return adalahTerbuka(baris, kolom - 1) || adalahTerbuka(barisTetangga, kolom - 1) ||
           adalahTerbuka(baris, kolom + 1) || adalahTerbuka(barisTetangga, kolom + 1);
}

// Indeks = bit: 1 = atas, 2 = kanan, 4 = bawah, 8 = kiri
static const char *KARAKTER_GARIS[16] = {
    " ", "║", "═", "╚", "║", "║", "╔", "╠",
    "═", "╝", "═", "╩", "╗", "╣", "╦", "╬",
};

#define KEY_ESC 27

#define wajah "😀"
//#define wajah "@"

int main() {

    short int barisAwal, kolomAwal;
    int tombol,i,jumlah_karakter;
    short int baris, kolom,barisArray, kolomArray;
    bool boleh[200] [200];

    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    // supaya dapat dideteksi penekanan tombol khusus seperti
    // F1 .. F10, panah kanan, panah kiri dst ...
    keypad(stdscr,TRUE);

    int jumlahBaris, jumlahKolom;
    getmaxyx(stdscr, jumlahBaris, jumlahKolom);



    if (jumlahBaris < TINGGI + 2 || jumlahKolom < LEBAR * 2 + 2) {
        endwin();
        printf("Terminal terlalu kecil. Minimal %d kolom x %d baris.\n", LEBAR * 2 + 2,
               TINGGI + 2);
        return 1;
    }

    bool berwarna = has_colors();
    if (berwarna) {
        start_color();
        init_pair(PASANGAN_DINDING, COLOR_BLUE, COLOR_BLACK);
        init_pair(PASANGAN_PINTU, COLOR_MAGENTA, COLOR_BLACK);
    }

    int batasAtas = (jumlahBaris - TINGGI) / 2;
    int batasKiri = (jumlahKolom - LEBAR * 2) / 2;

    for (int baris = 0; baris < TINGGI; baris++) {
        for (int kolom = 0; kolom < LEBAR; kolom++) {
            char sel = LABIRIN[baris][kolom];

            // tempat menyisipkan true false tujuan
            if (sel != '#' && sel != '-')
               {
                  boleh[baris] [kolom] = true;
               }
            else
            {
                boleh[baris] [kolom] = false;
            };


            if (sel != '#' && sel != '-') continue;

            int warna = (sel == '-') ? PASANGAN_PINTU : PASANGAN_DINDING;
            int layarBaris = batasAtas + baris;
            int layarKolom = batasKiri + kolom * 2;

            if (berwarna) attron(COLOR_PAIR(warna) | A_BOLD);
            if (sel == '-') {
                mvaddstr(layarBaris, layarKolom, "──");
            } else {
                int topeng = (tersambung(baris, kolom, -1, 0) ? 1 : 0) |
                             (tersambung(baris, kolom, 0, 1) ? 2 : 0) |
                             (tersambung(baris, kolom, 1, 0) ? 4 : 0) |
                             (tersambung(baris, kolom, 0, -1) ? 8 : 0);
                mvaddstr(layarBaris, layarKolom, KARAKTER_GARIS[topeng]);
                // Kolom kedua sel: lanjutkan garis horizontal ke kanan jika tersambung
                if (topeng & 2) mvaddstr(layarBaris, layarKolom + 1, "═");
            }
            if (berwarna) attroff(COLOR_PAIR(warna) | A_BOLD);
        }
    }

    /*
     * posisi yang pas
     Jumlah baris :  35
     Jumlah kolom : 124
     Tinggi lab   :  19
     Lebar lab    :  19
     Baris awal   :  17
     Kolom awal   :  59
     *
     * */
    barisAwal = 17;
    kolomAwal = 59;
    mvprintw(20,5,"%s %d", "Jumlah baris : ",jumlahBaris);
    mvprintw(21,5,"%s %d", "Jumlah kolom : ",jumlahKolom);
    mvprintw(22,5,"%s %d", "Tinggi lab   : ",TINGGI);
    mvprintw(23,5,"%s %d", "Lebar lab    : ",LEBAR);
    mvprintw(24,5,"%s %d", "Baris awal   : ",barisAwal);
    mvprintw(25,5,"%s %d", "Kolom awal   : ",kolomAwal);
    baris = barisAwal;
    kolom = kolomAwal;

    barisArray = 0;
    kolomArray = 0;

    mvprintw(barisAwal,kolomAwal,wajah);

    // membuat looping selama tidak menekan tombol ESC
    while (tombol != KEY_ESC)
    {

        mvprintw(26,5,"%s %d", "Baris        : ",baris);
        mvprintw(27,5,"%s %d", "Kolom        : ",kolom);

        mvprintw(28,5,"%s %d", "Boleh Kiri   : ",boleh[baris][kolom-1]);
        mvprintw(29,5,"%s %d", "Boleh Kanan  : ",boleh[baris][kolom+1]);

        if ((tombol = getch()) == ERR) {
            /* user hasn't responded
             *               ...
             */
        }
        else
            /* user has pressed a key ch
             *               ...
             */
            if (tombol == KEY_ENTER)
            {
            }
            else if ( (tombol == KEY_LEFT) and (boleh[baris] [kolom-1])==false  )
            {
                // bergerak ke kiri, jadi kolom berkurang
                kolom = kolom - 1;

                // jika sudah mentok ke kiri, kolom tetap 1
                if (kolom<=1) kolom=1;
                mvprintw (baris,kolom,wajah);
                mvprintw (baris,kolom+1," ");
            }
            else if(tombol == KEY_RIGHT)
            {
                // bergerak ke kiri, jadi kolom berkurang
                kolom = kolom + 1;

                // jika sudah mentok ke kiri, kolom tetap 1
                if (kolom>=75) kolom=75;
                mvprintw (baris,kolom,wajah);
                mvprintw (baris,kolom-1," ");
            }
            else if(tombol == KEY_UP)
            {
                // bergerak ke kiri, jadi kolom berkurang
                baris = baris - 1;

                // jika sudah mentok ke kiri, kolom tetap 1
                if (baris<=1) baris=1;
                mvprintw (baris,kolom,wajah);
                mvprintw (baris+1,kolom," ");
            }
            else if(tombol == KEY_DOWN)
            {
                // bergerak ke kiri, jadi kolom berkurang
                baris = baris + 1;

                // jika sudah mentok ke kiri, kolom tetap 1
                if (baris<=1) baris=1;
                mvprintw (baris,kolom,wajah);
                mvprintw (baris-1,kolom," ");
            }

    }

    //mvprintw(10,30,"😀");

    refresh();
    getch();
    endwin();
    return 0;
}
