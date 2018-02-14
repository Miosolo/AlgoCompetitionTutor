#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[30];

    while (scanf("%s", input) == 1) {
        if (input[1] == 'e')
            return 0;

        int expo = atoi(input + 18);
        *(input + 17) = 0;
        double dem = atof(input);

        int expoCount = 0;
        while (dem > 1 || expo > 0) {
            if (dem < 1) {
                dem *= 10;
                expo--;
            }
            dem /= 2;
            expoCount++;
        }

        int expoCountBin = 0;
        while (expoCount > 0) {
            expoCount /= 2;
            expoCountBin++;
        }

        dem = 1 - dem;
        int mantCount = 0;
        while (dem < 0.9) {
            dem *= 2;
            mantCount++;
        }

        printf("%d %d\n", mantCount - 1, expoCountBin);
    }
}