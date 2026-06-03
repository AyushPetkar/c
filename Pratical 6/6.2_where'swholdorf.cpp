#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore(); // blank line

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<string> grid(m);

        for (int i = 0; i < m; i++) {
            cin >> grid[i];

            for (char &c : grid[i])
                c = tolower(c);
        }

        int k;
        cin >> k;
        cin.ignore();

        while (k--) {
            string word;
            getline(cin, word);

            for (char &c : word)
                c = tolower(c);

            bool found = false;

            for (int i = 0; i < m && !found; i++) {
                for (int j = 0; j < n && !found; j++) {

                    if (grid[i][j] != word[0])
                        continue;

                    // check all 8 directions
                    for (int dir = 0; dir < 8 && !found; dir++) {
                        int x = i, y = j;
                        int p;

                        for (p = 0; p < word.size(); p++) {
                            int nx = i + dx[dir] * p;
                            int ny = j + dy[dir] * p;

                            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                                break;

                            if (grid[nx][ny] != word[p])
                                break;
                        }

                        if (p == word.size()) {
                            cout << i + 1 << " " << j + 1 << endl;
                            found = true;
                        }
                    }
                }
            }
        }

        if (t) cout << endl;
    }

    return 0;
}