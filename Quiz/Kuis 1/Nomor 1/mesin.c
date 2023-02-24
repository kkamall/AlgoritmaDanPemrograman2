/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal Kuis 1 Alpro 2 C1 2021 - MATDMAT2
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Fungsi untuk mengecek matriks mana yang lebih besar
int cek(int a, int b, int c, int d, int *e, int *f, int *g, int *h)
{
    int flag=0;
    /*
        (1) flag = tanda matriks mana yang lebih besar
    */

    // Pen-copy-an nilai baris dan kolom matriks
    if(a*b > c*d)
    {
        *e=a;*f=b;*g=c;*h=d;flag=1;
    }
    else
    {
        *e=c;*f=d;*g=a;*h=b;
    }

    // Pengembalian nilai variabel flah
    return flag;
}

// Prosedur untuk mengeluarkan output
void hasil(int e, int f, int g, int h, int x1, int x2, matriks nilai, int tanda)
{
    int g1=0, h1=0;
    /*
        (1) g1, h1 = buat index matriks yang lebih kecil
    */

    // Looping buat mengalikan dan ngasih output
    for(i=0; i<e; i++)
    {
        for(j=0; j<f; j++)
        {
            // Tanda kalau matriks 1 > matriks 2
            if(tanda == 1)
            {
                // Untuk menandakan baris dan kolom matriks besar yang ingin dikalian
                if((i<x1+g && j<x2+h) && (i>=x1 && j>=x2))
                {
                    nilai.mat1[i][j][0] *= nilai.mat2[g1][h1][0];
                    nilai.mat1[i][j][1] *= nilai.mat2[g1][h1][1];
                    printf("%d %d\n", nilai.mat1[i][j][0], nilai.mat1[i][j][1]);
                    // Penambahan indeks matriks kecil
                    if(h1!=h-1)
                    {
                        h1++;
                    }
                    else
                    {
                        g1++;
                        h1=0;
                    }
                }
                else
                {
                    printf("%d %d\n", nilai.mat1[i][j][0], nilai.mat1[i][j][1]);
                }
            }
            // Tanda kalau matriks 1 < matriks 2
            else
            {
                // Untuk menandakan baris dan kolom matriks besar yang ingin dikalian
                if((i<x1+g && j<x2+h) && (i>=x1 && j>=x2))
                {
                    nilai.mat2[i][j][0] *= nilai.mat1[g1][h1][0];
                    nilai.mat2[i][j][1] *= nilai.mat1[g1][h1][1];
                    printf("%d %d\n", nilai.mat2[i][j][0], nilai.mat2[i][j][1]);
                    // Penambahan indeks matriks kecil
                    if(h1!=h-1)
                    {
                        h1++;
                    }
                    else
                    {
                        g1++;
                        h1=0;
                    }
                }
                else
                {
                    printf("%d %d\n", nilai.mat2[i][j][0], nilai.mat2[i][j][1]);
                }
            }
        }
    }
}