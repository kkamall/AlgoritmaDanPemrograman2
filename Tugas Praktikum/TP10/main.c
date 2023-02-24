/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP10 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "mesinkata.h"

int main()
{
    int a, b, c, pendek, menengah, panjang;
    int i, j, k;
    /*
        (1) a, b, c = buat indeks sekaligus masukan user berupa panjang maksimal (a dan b)
        (2) pendek, menengah = panjang maksimal kata
        (3) panjang = panjang ckata
    */

    // Meminta panjang maksimal
    scanf("%d %d", &a, &b);

    // Mencari panjang pendek dan menengah maksimal kata
    pendek = PENDEK(a, b);
    menengah = MENENGAH(a, b);

    // Set ke 0 buat jadi indeks
    c = 0;
    a = 0;
    b = 0;

    char pita[105], kpendek[50][50], kmenengah[50][50], kpanjang[50][50];
    /*
        (1) pita = pita masukkan user
        (2) kpendek, kmenengah, kpanjang = berisi kata sesuai dengan panjang kata
    */

    // Meminta masukkan berupa pita
    scanf(" %104[^\n]s", &pita);

    // Memulai pembacaan kalimat
    STARTKATA(pita);
    // While membaca kata hingga menemukan EOP '.'
    while (EOPKATA(pita) == 0)
    {
        // Set panjang CKATA
        panjang = PANJANGKATA();

        // Proses pengelompokkan kata
        if (panjang <= pendek)
        {
            strcpy(kpendek[a], GETKATA(pita));
            a++;
        }
        else if ((panjang > pendek) && (panjang <= menengah))
        {
            strcpy(kmenengah[b], GETKATA(pita));
            b++;
        }
        else if (panjang > menengah)
        {
            strcpy(kpanjang[c], GETKATA(pita));
            c++;
        }

        // Mengambil kata selanjutnya
        INCKATA(pita);
    }

    // Pegambilan kata terakhir
    if (PANJANGKATA() > 0)
    {
        // Set panjang CKATA
        panjang = PANJANGKATA();

        // Pengelompokkan kata
        if (panjang <= pendek)
        {
            strcpy(kpendek[a], GETKATA(pita));
            a++;
        }
        else if ((panjang > pendek) && (panjang <= menengah))
        {
            strcpy(kmenengah[b], GETKATA(pita));
            b++;
        }
        else if (panjang > menengah)
        {
            strcpy(kpanjang[c], GETKATA(pita));
            c++;
        }
    }

    // Sorting kelompok kata
    SORT(kpendek, a);
    SORT(kmenengah, b);
    SORT(kpanjang, c);

    // Output sesuai dengan kelompok katanya
    printf("KATA PENDEK\n");
    if (kpendek[0][0] == '\0')
    {
        printf("TIDAK ADA.\n");
    }
    else
    {
        for (i = 0; i < a; i++)
        {
            printf("- %s\n", kpendek[i]);
        }
    }

    printf("\nKATA MENENGAH\n");
    if (kmenengah[0][0] == '\0')
    {
        printf("TIDAK ADA.\n");
    }
    else
    {
        for (i = 0; i < b; i++)
        {
            printf("- %s\n", kmenengah[i]);
        }
    }

    printf("\nKATA PANJANG\n");
    if (kpanjang[0][0] == '\0')
    {
        printf("TIDAK ADA.\n");
    }
    else
    {
        for (i = 0; i < c; i++)
        {
            printf("- %s\n", kpanjang[i]);
        }
    }

    // Mengembalikkan nilai 0, dalam arti program telah selesai
    return 0;
}