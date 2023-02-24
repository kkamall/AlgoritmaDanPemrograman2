#include <stdio.h>

int idx, wlen, bquery, bvalue, btabel, idxvalue, idxtabel, tanda;
char queryAwal[4][50], tabel[5][50], value[10][50];
char cw[501], kata[501];

void start(char query[]);
void reset();
int eop(char query[]);
void inc(char query[]);
int getlen();
char *getcw();
int compare(char word1[], char word2[]);
void uppercase(char word[]);
void explode();
void salin(char word[][50], int index);
void jalan();
void panjang(char value[][4][100], int n, int panjang[][3], int palingPanjang[]);
void outputGame(int panjangKata[][3], char value[][4][100], int n, int palingPanjang[]);
void outputDev(int panjangKata[][3], char value[][4][100], int n, int palingPanjang[]);