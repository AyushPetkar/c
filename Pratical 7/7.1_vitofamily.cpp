#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r;
        cin >> r;

        vector<int> house(r);

        for (int i = 0; i < r; i++)
            cin >> house[i];

        sort(house.begin(), house.end());

        // Median gives minimum total distance
        int vito = house[r / 2];

        int sum = 0;

        for (int i = 0; i < r; i++)
            sum += abs(house[i] - vito);

        cout << sum << endl;
    }

    return 0;
}