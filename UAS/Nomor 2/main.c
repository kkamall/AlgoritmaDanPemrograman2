/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS [MSKAT22K] Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int index = 0, k;
    char kata[502];
    char pita[502];
    char valid[500][502];
    /*
        (1) k = buat index for
        (2) kata = kelompok kata yang dicari
        (3) pita = pita masukan user
        (4) valid = berisi kata-kata yang ada kelompok kata yang di-input user
    */

    // [ Memminta inputan user ]
    // Kelompok kata yang dicari
    scanf(" %501[^\n]s", &kata);
    // Pita
    scanf(" %501[^\n]s", &pita);

    // Memulai pembacaan dan pengecekan kelompok kata masukkan user
    if (start(pita, kata) == 1)
    {
        // Kelompok kata ada => string di masukkan ke dalam variabel valid
        copykata(valid, index);
        index++;
    }

    // While untuk pembacaan kata selanjutnya hingga menemukan EOP
    while (eop(pita) == 0)
    {
        // Pembacaan kata selanjutnya dan pengecekan kelompok kata masukkan user
        if (inc(pita, kata) == 1)
        {
            // Kelompok kata ada => string di masukkan ke dalam variabel valid
            copykata(valid, index);
            index++;
        }
    }

    // Memberikan output ke user berupa kata yang terdapat kelompok kata yang dicari
    for (k = 0; k < index; k++)
    {
        printf("%s\n", valid[k]);
    }

    // Tanda program selesai
    return 0;
}