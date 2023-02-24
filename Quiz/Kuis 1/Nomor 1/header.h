/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal Kuis 1 Alpro 2 C1 2021 - MATDMAT2
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>

int i, j, k;
/*
    (1) i, j, k = variabel untuk jadi indeks looping
*/

typedef struct
{
    int mat1[100][100][2];
    int mat2[100][100][2];
    /*
        (1) mat1 = buat nyimpen nilai matriks pertama
        (2) mat2 = buat nyimpen nilai matriks kedua
    */
}matriks;

// Fungsi untuk mengecek matriks mana yang lebih besar
int cek(int a, int b, int c, int d, int *e, int *f, int *g, int *h);
// Prosedur untuk mengeluarkan output
void hasil(int e, int f, int g, int h, int x1, int x2, matriks nilai, int tanda);
