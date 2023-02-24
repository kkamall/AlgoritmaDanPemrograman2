/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal UTS Alpro 2 C1 2021 - migor22
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Fungsi untuk menghitung hasil bagi
double pembagian(minyak sup[], int i)
{
    // Penyimpanan sementara nilai hasil bagi 
    double temp;
    temp = sup[i].harga/(sup[i].kalori+sup[i].lemak);
    // Mengembalikan nilai yang ada dalam variabel temp
    return temp;
}

// Prosedur untuk sorting insertion
void insertion(int x, minyak sup[])
{
    int i, j;
    minyak key;
    /*
        (1) i, j = buat iterasi
        (2) minyak key = data minyak buat dibandingin dan di-swap
    */

    // Looping untuk sorting
    for(i=1; i<x; i++)
    {
        key = sup[i];
        j = i-1;
        while(j>=0 && key.hb < sup[j].hb)
        {
            sup[j+1] = sup[j];
            j--;
        }
        sup[j+1] = key;
    }
}

// Prosedur untuk sorting selection
void selection(int x, minyak sup[])
{
    int i, j, minindex;
    minyak temp;
    /*
        (1) i, j = iterasi
        (2) minindex = minimal index
        (3) temp = buat nuker nilai
    */

    // Looping untuk sorting
    for(i=0; i<x-1; i++)
    {
        minindex = i;
        for(j=i+1; j<x; j++)
        {
            if(sup[minindex].hb > sup[j].hb)
            {
                minindex = j;
            }
        }
        // Proses pertukaran
        temp = sup[i];
        sup[i] = sup[minindex];
        sup[minindex] = temp;
    }
}

// Prosedur untuk sorting bubble
void bubble(int x, minyak sup[])
{
    int i, flag;
    minyak temp;
    /*
        (1) i = iterasi
        (2) flag = sebagai penanda ada pertukaran
        (3) temp = untuk proses pertukaran data
    */

    // Do While untuk proses sorting
    do
    {
        flag = 0;
        for(i=0; i<x-1; i++)
        {
            if(sup[i].hb > sup[i+1].hb)
            {
                // Proses pertukaran
                temp = sup[i];
                sup[i] = sup[i+1];
                sup[i+1] = temp;
                flag = 1;
            }
        }
    }while(flag==1);
}

// Prosedur untuk sorting quick
void quick(minyak sup[], int kiri, int kanan)
{
    int i, j;
    minyak pivot;
    minyak temp;
    /*
        (1) i, j = iterasi
        (2) pivot = untuk membandingkan nilainya
        (3) temp = buat proses pertukaran
    */
    
    i=kiri; j=kanan;
    pivot = sup[(kanan+kiri)/2];

    // Do While proses sorting
    do
    {
        // Membandingkan supplier dengan pivot untuk mencari indeks i
        while((sup[i].hb < pivot.hb) && (i <= j))
        {
            i++;
        }
        // Membandingkan supplier dengan pivot untuk mencari indeks j
        while((sup[j].hb > pivot.hb) && (i <= j))
        {
            j--;
        }

        if(i<j)
        {
            // Proses pertukaran nilai
            temp = sup[i];
            sup[i] = sup[j];
            sup[j] = temp;
            i++; j--;
        }
    }while(i<j);

    if((kiri<j) && (j<kanan))
    {
        // Rekrusif
        quick(sup, kiri, j);
    }
    if((i<kanan) && (i>kiri))
    {
        // Rekursif
        quick(sup, i, kanan);
    }
}

// Prosedur untuk merge array
void merge(minyak sup1[], minyak sup2[], int x, int y, minyak sup3[])
{
    int i=0, j=0, k;
    /*
        (1) i, j = buat index array yang dibandingkan
        (2) k = buat iterasi
    */

    // Looping untuk membandingkan dan meng-copy nilai
    for(k=0; k<x+y; k++)
    {
        // Kondisi di mana nilai array sup1 sudah di-copy semua ke array sup3
        if(i==x)
        {
            sup3[k] = sup2[j];
            j++;
        }
        // Kondisi di mana nilai array sup2 sudah di-copy semua ke array sup3
        else if(j==y)
        {
            sup3[k] = sup1[i];
            i++;
        }
        // Kondisi di mana hasil bagi sup1 lebih kecil dari hasil bagi sup2
        else if(sup1[i].hb < sup2[j].hb)
        {
            sup3[k] = sup1[i];
            i++;
        }
        // Kondisi di mana hasil bagi sup1 lebih besar dari hasil bagi sup2
        else if(sup1[i].hb > sup2[j].hb)
        {
            sup3[k] = sup2[j];
            j++;
        }
        // Kondisi di mana hasil bagi sup1 sama dengan hasil bagi sup2
        else if(sup1[i].hb == sup2[i].hb)
        {
            sup3[k] = sup1[i];
            i++; k++;
            sup3[k] = sup2[j];
            j++;
        }
    }
}

// Prosedur untuk mengeluarkan output
void output(char metode[3], minyak sup1[], minyak sup2[], minyak sup3[], minyak sup4[], minyak sup5[], int a, int b, int c)
{
    int i, temp;
    /*
        (1) i = buat iterasi
        (2) temp = buat ngasih tau hasil bagi apakah ada angka di belakang koma atau tidak
    */

    // Looping mencari hasil bagi tiap minyak
    for(i=0; i<a; i++)
    {
        sup1[i].hb =  pembagian(sup1, i);
    }
    for(i=0; i<b; i++)
    {
        sup2[i].hb =  pembagian(sup2, i);
    }
    for(i=0; i<c; i++)
    {
        sup3[i].hb =  pembagian(sup3, i);
    }

    // If Else untuk menentukan metode sorting yang dipakai
    if(strcmp(metode, "is") == 0)
    {
        insertion(a, sup1);
        insertion(b, sup2);
        insertion(c, sup3);
    }
    else if(strcmp(metode, "ss") == 0)
    {
        selection(a, sup1);
        selection(b, sup2);
        selection(c, sup3);
    }
    else if(strcmp(metode, "bs") == 0)
    {
        bubble(a, sup1);
        bubble(b, sup2);
        bubble(c, sup3);
    }
    else
    {
        quick(sup1, 0, a-1);
        quick(sup2, 0, b-1);
        quick(sup3, 0, c-1);
    }

    // Pemanggilan prosedur merge buat merge array
    merge(sup1, sup2, a, b, sup4);
    merge(sup3, sup4, c, a+b, sup5);

    // Proses pengeluaran output:
    // Output per supplier
    printf("Per Supplier:\n");
    // Output supplier 1
    printf("Supplier 1:\n");
    for(i=0; i<a; i++)
    {
        printf("%s %.0f %.0f %.0f - ", sup1[i].merk, sup1[i].kalori, sup1[i].lemak, sup1[i].harga);
        temp = sup1[i].hb;
        if(sup1[i].hb - temp != 0)
        {
            printf("%.2lf\n", sup1[i].hb);
        }
        else
        {
            printf("%d\n", temp);
        }
    }printf("\n");

    // Output supplier 2
    printf("Supplier 2:\n");
    for(i=0; i<b; i++)
    {
        printf("%s %.0f %.0f %.0f - ", sup2[i].merk, sup2[i].kalori, sup2[i].lemak, sup2[i].harga);
        temp = sup2[i].hb;
        if(sup2[i].hb - temp != 0)
        {
            printf("%.2lf\n", sup2[i].hb);
        }
        else
        {
            printf("%d\n", temp);
        }
    }printf("\n");

    // Output supplier 3
    printf("Supplier 3:\n");
    for(i=0; i<c; i++)
    {
        printf("%s %.0f %.0f %.0f - ", sup3[i].merk, sup3[i].kalori, sup3[i].lemak, sup3[i].harga);
        temp = sup3[i].hb;
        if(sup3[i].hb - temp != 0)
        {
            printf("%.2lf\n", sup3[i].hb);
        }
        else
        {
            printf("%d\n", temp);
        }
    }printf("\n");

    // Output semua minyak yang sudah di merge
    printf("Semua:\n");
    for(i=0; i<a+b+c; i++)
    {
        printf("%s %.0f %.0f %0.f - ", sup5[i].merk, sup5[i].kalori, sup5[i].lemak, sup5[i].harga);
        temp = sup5[i].hb;
        if(sup5[i].hb - temp != 0)
        {
            printf("%.2lf ", sup5[i].hb);
        }
        else
        {
            printf("%d ", temp);
        }
        printf("Supplier %d\n", sup5[i].supp);
    }
}