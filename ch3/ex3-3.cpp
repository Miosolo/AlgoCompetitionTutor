#include <stdio.h>
#include <string.h>

#define toInt(c) ((c) - '0')

int main(void)
{
  int kase;
  scanf("%d", &kase);

  while (kase--)
  {
    int amount[10] = {0}, N;
    scanf("%d", &N);

    char curNum[5];
    for (int i = 1; i <= N; i++)
    {
      sprintf(curNum, "%d", i);
      char *p = curNum;
      while (*p)
      {
        amount[toInt(*p)]++;
        p++;
      }
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
