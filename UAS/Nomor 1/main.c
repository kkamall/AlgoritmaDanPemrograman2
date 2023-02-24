/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS [MSKAR22K] Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int panjang, flag = 0, banyak = 0, pk = 0;
    char kata;
    char pita[502];
    /*
        (1) panjang = panjang kata yang dicek
        (2) flag = tanda ada karakter yang dicari
        (3) banyak = banyak kata yang terdapat karakter yang dicari
        (4) pk = panjang kata
        (5) kata = karakter yang dicari
        (6) pita = pita
    */

    // Meminta masukkan user berupa panjang kata dan karakter yang dicari dan pita
    scanf("%d %c %501[^\n]s", &panjang, &kata, &pita);

    // Memulai pembacaan per-karakter
    start(pita);
    pk++;
    // Mengecek kesamaan dengan karakter yang dicari
    if (getcc() == kata)
    {
        flag = 1;
    }

    // Melanjutkan pembacaan karakter hingga menemukan EOP
    while (eop() == 0)
    {
        while ((eop() == 0) && (pk < panjang))
        {
            // Melanjutkan pembacaan karakter
            inc(pita);

            // Menghindari spasi
            if (getcc() == ' ')
            {
                spasi(pita);
            }
            // Mengecek kesamaan dengan karakter yang dicari
            if (getcc() == kata)
            {
                flag = 1;
            }
            // Menghindari penambahan panjang kata saat menemukan EOP
            if (eop() == 0)
            {
                pk++;
            }
        }
        // Kelompok kata melalui syarat yang ada
        if (flag == 1 && pk == panjang)
        {
            banyak++;
        }
        pk = 0;
        flag = 0;
    }

    // Memberikan output berupa banyak kata yang dapat melalui syarat yang ada
    printf("%d\n", banyak);

    return 0;
}