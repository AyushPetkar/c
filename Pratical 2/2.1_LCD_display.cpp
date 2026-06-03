#include <iostream>
#include <string>
using namespace std;

// Check if top segment exists
bool top(int d) {
    return d != 1 && d != 4;
}

// Check if middle segment exists
bool middle(int d) {
    return d != 0 && d != 1 && d != 7;
}

// Check if bottom segment exists
bool bottom(int d) {
    return d != 1 && d != 4 && d != 7;
}

// Upper left segment
bool upperLeft(int d) {
    return d == 0 || d == 4 || d == 5 || d == 6 || d == 8 || d == 9;
}

// Upper right segment
bool upperRight(int d) {
    return d != 5 && d != 6;
}

// Lower left segment
bool lowerLeft(int d) {
    return d == 0 || d == 2 || d == 6 || d == 8;
}

// Lower right segment
bool lowerRight(int d) {
    return d != 2;
}

int main() {
    int s;
    string n;

    while (cin >> s >> n) {
        if (s == 0 && n == "0") break;

        int rows = 2 * s + 3;

        for (int r = 0; r < rows; r++) {

            for (int i = 0; i < n.size(); i++) {
                int d = n[i] - '0';

                // Top row
                if (r == 0) {
                    cout << " ";
                    for (int j = 0; j < s; j++)
                        cout << (top(d) ? '-' : ' ');
                    cout << " ";
                }

                // Upper vertical rows
                else if (r <= s) {
                    cout << (upperLeft(d) ? '|' : ' ');
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << (upperRight(d) ? '|' : ' ');
                }

                // Middle row
                else if (r == s + 1) {
                    cout << " ";
                    for (int j = 0; j < s; j++)
                        cout << (middle(d) ? '-' : ' ');
                    cout << " ";
                }

                // Lower vertical rows
                else if (r < rows - 1) {
                    cout << (lowerLeft(d) ? '|' : ' ');
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << (lowerRight(d) ? '|' : ' ');
                }

                // Bottom row
                else {
                    cout << " ";
                    for (int j = 0; j < s; j++)
                        cout << (bottom(d) ? '-' : ' ');
                    cout << " ";
                }

                if (i != n.size() - 1) cout << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}