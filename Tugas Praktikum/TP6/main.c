/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP6 Alpro 2 C1 2021 - MWA21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int i, j, a, b, c;
    /*
        (1) i, j = iterasi
        (2) a, b, c = banyaknya array tiap toko
    */

    // Meminta inputan nilai a dan data toko1
    scanf("%d", &a);
    karakter toko1[a];
    for(i=0; i<a; i++)
    {
        scanf("%s %d %f", &toko1[i].barang, &toko1[i].harga, &toko1[i].rating);
    }

    // Meminta inputan nilai b dan data toko2
    scanf("%d", &b);
    karakter toko2[b];
    for(i=0; i<b; i++)
    {
        scanf("%s %d %f", &toko2[i].barang, &toko2[i].harga, &toko2[i].rating);
    }

    // Meminta inputan nilai c dan data toko3
    scanf("%d", &c);
    karakter toko3[c];
    for(i=0; i<c; i++)
    {
        scanf("%s %d %f", &toko3[i].barang, &toko3[i].harga, &toko3[i].rating);
    }

    karakter toko4[a+b];
    karakter toko5[a+b+c];
    int budget;
    char metode, patokan[10];
    /*
        (1) toko 4 = gabungan toko 1 dan toko 2
        (2) toko 5 = gabungan toko 3 dan toko 4
        (3) budget = budget konsumer
        (4) metode = metode sorting
        (5) patokan = patokan sorting
    */
    scanf("%d %c %s", &budget, &metode, &patokan);

    // Pemanggilan prosedur output
    output(budget, patokan, metode, a, b, c, toko1, toko2, toko3, toko4, toko5);

    return 0;
}