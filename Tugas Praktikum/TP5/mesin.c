/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP5 Alpro 2 C1 2021 - SFNL21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Fungsi untuk mengolah durasi film menjadi menit per judul dan secara keseluruhan film
int menambah(int n, x film[n])
{
    // Variabel untuk menyipan nilai olahan untuk balikkan kedalam fungsi main
    int back=0;

    // If dengan kondisi i kurang dari n, untuk mentotalkan durasi film menjadi menit/judul
    if(i<n)
    {
        back = film[i].jam*60+film[i].menit;
    }
    // If dengan kondisi i lebih dari n, untuk menghitung total jam dan menit keseluruhan film
    else
    {
        // Looping untuk menambahkan total menit keseluruhan film ke dalam variabel back
        for(k=0; k<n; k++)
        {
            back+=film[k].totmenit;
        }
        // If untuk mencari sisa menit dari totalmenit yang telah dikonversikan ke jam
        if(i==n+1)
        {
            back%=60;
        }
        // If untuk mencari total jam
        else
        {
            back/=60;
        }
    }

    // Mengembalikan nilai pada variabel back ke fungsi main
    return back;
}

// Prosedur untuk sorting menggunakan bubblesort
void bubble(int n, int urutan, x film[n])
{
    // Variabel sebagai tanda apakah ada nilai yang ditukar atau tidak
    int flag;

    // Do While untuk menukar nilai sesuai dengan syarat
    do
    {
        // Set ke-0 sebagai tanda tidak/belum ada perubahan
        flag = 0;
        // Looping untuk menukar nilai sesuai dengan syarat
        for(i=0; i<(n-1); i++)
        {
            // If yang menandakan ascending
            if(urutan == 'a')
            {
                if(film[i].totmenit>film[i+1].totmenit)
                {
                    // Proses pertukaran
                    temp = film[i];
                    film[i] = film[i+1];
                    film[i+1] = temp;
                    // Flag di-set menjadi 1 sebagai tanda ada perubahan
                    flag = 1;
                }
            }
            // If yang menandakan descending
            else
            {
                if(film[i].totmenit<film[i+1].totmenit)
                {
                    // Proses pertukaran
                    temp = film[i];
                    film[i] = film[i+1];
                    film[i+1] = temp;
                    // Flag di-set menjadi 1 sebagai tanda ada perubahan
                    flag = 1;
                }
            }
        }
    }while(flag==1);
}

// Prosedur untuk sorting menggunakan quicksort
void quick(int n, int kiri, int kanan, int urutan, x film[n], int metode)
{
    int pivot, l, m;
    /*
        (1) pivot = untuk pivot
        (2) l, m = sebagai indeks
    */
    l = kiri; m = kanan; pivot = film[(kanan+kiri)/2].totmenit;

    // Do While untuk melakukan proses pertukaan
    do
    {
        // If sebagai penanda ascending
        if(urutan == 'a')
        {
            // While untuk menentukan indeks yang akan ditukan
            while((film[l].totmenit<pivot) && (l<=m))
            {
                l++;
            }
            while((film[m].totmenit>pivot) && (l<=m))
            {
                m--;
            }
        }
        // If sebagai penanda descending
        else
        {
            // While untuk menentukan indeks yang akan ditukar
            while((film[l].totmenit>pivot) && (l<=m))
            {
                l++;
            }
            while((film[m].totmenit<pivot) && (l<=m))
            {
                m--;
            }
        }

        if(l<m)
        {
            // Proses pertukaran
            temp = film[l];
            film[l] = film[m];
            film[m] = temp;
            l++; m--;
        }
    }while(l<m);

    if((kiri<m) && (m<kanan))
    {
        // Rekursif
        quick(n, kiri, m, urutan, film, metode);
    }
    if((l<kanan) && (l>kiri))
    {
        // Rekursif
        quick(n, l, kanan, urutan, film, metode);
    }
}

// Prosedur untuk mengeluarkan output berupa film yang sudah berurut berdasarkan durasi
void output(int n, x film[n], int metode, int urutan)
{
    // Varibel berisi string terpanjang dari judul inputan user
    int terbanyak=0;

    // Looping untuk mencari string judul terpanjang
    for(i=0; i<n; i++)
    {
        if(terbanyak<strlen(film[i].judul))
        {
            terbanyak = strlen(film[i].judul);
        }
    }

    // If untuk menggunakan bubblesort
    if(metode == 'b')
    {
        bubble(n, urutan, film);
    }
    // If untuk menggunakan quicksort
    else
    {
        quick(n, 0, n-1, urutan, film, metode);
    }

    // Proses pengeluaran output
    printf("Data Film Terurut :\n");
    for(i=0; i<n; i++)
    {
        printf("%s  ", film[i].judul);
        // Looping untuk memberikan output berupa spasi
        for(j=0; j<terbanyak-strlen(film[i].judul); j++)
        {
            printf(" ");
        }printf("%dj %dm\n", film[i].jam, film[i].menit);
    }printf("\nTotal Durasi : %d jam %d menit\n", film[i].totmenit, film[i+1].totmenit);
}