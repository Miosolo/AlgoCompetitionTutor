//寻找100~999的所有水仙花数
#include <stdbool.h>
#include <stdio.h>

bool isNarci(int n)
{
    int a, b, c, n2 = n;
    a = n / 100, n %= 100;
    b = n / 10, n %= 10;
    c = n;

    if (a * a * a + b * b * b + c * c * c == n2)
        return true;
    else
        return false;
}

int main(void)
{
    for (int n = 100; n <= 999; n++)
    {
        if (isNarci(n))
        {
            printf("%d ", n);
        }
    }
    return 0;
}