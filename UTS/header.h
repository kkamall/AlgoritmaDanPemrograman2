/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal UTS Alpro 2 C1 2021 - migor22
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>

// Tipe data terstruktur untuk data minyak
typedef struct
{
    char merk[100];
    float kalori;
    float lemak;
    float harga;
    int supp;
    double hb;
    /*
        (1) merk = nama merek minyak
        (2) kalori = kalori minyak
        (3) lemak = lemak minyak
        (4) harga = harga minyak
        (5) supp = jenis supplier
        (6) hb = hasil bagi harga dengan kalori dan minyak
    */
}minyak;

// Fungsi untuk menghitung hasil bagi
double pembagian(minyak sup[], int i);
// Prosedur untuk sorting insertion
void insertion(int x, minyak sup[]);
// Prosedur untuk sorting selection
void selection(int x, minyak sup[]);
// Prosedur untuk sorting bubble
void bubble(int x, minyak sup[]);
// Prosedur untuk sorting quick tengah 
void quick(minyak sup[], int kiri, int kanan);
// Prosedur untuk merge array
void merge(minyak sup1[], minyak sup2[], int x, int y, minyak sup3[]);
// Prosedur untuk memberikan output
void output(char metode[3], minyak sup1[], minyak sup2[], minyak sup3[], minyak sup4[], minyak sup5[], int a, int b, int c);