// hash法：数据 -> 内存
// 桶排序思想

#include <cstdio>
#include <iostream>
using namespace std;

bool num[1000001];

int main(void) {
  memset(num, 0, sizeof(num));
  int n, m;
  cin >> n >> m;

  while (n--) {
    int posi;
    scanf("%d", &posi);
    num[posi + 500000] = 1;
  }
}