#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char martrix[1000][1000];

int main(void) {
  int H, W;
  cin >> H >> W;

  for (int i = 0; i < H; i++) {
    scanf("%s", martrix[i]);
  }

  int query;
  cin >> query;

  while (query--) {
    int l1, r1, l2, r2, l3, r3, l4, r4;
    scanf("%d%d%d%d%d%d%d%d", &l1, &r1, &l2, &r2, &l3, &r3, &l4, &r4);

    int diffam = 0;
    for (int i = 0; i <= l2 - l1; i++) {
      for (int j = 0; j <= r2 - r1; j++) {
        if (martrix[l1 + i][r1 + j] != martrix[l3 + i][r3 + j]) {
          if (diffam == 1) {
            diffam++;
            goto LoopDone;
          } else {
            diffam++;
          }
        }
      }
    }

  LoopDone:
    switch (diffam) {
      case 0:
        cout << "Perfect" << endl;
        break;
      case 1:
        cout << "One difference" << endl;
        break;
      default:
        cout << "Wrong" << endl;
    }
  }

  return 0;
}