/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP8 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Void untuk menambah data list film
void sFilm(dataF film[])
{
    // Untuk menukar data pada sorting
    dataF temp;
    i = 0;

    // Membuka file dengan mode read
    a = fopen("ListFilm.dat", "r");

    // Memasukkan data file ke variabel
    fscanf(a, "%s %s %s %s", &film[i].namaF, &film[i].sutradaraFK1, &film[i].genreFK1, &film[i].bioskopFK1);
    while (strcmp(film[i].namaF, "####") != 0)
    {
        i++;
        fscanf(a, "%s %s %s %s", &film[i].namaF, &film[i].sutradaraFK1, &film[i].genreFK1, &film[i].bioskopFK1);
    }

    // Menutup file
    fclose(a);

    // Meminta inputan data baru
    do
    {
        printf("\n(-) Masukkan Data Film\n    -> ");
        scanf("%s %s %s %s", &film[i].namaF, &film[i].sutradaraFK1, &film[i].genreFK1, &film[i].bioskopFK1);
        i++;
    } while (strcmp(film[i - 1].namaF, "####") != 0);

    // Banyak data
    banyakD[3] = i;

    // Membuka file dengan mode write sekaligus memasukkan value variabel ke dalam file
    a = fopen("ListFilm.dat", "w");
    for (i = 0; i < (banyakD[3] - 1); i++)
    {
        fprintf(a, "%s %s %s %s\n", film[i].namaF, film[i].sutradaraFK1, film[i].genreFK1, film[i].bioskopFK1);
    }

    // Menambahkan EOF dan menutup file
    fprintf(a, "#### #### #### ####");
    fclose(a);
}

// Void untuk menambah data genre
void sGenre(dataG gnr[])
{
    // Untuk menukar data pada sorting
    dataG temp;
    i = 0;

    // Membukan file dengan mode read
    a = fopen("Genre.dat", "r");

    // Memasukkan data file ke variabel
    fscanf(a, "%s %s", &gnr[i].genreFK2, &gnr[i].genreF);
    while (strcmp(gnr[i].genreFK2, "####") != 0)
    {
        i++;
        fscanf(a, "%s %s", &gnr[i].genreFK2, &gnr[i].genreF);
    }

    // Menutup file
    fclose(a);

    // Meminta inputan data baru
    do
    {
        printf("\n(-) Masukkan Data Genre\n    -> ");
        scanf("%s %s", &gnr[i].genreFK2, &gnr[i].genreF);
        i++;
    } while (strcmp(gnr[i - 1].genreFK2, "####") != 0);

    // Banyak data
    banyakD[0] = i;

    // Sorting, takutnya user masukinnya gak berurutan => karena akan menggunakan BinarySearch
    do
    {
        swap = 0;
        for (i = 0; i < (banyakD[0] - 2); i++)
        {
            if (strcmp(gnr[i].genreFK2, gnr[i + 1].genreFK2) == 1)
            {
                temp = gnr[i];
                gnr[i] = gnr[i + 1];
                gnr[i + 1] = temp;
                swap = 1;
            }
        }
    } while (swap == 1);

    // Membuka file dengan mode write sekaligus memasukkan value variabel ke dalam file
    a = fopen("Genre.dat", "w");
    for (i = 0; i < (banyakD[0] - 1); i++)
    {
        fprintf(a, "%s %s\n", gnr[i].genreFK2, gnr[i].genreF);
    }

    // Menambahkan EOF dan menutup file
    fprintf(a, "#### ####");
    fclose(a);
}

// Void untuk menambah data sutradara
void sSutradara(dataS std[])
{
    // Void untuk menambah data genre
    dataS temp;
    i = 0;

    // Membuka file dengan mode read
    a = fopen("Sutradara.dat", "r");

    // Memasukkan data file ke variabel
    fscanf(a, "%s %s", &std[i].sutradaraFK2, &std[i].sutradaraF);
    while (strcmp(std[i].sutradaraFK2, "####") != 0)
    {
        i++;
        fscanf(a, "%s %s", &std[i].sutradaraFK2, &std[i].sutradaraF);
    }

    // Menutup file
    fclose(a);

    // Meminta inputan data baru
    do
    {
        printf("\n(-) Masukkan Data Sutradara\n    -> ");
        scanf("%s %s", &std[i].sutradaraFK2, &std[i].sutradaraF);
        i++;
    } while (strcmp(std[i - 1].sutradaraFK2, "####") != 0);

    // Banyak data
    banyakD[0] = i;

    // Sorting, takutnya user masukinnya gak berurutan => karena akan menggunakan BinarySearch
    do
    {
        swap = 0;
        for (i = 0; i < (banyakD[0] - 2); i++)
        {
            if (strcmp(std[i].sutradaraFK2, std[i + 1].sutradaraFK2) == 1)
            {
                temp = std[i];
                std[i] = std[i + 1];
                std[i + 1] = temp;
                swap = 1;
            }
        }
    } while (swap == 1);

    // Membuka file dengan mode write sekaligus memasukkan value variabel ke dalam file
    a = fopen("Sutradara.dat", "w");
    for (i = 0; i < (banyakD[0] - 1); i++)
    {
        fprintf(a, "%s %s\n", std[i].sutradaraFK2, std[i].sutradaraF);
    }

    // Menambahkan EOF dan menutup file
    fprintf(a, "#### ####");
    fclose(a);
}

// Void untuk menambah data bioskop
void sBioskop(dataB bskp[])
{
    // Untuk menukar data pada sorting
    dataB temp;
    i = 0;

    // Membuka file dengan mode read
    a = fopen("Bioskop.dat", "r");

    // Memasukkan data file ke variabel
    fscanf(a, "%s %s", &bskp[i].bioskopFK2, &bskp[i].bioskopF);
    while (strcmp(bskp[i].bioskopFK2, "####") != 0)
    {
        i++;
        fscanf(a, "%s %s", &bskp[i].bioskopFK2, &bskp[i].bioskopF);
    }

    // Menutup file
    fclose(a);

    // Meminta inputan data baru
    do
    {
        printf("\n(-) Masukkan Data Bioskop\n    -> ");
        scanf("%s %s", &bskp[i].bioskopFK2, &bskp[i].bioskopF);
        i++;
    } while (strcmp(bskp[i - 1].bioskopFK2, "####") != 0);

    // Banyak data
    banyakD[0] = i;

    // Sorting, takutnya user masukinnya gak berurutan => karena akan menggunakan BinarySearch
    do
    {
        swap = 0;
        for (i = 0; i < (banyakD[0] - 2); i++)
        {
            if (strcmp(bskp[i].bioskopFK2, bskp[i + 1].bioskopFK2) == 1)
            {
                temp = bskp[i];
                bskp[i] = bskp[i + 1];
                bskp[i + 1] = temp;
                swap = 1;
            }
        }
    } while (swap == 1);

    // Membuka file dengan mode write sekaligus memasukkan value variabel ke dalam file
    a = fopen("Bioskop.dat", "w");
    for (i = 0; i < (banyakD[0] - 1); i++)
    {
        fprintf(a, "%s %s\n", bskp[i].bioskopFK2, bskp[i].bioskopF);
    }

    // Menambahkan EOF dan menutup file
    fprintf(a, "#### ####");
    fclose(a);
}

// Void untuk memberikan output berupa tabel List Film Final sekaligus memasukkan ke file-nya
void final(dataF film[], dataG gnr[], dataS std[], dataB bskp[])
{
    // Membuka file ListFilm.dat dengan mode read dan file ListFilmFinal.dat dengan mode write
    a = fopen("ListFilm.dat", "r");
    e = fopen("ListFilmFinal.dat", "w");

    // Buat nomor
    j = 1;

    // Output header tabel
    for (i = 0; i < 98; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("| No | Nama Film");
    for (i = 0; i < 21; i++)
    {
        printf(" ");
    }
    printf(" | Sutradara Film       | Genre Film      | Bioskop         |\n");
    for (i = 0; i < 98; i++)
    {
        printf("-");
    }

    // Memasukkan data file ke dalam variabel
    fscanf(a, "%s %s %s %s", &film[0].namaF, &film[0].sutradaraFK1, &film[0].genreFK1, &film[0].bioskopFK1);

    // While untuk memberikan output berupa data ListFilmFinal dalam bentuk tabel dan memasukkan data ke dalam file-nya
    while (strcmp(film[0].namaF, "####") != 0)
    {
        // Memasukkand data ke dalam file
        fprintf(e, "%s ", film[0].namaF);

        // Memberikan output nomor dan nama film
        printf("\n| ", j, film[0].namaF);
        if (j < 10)
        {
            printf("0");
        }
        printf("%d | %s", j, film[0].namaF);
        j++;
        for (i = 0; i < 30 - strlen(film[0].namaF); i++)
        {
            printf(" ");
        }
        printf(" | ");

        // Membuka file sutradara dengan mode read
        c = fopen("Sutradara.dat", "r");

        // Memasukkan data ke dalam variabel
        fscanf(c, "%s %s", &std[0].sutradaraFK2, &std[0].sutradaraF);
        while ((strcmp(film[0].sutradaraFK1, std[0].sutradaraFK2) != 0) && (strcmp(std[0].sutradaraFK2, "####") != 0))
        {
            fscanf(c, "%s %s", &std[0].sutradaraFK2, &std[0].sutradaraF);
        }

        // Memasukkan data ke dalam file dan memberikan output data file
        if (strcmp(film[0].sutradaraFK1, std[0].sutradaraFK2) == 0)
        {
            fprintf(e, "%s ", std[0].sutradaraF);
            printf("%s", std[0].sutradaraF);
        }
        else
        {
            fprintf(e, "tidakDitemukan ");
            printf("%s", std[0].sutradaraF);
        }
        for (i = 0; i < 20 - strlen(std[0].sutradaraF); i++)
        {
            printf(" ");
        }
        printf(" | ");

        // Menutup file sutradara.dat
        fclose(c);

        // Membuka file genre.dat dengan mode read
        b = fopen("Genre.dat", "r");

        // Memasukkan data file ke dalam variabel
        fscanf(b, "%s %s", &gnr[0].genreFK2, &gnr[0].genreF);
        while ((strcmp(film[0].genreFK1, gnr[0].genreFK2) != 0) && (strcmp(gnr[0].genreFK2, "####") != 0))
        {
            fscanf(c, "%s %s", &gnr[0].genreFK2, &gnr[0].genreF);
        }

        // Memasukkan data ke dalam file dan memberikan output data file
        if (strcmp(film[0].genreFK1, gnr[0].genreFK2) == 0)
        {
            fprintf(e, "%s ", gnr[0].genreF);
            printf("%s", gnr[0].genreF);
        }
        else
        {
            fprintf(e, "tidakDitemukan ");
            printf("%s", gnr[0].genreF);
        }
        for (i = 0; i < 15 - strlen(gnr[0].genreF); i++)
        {
            printf(" ");
        }
        printf(" | ");

        // Menutup file genre.dat
        fclose(b);

        // Membuka file bioskop.dat dengan mode read
        d = fopen("Bioskop.dat", "r");

        // Memasukkan data file ke dalam variabel
        fscanf(d, "%s %s", &bskp[0].bioskopFK2, &bskp[0].bioskopF);
        while ((strcmp(film[0].bioskopFK1, bskp[0].bioskopFK2) != 0) && (strcmp(bskp[0].bioskopFK2, "####") != 0))
        {
            fscanf(d, "%s %s", &bskp[0].bioskopFK2, &bskp[0].bioskopF);
        }

        // Memasukkan data ke dalam file dan memberikan output data file
        if (strcmp(film[0].bioskopFK1, bskp[0].bioskopFK2) == 0)
        {
            fprintf(e, "%s\n", bskp[0].bioskopF);
            printf("%s", bskp[0].bioskopF);
        }
        else
        {
            fprintf(e, "tidakDitemukan\n");
            printf("%s", bskp[0].bioskopF);
        }
        for (i = 0; i < 15 - strlen(bskp[0].bioskopF); i++)
        {
            printf(" ");
        }
        printf(" |\n");

        // Menutup file bioskop.dat
        fclose(d);

        // Merapihkan tabel
        for (i = 0; i < 98; i++)
        {
            printf("-");
        }

        // Memasukkan data file listfilm.dat ke dalam variabel
        fscanf(a, "%s %s %s %s", &film[0].namaF, &film[0].sutradaraFK1, &film[0].genreFK1, &film[0].bioskopFK1);
    }
    printf("\n");

    // Menambahkan EOF dan menutup file
    fprintf(e, "#### #### #### ####");
    fclose(e);
}

// Void untuk menghitung banyak data
void itung(dataS std[], dataG gnr[], dataB bskp[])
{
    // Membuka file sutradara.dat, genre.dat, bioskop.dat dengan mode read
    a = fopen("Sutradara.dat", "r");
    b = fopen("Genre.dat", "r");
    c = fopen("Bioskop.dat", "r");

    // Menghitung banyak data pada file sutradara.dat
    i = 0;
    fscanf(a, "%s %s", std[0].sutradaraFK2, std[0].sutradaraF);
    while (strcmp(std[i].sutradaraFK2, "####") != 0)
    {
        i++;
        fscanf(a, "%s %s", std[i].sutradaraFK2, std[i].sutradaraF);
    }
    banyakD[0] = i;

    // Menghitung banyak data pada file genre.dat
    i = 0;
    fscanf(b, "%s %s", gnr[0].genreFK2, gnr[0].genreF);
    while (strcmp(gnr[i].genreFK2, "####") != 0)
    {
        i++;
        fscanf(b, "%s %s", gnr[i].genreFK2, gnr[i].genreF);
    }
    banyakD[1] = i;

    // Menghitung banyak data pada file bioskop.dat
    i = 0;
    fscanf(c, "%s %s", bskp[0].bioskopFK2, bskp[0].bioskopF);
    while (strcmp(bskp[i].bioskopFK2, "####") != 0)
    {
        i++;
        fscanf(c, "%s %s", bskp[i].bioskopFK2, bskp[i].bioskopF);
    }
    banyakD[2] = i;

    // Menutup file
    fclose(a);
    fclose(b);
    fclose(c);
}

// Void untuk searching menggunakan Binary Search
void binSearch(dataS std[], dataG gnr[], dataB bskp[])
{
    i = 0;
    j = 0;
    k = 0;

    // Memberikan output data nama sutradara yang kodenya sama
    printf("\n(-) Hasil Pencarian\n    -> |");
    while ((i <= banyakD[0]) && (k == 0))
    {
        j = ((i + banyakD[0]) / 2);
        if (strcmp(std[j].sutradaraFK2, search[0]) == 0)
        {
            k = 1;
            printf(" %s | ", std[j].sutradaraF);
        }
        else
        {
            if (strcmp(std[j].sutradaraFK2, search[0]) == 1)
            {
                banyakD[0] = j - 1;
            }
            else
            {
                i = j + 1;
            }
        }
    }
    if (k == 0)
    {
        printf(" - | ");
    }

    i = 0;
    j = 0;
    k = 0;
    // Memberikan output data nama genre yang kodenya sama
    while ((i <= banyakD[1]) && (k == 0))
    {
        j = ((i + banyakD[1]) / 2);
        if (strcmp(gnr[j].genreFK2, search[1]) == 0)
        {
            k = 1;
            printf("%s | ", gnr[j].genreF);
        }
        else
        {
            if (strcmp(gnr[j].genreFK2, search[1]) == 1)
            {
                banyakD[1] = j - 1;
            }
            else
            {
                i = j + 1;
            }
        }
    }
    if (k == 0)
    {
        printf("- | ");
    }

    i = 0;
    j = 0;
    k = 0;
    // Memberikan output data nama bioskop yang kodenya sama
    while ((i <= banyakD[2]) && (k == 0))
    {
        j = ((i + banyakD[2]) / 2);
        if (strcmp(bskp[j].bioskopFK2, search[2]) == 0)
        {
            k = 1;
            printf("%s |\n", bskp[j].bioskopF);
        }
        else
        {
            if (strcmp(bskp[j].bioskopFK2, search[2]) == 1)
            {
                banyakD[2] = j - 1;
            }
            else
            {
                i = j + 1;
            }
        }
    }
    if (k == 0)
    {
        printf("- |\n");
    }
}