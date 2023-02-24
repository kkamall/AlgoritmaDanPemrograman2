/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal Evaluasi Alpro 2 C1 2021 - ROTT22
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    // Variabel untuk menyimpan banyak array
    int a, b, c;
    scanf("%d", &a);
    // Data mahasiswa tabel pertama
    data mahasiswa1[a];

    // Meminta data mahasiswa
    for(i=0; i<a; i++)
    {
        scanf("%s %s %d", &mahasiswa1[i].nim, &mahasiswa1[i].nama, &mahasiswa1[i].nilai);
    }

    scanf("%d", &b);
    // Data mahasiswa tabel kedua
    data mahasiswa2[b];

    // Meminta data mahasiswa
    for(i=0; i<b; i++)
    {
        scanf("%s %s %d", &mahasiswa2[i].nim, &mahasiswa2[i].nama, &mahasiswa2[i].nilai);
    }

    scanf("%d", &c);
    // Data mahasiswa tabel pertama
    data mahasiswa3[c];
    
    // Meminta data mahasiswa
    for(i=0; i<c; i++)
    {
        scanf("%s %s %d", &mahasiswa3[i].nim, &mahasiswa3[i].nama, &mahasiswa3[i].nilai);
    }

    // tabel mahasiswa gabungan tabel pertama dan kedua
    data mahasiswa4[a+b];
    // Data mahasiswa gabungan tabel ketiga dan keempat
    data mahasiswa5[a+b+c];
    // Pemanggilan prosedur output
    output(a, b, c, mahasiswa1, mahasiswa2, mahasiswa3, mahasiswa4, mahasiswa5);

    return 0;
}