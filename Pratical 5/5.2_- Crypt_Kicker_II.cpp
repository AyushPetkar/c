#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool makeMap(string code, string target, char mp[], char rev[]) {
    if (code.size() != target.size())
        return false;

    for (int i = 0; i < 256; i++) {
        mp[i] = 0;
        rev[i] = 0;
    }

    for (int i = 0; i < code.size(); i++) {
        char c1 = code[i];
        char c2 = target[i];

        if (c1 == ' ' && c2 == ' ')
            continue;

        if (c1 == ' ' || c2 == ' ')
            return false;

        // first time mapping
        if (mp[c1] == 0 && rev[c2] == 0) {
            mp[c1] = c2;
            rev[c2] = c1;
        }
        // wrong mapping
        else if (mp[c1] != c2 || rev[c2] != c1) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore(); // blank line

    string target = "the quick brown fox jumps over the lazy dog";

    while (t--) {
        vector<string> lines;
        string line;

        while (getline(cin, line) && line != "") {
            lines.push_back(line);
        }

        char mp[256];
        char rev[256];
        bool found = false;

        // Find valid encrypted sentence
        for (string s : lines) {
            if (makeMap(s, target, mp, rev)) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No solution." << endl;
        } else {
            for (string s : lines) {
                for (char c : s) {
                    if (c == ' ')
                        cout << ' ';
                    else
                        cout << mp[c];
                }
                cout << endl;
            }
        }

        if (t) cout << endl;
    }

    return 0;
}