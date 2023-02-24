/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS [MSKAT22K] Alpro 2 C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Fungsi untuk mulai membaca kalimat
int start(char str[], char kata[])
{
    int i, j;
    /*
        (1) i = buat index for
        (2) j = tanda adanya kesamaan kelompok kata
    */

    // Set ke-0
    idx = 0;
    pk = 0;
    flag = 0;

    // Menghindari spasi
    while (str[idx] == ' ')
    {
        idx++;
    }

    // While untuk memasukkan karakter ke Curren Word hingga menemukan spasi | EOP
    while (str[idx] != ' ' && eop(str) == 0)
    {
        // Set ke-0
        j = 0;

        // For untuk mengecek kesamaan dengan kelompok kata yang dicari
        for (i = 0; i < itungkata(kata); i++)
        {
            if (str[idx + i] == kata[i])
            {
                j++;
            }
        }

        // Kelompok kata ada
        if (j == itungkata(kata))
        {
            flag = 1;
        }

        // Masukkin karakter ke var Current Word
        cw[pk] = str[idx];
        idx++;
        pk++;
    }
    // Menjadikan sebuah string
    cw[pk] = '\0';

    // Mengembalikan nilai flag
    return flag;
}

// Prosedur untuk mereset kata
void reset()
{
    // Set ke-0
    pk = 0;
    // Hapus string
    cw[pk] = '\0';
}

// Fungsi untuk mengecek EOP
int eop(char str[])
{
    // EOP ketemu
    if (str[idx] == '$')
    {
        return 1;
    }
    // EOP gak ketemu
    else
    {
        return 0;
    }
}

// Fungsi untuk melanjutkan pembacaan kalimat ke kata berikutnya
int inc(char str[], char kata[])
{
    int i, j;
    /*
        (1) i = buat index for
        (2) j = tanda adanya kesamaan kelompok kata
    */

    // Set ke-0
    pk = 0;
    flag = 0;

    // Menghindari spasi
    while (str[idx] == ' ')
    {
        idx++;
    }

    // While untuk memasukkan karakter ke Curren Word hingga menemukan spasi | EOP
    while (str[idx] != ' ' && str[idx] != '$')
    {
        // Set ke-0
        j = 0;

        // For untuk mengecek kesamaan dengan kelompok kata yang dicari
        for (i = 0; i < itungkata(kata); i++)
        {
            if (str[idx + i] == kata[i])
            {
                j++;
            }
        }

        // Kelompok kata ada
        if (j == itungkata(kata))
        {
            flag = 1;
        }

        // Masukkin karakter ke var Current Word
        cw[pk] = str[idx];
        idx++;
        pk++;
    }
    // Menjadikan sebuah string
    cw[pk] = '\0';

    // Mengembalikan nilai flag
    return flag;
}

// Fungsi untuk mendapatkan panjang Current Word
int getlen()
{
    return pk;
}

// Fungsi untuk mendapatkan Current Word
char *getcw()
{
    return cw;
}

int itungkata(char kata[])
{
    int i = 0;
    klen = 0;
    // Mengitung banyak kata hingga menemukan '\0'
    while (kata[i] != '\0')
    {
        i++;
        klen++;
    }

    // Mengembalikan klen
    return klen;
}

void copykata(char valid[][502], int index)
{
    int i;

    // Proses copy kata
    for (i = 0; i < getlen(); i++)
    {
        valid[index][i] = cw[i];
    }
}