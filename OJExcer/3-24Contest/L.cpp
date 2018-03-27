#include <cmath>
#include <iostream>
using namespace std;

int main(void) {
  int kase;
  cin >> kase;
  const double log2 = log(2);

  while (kase--) {
    int poi;
    scanf("%d", &poi);
    printf("%d\n", (int)ceil(log(poi) / log2));
  }

  return 0;
}