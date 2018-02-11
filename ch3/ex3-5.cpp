#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char frame[5][5];
char input[500];

void swap(char* pa, char* pb)
{
    char t = *pa;
    *pa = *pb;
    *pb = t;

    return;
}

int main(void)
{
    for (int kase = 1;; kase++) {
        memset(input, 0, sizeof(input));

        char* pi = input;
        for (pi = input; pi < input + 25; pi += 5) {
            fgets(pi, 30, stdin);
            if (*pi == 'Z') {
                return 0;
            }
        }
        pi = input + 25;
        while (1) {
            scanf("%s", pi);
            while (*pi != 0) {
                pi++;
            }
            if (*(pi - 1) == '0') {
                break;
            } else {
                pi++;
            }
        }
        getchar();

        char* pBlank = NULL;
        pi = input;
        for (char *pf = frame[0]; pf <= &frame[4][4]; pf++, pi++) {
            *pf = *pi;
            if (*pf == ' ' || *pf == '\n') {
                *pf = ' ';
                pBlank = pf;
            }
        }

        bool noConf = false;
        pi = input + 25;
        while (!noConf && *pi != '0') {
            switch (*pi) {
            case 'A':
                if (pBlank - 5 >= frame[0]) {
                    swap(pBlank, pBlank - 5);
                    pBlank -= 5;
                } else
                    noConf = true;
                break;

            case 'B':
                if (pBlank + 5 <= &frame[4][4]) {
                    swap(pBlank, pBlank + 5);
                    pBlank += 5;
                } else
                    noConf = true;
                break;

            case 'L':
                if ((pBlank - frame[0]) % 5 != 0) {
                    swap(pBlank, pBlank - 1);
                    pBlank--;
                } else
                    noConf = true;
                break;

            case 'R':
                if ((pBlank - frame[0]) % 5 != 4) {
                    swap(pBlank, pBlank + 1);
                    pBlank++;
                } else
                    noConf = true;
                break;
            }
            pi++;
        }

        if (kase != 1) {
            putchar('\n');
        }
        printf("Puzzle #%d:\n", kase);
        if (noConf)
            printf("This puzzle has no final configuration.\n");
        else {
            for (char* pf = frame[0]; pf <= &frame[4][4]; pf++) {
                putchar(*pf);
                if ((pf - frame[0]) % 5 == 4)
                    putchar('\n');
                else
                    putchar(' ');
            }
        }
    }

    return 0;
}
