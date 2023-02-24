/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP8 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// Deklrasi buat file:
FILE *a;
FILE *b;
FILE *c;
FILE *d;
FILE *e;

int i, j, k, swap, banyakD[4];
char search[4][10];
/*
    (1) i, j, k = buat iterasi/index/flag
    (2) swap = sebagai flag di bubble sort
    (3) banyakD = banyak data
    (4) search = Kode yang dicari
*/

// Typedef Struct untuk data film
typedef struct
{
    char namaF[100];
    char genreFK1[10];
    char sutradaraFK1[10];
    char bioskopFK1[10];
} dataF;

// Typedef Struct untuk data Genre
typedef struct
{
    char genreFK2[10], genreF[25];
} dataG;

// Typedef Struct untuk data Sutradara
typedef struct
{
    char sutradaraFK2[10], sutradaraF[50];
} dataS;

// Typedef Struct untuk data Bioskop
typedef struct
{
    char bioskopFK2[10], bioskopF[25];
} dataB;

// Void untuk menambah data list film
void sFilm(dataF film[]);
// Void untuk menambah data genre
void sGenre(dataG gnr[]);
// Void untuk menambah data sutradara
void sSutradara(dataS std[]);
// Void untuk menambah data bioskop
void sBioskop(dataB bskp[]);
// Void untuk memberikan output berupa tabel List Film Final sekaligus memasukkan ke file-nya
void final(dataF film[], dataG gnr[], dataS std[], dataB bskp[]);
// Void untuk menghitung banyak data
void itung(dataS std[], dataG gnr[], dataB bskp[]);
// Void untuk searching menggunakan Binary Search
void binSearch(dataS std[], dataG gnr[], dataB bskp[]);