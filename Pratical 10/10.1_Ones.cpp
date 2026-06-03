#include <iostream>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int remainder = 1 % n;
        int length = 1;

        while (remainder != 0) {
            remainder = (remainder * 10 + 1) % n;
            length++;
        }

        cout << length << endl;
    }

    return 0;
}