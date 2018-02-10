#include <stdio.h>
#include <string.h>

int main(void)
{
  int kase;
  scanf("%d", &kase);

  while (kase--)
  {
    char oStr[105], rStr[205];
    scanf("%s", oStr);
    int len = strlen(oStr);
    strcpy(rStr, oStr);
    strcpy(rStr + len, oStr);

    char* smallest = rStr;
    for (char* p = rStr + 1; p < rStr + len; p++)
    {
      if (strcmp(p, smallest) < 0)
      {
        smallest = p;
      }
    }
    *(smallest + len) = 0;

    printf("%s\n", smallest);
  }
  return 0;
}
