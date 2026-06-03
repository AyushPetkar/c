#include <iostream>
using namespace std;

// Reverse the digits of a number
unsigned long long reverseNum(unsigned long long n) {
    unsigned long long rev = 0;

    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    return rev;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        unsigned long long n;
        cin >> n;

        int count = 0;

        while (true) {
            unsigned long long rev = reverseNum(n);

            if (n == rev)
                break;

            n = n + rev;
            count++;
        }

        cout << count << " " << n << endl;
    }

    return 0;
}