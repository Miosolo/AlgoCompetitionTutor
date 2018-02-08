#include <stdio.h>

#define toChar(n) ((n) + 48)

int main(void)
{
  int upnum, downnum, precision, kase = 0;
  while (scanf("%d%d%d", &upnum, &downnum, &precision) == 3 && (upnum || downnum || precision))
  {
    if (kase)
      printf("\n");
    printf("Case %d: ", ++kase);

    char value[110] = {0};
    sprintf(value, "%d", upnum / downnum);

    char *p = value;
    while (*p)
    {
      p++;
    }
    *p++ = '.';

    int remain = upnum % downnum;
    for (int i = 0; i <= precision; i++)
    {
      if (i == precision)
      {
        if (remain * 10 / downnum >= 5)
        (*--p)++;
        continue;
      }
      remain *= 10;
      *p++ = toChar(remain / downnum);
      remain %= downnum;
    }
      printf("%s\n", value);
  }
    return 0;
}
