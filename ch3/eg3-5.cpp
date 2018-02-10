#include <stdio.h>

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

int getDG(int n)
{
  int digit = getDigit(n);
  for (int i = n - digit * 9; i < n; i++)
  {
    int numSum = 0, j = i;
    while (j > 0)
    {
      numSum += j % 10;
      j /= 10;
    }
    if (numSum + i == n)
    {
      return i;
    }
  }
  return 0;
}

int main(void)
{
  int n, kase;
  scanf("%d", &kase);
  while (kase-- && scanf("%d", &n) == 1)
  {
    int dg;

    if (n < 10)
    {
      if (n % 2 == 0)
        dg = n / 2;
      else
        dg = 0;
    }
    else
      dg = getDG(n);

    printf("%d\n", dg);
  }

  return 0;
}
