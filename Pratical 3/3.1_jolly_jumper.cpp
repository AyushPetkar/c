#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        vector<int> arr(n);
        vector<bool> seen(n, false);   // differences 1 to n-1

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 1; i < n; i++) {
            int diff = abs(arr[i] - arr[i - 1]);

            if (diff >= 1 && diff <= n - 1)
                seen[diff] = true;
        }  

        bool jolly = true;

        for (int i = 1; i <= n - 1; i++) {
            if (!seen[i]) {
                jolly = false;
                break;
            }
        }

        if (jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }

    return 0;
}

