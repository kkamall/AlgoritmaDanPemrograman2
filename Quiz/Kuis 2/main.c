/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Kuis 2 Alpro 2 C1 2021 - kngmdk22
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    dmakanan data[51];
    int n, cari;
    char urut[10];
    /*
        (1) n = banyak data
        (2) cari = data yang ingin dicari
        (3) urut = urutan berdasarkan apa
    */
    // Meminta inputan banyaknya data
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        // Meminta inputan data-data makanan
        scanf("%s %d %s %d", &data[i].nama, &data[i].harga, &data[i].toko, &data[i].kalori);
    }

    // Meminta inputan dasar urutan dan data yang akan dicari
    scanf("%s %d", &urut, &cari);

    // Pemanggilan prosedur sorting dan searching
    sorting(data, n, urut);
    search(data, n, cari, urut);

    return 0;
}