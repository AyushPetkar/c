#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// Reverse pancakes from top to position k
void flip(vector<int>& a, int k) {
    reverse(a.begin(), a.begin() + k);
}

int main() {
    string line;

    while (getline(cin, line)) {
        cout << line << endl;   // print original stack

        stringstream ss(line);
        vector<int> a;
        int x;

        while (ss >> x)
            a.push_back(x);

        int n = a.size();

        // Sort largest to smallest from bottom side
        for (int size = n; size > 1; size--) {

            // Find largest pancake in first 'size' pancakes
            int pos = max_element(a.begin(), a.begin() + size) - a.begin();

            // Already in correct place
            if (pos == size - 1)
                continue;

            // Bring largest to top
            if (pos != 0) {
                flip(a, pos + 1);
                cout << n - pos << " ";
            }

            // Bring largest to correct bottom position
            flip(a, size);
            cout << n - size + 1 << " ";
        }

        cout << "0" << endl;
    }

    return 0;
}