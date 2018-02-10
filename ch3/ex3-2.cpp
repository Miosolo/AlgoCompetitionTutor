#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define C 0
#define H 1
#define O 2
#define N 3

int main(void)
{
  int kase;
  const double mass[4] = {12.01, 1.008, 16.00, 14.01};
  scanf("%d", &kase);

  while (kase--)
  {
    char formula[85] = {0};
    scanf("%s", formula);
    char *p = formula;
    int amount[4] = {0};

    while (*p)
    {
      char eTemp = *p;
      int aTemp;

      if (*(p + 1) == 0 || isalpha(*(p + 1)))
      {
        aTemp = 1;
        p++;
      }
      else
      {
        p++;
        sscanf(p, "%d", &aTemp);
        while (!isalpha(*p))
          p++;
      }

      switch (eTemp)
      {
        case 'C': amount[C] += aTemp; break;
        case 'H': amount[H] += aTemp; break;
        case 'O': amount[O] += aTemp; break;
        case 'N': amount[N] += aTemp; break;
      }
    }

    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
      sum += mass[i] * amount[i];
    }
    printf("%.3f\n", sum);
  }
  return 0;
}
