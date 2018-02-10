#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char str[85];
int factor[25];

void getFactor(int n)
{
  memset(factor, 0, sizeof(factor));
  int *p = factor;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
      {
        *p++ = i;
      }
  }

  int *pr = p - 1;
  while (pr >= factor)
  {
    *p++ = n / *pr--;
  }

  return;
}

int main(void)
{
  int kase;
  scanf("%d", &kase);

  for (int i = 0; i < kase; i++)
  {
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    getFactor(strlen(str));
    int T;

    int *pf = factor;
    while (*(pf + 1))
      pf++;
    while (pf >= factor)
    {
      int patternLen = *pf;
      char pattern[patternLen + 1];
      strncpy(pattern, str, patternLen);
      bool match = true;

      for (char *ps = str; *ps != 0 && match; ps += patternLen)
      {
        if ((int)strncmp(pattern, ps, patternLen) != 0)
          match = false;
      }
      if (match)
      {
        T = patternLen;
      }
      pf--;
    }

    if (i)
      printf("\n");
    printf("%d\n", T);
  }
  return 0;
}
