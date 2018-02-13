#include <stdio.h>
#include <string.h>

int main(void)
{
    int kase;
    scanf("%d", &kase);

    while (kase--) {
        int m, n;
        scanf("%d%d", &m, &n);

        char dnaTable[m][n];
        for (char* pt = dnaTable[0]; pt <= &dnaTable[m - 1][n - 1]; pt += n) {
            scanf("%s", pt);
        }

        int hamDisSum = 0;
        char conStr[n + 1];
        memset(conStr, 0, sizeof(conStr));
        for (int j = 0; j < n; j++) {
            int amount[128] = { 0 };
            for (int i = 0; i < m; i++) {
                amount[(int)dnaTable[i][j]]++;
            }

            char index[] = "ACGT";
            int maxAmountIndex = 'A';
            for (int i = 0; i <= 3; i++) {
                if (amount[(int)index[i]] > amount[maxAmountIndex]) {
                    maxAmountIndex = index[i];
                }
            }
            conStr[j] = maxAmountIndex;

            for (int i = 0; i <= 3; i++) {
                if (index[i] != maxAmountIndex) {
                    hamDisSum += amount[(int)index[i]];
                }
            }
        }

        puts(conStr);
        printf("%d\n", hamDisSum);
    }

    return 0;
}