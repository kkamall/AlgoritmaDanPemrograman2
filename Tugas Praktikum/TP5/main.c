/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP5 Alpro 2 C1 2021 - SFNL21
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Fungsi main
int main()
{
    int n;
    // Meminta inputan user berupa nilai n
    scanf("%d", &n);
    char metode, urutan;
    x film[n+2];
    /*
        (1) n = berisi banyak film dan durasi inputan user
        (2) metode = metode yang digunakan untuk sorting
        (3) urutan = urutan filmnya (ascending/descending)
        (4) film = buat judul, jam, menit, dan totmenit sebanyak n
    */

    // Looping untuk meminta inputan user berupa judul film, durasi film, metode, dan urutan
    for(i=0; i<n; i++)
    {
        scanf("%s %d %d", &film[i].judul, &film[i].jam, &film[i].menit);
    }scanf(" %c %c", &metode, &urutan);

    // Looping untuk memanggil fungsi dan menambah dan memasukkan nilai dari fungsi menambah ke variabel film
    for(i=0; i<n+2; i++)
    {
        film[i].totmenit = menambah(n, film);
    }

    // Memanggil prosedur output untuk mengeluarkan output
    output(n, film, metode, urutan);
    
    return 0;
}