#include "header.h"

int main()
{
    banyakdata = 0;
    int i = 0, x;
    char pita[100][55];
    scanf(" %51[^\n]s", &pita[i]);

    start(pita[i]);
    while ((strcmp(getcw(), "SELESAI") != 0) && (pita[i][strlen(pita[i])] != ';'))
    {
        prosedur(i, pita[i]);
        i++;
        scanf(" %50[^\n]s", &pita[i]);
        start(pita[i]);
    }
    printf("%s\n", barang[1][0]);

    return 0;
}