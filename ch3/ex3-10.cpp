#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int pallet[6][3];
    memset(pallet, -1, sizeof(pallet));

    while (scanf("%d", &pallet[0][1]) == 1) {
        for (int *p = &pallet[0][2]; p <= &pallet[5][2]; p++) {
            if ((p - pallet[0]) % 3 == 0) {
                continue;
            } else if ((p - pallet[0]) % 3 == 2) {
                scanf("%d", p);
                if (*p > *(p - 1)) swap(p, p - 1);
            } else {
                scanf("%d", p);
            }
        }

        for (int *pp = pallet[0], pairCount = 0; pp <= pallet[5]; pp += 3) {
            if (*pp != -1) {
                continue;
            } else {
                for (int *ppt = pp + 3; ppt <= pallet[5]; ppt += 3) {
                    if (*(ppt + 1) == *(pp + 1) && *(ppt + 2) == *(pp + 2)) {
                        *pp = *ppt = pairCount++;
                        break;
                    }
                }
            }
        }

        bool paired = true;
        for (int *pp = pallet[0]; pp <= pallet[5]; pp += 3) {
            if (*pp == -1) {
                paired = false;
                break;
            }
        }

        if (paired) {
            int vp[3][2] = {0};
            for (int *pp = pallet[0]; pp <= pallet[5]; pp += 3) {
                if (vp[*pp][0] == 0) memcpy(vp[*pp], pp + 1, 2 * sizeof(int));
            }

            bool allMatch = true;
            for (int i = 0; i < 3; i++) {
                int *pl = vp[0];

                while (!*pl) pl++;
                for (int *plt = pl + 1; plt <= &vp[2][1]; plt++) {
                    if (*plt == *pl) {
                        *plt = *pl = 0;
                        break;
                    }
                }
            }
            for (int *pl = vp[0]; pl <= &vp[2][1]; pl++) {
                if (*pl) allMatch = false;
            }

            if (allMatch) {
                printf("POSSIBLE\n");
                memset(pallet, -1, sizeof(pallet));
                continue;
            }
        }
        printf("IMPOSSIBLE\n");
        memset(pallet, -1, sizeof(pallet));
    }

    return 0;
}