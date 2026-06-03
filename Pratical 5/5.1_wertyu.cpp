#include <iostream>
#include <string>
using namespace std;

int main() {
    string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string line;

    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                cout << " ";
            } else {
                for (int j = 1; j < keyboard.size(); j++) {
                    if (line[i] == keyboard[j]) {
                        cout << keyboard[j - 1];
                        break;
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}