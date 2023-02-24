/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP1 Alpro 2 C1 2021 - MPM22
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk mengubah matriks sesuai dengan aturan yang ada
void ubah(int a, char b[a], int n, int m, char matriksa[n*m][m*n], char matriks[n*m][m*n])
{
    int y, z, tanda1=0, tukar, tanda2=0, cek=0;
    char matrikscopy1[n*m][m*n];
    /*
        (1) y, z = sebagai indeks array
        (2) tanda1, tanda2 = sebagai tanda apakah baris dan kolom matriks >/<
        (3) cek = untuk mengecek kesamaan matriks
        (4) matrikscopy1 = membantu dalam transformasi matriks
    */

    // Fungsi pengulangan untuk mentransformasi matriks
    for(i=0; i<a; i++)
    {
        // Mengcopy isi matriksa ke matrikscopy1
        for(j=0; j<n; j++)
        {
            for(k=0; k<m; k++)
            {
                matrikscopy1[j][k] = matriksa[j][k];
            }
        }y=0;

        // Transformasi jika kodenya A
        if(b[i] == 'A')
        {
            // Looping transformasi matriks sekaligus memberikan keluaran
            for(j=n-1; j>=0; j--)
            {
                z=0;
                for(k=0; k<m; k++)
                {
                    // Transformasi matriks
                    matriksa[y][z]=matrikscopy1[j][k];
                    // If untuk memberikan output
                    if(i==a-1)
                    {
                        printf("%c", matriksa[y][z]);
                        if(k<m-1)
                        {
                            printf(" ");
                        }
                    }
                    z++;
                }
                // If untuk memberikan newline
                if(i==a-1)
                {
                    printf("\n");
                }
                y++;
            }
        }y=0;

        // Transformasi jika kodenya B
        if(b[i] == 'B')
        {
            for(j=0; j<m; j++)
            {
                z=0;
                for(k=n-1; k>=0; k--)
                {
                    // Transformasi matriks
                    matriksa[y][z]=matrikscopy1[k][j];
                    // If untuk memberikan output
                    if(i==a-1)
                    {
                        printf("%c", matriksa[y][z]);
                        if(k!=0)
                        {
                            printf(" ");
                        }
                    }
                    z++;
                }
                // If untuk memberikan newline
                if(i==a-1)
                {
                    printf("\n");
                }
                y++;
            }
            tanda1++;
        }y=0;

        // Transformasi jika kodenya C
        if(b[i] == 'C')
        {
            for(j=m-1; j>=0; j--)
            {
                z=0;
                for(k=0; k<n; k++)
                {
                    // Transformasi matriks
                    matriksa[y][z]=matrikscopy1[k][j];
                    // If untuk memberikan output
                    if(i==a-1)
                    {
                        printf("%c", matriksa[y][z]);
                        if(k<n-1)
                        {
                            printf(" ");
                        }
                    }
                    z++;
                }
                // If untuk memberikan newline
                if(i==a-1)
                {
                    printf("\n");
                }
                y++;
            }
            tanda1++;
        }y=0;

        // Transformasi jika kodenya D
        if(b[i] == 'D')
        {
            for(j=0; j<m; j++)
            {
                z=0;
                for(k=0; k<n; k++)
                {
                    // Transformasi matriks
                    matriksa[y][z]=matrikscopy1[k][j];
                    // If untuk memberikan output
                    if(i==a-1)
                    {
                        printf("%c", matriksa[y][z]);
                        if(k<n-1)
                        {
                            printf(" ");
                        }
                    }
                    z++;
                }
                // If untuk memberikan newline
                if(i==a-1)
                {
                    printf("\n");
                }
                y++;
            }
            tanda1++;
        }

        // If untuk menukar nilai n dan m untuk indeks array
        if(tanda1>tanda2)
        {
            tukar = n;
            n = m;
            m = tukar;
        }tanda2=tanda1;
    }

    // If dengan kondisi baris x kolom matriks sama dengan yang awal
    if(tanda1%2==0)
    {
        // Looping untuk mengecek kesamaan nilai matriks
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(matriks[i][j]==matriksa[i][j])
                {
                    cek++;
                }
            }
        }
        // If dengan kondisi posisi nilai matriks sama semua
        if(cek==n*m)
        {
            printf("Main lagi besok!\n");
        }
        // If dengan kondisi posisi nilai matriks beda semua
        else
        {
            printf("Keren! Ayo kita main lagi!\n");
        }
    }

    // If dengan kondisi baris x kolom matriks beda dengan yang awal
    else
    {
        printf("Keren! Ayo kita main lagi!\n");
    }
}