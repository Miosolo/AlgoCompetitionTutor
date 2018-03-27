#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
  int kase;
  cin >> kase;

  for (int k = 1; k <= kase; k++) {
    double X, Y, T, S;
    cin >> X >> Y >> T >> S;

    if (X <= Y) {
      printf("Case #%d: %.3f", k, S / X);
      continue;
    } else {
      double tAm = 0, sAm, t;
      sAm = Y * T;

      while (tAm <= S / Y) {
        t = sAm / (X - Y);
        tAm += t;
        sAm += Y * t;
      }
      tAm -= t;
      tAm += S / X;

      printf("Case #%d: %.3f", k, tAm);
    }
  }

  return 0;
}
