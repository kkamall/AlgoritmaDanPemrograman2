/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP6 Alpro 2 C1 2021 - MWA21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

// Library
#include <stdio.h>
#include <string.h>

// Tipe data terstruktur
typedef struct
{
    char barang[100];
    int harga;
    float rating;
    /*
        (1) barang = nama barang
        (2) harga = harga barang
        (3) rating = rating barang
    */
}karakter;

// Prosedur untuk sorting insertion
void insertion(int x, karakter kelontong[], char patokan[10]);
// Prosedur untuk sorting selection
void selection(int x, karakter kelontong[], char patokan[10]);
// Prosedur untuk sorting bubble
void bubble(karakter kelontong[], int x, char patokan[10]);
// Prosedur untuk sorting quick
void quick(char patokan[10], karakter kelontong[], int kiri, int kanan);
// Prosedur untuk merge array
void merge(int x, int y, char patokan[10], karakter kelontong1[], karakter kelontong2[], karakter kelontong3[]);
// Prosedur untuk memberikan output
void output(int budget, char patokan[10], char metode, int a, int b, int c, karakter toko1[a], karakter toko2[b], karakter toko3[c], karakter toko4[a+b], karakter toko5[a+b+c]);