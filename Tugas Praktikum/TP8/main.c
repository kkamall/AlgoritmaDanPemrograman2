/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP8 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int tanda;
    char fff;
    /*
        (1) tanda = flag fitur
        (2) fff = buat nahan biar gak ke cls
    */

    // Memanggil typedef struct
    dataF film[100];
    dataG gnr[100];
    dataS std[100];
    dataB bskp[100];

    // Do While untuk menjalankan macam fitur
    do
    {
        // Nge-clear CMD
        system("cls");

        // Memberi Output berupa penjelasan macam-macam fitur yang ada
        printf("(-) Macam Fitur:\n");
        for (i = 0; i < 61; i++)
        {
            printf("-");
        }
        printf("\n");
        printf("| 1. Menambah Record | 2. Tabel | 3. Searching | 4. Selesai |\n");
        for (i = 0; i < 61; i++)
        {
            printf("-");
        }
        printf("\n");

        // Meminta inputan berupa angka untuk menentukan fitur yang dijalankan
        printf("(-) Pilih Angkanya: ");
        scanf("%d", &tanda);
        printf("\n");

        // Menjalankan fitur penambahan data
        if (tanda == 1)
        {
            // Sebagai tanda file yang ingin ditambahkan datanya
            int flag;

            // Output Pemilihan file
            printf("(-) Tambahkan Data:\n");
            printf("--------------------------------------------------\n");
            printf("| 1. Film | 2. Sutradara | 3. Genre | 4. Bioskop |\n");
            printf("--------------------------------------------------\n");
            printf("(-) Pilih Angka File yang ingin Ditambahkan Data: ");
            scanf("%d", &flag);

            // Menambahkan data pada file listfilm.dat
            if (flag == 1)
            {
                sFilm(film);
            }
            // Menambahkan data pada file sutradara.dat
            else if (flag == 2)
            {
                sSutradara(std);
            }
            // Menambahkan data pada file genre.dat
            else if (flag == 3)
            {
                sGenre(gnr);
            }
            // Menambahkan data pada file bioskop.dat
            else
            {
                sBioskop(bskp);
            }
            printf("\n");
            for (i = 0; i < 28; i++)
            {
                printf("-");
            }

            // Tanda selesai
            printf("\n| Data Selesai Dimasukkan! |\n");
            for (i = 0; i < 28; i++)
            {
                printf("-");
            }
            printf("\n");
        }

        // Menjalankan fitur output tabel
        else if (tanda == 2)
        {
            final(film, gnr, std, bskp);
        }

        // Menjalankan fitur searching
        else if (tanda == 3)
        {
            // Output informasi
            for (i = 0; i < 71; i++)
            {
                printf("-");
            }
            printf("\n| Masukkan Data yang Ingin Dicari (Opsional || '-' Jika Tidak Dicari) |\n");
            for (i = 0; i < 71; i++)
            {
                printf("-");
            }

            // Meminta inputan kode yang akan dicari
            printf("\n(-) Struktur (KSutradara  KGenre  KBioskop)\n    -> ");
            scanf("%s %s %s", &search[0], &search[1], &search[2]);

            // Memanggil prosedur
            itung(std, gnr, bskp);
            binSearch(std, gnr, bskp);
        }

        // Menjalankan getch supaya gak langsung ke clear
        if (tanda != 4)
        {
            printf("\n-- Press Anykey to Continue!!! --\n");
            fff = getch();
        }

        // Tanda sistem keluar/selesai
        else
        {
            printf("-- Terima Kasih!!! --\n");
        }
    } while (tanda != 4);
}