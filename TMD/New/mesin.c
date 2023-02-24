/*
Saya Muhammad Kamal Robbani mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// Link dengan file header.h
#include "header.h"

// Prosedur untuk memulai pembacaan string
void start(char word[])
{
    int i;

    // Set Nilai ke-0 dan string kosong
    for (i = 0; i < 4; i++)
    {
        query[i][0] = '\0';
    }
    for (i = 0; i < 3; i++)
    {
        tabel[i][0] = '\0';
    }
    for (i = 0; i < 4; i++)
    {
        value[i][0] = '\0';
    }
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

    // Persiapan untuk prosedur exploade
    a = 0;
    b = 0;
    c = 0;
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

// Fungsi untuk melakukan compare antar string
int compare(char word1[], char word2[])
{
    int i = 0, flag = 0, panjangkata = 0;
    char huruf1, huruf2;
    /*
        (1) i = untuk indeks
        (2) flag = banyak kata yang sama
        (3) panjangkata = panjang kata kata terpanjang
        (4) huruf 1, huruf 2 = untuk menghindari error
    */

    // While yang digunakan untuk membandingkan kata
    while (word1[i] != '\0' || word2[i] != '\0')
    {
        // Proses menghindari error
        huruf1 = word1[i];
        huruf2 = word2[i];

        // Pemaksaan huruf menjadi kapital
        if (word1[i] >= 97)
        {
            huruf1 -= 32;
        }
        if (word2[i] >= 97)
        {
            huruf2 -= 32;
        }
        // Proses pembandingan
        if (huruf1 == huruf2)
        {
            flag++;
        }
        // Iterasi
        panjangkata++;
        i++;
    }

    // Membandingkan panjang flag dengan panjangkata
    if (panjangkata == flag)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk mencopy kata (word 2 -> word 1)
void copykata(char word1[], char word2[])
{
    // Variabel untuk indeks
    int i = 0;

    // While untuk mencopy kata
    while (word2[i] != '\0')
    {
        word1[i] = word2[i];
        i++;
    }

    // Penambahan '\0' agar menjadi sebuah string
    word1[i] = '\0';
}

// Fungsi untuk menghitung panjang kata
int panjangkata(char word[])
{
    // (1) i = untuk indeks, (2) panjang = panjang kata
    int i = 0, panjang = 0;

    // While untuk meghitung panjang kata
    while (word[i] != '\0')
    {
        if (word[i] != ';')
        {
            panjang++;
        }
        i++;
    }

    return panjang;
}

// Prosedur untuk mengambil record data
void ambildata()
{
    // Set ke-0
    int i = 0;
    banyakrecord[0] = 0;
    banyakrecord[1] = 0;

    // Deklarasi file
    FILE *file;
    file = fopen("tgame.dat", "r");

    // Memindahkan record ke variabel
    fscanf(file, "%s %s %s", game[i].value[0], game[i].value[1], game[i].value[2]);

    // While untuk memindahkan record ke variabel
    while (compare(game[i].value[0], "####") == 0)
    {
        i++;
        banyakrecord[0]++;
        fscanf(file, "%s %s %s", game[i].value[0], game[i].value[1], game[i].value[2]);
    }
    // Menutup file
    fclose(file);

    // Set ke-0
    i = 0;

    // Deklarasi file
    file = fopen("tdeveloper.dat", "r");

    // Menindahkan record ke variabel
    fscanf(file, "%s %s %s", developer[i].value[0], developer[i].value[1], developer[i].value[2]);

    // While untuk memindahkan record ke variabel
    while (compare(developer[i].value[0], "####") == 0)
    {
        i++;
        banyakrecord[1]++;
        fscanf(file, "%s %s %s", developer[i].value[0], developer[i].value[1], developer[i].value[2]);
    }
    // Menutup File
    fclose(file);
}

// Prosedur untuk memecah pita masukkan user
void explode(char word1[])
{
    int tanda = 0;
    // Proses pemecahan pita;
    while (tanda == 0)
    {
        // Kata masuk ke dalam kategori query
        if ((compare(getcw(), "ENTRI") == 1) || (compare(getcw(), "UBAH") == 1) || (compare(getcw(), "HAPUS") == 1) || (compare(getcw(), "TAMPIL") == 1))
        {
            copykata(query[a], getcw());
            a++;
        }
        // Kata masuk ke dalam kategori tabel
        else if ((compare(getcw(), "tgame") == 1) || (compare(getcw(), "tdeveloper") == 1))
        {
            copykata(tabel[b], getcw());
            b++;
        }
        // Kata masuk ke dalam kategori value
        else
        {
            copykata(value[c], getcw());
            c++;
        }
        tanda = 1;
    }
}

// Fungsi untuk mengecek error
int cek(char word[])
{
    // Pita tidak diakhiri dengan DELIMITER
    if (word[panjangkata(word)] != ';')
    {
        printf("\n[ ERROR ] -> Query tidak terdapat delimiter ';'\n");
        return 1;
    }
    // Jika query tidak ada atau query lebih dari dua
    else if ((query[0][0] == '\0') || (query[2][0] != '\0'))
    {
        printf("\n[ ERROR ] -> Query yang dimasukkan harus 1 - 2 query!\n");
        return 1;
    }
    // User tidak memasukkan tabel atau user memasukkan tabel yang tidak dibuat
    else if (tabel[0][0] == '\0')
    {
        printf("\n[ ERROR ] -> Tabel tidak tersedia!\n");
        return 1;
    }
    // Jika user memasukkan lebih dari 2 tabel
    else if ((tabel[2][0] != '\0') && (((compare(query[0], "TAMPIL") == 1) || (compare(query[1], "TAMPIL") == 1))))
    {
        printf("\n[ ERROR ] -> Tabel yang dimasukkan maksimal 2!\n");
        return 1;
    }
    // Jika query bukan "TAMPIL" tapi user memasukkan 0 atau lebih dari 1 tabel
    else if (((tabel[0][0] == '\0') || (tabel[1][0] != '\0')) && (compare(query[0], "TAMPIL") == 0) && (compare(query[1], "TAMPIL") == 0))
    {
        printf("\n[ ERROR ] -> Tabel yang dimasukkan harus 1!\n");
        return 1;
    }
    // Query "TAMPIL" dan "HAPUS" hanya bisa menjadi solo
    else if (((compare(query[0], "HAPUS") == 1) || (compare(query[1], "HAPUS") == 1) || (compare(query[0], "TAMPIL") == 1) || (compare(query[1], "TAMPIL") == 1)) && (query[1][0] != '\0'))
    {
        printf("\n[ ERROR ] -> Query 'HAPUS' | 'TAMPIL' hanya bisa digunakan sendiri!\n");
        return 1;
    }
    // Jika query masukkannya "HAPUS" tapi valuenya tidak 1
    else if (((value[0][0] == '\0') || (value[1][0] != '\0')) && (compare(query[0], "HAPUS") == 1))
    {
        printf("\n[ ERROR ] -> Value yang dimasukkan harus 1 (Primary Key)!\n");
        return 1;
    }
    // Jika query masukannya "TAMPIL" dan user memasukkan value
    else if ((compare(query[0], "TAMPIL") == 1) && (value[0][0] != '\0'))
    {
        printf("\n[ ERROR ] -> Tidak boleh ada value yang dimasukkan!\n");
        return 1;
    }
    // Jika query yang digunakan bukan "TAMPIL" atau "HAPUS" tetapi value yang dimasukkan tidak 3
    else if (((compare(query[0], "TAMPIL") == 0) && (compare(query[1], "TAMPIL") == 0) && (compare(query[1], "HAPUS") == 0) && (compare(query[0], "HAPUS") == 0)) && ((value[2][0] == '\0') || (value[3][0] != '\0')))
    {
        printf("\n[ ERROR ] -> Value yang dimasukkan harus 3!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk mencari kata terpanjang
void carikataterpanjang()
{
    // Variabel untuk indeks
    int i, j;

    // Set kata terpanjang pertama sepanjang judul tabel
    kataterpanjang[0][0] = 9;
    kataterpanjang[0][1] = 10;
    kataterpanjang[0][2] = 9;

    // Proses pencarian kata terpanjang
    for (i = 0; i < banyakrecord[0]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (kataterpanjang[0][j] < panjangkata(game[i].value[j]))
            {
                kataterpanjang[0][j] = panjangkata(game[i].value[j]);
            }
        }
    }

    // Set kata terpanjang pertama sepanjang judul tabel
    kataterpanjang[1][0] = 9;
    kataterpanjang[1][1] = 13;
    kataterpanjang[1][2] = 12;

    // Proses pencarian kata terpanjang
    for (i = 0; i < banyakrecord[1]; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (kataterpanjang[1][j] < panjangkata(developer[i].value[j]))
            {
                kataterpanjang[1][j] = panjangkata(developer[i].value[j]);
            }
        }
    }
}

// Query entri (memasukkan data ke tabel atau file)
int entri()
{
    // (1) i, j = untuk indeks | (2) flag = tanda ada atau tidaknya record yang dimasukkan
    int i, j, flag = 0;

    // Deklarasi File
    FILE *file;
    // Jika user memasukkan tabel tgame
    if (compare(tabel[0], "tgame") == 1)
    {
        file = fopen("tgame.dat", "w");

        // Mengecek Ketersediaan Data
        for (i = 0; i < banyakrecord[0]; i++)
        {
            if (compare(value[0], game[i].value[0]) == 1)
            {
                flag = 1;
            }
        }

        // Mengecek Ketersediaan Foreign Key
        if (flag == 0)
        {
            i = 0;
            while (flag != 2 && i < banyakrecord[1])
            {
                if (compare(value[2], developer[i].value[0]) == 1)
                {
                    flag = 2;
                }
                i++;
            }
        }

        // Valid (foreign key ada dan primary key belum tersedia)
        if (flag == 2)
        {
            // Proses pemasukkan data
            for (i = 0; i < banyakrecord[0]; i++)
            {
                fprintf(file, "%s %s %s\n", game[i].value[0], game[i].value[1], game[i].value[2]);
            }
            fprintf(file, "%s %s %s\n", value[0], value[1], value[2]);
            printf("\n[ VALID ] -> Data berhasil dimasukkan!\n\n[ DATA YANG DIMASUKKAN ]\n-) Nama Game  => %s\n-) Harga Game => %s\n-) Developer  => %s\n", value[0], value[1], value[2]);
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 1;
        }
        // Data yang ingin dimasukkan sudah tersedia
        else if (flag == 1)
        {
            // Mengecek apakah query yang dimasukkan hanya satu
            if (query[1][0] == '\0')
            {
                printf("\n[ ERROR ] -> Data telah tersedia!\n");
            }
            // Memasukkan data sebelumnya ke tabel/file
            for (i = 0; i < banyakrecord[0]; i++)
            {
                fprintf(file, "%s %s %s\n", game[i].value[0], game[i].value[1], game[i].value[2]);
            }
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 0;
        }
        // Foreign key tidak tersedia
        else
        {
            // Mengecek apakah query yang dimasukkan hanya satu
            if (query[1][0] == '\0')
            {
                printf("\n[ ERROR ] -> Foreign key tidak tersedia!\n");
            }
            // Memasukkan data sebelumnya ke tabel/file
            for (i = 0; i < banyakrecord[0]; i++)
            {
                fprintf(file, "%s %s %s\n", game[i].value[0], game[i].value[1], game[i].value[2]);
            }
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 0;
        }
    }
    // Jika user memasukkan tabel tdeveloper
    else
    {
        file = fopen("tdeveloper.dat", "w");

        // Mengecek Ketersediaan Data
        for (i = 0; i < banyakrecord[1]; i++)
        {
            if (compare(value[0], developer[i].value[0]) == 1)
            {
                flag = 1;
            }
        }

        // Valid (primary key belum tersedia)
        if (flag == 0)
        {
            // Proses pemasukkan data
            for (i = 0; i < banyakrecord[1]; i++)
            {
                fprintf(file, "%s %s %s\n", developer[i].value[0], developer[i].value[1], developer[i].value[2]);
            }
            fprintf(file, "%s %s %s\n", value[0], value[1], value[2]);
            printf("\n[ VALID ] -> Data berhasil dimasukkan!\n\n[ DATA YANG DIMASUKKAN ]\n-) Nama Developer => %s\n-) Tahun Dibentuk => %s\n-) Kantor Pusat   => %s\n", value[0], value[1], value[2]);
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 1;
        }
        // Data yang ingin dimasukkan sudah tersedia
        else
        {
            // Mengecek apakah query yang dimasukkan hanya satu
            if (query[1][0] == '\0')
            {
                printf("\n[ ERROR ] -> Data telah tersedia!\n");
            }
            // Memasukkan data sebelumnya ke tabel/file
            for (i = 0; i < banyakrecord[1]; i++)
            {
                fprintf(file, "%s %s %s\n", developer[i].value[0], developer[i].value[1], developer[i].value[2]);
            }
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 0;
        }
    }
}

// Query ubah (mengubah record data dalam tabel atau file)
int ubah()
{
    // (1) i, j = untuk indeks | (2) flag = tanda ada atau tidaknya record yang diubah
    int i, j, flag = 1;

    // Deklarasi File
    FILE *file;
    // Jika user memasukkan tabel tgame
    if (compare(tabel[0], "tgame") == 1)
    {
        file = fopen("tgame.dat", "w");

        // Mengecek Ketersediaan Data
        for (i = 0; i < banyakrecord[0]; i++)
        {
            if (compare(value[0], game[i].value[0]) == 1)
            {
                flag = 0;
                j = i;
            }
        }

        // Mengecek Ketersediaan Foreign Key
        if (flag == 0)
        {
            i = 0;
            while (flag != 2 && i < banyakrecord[1])
            {
                // Proses penimpaan nilai masukkan user dengan nilai yang ada sebelumnya
                if (compare(value[2], developer[i].value[0]) == 1)
                {
                    copykata(game[j].value[0], value[0]);
                    copykata(game[j].value[1], value[1]);
                    copykata(game[j].value[2], value[2]);
                    flag = 2;
                }
                i++;
            }
        }

        // Valid (foreign key ada dan primary key tersedia)
        if (flag == 2)
        {
            // Proses pemasukkan data
            for (i = 0; i < banyakrecord[0]; i++)
            {
                fprintf(file, "%s %s %s\n", game[i].value[0], game[i].value[1], game[i].value[2]);
            }
            printf("\n[ VALID ] -> Data berhasil di-update!\n\n[ DATA YANG DI-UPDATE ]\n-) Nama Game  => %s\n-) Harga Game => %s\n-) Developer  => %s\n", value[0], value[1], value[2]);
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 1;
        }
        // Data yang ingin dimasukkan tidak tersedia
        else if (flag == 1)
        {
            // Mengecek apakah query yang dimasukkan hanya satu
            if (query[1][0] == '\0')
            {
                printf("\n[ ERROR ] -> Data tidak tersedia!\n");
            }
            // Memasukkan data sebelumnya ke tabel/file
            for (i = 0; i < banyakrecord[0]; i++)
            {
                fprintf(file, "%s %s %s\n", game[i].value[0], game[i].value[1], game[i].value[2]);
            }
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 0;
        }
        else
        {

            // Mengecek apakah query yang dimasukkan hanya satu
            if (query[1][0] == '\0')
            {
                printf("\n[ ERROR ] -> Foreign key tidak tersedia!\n");
            }
            // Memasukkan data sebelumnya ke tabel/file
            for (i = 0; i < banyakrecord[0]; i++)
            {
                fprintf(file, "%s %s %s\n", game[i].value[0], game[i].value[1], game[i].value[2]);
            }
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 0;
        }
    }
    // Jika user memasukkan tabel tdeveloper
    else
    {
        file = fopen("tdeveloper.dat", "w");

        // Mengecek Ketersediaan Data
        for (i = 0; i < banyakrecord[1]; i++)
        {
            // Proses penimpaan nilai masukkan user dengan nilai yang ada sebelumnya
            if (compare(value[0], developer[i].value[0]) == 1)
            {
                copykata(developer[i].value[0], value[0]);
                copykata(developer[i].value[1], value[1]);
                copykata(developer[i].value[2], value[2]);
                flag = 0;
            }
        }

        // Valid (primary key tersedia)
        if (flag == 0)
        {
            // Proses pemasukkan data
            for (i = 0; i < banyakrecord[1]; i++)
            {
                fprintf(file, "%s %s %s\n", developer[i].value[0], developer[i].value[1], developer[i].value[2]);
            }
            printf("\n[ VALID ] -> Data berhasil di-update!\n\n[ DATA YANG DI-UPDATE ]\n-) Nama Developer => %s\n-) Tahun Dibentuk => %s\n-) Kantor Pusat   => %s\n", value[0], value[1], value[2]);
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            fclose(file);
            return 1;
        }
        else
        {
            // Mengecek apakah query yang dimasukkan hanya satu
            if (query[1][0] == '\0')
            {
                printf("\n[ ERROR ] -> Data tidak tersedia!\n");
            }
            // Memasukkan data sebelumnya ke tabel/file
            for (i = 0; i < banyakrecord[1]; i++)
            {
                fprintf(file, "%s %s %s\n", developer[i].value[0], developer[i].value[1], developer[i].value[2]);
            }
            // Penambahan EOF
            fprintf(file, "#### #### ####\n");
            // Menutup file
            fclose(file);
            return 0;
        }
    }
}

// Query hapus (menghapus record data di tabel)
int hapus()
{
    // (1) i, j = untuk indeks | (2) flag = tanda ada atau tidaknya record yang dihapus
    int i, j, flag = 1;

    // Deklarasi File
    FILE *file;
    // Jika user memasukkan tabel tgame
    if (compare(tabel[0], "tgame") == 1)
    {
        file = fopen("tgame.dat", "w");

        // Mengecek Ketersediaan Data
        for (i = 0; i < banyakrecord[0]; i++)
        {
            if (compare(value[0], game[i].value[0]) == 1)
            {
                flag = 0;
                j = i;
            }
        }

        // Valid (primary key tersedia)
        if (flag == 0)
        {
            // Proses pemasukkan data
            for (i = 0; i < banyakrecord[0]; i++)
            {
                // Proses pelewatan fprintf pada data yang ingin dihapus
                if (i == j)
                {
                    i++;
                }
                fprintf(file, "%s %s %s\n", game[i].value[0], game[i].value[1], game[i].value[2]);
            }
            printf("\n[ VALID ] -> Data berhasil dihapus!\n\n[ DATA YANG DIHAPUS ]\n-) Nama Game  => %s\n-) Harga Game => %s\n-) Developer  => %s\n", game[j].value[0], game[j].value[1], game[j].value[2]);
            fclose(file);
            return 1;
        }
        // Unvalid (primary key tidak tersedia)
        else if (flag == 1)
        {
            // Proses pemasukkan data
            printf("\n[ ERROR ] -> Data tidak tersedia!\n");
            for (i = 0; i < banyakrecord[0]; i++)
            {
                fprintf(file, "%s %s %s\n", game[i].value[0], game[i].value[1], game[i].value[2]);
            }
            fprintf(file, "#### #### ####\n");
            fclose(file);
            return 0;
        }
    }
    // Jika user memasukkan tabel tdeveloper
    else
    {
        file = fopen("tdeveloper.dat", "w");

        // Mengecek Ketersediaan Data
        for (i = 0; i < banyakrecord[1]; i++)
        {
            if (compare(value[0], developer[i].value[0]) == 1)
            {
                j = i;
                flag = 0;
            }
        }

        // Valid (primary key tersedia)
        if (flag == 0)
        {
            // Proses pemasukkan data
            for (i = 0; i < banyakrecord[1]; i++)
            {
                // Proses pelewatan fprintf pada data yang ingin dihapus
                if (i == j)
                {
                    i++;
                }
                fprintf(file, "%s %s %s\n", developer[i].value[0], developer[i].value[1], developer[i].value[2]);
            }
            printf("\n[ VALID ] -> Data berhasil dihapus!\n\n[ DATA YANG DIHAPUS ]\n-) Nama Developer => %s\n-) Tahun Dibentuk => %s\n-) Kantor Pusat   => %s\n", developer[j].value[0], developer[j].value[1], developer[j].value[2]);
            fclose(file);
            return 1;
        }
        // Unvalid (primary key tidak tersedia)
        else
        {
            // Proses pemasukkan data
            printf("\n[ ERROR ] -> Data tidak tersedia!\n");
            for (i = 0; i < banyakrecord[1]; i++)
            {
                fprintf(file, "%s %s %s\n", developer[i].value[0], developer[i].value[1], developer[i].value[2]);
            }
            fprintf(file, "#### #### ####\n");
            fclose(file);
            return 0;
        }
    }
}

// Query tampil (Menampilkan tabel)
int tampil()
{
    // Untuk indeks
    int i, j, k, l;

    // If dengan kondisi user memasukkan tabel tgame saja
    if ((compare(tabel[0], "tgame") == 1) && (compare(tabel[1], "tdeveloper") == 0))
    {
        // Proses ngeprint bagian header tabel
        printf("\n[ DATA TABEL GAME ]\n  ---------------\n+");
        for (i = 0; i < kataterpanjang[0][0] + kataterpanjang[0][1] + kataterpanjang[0][2] + 8; i++)
        {
            printf("-");
        }
        printf("+\n| NAMA GAME ");
        for (i = 0; i < kataterpanjang[0][0] - 9; i++)
        {
            printf(" ");
        }
        printf("| HARGA GAME ");
        for (i = 0; i < kataterpanjang[0][1] - 10; i++)
        {
            printf(" ");
        }
        printf("| DEVELOPER ");
        for (i = 0; i < kataterpanjang[0][2] - 9; i++)
        {
            printf(" ");
        }
        printf("|\n");
        printf("+");
        for (i = 0; i < kataterpanjang[0][0] + kataterpanjang[0][1] + kataterpanjang[0][2] + 8; i++)
        {
            printf("-");
        }
        printf("+\n");

        // Proses ngeprint data tabel
        for (j = 0; j < banyakrecord[0]; j++)
        {
            printf("| %s ", game[j].value[0]);
            for (i = 0; i < kataterpanjang[0][0] - panjangkata(game[j].value[0]); i++)
            {
                printf(" ");
            }
            printf("| %s ", game[j].value[1]);
            for (i = 0; i < kataterpanjang[0][1] - panjangkata(game[j].value[1]); i++)
            {
                printf(" ");
            }
            printf("| %s ", game[j].value[2]);
            for (i = 0; i < kataterpanjang[0][2] - panjangkata(game[j].value[2]); i++)
            {
                printf(" ");
            }
            printf("|\n");
        }
        // Proses nge-print penutup tabel
        printf("+");
        for (i = 0; i < kataterpanjang[0][0] + kataterpanjang[0][1] + kataterpanjang[0][2] + 8; i++)
        {
            printf("-");
        }
        printf("+\n");
    }
    // If dengan kondisi user memasukkan tabel tdeveloper saja
    else if ((compare(tabel[0], "tdeveloper") == 1) && (compare(tabel[1], "tgame") == 0))
    {
        // Proses ngeprint bagian header tabel
        printf("\n[ DATA TABEL DEVELOPER ]\n  --------------------\n+");
        for (i = 0; i < kataterpanjang[1][0] + kataterpanjang[1][1] + kataterpanjang[1][2] + 8; i++)
        {
            printf("-");
        }
        printf("+\n| NAMA DEVELOPER ");
        for (i = 0; i < kataterpanjang[1][0] - 14; i++)
        {
            printf(" ");
        }
        printf("| TAHUN BERDIRI ");
        for (i = 0; i < kataterpanjang[1][1] - 13; i++)
        {
            printf(" ");
        }
        printf("| KANTOR PUSAT ");
        for (i = 0; i < kataterpanjang[1][2] - 12; i++)
        {
            printf(" ");
        }
        printf("|\n");
        printf("+");
        for (i = 0; i < kataterpanjang[1][0] + kataterpanjang[1][1] + kataterpanjang[1][2] + 8; i++)
        {
            printf("-");
        }
        printf("+\n");

        // Proses ngeprint data tabel
        for (j = 0; j < banyakrecord[1]; j++)
        {
            printf("| %s ", developer[j].value[0]);
            for (i = 0; i < kataterpanjang[1][0] - panjangkata(developer[j].value[0]); i++)
            {
                printf(" ");
            }
            printf("| %s ", developer[j].value[1]);
            for (i = 0; i < kataterpanjang[1][1] - panjangkata(developer[j].value[1]); i++)
            {
                printf(" ");
            }
            printf("| %s ", developer[j].value[2]);
            for (i = 0; i < kataterpanjang[1][2] - panjangkata(developer[j].value[2]); i++)
            {
                printf(" ");
            }
            printf("|\n");
        }
        // Proses nge-print penutup tabel
        printf("+");
        for (i = 0; i < kataterpanjang[1][0] + kataterpanjang[1][1] + kataterpanjang[1][2] + 8; i++)
        {
            printf("-");
        }
        printf("+\n");
    }
    // If dengan kondisi user memasukkan 2 tabel (join)
    else if (((compare(tabel[0], "tdeveloper") == 1) && (compare(tabel[1], "tgame") == 1)) || ((compare(tabel[1], "tdeveloper") == 1) && (compare(tabel[0], "tgame") == 1)))
    {
        // Proses ngeprint bagian header tabel
        printf("\n[ DATA TABEL GAME DAN DEVELOPER ]\n  -----------------------------\n+");
        for (i = 0; i < kataterpanjang[0][0] + kataterpanjang[0][1] + kataterpanjang[0][2] + kataterpanjang[1][1] + kataterpanjang[1][2] + 14; i++)
        {
            printf("-");
        }
        printf("+\n| NAMA GAME ");
        for (i = 0; i < kataterpanjang[0][0] - 9; i++)
        {
            printf(" ");
        }
        printf("| HARGA GAME ");
        for (i = 0; i < kataterpanjang[0][1] - 10; i++)
        {
            printf(" ");
        }
        printf("| DEVELOPER ");
        for (i = 0; i < kataterpanjang[0][2] - 9; i++)
        {
            printf(" ");
        }
        printf("| TAHUN BERDIRI ");
        for (i = 0; i < kataterpanjang[1][1] - 13; i++)
        {
            printf(" ");
        }
        printf("| KANTOR PUSAT ");
        for (i = 0; i < kataterpanjang[1][2] - 12; i++)
        {
            printf(" ");
        }
        printf("|\n");
        printf("+");
        for (i = 0; i < kataterpanjang[0][0] + kataterpanjang[0][1] + kataterpanjang[0][2] + kataterpanjang[1][1] + kataterpanjang[1][2] + 14; i++)
        {
            printf("-");
        }
        printf("+\n");

        // Proses ngeprint data tabel
        for (j = 0; j < banyakrecord[0]; j++)
        {
            printf("| %s ", game[j].value[0]);
            for (i = 0; i < kataterpanjang[0][0] - panjangkata(game[j].value[0]); i++)
            {
                printf(" ");
            }
            printf("| %s ", game[j].value[1]);
            for (i = 0; i < kataterpanjang[0][1] - panjangkata(game[j].value[1]); i++)
            {
                printf(" ");
            }
            printf("| %s ", game[j].value[2]);
            for (i = 0; i < kataterpanjang[0][2] - panjangkata(game[j].value[2]); i++)
            {
                printf(" ");
            }
            // Proses pengecekan kesamaan foreign key di tgame dengan primary key di tdeveloper
            for (k = 0; k < banyakrecord[1]; k++)
            {
                if (compare(game[j].value[2], developer[k].value[0]) == 1)
                {
                    // Proses ngeprint data tabel
                    printf("| %s ", developer[k].value[1]);
                    for (l = 0; l < kataterpanjang[1][1] - panjangkata(developer[k].value[1]); l++)
                    {
                        printf(" ");
                    }
                    printf("| %s ", developer[k].value[2]);
                    for (l = 0; l < kataterpanjang[1][2] - panjangkata(developer[k].value[2]); l++)
                    {
                        printf(" ");
                    }
                }
            }
            printf("|\n");
        }
        // Proses nge-print penutup tabel
        printf("+");
        for (i = 0; i < kataterpanjang[0][0] + kataterpanjang[0][1] + kataterpanjang[0][2] + kataterpanjang[1][1] + kataterpanjang[1][2] + 14; i++)
        {
            printf("-");
        }
        printf("+\n");
    }
    return 1;
}