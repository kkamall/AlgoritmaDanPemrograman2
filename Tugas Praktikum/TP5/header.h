/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP5 Alpro 2 C1 2021 - SFNL21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

// Library :
#include <stdio.h>
#include <string.h>

// Variabel global buat index
int i, j, k;

// Typedef struct buat film
typedef struct
{
    char judul[100];
    int jam, menit, totmenit;
    /*
        (1) judul = buat judul film
        (2) jam = buat durasi jam film
        (3) menit = buat durasi menit film
        (4) totmenit = buat total menit per judul dan total menit keseluruhan judul
    */
}x;

// Variabel buat tuker nilai typedef struct secara keseluruhan
x temp;

// Fungsi untuk mengolah durasi film menjadi menit per judul dan secara keseluruhan film
int menambah(int n, x film[n]);
// Prosedur untuk sorting menggunakan quicksort
void quick(int n, int kiri, int kanan, int urutan, x film[n], int metode);
// Prosedur untuk sorting menggunakan bubblesort
void bubble(int n, int urutan, x film[n]);
// Prosedur untuk mengeluarkan output berupa film yang sudah berurut berdasarkan durasi
void output(int n, x film[n], int metode, int urutan);