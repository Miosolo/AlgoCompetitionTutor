#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getHam(char* str1, char* str2)
{
    char *p1 = str1, *p2 = str2;
    int hamDis = 0;

    while (*p1) {
        if (*p1++ != *p2++) {
            hamDis++;
        }
    }

    return hamDis;
}

int main(void)
{
    int kase;
    scanf("%d", &kase);

    while (kase--) {
        int m, n;
        scanf("%d%d", &m, &n);

        char* dna[m];
        for (int i = 0; i < m; i++) {
            dna[i] = (char*)malloc(n + 1);
            scanf("%s", dna[i]);
        }

        for (int i = 0; i < m; i++) {
            puts(dna[i]);
        }

        int hamDis[m][m];
        memset(hamDis, -1, sizeof(hamDis));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j) {
                    hamDis[i][j] = 0;
                } else {
                    hamDis[i][j] = getHam(dna[i], dna[j]);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", hamDis[i][j]);
            }
            printf("\n");
        }

        int hamDisSum[m];
        memset(hamDisSum, 0, sizeof(hamDisSum));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (j > i) {
                    hamDisSum[i] += hamDis[j][i];
                } else {
                    hamDisSum[i] += hamDis[i][j];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            printf("%d ", hamDisSum[i]);
        }

        int leastSum = -1;
        for (int i = 0; i < m; i++) {
            if (leastSum < 0) {
                leastSum = hamDisSum[i];
            } else if (hamDisSum[i] < leastSum) {
                leastSum = hamDisSum[i];
            }
        }

        int targetIndex = n;
        for (int i = 0; i < m; i++) {
            if (hamDisSum[i] == leastSum) {
                if (targetIndex == n) {
                    targetIndex = i;
                } else if (strcmp(dna[i], dna[targetIndex]) < 0) {
                    targetIndex = i;
                }
            }
        }

        puts(dna[targetIndex]);
        printf("%d\n", hamDisSum[targetIndex]);

        for (int i = 0; i < m; i++) {
            free(dna[i]);
        }
    }

    return 0;
}