// Link dengan file header.h
#include "header.h"

// Prosedur untuk memulai pembacaan string
void start(char word[])
{
    idx = 0;
    wlen = 0;

    // While untuk melewati spasi
    while (word[idx] == ' ')
    {
        idx++;
    }

    // While untuk memasukkan kata ke dalam variabel cw(current word)
    while ((word[idx] != ' ') && (eop(word) == 0))
    {
        cw[wlen] = word[idx];
        idx++;
        wlen++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    cw[wlen] = '\0';
}

// Prosedur untuk mereset current word
void reset()
{
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk mengecek EOP
int eop(char query[])
{
    if (query[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk membaca kata selanjutnya
void inc(char query[])
{
    // Set ke-0
    wlen = 0;

    // While untuk melewati spasi
    while (query[idx] == ' ')
    {
        idx++;
    }

    // While untuk Memasukkan kata ke variabel cw
    while ((query[idx] != ' ') && (eop(query) == 0))
    {
        cw[wlen] = query[idx];
        idx++;
        wlen++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    cw[wlen] = '\0';
}

// Fungsi untuk mendapatkan panjang kata yang sedang dibaca
int getlen()
{
    return wlen;
}

// Fungsi untuk mendapatkan current word
char *getcw()
{
    return cw;
}

void prosedur(int i, char pita[])
{
    int a;
    if (strcmp(getcw(), "INSERT") == 0)
    {
        for (a = 0; a < 3; a++)
        {
            inc(pita);
            strcpy(barang[banyakdata][a], getcw());
        }
        banyakdata++;
    }
    else
    {
        inc(pita);
        if (strcmp(getcw(), "NAMA") == 0)
        {
            inc(pita);
            for (a = 0; a < banyakdata; a++)
            {
                if (strcmp(barang[a][0], getcw()) == 0)
                {
                    inc(pita);
                    barang[a][0][0] = '\0';
                    strcpy(barang[a][0], getcw());
                }
            }
        }
        else if (strcmp(getcw(), "HARGA") == 0)
        {
            inc(pita);
            for (a = 0; a < banyakdata; a++)
            {
                if (strcmp(barang[a][0], getcw()) == 0)
                {
                    inc(pita);
                    barang[a][0][1] = '\0';
                    strcpy(barang[a][1], getcw());
                }
            }
        }
        else if (strcmp(getcw(), "STATUS") == 0)
        {
            inc(pita);
            for (a = 0; a < banyakdata; a++)
            {
                if (strcmp(barang[a][0], getcw()) == 0)
                {
                    inc(pita);
                    barang[a][0][2] = '\0';
                    strcpy(barang[a][2], getcw());
                }
            }
        }
    }
}

void cariterpanjang(int i)
{
    int a, b;
    terpanjang[0] = 6;
    terpanjang[1] = 5;
    terpanjang[2] = 6;

    for (b = 0; b < 3; b++)
    {
        for (a = 0; a < banyakdata; a++)
        {
            if (terpanjang[b] < strlen(barang[a][b]))
            {
                terpanjang[b] = strlen(barang[a][b]);
            }
        }
    }
}

void output(int i)
{
    cariterpanjang(banyakdata);
    int a, b;
    printf("=");
    for (a = 0; a < terpanjang[0] + terpanjang[1] + terpanjang[2] + 8; a++)
    {
        printf("=");
    }
    printf("=\n");
    printf("| BARANG ");
    for (a = 0; a < terpanjang[0] - 6; a++)
    {
        printf(" ");
    }
    printf("| HARGA ");
    for (a = 0; a < terpanjang[1] - 5; a++)
    {
        printf(" ");
    }
    printf("| STATUS ");
    for (a = 0; a < terpanjang[2] - 6; a++)
    {
        printf(" ");
    }
    printf("|\n");
    printf("=");
    for (a = 0; a < terpanjang[0] + terpanjang[1] + terpanjang[2] + 8; a++)
    {
        printf("=");
    }
    printf("=\n");
    for (a = 0; a < banyakdata; a++)
    {
        printf("| %s ", barang[a][0]);
        for (b = 0; b < terpanjang[0] - strlen(barang[a][0]); b++)
        {
            printf(" ");
        }
        printf("| %s ", barang[a][1]);
        for (b = 0; b < terpanjang[1] - strlen(barang[a][1]); b++)
        {
            printf(" ");
        }
        printf("| %s ", barang[a][2]);
        for (b = 0; b < terpanjang[2] - strlen(barang[a][2]); b++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    printf("=");
    for (a = 0; a < terpanjang[0] + terpanjang[1] + terpanjang[2] + 8; a++)
    {
        printf("=");
    }
    printf("=\n%d data ditampilkan.\n", i);
}