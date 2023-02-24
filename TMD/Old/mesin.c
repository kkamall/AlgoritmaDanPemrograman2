#include "header.h"

void start(char query[])
{
    idx = 0;
    wlen = 0;

    while (query[idx] == ' ')
    {
        idx++;
    }

    while ((query[idx] != ' ') && (eop(query) == 0))
    {
        cw[wlen] = query[idx];
        idx++;
        wlen++;
    }

    cw[wlen] = '\0';
}

void reset()
{
    wlen = 0;
    cw[wlen] = '\0';
}

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

void inc(char query[])
{
    wlen = 0;

    while (query[idx] == ' ')
    {
        idx++;
    }

    while ((query[idx] != ' ') && (eop(query) == 0))
    {
        cw[wlen] = query[idx];
        idx++;
        wlen++;
    }

    cw[wlen] = '\0';
}

int getlen()
{
    return wlen;
}

char *getcw()
{
    return cw;
}

int compare(char word1[], char word2[])
{
    int i = 0, flag = 0, panjang = 0;
    char huruf1, huruf2;

    while (word1[i] != '\0' || word2[i] != '\0')
    {
        huruf1 = word1[i];
        huruf2 = word2[i];
        if (word1[i] >= 97)
        {
            huruf1 -= 32;
        }
        if (word2[i] >= 97)
        {
            huruf2 -= 32;
        }
        if (huruf1 == huruf2)
        {
            flag++;
        }
        i++;
        panjang++;
    }

    if (flag == panjang)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void salin(char word[][50], int index)
{
    int i;

    for (i = 0; i < getlen(); i++)
    {
        word[index][i] = cw[i];
    }
    word[index][i] = '\0';
}

void copy(char word3[][4][100], int n, int m, char word4[][50])
{
    int i = 0;

    while (word4[m][i] != '\0')
    {
        word3[n][m][i] = word4[m][i];
        i++;
    }
    word3[n][m][i] = '\0';
}

void explode()
{
    // Memasukkan Query ke Variabel
    if (tanda == 0)
    {
        if ((compare(cw, "ENTRI") == 1))
        {
            salin(queryAwal, bquery);
            bquery++;
        }
        else if ((compare(cw, "UBAH") == 1))
        {
            salin(queryAwal, bquery);
            bquery++;
        }
        else if ((compare(cw, "HAPUS") == 1))
        {
            salin(queryAwal, bquery);
            bquery++;
        }
        else if ((compare(cw, "TAMPIL") == 1))
        {
            salin(queryAwal, bquery);
            bquery++;
        }
        else
        {
            tanda++;
        }
    }

    // Memasukkan Nama Tabel ke Variabel
    if ((tanda == 1) && ((compare(cw, "tgame") == 1) || (compare(cw, "tdeveloper") == 1)))
    {
        salin(tabel, idxtabel);
        btabel++;
    }
    else if ((tanda == 1) && ((compare(cw, "tgame") == 0) || (compare(cw, "tdeveloper") == 0)))
    {
        tanda++;
    }

    // Memasukkan Value ke Variabel
    if (tanda >= 2)
    {
        salin(value, idxvalue);
        idxvalue++;
        bvalue++;
    }
}

void panjang(char value[][4][100], int n, int panjang[][3], int palingPanjang[])
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            panjang[i][j] = 0;
            k = 0;
            while (value[i][j][k] != '\0')
            {
                k++;
                panjang[i][j]++;
            }
            if (panjang[i][j] > palingPanjang[j])
            {
                palingPanjang[j] = panjang[i][j];
            }
        }
    }
}

int hitung(char value[100])
{
    int i = 0, j = 0, k;

    while (value != '\0')
    {
        j++;
    }

    return j;
}

void jalan()
{
    FILE *file;
    char tampungValue[100][4][100];
    int i, j, k, l, n, panjangKata[100][3] = {0}, palingPanjang[3] = {0}, flag;

    if (bquery > 0 && bquery < 3)
    {
        flag = 0;
        i = 0;

        if (btabel == 0)
        {
            printf("\n[ ERROR ] => Tabel Tidak Ditemukan!!!\n");
            flag = 2;
        }
        else if ((btabel > 1) && (compare(queryAwal[0], "TAMPIL") == 0) && (compare(queryAwal[1], "TAMPIL") == 0))
        {
            printf("\n[ ERROR ] => Pilih Salah Satu Tabel!!!\n");
            flag = 2;
        }
        else if ((bvalue > 3) && (compare(queryAwal[0], "TAMPIL") == 0) && (compare(queryAwal[1], "TAMPIL") == 0))
        {
            printf("\n[ ERROR ] => Value Atribut Lebih Dari 3!!!\n");
            flag = 2;
        }
        else if ((bvalue < 3) && (compare(queryAwal[0], "TAMPIL") == 0) && (compare(queryAwal[1], "TAMPIL") == 0))
        {
            printf("\n[ ERROR ] => Value Atribut Kurang Dari 3!!!\n");
            flag = 2;
        }

        while (flag == 0 && i != bquery)
        {
            n = 0;
            tanda = 0;
            if (compare(tabel[0], "tgame") == 1)
            {
                file = fopen("tgame.dat", "r");
            }
            else
            {
                file = fopen("tdeveloper.dat", "r");
            }
            fscanf(file, "%s %s %s", tampungValue[n][0], tampungValue[n][1], tampungValue[n][2]);

            if ((compare(queryAwal[i], "ENTRI") == 1))
            {
                if (compare(tampungValue[n][0], value[0]) == 1)
                {
                    tanda = 1;
                }

                while (compare(tampungValue[n][0], "####") == 0)
                {
                    n++;
                    fscanf(file, "%s %s %s", tampungValue[n][0], tampungValue[n][1], tampungValue[n][2]);
                    if (compare(tampungValue[n][0], value[0]) == 1)
                    {
                        tanda = 1;
                    }
                }
                fclose(file);

                if (compare(tabel[0], "tgame") == 1)
                {
                    file = fopen("tgame.dat", "w");
                }
                else
                {
                    file = fopen("tdeveloper.dat", "w");
                }
                if (tanda == 0)
                {
                    for (j = 0; j < n; j++)
                    {
                        fprintf(file, "%s %s %s\n", tampungValue[j][0], tampungValue[j][1], tampungValue[j][2]);
                    }
                    fprintf(file, "%s %s %s\n", value[0], value[1], value[2]);
                    flag = 1;
                }
                else if ((tanda == 1))
                {
                    for (j = 0; j < n; j++)
                    {
                        fprintf(file, "%s %s %s\n", tampungValue[j][0], tampungValue[j][1], tampungValue[j][2]);
                    }
                    if (bquery == 1)
                    {
                        printf("\n[ ERROR ] => Data Sudah Tersedia!!!\n");
                    }
                }

                fprintf(file, "#### #### ####\n");
                fclose(file);
            }
            else if ((compare(queryAwal[i], "UBAH") == 1))
            {
                if (compare(tampungValue[n][0], value[0]) == 1)
                {
                    copy(tampungValue, n, 1, value);
                    copy(tampungValue, n, 2, value);
                    tanda = 1;
                }

                while (compare(tampungValue[n][0], "####") == 0)
                {
                    n++;
                    fscanf(file, "%s %s %s", tampungValue[n][0], tampungValue[n][1], tampungValue[n][2]);
                    if (compare(tampungValue[n][0], value[0]) == 1)
                    {
                        copy(tampungValue, n, 1, value);
                        copy(tampungValue, n, 2, value);
                        tanda = 1;
                    }
                }
                fclose(file);

                if (compare(tabel[0], "tgame") == 1)
                {
                    file = fopen("tgame.dat", "w");
                }
                else
                {
                    file = fopen("tdeveloper.dat", "w");
                }

                if (tanda == 1)
                {
                    for (j = 0; j < n; j++)
                    {
                        fprintf(file, "%s %s %s\n", tampungValue[j][0], tampungValue[j][1], tampungValue[j][2]);
                    }
                    flag = 1;
                }
                else if ((tanda == 0))
                {
                    for (j = 0; j < n; j++)
                    {
                        fprintf(file, "%s %s %s\n", tampungValue[j][0], tampungValue[j][1], tampungValue[j][2]);
                    }
                    if (bquery == 1)
                    {
                        printf("\n[ ERROR ] => Data Tidak Tersedia!!!\n");
                    }
                }
                fprintf(file, "#### #### ####\n");
                fclose(file);
            }
            else if ((compare(queryAwal[i], "HAPUS") == 1))
            {
                if (compare(tampungValue[n][0], value[0]) == 1)
                {
                    tanda = 1;
                }

                while (compare(tampungValue[n][0], "####") == 0)
                {
                    if (tanda != 1)
                    {
                        n++;
                    }
                    else
                    {
                        tanda++;
                    }
                    fscanf(file, "%s %s %s", tampungValue[n][0], tampungValue[n][1], tampungValue[n][2]);
                    if (compare(tampungValue[n][0], value[0]) == 1)
                    {
                        tanda = 1;
                    }
                }
                fclose(file);

                if (compare(tabel[0], "tgame") == 1)
                {
                    file = fopen("tgame.dat", "w");
                }
                else
                {
                    file = fopen("tdeveloper.dat", "w");
                }

                if (tanda == 1)
                {
                    for (j = 0; j < n; j++)
                    {
                        fprintf(file, "%s %s %s\n", tampungValue[j][0], tampungValue[j][1], tampungValue[j][2]);
                    }
                    flag = 1;
                }
                else if ((tanda != 1))
                {
                    for (j = 0; j < n; j++)
                    {
                        fprintf(file, "%s %s %s\n", tampungValue[j][0], tampungValue[j][1], tampungValue[j][2]);
                    }
                    if (bquery == 1)
                    {
                        printf("\n[ ERROR ] => Data Tidak Tersedia!!!\n");
                    }
                }
                fprintf(file, "#### #### ####\n");
                fclose(file);
            }
            else if (compare(queryAwal[i], "TAMPIL") == 1)
            {
                while (compare(tampungValue[n][0], "####") == 0)
                {
                    n++;
                    fscanf(file, "%s %s %s", tampungValue[n][0], tampungValue[n][1], tampungValue[n][2]);
                }
                fclose(file);

                if (btabel == 2)
                {
                    int x, y, join[6];
                    for (l = 0; l < btabel; l++)
                    {
                        n = 0;
                        FILE *file;
                        if (l == 0)
                        {
                            file = fopen("tgame.dat", "r");
                            y = 0;
                        }
                        else
                        {
                            file = fopen("tdeveloper.dat", "r");
                            y = 3;
                        }
                        fscanf(file, "%s %s %s", tampungValue[n][0], tampungValue[n][1], tampungValue[n][2]);

                        while (compare(tampungValue[n][0], "####") == 0)
                        {
                            n++;
                            fscanf(file, "%s %s %s", tampungValue[n][0], tampungValue[n][1], tampungValue[n][2]);
                        }
                        fclose(file);
                        int palingPanjang[3] = {0};

                        panjang(tampungValue, n, panjangKata, palingPanjang);

                        for (x = 0; x < 3; x++)
                        {
                            join[x + y] = palingPanjang[x];
                            printf("%d ", join[x + y]);
                        }
                    }
                }

                panjang(tampungValue, n, panjangKata, palingPanjang);

                // Mengeluarkan Output Tabel
                if (compare(tabel[0], "tgame") == 1)
                {
                    outputGame(panjangKata, tampungValue, n, palingPanjang);
                }
                else
                {
                    outputDev(panjangKata, tampungValue, n, palingPanjang);
                }

                flag = 1;
            }
            i++;
        }

        if (compare(queryAwal[i - 1], "TAMPIL") == 0 && flag == 1)
        {
            if (bquery > 1)
            {
                printf("\nQuery yang Dijalankan => [ %s ]\n", queryAwal[i - 1]);
            }
            else
            {
                printf("\nQuery Berhasil Dijalankan.\n");
            }

            printf("\n");
            printf("[ Data yang Di-%s ]\n", queryAwal[i - 1]);
            if (compare(tabel[0], "tgame") == 1)
            {
                printf("-) Nama Game      => %s\n-) Harga Game     => %s\n-) Nama Developer => %s\n", value[0], value[1], value[2]);
            }
            else
            {
                printf("-) Nama Developer => %s\n-) Tahun Berdiri  => %s\n-) Kota Pusat     => %s\n", value[0], value[1], value[2]);
            }
        }
        else if (flag == 0 && bquery != 1)
        {
            printf("\n[ ERROR ] => Tidak Ada Query yang Dijalankan!!!\n");
        }
    }
    else if (bquery > 2)
    {
        printf("\n[ ERROR ] => Query yang Dimasukkan harus 1 - 2 query!!!\n");
    }
    else if (bquery == 0)
    {
        printf("\n[ ERROR ] => Query yang Dimasukkan Tidak Sesuai!!!\n");
    }

    // Set Variabel Global ke-0 Untuk Query Selanjutnya
    bquery = 0;
    bvalue = 0;
    btabel = 0;
    idxtabel = 0;
    idxvalue = 0;
    tanda = 0;
}

void outputGame(int panjangKata[][3], char value[][4][100], int n, int palingPanjang[])
{
    int j, k;

    printf("\nQuery yang Dijalankan => [ TAMPIL ]\n\n");

    printf("+-");
    for (j = 0; j < palingPanjang[0]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[1]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[2]; j++)
    {
        printf("-");
    }
    printf("-+\n");

    printf("| Nama Games");
    for (j = 0; j < palingPanjang[0] - 10; j++)
    {
        printf(" ");
    }
    printf(" | Harga");
    for (j = 0; j < palingPanjang[1] - 5; j++)
    {
        printf(" ");
    }
    printf(" | Developer");
    for (j = 0; j < palingPanjang[2] - 9; j++)
    {
        printf(" ");
    }
    printf(" |\n");

    printf("+-");
    for (j = 0; j < palingPanjang[0]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[1]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[2]; j++)
    {
        printf("-");
    }
    printf("-+\n");

    for (j = 0; j < n; j++)
    {
        printf("| %s ", value[j][0]);
        for (k = 0; k < palingPanjang[0] - panjangKata[j][0]; k++)
        {
            printf(" ");
        }
        printf("| %s ", value[j][1]);
        for (k = 0; k < palingPanjang[1] - panjangKata[j][1]; k++)
        {
            printf(" ");
        }
        printf("| %s", value[j][2]);
        for (k = 0; k < palingPanjang[2] - panjangKata[j][2]; k++)
        {
            printf(" ");
        }
        printf(" |\n");

        printf("+-");
        for (k = 0; k < palingPanjang[0]; k++)
        {
            printf("-");
        }
        printf("-+-");
        for (k = 0; k < palingPanjang[1]; k++)
        {
            printf("-");
        }
        printf("-+-");
        for (k = 0; k < palingPanjang[2]; k++)
        {
            printf("-");
        }
        printf("-+\n");
    }
}

void outputDev(int panjangKata[][3], char value[][4][100], int n, int palingPanjang[])
{
    int j, k;

    printf("\nQuery yang Dijalankan => [ TAMPIL ]\n\n");

    printf("+-");
    for (j = 0; j < palingPanjang[0]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[1] + 1; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[2]; j++)
    {
        printf("-");
    }
    printf("-+\n");

    printf("| Nama Developer");
    for (j = 0; j < palingPanjang[0] - 14; j++)
    {
        printf(" ");
    }
    printf(" | Tahun");
    for (j = 0; j < palingPanjang[1] - 5; j++)
    {
        printf(" ");
    }
    printf(" | Pusat");
    for (j = 0; j < palingPanjang[2] - 5; j++)
    {
        printf(" ");
    }
    printf(" |\n");

    printf("+-");
    for (j = 0; j < palingPanjang[0]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[1] + 1; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[2]; j++)
    {
        printf("-");
    }
    printf("-+\n");

    for (j = 0; j < n; j++)
    {
        printf("| %s ", value[j][0]);
        for (k = 0; k < palingPanjang[0] - panjangKata[j][0]; k++)
        {
            printf(" ");
        }
        printf("| %s ", value[j][1]);
        for (k = 0; k < palingPanjang[1] - panjangKata[j][1] + 1; k++)
        {
            printf(" ");
        }
        printf("| %s", value[j][2]);
        for (k = 0; k < palingPanjang[2] - panjangKata[j][2]; k++)
        {
            printf(" ");
        }
        printf(" |\n");

        printf("+-");
        for (k = 0; k < palingPanjang[0]; k++)
        {
            printf("-");
        }
        printf("-+-");
        for (k = 0; k < palingPanjang[1] + 1; k++)
        {
            printf("-");
        }
        printf("-+-");
        for (k = 0; k < palingPanjang[2]; k++)
        {
            printf("-");
        }
        printf("-+\n");
    }
}

void outputDuaTabel(int panjangKata[][3], char value[][4][100], int n, int palingPanjang[])
{
    int j, k;

    printf("\nQuery yang Dijalankan => [ TAMPIL ]\n\n");

    // Output Games
    printf("+-");
    for (j = 0; j < palingPanjang[0]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[1]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[2]; j++)
    {
        printf("-");
    }

    // Output Developer
    printf("-+-");
    for (j = 0; j < palingPanjang[4] + 1; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[5]; j++)
    {
        printf("-");
    }
    printf("-+\n");

    // Output Games
    printf("| Nama Games");
    for (j = 0; j < palingPanjang[0] - 10; j++)
    {
        printf(" ");
    }
    printf(" | Harga");
    for (j = 0; j < palingPanjang[1] - 5; j++)
    {
        printf(" ");
    }
    printf(" | Developer");
    for (j = 0; j < palingPanjang[2] - 9; j++)
    {
        printf(" ");
    }

    // Output Developer
    printf(" | Tahun");
    for (j = 0; j < palingPanjang[4] - 5; j++)
    {
        printf(" ");
    }
    printf(" | Pusat");
    for (j = 0; j < palingPanjang[5] - 5; j++)
    {
        printf(" ");
    }
    printf(" |\n");

    // Output Games
    printf("+-");
    for (j = 0; j < palingPanjang[0]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[1]; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[2]; j++)
    {
        printf("-");
    }

    // Output Developer
    printf("-+-");
    for (j = 0; j < palingPanjang[4] + 1; j++)
    {
        printf("-");
    }
    printf("-+-");
    for (j = 0; j < palingPanjang[5]; j++)
    {
        printf("-");
    }
    printf("-+\n");

    for (j = 0; j < n; j++)
    {
        printf("| %s ", value[j][0]);
        for (k = 0; k < palingPanjang[0] - panjangKata[j][0]; k++)
        {
            printf(" ");
        }
        printf("| %s ", value[j][1]);
        for (k = 0; k < palingPanjang[1] - panjangKata[j][1]; k++)
        {
            printf(" ");
        }
        printf("| %s", value[j][2]);
        for (k = 0; k < palingPanjang[2] - panjangKata[j][2]; k++)
        {
            printf(" ");
        }
        printf(" |\n");

        printf("+-");
        for (k = 0; k < palingPanjang[0]; k++)
        {
            printf("-");
        }
        printf("-+-");
        for (k = 0; k < palingPanjang[1]; k++)
        {
            printf("-");
        }
        printf("-+-");
        for (k = 0; k < palingPanjang[2]; k++)
        {
            printf("-");
        }
        printf("-+\n");
    }
}