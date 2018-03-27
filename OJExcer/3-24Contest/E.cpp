#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char num[200001];

int main(void) {
  int kase;
  cin >> kase;

  while (kase--) {
    int len;
    cin >> len;

    scanf("%s", num);
    char *p = num;

    int del;
    do {
      del = 0, p = num;
      while (*p) {
        if (*p == '0') {
          char *t = p++;
          while (*p == ' ') p++;
          if (*p == '1') {
            del++;
            *p = *t = ' ';
            p++;
          }
        } else {
          p++;
        }
      }
      len -= 2 * del;
    } while (del != 0);

    cout << len << ".000" << endl;
  }
}