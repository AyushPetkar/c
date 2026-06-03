#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    string line;
    getline(cin, line); // blank line after test cases

    while (t--) {
        vector<int> ram(1000, 0);
        vector<int> reg(10, 0);

        int index = 0;

        // Read program
        while (getline(cin, line)) {
            if (line == "") break;
            ram[index++] = stoi(line);
        }

        int pc = 0;      // program counter
        int count = 0;   // instruction count

        while (true) {
            int inst = ram[pc];
            pc++;
            count++;

            int op = inst / 100;
            int d = (inst / 10) % 10;
            int n = inst % 10;

            if (op == 1) break; // halt

            else if (op == 2) reg[d] = n;

            else if (op == 3) reg[d] = (reg[d] + n) % 1000;

            else if (op == 4) reg[d] = (reg[d] * n) % 1000;

            else if (op == 5) reg[d] = reg[n];

            else if (op == 6) reg[d] = (reg[d] + reg[n]) % 1000;

            else if (op == 7) reg[d] = (reg[d] * reg[n]) % 1000;

            else if (op == 8) reg[d] = ram[reg[n]];

            else if (op == 9) ram[reg[n]] = reg[d];

            else if (op == 0) {
                if (reg[n] != 0)
                    pc = reg[d];
            }
        }

        cout << count << endl;
        if (t) cout << endl;
    }

    return 0;
}