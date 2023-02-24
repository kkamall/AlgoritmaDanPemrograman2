/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP2 Alpro 2 C1 2021 - MBPG
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>

int i, j, k;
/*
    (1) i, j, k = buat di fungsi for loop
*/

typedef struct
{
    char tim[100];
    int kekuatan[2];
    char tukar1[100];
    char tukar2[100];
}basket;
/*
    (1) tim = untuk menyimpan nama tim
    (2) kekuatan = untuk menyimpan attack dan defense tim
    (3) tukar1, tukar2 = untuk menyimpan nama tim yang ingin di tukar
*/

// Prosedur untuk mengeluarkan keluaran sebelum ditukar
void awal(int baris, int kolom, basket team[baris][kolom], int panjang[kolom]);
// Fungsi untuk memberikan tanda apakan bisa diswap atau tidak timnya
int swap(int baris, int kolom, basket team[baris][kolom], basket menukar[1000], int x);
// Prosedur untuk menukar tim dan memberikan output setelah ditukar
void akhir(int baris, int kolom, basket (*team)[baris][kolom], basket menukar[1000], int x, int panjang[kolom]);