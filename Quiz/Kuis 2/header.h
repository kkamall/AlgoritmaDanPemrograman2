/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Kuis 2 Alpro 2 C1 2021 - kngmdk22
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>

// Variabel Global untuk indeks
int i, j, k;

typedef struct
{
    char nama[100];
    int harga;
    char toko[100];
    int kalori;
    /*
        (1) nama = nama makanan
        (2) harga = harga makanan
        (3) toko = toko makanan
        (4) kalori = kalori makanan
    */
} dmakanan;

// Prosedur untuk sorting menggunakan selection sort
void sorting(dmakanan data[], int n, char urut[]);
// Prosedur untuk melakukan search menggunakan binary search
void search(dmakanan data[], int n, int cari, char urut[]);