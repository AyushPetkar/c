#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    int field = 1;

    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        vector<string> ans = grid;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '*')
                    continue;

                int count = 0;

                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int ni = i + x;
                        int nj = j + y;

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            if (grid[ni][nj] == '*')
                                count++;
                        }
                    }
                }

                ans[i][j] = count + '0';
            }
        }

        if (field > 1)
            cout << endl;

        cout << "Field #" << field << ":" << endl;

        for (int i = 0; i < n; i++) {
            cout << ans[i] << endl;
        }

        field++;
    }

    return 0;
}