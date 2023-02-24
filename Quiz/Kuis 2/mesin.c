/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Kuis 2 Alpro 2 C1 2021 - kngmdk22
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk sorting menggunakan selection sort
void sorting(dmakanan data[], int n, char urut[])
{
    int minidx;
    dmakanan temp;
    /*
        (1) minidx = minindex
        (2) temp = untuk menyimpan data sementara saat pertukaran
    */

    // Looping selection sort
    for (i = 0; i < n - 1; i++)
    {
        // Set minindex
        minidx = i;
        // Looping pembandingan
        for (j = i + 1; j < n; j++)
        {
            // Jika urutan berdasarkan harga
            if (strcmp(urut, "harga") == 0)
            {
                if (data[minidx].harga > data[j].harga)
                {
                    minidx = j;
                }
            }
            // Jika urutan berdasarkan kalori
            else
            {
                if (data[minidx].kalori < data[j].kalori)
                {
                    minidx = j;
                }
            }
        }
        // Proses pertukaran data
        temp = data[i];
        data[i] = data[minidx];
        data[minidx] = temp;
    }
}

// Prosedur untuk melakaukan searching menggunakan binary search
void search(dmakanan data[], int n, int cari, char urut[])
{
    int flag = 0;
    i = 0, k = 0;
    /*
        (1) flag = tanda ketemu atau tidaknya data
        (2) i, k = index
    */

    // While untuk proses binary search
    while ((i <= n) && (flag == 0))
    {
        // Set nilai k
        k = (i + n) / 2;

        // Jika urut berdasarkan harga
        if (strcmp(urut, "harga") == 0)
        {
            // Jika data yang dicari ketemu
            if (data[k].harga == cari)
            {
                flag = 1;
                printf("nama makanan: %s\nharga: %d\ntempat penjualan: %s\npersen kalori: %d\n", data[k].nama, data[k].harga, data[k].toko, data[k].kalori);
            }
            // Jika data yang dicari tidak ketemu
            else
            {
                // Setting nilai index
                if (data[k].harga > cari)
                {
                    n = k - 1;
                }
                else
                {
                    i = k + 1;
                }
            }
        }
        // Jika urut berdasarkan kalori
        else
        {
            // Jika data yang dicari ketemu
            if (data[k].kalori == cari)
            {
                flag = 1;
                printf("nama makanan: %s\nharga: %d\ntempat penjualan: %s\npersen kalori: %d\n", data[k].nama, data[k].harga, data[k].toko, data[k].kalori);
            }
            // Jika data yang dicari tidak ketemu
            else
            {
                // Setting index
                if (data[k].kalori < cari)
                {
                    n = k - 1;
                }
                else
                {
                    i = k + 1;
                }
            }
        }
    }

    // Output bila data tidak ditemukan
    if (flag == 0)
    {
        printf("tidak ditemukan\n");
    }
}