/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP4 Alpro 2 C1 2021 - SFN21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int n;
    /*
        (1) n = banyaknya film
    */

    // Meminta inputan berupa nilai n
    scanf("%d", &n);
    // Pemanggilan typedef struct
    jenis film[n];

    // Looping untu meminta inputan berupa judul film, genre film, dan rating film
    for(i=0; i<n; i++)
    {
        scanf("%s %s %f", &film[i].judul, &film[i].genre, &film[i].rating);
    }

    char patokan[7], metode[10], tipe[5];
    /*
        (1) patokan = patokan yang dijadikan pengurutan (judul/rating)
        (2) metode = metode yang digunakan untuk sorting
        (3) tipe = tipe dari urutannya (ascending/descending)
    */

    // Meminta inputan user berupa patokan, metode, dan tipe
    scanf("%s %s %s", &patokan, &metode, &tipe);

    // Pemanggilan prosedur
    output(metode, n, film, patokan, tipe);
    
    return 0;
}