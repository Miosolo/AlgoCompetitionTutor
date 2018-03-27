#include <stdio.h>

int main(void) {
  int x1, x2, x3, x4;
  int i, j, k, l, m, q;
  int N;
  int sum = 0;
  unsigned long p = 1000000007;
  scanf("%d", &N);
  i = N - x1;
  j = N - x2;
  k = N - x3;
  l = N - x4;
  for (x1 = 1; x1 <= N; x1++) {
    for (x2 = x1; x2 <= N;) {
      for (x3 = x2; x3 <= N;) {
        for (x4 = x3; x4 <= N;) {
          m = i * j * k * l;
          sum = sum + m;
        }
      }
    }
  }
  q = sum % p;
  printf("%d", q);
  return 0;
}
