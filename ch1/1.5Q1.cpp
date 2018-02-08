// detect the limit of int
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define isValid(n) (((n / (int)n) > 0) ? true : false)

int main(void)
{
    long long i = 0;

    long long upLim, downLim;

    //upLim
    int digit = 9;
    for (i = 1; digit >= 0; digit--)
    {        while (isValid(i))
        {
            i += (long long)pow(10, digit);
        }
        i -= (long long)pow(10, digit);
    }
    upLim = i;

    //dowmLim
    digit = 9;
    for (i = 1; digit >= 0; digit--)
    {
        while (isValid(i))
        {
            i -= (long long)pow(10, digit);
        }
        i += (long long)pow(10, digit);
    }
    downLim = i;

    printf("%lld, %lld", upLim, downLim);

    return 0;
}