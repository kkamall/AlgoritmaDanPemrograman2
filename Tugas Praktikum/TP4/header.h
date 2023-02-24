/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP4 Alpro 2 C1 2021 - SFN21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>

int i, j, k;
/*
    (1) i, j = digunakan dalam for loop
    (2) k = dijadikan sebagai minimum indeks dalam selection sort
*/

typedef struct
{
    char judul[100];
    char genre[100];
    float rating;
    /*
        (1) judul = berisi judul film
        (2) genre = berisi genre film
        (3) rating = berisi rating film
    */
}jenis;

// Prosedur untuk melakukan sorting sekaligus mengeluarkan output
void output(char metode[9], int n, jenis film[n], char patokan[6], char tipe[4]);