#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define LowToAlpha 'a' - 0

using namespace std;

char str[100001];
int letteram[26];

bool IntComp(int *arr1, int *arr2) {
  for (int i = 0; i < 26; i++) {
    if (*(arr1 + i) != *(arr2 + i)) return false;
  }
  return true;
}

int main(void) {
  scanf("%s", str);

  int sublen = 0;
  for (int i = 0; i < 26; i++) {
    scanf("%d", letteram + i);
    sublen += letteram[i];
  }

  int sublm[26], len = strlen(str);
  for (int i = 0; i <= len - sublen; i++) {
    if (i == 0) {
      memset(sublm, 0, sizeof(sublm));
      for (int j = 0; j < sublen; j++) sublm[str[j] - LowToAlpha]++;
    } else {
      sublm[str[i - 1] - LowToAlpha]--;
      sublm[str[i + sublen - 1] - LowToAlpha]++;
    }

    if (IntComp(letteram, sublm)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}