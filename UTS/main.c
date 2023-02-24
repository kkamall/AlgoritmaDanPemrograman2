/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal UTS Alpro 2 C1 2021 - migor22
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    char metode[3];
    scanf("%s", &metode);
    int a, b, c, i, j;
    /*
        (1) metode = untuk metode sorting
        (2) a, b, c = buat banyaknya minyak di supplier
        (3) i, j = buat iterasi
    */
    
    // Meminta inputan nilai a dan data dari minyak supplier 1
    scanf("%d", &a);
    // Supplier 1
    minyak sup1[a];
    for(i=0; i<a; i++)
    {
        scanf("%s %f %f %f", &sup1[i].merk, &sup1[i].kalori, &sup1[i].lemak, &sup1[i].harga);
        sup1[i].supp = 1;
    }

    // Meminta inputan nilai b dan data dari minyak supplier 2
    scanf("%d", &b);
    // Supplier 2
    minyak sup2[b];
    for(i=0; i<b; i++)
    {
        scanf("%s %f %f %f", &sup2[i].merk, &sup2[i].kalori, &sup2[i].lemak, &sup2[i].harga);
        sup2[i].supp = 2;
    }

    // Meminta inputan nilai c dan data dari minyak supplier 3
    scanf("%d", &c);
    // Supplier 3
    minyak sup3[c];
    for(i=0; i<c; i++)
    {
        scanf("%s %f %f %f", &sup3[i].merk, &sup3[i].kalori, &sup3[i].lemak, &sup3[i].harga);
        sup3[i].supp = 3;
    }
    
    // Supplier 4 = gabungan dari supplier 1 dan 2
    minyak sup4[a+b];
    // Supplier 5 = gabungan dari supplier 3 dan 4
    minyak sup5[a+b+c];
    // Pemanggilan prosedur output
    output(metode, sup1, sup2, sup3, sup4, sup5, a, b, c);
    
    return 0;
}