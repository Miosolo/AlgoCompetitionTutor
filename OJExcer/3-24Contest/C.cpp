#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char str[1001];
struct SearchNode {
 public:
  char target[21];
  int len;
  int match;
  SearchNode *next;

  SearchNode(void) : match(0), next(NULL) {}
  ~SearchNode(void) {
    if (this->next != NULL) delete next;
  }
  void CreateNode(char *que) {
    int length;
    char *p = que;
    while (*p != '?') p++, length++;
    strncpy(target, que, length);
    len = length;
    Search();
  }
  void Search(void) {
    for (char *p = str; *p; p++) {
      if (*target == *p) {
        if (strncmp(target, p, len) == 0) {
          p += len;
          match++;
          continue;
        }
      }
      p++;
    }
  }
};

struct SearchNode *head;
void InsertNode(struct SearchNode *node) {
  struct SearchNode *ps = head;
  while (ps != NULL) {
    if (strlen(node->target, ps->next->target) <) }
}

int main(void) {
  memset(str, 0, sizeof(str));
  int kase;
  cin >> kase;

  while (kase--) {
    char query[21];
    scanf("%s", query);
  }
}
