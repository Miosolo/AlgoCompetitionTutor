#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define toInt(n) ((n) - '0')
#define value(digit) ((digit) - i - 1)

int getDigit(int n)
{
  int digit = 0;
  do
  {
    digit++;
    n /= 10;
  } while (n != 0);
  return digit;
}

int main(void)
{
  int kase;
  scanf("%d", &kase);

  while (kase--)
  {
    int amount[10] = {0}, N, digit;
    scanf("%d", &N);
    digit = getDigit(N);
    char num[7] = {0};
    sprintf(num, "%d", N);

    for (int i = 0; i <= digit - 1; i++)
    {
      for (int j = 0; j <= 9; j++)
      {
        int t = N / pow(10, i + 1);
        t *= pow (10, i);
        amount[j] += t;
      }
      for (int j = 1; j <= toInt(num[value(digit)]) - 1; j++)
      {
        amount[j] += pow(10, i);
      }
      amount[toInt(num[value(digit)])] += N % (int)pow(10, i) + 1;
    }

    for (int i = 0; i <= 9; i++)
    {
      if (i)
        printf(" ");
      printf("%d", amount[i]);
    }
    printf("\n");
  }
  return 0;
}
