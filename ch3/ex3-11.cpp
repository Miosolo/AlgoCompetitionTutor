#include <stdio.h>
#include <string.h>

#define toInt(ch) ((ch)-48)

int main(void)
{
    char input1[105], input2[105];
    while (scanf("%s", input1) == 1) {
        scanf("%s", input2);

        int len1 = strlen(input1), len2 = strlen(input2);
        char str1[len1 + len2 + 1], str2[len1 + len2 + 1];
        memset(str1, 0, sizeof(str1));
        strcpy(str1 + len2, input1);

        int minLen = len1 + len2;
        for (int i = 1; i <= len1 + len2 - 1; i++) {
            memset(str2, 0, sizeof(str2));
            strcpy(str2 + i, input2);
            bool noMore3 = true;

            for (int j = (i > len2) ? i : len2; j < ((len1 + len2 < i + len2) ? len1 + len2 : i + len2); j++) {
                if (toInt(str1[j]) + toInt(str2[j]) > 3) {
                    noMore3 = false;
                    break;
                }
            }

            if (noMore3) {
                int t = ((len1 + len2 > i + len2) ? len1 + len2 : i + len2) - ((i < len2) ? i : len2);
                minLen = minLen > t ? t : minLen;
            }
        }
        printf("%d\n", minLen);
    }

    return 0;
}