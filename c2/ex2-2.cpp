#include <stdio.h>

#define INVALID 10000

int main(void)
{
    int rem3, rem5, rem7, kase = 0;

    while (scanf("%d%d%d", &rem3, &rem5, &rem7) == 3)
    {
        int  amount = INVALID;
        for (int i = 10 + rem5; i <= 100; i += 5)
        {
            if (i % 7 == rem7)
            {
                if (i % 3 == rem3)
                {
                    amount = i;
                    goto loopDone;
                }
            }
        }
        loopDone:
        if (kase)
        {
            printf("\n");
        }
        if (amount != INVALID)
        {

            printf("Case %d: %d\n", kase, amount);
        }
        else
        {
            printf("Case %d: No answer\n", kase);
        }
    }

    return 0;
}