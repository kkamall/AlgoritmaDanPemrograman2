#include "header.h"

int main()
{
    char query[501];

    printf("Selamat Datang di DBMS Kamal\nVersi 1.0\n\n");
    printf("dbms kamal > ");
    scanf(" %500[^\n]s", &query);
    start(query);

    while (compare(getcw(), "exit") == 0)
    {
        while (eop(query) == 0)
        {
            explode();
            inc(query);
        }
        explode();
        jalan();

        printf("\ndbms kamal > ");
        scanf(" %500[^\n]s", &query);
        start(query);
    }

    return 0;
}