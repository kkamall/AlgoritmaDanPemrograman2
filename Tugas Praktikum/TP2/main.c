/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP2 Alpro 2 C1 2021 - MBPG
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int baris, kolom, x=0;
    // Meminta inputan berupa banyak baris dan kolom matriks
    scanf("%d %d", &baris, &kolom);
    int panjang[kolom];
    basket team[baris][kolom];
    basket menukar[1000];
    /*
        (1) baris, kolom = baris dan kolom matriks
        (2) panjang = buat nyimpen string tim terpanjang 
        (3) team = buat nyimpen inputan team basket dak kekuatannya
        (4) basket = buat nyimpen tim yang ingin dituker
        (5) x = buat nyimpen banyaknya tim yang ingin ditukar sampe kata stop
    */

    // Fungsi loop untuk meng-0-kan seluruh nilai array panjang
    for(i=0; i<kolom; i++)
    {
        panjang[i]=0;
    }

    // Fungsi loop untuk meminta inputan berupa nama tim dan kekuatannya
    for (i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            scanf("%s", &team[i][j].tim);
            for(k=0; k<2; k++)
            {
                scanf("%d", &team[i][j].kekuatan[k]);
            }
        }
    }

    j=0;
    // Fungsi while untuk meminta masukan berupa tim yang ingin ditukar sampai kata stop
    while(j==0)
    {
        scanf("%s", &menukar[x].tukar1);
        if(strcmp(menukar[x].tukar1, "stop") == 0)
        {
            j=1;
        }
        else
        {
            scanf("%s", &menukar[x].tukar2);
            x++;
        }
    }

    // Pemanggilan prosedur "awal" untuk mengeluarkan keluaran sebelum ditukar
    awal(baris, kolom, team, panjang);
    // Pemanggilan prosedur "akhir" untuk menukar tim dan memberikan output setelah ditukar
    akhir(baris, kolom, &team, menukar, x, panjang);

    return 0;
}