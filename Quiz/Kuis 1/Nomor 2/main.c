/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal Kuis 1 Alpro 2 C1 2021 - DERET322
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int banyak;
    /*
        (1) banyak = banyaknya deret 3 lain yang akan dibuat
    */

    // Looping untuk minta inputan
    for(i=0; i<3; i++)
    {
        scanf("%d", &awal[i]);
    }scanf("%d", &banyak);

    // Pemanggilan prosedur output
    output(awal, banyak);
    // Memberikan keluaran berupa newline
    printf("\n");

    return 0;
}