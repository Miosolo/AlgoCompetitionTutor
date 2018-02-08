#include <stdio.h>
#include <stdbool.h>

bool allNumber(int a, int b, int c)
{
  bool numList[10] = {true};

  for (int i = 0; i < 3; i++)
  {
    int n;
    switch (i)
    {
      case 0: n = a;  break;
      case 1: n = b;  break;
      case 2: n = c;  break;
    }

    for (int j = 0; j < 3; j++)
    {
      int k = n % 10;
      if (numList[k] == true)
        return false;
      else
        numList[k] = true;
      n /= 10;
    }
  }

  return true;
}

int main(void)
{
  for (int i = 123; i <= 333; i++)
  {
    if (allNumber(i, 2 * i, 3 * i))
    {
      printf("%d %d %d\n", i, 2 * i, 3 * i);
    }
  }

  return 0;
}
