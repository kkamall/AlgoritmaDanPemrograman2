/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP10 Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "mesinkata.h"

// Prosedur untuk memulai membaca kalimat
void STARTKATA(char pita[])
{
    // Set ke awal
    indeks = 0;
    panjangkata = 0;

    // While untuk nge-skip spasi
    while (pita[indeks] == ' ')
    {
        indeks++;
    }
    // While membaca kata dan menyimpannya ke var ckata sekaligus menhitung panjang ckata
    while ((pita[indeks] != ';') && (pita[indeks] != '.'))
    {
        ckata[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }
    // Menajadikan string
    ckata[panjangkata] = '\0';
}

// Prosedur untuk mereset ckata
void RESETKATA()
{
    // Set ke awal
    panjangkata = 0;
    // Menghapus ckata
    ckata[panjangkata] = '\0';
}

// Prosedur untuk membaca kata berikutnya
void INCKATA(char pita[])
{
    // Set ke awal
    panjangkata = 0;

    // While untuk nge-skip spasi
    while (pita[indeks] == ' ' || pita[indeks] == ';')
    {
        indeks++;
    }
    // While membaca kata dan menyimpannya ke var ckata sekaligus menhitung panjang ckata
    while ((pita[indeks] != ';') && (pita[indeks] != '.'))
    {
        ckata[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }
    // Menajadikan string
    ckata[panjangkata] = '\0';
}

// Fungsi untuk mengambil kata
char *GETKATA()
{
    return ckata;
}

// Fungsi untuk mengambil panjang ckata
int PANJANGKATA()
{
    return panjangkata;
}

// Fungsi untuk mengecek EOP pada kalimat
int EOPKATA(char pita[])
{
    if (pita[indeks] == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Fungsi untuk mencari nilai panjang menengah maksimal
int MENENGAH(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Fungsi untuk mencari nilai panjang pendek maksimal
int PENDEK(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Prosedur untuk melakukan sorting
void SORT(char pita[][50], int x)
{
    int i, j, k;
    char temp[50];
    /*
        (1) i, j = untuk indeks
        (2) k = minindeks
        (3) temp = tempat penyimpanan string sementara
    */

    // For untuk proses sorting
    for (i = 0; i < x - 1; i++)
    {
        // Set minindeks
        k = i;
        for (j = i + 1; j < x; j++)
        {
            // Mebandingkan string
            if (strcmp(pita[k], pita[j]) == 1)
            {
                k = j;
            }
        }

        // Proses pertukaran
        strcpy(temp, pita[i]);
        strcpy(pita[i], pita[k]);
        strcpy(pita[k], temp);
    }
}