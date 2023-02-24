/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS [MSKAR22K] Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Memulai membaca karakter
void start(char pita[])
{
    idx = 0;
    cc = pita[idx];
}

// Mengecek EOP
int eop()
{
    // EOP ketemu
    if (cc == '$')
    {
        return 1;
    }
    // EOP tidak ketemu
    else
    {
        return 0;
    }
}

// Membaca karakter selanjutnya
void inc(char pita[])
{
    idx++;
    cc = pita[idx];
}

// Menghindari spasi
void spasi(char pita[])
{
    // Index nambah kalau ketemu spasi
    while (getcc() == ' ')
    {
        idx++;
        cc = pita[idx];
    }
}

// Mendapatkan index
int getidx()
{
    return idx;
}

// Mendapatkan current word
char getcc()
{
    return cc;
}