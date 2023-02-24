/*
Saya Muhammad Kamal Robbani mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// Link dengan file header.h
#include "header.h"

int main()
{
    char query[501], fungsi[2][20];
    int flag = 0, tanda = 0;
    int index;
    /*
        (1) query = pita masukkan user
        (2) fungsi = menampung query masukkan user
        (3) flag = sebagai tanda
        (4) tanda = sebagai tanda
        (5) index = buat index dalam fungsi for/while
    */

    printf("Selamat Datang di DBMS Kamal\nVersi 1.0\n\n");
    printf("dbms kamal > ");

    // Meminta masukkan pita dari user
    scanf(" %500[^\n]s", &query);

    // Memulai pembacaan pita
    start(query);

    // Cek kondisi apakah masukkan user adalah "exit;"
    if ((compare(getcw(), "exit") == 1) && (query[panjangkata(query)] == ';'))
    {
        flag = 2;
    }

    // While jika masukkan user bukan "exit;"
    while (flag != 2)
    {
        // Mereset char fungsi mejadi string kosong
        for (index = 0; index < 2; index++)
        {
            fungsi[index][0] = '\0';
        }
        index = 0;

        // While jika querynya belum mencapai eop
        while (eop(query) == 0)
        {
            // Pemasukkan query kepada variabel fungsi
            if ((compare(getcw(), "TAMPIL") == 1) || (compare(getcw(), "ENTRI") == 1) || (compare(getcw(), "UBAH") == 1) || (compare(getcw(), "HAPUS") == 1))
            {
                copykata(fungsi[index], getcw());
                index++;
            }
            // Pemecahan pita
            explode(query);
            // Lanjut membaca kata berikutnya
            inc(query);
        }
        // Pemecahan pita
        explode(query);
        // Mengambil record data dari tabel
        ambildata();
        // Mencari kata terpanjang tiap tabel
        carikataterpanjang();
        // Proses pengecekkan error (flag = 1 -> ada error | flag = 0 -> gak ada error)
        flag = cek(query);

        // If yang menandakan error tidak ada
        if (flag == 0)
        {
            index = 0;
            tanda = 0;

            // While jika tanda = 0 (belum ada query yang dijalankan) dan index < 2 (maksimal query adalah 2)
            while (tanda == 0 && index < 2)
            {
                // Menjalankan query ENTRI
                if (compare(fungsi[index], "ENTRI") == 1)
                {
                    tanda = entri();
                }
                // Menjalankan query UBAH
                else if (compare(fungsi[index], "UBAH") == 1)
                {
                    tanda = ubah();
                }
                // Menjalankan query HAPUS
                else if (compare(fungsi[index], "HAPUS") == 1)
                {
                    tanda = hapus();
                }
                // Menjalankan query TAMPIL
                else if (compare(fungsi[index], "TAMPIL") == 1)
                {
                    tanda = tampil();
                }
                index++;
            }
            // If dengan kondisi query yang dimasukkan ada dua dan query tidak ada yang dijalankan
            if (fungsi[1][0] != '\0' && tanda == 0)
            {
                printf("\n[ ERROR ] -> Query tidak ada yang dijalankan!\n");
            }
        }

        printf("\ndbms kamal > ");
        // Meminta masukkan user kembali
        scanf(" %500[^\n]s", &query);
        // Mulai membaca kata
        start(query);
        // Cek kondisi apakah masukkan user adalah "exit;"
        if ((compare(getcw(), "exit") == 1) && (query[panjangkata(query)] == ';'))
        {
            flag = 2;
        }
    }

    return 0;
}