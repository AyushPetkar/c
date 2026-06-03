#include <iostream>
using namespace std;

int main() {
    int m, n;

    while (cin >> m >> n) {
        if (m == 1 && n == 1)
            break;

        while (!(m == 1 && n == 1)) {
            if (m < n) {
                cout << 'L';
                n = n - m;
            } else {
                cout << 'R';
                m = m - n;
            }
        }

        cout << endl;
    }

    return 0;
}