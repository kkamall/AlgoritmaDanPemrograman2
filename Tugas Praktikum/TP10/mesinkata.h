/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP10 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library
#include <stdio.h>
#include <string.h>

// Variabel Global:
int indeks;
int panjangkata;
char ckata[105];
/*
    (1) Indeks = buat indeks di mesin
    (2) panjangkata = panjang kata per kata
    (3) ckata = current kata
*/

// Untuk memulai membaca kata
void STARTKATA(char pita[]);
// Mereset CKATA
void RESETKATA();
// Maju satu kata
void INCKATA(char pita[]);
// Mengambil nilai CKATA
char *GETKATA();
// Mengambil nilai panjang kata
int PANJANGKATA();
// Mengecek End Of File kalimat
int EOPKATA(char pita[]);
// Menentukan panjang menengah maksimal
int MENENGAH(int a, int b);
// Menentukan panjang pendek maksimal
int PENDEK(int a, int b);
void SORT(char pita[][50], int x);