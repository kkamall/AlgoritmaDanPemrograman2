/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal Kuis 1 Alpro 2 C1 2021 - MATDMAT2
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int a, b, c, d, e, f, g, h, x1, x2;
    /*
        (1) a, b = banyak baris dan kolom matriks pertama
        (2) c, d = banyak baris dan kolom matrisk kedua
        (3) e, f = berisi baris dan kolom dari matriks yang lebih gede
        (4) g, h = berisi baris dan kolom dari matriks yang lebih kecil
        (5) x1, x2 = Posisi kiri atas matriks
    */

    // Pemanggilan typedef struct
    matriks nilai;

    // Minta inputan a dan b
    scanf("%d %d", &a, &b);
    // Looping buat minta inputan nilai matriks pertama
    for(i=0; i<a; i++)
    {
        for(j=0; j<b; j++)
        {
            for(k=0; k<2; k++)
            {
                scanf("%d", &nilai.mat1[i][j][k]);
            }
        }
    }

    // Minta inputan c dan d
    scanf("%d %d", &c, &d);
    // Looping buat minta inputan nilai matriks kedua
    for(i=0; i<c; i++)
    {
        for(j=0; j<d; j++)
        {
            for(k=0; k<2; k++)
            {
                scanf("%d", &nilai.mat2[i][j][k]);
            }
        }
    }
    scanf("%d %d", &x1, &x2);

    // Tanda untk menyimpan nilai dari fungsi cek berupa tanda matriks mana yang lebih besar
    int tanda = cek(a, b, c, d, &e, &f, &g, &h);
    // Pemanggilan prosedur hasil
    hasil(e, f, g, h, x1, x2, nilai, tanda);

    return 0;
}