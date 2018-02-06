//计算前n个数的阶乘之和的后六位
#include <stdio.h>
#include <time.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    long long fac = 1, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        fac *= i, fac %= 1000000;
        sum += fac, sum %= 1000000;
    }

    printf("%ld\n", sum);
    printf("time used: %f\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}
