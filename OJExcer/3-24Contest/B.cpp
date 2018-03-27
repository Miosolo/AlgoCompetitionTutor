#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char num[7];
int insert[7];

void addInsert(void) {
  int *p = insert + 6;
  while (*p == -1) p--;

  while (p >= insert) {
    if (*p == 0) {
      p++;
      return;
    } else {
      p++;
    }
  }
}

int main(void) {
  int kase;
  while (kase--) {
    memset(num, 0, sizeof(num));
    scanf("%s", num);
    memset(insert, -1, sizeof(insert));

    int len = strlen(num);
    for (int i = 0; i < len - 1; i++) insert[i] = 0;
    for (int i = 0; i < (int)pow(2, len - 1); i++, addInsert()) {
      char buffer[7], *pb = buffer;
      int counter;

      for (int j = 0; j < len - 1, j++) {
        *(++pb) = num[i];
      }
    }
  }
}