#include <algorithm>
#include <iostream>
using namespace std;

void swap2(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;

    return;
}

int main(void)
{
    int a, b;
    cin >> a >> b;
    swap(a, b);
    cout << a << " " << b << "hahaha" << endl;

    return 0;
}