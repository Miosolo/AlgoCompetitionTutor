// detect the limit of double
#include <stdio.h>

int main(void)
{
    int dem = 0;
    double num = 1;

    while(num != 0)
    {
        num /= 10;
        dem++;
    }
    printf("%d", dem);
}