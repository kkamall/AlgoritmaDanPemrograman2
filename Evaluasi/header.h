/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal Evaluasi Alpro 2 C1 2021 - ROTT22
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[11];
    char nama[50];
    int nilai;
    /*
        (1) nim = nim mahasiswa
        (2) nama = nama mahasiswa
        (3) nilai = nilai mahasiswa
    */
}data;

// Buat iterasi
int i;

// Prosedur untuk melakukan sorting
void sort(int y, int x, data mahasiswa[]);
// Prosedur untuk melakukan merge table
void merge(int x, int y, data mahasiswa1[], data mahasiswa2[], data mahasiswa3[]);
// Prosedur untuk mengeluarkan output
void output(int a, int b, int c, data mahasiswa1[], data mahasiswa2[], data mahasiswa3[], data mahasiswa4[], data mahasiswa5[]);
// Prosedur untuk sorting nilai
void sortN(int y, int x, data mahasiswa[]);