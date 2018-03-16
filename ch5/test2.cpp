#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
    string str;
    while (getline(cin, str)) {
        int sum = 0, t;
        stringstream ss(str);
        while (ss >> t) {
            sum += t;
        }
        cout << sum << endl;
    }

    return 0;
}