/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS [MSKAR22K] Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>

// Variabel Global:
int idx;
char cc;
/*
    (1) idx = index
    (2) cc = current word
*/

// Memulai membaca karakter
void start(char pita[]);
// Mengecek EOP
int eop();
// Membaca karakter selanjutnya
void inc(char pita[]);
// Mendapatkan index
int getidx();
// Mendapatkan current word
char getcc();
// Menghindari spasi
void spasi(char pita[]);