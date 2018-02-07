#include <stdio.h>

int main(void)
{
  int n, m;
  int kase = 0;
  while (scanf("%d%d", &n, &m) == 2 && (n || m))
  {
    double sum = 0;
    for (int i = n; i <= m; i++)
    {
      sum += (double)1 / (i * i);
    }
    if (kase)
      printf("\n");
    printf("Case %d: %.5f\n", ++kase, sum);
  }
  return 0;
}
