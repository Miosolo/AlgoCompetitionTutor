#include <stdio.h>

char strs[1000000], strt[1000000];

int main(void) {
    while (scanf("%s%s", strs, strt) == 2) {
        char *ps = strs, *pt = strt;

        while (*ps) {
            while (*pt != *ps) {
                if (*(pt + 1)) {
                    pt++;
                } else {
                    printf("No\n");
                    goto nextInput;
                }
            }
            ps++, pt++;
        }
        printf("Yes\n");

    nextInput:
        ps = NULL;
    }
}