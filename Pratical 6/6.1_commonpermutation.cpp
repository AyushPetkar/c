#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;

    while (getline(cin, a) && getline(cin, b)) {
        int countA[26] = {0};
        int countB[26] = {0};

        // Count letters in first string
        for (char c : a)
            countA[c - 'a']++;

        // Count letters in second string
        for (char c : b)
            countB[c - 'a']++;

        // Print common letters in alphabetical order
        for (int i = 0; i < 26; i++) {
            int common = min(countA[i], countB[i]);

            while (common--) {
                cout << char(i + 'a');
            }
        }

        cout << endl;
    }

    return 0;
}

