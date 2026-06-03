#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<bool> hartal(n + 1, false);

        for (int i = 0; i < p; i++) {
            int h;
            cin >> h;

            for (int day = h; day <= n; day += h) {
                // Skip Friday and Saturday
                if (day % 7 != 6 && day % 7 != 0)
                    hartal[day] = true;
            }
        }

        int count = 0;

        for (int day = 1; day <= n; day++) {
            if (hartal[day])
                count++;
        }

        cout << count << endl;
    }

    return 0;
}