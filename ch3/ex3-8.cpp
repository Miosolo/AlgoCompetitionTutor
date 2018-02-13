#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(void)
{
    int a, b;
    for (int kase = 1; scanf("%d%d", &a, &b) == 2; kase++) {
        printf("%d/%d = %d.", a, b, a / b);

        for (int d = gcd(a, b); d != 1; d = gcd(a, b)) {
            a /= d;
            b /= d;
        }

        bool isRemain[b];
        memset(isRemain, false, sizeof(isRemain));
        int demical[b + 2], remain[b + 2];
        memset(demical, -1, sizeof(demical));
        memset(remain, -1, sizeof(remain));

        int recStart = -1, recEnd = -1;
        remain[0] = a % b;
        isRemain[remain[0]] = true;
        for (int i = 1; i <= b; i++) {
            demical[i] = remain[i - 1] * 10 / b;
            remain[i] = remain[i - 1] * 10 % b;
            if (!isRemain[remain[i]]) {
                isRemain[remain[i]] = true;
            } else {
                recEnd = i;
                break;
            }
        }

        for (int i = 0; i < recEnd; i++) {
            if (remain[i] == remain[recEnd]) {
                recStart = i;
                break;
            }
        }

        for (int i = 1; i <= recEnd; i++) {
            if (i - 1 == recStart) {
                putchar('(');
            }
            printf("%d", demical[i]);
            if (i - recStart >= 50) {
                printf("...");
                break;
            }
        }
        printf(")\n   %d = number of digits in repeating cycle\n\n", recEnd - recStart);
    }
}