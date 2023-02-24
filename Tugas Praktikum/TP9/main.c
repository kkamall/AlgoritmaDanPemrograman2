/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP9 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    char pita1[1000];
    char x, y, z;
    char pita2[1000];
    int idx = 1;
    /*
        (1) pita1 = berisi string masukan user
        (2) x, y, z = berisi CC
        (3) pita 2 = berisi string yang sudah diberi spasi
        (4) idx = buat index pita 2
    */

    // Meminta inputan user
    scanf("%s", &pita1);

    // Memulai pembacaan string
    START(pita1);
    // Memasukkan CC ke pita2
    pita2[0] = GETCC();
    // Proses increment dan pemasukan CC ke var x, y, z
    INC(pita1);
    x = GETCC();
    INC(pita1);
    y = GETCC();
    INC(pita1);
    z = GETCC();

    // While untuk memberi spasi
    while (EOP(x) == 0)
    {
        pita2[idx] = x;
        idx++;
        // Kondisi dimana menunjukkan adanya kata baru dan harus diberi spasi
        if (((x >= 97 && x <= 122) && (y >= 65 && y <= 90)) || ((z >= 97 && z <= 122) && (y >= 65 && y <= 90) && (x >= 65 && x <= 90)))
        {
            pita2[idx] = ' ';
            idx++;
        }
        // Proses increment
        x = y;
        y = z;
        INC(pita1);
        z = GETCC();
    }

    // Mengeluarkan output
    printf("%s\n", pita2);

    return 0;
}