#include <iostream>
using namespace std;

// Function to find cycle length of a number
int cycleLength(int n) {
    int count = 1;

    while (n != 1) {
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;

        count++;
    }

    return count;
}

int main() {
    int i, j;

    // Read until EOF
    while (cin >> i >> j) {
        int start = i, end = j;

        // Swap if i > j
        if (start > end)
            swap(start, end);

        int maxCycle = 0;

        // Check all numbers in range
        for (int n = start; n <= end; n++) {
            int len = cycleLength(n);

            if (len > maxCycle)
                maxCycle = len;
        }

        // Output in original order
        cout << i << " " << j << " " << maxCycle << endl;
    }

    return 0;
}