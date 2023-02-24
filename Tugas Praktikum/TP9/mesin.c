/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP9 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk memulai pembacaan string
void START(char pita[])
{
    indeks = 0;
    cc = pita[indeks];
}

// Fungsi yang menentukan apakah sudah mencapai EOP atau belum
int EOP(char m)
{
    // If dengan kondisi sudah mencapai EOP
    if (m == '.')
    {
        return 1;
    }
    // If dengan kondisi belum mencapai EOP
    else
    {
        return 0;
    }
}

// Prosedur menambahkan index
void INC(char pita[])
{
    // Proses Increment
    indeks++;
    // Mendapatkan CC
    cc = pita[indeks];
}

// Fungsi mengembalikan current character ke main
char GETCC()
{
    return cc;
}