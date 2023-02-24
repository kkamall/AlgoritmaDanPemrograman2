/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP9 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library
#include <stdio.h>
#include <string.h>

// Variabel Global
int indeks;
char cc;
/*
    (1) indeks = untuk indeks array
    (2) cc = current character
*/

// Prosedur untuk memulai pembacaan string
void START(char pita[]);
// Fungsi yang menentukan apakah sudah mencapai EOP atau belum
int EOP(char m);
// Prosedur menambahkan index
void INC(char pita[]);
// Fungsi mengembalikan current character ke main
char GETCC();