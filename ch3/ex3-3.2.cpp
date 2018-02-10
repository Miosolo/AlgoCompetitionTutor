#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int amount[10];

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

void addNum(int n)
{
  if (n <= 0)
    return;

  int digit = getDigit(n);
  for (int i = 0; i < digit; i++)
  {
    int loopStart;
    if (i == digit - 1)
    {
      loopStart = n;
    }
    else
    {
      loopStart = pow(10, digit - 1) + n % (int)pow(10, i + 1);
      for (int j = 0; j <= 9; j++)
      {
        amount[j] += (n - loopStart) / 10;
      }
    }

    int loopEnd = loopStart / pow(10, i);
    loopEnd *= pow(10, i);
    for (int j = (i == digit - 1 ? 1 : 0); j <= (loopEnd - pow(10, i)) / pow(10, i) - 1; j++)
    {
      amount[j] += pow(10, i);
    }

    if (i == 0)
      continue;
    amount[(loopEnd - (int)pow(10, i)) / (int)pow(10, i)] += loopStart - loopEnd + 1;
  }


  addNum((int)pow(10, digit - 1) - 1);
}

int main(void)
{
  int kase;
  scanf("%d", &kase);

  while (kase--)
  {
    int N; 
    scanf("%d", &N);
    addNum(N);

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
