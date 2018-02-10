#include <stdio.h>

int main(void)
{
  int kase;
  scanf("%d", &kase);

  while (kase--)
  {
    char str[85] = {0};
    scanf("%s", str);
    int accu = 0, sum = 0;
    char *p = str;
    while (*p)
    {
      if (*p == 'O')
      {
        sum += ++accu;
      }
      else
      {
        accu = 0;
      }
      p++;
    }
      printf("%d\n", sum);
  }
  return 0;
}
