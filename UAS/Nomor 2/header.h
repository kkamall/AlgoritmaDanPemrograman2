/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS [MSKAT22K] Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>

// Variabel Global
int idx, pk, flag, klen;
char cw[501];
/*
    (1) idx = index
    (2) pk = panjang kata
    (3) flag = penanda ada kelompok kata yang di-input
    (4) cw = current word
    (5) klen = panjang kelompok kata masukkan user
*/

// Fungsi untuk mulai membaca kalimat
int start(char str[], char kata[]);
// Fungsi untuk melanjutkan pembacaan kalimat ke kata berikutnya
int inc(char str[], char kata[]);
// Prosedur untuk mereset kata
void reset();
// Fungsi untuk mengecek EOP
int eop(char str[]);
// Fungsi untuk mendapatkan panjang Current Word
int getlen();
// Fungsi untuk mendapatkan Current Word
char *getcw();
// Untuk menghitung banyak kata kelompok kata yang dicari
int itungkata(char kata[]);
// Untuk copy kata
void copykata(char valid[][502], int index);