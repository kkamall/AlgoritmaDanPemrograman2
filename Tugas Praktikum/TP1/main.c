/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP1 Alpro 2 C1 2021 - MPM22
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int n, m, a;
    /*
        (1) n = jumlah baris
        (2) m = jumlah kolom
        (3) a = jumlah transformasi
    */

    // Meminta inputan user nilai n dan m
    scanf("%d %d", &n, &m);

    char matriks[n*m][m*n], matriksa[n*m][m*n];
    /*
        (1) matriks = array berisi nilai matriks
        (2) matriksa = array berisi nilai matriks akhir/yang sudah diubah
    */

    // Fungsi pengulangan untuk meminta masukan nilai matriks
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf(" %c", &matriks[i][j]);
            // Copy nilai matriks ke array matriksa
            matriksa[i][j] = matriks[i][j]; 
        }
    }

    // Meminta inputan user nilai a
    scanf("%d", &a);

    char b[a];
    /*
        (1) b = Kode transformasi sebanyak a
    */

    // Fungsi pengulangan untuk meminta inputan user berupa kode transformasi
    for(i=0; i<a; i++)
    {
        scanf(" %c", &b[i]);
    }

    // Pemanggilan prosedur
    ubah(a, b, n, m, matriksa, matriks);

    // Fungsi yang menandakan bahwa program telah berakhir
    return 0;
}