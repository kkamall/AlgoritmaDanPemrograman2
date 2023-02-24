/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal eval 2 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>

int idx, wlen, terpanjang[3], banyakdata;
char cw[501];
char barang[100][3][100];
/*
    (1) idx = index
    (2) wlen = word length
    (3) cw = current word
*/

// Dijelaskan dalam mesin.c =>
void start(char word[]);
void reset();
int eop(char query[]);
void inc(char query[]);
int getlen();
char *getcw();
void ambildata();
void prosedur(int i, char pita[]);
void cariterpanjang(int i);
void output(int i);