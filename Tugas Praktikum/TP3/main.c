/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP3 Alpro 2 C1 2021 - VBB121
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int n;
    /*
        (1) n = banyaknya pencarian
    */
    scanf("%d", &n);
    // Pemanggilan prosedur
    virus v[n];

    // Looping untuk minta inputan
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d", &v[i].nilai[0], &v[i].nilai[1], &v[i].x);
    }

    // Looping untuk memberikan keluaran dari fungsi "cek"
    for(i=0; i<n; i++)
    {
        int k1=-1, k2=0, k3=1;
        /*
            (1) k1, k2, k3 = buat ngurangin index sama jadiin basis
        */
        printf("%d\n", cek(k1, k2, k3, v));
    }

    return 0;
}