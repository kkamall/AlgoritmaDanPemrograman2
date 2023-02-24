/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP6 Alpro 2 C1 2021 - MWA21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk sorting insertion
void insertion(int x, karakter kelontong[], char patokan[10])
{
    // Iterasi
    int i, j;
    // buat membandingkan nilai
    karakter temp;

    // Looping untuk sorting
    for(i=0; i<x; i++)
    {
        temp = kelontong[i];
        j = i-1;
        
        // Kondisi patokannya harga
        if(strcmp(patokan, "harga") == 0)
        {   
            // While untuk pertukaran nilai
            while(j>=0 && temp.harga<kelontong[j].harga)
            {
                kelontong[j+1] = kelontong[j];
                j--;
            }
        }
        // Kondisi patokannya rating
        else
        {
            // While untuk pertukaran nilai
            while (j>=0 && temp.rating>kelontong[j].rating)
            {
                kelontong[j+1] = kelontong[j];
                j--;
            }
        }
        kelontong[j+1]=temp;
    }
}

// Prosedur untuk sorting selection
void selection(int x, karakter kelontong[], char patokan[10])
{
    int i, j, midx;
    karakter temp;
    /*
        (1) i, j = iterasi
        (2) midx = minimal index
        (3) temp = untuk pertukaran nilai
    */

    // Looping untuk sorting
    for(i=0; i<x-1; i++)
    {
        midx = i;

        // Kondisi patokannya harga
        if(strcmp(patokan, "harga") == 0)
        {
            // Looping mencari minimal index
            for(j=i+1; j<x; j++)
            {
                if(kelontong[midx].harga>kelontong[j].harga)
                {
                    midx = j;
                }
            }
        }
        // Kondisi patokannya rating
        else
        {
            // Looping mencari minimal index
            for(j=i+1; j<x; j++)
            {    
                if(kelontong[midx].rating<kelontong[j].rating)
                {
                    midx = j;
                }
            }
        }
        // Proses pertukaran nilai
        temp = kelontong[i];
        kelontong[i] = kelontong[midx];
        kelontong[midx] = temp;
    }
}

// Prosedur untuk sorting bubble
void bubble(karakter kelontong[], int x, char patokan[10])
{
    int i, flag;
    karakter temp;
    /*
        (1) i = buat iterasi
        (2) flag = sebagai tanda ada atau tidanya pertukaran nilai
        (3) temp = untuk pertukaran nilai
    */

    // Do While untuk proses sorting
    do
    {
        flag=0;
        // Looping untuk proses sorting
        for(i=0; i<x-1; i++)
        {
            // Kondisi patokannya harga
            if(strcmp(patokan, "harga") == 0)
            {
                if(kelontong[i].harga>kelontong[i+1].harga)
                {
                    // Proses pertukaran nilai
                    temp = kelontong[i];
                    kelontong[i] = kelontong[i+1];
                    kelontong[i+1] = temp;
                    flag = 1;
                }
            }
            // Kondisi patokannya rating
            else
            {
                if(kelontong[i].rating<kelontong[i+1].rating)
                {
                    // Proses pertukaran nilai
                    temp = kelontong[i];
                    kelontong[i] = kelontong[i+1];
                    kelontong[i+1] = temp;
                    flag = 1;
                }
            }
        }
    }while(flag==1);
}

// Prosedur untuk sorting quick tengah
void quick(char patokan[10], karakter kelontong[], int kiri, int kanan)
{
    int i, j;
    karakter pivot;
    karakter temp;
    /*
        (1) i, j = iterasi
        (2) pivot = sebagai pembanding nilai
        (3) temp = untuk proses pertukaran nilai
    */

    i = kiri; j = kanan;
    pivot = kelontong[(kanan+kiri)/2];

    // Do While untuk proses sorting
    do
    {
        // Kondisi patokannya harga
        if(strcmp(patokan, "harga") == 0)
        {
            // While untuk mencari index i
            while((kelontong[i].harga < pivot.harga) && (i<=j))
            {
                i++;
            }
            // While untuk mencari index j
            while((kelontong[j].harga > pivot.harga) && (i<=j))
            {
                j--;
            }
        }
        // Kondsi patokannya rating
        else
        {
            // While untuk mencari index i
            while((kelontong[i].rating > pivot.rating) && (i<=j))
            {
                i++;
            }
            // While untuk mencari index j
            while((kelontong[j].rating < pivot.rating) && (i<=j))
            {
                j--;
            }
        }
        if(i<j)
        {
            // Proses pertukran nilai
            temp = kelontong[i];
            kelontong[i] = kelontong[j];
            kelontong[j] = temp;
            i++; j--;
        }
    }while(i<j);

    // Proses rekursif
    if((kiri<j) && (j<kanan))
    {
        quick(patokan, kelontong, kiri, j);
    }
    // Proses rekursif
    if((i<kanan) && (i>kiri))
    {
        quick(patokan, kelontong, i, kanan);
    }
}

// Prosedur untuk merge array
void merge(int x, int y, char patokan[10], karakter kelontong1[], karakter kelontong2[], karakter kelontong3[])
{
    int i=0, j=0, k;
    /*
        (1) i = untuk index kelontong 1
        (2) j = untuk index kelontong 2
        (3) k = buat iterasi
    */

    // Looping untuk mengurutkan dan menyatukan array
    for(k=0; k<x+y; k++)
    {
        // Kondisi patokannya harga
        if(strcmp(patokan, "harga") == 0)
        {
            // Kondisi dimana data kelontong1 sudah di-copy semua
            if(i==x)
            {
                kelontong3[k] = kelontong2[j];
                j++;
            }
            // Kondisi dimana data kelontong 2 sudah di-copy semua
            else if(j==y)
            {
                kelontong3[k] = kelontong1[i];
                i++;
            }
            // Kondisi dimana harga pada kelontong 1 lebih kecil dari harga pada kelontong 2
            else if(kelontong1[i].harga<kelontong2[j].harga)
            {
                kelontong3[k] = kelontong1[i];
                i++;
            }
            // Kondisi dimana harga pada kelontong 1 lebih besar dari harga pada kelontong 2
            else if(kelontong1[i].harga>kelontong2[j].harga)
            {
                kelontong3[k] = kelontong2[j];
                j++;
            }
            // Kondisi dimana harga pada kelontong 1 sama dengan harga pada kelontong 2
            else if(kelontong1[i].harga==kelontong2[j].harga)
            {
                kelontong3[k] = kelontong1[i];
                k++;
                kelontong3[k] = kelontong2[j];
                i++; j++;
            }
        }
        // Kondsii patokannya rating
        else
        {
            // Kondisi dimana data kelontong1 sudah di-copy semua
            if(i==x)
            {
                kelontong3[k] = kelontong2[j];
                j++;
            }
            // Kondisi dimana data kelontong 2 sudah di-copy semua
            else if(j==y)
            {
                kelontong3[k] = kelontong1[i];
                i++;
            }
            // Kondisi dimana harga pada kelontong 1 lebih besar dari harga pada kelontong 2
            else if(kelontong1[i].rating>kelontong2[j].rating)
            {
                kelontong3[k] = kelontong1[i];
                i++;
            }
            // Kondisi dimana harga pada kelontong 1 lebih kecil dari harga pada kelontong 2
            else if(kelontong1[i].rating<kelontong2[j].rating)
            {
                kelontong3[k] = kelontong2[j];
                j++;
            }
            // Kondisi dimana harga pada kelontong 1 sama dengan harga pada kelontong 2
            else if(kelontong1[i].rating==kelontong2[j].rating)
            {
                kelontong3[k] = kelontong1[i];
                k++;
                kelontong3[k] = kelontong2[j];
                i++; j++;
            }
        }
    }
}

// Prosedur untuk mengeluarka otuput
void output(int budget, char patokan[10], char metode, int a, int b, int c, karakter toko1[a], karakter toko2[b], karakter toko3[c], karakter toko4[a+b], karakter toko5[a+b+c])
{
    int i, j=0;
    int duit=0;
    /*
        (1) i, j = buat iterasi
        (2) duit = buat di kondisi
    */

    // Proses memanggil prosedur sesuai metode sorting
    if(metode == 'i')
    {
        insertion(a, toko1, patokan);
        insertion(b, toko2, patokan);
        insertion(c, toko3, patokan);
    }
    else if(metode == 's')
    {
        selection(a, toko1, patokan);
        selection(b, toko2, patokan);
        selection(c, toko3, patokan);
    }
    else if(metode == 'b')
    {
        bubble(toko1, a, patokan);
        bubble(toko2, b, patokan);
        bubble(toko3, c, patokan);
    }
    else if(metode == 'q')
    {
        quick(patokan, toko1, 0, a-1);
        quick(patokan, toko2, 0, b-1);
        quick(patokan, toko3, 0, c-1);
    }

    // Pemanggilan prosedur untuk merge array
    merge(a, b, patokan, toko1, toko2, toko4);
    merge(c, a+b, patokan, toko3, toko4, toko5);
    
    // Output
    printf("Wishlist Ana:\n-------------------------------\n");
    // Keluaran berupa list barang yang sudah di sorting dan disatukan
    for(i=0; i<a+b+c; i++)
    {
        printf("%s %d %.1f\n", toko5[i].barang, toko5[i].harga, toko5[i].rating);
    }

    // Keluaran berupa list barang yang bisa dibeli oleh Ana
    printf("===============================\nbarang yang dibeli:\n-------------------------------\n");
    while((duit<budget) && (j<a+b+c))
    {
        duit += toko5[j].harga;
        if(budget<toko5[0].harga)
        {
            printf("tidak ada barang yang dibeli\n");
        }
        else if(budget>=duit)
        {
            printf("%s %d %.1f\n", toko5[j].barang, toko5[j].harga, toko5[j].rating);
        }
        j++;
    }
    printf("===============================\n");
    
    // Keluaran berupa total belanja dan sisa budget Ana
    if(duit>budget && j<=a+b+c)
    {
        duit-=toko5[j-1].harga;
    }
    printf("total belanja : Rp. %d\n", duit);
    printf("sisa budget   : Rp. %d\n", budget-duit);
    printf("===============================\n");
}