/*
	Saya Muhammad Kamal Robbani [2102313] mengerjakan
	soal TP3 Alpro 2 C1 2021 - VBB121
	dalam mata kuliah Algoritma dan Pemrograman 2
	untuk keberkahanNya maka saya tidak melakukan kecurangan
	seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk cari nilai di jam ke-x
int cek(int k1, int k2, int k3, virus v[])
{
    // If buat ngebalikin nilai di jam ke-0 dan ke-1 dan buat basis juga
    if(k2 == v[i].x)
    {
        return v[i].nilai[0];
        return v[i].nilai[1];
    }
    // If dengna kondisi jamnya selain 1 dan 0
    else
    {
        // Rekrusif
        cek(k1+1, k2+1, k3+1, v);
        // Buat nyari nilai jam ke-x
        v[i].nilai[v[i].x-k1] = 2*(v[i].x-k1)*(v[i].nilai[v[i].x-k2])+(v[i].nilai[v[i].x-k3])*(v[i].nilai[v[i].x-k3])-1;
        return v[i].nilai[v[i].x-k1-1];
    }
}