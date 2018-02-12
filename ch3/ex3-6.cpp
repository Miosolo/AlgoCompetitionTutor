#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int r, c, kase = 0;
    while (scanf("%d", &r) == 1 && r != 0) {
        scanf("%d", &c);
        char field[r][c], *pf = field[0];

        for (pf = field[0]; pf <= &field[r - 1][c - 1]; pf += c) {
            scanf("%s", pf);
        }

        int index[r][c], indexCount = 0;
        memset(index, -1, sizeof(index));
        for (pf = field[0]; pf <= &field[r - 1][c - 1]; pf++) {
            if (*pf != '*') {
                bool count = false;

                if (pf >= field[0] && pf <= &field[0][c - 1]) {
                    count = true;
                } else if ((pf - field[0]) % c == 0) {
                    count = true;
                } else if (field[0] <= (pf - c) && (pf - c) <= &field[r - 2][c - 1] && *(pf - c) == '*') {
                    count = true;
                } else if (0 <= (pf - 1 - field[0]) % c && (pf - 1 - field[0]) % c <= c - 2 && *(pf - 1) == '*') {
                    count = true;
                }
                if (count) {
                    *(index[0] + (pf - field[0])) = ++indexCount;
                }
            }
        }

        if (kase) {
            putchar('\n');
        }
        printf("puzzle #%d:\n", ++kase);

        int indexBackup[r][c];
        memcpy(indexBackup, index, sizeof(index));

        printf("Across\n");
        for (int* pi = index[0]; pi <= &index[r - 1][c - 1]; pi++) {
            if (*pi != -1) {
                printf("%3d.", *pi);
                pf = field[0] + (pi - index[0]);
                do {
                    putchar(*pf);
                    *(index[0] + (int)(pf - field[0])) = -1;
                    pf++;
                } while (*pf != '*' && (pf - field[0]) % c > 0);
                putchar('\n');
            }
        }

        memcpy(index, indexBackup, sizeof(index));
        printf("Down\n");
        for (int* pi = index[0]; pi <= &index[r - 1][c - 1]; pi++) {
            if (*pi != -1) {
                printf("%3d.", *pi);
                pf = field[0] + (pi - index[0]);
                do {
                    putchar(*pf);
                    *(index[0] + (pf - field[0])) = -1;
                    pf += c;
                } while (*pf != '*' && pf <= &field[r - 1][c - 1]);
                putchar('\n');
            }
        }
    }

    return 0;
}