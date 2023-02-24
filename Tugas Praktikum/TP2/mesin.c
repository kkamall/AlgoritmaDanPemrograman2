/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP2 Alpro 2 C1 2021 - MBPG
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk mengeluarkan keluaran sebelum ditukar
void awal(int baris, int kolom, basket team[baris][kolom], int panjang[kolom])
{
    // Memberikan keluaran isi matriks sebelum ditukar
    printf("Drawing Awal:\n");
    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            // Fungsi if untuk mengisi menentukan string tim terpanjang pada tiap baris
            if(i==0)
            {
                for(k=0; k<baris; k++)
                {
                    if(strlen(team[k][j].tim)>panjang[j])
                    {
                        panjang[j]=strlen(team[k][j].tim);
                    }
                }
            }
            // Memberikan output tim basket
            printf("%s", team[i][j].tim);
            // Memberikan output berupa spasi
            if(j<kolom-1)
            {
                for(k=0; k<panjang[j]-strlen(team[i][j].tim); k++)
                {
                    printf(" ");
                }
                printf("  ");
            }
        }
        // Newline
        printf("\n");
    }
}

// Fungsi untuk memberikan tanda apakan bisa diswap atau tidak timnya
int swap(int baris, int kolom, basket team[baris][kolom], basket menukar[1000], int x)
{
    int flag=0, r1=0, r2=0;
    /*
        (1) flag = sebagai tanda apakah rata^2 tim kiri >/< dari tim kanan
        (2) r1 = menyimpan nilai rata^2 tim kiri
        (3) r2 = menyimpan nilai rata^2 tim kanan
    */

    // Fungsi looping untuk menenentukan rata-rata tim yang ingin ditukar
    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            if(strcmp(menukar[k].tukar1, team[i][j].tim)==0)
            {
                r1 = (team[i][j].kekuatan[0]+team[i][j].kekuatan[1])/2;
            }
            else if(strcmp(menukar[k].tukar2, team[i][j].tim)==0)
            {
                r2 = (team[i][j].kekuatan[0]+team[i][j].kekuatan[1])/2;
            }
        }
    }

    // Fungsi if untuk mengubah flag menjadi 1 yang menandakan rata^2 tim kiri > tim kanan 
    if(r1>r2)
    {
        flag=1;
    }

    // Mengembalikan nilai dari flag
    return flag;
}

// Prosedur untuk menukar tim dan memberikan output setelah ditukar
void akhir(int baris, int kolom, basket (*team)[baris][kolom], basket menukar[1000], int x, int panjang[kolom])
{
    basket temp;
    /*
        (1) temp = buat penukaran
    */

    // Fungsi looping untuk menentukan indeks tim yang ingin ditukar jika flagnya 1
    for(k=0; k<x; k++)
    {
        int  a=0, b=0, c=0, d=0;
        if(swap(baris, kolom, (*team), menukar, x)==1)
        {
            for(i=0; i<baris; i++)
            {
                for(j=0; j<kolom; j++)
                {
                    if(strcmp((*team)[i][j].tim, menukar[k].tukar1)==0)
                    {
                        a=i;
                        b=j;
                    }
                    else if(strcmp((*team)[i][j].tim, menukar[k].tukar2)==0)
                    {
                        c=i;
                        d=j;
                    }
                }
            }

            // Proses penukaran
            temp = (*team)[a][b];
            (*team)[a][b] = (*team)[c][d];
            (*team)[c][d] = temp;
        }
    }

    // Memberikan output
    printf("\nDrawing Akhir:\n");
    for(i=0; i<baris; i++)
    {
        for(j=0; j<kolom; j++)
        {
            // Penentuan string tim terpanjang (setelah ditukar)
            if(i==0)
            {
                for(k=0; k<baris; k++)
                {
                    if(strlen((*team)[k][j].tim)>panjang[j])
                    {
                        panjang[j]=strlen((*team)[k][j].tim);
                    }
                }
            }
            printf("%s", (*team)[i][j].tim);

            // Memberika output spasi
            if(j<kolom-1)
            {
                for(k=0; k<panjang[j]-strlen((*team)[i][j].tim); k++)
                {
                    printf(" ");
                }
                printf("  ");
            }
        }
        // Newline
        printf("\n");
    }
}