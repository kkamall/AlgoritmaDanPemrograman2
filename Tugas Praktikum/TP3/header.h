/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP3 Alpro 2 C1 2021 - VBB121
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>

int i, j, k;
/*
    (1) i, j, k = buat di looping
*/

typedef struct
{
    int nilai[100], x;
    /*
        (1) nilai = array buat nilai tiap jamnya
        (2) x = jam yang nilainya ingin dicari
    */
}virus;

// Prosedur untuk cari nilai di jam ke-x
int cek(int k1, int k2, int k3, virus v[]);