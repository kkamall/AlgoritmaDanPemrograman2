/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal Evaluasi Alpro 2 C1 2021 - ROTT22
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk melakukan sorting nim
void sort(int y, int x, data mahasiswa[])
{
    int flag;
    data temp;
    /*
        (1) flag = sebagai tanda ada pertukaran
        (2) temp = untuk menyimpan data sementara
    */

    do
    {
        flag=0;
        for(i=y; i<x-1; i++)
        {
            if(strcmp(mahasiswa[i].nim, mahasiswa[i+1].nim) == 1)
            {
                // Proses pertukaran
                temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[i+1];
                mahasiswa[i+1] = temp;

                flag=1;
            }
        }
    }while(flag==1);
}

// Prosedur untuk melakukan sorting nilai
void sortN(int y, int x, data mahasiswa[])
{
    int flag;
    data temp;
    /*
        (1) flag = sebagai tanda ada pertukaran
        (2) temp = untuk menyimpan data sementara
    */

    do
    {
        flag=0;
        for(i=y; i<x-1; i++)
        {
            if(mahasiswa[i].nilai < mahasiswa[i+1].nilai)
            {
                // Proses pertukaran
                temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[i+1];
                mahasiswa[i+1] = temp;

                flag=1;
            }
        }
    }while(flag==1);
}

void merge(int x, int y, data mahasiswa1[], data mahasiswa2[], data mahasiswa3[])
{
    int j=0, k=0;
    /*
        (1) j = buat indeks tabel mahasiswa 1
        (2) k = buat indeks tabel mahasiswa 2
    */

    // Looping untuk merge tabel mahasiswa
    for(i=0; i<x+y; i++)
    {
        // Kondisi tabel mahasiswa 1 sudah ke-copy semua
        if(j==x)
        {
            mahasiswa3[i] = mahasiswa2[k];
            k++;
        }
        // Kondisi tabel mahasiswa 2 sudah ke-copy semua
        else if(k==y)
        {
            mahasiswa3[i] = mahasiswa1[j];
            j++;
        }
        // Kondisi nim mahasiswa tabel 1 lebih kecil dari tabel ke 2
        else if(strcmp(mahasiswa1[j].nim, mahasiswa2[k].nim) == -1)
        {
            mahasiswa3[i] = mahasiswa1[j];
            j++;
        }
        // Kondisi nim mahasiswa tabel 1 lebih besar dari tabel ke 2
        else if(strcmp(mahasiswa1[j].nim, mahasiswa2[k].nim) == 1)
        {
            mahasiswa3[i] = mahasiswa2[k];
            k++;
        }
    }
}

void output(int a, int b, int c, data mahasiswa1[], data mahasiswa2[], data mahasiswa3[], data mahasiswa4[], data mahasiswa5[])
{
    // Proses sorting
    sort(0, a, mahasiswa1);
    sort(0, b, mahasiswa2);
    sort(0, c, mahasiswa3);

    // Merge table
    merge(a, b, mahasiswa1, mahasiswa2, mahasiswa4);
    merge(c, a+b, mahasiswa3, mahasiswa4, mahasiswa5);

    // Proses pengeluaran OUTPUT
    printf("====================\n");
    for(i=0; i<a+b+c; i++)
    {
        printf("%s %s %d\n", mahasiswa5[i].nim, mahasiswa5[i].nama, mahasiswa5[i].nilai);
    }
    
    printf("====================\n");

    // Sorting berdasarkan nilai untuk index 0 - setengah
    sortN(0, (a+b+c)/2, mahasiswa5);
    for(i=0; i<(a+b+c)/2; i++)
    {
        printf("%s %s %d\n", mahasiswa5[i].nim, mahasiswa5[i].nama, mahasiswa5[i].nilai);
    }
    printf("====================\n");

    // Sorting berdasarkan nilai untuk index setengah - akhir
    sortN((a+b+c)/2, a+b+c, mahasiswa5);
    for(i=(a+b+c)/2; i<a+b+c; i++)
    {
        printf("%s %s %d\n", mahasiswa5[i].nim, mahasiswa5[i].nama, mahasiswa5[i].nilai);
    }
    printf("====================\n");


}