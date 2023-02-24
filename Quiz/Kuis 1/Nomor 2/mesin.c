/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal Kuis 1 Alpro 2 C1 2021 - DERET322
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk mengeluarkan output yang sudah dihitung
void output(int awal[], int banyak)
{
    int x=0;
    /*
        (1) x = buat tanda supaya gak ada spasi di akhir  
    */

    // Basis untuk rekursif
    if(banyak>-1)
    {
        // Looping untuk memberikan output berupa nilai deret dan spasi
        for(i=0; i<3; i++)
        {
            printf("%d", awal[i]);
            if(x!=2+banyak*3)
            {
                printf(" ");
            }
            x++;
        }

        // Perhitungan deret posisi 2 & posisi 3
        awal[1]*=awal[1];
        awal[2]+=awal[1];
        
        // Rekursif
        output(awal, banyak-1);
    }
}