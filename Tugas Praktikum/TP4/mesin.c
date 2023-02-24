/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP4 Alpro 2 C1 2021 - SFN21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk melakukan sorting sekaligus mengeluarkan output
void output(char metode[10], int n, jenis film[n], char patokan[7], char tipe[5])
{
    // Pemanggilan typedef struct untuk menjadi kotak menyimpan nilai sementara
    jenis temp;

    // If dengan kondisi metode masukan user adalah insertion
    if(strcmp(metode, "insertion") == 0)
    {
        // Loop untuk sorting
        for(i=1; i<n; i++)
        {
            temp = film[i];
            j = i-1;

            // If dengan kondisi tipe masukan user adalah ascending
            if(strcmp(tipe, "asc") == 0)
            {
                // If dengan kondisi patokan sorting masukan user adalah judul
                if(strcmp(patokan, "judul") == 0)
                {
                    // While untuk melakukan pertukaran nilai
                    while((j>=0) && (strcmp(temp.judul, film[j].judul) == -1))
                    {
                        film[j+1] = film[j];
                        j--;
                    }
                }
                // If dengan kondisi patokan sorting masukan user adalah rating
                else
                {
                    // While untuk melakukan pertukaran nilai
                    while((j>=0) && (temp.rating < film[j].rating))
                    {
                        film[j+1] = film[j];
                        j--;
                    }
                }
            }
            // If dengan kondisi tipe masukan user adalah descending
            else
            {
                // If dengan kondisi patokan sorting masukan user adalah judul
                if(strcmp(patokan, "judul") == 0)
                {
                    // While untuk melakukan pertukaran nilai
                    while((j>=0) && (strcmp(temp.judul, film[j].judul) == 1))
                    {
                        film[j+1] = film[j];
                        j--;
                    }
                }
                // If dengan kondisi patokan sorting masukan user adalah rating
                else
                {
                    // While untuk melakukan pertukaran nilai
                    while((j>=0) && (temp.rating > film[j].rating))
                    {
                        film[j+1] = film[j];
                        j--;
                    }
                }
            }
            film[j+1] = temp;
        }
    }
    // if dengan kondisi metode masukan user adalah selection
    else
    {
        // Looping untuk melakukan sorting
        for(i=0; i<n-1; i++)
        {
            k=i;
            // If dengan kondisi tipe masukan user adalah ascending
            if(strcmp(tipe, "asc") == 0)
            {
                // If dengan kondisi patokan sorting masukan user adalah judul
                if(strcmp(patokan, "judul") == 0)
                {
                    // Loop untuk mencari indeks dengan judul yang paling kecil huruf yang dibandingkannya *judulnya yang belum disorting
                    for(j=i+1; j<n; j++)
                    {
                        // If dengan kondisi huruf yang dibandingkan antara judul dengan indeks k > judul dengan indeks j
                        if(strcmp(film[k].judul, film[j].judul) == 1)
                        {
                            k=j;
                        }
                    }
                }
                // If dengan kondisi patokan sorting masukan user adalah rating
                else
                {
                    // Loop untuk mencari indeks dengan judul yang paling kecil huruf yang dibandingkannya *judulnya yang belum disorting
                    for(j=i+1; j<n; j++)
                    {
                        // If dengan kondisi huruf yang dibandingkan antara judul dengan indeks k > judul dengan indeks j
                        if(film[k].rating>film[j].rating)
                        {
                            k=j;
                        }
                    }
                }
            }
            // If dengan kondisi tipe masukan user adalah descending
            else
            {
                // If dengan kondisi patokan sorting masukan user adalah judul
                if(strcmp(patokan, "judul") == 0)
                {
                    // Loop untuk mencari indeks dengan judul yang paling kecil huruf yang dibandingkannya *judulnya yang belum disorting
                    for(j=i+1; j<n; j++)
                    {
                        // If dengan kondisi huruf yang dibandingkan antara judul dengan indeks k > judul dengan indeks j
                        if(strcmp(film[k].judul, film[j].judul) == -1)
                        {
                            k=j;
                        }
                    }
                }
                // If dengan kondisi patokan sorting masukan user adalah rating
                else
                {
                    // Loop untuk mencari indeks dengan judul yang paling kecil huruf yang dibandingkannya *judulnya yang belum disorting
                    for(j=i+1; j<n; j++)
                    {
                        // If dengan kondisi huruf yang dibandingkan antara judul dengan indeks k > judul dengan indeks j
                        if(film[k].rating<film[j].rating)
                        {
                            k=j;
                        }
                    }
                }
            }
            // Proses pertukaran nilai
            temp = film[i];
            film[i] = film[k];
            film[k] = temp;
        }
    }

    // Integer berisi string judul dan genre paling panjang
    int terbanyak[2] = {strlen(film[0].judul), strlen(film[0].genre)};
    // Looping untuk menentukan string judul dan genre paling panjang
    for(i=1; i<n; i++)
    {
        if(terbanyak[0]<strlen(film[i].judul))
        {
            terbanyak[0] = strlen(film[i].judul);
        }
        if(terbanyak[1]<strlen(film[i].genre))
        {
            terbanyak[1] = strlen(film[i].genre);
        }
    }

    // Pengeluaran output
    printf("Daftar Film Terurut :\n");

    // Looping untuk ngeprint batas/"="
    for(i=0; i<terbanyak[0]+terbanyak[1]+7; i++)
    {
        printf("=");
    }printf("\n");

    // Looping untuk memberikan output berupa judul film, genre film, dan rating film
    for(i=0; i<n; i++)
    {
        printf("%s  ", film[i].judul);
        for(j=0; j<terbanyak[0]-strlen(film[i].judul); j++)
        {
            printf(" ");
        }
        printf("%s  ", film[i].genre);
        for(j=0; j<terbanyak[1]-strlen(film[i].genre); j++)
        {
            printf(" ");
        }
        printf("%.1f\n", film[i].rating);
    }

    // Looping untuk ngeprint batas/"="
    for(i=0; i<terbanyak[0]+terbanyak[1]+7; i++)
    {
        printf("=");
    }printf("\n");
}