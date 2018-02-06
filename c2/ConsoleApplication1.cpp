//近似计算 pi/4
#include <stdio.h>
#include <math.h>

int main(void)
{
    int op = 1;
    double pi_4 = 0, denom = 1;

    while (denom <= pow(10, 6))
    {
        pi_4 += (op / denom);
        denom += 2;
        op *= -1;
    }

    printf("%f", pi_4);
}